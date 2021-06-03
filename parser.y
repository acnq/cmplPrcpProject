%{
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <string>
#include <cstdio>
#include <iostream>
#include "ASTNodes.h"

extern int yylineno;
extern char* yytext;
extern FILE* yyin;

extern int yylex(void);

void yyerror(const char* s);
void display(struct node*, int);/*用于实现画出AST*/
int typeCheck(char* type);/*类型检查*/

%}

%union{
    /*treeNode member needed here*/
    ...
    int type_int;
    float type_float;
    double type_double; // needed?
    bool type_bool;
    char type_char;
    char type_id[32];

};
%type <ptr> exp term factor ifactor item

%token <type_int> INT   //指定INT的语义值是type_int，有词法分析得到的数值
%token <type_float> FLOAT
%token <type_double> DOUBLE //needed?
%token <type_bool> TRUE  FALSE 
%token <type_char> CHAR 

%token <type_id> ID

%token IF ELSE WHILE RETURN FOR EXTERN//keywords
%token INT_TYPE VOID_TYPE DOUBLE_TYPE FLOAT_TYPE CHAR_TYPE BOOL_TYPE //type words

%token LP RP LC RC LB RB SEMICOLON COMMA //assoc chara
%token ASSIGN PLUSASSIGN MINUSASSIGN MULTASSIGN DIVASSIGN MODASSIGN BORASSIGN BXORASSIGN BANDASSIGN SRASSIGN SLASSIGN //assign op
%token LOR LAND BOR BAND BXOR SR SL PLUS MINUS MULT DIV MOD LNOT BNOT INCR DECR //op
%token EQ NEQ LT GT LTE GTE //relop
%

%left ASSIGN PLUSASSIGN MINUSASSIGN MULTASSIGN DIVASSIGN MODASSIGN BORASSIGN BXORASSIGN BANDASSIGN SRASSIGN SLASSIGN
%left EQ NEQ LT GT LTE GTE
%right LNOT BNOT MINUS

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

varDeclaration:     typeSpecifier  ID SEMICOLON {}
                    | baseSpecifier ID ASSIGN expression SEMICOLON {}
                    ;
                
typeSpecifier:      baseType {}
                    | arrayType {}
                    ;

arrayType:          baseType LB INT RB  {}
                    | arrayType LB INT RB {}
                    | arrayType LB INT RB ASSIGN LC arrayInitList RC {}
                    ;
arrayInitList:      arrayInitList COMMA arrayInit {}
                    | arrayInit {}
                    ;

arrayInit:          LB arrayInitList RB {}
                    | INT {}
                    ;

baseType:           INT_TYPE {}
                    | VOID_TYPE {}
                    | DOUBLE_TYPE {}
                    | FLOAT_TYPE {}
                    | CHAR_TYPE {}
                    | BOOL_TYPE {}
                    ;

funDeclaration:     typeSpecifier ID LP params RP compoundStmt {}
                    | EXTERN typeSpecifier ID LP params RP {}
                    ;

params:             paramList {}
                    | VOID_TYPE {}
                    ;

paramList:          paramList COMMA param {}
                    |  param {}
                    ;

param:              typeSpecifier ID {}
                    | typeSpecifier ID LB RB  {}
                    ;

compoundStmt:       LC localDeclarations statementList  RC {};

localDeclarations:  /*empty*/{}
                    | localDeclarations var-declaration {}
                    ;

statementList:      /*emtpy*/ {}
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

whileStmt:          WHILE LP expression RP statement; {}

forStmt:            FOR LP expression SEMICOLON expression SEMICOLON expression RP statement; {}
 
returnStmt:         RETURN SEMICOLON {}
                    | RETURN    expression SEMICOLON {}
                    ;

expression:         var assop expression {}
                    | simpleExpression {}
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
                    | ID [expression] {}
                    ;

simpleExpression:   simpleExpression logop logicExpression {}
                    | logicExpression {}
                    ;

logop:              LOR {} 
                    | LAND {};

logicExpression:     logicExpression bitop bitExpression {}
                    | bitExpression {}
                    ;

bitop:              BOR|BAND|BXOR;

bitExpression:      bitExpression relop shiftExpression {}
                    | shiftExpression {}
                    ;

relop:              EQ|NEQ|LT|GT|LTE|GTE;

shiftExpression:    shiftExpression shiop additiveExpression {}
                    | additiveExpression {}
                    ;

shiop:              SL|SR;

additiveExpression: additiveExpression addop term {}
                    | term {}
                    ;

addop:              PLUS|MINUS;

term:               term mulop factor {}
                    | factor {}
                    ;

mulop:              MULT | DIV | MOD;

factor:             LNOT factor {}
                    | BNOT factor {}
                    | MINUS factor {}
                    | incre {}
                    ;

incre:              incre INCR {} 
                    | incre DECR {} 
                    | terminal {}
                    ;

terminal:           LP expression RP {} 
                    | var {}
                    | call {}
                    | INT | FLOAT | CHAR | TURE | FALSE
                    ;

call:               ID LP args RP{};

args:               /*empty*/{}
                    | argList {} 
                    ;

argList:            argList COMMA expression {}
                    | expression {}
                    ;    

%%

int main() { 
    return yyparse();
}

int yyerror(char *s) {
    fprintf(stderr, "%s\n", s);
    return 0;
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

#include<stdarg.h>
void yyerror(const char* fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    fprintf(stderr, "Grammar Error at Line %d Column %d: ", yylloc.first_line,yylloc.first_column);
    vfprintf(stderr, fmt, ap);
    fprintf(stderr, ".\n");
}