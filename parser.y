%{
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <ctype.h>
#include <math.h>
#include <string>
#include <cstdio>
#include <iostream>
#include "ASTNodes.hpp"

using namespace std;

extern int yylineno;
extern char* yytext;
extern FILE* yyin;

extern int yylex(void);

void yyerror(std::string s);
void display(struct node*, int);/*用于实现画出AST*/
int typeCheck(char* type);/*类型检查*/

%}

%union{
    /*treeNode member needed here*/
    /*...*/
    int type_int;
    float type_float;
    double type_double; // needed?
    bool type_bool;
    char type_char;
    char type_id[32];

};
/* %type <ptr> term factor */

%token <type_int> INT   //指定INT的语义值是type_int，有词法分析得到的数值
%token <type_float> FLOAT
%token <type_double> DOUBLE //needed?
%token <type_bool> TRUE  FALSE 
%token <type_char> CHAR 

%token <type_id> ID

%token IF ELSE WHILE RETURN FOR //keywords
%token INT_TYPE VOID_TYPE DOUBLE_TYPE FLOAT_TYPE CHAR_TYPE BOOL_TYPE EXTERN_TYPE//type words

%token LP RP LC RC LB RB SEMICOLON COMMA //assoc chara
%token ASSIGN PLUSASSIGN MINUSASSIGN MULTASSIGN DIVASSIGN MODASSIGN BORASSIGN BXORASSIGN BANDASSIGN SRASSIGN SLASSIGN //assign op
%token LOR LAND BOR BAND BXOR SR SL PLUS MINUS MULT DIV MOD LNOT BNOT INCR DECR //op
%token EQ NEQ LT GT LTE GTE //relop

%right ASSIGN PLUSASSIGN MINUSASSIGN MULTASSIGN DIVASSIGN MODASSIGN BORASSIGN BXORASSIGN BANDASSIGN SRASSIGN SLASSIGN
%left LOR
%left LAND
%left BOR
%left BXOR
%left BAND
%left EQ NEQ
%left LT GT LTE GTE
%left SL SR
%left PLUS MINUS
%left MULT DIV MOD
%right LNOT BNOT

%nonassoc ELSE

%start program


%%

program:            declarationList {/* do sth with $1 */}
                    ;

declarationList:    declarationList declaration  {
                        $1.push_back($2);
                        $$ = $1;
                    }
                    | declaration   {
                        $$ = vector<unique_ptr<declarationNode>>();
                        $$.push_back($1);
                    }
                    ;

declaration:        varDeclaration   {
                        $$ = move(make_unique<declarationNode>($1));
                    }
                    | funDeclaration  {
                        $$ = move(make_unique<declarationNode>($1));
                    }
                    ;

varDeclaration:     baseType ID SEMICOLON {}
                    | baseType arrayPost ID SEMICOLON {}
                    | baseType ID ASSIGN expression SEMICOLON {}
	                | baseType ID arrayPost ASSIGN LC arrayInitList RC SEMICOLON {}
                    ;
                
arrayPost:          LB INT RB  {}
                    | arrayPost LB INT RB {}
                    ;

arrayInitList:      arrayInitList COMMA arrayInit {}
                    | arrayInit {}
                    ;

arrayInit:          LC arrayInitList RC {}
                    | INT {}
                    ;

baseType:           INT_TYPE { $$ =  }
                    | DOUBLE_TYPE {}
                    | FLOAT_TYPE {}
                    | CHAR_TYPE {}
                    | BOOL_TYPE {}
                    ;

funDeclaration:     baseType ID LP params RP compoundStmt {}
                    | VOID_TYPE ID LP params RP compoundStmt {}
                    | EXTERN_TYPE baseType ID LP params RP SEMICOLON {}
                    | EXTERN_TYPE VOID_TYPE ID LP params RP SEMICOLON {}
                    ;

params:             paramList {}
                    | VOID_TYPE { $$ = nullptr; }
                    ;

paramList:          paramList COMMA param {}
                    |  param {}
                    ;

param:              baseType ID {}
                    | baseType ID LB RB  {}
                    ;

compoundStmt:       LC localDeclarations statementList  RC {};

localDeclarations:  %empty {}
                    | localDeclarations varDeclaration {}
                    ;

statementList:      %empty {}
                    | statementList statement {}
                    ;

statement:          expressionStmt {}
                    | compoundStmt {}
                    | selectionStmt {}
                    | iterationStmt {}
                    | returnStmt {}
                    ;

expressionStmt:     expression SEMICOLON { $$ = make_unique<expressionNode>(move($1)); }
                    | SEMICOLON { $$ = nullptr; }
                    ;

selectionStmt:      IF LP expression RP statement { $$ = make_unique<selectionStmtNode>(move($3), move($5), nullptr); }
                    | IF LP expression RP statement ELSE statement { $$ = make_unique<selectionStmtNode>(move($3), move($5), move($7)); }
                    ;

iterationStmt:      whileStmt { $$ = make_unique<iterationStmtNode>(move($1)); }
                    | forStmt { $$ = make_unique<iterationStmtNode>(move($1)); }
                    ;

whileStmt:          WHILE LP expression RP statement {
                        $$ = make_unique<whileStmtNode>(move($3), move($5));
                    }
                    ;

forStmt:            FOR LP expression SEMICOLON expression SEMICOLON expression RP statement {
                        $$ = make_unique<forStmtNode>(move($3), move($5), move($7), move($9));
                    }
                    ;
 
returnStmt:         RETURN SEMICOLON { $$ = nullptr; }
                    | RETURN expression SEMICOLON { $$ = make_unique<returnStmtNode>(move($2)); }
                    ;

expression:         var assop expression { $$ = make_unique<expressionNode>(move($2), move($1), move($3)); }
                    | operand { $$ = make_unique<expressionNode>(nullptr, nullptr, move($3)); }
                    ;

assop:              ASSIGN { $$ = make_unique<string>($1); }
                    | PLUSASSIGN { $$ = make_unique<string>($1); } 
                    | MINUSASSIGN { $$ = make_unique<string>($1); } 
                    | MULTASSIGN { $$ = make_unique<string>($1); } 
                    | DIVASSIGN { $$ = make_unique<string>($1); } 
                    | MODASSIGN { $$ = make_unique<string>($1); } 
                    | BANDASSIGN { $$ = make_unique<string>($1); } 
                    | BORASSIGN { $$ = make_unique<string>($1); } 
                    | BXORASSIGN { $$ = make_unique<string>($1); } 
                    | SLASSIGN { $$ = make_unique<string>($1); } 
                    | SRASSIGN { $$ = make_unique<string>($1); } 
                    ;

var:                ID { $$ = make_unique<varNode>(make_unique<string>($1), nullptr); }
                    | ID LB expression RB { $$ = make_unique<varNode>(make_unique<string>($1), move($3)); }
                    ;

operand:            operand LOR operand { $$ = make_unique<operandNode>(make_unique<string>($2), move($1), move($3)); }
                    | operand LAND operand { $$ = make_unique<operandNode>(make_unique<string>($2), move($1), move($3)); }
                    | operand BOR operand { $$ = make_unique<operandNode>(make_unique<string>($2), move($1), move($3)); }
                    | operand BXOR operand { $$ = make_unique<operandNode>(make_unique<string>($2), move($1), move($3)); }
                    | operand BAND operand { $$ = make_unique<operandNode>(make_unique<string>($2), move($1), move($3)); }
                    | operand EQ operand { $$ = make_unique<operandNode>(make_unique<string>($2), move($1), move($3)); }
                    | operand NEQ operand { $$ = make_unique<operandNode>(make_unique<string>($2), move($1), move($3)); }
                    | operand LT operand { $$ = make_unique<operandNode>(make_unique<string>($2), move($1), move($3)); }
                    | operand GT operand { $$ = make_unique<operandNode>(make_unique<string>($2), move($1), move($3)); }
                    | operand LTE operand { $$ = make_unique<operandNode>(make_unique<string>($2), move($1), move($3)); }
                    | operand GTE operand { $$ = make_unique<operandNode>(make_unique<string>($2), move($1), move($3)); }
                    | operand SL operand { $$ = make_unique<operandNode>(make_unique<string>($2), move($1), move($3)); }
                    | operand SR operand { $$ = make_unique<operandNode>(make_unique<string>($2), move($1), move($3)); }
                    | operand PLUS operand { $$ = make_unique<operandNode>(make_unique<string>($2), move($1), move($3)); }
                    | operand MINUS operand { $$ = make_unique<operandNode>(make_unique<string>($2), move($1), move($3)); }
                    | operand MULT operand { $$ = make_unique<operandNode>(make_unique<string>($2), move($1), move($3)); }
                    | operand DIV operand { $$ = make_unique<operandNode>(make_unique<string>($2), move($1), move($3)); }
                    | operand MOD operand { $$ = make_unique<operandNode>(make_unique<string>($2), move($1), move($3)); }
                    | prefix LP operand RP { $$ = make_unique<operandNode>(move($1), move($3), nullptr); }
                    | prefix single {  $$ = make_unique<operandNode>(move($1), move($2), nullptr); }
                    ;
                    

prefix:             %empty { $$ = nullptr; }
                    | BNOT { $$ = make_unique<string>($1); }
                    | LNOT  { $$ = make_unique<string>($1); }
                    | MINUS { $$ = make_unique<string>($1); }
                    ;

single:             ID { $$ = make_unique<singleNode>( make_unique<string>($1) ); }
                    | call { $$ = make_unique<singleNode>($1); }
                    | INT { $$ = make_unique<singleNode>($1); }
                    | FLOAT { $$ = make_unique<singleNode>($1); }
                    | CHAR { $$ = make_unique<singleNode>($1); }
                    | TRUE { $$ = make_unique<singleNode>($1); }
                    | FALSE { $$ = make_unique<singleNode>($1); }
                    // overload multiple initialization fun, with different type (enum)
                    ;

call:               ID LP args RP {
                        $$ = make_unique<callNode>(make_unique<string>($1), move($3)));
                    };

args:               %empty { $$ = nullptr; }
                    | argList { $$ = move($1); } 
                    ;

argList:            argList COMMA expression {
                        $1->push_back(move($3));
                        $$ = move($1);
                    }
                    | expression {
                        $$ = make_unique<vector<unique_ptr<argListNode>>>();
                        $$->push_back(move($1));
                    }
                    ;    

%%

int main() { 
    return yyparse();
}

void yyerror(std::string s) {
    fprintf(stderr, "%s\n", s.c_str());
    return ;
}

/*maybe use the following？：*/
int TypeCheck(char* type)
{
    if (!strcmp(type,"int"))
	{
		return INT;
	}
	if (!strcmp(type,"float"))
	{
		return FLOAT;
	}
	if (!strcmp(type,"char"))
	{
		return CHAR;
	}
}

// #include<stdarg.h>
// void yyerror(const char* fmt, ...)
// {
//     va_list ap;
//     va_start(ap, fmt);
//     fprintf(stderr, "Grammar Error at Line %d Column %d: ", yylloc.first_line,yylloc.first_column);
//     vfprintf(stderr, fmt, ap);
//     fprintf(stderr, ".\n");
// }
