/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    IDENTIFIER = 258,              /* IDENTIFIER  */
    INT_LITERAL = 259,             /* INT_LITERAL  */
    CHAR_LITERAL = 260,            /* CHAR_LITERAL  */
    REAL_LITERAL = 261,            /* REAL_LITERAL  */
    HEX_LITERAL = 262,             /* HEX_LITERAL  */
    FLOAT_LITERAL = 263,           /* FLOAT_LITERAL  */
    ADDOP = 264,                   /* ADDOP  */
    MULOP = 265,                   /* MULOP  */
    ANDOP = 266,                   /* ANDOP  */
    RELOP = 267,                   /* RELOP  */
    EXPOP = 268,                   /* EXPOP  */
    REMOP = 269,                   /* REMOP  */
    NEGOP = 270,                   /* NEGOP  */
    MODOP = 271,                   /* MODOP  */
    NOTOP = 272,                   /* NOTOP  */
    OROP = 273,                    /* OROP  */
    ARROW = 274,                   /* ARROW  */
    BEGIN_ = 275,                  /* BEGIN_  */
    CASE = 276,                    /* CASE  */
    CHARACTER = 277,               /* CHARACTER  */
    ELSE = 278,                    /* ELSE  */
    END = 279,                     /* END  */
    ENDSWITCH = 280,               /* ENDSWITCH  */
    FUNCTION = 281,                /* FUNCTION  */
    INTEGER = 282,                 /* INTEGER  */
    IS = 283,                      /* IS  */
    LIST = 284,                    /* LIST  */
    OF = 285,                      /* OF  */
    OTHERS = 286,                  /* OTHERS  */
    RETURNS = 287,                 /* RETURNS  */
    SWITCH = 288,                  /* SWITCH  */
    WHEN = 289,                    /* WHEN  */
    REAL = 290,                    /* REAL  */
    IF = 291,                      /* IF  */
    THEN = 292,                    /* THEN  */
    ELSIF = 293,                   /* ELSIF  */
    ENDIF = 294,                   /* ENDIF  */
    FOLD = 295,                    /* FOLD  */
    ENDFOLD = 296,                 /* ENDFOLD  */
    LEFT = 297,                    /* LEFT  */
    RIGHT = 298                    /* RIGHT  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 37 "parser.y"

	int direction;
	int boolean_value;
	CharPtr iden;
	Operators oper;
	double value;
	vector<double>* list;

#line 116 "parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
