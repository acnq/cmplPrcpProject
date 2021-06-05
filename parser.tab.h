/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

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
    TRUE = 260,
    FALSE = 261,
    CHAR = 262,
    ID = 263,
    IF = 264,
    ELSE = 265,
    WHILE = 266,
    RETURN = 267,
    FOR = 268,
    INT_TYPE = 269,
    VOID_TYPE = 270,
    DOUBLE_TYPE = 271,
    FLOAT_TYPE = 272,
    CHAR_TYPE = 273,
    BOOL_TYPE = 274,
    EXTERN_TYPE = 275,
    LP = 276,
    RP = 277,
    LC = 278,
    RC = 279,
    LB = 280,
    RB = 281,
    SEMICOLON = 282,
    COMMA = 283,
    ASSIGN = 284,
    PLUSASSIGN = 285,
    MINUSASSIGN = 286,
    MULTASSIGN = 287,
    DIVASSIGN = 288,
    MODASSIGN = 289,
    BORASSIGN = 290,
    BXORASSIGN = 291,
    BANDASSIGN = 292,
    SRASSIGN = 293,
    SLASSIGN = 294,
    LOR = 295,
    LAND = 296,
    BOR = 297,
    BAND = 298,
    BXOR = 299,
    SR = 300,
    SL = 301,
    PLUS = 302,
    MINUS = 303,
    MULT = 304,
    DIV = 305,
    MOD = 306,
    LNOT = 307,
    BNOT = 308,
    INCR = 309,
    DECR = 310,
    EQ = 311,
    NEQ = 312,
    LT = 313,
    GT = 314,
    LTE = 315,
    GTE = 316
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 28 "parser.y"

    DeclarationNode      *declarationNode;
    VarDeclarationNode   *varDeclarationNode;
    FunDeclarationNode   *funDeclarationNode;
    ParamNode            *paramNode;
    CompoundStmtNode     *compoundStmtNode;
    StatementNode        *statementNode;
    SelectionStmtNode    *selectionStmtNode;
    IterationStmtNode    *iterationStmtNode;
    WhileStmtNode        *whileStmtNode;
    ForStmtNode          *forStmtNode;
    ReturnStmtNode       *returnStmtNode;
    ExpressionNode       *expressionNode;
    VarNode              *varNode;
    OperandNode          *operandNode;
    SingleNode           *singleNode;
    CallNode             *callNode;
    
    vector<int>* intVec;
    string*  stringNode;

    vector<DeclarationNode*>    *declarationNodeVec;
    vector<IdListNode*>         *idListNodeVec;
    vector<SingleNode*>         *singleNodeVec;
    vector<ParamNode*>          *paramVec;
    vector<VarDeclarationNode*> *varDeclarationNodeVec;
    vector<StatementNode*>      *statementNodeVec;
    vector<ExpressionNode*>     *expressionNodeVec;

    int type_int;
    float type_float;
    double type_double; // needed?
    bool type_bool;
    char type_char;
    char type_id[32];


#line 157 "parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
