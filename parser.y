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

program:            declarationList {}
                    ;

declarationList:    declarationList declaration  {}
                    | declaration   {}
                    ;

declaration:        varDeclaration   {}
                    | funDeclaration  {}
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

baseType:           INT_TYPE {}
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
                    | VOID_TYPE {}
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

expressionStmt:     expression SEMICOLON {}
                    | SEMICOLON {}
                    ;

selectionStmt:      IF  LP  expression RP statement {}
                    | IF LP expression RP statement ELSE statement {}
                    ;

iterationStmt:      whileStmt {}
                    | forStmt  {}
                    ;

whileStmt:          WHILE LP expression RP statement {}
                    ;

forStmt:            FOR LP expression SEMICOLON expression SEMICOLON expression RP statement {}
                    ;
 
returnStmt:         RETURN SEMICOLON {}
                    | RETURN expression SEMICOLON {}
                    ;

expression:         var assop expression {}
                    | operand {}
                    ;

assop:              ASSIGN {}
                    | PLUSASSIGN {} 
                    | MINUSASSIGN {} 
                    | MULTASSIGN {} 
                    | DIVASSIGN {} 
                    | MODASSIGN {} 
                    | BANDASSIGN {}     
                    | BORASSIGN {} 
                    | BXORASSIGN {}
                    | SLASSIGN {}
                    | SRASSIGN {}
                    ;

var:                ID {}
                    | ID LB expression RB {}
                    ;

operand:            operand LOR operand {}
                    | operand LAND operand {}
                    | operand BOR operand {}
                    | operand BXOR operand {}
                    | operand BAND operand {}
                    | operand EQ operand {}
                    | operand NEQ operand {}
                    | operand LT operand {}
                    | operand GT operand {}
                    | operand LTE operand {}
                    | operand GTE operand {}
                    | operand SL operand {}
                    | operand SR operand {}
                    | operand PLUS operand {}
                    | operand MINUS operand {}
                    | operand MULT operand {}
                    | operand DIV operand {}
                    | operand MOD operand {}
                    | prefix LP operand RP {}
                    | prefix single
                    ;
                    

prefix:             %empty | BNOT | LNOT | MINUS
                    ;

single:             ID {}
                    | call {}
                    | INT | FLOAT | CHAR | TRUE | FALSE
                    ;

call:               ID LP args RP {};

args:               %empty {}
                    | argList {} 
                    ;

argList:            argList COMMA expression {}
                    | expression {}
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
