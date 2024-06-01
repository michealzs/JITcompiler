/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 8 "parser.y"


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


#line 98 "parser.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_IDENTIFIER = 3,                 /* IDENTIFIER  */
  YYSYMBOL_INT_LITERAL = 4,                /* INT_LITERAL  */
  YYSYMBOL_CHAR_LITERAL = 5,               /* CHAR_LITERAL  */
  YYSYMBOL_REAL_LITERAL = 6,               /* REAL_LITERAL  */
  YYSYMBOL_HEX_LITERAL = 7,                /* HEX_LITERAL  */
  YYSYMBOL_FLOAT_LITERAL = 8,              /* FLOAT_LITERAL  */
  YYSYMBOL_ADDOP = 9,                      /* ADDOP  */
  YYSYMBOL_MULOP = 10,                     /* MULOP  */
  YYSYMBOL_ANDOP = 11,                     /* ANDOP  */
  YYSYMBOL_RELOP = 12,                     /* RELOP  */
  YYSYMBOL_EXPOP = 13,                     /* EXPOP  */
  YYSYMBOL_REMOP = 14,                     /* REMOP  */
  YYSYMBOL_NEGOP = 15,                     /* NEGOP  */
  YYSYMBOL_NOTOP = 16,                     /* NOTOP  */
  YYSYMBOL_OROP = 17,                      /* OROP  */
  YYSYMBOL_ARROW = 18,                     /* ARROW  */
  YYSYMBOL_BEGIN_ = 19,                    /* BEGIN_  */
  YYSYMBOL_CASE = 20,                      /* CASE  */
  YYSYMBOL_CHARACTER = 21,                 /* CHARACTER  */
  YYSYMBOL_ELSE = 22,                      /* ELSE  */
  YYSYMBOL_END = 23,                       /* END  */
  YYSYMBOL_ENDSWITCH = 24,                 /* ENDSWITCH  */
  YYSYMBOL_FUNCTION = 25,                  /* FUNCTION  */
  YYSYMBOL_INTEGER = 26,                   /* INTEGER  */
  YYSYMBOL_IS = 27,                        /* IS  */
  YYSYMBOL_LIST = 28,                      /* LIST  */
  YYSYMBOL_OF = 29,                        /* OF  */
  YYSYMBOL_OTHERS = 30,                    /* OTHERS  */
  YYSYMBOL_RETURNS = 31,                   /* RETURNS  */
  YYSYMBOL_SWITCH = 32,                    /* SWITCH  */
  YYSYMBOL_WHEN = 33,                      /* WHEN  */
  YYSYMBOL_REAL = 34,                      /* REAL  */
  YYSYMBOL_IF = 35,                        /* IF  */
  YYSYMBOL_THEN = 36,                      /* THEN  */
  YYSYMBOL_ELSIF = 37,                     /* ELSIF  */
  YYSYMBOL_ENDIF = 38,                     /* ENDIF  */
  YYSYMBOL_FOLD = 39,                      /* FOLD  */
  YYSYMBOL_ENDFOLD = 40,                   /* ENDFOLD  */
  YYSYMBOL_LEFT = 41,                      /* LEFT  */
  YYSYMBOL_RIGHT = 42,                     /* RIGHT  */
  YYSYMBOL_43_ = 43,                       /* ';'  */
  YYSYMBOL_44_ = 44,                       /* ','  */
  YYSYMBOL_45_ = 45,                       /* ':'  */
  YYSYMBOL_46_ = 46,                       /* '('  */
  YYSYMBOL_47_ = 47,                       /* ')'  */
  YYSYMBOL_YYACCEPT = 48,                  /* $accept  */
  YYSYMBOL_function = 49,                  /* function  */
  YYSYMBOL_function_header = 50,           /* function_header  */
  YYSYMBOL_parameters = 51,                /* parameters  */
  YYSYMBOL_more_parameters = 52,           /* more_parameters  */
  YYSYMBOL_parameter = 53,                 /* parameter  */
  YYSYMBOL_type = 54,                      /* type  */
  YYSYMBOL_optional_variable = 55,         /* optional_variable  */
  YYSYMBOL_variables = 56,                 /* variables  */
  YYSYMBOL_variable = 57,                  /* variable  */
  YYSYMBOL_list = 58,                      /* list  */
  YYSYMBOL_expressions = 59,               /* expressions  */
  YYSYMBOL_body = 60,                      /* body  */
  YYSYMBOL_statement_ = 61,                /* statement_  */
  YYSYMBOL_statement = 62,                 /* statement  */
  YYSYMBOL_cases = 63,                     /* cases  */
  YYSYMBOL_case = 64,                      /* case  */
  YYSYMBOL_fold_statement = 65,            /* fold_statement  */
  YYSYMBOL_direction = 66,                 /* direction  */
  YYSYMBOL_list_choice = 67,               /* list_choice  */
  YYSYMBOL_if_statement = 68,              /* if_statement  */
  YYSYMBOL_elsif_clauses = 69,             /* elsif_clauses  */
  YYSYMBOL_condition = 70,                 /* condition  */
  YYSYMBOL_relation = 71,                  /* relation  */
  YYSYMBOL_expression = 72,                /* expression  */
  YYSYMBOL_arithmetic_operator = 73,       /* arithmetic_operator  */
  YYSYMBOL_term = 74,                      /* term  */
  YYSYMBOL_factor = 75,                    /* factor  */
  YYSYMBOL_exponent = 76,                  /* exponent  */
  YYSYMBOL_unary = 77,                     /* unary  */
  YYSYMBOL_primary = 78                    /* primary  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if 1

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* 1 */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  7
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   246

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  48
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  31
/* YYNRULES -- Number of rules.  */
#define YYNRULES  82
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  169

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   297


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      46,    47,     2,     2,    44,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    45,    43,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    75,    75,    78,    79,    80,    83,    86,    86,    89,
      92,    93,    94,    97,    98,    99,   102,   103,   104,   107,
     108,   111,   114,   115,   118,   121,   122,   125,   126,   127,
     128,   128,   129,   142,   152,   160,   163,   166,   166,   170,
     171,   174,   175,   178,   179,   182,   183,   184,   185,   188,
     189,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   205,   205,   205,   205,   205,   208,   209,   212,   213,
     214,   217,   218,   221,   222,   225,   226,   227,   228,   229,
     230,   231,   232
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "IDENTIFIER",
  "INT_LITERAL", "CHAR_LITERAL", "REAL_LITERAL", "HEX_LITERAL",
  "FLOAT_LITERAL", "ADDOP", "MULOP", "ANDOP", "RELOP", "EXPOP", "REMOP",
  "NEGOP", "NOTOP", "OROP", "ARROW", "BEGIN_", "CASE", "CHARACTER", "ELSE",
  "END", "ENDSWITCH", "FUNCTION", "INTEGER", "IS", "LIST", "OF", "OTHERS",
  "RETURNS", "SWITCH", "WHEN", "REAL", "IF", "THEN", "ELSIF", "ENDIF",
  "FOLD", "ENDFOLD", "LEFT", "RIGHT", "';'", "','", "':'", "'('", "')'",
  "$accept", "function", "function_header", "parameters",
  "more_parameters", "parameter", "type", "optional_variable", "variables",
  "variable", "list", "expressions", "body", "statement_", "statement",
  "cases", "case", "fold_statement", "direction", "list_choice",
  "if_statement", "elsif_clauses", "condition", "relation", "expression",
  "arithmetic_operator", "term", "factor", "exponent", "unary", "primary", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-109)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-18)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      21,   -32,    17,    38,    31,  -109,    16,  -109,    15,     4,
      45,  -109,    85,    32,   158,    58,    61,  -109,   179,     9,
      70,    94,  -109,   158,  -109,  -109,  -109,    95,   158,   155,
    -109,   137,   143,   131,   129,  -109,  -109,  -109,  -109,  -109,
     119,   145,   119,   125,   125,   -11,   119,   157,   138,  -109,
    -109,   216,   180,   102,  -109,   182,  -109,  -109,  -109,  -109,
    -109,   153,    61,   158,    75,  -109,   119,   216,  -109,  -109,
    -109,  -109,  -109,   119,  -109,   189,   125,   125,    10,  -109,
     209,    57,  -109,  -109,   223,   154,  -109,  -109,    93,  -109,
    -109,  -109,  -109,   119,    93,    93,    93,    93,  -109,  -109,
     170,   165,   163,   173,  -109,    56,  -109,    18,   147,   139,
     139,   119,   119,     9,  -109,     6,  -109,   180,   216,   102,
    -109,  -109,  -109,   160,  -109,  -109,  -109,    46,  -109,  -109,
    -109,    47,   216,   172,  -109,   119,  -109,   171,   169,   210,
     197,  -109,   119,   125,    37,   146,   216,  -109,  -109,   199,
      75,   216,   100,     9,  -109,   119,  -109,    75,   184,     9,
     190,   216,   191,   211,   172,  -109,  -109,  -109,  -109
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     5,     0,     1,     0,     0,
       0,    13,     0,     0,     0,     0,     8,    15,     0,     0,
       0,     0,    16,     0,    12,    10,    11,     0,     0,     0,
       6,     0,     0,     0,    82,    54,    55,    56,    57,    58,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    31,
      30,    28,    60,    67,    70,    71,    74,     2,    18,     9,
       3,     0,     8,     0,     0,    26,     0,    53,    76,    77,
      78,    79,    80,     0,    73,     0,     0,     0,    27,    48,
       0,     0,    37,    38,     0,     0,    24,    25,    61,    63,
      62,    64,    65,     0,     0,     0,     0,     0,     4,     7,
       0,     0,     0,     0,    34,    47,    73,     0,     0,     0,
       0,     0,     0,     0,    61,     0,    51,    59,    52,    66,
      68,    69,    72,     0,    19,    81,    75,     0,    49,    45,
      46,     0,    50,    43,    40,     0,    39,     0,     0,     0,
       0,    33,     0,     0,     0,     0,    23,    36,    20,     0,
       0,    29,     0,     0,    41,     0,    21,     0,     0,     0,
       0,    22,     0,     0,    43,    42,    35,    32,    44
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -109,  -109,  -109,  -109,   177,   212,     0,  -109,   228,  -109,
     120,  -109,  -109,  -108,   -63,  -109,  -109,  -109,  -109,  -109,
    -109,    78,   -37,   -25,   -40,   161,   156,   152,    23,  -109,
     -33
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     3,     4,    15,    30,    16,    27,    10,    11,    12,
     136,   145,    20,    47,    48,   127,   141,    49,    84,   137,
      50,   144,    78,    79,    51,    93,    52,    53,    54,    55,
      56
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      67,   101,    75,    80,    80,   133,    85,    81,    74,   134,
      33,     5,    34,    35,    36,    37,    38,    39,    32,    13,
       6,   109,     1,    59,    40,    41,   102,   110,    61,   109,
      82,    83,     8,   103,     9,   110,    80,   108,     7,   105,
     107,    42,    43,   106,    44,   160,     2,    14,    45,    18,
     -14,   164,   135,   118,   111,    46,    88,    89,    17,   153,
      90,    91,    92,   100,    19,   128,   139,   109,   109,    80,
      80,   131,   132,   110,   110,   154,   140,    23,    34,    35,
      36,    37,    38,    39,   129,   130,    21,   158,     9,    28,
      40,    41,   142,   113,   162,   146,    34,    68,    69,    70,
      71,    72,   151,    80,   -17,    29,   152,    42,    43,    41,
      44,   109,    95,    57,    45,   161,    96,   110,   120,   121,
     122,    46,    34,    35,    36,    37,    38,    39,    34,    35,
      36,    37,    38,    39,    40,    41,   159,    58,    60,    73,
      40,    76,    34,    35,    36,    37,    38,    39,    34,    68,
      69,    70,    71,    72,    40,    41,    88,    89,    13,   112,
      90,    91,    92,    88,    89,    46,    63,    90,    91,    92,
      64,    77,    88,    89,    65,    66,    90,    91,    92,    24,
      86,    87,    88,    89,    25,    77,    90,    91,    92,    94,
     155,    73,    26,   156,   116,    97,    98,   123,    88,    89,
      24,   116,    90,    91,    92,    25,   135,    31,   124,   143,
     125,   147,   148,    26,   149,   150,   104,   157,    88,    89,
     126,   112,    90,    91,    92,    88,    89,   163,   165,    90,
      91,    92,   114,    89,   166,   167,    90,    91,    92,    99,
      22,    62,   168,   138,   117,   115,   119
};

static const yytype_uint8 yycheck[] =
{
      40,    64,    42,    43,    44,   113,    46,    44,    41,     3,
       1,    43,     3,     4,     5,     6,     7,     8,    18,     3,
       3,    11,     1,    23,    15,    16,    66,    17,    28,    11,
      41,    42,     1,    73,     3,    17,    76,    77,     0,    76,
      77,    32,    33,    76,    35,   153,    25,    31,    39,    45,
      19,   159,    46,    93,    44,    46,     9,    10,    43,    22,
      13,    14,    15,    63,    19,    47,    20,    11,    11,   109,
     110,   111,   112,    17,    17,    38,    30,    45,     3,     4,
       5,     6,     7,     8,   109,   110,     1,   150,     3,    31,
      15,    16,    45,    36,   157,   135,     3,     4,     5,     6,
       7,     8,   142,   143,    19,    44,   143,    32,    33,    16,
      35,    11,    10,    43,    39,   155,    14,    17,    95,    96,
      97,    46,     3,     4,     5,     6,     7,     8,     3,     4,
       5,     6,     7,     8,    15,    16,    36,    43,    43,    46,
      15,    16,     3,     4,     5,     6,     7,     8,     3,     4,
       5,     6,     7,     8,    15,    16,     9,    10,     3,    12,
      13,    14,    15,     9,    10,    46,    29,    13,    14,    15,
      27,    46,     9,    10,    43,    46,    13,    14,    15,    21,
      23,    43,     9,    10,    26,    46,    13,    14,    15,     9,
      44,    46,    34,    47,    47,    13,    43,    27,     9,    10,
      21,    47,    13,    14,    15,    26,    46,    28,    43,    37,
      47,    40,    43,    34,     4,    18,    27,    18,     9,    10,
      47,    12,    13,    14,    15,     9,    10,    43,    38,    13,
      14,    15,     9,    10,    43,    24,    13,    14,    15,    62,
      12,    29,   164,   123,    88,    84,    94
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,    25,    49,    50,    43,     3,     0,     1,     3,
      55,    56,    57,     3,    31,    51,    53,    43,    45,    19,
      60,     1,    56,    45,    21,    26,    34,    54,    31,    44,
      52,    28,    54,     1,     3,     4,     5,     6,     7,     8,
      15,    16,    32,    33,    35,    39,    46,    61,    62,    65,
      68,    72,    74,    75,    76,    77,    78,    43,    43,    54,
      43,    54,    53,    29,    27,    43,    46,    72,     4,     5,
       6,     7,     8,    46,    78,    72,    16,    46,    70,    71,
      72,    70,    41,    42,    66,    72,    23,    43,     9,    10,
      13,    14,    15,    73,     9,    10,    14,    13,    43,    52,
      54,    62,    72,    72,    27,    70,    78,    70,    72,    11,
      17,    44,    12,    36,     9,    73,    47,    74,    72,    75,
      76,    76,    76,    27,    43,    47,    47,    63,    47,    71,
      71,    72,    72,    61,     3,    46,    58,    67,    58,    20,
      30,    64,    45,    37,    69,    59,    72,    40,    43,     4,
      18,    72,    70,    22,    38,    44,    47,    18,    62,    36,
      61,    72,    62,    43,    61,    38,    43,    24,    69
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    48,    49,    50,    50,    50,    51,    52,    52,    53,
      54,    54,    54,    55,    55,    55,    56,    56,    56,    57,
      57,    58,    59,    59,    60,    61,    61,    62,    62,    62,
      62,    62,    62,    63,    63,    64,    65,    66,    66,    67,
      67,    68,    68,    69,    69,    70,    70,    70,    70,    71,
      71,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      72,    73,    73,    73,    73,    73,    74,    74,    75,    75,
      75,    76,    76,    77,    77,    78,    78,    78,    78,    78,
      78,    78,    78
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     4,     5,     6,     2,     2,     3,     0,     3,
       1,     1,     1,     1,     0,     2,     2,     0,     2,     6,
       8,     3,     3,     1,     3,     2,     2,     2,     1,     6,
       1,     1,     9,     2,     0,     5,     5,     1,     1,     1,
       1,     6,     8,     0,     5,     3,     3,     2,     1,     3,
       3,     3,     3,     2,     1,     1,     1,     1,     1,     3,
       1,     1,     1,     1,     1,     1,     3,     1,     3,     3,
       1,     1,     3,     2,     1,     3,     1,     1,     1,     1,
       1,     4,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
  if (!yypact_value_is_default (yyn))
    {
      /* Start YYX at -YYN if negative to avoid negative indexes in
         YYCHECK.  In other words, skip the first -YYN actions for
         this state because they are default actions.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;
      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yyx;
      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;
      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* function: function_header optional_variable body ';'  */
#line 75 "parser.y"
                                                    {result = (yyvsp[-1].value);}
#line 1560 "parser.tab.c"
    break;

  case 9: /* parameter: IDENTIFIER ':' type  */
#line 89 "parser.y"
                        { scalars.insert((yyvsp[-2].iden), params[countParams++]);}
#line 1566 "parser.tab.c"
    break;

  case 19: /* variable: IDENTIFIER ':' type IS statement ';'  */
#line 107 "parser.y"
                                             {scalars.insert((yyvsp[-5].iden), (yyvsp[-1].value));}
#line 1572 "parser.tab.c"
    break;

  case 20: /* variable: IDENTIFIER ':' LIST OF type IS list ';'  */
#line 108 "parser.y"
                                                {lists.insert((yyvsp[-7].iden), (yyvsp[-1].list));}
#line 1578 "parser.tab.c"
    break;

  case 21: /* list: '(' expressions ')'  */
#line 111 "parser.y"
                            {(yyval.list) = (yyvsp[-1].list);}
#line 1584 "parser.tab.c"
    break;

  case 22: /* expressions: expressions ',' expression  */
#line 114 "parser.y"
                                   {(yyvsp[-2].list)->push_back((yyvsp[0].value)); (yyval.list) = (yyvsp[-2].list);}
#line 1590 "parser.tab.c"
    break;

  case 23: /* expressions: expression  */
#line 115 "parser.y"
                   {(yyval.list) = new vector<double>(); (yyval.list)->push_back((yyvsp[0].value));}
#line 1596 "parser.tab.c"
    break;

  case 24: /* body: BEGIN_ statement_ END  */
#line 118 "parser.y"
                              {(yyval.value) = (yyvsp[-1].value);}
#line 1602 "parser.tab.c"
    break;

  case 26: /* statement_: error ';'  */
#line 122 "parser.y"
                  {(yyval.value) = 0;}
#line 1608 "parser.tab.c"
    break;

  case 27: /* statement: WHEN condition  */
#line 125 "parser.y"
                       {(yyval.value) = (yyvsp[0].value);}
#line 1614 "parser.tab.c"
    break;

  case 29: /* statement: WHEN condition ',' expression ':' expression  */
#line 127 "parser.y"
                                                     {(yyval.value) = (yyvsp[-4].value) ? (yyvsp[-2].value) : (yyvsp[0].value);}
#line 1620 "parser.tab.c"
    break;

  case 32: /* statement: SWITCH expression IS cases OTHERS ARROW statement ';' ENDSWITCH  */
#line 129 "parser.y"
                                                                        {
        double switchExprValue = (yyvsp[-7].value);
        Case *caseArray = (yyvsp[-5].casesArray);
        double result = (yyvsp[-2].value); 
        for (int i = 0; i < MAX_CASES && caseArray[i].caseValue != 0; ++i) {
            result = (caseArray[i].caseValue == switchExprValue) ? caseArray[i].statementValue : result;
        }

        (yyval.value) = result;
    }
#line 1635 "parser.tab.c"
    break;

  case 33: /* cases: cases case  */
#line 142 "parser.y"
                   {
        int i = 0;
        while (i < MAX_CASES && (yyvsp[-1].casesArray)[i].caseValue != 0) ++i;
        if (i < MAX_CASES) {
            (yyvsp[-1].casesArray)[i] = (yyvsp[0].aCase);
            for (int i = 0; i < MAX_CASES; ++i) {
    			(yyval.casesArray)[i] = (yyvsp[-1].casesArray)[i];
			}
        }
    }
#line 1650 "parser.tab.c"
    break;

  case 34: /* cases: %empty  */
#line 152 "parser.y"
               {
        Case emptyCases[MAX_CASES] = {{0, 0}};
        for (int i = 0; i < MAX_CASES; ++i) {
    		(yyval.casesArray)[i] = emptyCases[i];
		}
    }
#line 1661 "parser.tab.c"
    break;

  case 35: /* case: CASE INT_LITERAL ARROW statement ';'  */
#line 160 "parser.y"
                                             { (yyval.aCase) = (Case){static_cast<int>((yyvsp[-3].value)), (yyvsp[-1].value)}; }
#line 1667 "parser.tab.c"
    break;

  case 36: /* fold_statement: FOLD direction arithmetic_operator list_choice ENDFOLD  */
#line 163 "parser.y"
                                                           { (yyval.value) = ((yyvsp[-3].direction) == LEFT) ? fold_left((yyvsp[-2].oper), (yyvsp[-1].list)) : fold_right((yyvsp[-2].oper), (yyvsp[-1].list)); }
#line 1673 "parser.tab.c"
    break;

  case 37: /* direction: LEFT  */
#line 166 "parser.y"
         { (yyval.direction) = LEFT; }
#line 1679 "parser.tab.c"
    break;

  case 38: /* direction: RIGHT  */
#line 166 "parser.y"
                                { (yyval.direction) = RIGHT; }
#line 1685 "parser.tab.c"
    break;

  case 39: /* list_choice: list  */
#line 170 "parser.y"
         { (yyval.list) = (yyvsp[0].list); }
#line 1691 "parser.tab.c"
    break;

  case 40: /* list_choice: IDENTIFIER  */
#line 171 "parser.y"
               { lists.find((yyvsp[0].iden), listValue); (yyval.list) = listValue; }
#line 1697 "parser.tab.c"
    break;

  case 41: /* if_statement: IF condition THEN statement_ elsif_clauses ENDIF  */
#line 174 "parser.y"
                                                     { (yyval.value) = (yyvsp[-4].value) ? (yyvsp[-2].value) : (yyvsp[-1].value); }
#line 1703 "parser.tab.c"
    break;

  case 42: /* if_statement: IF condition THEN statement_ elsif_clauses ELSE statement_ ENDIF  */
#line 175 "parser.y"
                                                                     { (yyval.value) = (yyvsp[-6].value) ? (yyvsp[-4].value) : ((yyvsp[-3].value) ? (yyvsp[-3].value) : (yyvsp[-1].value)); }
#line 1709 "parser.tab.c"
    break;

  case 43: /* elsif_clauses: %empty  */
#line 178 "parser.y"
           { (yyval.value) = 0; }
#line 1715 "parser.tab.c"
    break;

  case 44: /* elsif_clauses: ELSIF condition THEN statement_ elsif_clauses  */
#line 179 "parser.y"
                                                  { (yyval.value) = (yyvsp[-3].value) ? (yyvsp[-1].value) : (yyvsp[0].value); }
#line 1721 "parser.tab.c"
    break;

  case 45: /* condition: condition ANDOP relation  */
#line 182 "parser.y"
                                 {(yyval.value) = (yyvsp[-2].value) && (yyvsp[-1].oper);}
#line 1727 "parser.tab.c"
    break;

  case 46: /* condition: condition OROP relation  */
#line 183 "parser.y"
                                {(yyval.value) = (yyvsp[-2].value) || (yyvsp[0].value); }
#line 1733 "parser.tab.c"
    break;

  case 47: /* condition: NOTOP condition  */
#line 184 "parser.y"
                        { (yyval.value) = !(yyvsp[0].value); }
#line 1739 "parser.tab.c"
    break;

  case 48: /* condition: relation  */
#line 185 "parser.y"
                 { (yyval.value) = (yyvsp[0].value); }
#line 1745 "parser.tab.c"
    break;

  case 49: /* relation: '(' condition ')'  */
#line 188 "parser.y"
                          {(yyval.value) = (yyvsp[-1].value);}
#line 1751 "parser.tab.c"
    break;

  case 50: /* relation: expression RELOP expression  */
#line 189 "parser.y"
                                    {(yyval.value) = evaluateRelational((yyvsp[-2].value), (yyvsp[-1].oper), (yyvsp[0].value));}
#line 1757 "parser.tab.c"
    break;

  case 51: /* expression: '(' expression ')'  */
#line 193 "parser.y"
                           { (yyval.value) = (yyvsp[-1].value); }
#line 1763 "parser.tab.c"
    break;

  case 52: /* expression: expression arithmetic_operator expression  */
#line 194 "parser.y"
                                             { (yyval.value) = evaluateArithmetic((yyvsp[-2].value), (yyvsp[-1].oper), (yyvsp[0].value)); }
#line 1769 "parser.tab.c"
    break;

  case 53: /* expression: NEGOP expression  */
#line 195 "parser.y"
                    { (yyval.value) = -(yyvsp[0].value); }
#line 1775 "parser.tab.c"
    break;

  case 54: /* expression: INT_LITERAL  */
#line 196 "parser.y"
               { (yyval.value) = (yyvsp[0].value); }
#line 1781 "parser.tab.c"
    break;

  case 55: /* expression: CHAR_LITERAL  */
#line 197 "parser.y"
                { (yyval.value) = (yyvsp[0].value); }
#line 1787 "parser.tab.c"
    break;

  case 56: /* expression: REAL_LITERAL  */
#line 198 "parser.y"
                { (yyval.value) = (yyvsp[0].value); }
#line 1793 "parser.tab.c"
    break;

  case 57: /* expression: HEX_LITERAL  */
#line 199 "parser.y"
               { (yyval.value) = (yyvsp[0].value); }
#line 1799 "parser.tab.c"
    break;

  case 58: /* expression: FLOAT_LITERAL  */
#line 200 "parser.y"
                 { (yyval.value) = (yyvsp[0].value); }
#line 1805 "parser.tab.c"
    break;

  case 59: /* expression: expression ADDOP term  */
#line 201 "parser.y"
                              {(yyval.value) = evaluateArithmetic((yyvsp[-2].value), (yyvsp[-1].oper), (yyvsp[0].value));}
#line 1811 "parser.tab.c"
    break;

  case 66: /* term: term ADDOP factor  */
#line 208 "parser.y"
                          {(yyval.value) = evaluateArithmetic((yyvsp[-2].value), (yyvsp[-1].oper), (yyvsp[0].value));}
#line 1817 "parser.tab.c"
    break;

  case 68: /* factor: factor MULOP exponent  */
#line 212 "parser.y"
                              {(yyval.value) = evaluateArithmetic((yyvsp[-2].value), (yyvsp[-1].oper), (yyvsp[0].value));}
#line 1823 "parser.tab.c"
    break;

  case 69: /* factor: factor REMOP exponent  */
#line 213 "parser.y"
                              { (yyval.value) = fmod((yyvsp[-2].value) , (yyvsp[0].value)); }
#line 1829 "parser.tab.c"
    break;

  case 72: /* exponent: unary EXPOP exponent  */
#line 218 "parser.y"
                             { (yyval.value) = pow((yyvsp[-2].value), (yyvsp[0].value));}
#line 1835 "parser.tab.c"
    break;

  case 73: /* unary: NOTOP primary  */
#line 221 "parser.y"
                      {(yyval.value) = (yyvsp[0].value);}
#line 1841 "parser.tab.c"
    break;

  case 75: /* primary: '(' expression ')'  */
#line 225 "parser.y"
                           {(yyval.value) = (yyvsp[-1].value);}
#line 1847 "parser.tab.c"
    break;

  case 81: /* primary: IDENTIFIER '(' expression ')'  */
#line 231 "parser.y"
                                      {(yyval.value) = extract_element((yyvsp[-3].iden), (yyvsp[-1].value)); }
#line 1853 "parser.tab.c"
    break;

  case 82: /* primary: IDENTIFIER  */
#line 232 "parser.y"
                   {if (!scalars.find((yyvsp[0].iden), (yyval.value))) appendError(UNDECLARED, (yyvsp[0].iden));}
#line 1859 "parser.tab.c"
    break;


#line 1863 "parser.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      {
        yypcontext_t yyctx
          = {yyssp, yytoken};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 234 "parser.y"


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
