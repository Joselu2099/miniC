/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "miniC.y" /* yacc.c:339  */

#include <stdio.h>
#include "listaSimbolos.h"
#include "listaCodigo.h"
#include <string.h>
#include <assert.h>
#include <stdlib.h>

extern int yylex();
extern int yylineno;

int errores_sintacticos = 0;
int errores_semanticos = 0;
extern int errores_lexicos;
void yyerror(const char *msg);
int ok();
int contadorString = 1;
int contador_etiq = 1;
void imprimirLS();
void imprimirCodigo(ListaC codigo);
char *obtenerReg();
void liberarReg(char *reg);
char *concatena(char *arg1, char *arg2);
char *concatena2(char *arg1, int i);
char *nuevaEtiqueta();
char registros[10] = {0};

//Lista de simbolos
Lista l;


#line 98 "miniC.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "miniC.tab.h".  */
#ifndef YY_YY_MINIC_TAB_H_INCLUDED
# define YY_YY_MINIC_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 33 "miniC.y" /* yacc.c:355  */

	#include "listaCodigo.h"

#line 132 "miniC.tab.c" /* yacc.c:355  */

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    ID = 258,
    VOID = 259,
    CONST = 260,
    VAR = 261,
    COMMA = 262,
    IF = 263,
    ELSE = 264,
    WHILE = 265,
    PRINT = 266,
    READ = 267,
    STRING = 268,
    NUM = 269,
    PLUSOP = 270,
    MINUSOP = 271,
    POROP = 272,
    DIVOP = 273,
    LPAREN = 274,
    RPAREN = 275,
    SEMICOLON = 276,
    ASSIGNOP = 277,
    LCOR = 278,
    RCOR = 279,
    UMINUS = 280
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 39 "miniC.y" /* yacc.c:355  */

	char *str;
	ListaC codigo;

#line 175 "miniC.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_MINIC_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 192 "miniC.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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


#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   128

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  39
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  19
/* YYNRULES -- Number of rules.  */
#define YYNRULES  47
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  115

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   293

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    90,    90,    90,   101,   102,   105,   110,   111,   115,
     118,   134,   150,   153,   174,   200,   203,   204,   207,   208,
     213,   235,   252,   283,   312,   325,   326,   327,   330,   331,
     336,   361,   393,   430,   471,   482,   493,   504,   515,   523,
     525,   540,   549,   558,   561,   562,   565,   566
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "\"id\"", "\"void\"", "\"const\"",
  "\"var\"", "\",\"", "\"if\"", "\"else\"", "\"while\"", "\"print\"",
  "\"read\"", "\"string\"", "\"num\"", "\"+\"", "\"-\"", "\"*\"", "\"/\"",
  "\"(\"", "\")\"", "\";\"", "\"=\"", "\"{\"", "\"}\"", "UMINUS",
  "\"program\"", "\".\"", "\"function\"", "\":\"", "\"integer\"", "\":=\"",
  "\"begin\"", "\"end\"", "\"then\"", "\"do\"", "\"for\"", "\"to\"",
  "\"write\"", "$accept", "program", "$@1", "functions", "function",
  "declarations", "identifiers", "type", "constants", "compound_statement",
  "optional_statements", "statements", "statement", "print_list",
  "print_item", "read_list", "expression", "arguments", "expressions", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293
};
# endif

#define YYPACT_NINF -76

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-76)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -76,    14,   -18,   -76,     7,    16,    -1,    32,   -76,     2,
      63,    50,     0,    53,   -76,    70,    72,     1,    55,    83,
      61,     8,   -76,     9,    77,    75,    75,    74,   103,    88,
     -76,    76,    89,   -76,   -76,    72,    75,   105,   -76,   108,
      82,    75,    94,   -76,    75,    67,    46,    34,   111,    84,
      71,   -76,     1,    15,    87,    85,   -76,   -76,    96,    87,
      75,   -76,    98,    80,    75,    75,    75,    75,     1,     1,
     -76,    11,    75,   -76,    47,   -76,    87,   -76,    82,    75,
     -76,    87,    99,   113,   -76,   -76,    28,    28,   -76,   -76,
     112,   -76,   119,   -76,    10,    71,   -76,   104,    87,   -76,
      75,     1,   -76,    75,   -76,    97,    87,   -76,    42,    82,
       1,   -76,   -76,     0,   -76
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     0,     1,     0,     0,     0,     0,     5,     9,
       0,     0,     0,     0,     4,     0,     0,    17,     0,     0,
       0,     0,    10,     0,     0,     0,     0,     0,     0,     0,
      27,     0,    16,    18,     3,     0,     0,     0,     8,     0,
       0,     0,    40,    41,     0,     0,     0,     0,     0,     0,
       0,    15,     0,     0,    13,     0,    11,    12,     0,    20,
      45,    38,     0,     0,     0,     0,     0,     0,     0,     0,
      32,     0,     0,    31,     0,    28,    30,    19,     0,     0,
       7,    46,     0,    44,    43,    39,    34,    35,    36,    37,
      21,    23,     0,    26,     0,     0,    25,     0,    14,    42,
       0,     0,    33,     0,    29,     0,    47,    22,     0,     0,
       0,     9,    24,     0,     6
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -76,   -76,   -76,   -76,   -76,    12,    90,   -75,   -76,   -12,
     -76,   -76,   -45,   -76,    33,   -76,   -24,   -76,   -76
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,     2,     9,    11,    12,    23,    58,    21,    30,
      31,    32,    33,    74,    75,    71,    76,    82,    83
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      18,    46,    47,    97,    24,    15,    16,    77,     4,    25,
       5,    26,    54,    27,     3,    37,    39,    59,    92,     7,
      61,    63,    39,    90,    91,    64,    65,    66,    67,    38,
      10,    93,    17,    17,   111,     6,    81,    28,    40,    29,
      86,    87,    88,    89,    78,    66,    67,   103,    94,    64,
      65,    66,    67,     8,    95,    98,   107,    64,    65,    66,
      67,    64,    65,    66,    67,   112,    13,    96,    62,    69,
      42,    14,    19,    20,    42,    22,   106,   110,    42,   108,
      68,    43,    34,    44,    73,    43,    45,    44,    35,    43,
      45,    44,    36,    48,    45,    64,    65,    66,    67,    41,
      85,   114,    64,    65,    66,    67,    49,    50,    55,    51,
      52,    56,    57,    60,    70,    72,    79,    80,    84,    99,
     100,   101,   102,   113,   105,    53,   109,     0,   104
};

static const yytype_int8 yycheck[] =
{
      12,    25,    26,    78,     3,     5,     6,    52,    26,     8,
       3,    10,    36,    12,     0,     7,     7,    41,     7,    20,
      44,    45,     7,    68,    69,    15,    16,    17,    18,    21,
      28,    20,    32,    32,   109,    19,    60,    36,    29,    38,
      64,    65,    66,    67,    29,    17,    18,    37,    72,    15,
      16,    17,    18,    21,     7,    79,   101,    15,    16,    17,
      18,    15,    16,    17,    18,   110,     3,    20,     1,    35,
       3,    21,    19,     3,     3,     3,   100,    35,     3,   103,
      34,    14,    27,    16,    13,    14,    19,    16,     5,    14,
      19,    16,    31,    19,    19,    15,    16,    17,    18,    22,
      20,   113,    15,    16,    17,    18,     3,    19,     3,    33,
      21,     3,    30,    19,     3,    31,    31,    21,    20,    20,
       7,     9,     3,   111,    20,    35,    29,    -1,    95
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    40,    41,     0,    26,     3,    19,    20,    21,    42,
      28,    43,    44,     3,    21,     5,     6,    32,    48,    19,
       3,    47,     3,    45,     3,     8,    10,    12,    36,    38,
      48,    49,    50,    51,    27,     5,    31,     7,    21,     7,
      29,    22,     3,    14,    16,    19,    55,    55,    19,     3,
      19,    33,    21,    45,    55,     3,     3,    30,    46,    55,
      19,    55,     1,    55,    15,    16,    17,    18,    34,    35,
       3,    54,    31,    13,    52,    53,    55,    51,    29,    31,
      21,    55,    56,    57,    20,    20,    55,    55,    55,    55,
      51,    51,     7,    20,    55,     7,    20,    46,    55,    20,
       7,     9,     3,    37,    53,    20,    55,    51,    55,    29,
      35,    46,    51,    44,    48
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    39,    41,    40,    42,    42,    43,    44,    44,    44,
      45,    45,    46,    47,    47,    48,    49,    49,    50,    50,
      51,    51,    51,    51,    51,    51,    51,    51,    52,    52,
      53,    53,    54,    54,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    56,    56,    57,    57
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,    10,     3,     0,    12,     6,     4,     0,
       1,     3,     1,     3,     5,     3,     1,     0,     1,     3,
       3,     4,     6,     4,     8,     4,     4,     1,     1,     3,
       1,     1,     1,     3,     3,     3,     3,     3,     2,     3,
       1,     1,     4,     3,     1,     0,     1,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
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
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
            /* Fall through.  */
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

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
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
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
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
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
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
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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
        case 2:
#line 90 "miniC.y" /* yacc.c:1646  */
    { l = creaLS(); }
#line 1343 "miniC.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 90 "miniC.y" /* yacc.c:1646  */
    {
	    if(ok()){
		   imprimirLS(l); 	//Volcar .data del programa
		   concatenaLC((yyvsp[-2].codigo),(yyvsp[-1].codigo));
		   imprimirCodigo((yyvsp[-2].codigo));  //Volcar .text del programa
	    }
	    liberaLS(l);
	    liberaLC((yyvsp[-2].codigo));
	  }
#line 1357 "miniC.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 101 "miniC.y" /* yacc.c:1646  */
    {}
#line 1363 "miniC.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 102 "miniC.y" /* yacc.c:1646  */
    {}
#line 1369 "miniC.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 105 "miniC.y" /* yacc.c:1646  */
    { printf("Error: funciones no soportadas\n");
													   errores_semanticos++;
													 }
#line 1377 "miniC.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 110 "miniC.y" /* yacc.c:1646  */
    { (yyval.codigo)=(yyvsp[-5].codigo);}
#line 1383 "miniC.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 111 "miniC.y" /* yacc.c:1646  */
    { (yyval.codigo)=(yyvsp[-3].codigo);
						    concatenaLC((yyval.codigo),(yyvsp[-1].codigo));
						    liberaLC((yyvsp[-1].codigo));
						  }
#line 1392 "miniC.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 115 "miniC.y" /* yacc.c:1646  */
    { (yyval.codigo)=creaLC();}
#line 1398 "miniC.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 118 "miniC.y" /* yacc.c:1646  */
    {
			//Comprobar si $1 esta en la lista
			PosicionLista p = buscaLS(l,(yyvsp[0].str));
  			if (p != finalLS(l)) {
				//Estoy redeclarando el identificador
				printf("Error en linea %d: %s redeclarado\n", yylineno, (yyvsp[0].str));
				errores_semanticos++;
			}
			else{
				//Primera declaracion de $1: es correcto
				Simbolo aux;
				aux.nombre = (yyvsp[0].str);
				aux.tipo = VARIABLE;
				insertaLS(l,finalLS(l),aux);
			}
	    }
#line 1419 "miniC.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 134 "miniC.y" /* yacc.c:1646  */
    { PosicionLista p = buscaLS(l,(yyvsp[0].str));
		  		     if (p != finalLS(l)) {
						//Estoy redeclarando el identificador
						printf("Error en linea %d: %s redeclarado\n", yylineno, (yyvsp[0].str));
						errores_semanticos++;
				     }
				     else{
						//Primera declaracion de $3: es correcto
						Simbolo aux;
						aux.nombre = (yyvsp[0].str);
						aux.tipo = VARIABLE;
						insertaLS(l,finalLS(l),aux);
				     }
				    }
#line 1438 "miniC.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 150 "miniC.y" /* yacc.c:1646  */
    {}
#line 1444 "miniC.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 153 "miniC.y" /* yacc.c:1646  */
    { PosicionLista p = buscaLS(l,(yyvsp[-2].str));
		  		    if (p != finalLS(l)) {
								//Estoy redeclarando la constante
								printf("Error en linea %d: %s redeclarado\n", yylineno, (yyvsp[-2].str));
								errores_semanticos++;
				    	}else{
								//Primera declaracion de $1: es correcto
								Simbolo aux;
								aux.nombre = (yyvsp[-2].str);
								aux.tipo = CONSTANTE;
								insertaLS(l,finalLS(l),aux);
				    	}
					    (yyval.codigo)=(yyvsp[0].codigo);
					    Operacion oper;
					    oper.op = "sw";
					    oper.res = recuperaResLC((yyvsp[0].codigo));
					    oper.arg1 = concatena("_",(yyvsp[-2].str));
					    oper.arg2 = NULL;
					    insertaLC((yyval.codigo),finalLC((yyval.codigo)),oper);
					    liberarReg(oper.res);
				   }
#line 1470 "miniC.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 174 "miniC.y" /* yacc.c:1646  */
    { PosicionLista p = buscaLS(l,(yyvsp[-2].str));
				  		 if (p != finalLS(l)) {
							//Estoy redeclarando la constante
							printf("Error en linea %d: %s redeclarado\n", yylineno, (yyvsp[-2].str));
							errores_semanticos++;
						 }
						 else{
							//Primera declaracion de $3: es correcto
							Simbolo aux;
							aux.nombre = (yyvsp[-2].str);
							aux.tipo = CONSTANTE;
							insertaLS(l,finalLS(l),aux);
						 }
						 (yyval.codigo)=(yyvsp[-4].codigo);
						 Operacion oper;
						 oper.op = "sw";
						 oper.res = recuperaResLC((yyvsp[0].codigo));
						 oper.arg1 = concatena("_",(yyvsp[-2].str));
						 oper.arg2 = NULL;
						 insertaLC((yyvsp[0].codigo),finalLC((yyvsp[0].codigo)),oper);
						 concatenaLC((yyval.codigo),(yyvsp[0].codigo));
						 liberarReg(oper.res);
						 liberaLC((yyvsp[0].codigo));
						}
#line 1499 "miniC.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 200 "miniC.y" /* yacc.c:1646  */
    { (yyval.codigo)=(yyvsp[-1].codigo);}
#line 1505 "miniC.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 203 "miniC.y" /* yacc.c:1646  */
    { (yyval.codigo)=(yyvsp[0].codigo);}
#line 1511 "miniC.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 204 "miniC.y" /* yacc.c:1646  */
    { (yyval.codigo)=creaLC();}
#line 1517 "miniC.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 207 "miniC.y" /* yacc.c:1646  */
    { (yyval.codigo)=(yyvsp[0].codigo); }
#line 1523 "miniC.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 208 "miniC.y" /* yacc.c:1646  */
    { (yyval.codigo)=(yyvsp[-2].codigo);
					concatenaLC((yyval.codigo),(yyvsp[0].codigo));
				      }
#line 1531 "miniC.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 213 "miniC.y" /* yacc.c:1646  */
    {  // Busqueda del si­mbolo "$1"
				    PosicionLista p = buscaLS(l,(yyvsp[-2].str));
				    if (p != finalLS(l)) {
					    Simbolo aux = recuperaLS(l,p);
					    if (aux.tipo != VARIABLE) {
						printf("Error en linea %d. No se puede asignar a la CONSTANTE %s\n",yylineno,aux.nombre);
						errores_semanticos++;
				    	    }
				    }
				    else {
					    printf("Error en linea %d. No encontrado %s\n",yylineno,(yyvsp[-2].str));
					    errores_semanticos++;
				    }
				    (yyval.codigo)=(yyvsp[0].codigo);
				    Operacion oper;
				    oper.op = "sw";
				    oper.res = recuperaResLC((yyvsp[0].codigo));
				    oper.arg1 = concatena("_",(yyvsp[-2].str));
				    oper.arg2 = NULL;
				    insertaLC((yyval.codigo),finalLC((yyval.codigo)),oper);
				    liberarReg(oper.res);
				 }
#line 1558 "miniC.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 235 "miniC.y" /* yacc.c:1646  */
    {  (yyval.codigo)=(yyvsp[-2].codigo);
						char *etiq = nuevaEtiqueta();
						Operacion oper;
						oper.op = "beqz";
						oper.res = recuperaResLC((yyvsp[-2].codigo));
						oper.arg1 = etiq;
						oper.arg2 = NULL;
						insertaLC((yyval.codigo),finalLC((yyval.codigo)),oper);
						concatenaLC((yyval.codigo),(yyvsp[0].codigo));
						liberaLC((yyvsp[0].codigo));

						oper.op = "etiq";
						oper.res = etiq;
						oper.arg1 = NULL;
						oper.arg2 = NULL;
						insertaLC((yyval.codigo),finalLC((yyval.codigo)),oper);
						}
#line 1580 "miniC.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 252 "miniC.y" /* yacc.c:1646  */
    { (yyval.codigo)=(yyvsp[-4].codigo);
								char *etiq = nuevaEtiqueta();
								char *etiq1 = nuevaEtiqueta();
								Operacion oper;
								oper.op = "beqz";
								oper.res = recuperaResLC((yyvsp[-4].codigo));
								oper.arg1 = etiq;
								oper.arg2 = NULL;
								insertaLC((yyval.codigo),finalLC((yyval.codigo)),oper);
								concatenaLC((yyval.codigo),(yyvsp[-2].codigo));
								liberaLC((yyvsp[-2].codigo));

								oper.op ="b";
								oper.res = etiq1;
								oper.arg1 = NULL;
								oper.arg2 = NULL;
								insertaLC((yyval.codigo),finalLC((yyval.codigo)),oper);

								oper.op = "etiq";
								oper.res = etiq;
								oper.arg1 = NULL;
								oper.arg2 = NULL;
								insertaLC((yyval.codigo),finalLC((yyval.codigo)),oper);

								oper.op = "etiq";
								oper.res = etiq1;
								oper.arg1 = NULL;
								oper.arg2 = NULL;
								insertaLC((yyval.codigo),finalLC((yyval.codigo)),oper);

							      }
#line 1616 "miniC.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 283 "miniC.y" /* yacc.c:1646  */
    { (yyval.codigo)=creaLC();
						char *etiq = nuevaEtiqueta();
						char *etiq1 = nuevaEtiqueta();
						Operacion oper;
						oper.op = "etiq";
						oper.res = etiq;
						oper.arg1 = NULL;
						oper.arg2 = NULL;
						insertaLC((yyval.codigo),finalLC((yyval.codigo)),oper);

						oper.op = "beqz";
						oper.res = recuperaResLC((yyvsp[-2].codigo));
						oper.arg1 = etiq1;
						oper.arg2 = NULL;
						insertaLC((yyval.codigo),finalLC((yyval.codigo)),oper);
						concatenaLC((yyval.codigo),(yyvsp[0].codigo));

						oper.op = "b";
						oper.res = etiq;
						oper.arg1 = NULL;
						oper.arg2 = NULL;
						insertaLC((yyval.codigo),finalLC((yyval.codigo)),oper);

						oper.op = "etiq";
						oper.res = etiq1;
						oper.arg1 = NULL;
						oper.arg2 = NULL;
						insertaLC((yyval.codigo),finalLC((yyval.codigo)),oper);
					     }
#line 1650 "miniC.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 312 "miniC.y" /* yacc.c:1646  */
    { PosicionLista p = buscaLS(l,(yyvsp[-6].str));
									if (p != finalLS(l)) {
									    Simbolo aux = recuperaLS(l,p);
									    if (aux.tipo != VARIABLE) {
										printf("Error en linea %d. No se puede asignar a la CONSTANTE %s\n",yylineno,aux.nombre);
										errores_semanticos++;
								    	    }
									 }
									 else {
										printf("Error en linea %d. No encontrado %s\n",yylineno,(yyvsp[-6].str));
										errores_semanticos++;
									 }
									}
#line 1668 "miniC.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 325 "miniC.y" /* yacc.c:1646  */
    { (yyval.codigo)=(yyvsp[-1].codigo);}
#line 1674 "miniC.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 326 "miniC.y" /* yacc.c:1646  */
    { (yyval.codigo)=(yyvsp[-1].codigo);}
#line 1680 "miniC.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 327 "miniC.y" /* yacc.c:1646  */
    { (yyval.codigo)=(yyvsp[0].codigo);}
#line 1686 "miniC.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 330 "miniC.y" /* yacc.c:1646  */
    { (yyval.codigo)=(yyvsp[0].codigo);}
#line 1692 "miniC.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 331 "miniC.y" /* yacc.c:1646  */
    { (yyval.codigo)=(yyvsp[-2].codigo);
					 concatenaLC((yyval.codigo),(yyvsp[0].codigo));
					 liberaLC((yyvsp[0].codigo));}
#line 1700 "miniC.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 336 "miniC.y" /* yacc.c:1646  */
    { (yyval.codigo)=(yyvsp[0].codigo);
			  Operacion oper;
			  oper.op = "li";
			  oper.res = "$v0";
			  oper.arg1 = "1";
			  oper.arg2 = NULL;

			  insertaLC((yyval.codigo),finalLC((yyval.codigo)),oper);

			  oper.op = "move";
			  oper.res = "$a0";
			  oper.arg1 = recuperaResLC((yyvsp[0].codigo));
			  oper.arg2 = NULL;

			  insertaLC((yyval.codigo),finalLC((yyval.codigo)),oper);

			  oper.op = "syscall";
			  oper.res = NULL;
			  oper.arg1 = NULL;
			  oper.arg2 = NULL;

			  insertaLC((yyval.codigo),finalLC((yyval.codigo)),oper);
			  liberarReg(recuperaResLC((yyvsp[0].codigo)));

			}
#line 1730 "miniC.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 361 "miniC.y" /* yacc.c:1646  */
    { Simbolo aux;
		        aux.nombre = (yyvsp[0].str);
			aux.tipo = CADENA;
			aux.valor = contadorString++;
			insertaLS(l,finalLS(l),aux);

			(yyval.codigo) = creaLC();

			Operacion oper;
			oper.op = "li";
			oper.res = "$v0";
			oper.arg1 = "4";
			oper.arg2 = NULL;

			insertaLC((yyval.codigo),finalLC((yyval.codigo)),oper);

			oper.op = "la";
			oper.res = "$a0";
			oper.arg1 = concatena2("$str",aux.valor);
			oper.arg2 = NULL;

			insertaLC((yyval.codigo),finalLC((yyval.codigo)),oper);

			oper.op = "syscall";
			oper.res = NULL;
			oper.arg1 = NULL;
			oper.arg2 = NULL;

			insertaLC((yyval.codigo),finalLC((yyval.codigo)),oper);
		      }
#line 1765 "miniC.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 393 "miniC.y" /* yacc.c:1646  */
    { // Busqueda del si­mbolo "$1"
		   PosicionLista p = buscaLS(l,(yyvsp[0].str));
		   if (p != finalLS(l)) {
				Simbolo aux = recuperaLS(l,p);
				if (aux.tipo != VARIABLE) {
					printf("Error en linea %d. No se puede asignar a la : %s\n",yylineno,aux.nombre);
					errores_semanticos++;
				}
		    }
	            else {
			printf("Error en linea %d. No encontrado %s\n",yylineno,(yyvsp[0].str));
			errores_semanticos++;
		    }

		    (yyval.codigo)=creaLC();
		    Operacion oper;
		    oper.op = "li";
		    oper.res = "$v0";
		    oper.arg1 = "5";
		    oper.arg2 = NULL;

		    insertaLC((yyval.codigo),finalLC((yyval.codigo)),oper);

		    oper.op = "syscall";
		    oper.res = NULL;
		    oper.arg1 = NULL;
		    oper.arg2 = NULL;

		    insertaLC((yyval.codigo),finalLC((yyval.codigo)),oper);

		    oper.op = "sw";
		    oper.res = "$v0";
		    oper.arg1 = concatena("_",(yyvsp[0].str));
		    oper.arg2 = NULL;

		    insertaLC((yyval.codigo),finalLC((yyval.codigo)),oper);
		  }
#line 1807 "miniC.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 430 "miniC.y" /* yacc.c:1646  */
    { // Busqueda del si­mbolo "$3"
				 PosicionLista p = buscaLS(l,(yyvsp[0].str));
				 if (p != finalLS(l)) {
					Simbolo aux = recuperaLS(l,p);
					if (aux.tipo != VARIABLE) {
						printf("Error en linea %d. No se puede asignar a la : %s\n",yylineno,aux.nombre);
						errores_semanticos++;
					}
				  }
				  else {
					printf("Error en linea %d. No encontrado %s\n",yylineno,(yyvsp[0].str));
					errores_semanticos++;
				  }

				  (yyval.codigo)=(yyvsp[-2].codigo);
				  Operacion oper;
				  oper.op = "li";
				  oper.res = "$v0";
				  oper.arg1 = "5";
				  oper.arg2 = NULL;

				  insertaLC((yyval.codigo),finalLC((yyval.codigo)),oper);

				  oper.op = "syscall";
				  oper.res = NULL;
				  oper.arg1 = NULL;
				  oper.arg2 = NULL;

				  insertaLC((yyval.codigo),finalLC((yyval.codigo)),oper);

				  oper.op = "sw";
				  oper.res = "$v0";
				  oper.arg1 = concatena("_",(yyvsp[0].str));
				  oper.arg2 = NULL;

				  insertaLC((yyval.codigo),finalLC((yyval.codigo)),oper);
				}
#line 1849 "miniC.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 471 "miniC.y" /* yacc.c:1646  */
    { (yyval.codigo)=(yyvsp[-2].codigo);
					 concatenaLC((yyval.codigo),(yyvsp[0].codigo));
					 Operacion oper;
					 oper.op = "add";
					 oper.res = recuperaResLC((yyvsp[-2].codigo));
					 oper.arg1 = recuperaResLC((yyvsp[-2].codigo));
					 oper.arg2 = recuperaResLC((yyvsp[0].codigo));
					 insertaLC((yyval.codigo),finalLC((yyval.codigo)),oper);
					 liberaLC((yyvsp[0].codigo));
					 liberarReg(oper.arg2);
				       }
#line 1865 "miniC.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 482 "miniC.y" /* yacc.c:1646  */
    { (yyval.codigo)=(yyvsp[-2].codigo);
					 concatenaLC((yyval.codigo),(yyvsp[0].codigo));
					 Operacion oper;
					 oper.op = "sub";
					 oper.res = recuperaResLC((yyvsp[-2].codigo));
					 oper.arg1 = recuperaResLC((yyvsp[-2].codigo));
					 oper.arg2 = recuperaResLC((yyvsp[0].codigo));
					 insertaLC((yyval.codigo),finalLC((yyval.codigo)),oper);
					 liberaLC((yyvsp[0].codigo));
					 liberarReg(oper.arg2);
				       }
#line 1881 "miniC.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 493 "miniC.y" /* yacc.c:1646  */
    { (yyval.codigo)=(yyvsp[-2].codigo);
					 concatenaLC((yyval.codigo),(yyvsp[0].codigo));
					 Operacion oper;
					 oper.op = "mul";
					 oper.res = recuperaResLC((yyvsp[-2].codigo));
					 oper.arg1 = recuperaResLC((yyvsp[-2].codigo));
					 oper.arg2 = recuperaResLC((yyvsp[0].codigo));
					 insertaLC((yyval.codigo),finalLC((yyval.codigo)),oper);
					 liberaLC((yyvsp[0].codigo));
					 liberarReg(oper.arg2);
				       }
#line 1897 "miniC.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 504 "miniC.y" /* yacc.c:1646  */
    { (yyval.codigo)=(yyvsp[-2].codigo);
					 concatenaLC((yyval.codigo),(yyvsp[0].codigo));
					 Operacion oper;
					 oper.op = "div";
					 oper.res = recuperaResLC((yyvsp[-2].codigo));
					 oper.arg1 = recuperaResLC((yyvsp[-2].codigo));
					 oper.arg2 = recuperaResLC((yyvsp[0].codigo));
					 insertaLC((yyval.codigo),finalLC((yyval.codigo)),oper);
					 liberaLC((yyvsp[0].codigo));
					 liberarReg(oper.arg2);
				       }
#line 1913 "miniC.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 515 "miniC.y" /* yacc.c:1646  */
    { (yyval.codigo)=(yyvsp[0].codigo);
					   Operacion oper;
					   oper.op = "neg";
					   oper.res = recuperaResLC((yyvsp[0].codigo));
					   oper.arg1 = recuperaResLC((yyvsp[0].codigo));
					   oper.arg2 = NULL;
	  				   insertaLC((yyval.codigo),finalLC((yyval.codigo)),oper);
					 }
#line 1926 "miniC.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 523 "miniC.y" /* yacc.c:1646  */
    { (yyval.codigo)=(yyvsp[-1].codigo);
				}
#line 1933 "miniC.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 525 "miniC.y" /* yacc.c:1646  */
    {  // Busqueda del si­mbolo "$1"
		    PosicionLista p = buscaLS(l,(yyvsp[0].str));
		    if (p == finalLS(l)) {
			printf("Error en linea %d. No encontrado %s\n",yylineno,(yyvsp[0].str));
			errores_semanticos++;
		    }
		    (yyval.codigo) = creaLC();
   		    Operacion oper;
		    oper.op = "lw";
		    oper.res = obtenerReg();
		    oper.arg1 = concatena("_",(yyvsp[0].str));
		    oper.arg2 = NULL;
		    insertaLC((yyval.codigo),finalLC((yyval.codigo)),oper);
		    guardaResLC((yyval.codigo),oper.res);
		   }
#line 1953 "miniC.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 540 "miniC.y" /* yacc.c:1646  */
    { (yyval.codigo) = creaLC();
		     Operacion oper;
		     oper.op = "li";
		     oper.res = obtenerReg();
		     oper.arg1 = (yyvsp[0].str);
		     oper.arg2 = NULL;
		     insertaLC((yyval.codigo),finalLC((yyval.codigo)),oper);
		     guardaResLC((yyval.codigo),oper.res);
		   }
#line 1967 "miniC.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 549 "miniC.y" /* yacc.c:1646  */
    { // Busqueda del si­mbolo "$1"
				      PosicionLista p = buscaLS(l,(yyvsp[-3].str));
				      if (p == finalLS(l)) {
					  printf("Error en linea %d. No encontrado %s\n",yylineno,(yyvsp[-3].str));
					  errores_semanticos++;
				      }
					printf("Error: funciones no soportadas\n");
					errores_semanticos++;
				    }
#line 1981 "miniC.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 558 "miniC.y" /* yacc.c:1646  */
    { }
#line 1987 "miniC.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 561 "miniC.y" /* yacc.c:1646  */
    {}
#line 1993 "miniC.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 562 "miniC.y" /* yacc.c:1646  */
    {}
#line 1999 "miniC.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 565 "miniC.y" /* yacc.c:1646  */
    {}
#line 2005 "miniC.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 566 "miniC.y" /* yacc.c:1646  */
    {}
#line 2011 "miniC.tab.c" /* yacc.c:1646  */
    break;


#line 2015 "miniC.tab.c" /* yacc.c:1646  */
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
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
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 570 "miniC.y" /* yacc.c:1906  */


/*Metodo invocado por Bison si hay errores sintacticos */
void yyerror(const char *msg) {
	printf("Error en linea %d; %s\n",yylineno, msg);
	errores_sintacticos++;
}

int ok() {
	return !(errores_lexicos + errores_sintacticos + errores_semanticos);
}

char *obtenerReg() {
	for (int i = 0; i < 10; i++) {
		if (registros[i] == 0) {
			registros[i] = 1;
			char aux[16];
			sprintf(aux,"$t%d",i);
			return strdup(aux);
		}
	}
	printf("Error: registros agotados\n");
	exit(1);
}

void liberarReg(char *reg) {
	if (reg[0] =='$' && reg[1] =='t') {
		int aux = reg[2] - '0';
		assert(aux >= 0);
		assert(aux < 9);
		registros[aux] = 0;
	}
}

char *concatena(char *arg1, char *arg2) {
	char *aux = (char*)malloc(strlen(arg1)+strlen(arg2)+1);
	sprintf(aux,"%s%s",arg1,arg2);
	return aux;
}

char *concatena2(char *arg1, int i) {
	char *aux = (char*)malloc(strlen(arg1)+11);
	sprintf(aux,"%s%d",arg1,i);
	return aux;
}

char *nuevaEtiqueta() {
	char aux[16];
	sprintf(aux,"$l%d",contador_etiq++);
	return strdup(aux);
}

void imprimirLS() {
	//Recorrido y generacion de .data
	PosicionLista q = inicioLS(l);
	printf("######################\n");
	printf("# Cadenas del programa\n");
	printf("	.data\n");
  	while (q != finalLS(l)) {
    		Simbolo aux = recuperaLS(l,q);
		//Volcar informacion de simbolo
		if(aux.tipo == CADENA) {
			printf("$str%d: .asciiz %s\n", aux.valor,aux.nombre);
		}
    		q = siguienteLS(l,q);
  	}
	PosicionLista p = inicioLS(l);
	printf("# Variables y constantes\n");
	while (p != finalLS(l)) {
    		Simbolo aux = recuperaLS(l,p);
		//Volcar informacion de simbolo
		if (aux.tipo == VARIABLE || aux.tipo == CONSTANTE) {
			printf("_%s: .word 0\n", aux.nombre);
		}
    		p = siguienteLS(l,p);
  	}
}

void imprimirCodigo(ListaC codigo) {
	printf("###################\n");
	printf("# Seccion de codigo\n");
	printf("\t.text\n");
	printf("\t.globl main\n");
	printf("main:\n");
	PosicionListaC p = inicioLC(codigo);
	while (p != finalLC(codigo)) {
		Operacion oper;
		oper = recuperaLC(codigo,p);
		if (!strcmp(oper.op,"etiq")) printf("%s:\n",oper.res);
		else {  printf("\t%s",oper.op);
			if (oper.res) printf(" %s",oper.res);
			if (oper.arg1) printf(",%s",oper.arg1);
			if (oper.arg2) printf(",%s",oper.arg2);
			}
		printf("\n");
		p = siguienteLC(codigo,p);
	}
	printf("##################\n");
	printf("# Fin\n");
	printf("\tli $v0, 10\n");
	printf("\tsyscall\n");
}
