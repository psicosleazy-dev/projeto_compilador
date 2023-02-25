/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1





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

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 1 "parser.y"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ast.h"
#include "hash.h"
#include "errors.h"
#include "stack_management.h"
int yylex(void);
void yyerror (char const *s);
extern int get_line_number();
extern void* arvore;
extern Stack* stack;

#line 126 "parser.tab.c"

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    TK_PR_INT = 258,
    TK_PR_FLOAT = 259,
    TK_PR_BOOL = 260,
    TK_PR_CHAR = 261,
    TK_PR_IF = 262,
    TK_PR_THEN = 263,
    TK_PR_ELSE = 264,
    TK_PR_WHILE = 265,
    TK_PR_INPUT = 266,
    TK_PR_OUTPUT = 267,
    TK_PR_RETURN = 268,
    TK_PR_FOR = 269,
    TK_OC_LE = 270,
    TK_OC_GE = 271,
    TK_OC_EQ = 272,
    TK_OC_NE = 273,
    TK_OC_AND = 274,
    TK_OC_OR = 275,
    TK_LIT_INT = 276,
    TK_LIT_CHAR = 277,
    TK_LIT_FLOAT = 278,
    TK_LIT_FALSE = 279,
    TK_LIT_TRUE = 280,
    TK_IDENTIFICADOR = 281,
    TK_ERRO = 282
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 19 "parser.y"

 node_t *no;
 valor_t valor_lexico;

#line 170 "parser.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */



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
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
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
#define YYFINAL  10
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   165

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  31
/* YYNRULES -- Number of rules.  */
#define YYNRULES  92
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  164

#define YYUNDEFTOK  2
#define YYMAXUTOK   282


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    40,     2,     2,     2,    39,     2,     2,
      41,    42,    37,    35,    29,    36,     2,    38,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    28,
      34,    45,    33,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    30,     2,    31,    32,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    43,     2,    44,     2,     2,     2,     2,
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
      25,    26,    27
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    84,    84,    85,    86,    87,    88,    89,    90,    91,
      92,   113,   136,   150,   167,   187,   193,   199,   214,   229,
     243,   244,   245,   258,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   309,   319,   328,   336,   345,
     353,   361,   362,   363,   364,   365,   366,   378,   379,   380,
     386,   392,   393,   408,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   434,   435,   436,
     437,   438,   439
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TK_PR_INT", "TK_PR_FLOAT", "TK_PR_BOOL",
  "TK_PR_CHAR", "TK_PR_IF", "TK_PR_THEN", "TK_PR_ELSE", "TK_PR_WHILE",
  "TK_PR_INPUT", "TK_PR_OUTPUT", "TK_PR_RETURN", "TK_PR_FOR", "TK_OC_LE",
  "TK_OC_GE", "TK_OC_EQ", "TK_OC_NE", "TK_OC_AND", "TK_OC_OR",
  "TK_LIT_INT", "TK_LIT_CHAR", "TK_LIT_FLOAT", "TK_LIT_FALSE",
  "TK_LIT_TRUE", "TK_IDENTIFICADOR", "TK_ERRO", "';'", "','", "'['", "']'",
  "'^'", "'>'", "'<'", "'+'", "'-'", "'*'", "'/'", "'%'", "'!'", "'('",
  "')'", "'{'", "'}'", "'='", "$accept", "programa", "lista",
  "declaracao_global", "declaracao_local", "lista_nomes_local",
  "lista_nomes_global", "lista_inteiros", "expressao", "prec_six",
  "prec_five", "prec_four", "prec_three", "prec_two", "prec_one",
  "prec_zero", "expressoes", "argumentos", "args", "chamada_funcao",
  "operando", "tipo", "funcao", "bloco", "parametros", "atribuicao",
  "comandos_simples", "retorno", "if", "else", "while", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,    59,    44,
      91,    93,    94,    62,    60,    43,    45,    42,    47,    37,
      33,    40,    41,   123,   125,    61
};
# endif

#define YYPACT_NINF (-82)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      38,   -82,   -82,   -82,   -82,    37,   -82,    38,    25,    38,
     -82,   -82,    42,    68,   -82,    60,    38,   -82,    36,   -82,
      71,    58,    32,    61,   -82,    67,   -82,    38,    50,    60,
     -82,    81,    21,   -82,    94,   -82,    73,    93,    54,    41,
     -82,    95,   111,   114,   113,   115,    98,   116,   117,   118,
     -82,    54,    54,   -82,   -82,   -82,   -82,    57,    54,    54,
      54,   127,   129,    82,    23,    92,    83,   -82,   -82,   -82,
     -82,    54,    54,    54,    63,    63,   -11,   120,    63,    63,
     -82,    63,    63,    63,   -12,   -10,    54,   -82,   -82,    -9,
      54,    54,    54,    54,    54,    54,    54,    54,    54,    54,
      54,    54,    54,   -14,   119,    -8,   -82,   109,   127,   -82,
     -82,   131,    60,   128,   -82,   -82,   -82,   -82,   -82,   145,
      50,   124,   -82,   129,    82,    23,    23,    92,    92,    92,
      92,    83,    83,   -82,   -82,   -82,    54,   112,    54,   -82,
     -82,    99,    33,    50,   -82,   -82,   -82,    54,   -82,   141,
     137,    60,   150,   127,   139,   -82,   101,    50,   -82,   -82,
     146,   -82,   142,   -82
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,    62,    63,    64,    65,     0,     2,     6,     0,     4,
       1,     7,    21,     0,     5,     0,    71,     8,     0,    23,
       0,     0,     0,    20,    19,     0,    70,     0,     0,     0,
      22,     0,     0,    66,     0,    69,     0,     0,     0,     0,
      68,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      18,     0,     0,    57,    58,    59,    60,    56,     0,     0,
       0,    88,    25,    27,    30,    35,    38,    42,    45,    61,
      47,     0,    53,     0,    75,    79,    15,     9,    77,    81,
      67,    83,    85,    87,     0,     0,     0,    44,    43,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    49,     0,    51,    52,     0,    73,    74,
      78,     0,     0,     0,    76,    80,    82,    84,    86,     0,
       0,     0,    46,    24,    26,    28,    29,    33,    34,    31,
      32,    36,    37,    39,    40,    41,     0,     0,     0,    54,
      13,     0,    16,     0,    92,    55,    48,     0,    50,    12,
       0,     0,    91,    72,     0,    14,     0,     0,    89,    11,
      17,    90,     0,    10
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -82,   -82,     0,   -82,   -82,   -82,   -82,   -27,   -37,    72,
      74,    43,    22,    39,   -42,   -82,   -81,    26,   -82,   -29,
     -82,    13,   -82,   -28,   -82,   -82,    30,   -82,   -82,   -82,
     -82
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     5,     6,     7,    41,    77,    13,    20,   103,    62,
      63,    64,    65,    66,    67,    68,   104,   106,   107,    69,
      70,    43,     9,    44,    22,    45,    46,    47,    48,   158,
      49
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      33,    61,    34,    42,   111,   121,    90,    11,    90,    14,
      90,    90,    90,     8,    84,    85,    87,    88,   136,   112,
       8,   138,     8,    89,     1,     2,     3,     4,    36,    21,
     119,    37,   120,   122,    38,   105,   108,    10,    94,    95,
      31,     1,     2,     3,     4,    42,    42,    39,   150,    42,
      42,    12,    42,    42,    42,   146,    96,    97,   133,   134,
     135,    27,    23,   151,    32,    40,     1,     2,     3,     4,
      36,    71,    15,    37,    28,    53,    38,    54,    55,    56,
      57,    19,    72,    16,    26,   141,    73,    86,    30,    39,
      58,    29,   144,    32,    59,    60,    17,    18,    72,    92,
      93,   105,    24,    25,   109,   110,    32,    35,   114,   115,
     153,   116,   117,   118,    51,   152,   127,   128,   129,   130,
     100,   101,   102,    74,   156,    50,    25,    98,    99,   161,
     149,    25,   160,    25,    52,   125,   126,   131,   132,    75,
      76,    78,    80,    79,    81,    82,    83,    90,    91,   113,
     137,   139,   140,   143,   142,   145,   154,   147,   155,   157,
     159,   162,   123,   163,   148,   124
};

static const yytype_uint8 yycheck[] =
{
      28,    38,    29,    32,    15,    86,    20,     7,    20,     9,
      20,    20,    20,     0,    51,    52,    58,    59,    32,    30,
       7,    29,     9,    60,     3,     4,     5,     6,     7,    16,
      42,    10,    42,    42,    13,    72,    73,     0,    15,    16,
      27,     3,     4,     5,     6,    74,    75,    26,    15,    78,
      79,    26,    81,    82,    83,   136,    33,    34,   100,   101,
     102,    29,    26,    30,    43,    44,     3,     4,     5,     6,
       7,    30,    30,    10,    42,    21,    13,    23,    24,    25,
      26,    21,    41,    41,    26,   112,    45,    30,    21,    26,
      36,    30,   120,    43,    40,    41,    28,    29,    41,    17,
      18,   138,    31,    32,    74,    75,    43,    26,    78,    79,
     147,    81,    82,    83,    41,   143,    94,    95,    96,    97,
      37,    38,    39,    28,   151,    31,    32,    35,    36,   157,
      31,    32,    31,    32,    41,    92,    93,    98,    99,    28,
      26,    28,    44,    28,    28,    28,    28,    20,    19,    29,
      31,    42,    21,     8,    26,    31,    15,    45,    21,     9,
      21,    15,    90,    21,   138,    91
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     6,    47,    48,    49,    67,    68,
       0,    48,    26,    52,    48,    30,    41,    28,    29,    21,
      53,    67,    70,    26,    31,    32,    26,    29,    42,    30,
      21,    67,    43,    69,    53,    26,     7,    10,    13,    26,
      44,    50,    65,    67,    69,    71,    72,    73,    74,    76,
      31,    41,    41,    21,    23,    24,    25,    26,    36,    40,
      41,    54,    55,    56,    57,    58,    59,    60,    61,    65,
      66,    30,    41,    45,    28,    28,    26,    51,    28,    28,
      44,    28,    28,    28,    54,    54,    30,    60,    60,    54,
      20,    19,    17,    18,    15,    16,    33,    34,    35,    36,
      37,    38,    39,    54,    62,    54,    63,    64,    54,    72,
      72,    15,    30,    29,    72,    72,    72,    72,    72,    42,
      42,    62,    42,    55,    56,    57,    57,    58,    58,    58,
      58,    59,    59,    60,    60,    60,    32,    31,    29,    42,
      21,    53,    26,     8,    69,    31,    62,    45,    63,    31,
      15,    30,    69,    54,    15,    21,    53,     9,    75,    21,
      31,    69,    15,    21
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    46,    47,    47,    48,    48,    48,    48,    49,    50,
      51,    51,    51,    51,    51,    51,    51,    51,    52,    52,
      52,    52,    53,    53,    54,    54,    55,    55,    56,    56,
      56,    57,    57,    57,    57,    57,    58,    58,    58,    59,
      59,    59,    59,    60,    60,    60,    61,    61,    62,    62,
      63,    63,    64,    64,    65,    66,    66,    66,    66,    66,
      66,    66,    67,    67,    67,    67,    68,    69,    69,    70,
      70,    70,    71,    71,    72,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    72,    72,    72,    72,    73,    74,
      75,    75,    76
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     0,     1,     2,     1,     2,     3,     2,
       8,     6,     4,     3,     5,     1,     3,     6,     6,     4,
       3,     1,     3,     1,     3,     1,     3,     1,     3,     3,
       1,     3,     3,     3,     3,     1,     3,     3,     1,     3,
       3,     3,     1,     2,     2,     1,     3,     1,     3,     1,
       3,     1,     1,     0,     4,     4,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     6,     3,     2,     4,
       2,     0,     6,     3,     3,     2,     3,     2,     3,     2,
       3,     2,     3,     2,     3,     2,     3,     2,     2,     7,
       2,     0,     5
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
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
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
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
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

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
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
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
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
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
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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
          ++yyp;
          ++yyformat;
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
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

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
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
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

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
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
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
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
  case 2:
#line 84 "parser.y"
                {arvore = (void*)(yyval.no); (yyval.no) = (yyvsp[0].no);}
#line 1464 "parser.tab.c"
    break;

  case 3:
#line 85 "parser.y"
          {arvore = (void*)(yyval.no); (yyval.no) = NULL;}
#line 1470 "parser.tab.c"
    break;

  case 4:
#line 86 "parser.y"
              {(yyval.no) = (yyvsp[0].no);}
#line 1476 "parser.tab.c"
    break;

  case 5:
#line 87 "parser.y"
                       {(yyval.no) = (yyvsp[-1].no); add_child((yyvsp[-1].no),(yyvsp[0].no));}
#line 1482 "parser.tab.c"
    break;

  case 6:
#line 88 "parser.y"
                            {(yyval.no) = (yyvsp[0].no);}
#line 1488 "parser.tab.c"
    break;

  case 7:
#line 89 "parser.y"
                                  {(yyval.no) = (yyvsp[-1].no); add_child((yyval.no),(yyvsp[0].no));}
#line 1494 "parser.tab.c"
    break;

  case 8:
#line 90 "parser.y"
                                               {(yyval.no) = (yyvsp[-1].no);}
#line 1500 "parser.tab.c"
    break;

  case 9:
#line 91 "parser.y"
                                         {(yyval.no) = (yyvsp[0].no);}
#line 1506 "parser.tab.c"
    break;

  case 10:
#line 92 "parser.y"
                                                                                                     {
	node_t *new_node;
	(yyval.no) = create_node(AST_INIT,"<=");
	char *leaf;
	leaf = create_leaf((yyvsp[-5].valor_lexico));
	node_t* new_node2;
	add_child((yyval.no),new_node2);
	add_child((yyval.no),(yyvsp[-7].no));
	leaf = create_leaf((yyvsp[0].valor_lexico));
	node_t* new_node3;
	add_child((yyval.no),new_node3);
	new_node = create_node(AST_ARR,"[]");
	add_child(new_node,new_node2);
	add_child(new_node,(yyvsp[-3].no));
	add_child((yyval.no),new_node);
	(yyvsp[-5].valor_lexico) = altera_natureza((yyvsp[-5].valor_lexico),NAT_VARIABLE);
	HASH_TABLE* table;
	table = pop(stack);
	checkTableDec(table,(yyvsp[-5].valor_lexico));
	insert_item(table,(yyvsp[-5].valor_lexico));
	push(stack,table);}
#line 1532 "parser.tab.c"
    break;

  case 11:
#line 113 "parser.y"
                                                                      {
	node_t *new_node;
	(yyval.no) = create_node(AST_INIT,"<=");
	char *leaf;
	leaf = create_leaf((yyvsp[-5].valor_lexico));
	node_t *new_node2;
	add_child((yyval.no),new_node2);
	node_t *new_node3;
	leaf = create_leaf((yyvsp[0].valor_lexico));
	add_child((yyval.no),new_node3);
	new_node = create_node(AST_ARR,"[]");
	add_child(new_node,new_node2);
	add_child(new_node,(yyvsp[-3].no));
	add_child((yyval.no),new_node);
	(yyvsp[-5].valor_lexico) = altera_natureza((yyvsp[-5].valor_lexico),NAT_ARRAY);
	HASH_TABLE *table;
	table = pop(stack);
	checkTableDec(table,(yyvsp[-5].valor_lexico));
	insert_item(table,(yyvsp[-5].valor_lexico));
	(yyvsp[0].valor_lexico) = altera_natureza((yyvsp[0].valor_lexico),NAT_LITERAL);
	insert_item(table,(yyvsp[0].valor_lexico));
	push(stack,table);
	}
#line 1560 "parser.tab.c"
    break;

  case 12:
#line 136 "parser.y"
                                                  {
	(yyval.no) = create_node(AST_ARR,"[]");
	node_t* new_node;
	char* leaf;
	leaf = create_leaf((yyvsp[-3].valor_lexico));
	new_node = create_node(AST_ID,leaf);
	add_child((yyval.no),new_node);
	add_child((yyval.no),(yyvsp[-1].no));
	HASH_TABLE *table;
	table = pop(stack);
	(yyvsp[-3].valor_lexico) = altera_natureza((yyvsp[-3].valor_lexico),NAT_ARRAY);
	checkTableDec(table,(yyvsp[-3].valor_lexico));
	insert_item(table,(yyvsp[-3].valor_lexico));
	push(stack,table);}
#line 1579 "parser.tab.c"
    break;

  case 13:
#line 150 "parser.y"
                                               {
	(yyval.no) = create_node(AST_INIT,"<=");
	node_t* new_node;
	char* leaf;
	leaf = create_leaf((yyvsp[-2].valor_lexico));
	new_node = create_node(AST_ID,leaf);
	add_child((yyval.no),new_node);
	node_t* new_node2;
	leaf = create_leaf((yyvsp[0].valor_lexico));
	new_node2 = create_node(AST_LIT_INT,leaf);
	add_child((yyval.no),new_node2);
	HASH_TABLE *table;
	table = pop(stack);
	(yyvsp[-2].valor_lexico) = altera_natureza((yyvsp[-2].valor_lexico),NAT_VARIABLE);
	checkTableDec(table,(yyvsp[-2].valor_lexico));
	insert_item(table,(yyvsp[-2].valor_lexico));
	push(stack,table);}
#line 1601 "parser.tab.c"
    break;

  case 14:
#line 167 "parser.y"
                                                                     {
	node_t* new_node;	
	char* leaf;
	leaf = create_leaf((yyvsp[-2].valor_lexico));
	(yyval.no) = create_node(AST_INIT,"<=");
	new_node = create_node(AST_ID,leaf);
	add_child((yyval.no),new_node);
	add_child((yyval.no),(yyvsp[-4].no));
	node_t* new_node2;
	leaf = create_leaf((yyvsp[0].valor_lexico));
	new_node2 = create_node(AST_LIT_INT,leaf);
	add_child((yyval.no),new_node2);
	add_child((yyval.no),(yyvsp[-4].no));
	(yyvsp[-2].valor_lexico) = altera_natureza((yyvsp[-2].valor_lexico),NAT_VARIABLE);
	HASH_TABLE *table;
	table = pop(stack);
	checkTableDec(table,(yyvsp[-2].valor_lexico));
	insert_item(table,(yyvsp[-2].valor_lexico));
	insert_item(table,(yyvsp[0].valor_lexico));
	push(stack,table);}
#line 1626 "parser.tab.c"
    break;

  case 15:
#line 187 "parser.y"
                           {(yyval.no) = NULL; (yyvsp[0].valor_lexico) = altera_natureza((yyvsp[0].valor_lexico),NAT_VARIABLE);
	HASH_TABLE* table;	
	table = pop(stack);
	checkTableDec(table,(yyvsp[0].valor_lexico));
	insert_item(table,(yyvsp[0].valor_lexico));
	push(stack,table);}
#line 1637 "parser.tab.c"
    break;

  case 16:
#line 193 "parser.y"
                                                 {(yyval.no) = (yyvsp[-2].no); (yyvsp[0].valor_lexico) = altera_natureza((yyvsp[0].valor_lexico),NAT_VARIABLE);
	HASH_TABLE* table;	
	table = pop(stack);
	checkTableDec(table,(yyvsp[0].valor_lexico));
	insert_item(table,(yyvsp[0].valor_lexico));
	push(stack,table);}
#line 1648 "parser.tab.c"
    break;

  case 17:
#line 199 "parser.y"
                                                                    {
		(yyval.no) = create_node(AST_ARR,"[]");
		node_t* new_node;
		char* leaf;
		leaf = create_leaf((yyvsp[-3].valor_lexico));
		new_node = create_node(AST_ID,leaf);
		add_child((yyval.no),new_node);
		add_child((yyval.no),(yyvsp[-1].no));
		add_child((yyval.no),(yyvsp[-5].no));
		(yyvsp[-3].valor_lexico) = altera_natureza((yyvsp[-3].valor_lexico),NAT_ARRAY);
		HASH_TABLE* table;	
		table = pop(stack);
		checkTableDec(table,(yyvsp[-3].valor_lexico));
		insert_item(table,(yyvsp[-3].valor_lexico));
		push(stack,table);}
#line 1668 "parser.tab.c"
    break;

  case 18:
#line 214 "parser.y"
                                                                                   {
	(yyval.no) = create_node(AST_ARR,"[]");
	node_t* new_node;
	char* leaf;
	leaf = create_leaf((yyvsp[-3].valor_lexico));
	new_node = create_node(AST_ID,leaf);
	add_child((yyval.no),new_node);
	add_child((yyval.no),(yyvsp[-1].no));
	add_child((yyval.no),(yyvsp[-5].no));
	HASH_TABLE* table;
	table = pop(stack);
	(yyvsp[-3].valor_lexico) = altera_natureza((yyvsp[-3].valor_lexico),NAT_VARIABLE);
	checkTableDec(table,(yyvsp[-3].valor_lexico));
	insert_item(table,(yyvsp[-3].valor_lexico));
	push(stack,table);}
#line 1688 "parser.tab.c"
    break;

  case 19:
#line 229 "parser.y"
                                                  {
	(yyval.no) = create_node(AST_ARR,"[]");
	node_t* new_node;	
	char* leaf;
	leaf = create_leaf((yyvsp[-3].valor_lexico));
	new_node = create_node(AST_ID,leaf);
	add_child((yyval.no),new_node); 
	add_child((yyval.no),(yyvsp[-1].no));
	HASH_TABLE *table;
	table = pop(stack);
	(yyvsp[-3].valor_lexico) = altera_natureza((yyvsp[-3].valor_lexico),NAT_ARRAY);
	checkTableDec(table,(yyvsp[-3].valor_lexico));
	insert_item(table,(yyvsp[-3].valor_lexico));
	push(stack,table);}
#line 1707 "parser.tab.c"
    break;

  case 20:
#line 243 "parser.y"
                                                  {(yyval.no) = NULL; (yyvsp[0].valor_lexico) = altera_natureza((yyvsp[0].valor_lexico),NAT_VARIABLE); HASH_TABLE* table; table = pop(stack); checkTableDec(table,(yyvsp[0].valor_lexico)); insert_item(table,(yyvsp[0].valor_lexico)); push(stack,table);}
#line 1713 "parser.tab.c"
    break;

  case 21:
#line 244 "parser.y"
                           {(yyval.no) = NULL; (yyvsp[0].valor_lexico) = altera_natureza((yyvsp[0].valor_lexico),NAT_VARIABLE); HASH_TABLE* table; table = pop(stack); checkTableDec(table,(yyvsp[0].valor_lexico)); insert_item(table,(yyvsp[0].valor_lexico)); push(stack,table);}
#line 1719 "parser.tab.c"
    break;

  case 22:
#line 245 "parser.y"
                                              {
	(yyval.no) = create_node(AST_CIRC, "^"); 
	node_t* new_node;
	char* leaf;
	leaf = create_leaf((yyvsp[0].valor_lexico));
	new_node = create_node(AST_LIT_INT,leaf);
	add_child((yyval.no),(yyvsp[-2].no));
	add_child((yyval.no),new_node);
	(yyvsp[0].valor_lexico) = altera_natureza((yyvsp[0].valor_lexico),NAT_LITERAL);
	HASH_TABLE* table;
	table = pop(stack);
	insert_item(table,(yyvsp[0].valor_lexico));
	push(stack,table);}
#line 1737 "parser.tab.c"
    break;

  case 23:
#line 258 "parser.y"
                     {
	node_t* new_node;	
	char* leaf;
	leaf = create_leaf((yyvsp[0].valor_lexico));
	(yyval.no) = create_node(AST_LIT_INT,leaf);
	(yyvsp[0].valor_lexico) = altera_natureza((yyvsp[0].valor_lexico),NAT_LITERAL);
	HASH_TABLE* table;
	table = pop(stack);
	insert_item(table,(yyvsp[0].valor_lexico));
	push(stack,table);}
#line 1752 "parser.tab.c"
    break;

  case 24:
#line 268 "parser.y"
                                       {(yyval.no) = create_node(AST_OR, "||"); add_child((yyval.no),(yyvsp[-2].no)); add_child((yyval.no),(yyvsp[0].no));}
#line 1758 "parser.tab.c"
    break;

  case 25:
#line 269 "parser.y"
                   {(yyval.no) = (yyvsp[0].no);}
#line 1764 "parser.tab.c"
    break;

  case 26:
#line 270 "parser.y"
                                       {(yyval.no) = create_node(AST_AND, "&&"); add_child((yyval.no),(yyvsp[-2].no)); add_child((yyval.no),(yyvsp[0].no));}
#line 1770 "parser.tab.c"
    break;

  case 27:
#line 271 "parser.y"
                    {(yyval.no) = (yyvsp[0].no);}
#line 1776 "parser.tab.c"
    break;

  case 28:
#line 272 "parser.y"
                                        {(yyval.no) = create_node(AST_EQ, "=="); add_child((yyval.no),(yyvsp[-2].no)); add_child((yyval.no),(yyvsp[0].no));}
#line 1782 "parser.tab.c"
    break;

  case 29:
#line 273 "parser.y"
                                       {(yyval.no) = create_node(AST_NE, "!="); add_child((yyval.no),(yyvsp[-2].no)); add_child((yyval.no),(yyvsp[0].no));}
#line 1788 "parser.tab.c"
    break;

  case 30:
#line 274 "parser.y"
                    {(yyval.no) = (yyvsp[0].no);}
#line 1794 "parser.tab.c"
    break;

  case 31:
#line 275 "parser.y"
                                    {(yyval.no) = create_node(AST_G, ">"); add_child((yyval.no),(yyvsp[-2].no)); add_child((yyval.no),(yyvsp[0].no));}
#line 1800 "parser.tab.c"
    break;

  case 32:
#line 276 "parser.y"
                                   {(yyval.no) = create_node(AST_L, "<"); add_child((yyval.no),(yyvsp[-2].no)); add_child((yyval.no),(yyvsp[0].no));}
#line 1806 "parser.tab.c"
    break;

  case 33:
#line 277 "parser.y"
                                        {(yyval.no) = create_node(AST_LE, "<="); add_child((yyval.no),(yyvsp[-2].no)); add_child((yyval.no),(yyvsp[0].no));}
#line 1812 "parser.tab.c"
    break;

  case 34:
#line 278 "parser.y"
                                        {(yyval.no) = create_node(AST_GE, ">="); add_child((yyval.no),(yyvsp[-2].no)); add_child((yyval.no),(yyvsp[0].no));}
#line 1818 "parser.tab.c"
    break;

  case 35:
#line 279 "parser.y"
                     {(yyval.no) = (yyvsp[0].no);}
#line 1824 "parser.tab.c"
    break;

  case 36:
#line 280 "parser.y"
                                    {(yyval.no) = create_node(AST_ADD, "+"); add_child((yyval.no),(yyvsp[-2].no)); add_child((yyval.no),(yyvsp[0].no));}
#line 1830 "parser.tab.c"
    break;

  case 37:
#line 281 "parser.y"
                                  {(yyval.no) = create_node(AST_SUB, "-"); add_child((yyval.no),(yyvsp[-2].no)); add_child((yyval.no),(yyvsp[0].no));}
#line 1836 "parser.tab.c"
    break;

  case 38:
#line 282 "parser.y"
                   {(yyval.no) = (yyvsp[0].no);}
#line 1842 "parser.tab.c"
    break;

  case 39:
#line 283 "parser.y"
                                {(yyval.no) = create_node(AST_MUL, "*"); add_child((yyval.no),(yyvsp[-2].no)); add_child((yyval.no),(yyvsp[0].no));}
#line 1848 "parser.tab.c"
    break;

  case 40:
#line 284 "parser.y"
                                {(yyval.no) = create_node(AST_DIV, "/"); add_child((yyval.no),(yyvsp[-2].no)); add_child((yyval.no),(yyvsp[0].no));}
#line 1854 "parser.tab.c"
    break;

  case 41:
#line 285 "parser.y"
                                {(yyval.no) = create_node(AST_MOD, "%"); add_child((yyval.no),(yyvsp[-2].no)); add_child((yyval.no),(yyvsp[0].no));}
#line 1860 "parser.tab.c"
    break;

  case 42:
#line 286 "parser.y"
                   {(yyval.no) = (yyvsp[0].no);}
#line 1866 "parser.tab.c"
    break;

  case 43:
#line 287 "parser.y"
                       {(yyval.no) = create_node(AST_NOT, "!"); add_child((yyval.no),(yyvsp[0].no));}
#line 1872 "parser.tab.c"
    break;

  case 44:
#line 288 "parser.y"
                       {(yyval.no) = create_node(AST_MINUS, "-"); add_child((yyval.no),(yyvsp[0].no));}
#line 1878 "parser.tab.c"
    break;

  case 45:
#line 289 "parser.y"
                    {(yyval.no) = (yyvsp[0].no);}
#line 1884 "parser.tab.c"
    break;

  case 46:
#line 290 "parser.y"
                             {(yyval.no) = (yyvsp[-1].no);}
#line 1890 "parser.tab.c"
    break;

  case 47:
#line 291 "parser.y"
                   {(yyval.no) = (yyvsp[0].no);}
#line 1896 "parser.tab.c"
    break;

  case 48:
#line 292 "parser.y"
                                     {(yyval.no) = create_node(AST_CIRC,"^"); add_child((yyval.no),(yyvsp[-2].no)); add_child((yyval.no),(yyvsp[0].no));}
#line 1902 "parser.tab.c"
    break;

  case 49:
#line 293 "parser.y"
                    {(yyval.no) = (yyvsp[0].no);}
#line 1908 "parser.tab.c"
    break;

  case 50:
#line 294 "parser.y"
                                     {(yyval.no) = (yyvsp[-2].no); add_child((yyval.no),(yyvsp[0].no));}
#line 1914 "parser.tab.c"
    break;

  case 51:
#line 295 "parser.y"
                    {(yyval.no) = (yyvsp[0].no);}
#line 1920 "parser.tab.c"
    break;

  case 52:
#line 296 "parser.y"
                 {(yyval.no) = (yyvsp[0].no);}
#line 1926 "parser.tab.c"
    break;

  case 53:
#line 297 "parser.y"
          {(yyval.no) = NULL;}
#line 1932 "parser.tab.c"
    break;

  case 54:
#line 298 "parser.y"
                                              {
	char label[100] = "call ", *nome_fun;
	nome_fun = strdup(create_leaf((yyvsp[-3].valor_lexico)));
	strcat(label,nome_fun);
	(yyval.no) = create_node(AST_CALL,label);
	add_child((yyval.no),(yyvsp[-1].no));
	HASH_TABLE *table;
	table = pop(stack);
	checkTableInUse(table,(yyvsp[-3].valor_lexico));
	push(stack,table);
}
#line 1948 "parser.tab.c"
    break;

  case 55:
#line 309 "parser.y"
                                              {
(yyval.no) = create_node(AST_INDEX,"[]");
	node_t* new_node;
	char* leaf;
	leaf = create_leaf((yyvsp[-3].valor_lexico));
	new_node = create_node(AST_ID,leaf); add_child((yyval.no),new_node); add_child((yyval.no),(yyvsp[-1].no));
	HASH_TABLE *table;
	table = pop(stack);
	checkTableInUse(table,(yyvsp[-3].valor_lexico));
	push(stack,table);}
#line 1963 "parser.tab.c"
    break;

  case 56:
#line 319 "parser.y"
                           {
	char* leaf;
	leaf = create_leaf((yyvsp[0].valor_lexico));
	(yyval.no) = create_node(AST_ID,leaf);
	(yyvsp[0].valor_lexico) = altera_natureza((yyvsp[0].valor_lexico),NAT_VARIABLE);
	HASH_TABLE *table;
	table = pop(stack);
	checkTableInUse(table,(yyvsp[0].valor_lexico));
	push(stack,table);}
#line 1977 "parser.tab.c"
    break;

  case 57:
#line 328 "parser.y"
                     {char* leaf;
	leaf = create_leaf((yyvsp[0].valor_lexico));
	(yyval.no) = create_node(AST_LIT_INT,leaf);
	(yyvsp[0].valor_lexico) = altera_natureza((yyvsp[0].valor_lexico),NAT_LITERAL);
	HASH_TABLE* table;
	table = pop(stack);
	insert_item(table,(yyvsp[0].valor_lexico));
	push(stack,table);}
#line 1990 "parser.tab.c"
    break;

  case 58:
#line 336 "parser.y"
                       {
	char* leaf;
	leaf = create_leaf((yyvsp[0].valor_lexico));
	(yyval.no) = create_node(AST_LIT_FLOAT,leaf);
	(yyvsp[0].valor_lexico) = altera_natureza((yyvsp[0].valor_lexico),NAT_LITERAL);
	HASH_TABLE* table;
	table = pop(stack);
	insert_item(table,(yyvsp[0].valor_lexico));
	push(stack,table);}
#line 2004 "parser.tab.c"
    break;

  case 59:
#line 345 "parser.y"
                       {char* leaf;
	leaf = create_leaf((yyvsp[0].valor_lexico));
	(yyval.no) = create_node(AST_LIT_FALSE,leaf);
	(yyvsp[0].valor_lexico) = altera_natureza((yyvsp[0].valor_lexico),NAT_LITERAL);
	HASH_TABLE* table;
	table = pop(stack);
	insert_item(table,(yyvsp[0].valor_lexico));
	push(stack,table);}
#line 2017 "parser.tab.c"
    break;

  case 60:
#line 353 "parser.y"
                      {char* leaf;
	leaf = create_leaf((yyvsp[0].valor_lexico));
	(yyval.no) = create_node(AST_LIT_TRUE,leaf);
	(yyvsp[0].valor_lexico) = altera_natureza((yyvsp[0].valor_lexico),NAT_LITERAL);
	HASH_TABLE* table;
	table = pop(stack);
	insert_item(table,(yyvsp[0].valor_lexico));
	push(stack,table);}
#line 2030 "parser.tab.c"
    break;

  case 61:
#line 361 "parser.y"
                         {(yyval.no) = (yyvsp[0].no);}
#line 2036 "parser.tab.c"
    break;

  case 66:
#line 366 "parser.y"
                                                       {
	char* leaf;
	leaf = create_leaf((yyvsp[-4].valor_lexico));
	(yyval.no) = create_node(AST_FUNC,leaf);
	add_child((yyval.no),(yyvsp[0].no));
	(yyvsp[-4].valor_lexico) = altera_natureza((yyvsp[-4].valor_lexico),NAT_FUNCTION);
	HASH_TABLE* table;
	table = pop(stack);
	checkTableDec(table,(yyvsp[-4].valor_lexico));
	insert_item(table,(yyvsp[-4].valor_lexico));
	push(stack,table);
	}
#line 2053 "parser.tab.c"
    break;

  case 67:
#line 378 "parser.y"
                                {(yyval.no) = (yyvsp[-1].no); HASH_TABLE* table; table = create_table(HASH_SIZE); push(stack,table);}
#line 2059 "parser.tab.c"
    break;

  case 68:
#line 379 "parser.y"
                  {(yyval.no) = NULL;}
#line 2065 "parser.tab.c"
    break;

  case 69:
#line 380 "parser.y"
                                                 {(yyvsp[0].valor_lexico) = altera_natureza((yyvsp[0].valor_lexico),NAT_VARIABLE);
	HASH_TABLE* table;
	table = pop(stack);
	checkTableDec(table,(yyvsp[0].valor_lexico));
	insert_item(table,(yyvsp[0].valor_lexico));
	push(stack,table);}
#line 2076 "parser.tab.c"
    break;

  case 70:
#line 386 "parser.y"
                                {(yyvsp[0].valor_lexico) = altera_natureza((yyvsp[0].valor_lexico),NAT_VARIABLE);
	HASH_TABLE* table;
	table = pop(stack);
	checkTableDec(table,(yyvsp[0].valor_lexico));
	insert_item(table,(yyvsp[0].valor_lexico));
	push(stack,table);}
#line 2087 "parser.tab.c"
    break;

  case 72:
#line 393 "parser.y"
                                                              {
node_t *new_node, *new_node2;
	(yyval.no) = create_node(AST_ATT,"=");
	char* leaf;
	leaf = create_leaf((yyvsp[-5].valor_lexico));
	add_child((yyval.no),new_node2);
	add_child((yyval.no),(yyvsp[0].no));
	new_node = create_node(AST_ARR,"[]");
	add_child(new_node,(yyvsp[-3].no));
	add_child((yyval.no),new_node);
	HASH_TABLE* table;
	table = pop(stack);
	(yyvsp[-5].valor_lexico) = altera_natureza((yyvsp[-5].valor_lexico),NAT_ARRAY);
	checkTableInUse(table,(yyvsp[-5].valor_lexico));
	push(stack,table);}
#line 2107 "parser.tab.c"
    break;

  case 73:
#line 408 "parser.y"
                                         {
	(yyval.no) = create_node(AST_ATT, "=");
	node_t* new_node;	
	char* leaf;
	leaf = create_leaf((yyvsp[-2].valor_lexico));
	new_node = create_node(AST_ID,leaf);
	add_child((yyval.no),new_node);
	add_child((yyval.no),(yyvsp[0].no));
	HASH_TABLE* table;
	table = pop(stack);
	(yyvsp[-2].valor_lexico) = altera_natureza((yyvsp[-2].valor_lexico),NAT_VARIABLE);
	checkTableInUse(table,(yyvsp[-2].valor_lexico));
	push(stack,table);}
#line 2125 "parser.tab.c"
    break;

  case 74:
#line 421 "parser.y"
                                                        {if((yyvsp[-2].no) == NULL) {(yyval.no) = (yyvsp[0].no);} else {(yyval.no) = (yyvsp[-2].no); add_child((yyval.no),(yyvsp[0].no));}}
#line 2131 "parser.tab.c"
    break;

  case 75:
#line 422 "parser.y"
                               {(yyval.no) = (yyvsp[-1].no);}
#line 2137 "parser.tab.c"
    break;

  case 76:
#line 423 "parser.y"
                                     {(yyval.no) = (yyvsp[-2].no); HASH_TABLE *table; table = create_table(HASH_SIZE); push(stack,table); add_child((yyval.no),(yyvsp[0].no));}
#line 2143 "parser.tab.c"
    break;

  case 77:
#line 424 "parser.y"
                    {(yyval.no) = (yyvsp[-1].no); HASH_TABLE *table; table = create_table(HASH_SIZE); push(stack,table);}
#line 2149 "parser.tab.c"
    break;

  case 78:
#line 425 "parser.y"
                                              {(yyval.no) = (yyvsp[-2].no); add_child((yyval.no),(yyvsp[0].no));}
#line 2155 "parser.tab.c"
    break;

  case 79:
#line 426 "parser.y"
                             {(yyval.no) = (yyvsp[-1].no);}
#line 2161 "parser.tab.c"
    break;

  case 80:
#line 427 "parser.y"
                                          {(yyval.no) = (yyvsp[-2].no); add_child((yyval.no),(yyvsp[0].no));}
#line 2167 "parser.tab.c"
    break;

  case 81:
#line 428 "parser.y"
                         {(yyval.no) = (yyvsp[-1].no);}
#line 2173 "parser.tab.c"
    break;

  case 82:
#line 429 "parser.y"
                                       {(yyval.no) = (yyvsp[-2].no); add_child((yyval.no),(yyvsp[0].no));}
#line 2179 "parser.tab.c"
    break;

  case 83:
#line 430 "parser.y"
                      {(yyval.no) = (yyvsp[-1].no);}
#line 2185 "parser.tab.c"
    break;

  case 84:
#line 431 "parser.y"
                                  {(yyval.no) = (yyvsp[-2].no); add_child((yyval.no),(yyvsp[0].no));}
#line 2191 "parser.tab.c"
    break;

  case 85:
#line 432 "parser.y"
                 {(yyval.no) = (yyvsp[-1].no);}
#line 2197 "parser.tab.c"
    break;

  case 86:
#line 433 "parser.y"
                                     {(yyval.no) = (yyvsp[-2].no); add_child((yyval.no),(yyvsp[0].no));}
#line 2203 "parser.tab.c"
    break;

  case 87:
#line 434 "parser.y"
                    {(yyval.no) = (yyvsp[-1].no);}
#line 2209 "parser.tab.c"
    break;

  case 88:
#line 435 "parser.y"
                                {(yyval.no) = create_node(AST_RET,"return"); add_child((yyval.no),(yyvsp[0].no));}
#line 2215 "parser.tab.c"
    break;

  case 89:
#line 436 "parser.y"
                                                     {(yyval.no) = create_node(AST_IF,"if"); add_child((yyval.no),(yyvsp[-4].no)); add_child((yyval.no),(yyvsp[-1].no)); add_child((yyval.no),(yyvsp[0].no));}
#line 2221 "parser.tab.c"
    break;

  case 90:
#line 437 "parser.y"
                       {(yyval.no) = (yyvsp[0].no);}
#line 2227 "parser.tab.c"
    break;

  case 91:
#line 438 "parser.y"
          {(yyval.no) = NULL;}
#line 2233 "parser.tab.c"
    break;

  case 92:
#line 439 "parser.y"
                                           {(yyval.no) = create_node(AST_WHILE,"while"); add_child((yyval.no),(yyvsp[-2].no)); add_child((yyval.no),(yyvsp[0].no));}
#line 2239 "parser.tab.c"
    break;


#line 2243 "parser.tab.c"

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
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

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


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
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
                  yystos[+*yyssp], yyvsp);
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
#line 440 "parser.y"

void yyerror (char const *s){
	fprintf(stderr, "%s in line %d.\n",s,get_line_number());
}
