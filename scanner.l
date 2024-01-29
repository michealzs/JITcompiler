
%{
#include <cstdio>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

#include "values.h"
#include "listing.h"
#include "tokens.h"

int hexToInt(const char* hexStr);
char charLiteralToChar(const char* charLit);

%}

%option noyywrap

ws    		[ \t\r]+
comment     "//".*\n
comment2	"--".*\n 
line     	[\n]
id    		[A-Za-z]([A-Za-z0-9]|(_[A-Za-z0-9])|(__[A-Za-z0-9]))*([A-Za-z0-9]+)?
float   	[-+.]?([0-9]+\.[0-9]*|\.[0-9]+)([eE][-+]?[0-9]+)?
digit    	[0-9]
dec      	{digit}+
char     	'.'
punc     	[\(\),:;]
real     	[0-9]*\.[0-9]+([Ee][+-]?[0-9]+)?
hex 	 	#[0-9A-Fa-f]+
%%

{ws}     	{ ECHO; }
{comment}   { ECHO; nextLine(); }
{line}      { ECHO; nextLine(); }
{comment2}  { ECHO; nextLine(); } 
"+"      	{ ECHO; yylval.oper = ADD; return(ADDOP);  }
"-"        { ECHO; yylval.oper = SUBTRACT; return(ADDOP); }
"/"        { ECHO; yylval.oper = DIVIDE; return(MULOP); }
"%"        { ECHO; yylval.oper = MODULO; return(MODOP); }
"^"        { ECHO; yylval.oper = EXPONENT; return(EXPOP); }
"~"        { ECHO; yylval.oper = NEGATE; return(NEGOP); }
"*"      { ECHO; yylval.oper = MULTIPLY; return(MULOP); }
"&"      { ECHO; yylval.oper = AND; return(ANDOP);  }
"<"      { ECHO; yylval.oper = LESS; return(RELOP); }
"=>"     { ECHO; return(ARROW); }
"|"        { ECHO; yylval.oper = OR; return(OROP); }
"!"        { ECHO; yylval.oper = NOT; return(NOTOP); }
"="        { ECHO; yylval.oper = EQUAL; return(RELOP); }
"<>"       { ECHO; yylval.oper = NOTEQUAL; return(RELOP); }
">"        { ECHO; yylval.oper = GREATER; return(RELOP); }
">="       { ECHO; yylval.oper = GEQ; return(RELOP); }
"<="       { ECHO; yylval.oper = LEQ; return(RELOP); }
else       { ECHO; return(ELSE); }
elsif      { ECHO; return(ELSIF); }
endfold    { ECHO; return(ENDFOLD); }
endif      { ECHO; return(ENDIF); }
fold       { ECHO; return(FOLD); }
if         { ECHO; return(IF); }
left       { ECHO; return(LEFT); }
real       { ECHO; return(REAL); }
right      { ECHO; return(RIGHT); }
then       { ECHO; return(THEN); }
begin    { ECHO; return(BEGIN_); }
case     { ECHO; return(CASE); }
character   { ECHO; return(CHARACTER); }
end      { ECHO; return(END); }
endswitch   { ECHO; return(ENDSWITCH); }
function { ECHO; return(FUNCTION); }
integer     { ECHO; return(INTEGER); }
is    { ECHO; return(IS); }
list     { ECHO; return(LIST); }
of    { ECHO; return(OF); }
others      { ECHO; return(OTHERS); }
returns     { ECHO; return(RETURNS); }
switch      { ECHO; return(SWITCH); }
when     { ECHO; return(WHEN); }
{real}      { ECHO; yylval.value = atof(yytext); return REAL_LITERAL; } 
{id}     { ECHO; yylval.iden = (CharPtr)malloc(yyleng + 1); 
			strcpy(yylval.iden, yytext); return(IDENTIFIER);}
{dec}    { ECHO; yylval.value = atoi(yytext); return(INT_LITERAL);  }
{char}      { ECHO; yylval.value = yytext[1]; return(CHAR_LITERAL); }
{punc}      { ECHO; return(yytext[0]); }
.     		{ ECHO; appendError(LEXICAL, yytext); }
{hex} 		{ ECHO; yylval.value = hexToInt(yytext); return HEX_LITERAL;  }
{float}		{ ECHO; yylval.value = atof(yytext); return FLOAT_LITERAL;}
'\\[btnfr]'  { ECHO; yylval.value = charLiteralToChar(yytext); return CHAR_LITERAL; }


%%

int hexToInt(const char* hexStr) {
	int hexint = strtol(hexStr + 1, NULL, 16); 
	std::cout << hexint <<std::endl;
    return hexint;
}

char charLiteralToChar(const char* charLit) {
    if (charLit[1] != '\\') {
        return charLit[1]; 
    } else {
        switch (charLit[2]) {
            case 'b': return '\b';
            case 't': return '\t';
            case 'n': return '\n';
            case 'f': return '\f';
            case 'r': return '\r';
            case '\'': return '\'';
            case '"': return '\"';
            case '\\': return '\\';
            default: return '\0'; 
        }
    }
}

