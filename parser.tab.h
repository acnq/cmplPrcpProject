/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    INT = 258,
    FLOAT = 259,
    DOUBLE = 260,
    TRUE = 261,
    FALSE = 262,
    CHAR = 263,
    ID = 264,
    IF = 265,
    ELSE = 266,
    WHILE = 267,
    RETURN = 268,
    FOR = 269,
    INT_TYPE = 270,
    VOID_TYPE = 271,
    DOUBLE_TYPE = 272,
    FLOAT_TYPE = 273,
    CHAR_TYPE = 274,
    BOOL_TYPE = 275,
    EXTERN_TYPE = 276,
    LP = 277,
    RP = 278,
    LC = 279,
    RC = 280,
    LB = 281,
    RB = 282,
    SEMICOLON = 283,
    COMMA = 284,
    ASSIGN = 285,
    PLUSASSIGN = 286,
    MINUSASSIGN = 287,
    MULTASSIGN = 288,
    DIVASSIGN = 289,
    MODASSIGN = 290,
    BORASSIGN = 291,
    BXORASSIGN = 292,
    BANDASSIGN = 293,
    SRASSIGN = 294,
    SLASSIGN = 295,
    LOR = 296,
    LAND = 297,
    BOR = 298,
    BAND = 299,
    BXOR = 300,
    SR = 301,
    SL = 302,
    PLUS = 303,
    MINUS = 304,
    MULT = 305,
    DIV = 306,
    MOD = 307,
    LNOT = 308,
    BNOT = 309,
    INCR = 310,
    DECR = 311,
    EQ = 312,
    NEQ = 313,
    LT = 314,
    GT = 315,
    LTE = 316,
    GTE = 317
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 24 "parser.y" /* yacc.c:1909  */

    /*treeNode member needed here*/
    /*...*/
    int type_int;
    float type_float;
    double type_double; // needed?
    bool type_bool;
    char type_char;
    char type_id[32];


#line 129 "parser.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
