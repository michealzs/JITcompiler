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

%token <value> INT_LITERAL CHAR_LITERAL REAL_LITERAL HEX_LITERAL FLOAT_LITERAL

%token <oper> ADDOP MULOP ANDOP RELOP EXPOP REMOP NEGOP MODOP NOTOP OROP

%token ARROW

%token BEGIN_ CASE CHARACTER ELSE END ENDSWITCH FUNCTION INTEGER IS LIST OF OTHERS RETURNS SWITCH WHEN REAL IF THEN ELSIF ENDIF FOLD ENDFOLD LEFT RIGHT 

%type <value> body statement_ statement  expression term primary condition relation if_statement elsif_clauses

%type <list> list expressions

%type <oper> arithmetic_operator



%%

function:	
	function_header optional_variable  body ';' {result = $3;} ;
	
function_header:	
	FUNCTION IDENTIFIER RETURNS type ';' ;

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
	if_statement ;

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
    ADDOP | MULOP | MODOP | EXPOP ;

term:
	term EXPOP primary {$$ = evaluateArithmetic($1, $2, $3);}  |
	term MULOP primary {$$ = evaluateArithmetic($1, $2, $3);}  |
	term MODOP primary {$$ = evaluateArithmetic($1, $2, $3);}  |
	primary ;

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
	firstLine();
	yyparse();
	if (lastLine() == 0)
		cout << "Result = " << result << endl;
	return 0;
} 
