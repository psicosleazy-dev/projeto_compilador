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




/* First part of user prologue.  */
#line 1 "parser.y"

int yylex(void);
void yyerror (char const *s);

#line 75 "parser.tab.c"

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
#line 8 "parser.y"

#include "stack_management.h"
extern Stack* stack;
LISTA* lista;
extern int get_line_number();
extern void* arvore;

#line 126 "parser.tab.c"

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    TK_LIT_INT = 258,
    TK_LIT_FLOAT = 259,
    TK_LIT_TRUE = 260,
    TK_LIT_FALSE = 261,
    TK_IDENTIFICADOR = 262,
    TK_PR_INT = 263,
    TK_PR_FLOAT = 264,
    TK_PR_BOOL = 265,
    TK_PR_CHAR = 266,
    TK_PR_IF = 267,
    TK_PR_THEN = 268,
    TK_PR_ELSE = 269,
    TK_PR_WHILE = 270,
    TK_PR_RETURN = 271,
    TK_OC_LE = 272,
    TK_OC_GE = 273,
    TK_OC_EQ = 274,
    TK_OC_NE = 275,
    TK_OC_AND = 276,
    TK_OC_OR = 277,
    TK_LIT_CHAR = 278,
    TK_ERRO = 279
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 16 "parser.y"

 node_t *no;
 valor_t valor_lexico;

#line 167 "parser.tab.c"

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
#define YYLAST   160

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  43
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  94
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  167

#define YYUNDEFTOK  2
#define YYMAXUTOK   279


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
       2,     2,     2,    39,     2,     2,     2,    38,     2,     2,
      26,    27,    36,    34,    28,    35,     2,    37,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    25,
      33,    42,    32,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    29,     2,    30,    31,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    40,     2,    41,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    76,    76,    77,    78,    79,    80,    81,    82,   108,
     109,   110,   111,   112,   113,   114,   134,   152,   164,   177,
     191,   193,   195,   206,   217,   227,   230,   233,   246,   256,
     271,   272,   287,   288,   319,   350,   351,   381,   411,   441,
     471,   472,   490,   507,   508,   526,   543,   544,   545,   546,
     547,   548,   549,   550,   551,   552,   553,   554,   555,   556,
     566,   575,   595,   613,   623,   641,   658,   659,   662,   663,
     664,   670,   676,   677,   693,   721,   722,   723,   724,   725,
     726,   727,   728,   729,   730,   731,   732,   733,   734,   735,
     736,   737,   748,   779,   804
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TK_LIT_INT", "TK_LIT_FLOAT",
  "TK_LIT_TRUE", "TK_LIT_FALSE", "TK_IDENTIFICADOR", "TK_PR_INT",
  "TK_PR_FLOAT", "TK_PR_BOOL", "TK_PR_CHAR", "TK_PR_IF", "TK_PR_THEN",
  "TK_PR_ELSE", "TK_PR_WHILE", "TK_PR_RETURN", "TK_OC_LE", "TK_OC_GE",
  "TK_OC_EQ", "TK_OC_NE", "TK_OC_AND", "TK_OC_OR", "TK_LIT_CHAR",
  "TK_ERRO", "';'", "'('", "')'", "','", "'['", "']'", "'^'", "'>'", "'<'",
  "'+'", "'-'", "'*'", "'/'", "'%'", "'!'", "'{'", "'}'", "'='", "$accept",
  "programa", "lista", "funcao", "tipo", "declaracao_global",
  "declaracao_local", "lista_nomes_local", "lista_nomes_global",
  "lista_inteiros", "expressao", "prec_six", "prec_five", "prec_four",
  "prec_three", "prec_two", "prec_one", "prec_zero", "expressoes",
  "argumentos", "args", "chamada_funcao", "operando", "_empilha", "bloco",
  "parametros", "atribuicao", "comandos_simples", "retorno", "if_else",
  "if", "while", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,    59,    40,    41,    44,    91,
      93,    94,    62,    60,    43,    45,    42,    47,    37,    33,
     123,   125,    61
};
# endif

#define YYPACT_NINF (-85)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      69,   -85,   -85,   -85,   -85,    28,   -85,    69,    83,    36,
     -85,   -85,    38,    14,    69,    69,   115,   112,   -85,   113,
      54,   -85,   -10,    92,   -85,    84,    69,   -85,   119,   115,
      85,   -85,   116,   -85,    39,   -85,    22,   -85,   -85,    -7,
     102,   103,     1,   123,   106,   107,   108,   109,    94,   114,
     117,   118,   120,     1,     1,     1,     1,     1,   -85,   -85,
     -85,   -85,    73,     1,     1,     1,   122,   125,    81,    42,
      76,    68,   -85,   -85,   -85,   -85,    -5,   110,    22,    22,
      22,    22,   -85,    22,    22,    22,    22,    21,   -85,   121,
      35,   111,   122,    17,    41,     1,    49,   -85,   -85,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,   134,   115,   133,   -85,   -85,   -85,   -85,   -85,
     -85,   -85,   -85,     1,   -85,     1,   105,   136,    84,   124,
     -85,   125,    81,    42,    42,    76,    76,    76,    76,    68,
      68,   -85,   -85,   -85,   -85,    77,    -3,   -85,   -85,     1,
      84,   -85,   -85,   135,   147,   115,   122,   137,   150,   -85,
      82,    84,   -85,   138,   -85,   153,   -85
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,     9,    10,    11,    12,     0,     2,     4,     0,     0,
       1,     5,    26,    13,     6,    72,     0,     0,     7,     0,
       0,    28,     0,    25,    71,     0,     0,    24,     0,     0,
      67,     8,     0,    27,     0,    69,     0,    70,    23,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    58,     0,     0,     0,     0,    62,    63,
      65,    64,    61,     0,     0,     0,    91,    30,    32,    35,
      40,    43,    47,    50,    66,    52,    20,    14,    76,    80,
      78,    82,    68,    84,    88,    86,    90,    56,    57,     0,
      54,     0,    74,     0,     0,     0,     0,    49,    48,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    75,    79,    77,    81,    83,
      87,    85,    89,     0,    59,     0,     0,     0,     0,     0,
      51,    29,    31,    33,    34,    38,    39,    36,    37,    41,
      42,    44,    45,    46,    18,     0,    21,    55,    53,     0,
       0,    94,    60,    17,     0,     0,    73,    93,     0,    19,
       0,     0,    16,    22,    92,     0,    15
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -85,   -85,    11,   -85,    58,   -85,   -85,   -85,   -85,   -28,
     -40,    59,    57,    13,    -8,     9,   -55,   -85,   -84,    37,
     -85,   -33,   -85,   -85,   -25,   -85,   -85,     8,   -85,   -85,
     -85,   -85
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     5,     6,     7,    43,     9,    44,    77,    13,    22,
      90,    67,    68,    69,    70,    71,    72,    73,    91,    88,
      89,    74,    75,    36,    46,    20,    47,    48,    49,    50,
      51,    52
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      31,    34,    66,    45,    58,    59,    60,    61,    62,    97,
      98,   129,   112,    87,   154,    92,    93,    94,    11,    53,
      27,    28,    54,    96,   113,    18,   155,    63,    10,    39,
       1,     2,     3,     4,    40,    55,    64,    41,    42,    99,
      65,   148,    17,    99,   127,    45,    45,    45,    45,   123,
      45,    45,    45,    45,   141,   142,   143,    99,     8,   103,
     104,    14,    30,    99,    15,     8,   125,    16,   128,    38,
      28,    99,     8,    19,   105,   106,   130,     1,     2,     3,
       4,    25,    26,    87,    32,   145,   115,   116,   117,   118,
      12,   119,   120,   121,   122,   135,   136,   137,   138,    53,
     101,   102,    95,   151,   109,   110,   111,   153,    28,   156,
     107,   108,   163,    28,   133,   134,   139,   140,    21,    23,
      24,    29,    33,    37,    30,   157,    35,   160,    56,    57,
      76,    78,    79,    80,    81,    82,   164,   144,   114,    83,
     146,   126,    84,    85,    99,    86,   100,   149,   124,   150,
     159,   161,   158,   162,   152,   165,   166,   132,   131,     0,
     147
};

static const yytype_int16 yycheck[] =
{
      25,    29,    42,    36,     3,     4,     5,     6,     7,    64,
      65,    95,    17,    53,    17,    55,    56,    57,     7,    26,
      30,    31,    29,    63,    29,    14,    29,    26,     0,     7,
       8,     9,    10,    11,    12,    42,    35,    15,    16,    22,
      39,   125,    28,    22,    27,    78,    79,    80,    81,    28,
      83,    84,    85,    86,   109,   110,   111,    22,     0,    17,
      18,    25,    40,    22,    26,     7,    31,    29,    27,    30,
      31,    22,    14,    15,    32,    33,    27,     8,     9,    10,
      11,    27,    28,   123,    26,   113,    78,    79,    80,    81,
       7,    83,    84,    85,    86,   103,   104,   105,   106,    26,
      19,    20,    29,   128,    36,    37,    38,    30,    31,   149,
      34,    35,    30,    31,   101,   102,   107,   108,     3,     7,
       7,    29,     3,     7,    40,   150,    41,   155,    26,    26,
       7,    25,    25,    25,    25,    41,   161,     3,    28,    25,
       7,    30,    25,    25,    22,    25,    21,    42,    27,    13,
       3,    14,    17,     3,    30,    17,     3,   100,    99,    -1,
     123
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     8,     9,    10,    11,    44,    45,    46,    47,    48,
       0,    45,     7,    51,    25,    26,    29,    28,    45,    47,
      68,     3,    52,     7,     7,    27,    28,    30,    31,    29,
      40,    67,    47,     3,    52,    41,    66,     7,    30,     7,
      12,    15,    16,    47,    49,    64,    67,    69,    70,    71,
      72,    73,    74,    26,    29,    42,    26,    26,     3,     4,
       5,     6,     7,    26,    35,    39,    53,    54,    55,    56,
      57,    58,    59,    60,    64,    65,     7,    50,    25,    25,
      25,    25,    41,    25,    25,    25,    25,    53,    62,    63,
      53,    61,    53,    53,    53,    29,    53,    59,    59,    22,
      21,    19,    20,    17,    18,    32,    33,    34,    35,    36,
      37,    38,    17,    29,    28,    70,    70,    70,    70,    70,
      70,    70,    70,    28,    27,    31,    30,    27,    27,    61,
      27,    54,    55,    56,    56,    57,    57,    57,    57,    58,
      58,    59,    59,    59,     3,    52,     7,    62,    61,    42,
      13,    67,    30,    30,    17,    29,    53,    67,    17,     3,
      52,    14,     3,    30,    67,    17,     3
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    43,    44,    44,    45,    45,    45,    45,    46,    47,
      47,    47,    47,    48,    49,    50,    50,    50,    50,    50,
      50,    50,    50,    51,    51,    51,    51,    52,    52,    53,
      53,    54,    54,    55,    55,    55,    56,    56,    56,    56,
      56,    57,    57,    57,    58,    58,    58,    58,    59,    59,
      59,    60,    60,    61,    61,    62,    62,    63,    63,    64,
      65,    65,    65,    65,    65,    65,    65,    66,    67,    67,
      68,    68,    68,    69,    69,    70,    70,    70,    70,    70,
      70,    70,    70,    70,    70,    70,    70,    70,    70,    70,
      70,    71,    72,    73,    74
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     0,     1,     2,     2,     3,     6,     1,
       1,     1,     1,     2,     2,     8,     6,     4,     3,     5,
       1,     3,     6,     6,     4,     3,     1,     3,     1,     3,
       1,     3,     1,     3,     3,     1,     3,     3,     3,     3,
       1,     3,     3,     1,     3,     3,     3,     1,     2,     2,
       1,     3,     1,     3,     1,     3,     1,     1,     0,     4,
       4,     1,     1,     1,     1,     1,     1,     0,     4,     2,
       4,     2,     0,     6,     3,     3,     2,     3,     2,     3,
       2,     3,     2,     3,     2,     3,     2,     3,     2,     3,
       2,     2,     8,     6,     5
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
#line 76 "parser.y"
                {arvore = (void*)(yyval.no); (yyval.no) = (yyvsp[0].no);}
#line 1460 "parser.tab.c"
    break;

  case 3:
#line 77 "parser.y"
          {arvore = (void*)(yyval.no); (yyval.no) = NULL;}
#line 1466 "parser.tab.c"
    break;

  case 4:
#line 78 "parser.y"
              {(yyval.no) = (yyvsp[0].no);}
#line 1472 "parser.tab.c"
    break;

  case 5:
#line 79 "parser.y"
                       {(yyval.no) = (yyvsp[-1].no); add_child((yyvsp[-1].no),(yyvsp[0].no));}
#line 1478 "parser.tab.c"
    break;

  case 6:
#line 80 "parser.y"
                                {(yyval.no) = (yyvsp[-1].no);}
#line 1484 "parser.tab.c"
    break;

  case 7:
#line 81 "parser.y"
                                      {if(!(yyvsp[-2].no)) {(yyval.no) = (yyvsp[0].no);} else{add_child((yyvsp[-2].no),(yyvsp[0].no)); (yyval.no) = (yyvsp[-2].no);}}
#line 1490 "parser.tab.c"
    break;

  case 8:
#line 82 "parser.y"
                                                       { // adicionar na tabela o label da funcao funcao: header body
	char* leaf;
	leaf = create_leaf((yyvsp[-4].valor_lexico));
	(yyval.no) = create_node(AST_FUNC,leaf);
	add_child((yyval.no),(yyvsp[0].no));
	(yyvsp[-4].valor_lexico) = altera_natureza((yyvsp[-4].valor_lexico),NAT_FUNCTION);
	(yyvsp[-4].valor_lexico) = altera_tipo((yyvsp[-4].valor_lexico),(yyvsp[-5].valor_lexico));
	checkTableDec(stack,(yyvsp[-4].valor_lexico));
	HASH_TABLE* table;
	table = pop(stack);
	insert_item(table,(yyvsp[-4].valor_lexico));
	push(stack,table);
	// vamos gerar codigo
	char* label_da_funcao;
	label_da_funcao = retorna_label(stack,(yyvsp[-4].valor_lexico).value.token);
	LISTA_ILOCS* l = NULL;
	ILOC inst;
	inst = gera_inst(ILOC_JUMP,"jumpI",NULL,NULL,label_da_funcao);
	// printf("label ta aqui: %s",inst.res);
	insere_lista_ilocs(&l,inst);
	inst = gera_inst(ILOC_NOP,"nop",NULL,NULL,NULL);
	inst = gera_inst_com_label(label_da_funcao,inst);
	insere_lista_ilocs(&l,inst);
	l = concat_lista_ilocs(l,(yyvsp[0].no)->code);
	(yyval.no)->code = l;
	}
#line 1521 "parser.tab.c"
    break;

  case 9:
#line 108 "parser.y"
                {inicializar_lista(&lista);}
#line 1527 "parser.tab.c"
    break;

  case 10:
#line 109 "parser.y"
                      {inicializar_lista(&lista);}
#line 1533 "parser.tab.c"
    break;

  case 11:
#line 110 "parser.y"
                     {inicializar_lista(&lista);}
#line 1539 "parser.tab.c"
    break;

  case 12:
#line 111 "parser.y"
                     {inicializar_lista(&lista);}
#line 1545 "parser.tab.c"
    break;

  case 13:
#line 112 "parser.y"
                                           {altera_tipo_na_lista(lista,(yyvsp[-1].valor_lexico)); insere_lista_na_tabela(lista,stack); (yyval.no) = (yyvsp[0].no);}
#line 1551 "parser.tab.c"
    break;

  case 14:
#line 113 "parser.y"
                                         {altera_tipo_na_lista(lista,(yyvsp[-1].valor_lexico)); insere_lista_na_tabela(lista,stack); (yyval.no) = (yyvsp[0].no);}
#line 1557 "parser.tab.c"
    break;

  case 15:
#line 114 "parser.y"
                                                                                                     {
	node_t *new_node;
	(yyval.no) = create_node(AST_INIT,"<=");
	char *leaf;
	leaf = create_leaf((yyvsp[-5].valor_lexico));
	node_t* new_node2;
	new_node2 = create_node(AST_ID,leaf);
	add_child((yyval.no),new_node2);
	add_child((yyval.no),(yyvsp[-7].no));
	add_child((yyval.no),(yyvsp[-3].no));
	leaf = create_leaf((yyvsp[0].valor_lexico));
	node_t* new_node3;
	new_node3 = create_node(AST_LIT_INT,leaf);
	add_child((yyval.no),new_node3);
	new_node = create_node(AST_ARR,"[]");
	add_child(new_node,new_node2);
	add_child(new_node,(yyvsp[-3].no));
	add_child((yyval.no),new_node);
	(yyvsp[-5].valor_lexico) = altera_natureza((yyvsp[-5].valor_lexico),NAT_ARRAY);
	lista = insere(lista,(yyvsp[-5].valor_lexico));}
#line 1582 "parser.tab.c"
    break;

  case 16:
#line 134 "parser.y"
                                                                      {
	node_t *new_node;
	(yyval.no) = create_node(AST_INIT,"<=");
	char *leaf;
	leaf = create_leaf((yyvsp[-5].valor_lexico));
	node_t* new_node2;
	new_node2 = create_node(AST_ID,leaf);
	add_child((yyval.no),new_node2);
	leaf = create_leaf((yyvsp[0].valor_lexico));
	node_t* new_node3;
	new_node3 = create_node(AST_LIT_INT,leaf);
	add_child((yyval.no),new_node3);
	new_node = create_node(AST_ARR,"[]");
	add_child(new_node,new_node2);
	add_child(new_node,(yyvsp[-3].no));
	add_child((yyval.no),new_node);
	(yyvsp[-5].valor_lexico) = altera_natureza((yyvsp[-5].valor_lexico),NAT_ARRAY);
	lista = insere(lista,(yyvsp[-5].valor_lexico));}
#line 1605 "parser.tab.c"
    break;

  case 17:
#line 152 "parser.y"
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
	lista = insere(lista,(yyvsp[-3].valor_lexico));}
#line 1622 "parser.tab.c"
    break;

  case 18:
#line 164 "parser.y"
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
	(yyvsp[-2].valor_lexico) = altera_natureza((yyvsp[-2].valor_lexico),NAT_VARIABLE);
	lista = insere(lista,(yyvsp[-2].valor_lexico));}
#line 1640 "parser.tab.c"
    break;

  case 19:
#line 177 "parser.y"
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
	(yyvsp[-2].valor_lexico) = altera_natureza((yyvsp[-2].valor_lexico),NAT_VARIABLE);
	lista = insere(lista,(yyvsp[-2].valor_lexico));}
#line 1659 "parser.tab.c"
    break;

  case 20:
#line 191 "parser.y"
                           {(yyvsp[0].valor_lexico) = altera_natureza((yyvsp[0].valor_lexico),NAT_VARIABLE);
	lista = insere(lista,(yyvsp[0].valor_lexico)); (yyval.no) = NULL;}
#line 1666 "parser.tab.c"
    break;

  case 21:
#line 193 "parser.y"
                                                 {(yyval.no) = (yyvsp[-2].no); (yyvsp[0].valor_lexico) = altera_natureza((yyvsp[0].valor_lexico),NAT_VARIABLE);
	lista = insere(lista,(yyvsp[0].valor_lexico));}
#line 1673 "parser.tab.c"
    break;

  case 22:
#line 195 "parser.y"
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
		lista = insere(lista,(yyvsp[-3].valor_lexico));}
#line 1689 "parser.tab.c"
    break;

  case 23:
#line 206 "parser.y"
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
	lista = insere(lista,(yyvsp[-3].valor_lexico));}
#line 1705 "parser.tab.c"
    break;

  case 24:
#line 217 "parser.y"
                                                  {
	(yyval.no) = create_node(AST_ARR,"[]");
	node_t* new_node;	
	char* leaf;
	leaf = create_leaf((yyvsp[-3].valor_lexico));
	new_node = create_node(AST_ID,leaf);
	add_child((yyval.no),new_node); 
	add_child((yyval.no),(yyvsp[-1].no));
	(yyvsp[-3].valor_lexico) = altera_natureza((yyvsp[-3].valor_lexico),NAT_ARRAY);
	lista = insere(lista,(yyvsp[-3].valor_lexico));}
#line 1720 "parser.tab.c"
    break;

  case 25:
#line 227 "parser.y"
                                                  {(yyval.no) = (yyvsp[-2].no);
	(yyvsp[0].valor_lexico) = altera_natureza((yyvsp[0].valor_lexico),NAT_VARIABLE);
	lista = insere(lista,(yyvsp[0].valor_lexico));}
#line 1728 "parser.tab.c"
    break;

  case 26:
#line 230 "parser.y"
                           {(yyval.no) = NULL;
	(yyvsp[0].valor_lexico) = altera_natureza((yyvsp[0].valor_lexico),NAT_VARIABLE);
	lista = insere(lista,(yyvsp[0].valor_lexico));}
#line 1736 "parser.tab.c"
    break;

  case 27:
#line 233 "parser.y"
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
#line 1754 "parser.tab.c"
    break;

  case 28:
#line 246 "parser.y"
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
#line 1769 "parser.tab.c"
    break;

  case 29:
#line 256 "parser.y"
                                       {(yyval.no) = create_node(AST_OR, "||");
add_child((yyval.no),(yyvsp[-2].no));
add_child((yyval.no),(yyvsp[0].no));
(yyval.no) = inf_tipo((yyval.no),(yyvsp[-2].no),(yyvsp[0].no),AST_OR);
(yyval.no)->temp = gera_temp();
LISTA_ILOCS *l = NULL, *code_1 = NULL, *code_3 = NULL;
ILOC inst;
inst = gera_inst(ILOC_OR,"or",(yyvsp[-2].no)->temp,(yyvsp[0].no)->temp,(yyval.no)->temp);
insere_lista_ilocs(&l,inst);
code_1 = (yyvsp[-2].no)->code;
code_3 = (yyvsp[0].no)->code;
code_1 = concat_lista_ilocs(code_1,code_3);
code_1 = concat_lista_ilocs(code_1,l);
(yyval.no)->code = code_1;
}
#line 1789 "parser.tab.c"
    break;

  case 30:
#line 271 "parser.y"
                   {(yyval.no) = (yyvsp[0].no);}
#line 1795 "parser.tab.c"
    break;

  case 31:
#line 272 "parser.y"
                                       {(yyval.no) = create_node(AST_AND, "&&");
add_child((yyval.no),(yyvsp[-2].no));
add_child((yyval.no),(yyvsp[0].no));
(yyval.no) = inf_tipo((yyval.no),(yyvsp[-2].no),(yyvsp[0].no),AST_AND);
(yyval.no)->temp = gera_temp();
LISTA_ILOCS *l = NULL, *code_1, *code_3;
ILOC inst;
inst = gera_inst(ILOC_AND,"and",(yyvsp[-2].no)->temp,(yyvsp[0].no)->temp,(yyval.no)->temp);
insere_lista_ilocs(&l,inst);
code_1 = (yyvsp[-2].no)->code;
code_3 = (yyvsp[0].no)->code;
code_1 = concat_lista_ilocs(code_1,code_3);
code_1 = concat_lista_ilocs(code_1,l);
(yyval.no)->code = code_1;
}
#line 1815 "parser.tab.c"
    break;

  case 32:
#line 287 "parser.y"
                    {(yyval.no) = (yyvsp[0].no);}
#line 1821 "parser.tab.c"
    break;

  case 33:
#line 288 "parser.y"
                                        {(yyval.no) = create_node(AST_EQ, "==");
add_child((yyval.no),(yyvsp[-2].no));
add_child((yyval.no),(yyvsp[0].no));
(yyval.no) = inf_tipo((yyval.no),(yyvsp[-2].no),(yyvsp[0].no),AST_EQ);
(yyval.no)->temp = strdup(gera_temp());
char *label_true = strdup(gera_rotulo());
char *label_false = strdup(gera_rotulo());
char *next = strdup(gera_rotulo());
LISTA_ILOCS *l = NULL;
ILOC inst = gera_inst(ILOC_LE,"cmp_EQ",(yyvsp[-2].no)->temp,(yyvsp[0].no)->temp,(yyval.no)->temp);
insere_lista_ilocs(&l,inst);
ILOC inst2 = gera_inst(ILOC_BR,"cbr",(yyval.no)->temp,label_true,label_false);
insere_lista_ilocs(&l,inst2);
ILOC inst3 = gera_inst(ILOC_LOADI,"loadI","1",NULL,(yyval.no)->temp);
inst3 = gera_inst_com_label(label_true,inst3);
insere_lista_ilocs(&l,inst3);
ILOC inst4 = gera_inst(ILOC_JUMP,"jumpI",NULL,NULL,next);
insere_lista_ilocs(&l,inst4);
ILOC inst5 = gera_inst(ILOC_LOADI,"loadI","0",NULL,(yyval.no)->temp);
inst5 = gera_inst_com_label(label_false,inst5);
insere_lista_ilocs(&l,inst5);
ILOC inst6 = gera_inst(ILOC_NOP,"nop",NULL,NULL,NULL);
inst6 = gera_inst_com_label(next,inst6);
insere_lista_ilocs(&l,inst6);
LISTA_ILOCS *code_1 = NULL,*code_3 = NULL;
code_1 = (yyvsp[-2].no)->code;
code_3 = (yyvsp[0].no)->code;
code_1 = concat_lista_ilocs(code_1,code_3);
code_1 = concat_lista_ilocs(code_1,l);
(yyval.no)->code = code_1;
}
#line 1857 "parser.tab.c"
    break;

  case 34:
#line 319 "parser.y"
                                       {(yyval.no) = create_node(AST_NE, "!=");
	add_child((yyval.no),(yyvsp[-2].no));
	add_child((yyval.no),(yyvsp[0].no));
	(yyval.no) = inf_tipo((yyval.no),(yyvsp[-2].no),(yyvsp[0].no),AST_NE);
	(yyval.no)->temp = gera_temp();
	char *label_true = gera_rotulo();
	char *label_false = gera_rotulo();
	char *next = gera_rotulo();
	LISTA_ILOCS *l = NULL;
	ILOC inst = gera_inst(ILOC_LE,"cmp_NE",(yyvsp[-2].no)->temp,(yyvsp[0].no)->temp,(yyval.no)->temp);
	insere_lista_ilocs(&l,inst);
	ILOC inst2 = gera_inst(ILOC_BR,"cbr",(yyval.no)->temp,label_true,label_false);
	insere_lista_ilocs(&l,inst2);
	ILOC inst3 = gera_inst(ILOC_LOADI,"loadI","1",NULL,(yyval.no)->temp);
	inst3 = gera_inst_com_label(label_true,inst3);
	insere_lista_ilocs(&l,inst3);
	ILOC inst4 = gera_inst(ILOC_JUMP,"jumpI",NULL,NULL,next);
	insere_lista_ilocs(&l,inst4);
	ILOC inst5 = gera_inst(ILOC_LOADI,"loadI","0",NULL,(yyval.no)->temp);
	inst5 = gera_inst_com_label(label_false,inst5);
	insere_lista_ilocs(&l,inst5);
	ILOC inst6 = gera_inst(ILOC_NOP,"nop",NULL,NULL,NULL);
	inst6 = gera_inst_com_label(next,inst6);
	insere_lista_ilocs(&l,inst6);
	LISTA_ILOCS *code_1 = NULL,*code_3 = NULL;
	code_1 = (yyvsp[-2].no)->code;
	code_3 = (yyvsp[0].no)->code;
	code_1 = concat_lista_ilocs(code_1,code_3);
	code_1 = concat_lista_ilocs(code_1,l);
	(yyval.no)->code = code_1;
	}
#line 1893 "parser.tab.c"
    break;

  case 35:
#line 350 "parser.y"
                    {(yyval.no) = (yyvsp[0].no);}
#line 1899 "parser.tab.c"
    break;

  case 36:
#line 351 "parser.y"
                                    {(yyval.no) = create_node(AST_G, ">");
add_child((yyval.no),(yyvsp[-2].no));
add_child((yyval.no),(yyvsp[0].no));
(yyval.no) = inf_tipo((yyval.no),(yyvsp[-2].no),(yyvsp[0].no),AST_G);
(yyval.no)->temp = gera_temp();
char *label_true = gera_rotulo();
char *label_false = gera_rotulo();
char *next = gera_rotulo();
LISTA_ILOCS *l = NULL;
ILOC inst = gera_inst(ILOC_LE,"cmp_GT",(yyvsp[-2].no)->temp,(yyvsp[0].no)->temp,(yyval.no)->temp);
insere_lista_ilocs(&l,inst);
ILOC inst2 = gera_inst(ILOC_BR,"cbr",(yyval.no)->temp,label_true,label_false);
insere_lista_ilocs(&l,inst2);
ILOC inst3 = gera_inst(ILOC_LOADI,"loadI","1",NULL,(yyval.no)->temp);
inst3 = gera_inst_com_label(label_true,inst3);
insere_lista_ilocs(&l,inst3);
ILOC inst4 = gera_inst(ILOC_JUMP,"jumpI",NULL,NULL,next);
insere_lista_ilocs(&l,inst4);
ILOC inst5 = gera_inst(ILOC_LOADI,"loadI","0",NULL,(yyval.no)->temp);
inst5 = gera_inst_com_label(label_false,inst5);
insere_lista_ilocs(&l,inst5);
ILOC inst6 = gera_inst(ILOC_NOP,"nop",NULL,NULL,NULL);
inst6 = gera_inst_com_label(next,inst6);
insere_lista_ilocs(&l,inst6);
LISTA_ILOCS *code_1 = NULL,*code_3 = NULL;
code_1 = (yyvsp[-2].no)->code;
code_3 = (yyvsp[0].no)->code;
code_1 = concat_lista_ilocs(code_1,code_3);
code_1 = concat_lista_ilocs(code_1,l);
(yyval.no)->code = code_1;}
#line 1934 "parser.tab.c"
    break;

  case 37:
#line 381 "parser.y"
                                   {(yyval.no) = create_node(AST_L, "<");
	add_child((yyval.no),(yyvsp[-2].no));
	add_child((yyval.no),(yyvsp[0].no));
	(yyval.no) = inf_tipo((yyval.no),(yyvsp[-2].no),(yyvsp[0].no),AST_L);
	(yyval.no)->temp = gera_temp();
char *label_true = gera_rotulo();
char *label_false = gera_rotulo();
char *next = gera_rotulo();
LISTA_ILOCS *l = NULL;
ILOC inst = gera_inst(ILOC_LE,"cmp_LT",(yyvsp[-2].no)->temp,(yyvsp[0].no)->temp,(yyval.no)->temp);
insere_lista_ilocs(&l,inst);
ILOC inst2 = gera_inst(ILOC_BR,"cbr",(yyval.no)->temp,label_true,label_false);
insere_lista_ilocs(&l,inst2);
ILOC inst3 = gera_inst(ILOC_LOADI,"loadI","1",NULL,(yyval.no)->temp);
inst3 = gera_inst_com_label(label_true,inst3);
insere_lista_ilocs(&l,inst3);
ILOC inst4 = gera_inst(ILOC_JUMP,"jumpI",NULL,NULL,next);
insere_lista_ilocs(&l,inst4);
ILOC inst5 = gera_inst(ILOC_LOADI,"loadI","0",NULL,(yyval.no)->temp);
inst5 = gera_inst_com_label(label_false,inst5);
insere_lista_ilocs(&l,inst5);
ILOC inst6 = gera_inst(ILOC_NOP,"nop",NULL,NULL,NULL);
inst6 = gera_inst_com_label(next,inst6);
insere_lista_ilocs(&l,inst6);
LISTA_ILOCS *code_1 = NULL,*code_3 = NULL;
code_1 = (yyvsp[-2].no)->code;
code_3 = (yyvsp[0].no)->code;
code_1 = concat_lista_ilocs(code_1,code_3);
code_1 = concat_lista_ilocs(code_1,l);
(yyval.no)->code = code_1;}
#line 1969 "parser.tab.c"
    break;

  case 38:
#line 411 "parser.y"
                                        {(yyval.no) = create_node(AST_LE, "<=");
	add_child((yyval.no),(yyvsp[-2].no));
	add_child((yyval.no),(yyvsp[0].no));
	(yyval.no) = inf_tipo((yyval.no),(yyvsp[-2].no),(yyvsp[0].no),AST_LE);
	(yyval.no)->temp = gera_temp();
char *label_true = gera_rotulo();
char *label_false = gera_rotulo();
char *next = gera_rotulo();
LISTA_ILOCS *l = NULL;
ILOC inst = gera_inst(ILOC_LE,"cmp_LE",(yyvsp[-2].no)->temp,(yyvsp[0].no)->temp,(yyval.no)->temp);
insere_lista_ilocs(&l,inst);
ILOC inst2 = gera_inst(ILOC_BR,"cbr",(yyval.no)->temp,label_true,label_false);
insere_lista_ilocs(&l,inst2);
ILOC inst3 = gera_inst(ILOC_LOADI,"loadI","1",NULL,(yyval.no)->temp);
inst3 = gera_inst_com_label(label_true,inst3);
insere_lista_ilocs(&l,inst3);
ILOC inst4 = gera_inst(ILOC_JUMP,"jumpI",NULL,NULL,next);
insere_lista_ilocs(&l,inst4);
ILOC inst5 = gera_inst(ILOC_LOADI,"loadI","0",NULL,(yyval.no)->temp);
inst5 = gera_inst_com_label(label_false,inst5);
insere_lista_ilocs(&l,inst5);
ILOC inst6 = gera_inst(ILOC_NOP,"nop",NULL,NULL,NULL);
inst6 = gera_inst_com_label(next,inst6);
insere_lista_ilocs(&l,inst6);
LISTA_ILOCS *code_1 = NULL,*code_3 = NULL;
code_1 = (yyvsp[-2].no)->code;
code_3 = (yyvsp[0].no)->code;
code_1 = concat_lista_ilocs(code_1,code_3);
code_1 = concat_lista_ilocs(code_1,l);
(yyval.no)->code = code_1;}
#line 2004 "parser.tab.c"
    break;

  case 39:
#line 441 "parser.y"
                                        {(yyval.no) = create_node(AST_GE, ">=");
	add_child((yyval.no),(yyvsp[-2].no));
	add_child((yyval.no),(yyvsp[0].no));
	(yyval.no) = inf_tipo((yyval.no),(yyvsp[-2].no),(yyvsp[0].no),AST_GE);
	(yyval.no)->temp = gera_temp();
char *label_true = gera_rotulo();
char *label_false = gera_rotulo();
char *next = gera_rotulo();
LISTA_ILOCS *l = NULL;
ILOC inst = gera_inst(ILOC_LE,"cmp_GE",(yyvsp[-2].no)->temp,(yyvsp[0].no)->temp,(yyval.no)->temp);
insere_lista_ilocs(&l,inst);
ILOC inst2 = gera_inst(ILOC_BR,"cbr",(yyval.no)->temp,label_true,label_false);
insere_lista_ilocs(&l,inst2);
ILOC inst3 = gera_inst(ILOC_LOADI,"loadI","1",NULL,(yyval.no)->temp);
inst3 = gera_inst_com_label(label_true,inst3);
insere_lista_ilocs(&l,inst3);
ILOC inst4 = gera_inst(ILOC_JUMP,"jumpI",NULL,NULL,next);
insere_lista_ilocs(&l,inst4);
ILOC inst5 = gera_inst(ILOC_LOADI,"loadI","0",NULL,(yyval.no)->temp);
inst5 = gera_inst_com_label(label_false,inst5);
insere_lista_ilocs(&l,inst5);
ILOC inst6 = gera_inst(ILOC_NOP,"nop",NULL,NULL,NULL);
inst6 = gera_inst_com_label(next,inst6);
insere_lista_ilocs(&l,inst6);
LISTA_ILOCS *code_1 = NULL,*code_3 = NULL;
code_1 = (yyvsp[-2].no)->code;
code_3 = (yyvsp[0].no)->code;
code_1 = concat_lista_ilocs(code_1,code_3);
code_1 = concat_lista_ilocs(code_1,l);
(yyval.no)->code = code_1;}
#line 2039 "parser.tab.c"
    break;

  case 40:
#line 471 "parser.y"
                     {(yyval.no) = (yyvsp[0].no);}
#line 2045 "parser.tab.c"
    break;

  case 41:
#line 472 "parser.y"
                                    {(yyval.no) = create_node(AST_ADD, "+");
add_child((yyval.no),(yyvsp[-2].no));
add_child((yyval.no),(yyvsp[0].no));
(yyval.no) = inf_tipo((yyval.no),(yyvsp[-2].no),(yyvsp[0].no),AST_ADD);
(yyval.no)->temp = gera_temp();
LISTA_ILOCS *l = NULL, *code_1, *code_3;
ILOC inst;
if((yyvsp[0].no)->datatype == INT_TYPE)
    inst = gera_inst(ILOC_ADDI,"addI",(yyvsp[-2].no)->temp,(yyvsp[0].no)->temp,(yyval.no)->temp);
else
    inst = gera_inst(ILOC_ADD,"add",(yyvsp[-2].no)->temp,(yyvsp[0].no)->temp,(yyval.no)->temp);
insere_lista_ilocs(&l,inst);
code_1 = (yyvsp[-2].no)->code;
code_3 = (yyvsp[0].no)->code;
code_1 = concat_lista_ilocs(code_1,code_3);
code_1 = concat_lista_ilocs(code_1,l);
(yyval.no)->code = code_1;
}
#line 2068 "parser.tab.c"
    break;

  case 42:
#line 490 "parser.y"
                                  {(yyval.no) = create_node(AST_SUB, "-");
	add_child((yyval.no),(yyvsp[-2].no));
	add_child((yyval.no),(yyvsp[0].no));
	(yyval.no) = inf_tipo((yyval.no),(yyvsp[-2].no),(yyvsp[0].no),AST_SUB);
	(yyval.no)->temp = gera_temp();
LISTA_ILOCS *l = NULL, *code_1, *code_3;
ILOC inst;
if((yyvsp[0].no)->datatype == INT_TYPE)
    inst = gera_inst(ILOC_SUBI,"subI",(yyvsp[-2].no)->temp,(yyvsp[0].no)->temp,(yyval.no)->temp);
else
    inst = gera_inst(ILOC_SUB,"sub",(yyvsp[-2].no)->temp,(yyvsp[0].no)->temp,(yyval.no)->temp);
insere_lista_ilocs(&l,inst);
code_1 = (yyvsp[-2].no)->code;
code_3 = (yyvsp[0].no)->code;
code_1 = concat_lista_ilocs(code_1,code_3);
code_1 = concat_lista_ilocs(code_1,l);
(yyval.no)->code = code_1;}
#line 2090 "parser.tab.c"
    break;

  case 43:
#line 507 "parser.y"
                   {(yyval.no) = (yyvsp[0].no);}
#line 2096 "parser.tab.c"
    break;

  case 44:
#line 508 "parser.y"
                                {(yyval.no) = create_node(AST_MUL, "*");
add_child((yyval.no),(yyvsp[-2].no));
add_child((yyval.no),(yyvsp[0].no));
(yyval.no) = inf_tipo((yyval.no),(yyvsp[-2].no),(yyvsp[0].no),AST_MUL);
(yyval.no)->temp = gera_temp();
LISTA_ILOCS *l = NULL, *code_1, *code_3;
ILOC inst;
if((yyvsp[0].no)->datatype == INT_TYPE)
    inst = gera_inst(ILOC_MULTI,"multI",(yyvsp[-2].no)->temp,(yyvsp[0].no)->temp,(yyval.no)->temp);
else
    inst = gera_inst(ILOC_MULT,"mult",(yyvsp[-2].no)->temp,(yyvsp[0].no)->temp,(yyval.no)->temp);
insere_lista_ilocs(&l,inst);
code_1 = (yyvsp[-2].no)->code;
code_3 = (yyvsp[0].no)->code;
code_1 = concat_lista_ilocs(code_1,code_3);
code_1 = concat_lista_ilocs(code_1,l);
(yyval.no)->code = code_1;
}
#line 2119 "parser.tab.c"
    break;

  case 45:
#line 526 "parser.y"
                                {(yyval.no) = create_node(AST_DIV, "/");
	add_child((yyval.no),(yyvsp[-2].no));
	add_child((yyval.no),(yyvsp[0].no));
	(yyval.no) = inf_tipo((yyval.no),(yyvsp[-2].no),(yyvsp[0].no),AST_DIV);
	(yyval.no)->temp = gera_temp();
	LISTA_ILOCS *l = NULL, *code_1, *code_3;
	ILOC inst;
	if((yyvsp[0].no)->datatype == INT_TYPE)
		inst = gera_inst(ILOC_DIVI,"divI",(yyvsp[-2].no)->temp,(yyvsp[0].no)->temp,(yyval.no)->temp);
	else
		inst = gera_inst(ILOC_DIV,"div",(yyvsp[-2].no)->temp,(yyvsp[0].no)->temp,(yyval.no)->temp);
	insere_lista_ilocs(&l,inst);
	code_1 = (yyvsp[-2].no)->code;
	code_3 = (yyvsp[0].no)->code;
	code_1 = concat_lista_ilocs(code_1,code_3);
	code_1 = concat_lista_ilocs(code_1,l);
	(yyval.no)->code = code_1;}
#line 2141 "parser.tab.c"
    break;

  case 46:
#line 543 "parser.y"
                                {(yyval.no) = create_node(AST_MOD, "%"); add_child((yyval.no),(yyvsp[-2].no)); add_child((yyval.no),(yyvsp[0].no)); (yyval.no) = inf_tipo((yyval.no),(yyvsp[-2].no),(yyvsp[0].no),AST_MOD);}
#line 2147 "parser.tab.c"
    break;

  case 47:
#line 544 "parser.y"
                   {(yyval.no) = (yyvsp[0].no);}
#line 2153 "parser.tab.c"
    break;

  case 48:
#line 545 "parser.y"
                       {(yyval.no) = create_node(AST_NOT, "!"); add_child((yyval.no),(yyvsp[0].no));}
#line 2159 "parser.tab.c"
    break;

  case 49:
#line 546 "parser.y"
                       {(yyval.no) = create_node(AST_MINUS, "-"); add_child((yyval.no),(yyvsp[0].no));}
#line 2165 "parser.tab.c"
    break;

  case 50:
#line 547 "parser.y"
                    {(yyval.no) = (yyvsp[0].no);}
#line 2171 "parser.tab.c"
    break;

  case 51:
#line 548 "parser.y"
                             {(yyval.no) = (yyvsp[-1].no);}
#line 2177 "parser.tab.c"
    break;

  case 52:
#line 549 "parser.y"
                   {(yyval.no) = (yyvsp[0].no);}
#line 2183 "parser.tab.c"
    break;

  case 53:
#line 550 "parser.y"
                                     {(yyval.no) = create_node(AST_CIRC,"^"); add_child((yyval.no),(yyvsp[-2].no)); add_child((yyval.no),(yyvsp[0].no));}
#line 2189 "parser.tab.c"
    break;

  case 54:
#line 551 "parser.y"
                    {(yyval.no) = (yyvsp[0].no);}
#line 2195 "parser.tab.c"
    break;

  case 55:
#line 552 "parser.y"
                                     {(yyval.no) = (yyvsp[-2].no); add_child((yyval.no),(yyvsp[0].no));}
#line 2201 "parser.tab.c"
    break;

  case 56:
#line 553 "parser.y"
                    {(yyval.no) = (yyvsp[0].no);}
#line 2207 "parser.tab.c"
    break;

  case 57:
#line 554 "parser.y"
                 {(yyval.no) = (yyvsp[0].no);}
#line 2213 "parser.tab.c"
    break;

  case 58:
#line 555 "parser.y"
          {(yyval.no) = NULL;}
#line 2219 "parser.tab.c"
    break;

  case 59:
#line 556 "parser.y"
                                              {
	char label[100] = "call ", *nome_fun;
	nome_fun = strdup(create_leaf((yyvsp[-3].valor_lexico)));
	strcat(label,nome_fun);
	(yyval.no) = create_node(AST_CALL,label);
	add_child((yyval.no),(yyvsp[-1].no));
	(yyvsp[-3].valor_lexico) = altera_natureza((yyvsp[-3].valor_lexico),NAT_FUNCTION);
	checkTableInUse(stack,(yyvsp[-3].valor_lexico));
}
#line 2233 "parser.tab.c"
    break;

  case 60:
#line 566 "parser.y"
                                              {
(yyval.no) = create_node(AST_INDEX,"[]");
	node_t* new_node;
	char* leaf;
	leaf = create_leaf((yyvsp[-3].valor_lexico));
	new_node = create_node(AST_ID,leaf); add_child((yyval.no),new_node); add_child((yyval.no),(yyvsp[-1].no));
	checkTableInUse(stack,(yyvsp[-3].valor_lexico));
	int tipo = retorna_tipo_simbolo((yyvsp[-3].valor_lexico),stack);
	(yyval.no) = altera_tipo_no((yyval.no),tipo);}
#line 2247 "parser.tab.c"
    break;

  case 61:
#line 575 "parser.y"
                           {
	char* leaf;
	leaf = create_leaf((yyvsp[0].valor_lexico));
	(yyval.no) = create_node(AST_ID,leaf);
	(yyvsp[0].valor_lexico) = altera_natureza((yyvsp[0].valor_lexico),NAT_VARIABLE);
	checkTableInUse(stack,(yyvsp[0].valor_lexico));
	int tipo = retorna_tipo_simbolo((yyvsp[0].valor_lexico),stack);
	(yyval.no) = altera_tipo_no((yyval.no),tipo);
    (yyval.no)->temp = strdup(gera_temp());
	LISTA_ILOCS* l = NULL;
	ILOC inst;
	char buf[2];
	sprintf(buf, "%d", retorna_end_desloc(stack,(yyvsp[0].valor_lexico)));
	if(escopo_global(stack,(yyvsp[0].valor_lexico)))
	   inst = gera_inst(ILOC_LOADAI,"loadAI","rbss",buf,(yyval.no)->temp);
	else
	   inst = gera_inst(ILOC_LOADAI,"loadAI","rfp",buf,(yyval.no)->temp);
	insere_lista_ilocs(&l,inst);
	(yyval.no)->code = l;
	}
#line 2272 "parser.tab.c"
    break;

  case 62:
#line 595 "parser.y"
                     {char* leaf;
	leaf = create_leaf((yyvsp[0].valor_lexico));
	char buf[2];
	sprintf(buf,"%d",atoi(leaf));
	(yyval.no) = create_node(AST_LIT_INT,leaf);
	(yyval.no) = altera_datatype((yyval.no));
	(yyvsp[0].valor_lexico) = altera_natureza((yyvsp[0].valor_lexico),NAT_LITERAL);
	HASH_TABLE* table;
	table = pop(stack);
	insert_item(table,(yyvsp[0].valor_lexico));
	push(stack,table);
	(yyval.no)->temp = gera_temp();
	LISTA_ILOCS* l = NULL;
	ILOC inst;
	inst = gera_inst(ILOC_LOADI,"loadI",buf,NULL,(yyval.no)->temp);
	insere_lista_ilocs(&l,inst);
	(yyval.no)->code = l;
	}
#line 2295 "parser.tab.c"
    break;

  case 63:
#line 613 "parser.y"
                       {
	char* leaf;
	leaf = create_leaf((yyvsp[0].valor_lexico));
	(yyval.no) = create_node(AST_LIT_FLOAT,leaf);
	(yyval.no) = altera_datatype((yyval.no));
	(yyvsp[0].valor_lexico) = altera_natureza((yyvsp[0].valor_lexico),NAT_LITERAL);
	HASH_TABLE* table;
	table = pop(stack);
	insert_item(table,(yyvsp[0].valor_lexico));
	push(stack,table);}
#line 2310 "parser.tab.c"
    break;

  case 64:
#line 623 "parser.y"
                       {char* leaf;
	leaf = create_leaf((yyvsp[0].valor_lexico));
	(yyval.no) = create_node(AST_LIT_FALSE,leaf);
	(yyval.no) = altera_datatype((yyval.no));
	(yyvsp[0].valor_lexico) = altera_natureza((yyvsp[0].valor_lexico),NAT_LITERAL);
	HASH_TABLE* table;
	table = pop(stack);
	insert_item(table,(yyvsp[0].valor_lexico));
	push(stack,table);
	(yyval.no)->temp = gera_temp();
	LISTA_ILOCS* l = NULL;
	ILOC inst;
	char buf[2];
	sprintf(buf,"%d",(yyvsp[0].valor_lexico).value.int_value);
	inst = gera_inst(ILOC_LOADI,"loadI",buf,NULL,(yyval.no)->temp);
	insere_lista_ilocs(&l,inst);
	(yyval.no)->code = l;
	}
#line 2333 "parser.tab.c"
    break;

  case 65:
#line 641 "parser.y"
                      {char* leaf;
	leaf = create_leaf((yyvsp[0].valor_lexico));
	(yyval.no) = create_node(AST_LIT_TRUE,leaf);
	(yyval.no) = altera_datatype((yyval.no));
	(yyvsp[0].valor_lexico) = altera_natureza((yyvsp[0].valor_lexico),NAT_LITERAL);
	HASH_TABLE* table;
	table = pop(stack);
	insert_item(table,(yyvsp[0].valor_lexico));
	push(stack,table);
	(yyval.no)->temp = gera_temp();
	LISTA_ILOCS* l = NULL;
	ILOC inst;
	char buf[2];
	sprintf(buf, "%d", (yyvsp[0].valor_lexico).value.int_value);
	inst = gera_inst(ILOC_LOADI,"loadI",buf,NULL,(yyval.no)->temp);
	insere_lista_ilocs(&l,inst);
	(yyval.no)->code = l;}
#line 2355 "parser.tab.c"
    break;

  case 66:
#line 658 "parser.y"
                         {(yyval.no) = (yyvsp[0].no);}
#line 2361 "parser.tab.c"
    break;

  case 67:
#line 659 "parser.y"
          {HASH_TABLE* table;
	table = create_table(HASH_SIZE);
	push(stack,table);}
#line 2369 "parser.tab.c"
    break;

  case 68:
#line 662 "parser.y"
                                         {(yyval.no) = (yyvsp[-1].no);}
#line 2375 "parser.tab.c"
    break;

  case 69:
#line 663 "parser.y"
                  {(yyval.no) = NULL;}
#line 2381 "parser.tab.c"
    break;

  case 70:
#line 664 "parser.y"
                                                 {(yyvsp[0].valor_lexico) = altera_natureza((yyvsp[0].valor_lexico),NAT_VARIABLE);
    (yyvsp[0].valor_lexico) = altera_tipo((yyvsp[0].valor_lexico),(yyvsp[-1].valor_lexico));
	HASH_TABLE* table;
	table = pop(stack);
	insert_item(table,(yyvsp[0].valor_lexico));
	push(stack,table);}
#line 2392 "parser.tab.c"
    break;

  case 71:
#line 670 "parser.y"
                                {(yyvsp[0].valor_lexico) = altera_natureza((yyvsp[0].valor_lexico),NAT_VARIABLE);
	(yyvsp[-1].valor_lexico) = altera_tipo((yyvsp[0].valor_lexico),(yyvsp[-1].valor_lexico));
	HASH_TABLE* table;
	table = pop(stack);
	insert_item(table,(yyvsp[0].valor_lexico));
	push(stack,table);}
#line 2403 "parser.tab.c"
    break;

  case 73:
#line 677 "parser.y"
                                                              {
node_t *new_node;
	(yyval.no) = create_node(AST_ATT,"=");
	char* leaf;
	leaf = create_leaf((yyvsp[-5].valor_lexico));
	new_node = create_node(AST_ID,leaf);
	add_child((yyval.no),new_node);
	add_child((yyval.no),(yyvsp[0].no));
	(yyvsp[-5].valor_lexico) = altera_natureza((yyvsp[-5].valor_lexico),NAT_ARRAY);
	checkTableInUse(stack,(yyvsp[-5].valor_lexico));
	int tipo = retorna_tipo_simbolo((yyvsp[-5].valor_lexico),stack);
	new_node = altera_tipo_no(new_node,tipo);
	(yyval.no) = inf_tipo((yyval.no),new_node,(yyvsp[0].no),AST_ATT);
	new_node = create_node(AST_ARR,"[]");
	add_child((yyval.no),(yyvsp[-3].no));
	add_child((yyval.no),new_node);}
#line 2424 "parser.tab.c"
    break;

  case 74:
#line 693 "parser.y"
                                         {
	(yyval.no) = create_node(AST_ATT, "=");
	node_t* new_node;	
	char* leaf;
	leaf = create_leaf((yyvsp[-2].valor_lexico));
	new_node = create_node(AST_ID,leaf);
	add_child((yyval.no),new_node);
	add_child((yyval.no),(yyvsp[0].no));
	(yyvsp[-2].valor_lexico) = altera_natureza((yyvsp[-2].valor_lexico),NAT_VARIABLE);
	checkTableInUse(stack,(yyvsp[-2].valor_lexico));
	int tipo = retorna_tipo_simbolo((yyvsp[-2].valor_lexico),stack);
	new_node = altera_tipo_no(new_node,tipo);
	(yyval.no) = inf_tipo((yyval.no),new_node,(yyvsp[0].no),AST_ATT);
	(yyval.no)->temp = strdup(gera_temp());
	LISTA_ILOCS* l = NULL;
	ILOC inst;
	char buf[2];
	sprintf(buf, "%d", retorna_end_desloc(stack,(yyvsp[-2].valor_lexico)));
	if(escopo_global(stack,(yyvsp[-2].valor_lexico)))
	   inst = gera_inst(ILOC_ATT,"storeAI",(yyvsp[0].no)->temp,"rbss",buf);
	else{
	   inst = gera_inst(ILOC_ATT,"storeAI",(yyvsp[0].no)->temp,"rfp",buf);
	}
	insere_lista_ilocs(&l,inst);
	l = concat_lista_ilocs(l,(yyvsp[0].no)->code);
	(yyval.no)->code = l;
	//print_code($$);
	}
#line 2457 "parser.tab.c"
    break;

  case 75:
#line 721 "parser.y"
                                                        {if(!(yyvsp[-2].no)) {(yyval.no) = (yyvsp[0].no);} else {add_child((yyvsp[-2].no),(yyvsp[0].no)); (yyval.no) = (yyvsp[-2].no);}}
#line 2463 "parser.tab.c"
    break;

  case 76:
#line 722 "parser.y"
                               {(yyval.no) = (yyvsp[-1].no);}
#line 2469 "parser.tab.c"
    break;

  case 77:
#line 723 "parser.y"
                                     {(yyval.no) = (yyvsp[-2].no); add_child((yyval.no),(yyvsp[0].no));}
#line 2475 "parser.tab.c"
    break;

  case 78:
#line 724 "parser.y"
                    {(yyval.no) = (yyvsp[-1].no);}
#line 2481 "parser.tab.c"
    break;

  case 79:
#line 725 "parser.y"
                                              {(yyval.no) = (yyvsp[-2].no); add_child((yyval.no),(yyvsp[0].no));}
#line 2487 "parser.tab.c"
    break;

  case 80:
#line 726 "parser.y"
                             {(yyval.no) = (yyvsp[-1].no);}
#line 2493 "parser.tab.c"
    break;

  case 81:
#line 727 "parser.y"
                                          {(yyval.no) = (yyvsp[-2].no); add_child((yyval.no),(yyvsp[0].no));}
#line 2499 "parser.tab.c"
    break;

  case 82:
#line 728 "parser.y"
                         {(yyval.no) = (yyvsp[-1].no);}
#line 2505 "parser.tab.c"
    break;

  case 83:
#line 729 "parser.y"
                                       {(yyval.no) = (yyvsp[-2].no); add_child((yyval.no),(yyvsp[0].no));}
#line 2511 "parser.tab.c"
    break;

  case 84:
#line 730 "parser.y"
                      {(yyval.no) = (yyvsp[-1].no);}
#line 2517 "parser.tab.c"
    break;

  case 85:
#line 731 "parser.y"
                                  {(yyval.no) = (yyvsp[-2].no); add_child((yyval.no),(yyvsp[0].no));}
#line 2523 "parser.tab.c"
    break;

  case 86:
#line 732 "parser.y"
                 {(yyval.no) = (yyvsp[-1].no);}
#line 2529 "parser.tab.c"
    break;

  case 87:
#line 733 "parser.y"
                                       {(yyval.no) = (yyvsp[-2].no); add_child((yyval.no),(yyvsp[0].no));}
#line 2535 "parser.tab.c"
    break;

  case 88:
#line 734 "parser.y"
                      {(yyval.no) = (yyvsp[-1].no);}
#line 2541 "parser.tab.c"
    break;

  case 89:
#line 735 "parser.y"
                                     {(yyval.no) = (yyvsp[-2].no); add_child((yyval.no),(yyvsp[0].no));}
#line 2547 "parser.tab.c"
    break;

  case 90:
#line 736 "parser.y"
                    {(yyval.no) = (yyvsp[-1].no);}
#line 2553 "parser.tab.c"
    break;

  case 91:
#line 737 "parser.y"
                                {
	(yyval.no) = create_node(AST_RET,"return");
	add_child((yyval.no),(yyvsp[0].no));
	(yyval.no)->temp = gera_temp();
	LISTA_ILOCS *l = NULL;
	ILOC inst;
	inst = gera_inst(ILOC_JUMP,"jump",NULL,NULL,(yyvsp[0].no)->temp);
	insere_lista_ilocs(&l,inst);
	l = concat_lista_ilocs(l,(yyvsp[0].no)->code);
	(yyval.no)->code = l;
	}
#line 2569 "parser.tab.c"
    break;

  case 92:
#line 748 "parser.y"
                                                                      {
	(yyval.no) = create_node(AST_IF,"if");
	add_child((yyval.no),(yyvsp[-5].no));
	add_child((yyval.no),(yyvsp[-2].no));
	add_child((yyval.no),(yyvsp[0].no));
	char *label_true = gera_rotulo();
	char *label_false = gera_rotulo();
	char *next = gera_rotulo();
	(yyval.no)->temp = gera_temp();
	char *opaco = gera_temp();
	LISTA_ILOCS *l = NULL;
	ILOC inst;
	inst = gera_inst(ILOC_LOADI, "loadI","0",NULL,(yyval.no)->temp);
	insere_lista_ilocs(&l,inst);
	inst = gera_inst(ILOC_DIF,"cmp_NE",(yyvsp[-5].no)->temp,(yyval.no)->temp,opaco);
	insere_lista_ilocs(&l,inst);
	inst = gera_inst(ILOC_BR,"cbr",opaco,label_true,label_false);
	insere_lista_ilocs(&l,inst);
	inst = gera_inst(ILOC_NOP,"nop",NULL,NULL,NULL);
	inst = gera_inst_com_label(label_true,inst);
	insere_lista_ilocs(&l,inst);
	l = concat_lista_ilocs(l,(yyvsp[-2].no)->code);
	inst = gera_inst(ILOC_JUMPI,"jumpI",NULL,NULL,next);
	insere_lista_ilocs(&l,inst);
	inst = gera_inst(ILOC_NOP,"nop",NULL,NULL,NULL);
	inst = gera_inst_com_label(label_false,inst);
	insere_lista_ilocs(&l,inst);
	l = concat_lista_ilocs(l,(yyvsp[0].no)->code);
	inst = gera_inst(ILOC_NOP,"nop",NULL,NULL,NULL);
	inst = gera_inst_com_label(next,inst);
	}
#line 2605 "parser.tab.c"
    break;

  case 93:
#line 779 "parser.y"
                                                {
	(yyval.no) = create_node(AST_IF,"if");
	add_child((yyval.no),(yyvsp[-3].no));
	add_child((yyval.no),(yyvsp[0].no));
	char *label_true = gera_rotulo();
	char *label_false = gera_rotulo();
	(yyval.no)->temp = gera_temp();
	char *opaco = gera_temp();
	LISTA_ILOCS *l = NULL;
	ILOC inst;
	inst = gera_inst(ILOC_LOADI, "loadI","0",NULL,(yyval.no)->temp);
	insere_lista_ilocs(&l,inst);
	inst = gera_inst(ILOC_DIF,"cmp_NE",(yyvsp[-3].no)->temp,(yyval.no)->temp,opaco);
	insere_lista_ilocs(&l,inst);
	inst = gera_inst(ILOC_BR,"cbr",opaco,label_true,label_false);
	insere_lista_ilocs(&l,inst);
	inst = gera_inst(ILOC_NOP,"nop",NULL,NULL,NULL);
	inst = gera_inst_com_label(label_true,inst);
	insere_lista_ilocs(&l,inst);
	l = concat_lista_ilocs(l,(yyvsp[0].no)->code);
	inst = gera_inst(ILOC_JUMPI,"jumpI",NULL,NULL,label_false);
	insere_lista_ilocs(&l,inst);
	inst = gera_inst(ILOC_NOP,"nop",NULL,NULL,NULL);
	inst = gera_inst_com_label(label_false,inst);
	}
#line 2635 "parser.tab.c"
    break;

  case 94:
#line 804 "parser.y"
                                           {
	(yyval.no) = create_node(AST_WHILE,"while");
	add_child((yyval.no),(yyvsp[-2].no));
	add_child((yyval.no),(yyvsp[0].no));
	char *label_true = gera_rotulo();
	char *label_false = gera_rotulo();
	(yyval.no)->temp = gera_temp();
	char *opaco = gera_temp();
    LISTA_ILOCS *l = NULL;
	ILOC inst;
	inst = gera_inst(ILOC_NOP,"nop",NULL,NULL,NULL);
	inst = gera_inst_com_label(label_true,inst);
	insere_lista_ilocs(&l,inst);
	inst = gera_inst(ILOC_LOADI, "loadI","0",NULL,(yyval.no)->temp);
	inst = gera_inst(ILOC_DIF,"cmp_NE",(yyvsp[-2].no)->temp,(yyval.no)->temp,opaco);
	insere_lista_ilocs(&l,inst);
	inst = gera_inst(ILOC_BR,"cbr",opaco,label_true,label_false);
	insere_lista_ilocs(&l,inst);
	l = concat_lista_ilocs(l,(yyvsp[0].no)->code);
	inst = gera_inst(ILOC_NOP,"nop",NULL,NULL,NULL);
	inst = gera_inst_com_label(label_false,inst);
	insere_lista_ilocs(&l,inst);
	(yyval.no)->code = l;
	}
#line 2664 "parser.tab.c"
    break;


#line 2668 "parser.tab.c"

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
#line 828 "parser.y"

void yyerror (char const *s){
	fprintf(stderr, "%s in line %d.\n",s,get_line_number());
}

void initMe(){
	stack = create_stack();
	HASH_TABLE *table = create_table(HASH_SIZE);
	push(stack,table); // tabela do escopo global

}
