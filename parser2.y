
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

%}

%define parse.error verbose

%union {
	int boolean_value;
	CharPtr iden;
	Operators oper;
	double value;
	vector<double>* list;
}


%token <iden> IDENTIFIER

%token <value> INT_LITERAL CHAR_LITERAL REAL_LITERAL HEX_LITERAL

%token <oper> ADDOP MULOP ANDOP RELOP EXPOP REMOP NEGOP REMOP

%token ARROW

%token BEGIN_ CASE CHARACTER ELSE END ENDSWITCH FUNCTION INTEGER IS LIST OF OTHERS RETURNS SWITCH WHEN REAL IF THEN ELSIF ENDIF FOLD ENDFOLD LEFT RIGHT

%token <boolean_value> NOTOP OROP

%type <value> body statement_ statement cases case expression term primary
	 condition relation 

%type <list> list expressions


%%

function:	
	function_header optional_variable body ';' {result = $3;};

function_header:	
	FUNCTION IDENTIFIER optional_parameters RETURNS type ';' | error ';' { yyerror("Error in function header"); } ;

type:
	INTEGER |
	REAL |
	CHARACTER ;

optional_variable:
    variables |
    %empty | 
    error ';' ;

variable:	
	IDENTIFIER ':' type IS statement ';' {scalars.insert($1, $5);}; |
	IDENTIFIER ':' LIST OF type IS list ';' {lists.insert($1, $7);}| 
	error ';';

variables:
    variable variables |
    %empty ;

list:
	'(' expressions ')' {$$ = $2;};

expressions:
	expressions ',' expression {$1->push_back($3); $$ = $1;}| 
	expression {$$ = new vector<double>(); $$->push_back($1);}

body:
	BEGIN_ statement_ END {$$ = $2;} ;

statement_:
	statement ';' |
	error ';' {$$ = 0;} ;

statement:
	expression |
	WHEN condition ',' expression ':' expression {$$ = $2 ? $4 : $6;} |
	SWITCH expression IS cases OTHERS ARROW statement ';' ENDSWITCH {$$ = !isnan($4) ? $4 : $7;} 
;

cases:
	cases case {$$ = !isnan($1) ? $1 : $2;}|
	%empty {$$ = NAN;} |
	error ';'{$$ = NAN;};
	
case:
	CASE INT_LITERAL ARROW statement ';' {$$ = $<value>-2 == $2 ? $4 : NAN;} |
	error ';'{$$ = NAN;}; 

condition:
	condition ANDOP relation {$$ = $1 && $2;} |
	relation |
    expression RELOP expression|
    condition logical_operator condition |
    NOTOP condition { $$ = !$2; };

relation:
	'(' condition ')' {$$ = $2;} |
	expression RELOP expression {$$ = evaluateRelational($1, $2, $3);} 

expression:
    term |
    expression ADDOP term {$$ = evaluateArithmetic($1, $2, $3);} |
    expression arithmetic_operator expression |
    NEGOP expression { $$ = -$2; };

term:
	term MULOP primary {$$ = evaluateArithmetic($1, $2, $3);}  |
	primary ;

primary:
	'(' expression ')' {$$ = $2;} |
	INT_LITERAL | 
	CHAR_LITERAL |
	REAL_LITERAL |
	IDENTIFIER '(' expression ')' {$$ = extract_element($1, $3); } |
	IDENTIFIER {if (!scalars.find($1, $$)) appendError(UNDECLARED, $1);} ;    

parameters:
    parameter more_parameters ;

more_parameters:
    ',' parameter more_parameters | %empty ;

parameter:
    IDENTIFIER ':' type ;

optional_parameters:
    parameters | %empty ; 


logical_operator:
    ANDOP | OROP;

arithmetic_operator:
    ADDOP | MULOP | REMOP | EXPOP ;


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
	firstLine();
	yyparse();
	if (lastLine() == 0)
		cout << "Result = " << result << endl;
	return 0;
} 
