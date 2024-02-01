/* CMSC 430 Compiler Theory and Design
   Project 3 Skeleton
   UMGC CITE
   Summer 2023
   
   Project 3 Parser with semantic actions for the interpreter */

%{

#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <map>

using namespace std;

#include "values.h"
#include "listing.h"
#include "symbols.h"

int yylex();
void yyerror(const char* message);
double extract_element(CharPtr list_name, double subscript);

Symbols<double> scalars;
Symbols<vector<double>*> lists;
double result;
double* params;
int countParams = 0; 
vector<double>* listValue; 

%}

%define parse.error verbose

%union {
	int direction;
	int boolean_value;
	CharPtr iden;
	Operators oper;
	double value;
	vector<double>* list;
	Case aCase;
    Case casesArray[MAX_CASES];
}


%token <iden> IDENTIFIER

%token <value> INT_LITERAL CHAR_LITERAL REAL_LITERAL HEX_LITERAL FLOAT_LITERAL

%token <oper> ADDOP MULOP ANDOP RELOP EXPOP REMOP NEGOP NOTOP OROP

%token ARROW

%token BEGIN_ CASE CHARACTER ELSE END ENDSWITCH FUNCTION INTEGER IS LIST OF OTHERS RETURNS SWITCH WHEN REAL IF THEN ELSIF ENDIF FOLD ENDFOLD LEFT RIGHT 

%type <value> body statement_ statement  expression term primary condition relation if_statement elsif_clauses fold_statement factor unary exponent

%type <list> list expressions list_choice

%type <oper> arithmetic_operator

%type <direction> direction

%type <aCase> case

%type <casesArray> cases


%%

function:	
	function_header optional_variable  body ';' {result = $3;} ;
	
function_header:	
	FUNCTION IDENTIFIER RETURNS type ';' |
	FUNCTION IDENTIFIER parameters RETURNS type ';' | 
	error ';' ;

parameters:
    parameter more_parameters ;

more_parameters:
    ',' parameter more_parameters | %empty ;

parameter:
    IDENTIFIER ':' type { scalars.insert($1, params[countParams++]);};

type:
	INTEGER |
	REAL |
	CHARACTER ;
	
optional_variable:
	variables |
	%empty |
	error ';';

variables:
	variable variables |
	%empty |
	error ';';
	
variable:	
	IDENTIFIER ':' type IS statement ';' {scalars.insert($1, $5);}; |
	IDENTIFIER ':' LIST OF type IS list ';' {lists.insert($1, $7);} ;

list:
	'(' expressions ')' {$$ = $2;} ;

expressions:
	expressions ',' expression {$1->push_back($3); $$ = $1;} | 
	expression {$$ = new vector<double>(); $$->push_back($1);}

body:
	BEGIN_ statement_ END {$$ = $2;} ;

statement_:
	statement ';' |
	error ';' {$$ = 0;} ;
    
statement:
	WHEN condition {$$ = $2;}|
	expression |
	WHEN condition ',' expression ':' expression {$$ = $2 ? $4 : $6;} | 
	if_statement | fold_statement | 
	SWITCH expression IS cases OTHERS ARROW statement ';' ENDSWITCH {
        double switchExprValue = $2;
        Case *caseArray = $4;
        double result = $7; 
        for (int i = 0; i < MAX_CASES && caseArray[i].caseValue != 0; ++i) {
            result = (caseArray[i].caseValue == switchExprValue) ? caseArray[i].statementValue : result;
        }

        $$ = result;
    }
	;

cases:
	cases case {
        int i = 0;
        while (i < MAX_CASES && $1[i].caseValue != 0) ++i;
        if (i < MAX_CASES) {
            $1[i] = $2;
            for (int i = 0; i < MAX_CASES; ++i) {
    			$$[i] = $1[i];
			}
        }
    }|
	%empty {
        Case emptyCases[MAX_CASES] = {{0, 0}};
        for (int i = 0; i < MAX_CASES; ++i) {
    		$$[i] = emptyCases[i];
		}
    }; ;

case:
	CASE INT_LITERAL ARROW statement ';' { $$ = (Case){static_cast<int>($2), $4}; };

fold_statement:
    FOLD direction arithmetic_operator list_choice ENDFOLD { $$ = ($2 == LEFT) ? fold_left($3, $4) : fold_right($3, $4); } ; 

direction:
    LEFT { $$ = LEFT; } | RIGHT { $$ = RIGHT; } ;


list_choice:
    list { $$ = $1; } | 
    IDENTIFIER { lists.find($1, listValue); $$ = listValue; };;

if_statement:
    IF condition THEN statement_ elsif_clauses ENDIF { $$ = $2 ? $4 : $5; }|
    IF condition THEN statement_ elsif_clauses ELSE statement_ ENDIF { $$ = $2 ? $4 : ($5 ? $5 : $7); };

elsif_clauses:
    %empty { $$ = 0; }|  
    ELSIF condition THEN statement_ elsif_clauses { $$ = $2 ? $4 : $5; } ;

condition:
	condition ANDOP relation {$$ = $1 && $2;} |
	condition OROP relation {$$ = $1 || $3; }|
	NOTOP condition { $$ = !$2; }|
	relation { $$ = $1; };

relation:
	'(' condition ')' {$$ = $2;} |
	expression RELOP expression {$$ = evaluateRelational($1, $2, $3);} ;


expression:
	'(' expression ')' { $$ = $2; }|
   expression arithmetic_operator expression { $$ = evaluateArithmetic($1, $2, $3); }|
   NEGOP expression { $$ = -$2; }|
   INT_LITERAL { $$ = $1; }|
   CHAR_LITERAL { $$ = $1; }|
   REAL_LITERAL { $$ = $1; }|
   HEX_LITERAL { $$ = $1; }|
   FLOAT_LITERAL { $$ = $1; }|
	expression ADDOP term {$$ = evaluateArithmetic($1, $2, $3);} |
	term ;

arithmetic_operator:
    ADDOP | EXPOP | MULOP | REMOP | NEGOP ;

term:
	term ADDOP factor {$$ = evaluateArithmetic($1, $2, $3);}  |
	factor ;

factor:
	factor MULOP exponent {$$ = evaluateArithmetic($1, $2, $3);}|
	factor REMOP exponent { $$ = fmod($1 , $3); } |
	exponent ;

exponent:
	unary |
	unary EXPOP exponent { $$ = pow($1, $3);};

unary:
	NOTOP primary {$$ = $2;} |
	primary;

primary:
	'(' expression ')' {$$ = $2;} |
	INT_LITERAL | 
	CHAR_LITERAL |
	REAL_LITERAL |
   HEX_LITERAL |
   FLOAT_LITERAL |
	IDENTIFIER '(' expression ')' {$$ = extract_element($1, $3); } |
	IDENTIFIER {if (!scalars.find($1, $$)) appendError(UNDECLARED, $1);} ;

%%

void yyerror(const char* message) {
	appendError(SYNTAX, message);
}

double extract_element(CharPtr list_name, double subscript) {
	vector<double>* list; 
	if (lists.find(list_name, list))
		return (*list)[subscript];
	appendError(UNDECLARED, list_name);
	return NAN;
}

int main(int argc, char *argv[]) {
	params = new double[argc - 1];
    for (int i = 1; i < argc; ++i) {
        params[i - 1] = atof(argv[i]);
    }
	firstLine();
	yyparse();
	if (lastLine() == 0)
		cout << "Result = " << result << endl;
	delete[] params; 
	return 0;
} 
