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
#line 1 "parser.y"

/* Gessica Franciéle Mendonça Azevedo - 00302865 | Jéssica Maria Lorencetti - 00228342 | Mariana Koppe - 00219819 */
#include <stdio.h>
#include "arvore.h"
#include "tabela_simbolo.h"

int yylex(void);
int yyparse(void);
extern void yyerror (char const *mensagem);

extern void* arvore;

extern Lista_tabelas *lista_tabelas;
extern Tabela *tabela_global;
extern Tabela *tabela_escopo;


#line 89 "parser.tab.c"

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
  YYSYMBOL_TK_PR_INT = 3,                  /* TK_PR_INT  */
  YYSYMBOL_TK_PR_FLOAT = 4,                /* TK_PR_FLOAT  */
  YYSYMBOL_TK_PR_BOOL = 5,                 /* TK_PR_BOOL  */
  YYSYMBOL_TK_PR_IF = 6,                   /* TK_PR_IF  */
  YYSYMBOL_TK_PR_ELSE = 7,                 /* TK_PR_ELSE  */
  YYSYMBOL_TK_PR_WHILE = 8,                /* TK_PR_WHILE  */
  YYSYMBOL_TK_PR_RETURN = 9,               /* TK_PR_RETURN  */
  YYSYMBOL_TK_OC_LE = 10,                  /* TK_OC_LE  */
  YYSYMBOL_TK_OC_GE = 11,                  /* TK_OC_GE  */
  YYSYMBOL_TK_OC_EQ = 12,                  /* TK_OC_EQ  */
  YYSYMBOL_TK_OC_NE = 13,                  /* TK_OC_NE  */
  YYSYMBOL_TK_OC_AND = 14,                 /* TK_OC_AND  */
  YYSYMBOL_TK_OC_OR = 15,                  /* TK_OC_OR  */
  YYSYMBOL_TK_IDENTIFICADOR = 16,          /* TK_IDENTIFICADOR  */
  YYSYMBOL_TK_LIT_INT = 17,                /* TK_LIT_INT  */
  YYSYMBOL_TK_LIT_FLOAT = 18,              /* TK_LIT_FLOAT  */
  YYSYMBOL_TK_LIT_FALSE = 19,              /* TK_LIT_FALSE  */
  YYSYMBOL_TK_LIT_TRUE = 20,               /* TK_LIT_TRUE  */
  YYSYMBOL_TK_ERRO = 21,                   /* TK_ERRO  */
  YYSYMBOL_22_ = 22,                       /* '-'  */
  YYSYMBOL_23_ = 23,                       /* '+'  */
  YYSYMBOL_24_ = 24,                       /* '*'  */
  YYSYMBOL_25_ = 25,                       /* '/'  */
  YYSYMBOL_26_ = 26,                       /* '%'  */
  YYSYMBOL_27_ = 27,                       /* '<'  */
  YYSYMBOL_28_ = 28,                       /* '>'  */
  YYSYMBOL_29_ = 29,                       /* '|'  */
  YYSYMBOL_30_ = 30,                       /* '~'  */
  YYSYMBOL_31_ = 31,                       /* '='  */
  YYSYMBOL_32_ = 32,                       /* '!'  */
  YYSYMBOL_33_ = 33,                       /* '('  */
  YYSYMBOL_34_ = 34,                       /* ','  */
  YYSYMBOL_35_ = 35,                       /* ';'  */
  YYSYMBOL_36_ = 36,                       /* ')'  */
  YYSYMBOL_37_ = 37,                       /* '{'  */
  YYSYMBOL_38_ = 38,                       /* '}'  */
  YYSYMBOL_YYACCEPT = 39,                  /* $accept  */
  YYSYMBOL_raiz = 40,                      /* raiz  */
  YYSYMBOL_41_1 = 41,                      /* $@1  */
  YYSYMBOL_programa = 42,                  /* programa  */
  YYSYMBOL_program_list = 43,              /* program_list  */
  YYSYMBOL_element = 44,                   /* element  */
  YYSYMBOL_ident_decl = 45,                /* ident_decl  */
  YYSYMBOL_decl_global = 46,               /* decl_global  */
  YYSYMBOL_id_list_gl = 47,                /* id_list_gl  */
  YYSYMBOL_type = 48,                      /* type  */
  YYSYMBOL_func = 49,                      /* func  */
  YYSYMBOL_header = 50,                    /* header  */
  YYSYMBOL_ident_func = 51,                /* ident_func  */
  YYSYMBOL_params_list_void = 52,          /* params_list_void  */
  YYSYMBOL_params_list = 53,               /* params_list  */
  YYSYMBOL_param = 54,                     /* param  */
  YYSYMBOL_ident_param = 55,               /* ident_param  */
  YYSYMBOL_body = 56,                      /* body  */
  YYSYMBOL_command_block = 57,             /* command_block  */
  YYSYMBOL_command_list = 58,              /* command_list  */
  YYSYMBOL_push_tabela_escopo = 59,        /* push_tabela_escopo  */
  YYSYMBOL_simple_command = 60,            /* simple_command  */
  YYSYMBOL_decl_local = 61,                /* decl_local  */
  YYSYMBOL_id_list_lc = 62,                /* id_list_lc  */
  YYSYMBOL_atr = 63,                       /* atr  */
  YYSYMBOL_fcall = 64,                     /* fcall  */
  YYSYMBOL_args_list = 65,                 /* args_list  */
  YYSYMBOL_return = 66,                    /* return  */
  YYSYMBOL_cflow = 67,                     /* cflow  */
  YYSYMBOL_else_command = 68,              /* else_command  */
  YYSYMBOL_expr = 69,                      /* expr  */
  YYSYMBOL_expr8 = 70,                     /* expr8  */
  YYSYMBOL_expr7 = 71,                     /* expr7  */
  YYSYMBOL_expr6 = 72,                     /* expr6  */
  YYSYMBOL_expr5 = 73,                     /* expr5  */
  YYSYMBOL_expr4 = 74,                     /* expr4  */
  YYSYMBOL_expr3 = 75,                     /* expr3  */
  YYSYMBOL_expr2 = 76,                     /* expr2  */
  YYSYMBOL_expr1 = 77,                     /* expr1  */
  YYSYMBOL_expr0 = 78,                     /* expr0  */
  YYSYMBOL_operand = 79,                   /* operand  */
  YYSYMBOL_literal = 80                    /* literal  */
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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   115

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  39
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  42
/* YYNRULES -- Number of rules.  */
#define YYNRULES  83
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  132

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   276


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
       2,     2,     2,    32,     2,     2,     2,    26,     2,     2,
      33,    36,    24,    23,    34,    22,     2,    25,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    35,
      27,    31,    28,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    37,    29,    38,    30,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   110,   110,   110,   112,   113,   116,   127,   130,   132,
     134,   138,   142,   143,   146,   147,   148,   152,   158,   160,
     173,   174,   176,   177,   179,   181,   185,   188,   189,   191,
     201,   204,   207,   208,   209,   210,   211,   212,   216,   218,
     219,   223,   229,   234,   236,   239,   245,   250,   255,   256,
     260,   261,   263,   267,   269,   273,   275,   279,   283,   285,
     289,   293,   297,   301,   303,   307,   311,   313,   317,   321,
     325,   327,   330,   333,   335,   336,   338,   341,   342,   343,
     345,   346,   347,   348
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
  "\"end of file\"", "error", "\"invalid token\"", "TK_PR_INT",
  "TK_PR_FLOAT", "TK_PR_BOOL", "TK_PR_IF", "TK_PR_ELSE", "TK_PR_WHILE",
  "TK_PR_RETURN", "TK_OC_LE", "TK_OC_GE", "TK_OC_EQ", "TK_OC_NE",
  "TK_OC_AND", "TK_OC_OR", "TK_IDENTIFICADOR", "TK_LIT_INT",
  "TK_LIT_FLOAT", "TK_LIT_FALSE", "TK_LIT_TRUE", "TK_ERRO", "'-'", "'+'",
  "'*'", "'/'", "'%'", "'<'", "'>'", "'|'", "'~'", "'='", "'!'", "'('",
  "','", "';'", "')'", "'{'", "'}'", "$accept", "raiz", "$@1", "programa",
  "program_list", "element", "ident_decl", "decl_global", "id_list_gl",
  "type", "func", "header", "ident_func", "params_list_void",
  "params_list", "param", "ident_param", "body", "command_block",
  "command_list", "push_tabela_escopo", "simple_command", "decl_local",
  "id_list_lc", "atr", "fcall", "args_list", "return", "cflow",
  "else_command", "expr", "expr8", "expr7", "expr6", "expr5", "expr4",
  "expr3", "expr2", "expr1", "expr0", "operand", "literal", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-54)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -54,     3,     4,   -54,   -54,   -54,   -54,   -54,   -54,   -54,
       4,   -54,     6,   -54,    -8,    11,   -54,   -54,   -54,   -23,
      -3,   -54,   -54,    32,    29,   -54,    17,   -54,     6,   -54,
      22,   -54,   -54,    54,    11,   -54,    43,    44,    38,    16,
       6,   -54,    36,    45,   -54,   -54,   -54,   -54,   -54,    11,
     -54,    38,    38,    47,   -54,   -54,   -54,   -54,    38,    38,
      38,   -54,   -54,    63,    67,    49,    23,    41,    -6,   -54,
     -54,   -54,   -54,   -54,    38,    38,   -54,    48,   -54,    22,
      57,    50,    51,   -54,   -54,    52,    38,    38,    38,    38,
      38,    38,    38,    38,    38,    38,    38,    38,    38,   -54,
      53,    55,     6,   -54,    68,    -8,    -8,   -54,    67,    49,
      23,    23,    41,    41,    41,    41,    -6,    -6,   -54,   -54,
     -54,   -54,    38,   -54,   -54,   -54,    78,   -54,   -54,    -8,
     -54,   -54
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     5,     1,    14,    15,    16,    31,     3,     4,
       7,     8,     0,     9,     0,    21,     6,    10,    13,     0,
      31,    17,    26,     0,     0,    20,    23,    11,     0,    27,
       0,    25,    24,     0,     0,    12,     0,     0,    51,     0,
       0,    32,     0,     0,    33,    34,    35,    36,    37,     0,
      22,    51,    51,    77,    80,    81,    82,    83,     0,     0,
      51,    79,    45,    50,    53,    55,    58,    63,    66,    70,
      73,    75,    76,    78,    51,    51,    40,    38,    28,    30,
       0,     0,     0,    71,    72,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    41,
       0,    44,     0,    29,     0,     0,     0,    74,    52,    54,
      56,    57,    61,    62,    59,    60,    65,    64,    67,    68,
      69,    42,    51,    39,    19,    18,    49,    47,    43,     0,
      46,    48
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -54,   -54,   -54,   -54,    83,   -54,   -27,   -54,   -54,   -13,
     -54,   -54,   -54,   -54,    60,   -54,   -54,   -54,   -14,    18,
      75,   -54,   -54,   -54,   -54,   -26,   -24,   -54,   -54,   -54,
     -28,   -54,    10,    12,   -21,   -51,   -22,   -53,   -54,   -54,
     -54,   -54
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,     8,     9,    10,    18,    11,    19,    12,
      13,    14,   125,    24,    25,    26,    32,    21,    41,    42,
      15,    43,    44,    77,    45,    61,   100,    47,    48,   130,
     101,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      22,    35,    23,     3,    46,    83,    84,     4,     5,     6,
      62,    27,    28,    76,     4,     5,     6,    40,    96,    97,
      98,    23,    17,    81,    82,     4,     5,     6,    36,    20,
      37,    38,    85,    90,    91,    29,    80,     7,    39,   112,
     113,   114,   115,   118,   119,   120,    99,    74,    31,    75,
      92,    93,    34,    46,    53,    54,    55,    56,    57,    20,
      58,    88,    89,    94,    95,    33,    40,   110,   111,    49,
      59,    60,   116,   117,    78,   123,    51,    52,    86,    79,
      75,    87,   104,   102,   124,   129,   105,   106,   107,   121,
     122,   126,   127,    16,    50,    30,   108,   103,   128,   109,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   131
};

static const yytype_int16 yycheck[] =
{
      14,    28,    15,     0,    30,    58,    59,     3,     4,     5,
      38,    34,    35,    40,     3,     4,     5,    30,    24,    25,
      26,    34,    16,    51,    52,     3,     4,     5,     6,    37,
       8,     9,    60,    10,    11,    38,    49,    33,    16,    90,
      91,    92,    93,    96,    97,    98,    74,    31,    16,    33,
      27,    28,    35,    79,    16,    17,    18,    19,    20,    37,
      22,    12,    13,    22,    23,    36,    79,    88,    89,    15,
      32,    33,    94,    95,    38,   102,    33,    33,    15,    34,
      33,    14,    25,    35,    16,     7,    36,    36,    36,    36,
      35,   105,   106,    10,    34,    20,    86,    79,   122,    87,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   129
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    40,    41,     0,     3,     4,     5,    33,    42,    43,
      44,    46,    48,    49,    50,    59,    43,    16,    45,    47,
      37,    56,    57,    48,    52,    53,    54,    34,    35,    38,
      59,    16,    55,    36,    35,    45,     6,     8,     9,    16,
      48,    57,    58,    60,    61,    63,    64,    66,    67,    15,
      53,    33,    33,    16,    17,    18,    19,    20,    22,    32,
      33,    64,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    31,    33,    45,    62,    38,    34,
      48,    69,    69,    76,    76,    69,    15,    14,    12,    13,
      10,    11,    27,    28,    22,    23,    24,    25,    26,    69,
      65,    69,    35,    58,    25,    36,    36,    36,    71,    72,
      73,    73,    74,    74,    74,    74,    75,    75,    76,    76,
      76,    36,    35,    45,    16,    51,    57,    57,    65,     7,
      68,    57
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    39,    41,    40,    42,    42,    43,    43,    44,    44,
      45,    46,    47,    47,    48,    48,    48,    49,    50,    51,
      52,    52,    53,    53,    54,    55,    56,    57,    57,    58,
      58,    59,    60,    60,    60,    60,    60,    60,    61,    62,
      62,    63,    64,    65,    65,    66,    67,    67,    68,    68,
      69,    69,    70,    70,    71,    71,    72,    72,    72,    73,
      73,    73,    73,    73,    74,    74,    74,    75,    75,    75,
      75,    76,    76,    76,    77,    77,    78,    79,    79,    79,
      80,    80,    80,    80
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     1,     0,     2,     1,     1,     1,
       1,     3,     3,     1,     1,     1,     1,     2,     8,     1,
       1,     0,     3,     1,     2,     1,     1,     2,     4,     3,
       2,     0,     1,     1,     1,     1,     1,     1,     2,     3,
       1,     3,     4,     3,     1,     2,     6,     5,     2,     0,
       1,     0,     3,     1,     3,     1,     3,     3,     1,     3,
       3,     3,     3,     1,     3,     3,     1,     3,     3,     3,
       1,     2,     2,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1
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
  case 2: /* $@1: %empty  */
#line 110 "parser.y"
      {pushTabela(&lista_tabelas, tabela_global);}
#line 1519 "parser.tab.c"
    break;

  case 4: /* programa: program_list  */
#line 112 "parser.y"
                         {(yyval.nodo) = (yyvsp[0].nodo); arvore = (yyval.nodo); popTabela(&lista_tabelas);}
#line 1525 "parser.tab.c"
    break;

  case 5: /* programa: %empty  */
#line 113 "parser.y"
                         {(yyval.nodo) = NULL; arvore = NULL; }
#line 1531 "parser.tab.c"
    break;

  case 6: /* program_list: element program_list  */
#line 116 "parser.y"
                                   { if((yyvsp[-1].nodo) == NULL) 
                                    {(yyval.nodo) = (yyvsp[0].nodo);}
                                     else
                                        { 
                                        if((yyvsp[0].nodo) == NULL) {(yyval.nodo) = (yyvsp[-1].nodo);}                   
                                            else { 
                                                {(yyval.nodo) = (yyvsp[-1].nodo); addFilho((yyval.nodo),(yyvsp[0].nodo));}
                                                 }
                                        
                                        }
}
#line 1547 "parser.tab.c"
    break;

  case 7: /* program_list: element  */
#line 127 "parser.y"
                    {(yyval.nodo)=(yyvsp[0].nodo);}
#line 1553 "parser.tab.c"
    break;

  case 8: /* element: decl_global  */
#line 130 "parser.y"
                      {(yyval.nodo) = NULL;}
#line 1559 "parser.tab.c"
    break;

  case 9: /* element: func  */
#line 132 "parser.y"
               {(yyval.nodo) = (yyvsp[0].nodo);}
#line 1565 "parser.tab.c"
    break;

  case 10: /* ident_decl: TK_IDENTIFICADOR  */
#line 134 "parser.y"
                              {(yyval.nodo) = createNodo((yyvsp[0].valor_lexico)); printf("Criou nó\n");}
#line 1571 "parser.tab.c"
    break;

  case 11: /* decl_global: type id_list_gl ','  */
#line 138 "parser.y"
                                             {(yyval.nodo) = NULL;}
#line 1577 "parser.tab.c"
    break;

  case 12: /* id_list_gl: id_list_gl ';' ident_decl  */
#line 142 "parser.y"
                                         {(yyval.nodo) = (yyvsp[-2].nodo);}
#line 1583 "parser.tab.c"
    break;

  case 13: /* id_list_gl: ident_decl  */
#line 143 "parser.y"
                                   {(yyval.nodo) = (yyvsp[0].nodo);}
#line 1589 "parser.tab.c"
    break;

  case 14: /* type: TK_PR_INT  */
#line 146 "parser.y"
                   {(yyval.nodo) = NULL;}
#line 1595 "parser.tab.c"
    break;

  case 15: /* type: TK_PR_FLOAT  */
#line 147 "parser.y"
                   {(yyval.nodo) = NULL;}
#line 1601 "parser.tab.c"
    break;

  case 16: /* type: TK_PR_BOOL  */
#line 148 "parser.y"
                   {(yyval.nodo) = NULL;}
#line 1607 "parser.tab.c"
    break;

  case 17: /* func: header body  */
#line 152 "parser.y"
                  {(yyval.nodo) = (yyvsp[0].nodo);
                    if((yyvsp[0].nodo) != NULL)
                         addFilho((yyval.nodo),(yyvsp[0].nodo));
                   }
#line 1616 "parser.tab.c"
    break;

  case 18: /* header: '(' push_tabela_escopo params_list_void ')' TK_OC_OR type '/' ident_func  */
#line 158 "parser.y"
                                                                                   {(yyval.nodo) = (yyvsp[0].nodo);}
#line 1622 "parser.tab.c"
    break;

  case 19: /* ident_func: TK_IDENTIFICADOR  */
#line 161 "parser.y"
     {
          (yyvsp[0].valor_lexico)->tipo = INT; /*Por convenção, todas as var são int */
          (yyvsp[0].valor_lexico)->natureza = FUNCTION;
          (yyval.nodo) = createNodo((yyvsp[0].valor_lexico));

          verificaERR_DECLARED(lista_tabelas,(yyvsp[0].valor_lexico));
	     insereEntradaTabela(&(lista_tabelas->tabela_simbolos), (yyvsp[0].valor_lexico));
          
     }
#line 1636 "parser.tab.c"
    break;

  case 20: /* params_list_void: params_list  */
#line 173 "parser.y"
                              {(yyval.nodo) = NULL;}
#line 1642 "parser.tab.c"
    break;

  case 21: /* params_list_void: %empty  */
#line 174 "parser.y"
       {(yyval.nodo)=NULL;}
#line 1648 "parser.tab.c"
    break;

  case 22: /* params_list: param ';' params_list  */
#line 176 "parser.y"
                                   {(yyval.nodo)=NULL;}
#line 1654 "parser.tab.c"
    break;

  case 23: /* params_list: param  */
#line 177 "parser.y"
            {(yyval.nodo)=NULL;}
#line 1660 "parser.tab.c"
    break;

  case 24: /* param: type ident_param  */
#line 179 "parser.y"
                        {(yyval.nodo)=NULL;}
#line 1666 "parser.tab.c"
    break;

  case 25: /* ident_param: TK_IDENTIFICADOR  */
#line 181 "parser.y"
                              {(yyval.nodo)=NULL;}
#line 1672 "parser.tab.c"
    break;

  case 26: /* body: command_block  */
#line 185 "parser.y"
                                                  {(yyval.nodo) = (yyvsp[0].nodo);}
#line 1678 "parser.tab.c"
    break;

  case 27: /* command_block: '{' '}'  */
#line 188 "parser.y"
                                              {(yyval.nodo) = NULL;}
#line 1684 "parser.tab.c"
    break;

  case 28: /* command_block: '{' push_tabela_escopo command_list '}'  */
#line 189 "parser.y"
                                                         {(yyval.nodo) = (yyvsp[-1].nodo);}
#line 1690 "parser.tab.c"
    break;

  case 29: /* command_list: simple_command ',' command_list  */
#line 191 "parser.y"
                                              {if((yyvsp[-2].nodo) == NULL) 
                                    {(yyval.nodo) = (yyvsp[0].nodo);}
                                     else
                                        { 
                                        if((yyvsp[0].nodo) == NULL) {(yyval.nodo) = (yyvsp[-2].nodo);}                   
                                            else { 
                                                {(yyval.nodo) = (yyvsp[-2].nodo); addFilho((yyval.nodo),(yyvsp[0].nodo));}
                                                 }
                                        
                                        }    }
#line 1705 "parser.tab.c"
    break;

  case 30: /* command_list: simple_command ','  */
#line 201 "parser.y"
                                                  {(yyval.nodo) = (yyvsp[-1].nodo);}
#line 1711 "parser.tab.c"
    break;

  case 31: /* push_tabela_escopo: %empty  */
#line 204 "parser.y"
                         {pushTabela(&lista_tabelas, tabela_escopo);}
#line 1717 "parser.tab.c"
    break;

  case 32: /* simple_command: command_block  */
#line 207 "parser.y"
                                   {(yyval.nodo) = (yyvsp[0].nodo);}
#line 1723 "parser.tab.c"
    break;

  case 33: /* simple_command: decl_local  */
#line 208 "parser.y"
                                   {(yyval.nodo) = (yyvsp[0].nodo);}
#line 1729 "parser.tab.c"
    break;

  case 34: /* simple_command: atr  */
#line 209 "parser.y"
                                   {(yyval.nodo) = (yyvsp[0].nodo);}
#line 1735 "parser.tab.c"
    break;

  case 35: /* simple_command: fcall  */
#line 210 "parser.y"
                                   {(yyval.nodo) = (yyvsp[0].nodo);}
#line 1741 "parser.tab.c"
    break;

  case 36: /* simple_command: return  */
#line 211 "parser.y"
                                   {(yyval.nodo) = (yyvsp[0].nodo);}
#line 1747 "parser.tab.c"
    break;

  case 37: /* simple_command: cflow  */
#line 212 "parser.y"
                                   {(yyval.nodo) = (yyvsp[0].nodo);}
#line 1753 "parser.tab.c"
    break;

  case 38: /* decl_local: type id_list_lc  */
#line 216 "parser.y"
                                            {(yyval.nodo) = NULL;}
#line 1759 "parser.tab.c"
    break;

  case 39: /* id_list_lc: id_list_lc ';' ident_decl  */
#line 218 "parser.y"
                                         {(yyval.nodo) = (yyvsp[-2].nodo);}
#line 1765 "parser.tab.c"
    break;

  case 40: /* id_list_lc: ident_decl  */
#line 219 "parser.y"
                                   {(yyval.nodo) = (yyvsp[0].nodo);}
#line 1771 "parser.tab.c"
    break;

  case 41: /* atr: TK_IDENTIFICADOR '=' expr  */
#line 223 "parser.y"
                                   {(yyval.nodo) = createNodo((yyvsp[-1].valor_lexico));
                                    addFilho((yyval.nodo), createNodo((yyvsp[-2].valor_lexico)));
                                    addFilho((yyval.nodo), (yyvsp[0].nodo));
                                   }
#line 1780 "parser.tab.c"
    break;

  case 42: /* fcall: TK_IDENTIFICADOR '(' args_list ')'  */
#line 229 "parser.y"
                                            {(yyval.nodo) = createFcallNodo((yyvsp[-3].valor_lexico));
                                            addFilho((yyval.nodo),(yyvsp[-1].nodo));
                                             }
#line 1788 "parser.tab.c"
    break;

  case 43: /* args_list: expr ';' args_list  */
#line 234 "parser.y"
                                             {(yyval.nodo) = (yyvsp[-2].nodo);
                                             addFilho((yyval.nodo), (yyvsp[0].nodo));}
#line 1795 "parser.tab.c"
    break;

  case 44: /* args_list: expr  */
#line 236 "parser.y"
                                             {(yyval.nodo) = (yyvsp[0].nodo);}
#line 1801 "parser.tab.c"
    break;

  case 45: /* return: TK_PR_RETURN expr  */
#line 239 "parser.y"
                            {(yyval.nodo) = createNodo((yyvsp[-1].valor_lexico));
                                 addFilho((yyval.nodo),(yyvsp[0].nodo));
                                }
#line 1809 "parser.tab.c"
    break;

  case 46: /* cflow: TK_PR_IF '(' expr ')' command_block else_command  */
#line 245 "parser.y"
                                                          {(yyval.nodo) = createNodo((yyvsp[-5].valor_lexico));
                                                             addFilho((yyval.nodo),(yyvsp[-3].nodo));
                                                             addFilho((yyval.nodo),(yyvsp[-1].nodo));
                                                             addFilho((yyval.nodo),(yyvsp[0].nodo));
                                                            }
#line 1819 "parser.tab.c"
    break;

  case 47: /* cflow: TK_PR_WHILE '(' expr ')' command_block  */
#line 250 "parser.y"
                                                          {(yyval.nodo) = createNodo((yyvsp[-4].valor_lexico));
                                                             addFilho((yyval.nodo),(yyvsp[-2].nodo));
                                                             addFilho((yyval.nodo),(yyvsp[0].nodo));
                                                            }
#line 1828 "parser.tab.c"
    break;

  case 48: /* else_command: TK_PR_ELSE command_block  */
#line 255 "parser.y"
                                                            {(yyval.nodo) = (yyvsp[0].nodo);}
#line 1834 "parser.tab.c"
    break;

  case 49: /* else_command: %empty  */
#line 256 "parser.y"
                                                            {(yyval.nodo) = NULL;}
#line 1840 "parser.tab.c"
    break;

  case 50: /* expr: expr8  */
#line 260 "parser.y"
                              {(yyval.nodo) = (yyvsp[0].nodo);}
#line 1846 "parser.tab.c"
    break;

  case 51: /* expr: %empty  */
#line 261 "parser.y"
                              {(yyval.nodo) = NULL;}
#line 1852 "parser.tab.c"
    break;

  case 52: /* expr8: expr8 TK_OC_OR expr7  */
#line 263 "parser.y"
                              {(yyval.nodo) = createNodo((yyvsp[-1].valor_lexico));
                               addFilho((yyval.nodo), (yyvsp[-2].nodo));
                               addFilho((yyval.nodo), (yyvsp[0].nodo));
                              }
#line 1861 "parser.tab.c"
    break;

  case 53: /* expr8: expr7  */
#line 267 "parser.y"
                              {(yyval.nodo) = (yyvsp[0].nodo);}
#line 1867 "parser.tab.c"
    break;

  case 54: /* expr7: expr7 TK_OC_AND expr6  */
#line 269 "parser.y"
                              {(yyval.nodo) = createNodo((yyvsp[-1].valor_lexico));
                               addFilho((yyval.nodo), (yyvsp[-2].nodo));
                               addFilho((yyval.nodo), (yyvsp[0].nodo));
                              }
#line 1876 "parser.tab.c"
    break;

  case 55: /* expr7: expr6  */
#line 273 "parser.y"
                              {(yyval.nodo) = (yyvsp[0].nodo);}
#line 1882 "parser.tab.c"
    break;

  case 56: /* expr6: expr6 TK_OC_EQ expr5  */
#line 275 "parser.y"
                              {(yyval.nodo) = createNodo((yyvsp[-1].valor_lexico));
                               addFilho((yyval.nodo), (yyvsp[-2].nodo));
                               addFilho((yyval.nodo), (yyvsp[0].nodo));
                              }
#line 1891 "parser.tab.c"
    break;

  case 57: /* expr6: expr6 TK_OC_NE expr5  */
#line 279 "parser.y"
                              {(yyval.nodo) = createNodo((yyvsp[-1].valor_lexico));
                               addFilho((yyval.nodo), (yyvsp[-2].nodo));
                               addFilho((yyval.nodo), (yyvsp[0].nodo));
                              }
#line 1900 "parser.tab.c"
    break;

  case 58: /* expr6: expr5  */
#line 283 "parser.y"
                              {(yyval.nodo) = (yyvsp[0].nodo);}
#line 1906 "parser.tab.c"
    break;

  case 59: /* expr5: expr5 '<' expr4  */
#line 285 "parser.y"
                              {(yyval.nodo) = createNodo((yyvsp[-1].valor_lexico));
                               addFilho((yyval.nodo), (yyvsp[-2].nodo));
                               addFilho((yyval.nodo), (yyvsp[0].nodo));
                              }
#line 1915 "parser.tab.c"
    break;

  case 60: /* expr5: expr5 '>' expr4  */
#line 289 "parser.y"
                              {(yyval.nodo) = createNodo((yyvsp[-1].valor_lexico));
                               addFilho((yyval.nodo), (yyvsp[-2].nodo));
                               addFilho((yyval.nodo), (yyvsp[0].nodo));
                              }
#line 1924 "parser.tab.c"
    break;

  case 61: /* expr5: expr5 TK_OC_LE expr4  */
#line 293 "parser.y"
                              {(yyval.nodo) = createNodo((yyvsp[-1].valor_lexico));
                               addFilho((yyval.nodo), (yyvsp[-2].nodo));
                               addFilho((yyval.nodo), (yyvsp[0].nodo));
                              }
#line 1933 "parser.tab.c"
    break;

  case 62: /* expr5: expr5 TK_OC_GE expr4  */
#line 297 "parser.y"
                              {(yyval.nodo) = createNodo((yyvsp[-1].valor_lexico));
                               addFilho((yyval.nodo), (yyvsp[-2].nodo));
                               addFilho((yyval.nodo), (yyvsp[0].nodo));
                              }
#line 1942 "parser.tab.c"
    break;

  case 63: /* expr5: expr4  */
#line 301 "parser.y"
                              {(yyval.nodo) = (yyvsp[0].nodo);}
#line 1948 "parser.tab.c"
    break;

  case 64: /* expr4: expr4 '+' expr3  */
#line 303 "parser.y"
                              {(yyval.nodo) = createNodo((yyvsp[-1].valor_lexico));                           
                               addFilho((yyval.nodo), (yyvsp[-2].nodo));
                               addFilho((yyval.nodo), (yyvsp[0].nodo));
                              }
#line 1957 "parser.tab.c"
    break;

  case 65: /* expr4: expr4 '-' expr3  */
#line 307 "parser.y"
                              {(yyval.nodo) = createNodo((yyvsp[-1].valor_lexico));
                               addFilho((yyval.nodo), (yyvsp[-2].nodo));
                               addFilho((yyval.nodo), (yyvsp[0].nodo));
                              }
#line 1966 "parser.tab.c"
    break;

  case 66: /* expr4: expr3  */
#line 311 "parser.y"
                              {(yyval.nodo) = (yyvsp[0].nodo);}
#line 1972 "parser.tab.c"
    break;

  case 67: /* expr3: expr3 '*' expr2  */
#line 313 "parser.y"
                              {(yyval.nodo) = createNodo((yyvsp[-1].valor_lexico));
                               addFilho((yyval.nodo), (yyvsp[-2].nodo));
                               addFilho((yyval.nodo), (yyvsp[0].nodo));                            
                              }
#line 1981 "parser.tab.c"
    break;

  case 68: /* expr3: expr3 '/' expr2  */
#line 317 "parser.y"
                              {(yyval.nodo) = createNodo((yyvsp[-1].valor_lexico));
                               addFilho((yyval.nodo), (yyvsp[-2].nodo));
                               addFilho((yyval.nodo), (yyvsp[0].nodo));
                              }
#line 1990 "parser.tab.c"
    break;

  case 69: /* expr3: expr3 '%' expr2  */
#line 321 "parser.y"
                              {(yyval.nodo) = createNodo((yyvsp[-1].valor_lexico));
                               addFilho((yyval.nodo), (yyvsp[-2].nodo));
                               addFilho((yyval.nodo), (yyvsp[0].nodo));
                              }
#line 1999 "parser.tab.c"
    break;

  case 70: /* expr3: expr2  */
#line 325 "parser.y"
                              {(yyval.nodo) = (yyvsp[0].nodo);}
#line 2005 "parser.tab.c"
    break;

  case 71: /* expr2: '-' expr2  */
#line 327 "parser.y"
                              {(yyval.nodo) = createNodo((yyvsp[-1].valor_lexico));
                               addFilho((yyval.nodo), (yyvsp[0].nodo));
                              }
#line 2013 "parser.tab.c"
    break;

  case 72: /* expr2: '!' expr2  */
#line 330 "parser.y"
                              {(yyval.nodo) = createNodo((yyvsp[-1].valor_lexico));
                               addFilho((yyval.nodo), (yyvsp[0].nodo));
                              }
#line 2021 "parser.tab.c"
    break;

  case 73: /* expr2: expr1  */
#line 333 "parser.y"
                              {(yyval.nodo) = (yyvsp[0].nodo);}
#line 2027 "parser.tab.c"
    break;

  case 74: /* expr1: '(' expr ')'  */
#line 335 "parser.y"
                              {(yyval.nodo) = (yyvsp[-1].nodo);}
#line 2033 "parser.tab.c"
    break;

  case 75: /* expr1: expr0  */
#line 336 "parser.y"
                              {(yyval.nodo) = (yyvsp[0].nodo);}
#line 2039 "parser.tab.c"
    break;

  case 76: /* expr0: operand  */
#line 338 "parser.y"
                              {(yyval.nodo) = (yyvsp[0].nodo);}
#line 2045 "parser.tab.c"
    break;

  case 77: /* operand: TK_IDENTIFICADOR  */
#line 341 "parser.y"
                              {(yyval.nodo) = createNodo((yyvsp[0].valor_lexico));}
#line 2051 "parser.tab.c"
    break;

  case 78: /* operand: literal  */
#line 342 "parser.y"
                              {(yyval.nodo) = (yyvsp[0].nodo);}
#line 2057 "parser.tab.c"
    break;

  case 79: /* operand: fcall  */
#line 343 "parser.y"
                              {(yyval.nodo) = (yyvsp[0].nodo);}
#line 2063 "parser.tab.c"
    break;

  case 80: /* literal: TK_LIT_INT  */
#line 345 "parser.y"
                              {(yyval.nodo) = createNodo((yyvsp[0].valor_lexico));}
#line 2069 "parser.tab.c"
    break;

  case 81: /* literal: TK_LIT_FLOAT  */
#line 346 "parser.y"
                              {(yyval.nodo) = createNodo((yyvsp[0].valor_lexico));}
#line 2075 "parser.tab.c"
    break;

  case 82: /* literal: TK_LIT_FALSE  */
#line 347 "parser.y"
                              {(yyval.nodo) = createNodo((yyvsp[0].valor_lexico));}
#line 2081 "parser.tab.c"
    break;

  case 83: /* literal: TK_LIT_TRUE  */
#line 348 "parser.y"
                              {(yyval.nodo) = createNodo((yyvsp[0].valor_lexico));}
#line 2087 "parser.tab.c"
    break;


#line 2091 "parser.tab.c"

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

#line 350 "parser.y"

