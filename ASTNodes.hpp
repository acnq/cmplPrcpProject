#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <utility>

#include "llvm/IR/BasicBlock.h"
#include "llvm/IR/Constants.h"
#include "llvm/IR/DerivedTypes.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/Instructions.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/LegacyPassManager.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Type.h"
#include "llvm/IR/Value.h" 
#include "llvm/IR/Verifier.h"
#include "llvm/Transforms/InstCombine/InstCombine.h"
#include "llvm/Transforms/Scalar.h"
#include "llvm/Transforms/Scalar/GVN.h"
#include "llvm/Transforms/Utils.h"
#include "llvm/Support/FileSystem.h"
#include "llvm/Support/Host.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Support/TargetRegistry.h"
#include "llvm/Support/TargetSelect.h"
#include "llvm/Target/TargetMachine.h"
#include "llvm/Target/TargetOptions.h"

using namespace std;
using namespace llvm;

class Node;
class DeclarationNode;
class VarDeclarationNode;
class IdListNode;
class FunDeclarationNode;
class ParamNode;
class CompoundStmtNode;
class FunctionBodyNode;
class StatementNode;
class SelectionStmtNode;
class IterationStmtNode;
class WhileStmtNode;
class ForStmtNode;
class ReturnStmtNode;
class ExpressionNode;
class VarNode;
class OperandNode;
class SingleNode;
class CallNode;
class IntNode;
class FloatNode;
class CharNode;
class BoolNode;

class Node {
public:
    ~Node() = default;
    Value * codeGen();
    void printNode(int layer);
};

class DeclarationNode : public Node {
public:
    VarDeclarationNode *varDecl= nullptr;
    FunDeclarationNode *funDecl = nullptr;

    DeclarationNode() {};
    DeclarationNode(VarDeclarationNode *node):varDecl(node) {};
    DeclarationNode(FunDeclarationNode *node):funDecl(node) {};
    
    Value * codeGen();
    void printNode(int layer);
};

class VarDeclarationNode : public Node {
public:
    string *baseType;
    vector<IdListNode*> *idList;
    vector<int> *arrayPost;
    vector<SingleNode*> *arrayConstList;

    VarDeclarationNode() {};
    VarDeclarationNode(
        string *baseType,
        vector<IdListNode*> *idList,
        vector<int> *arrayPost,
        vector<SingleNode*> *arrayConstList
    ):baseType(baseType), idList(idList), arrayPost(arrayPost), arrayConstList(arrayConstList) {};

    Value * codeGen(bool global);
    void printNode(int layer);
};

class IdListNode : public Node {
public:
    string *id;
    ExpressionNode *initExp;

    IdListNode() {};
    IdListNode(
        string *id,
        ExpressionNode *initExp
    ):id(id), initExp(initExp) {}; 

    Value * codeGen();
    void printNode(int layer);
};

class FunDeclarationNode : public Node {
public:
    string *baseType;
    string *id;
    vector<ParamNode*> *params;
    FunctionBodyNode *functionBody;
    bool isExtern;

    FunDeclarationNode() {};
    FunDeclarationNode(
        string *baseType,
        string *id,
        vector<ParamNode*> *params,
        FunctionBodyNode *functionBody,
        bool isExtern
    ):baseType(baseType), id(id), params(params), functionBody(functionBody), isExtern(isExtern) {};

    Value * codeGen();
    void printNode(int layer);
};

class ParamNode : public Node {
public:
    string *baseType;
    string *id;
    vector<int> *arrayPost;

    ParamNode() {};
    ParamNode(
        string *baseType,
        string *id,
        vector<int> *arrayPost
    ):baseType(baseType), id(id), arrayPost(arrayPost) {};

    Value * codeGen();
    void printNode(int layer);
};

class FunctionBodyNode : public Node {
public:
    vector<VarDeclarationNode*> *localDeclarations;
    vector<StatementNode*> *statementList;

    FunctionBodyNode() {};
    FunctionBodyNode(
        vector<VarDeclarationNode*> *localDeclarations,
        vector<StatementNode*> *statementList
    ):localDeclarations(localDeclarations), statementList(statementList) {};
    
    Value * codeGen(BasicBlock * afterBlock);
    void printNode(int layer);
};

class CompoundStmtNode : public Node {
public:
    vector<VarDeclarationNode*> *localDeclarations;
    vector<StatementNode*> *statementList;

    CompoundStmtNode() {};
    CompoundStmtNode(
        vector<VarDeclarationNode*> *localDeclarations,
        vector<StatementNode*> *statementList
    ):localDeclarations(localDeclarations), statementList(statementList) {};
    
    Value * codeGen();
    void printNode(int layer);
};

class StatementNode : public Node {
public:
    ExpressionNode *expNode = nullptr;
    CompoundStmtNode *compNode = nullptr;
    SelectionStmtNode *selNode = nullptr;
    IterationStmtNode *iterNode = nullptr;
    ReturnStmtNode *retNode = nullptr;

    StatementNode() {};
    StatementNode(ExpressionNode *statement):expNode(statement) {};
    StatementNode(CompoundStmtNode *statement):compNode(statement) {};
    StatementNode(SelectionStmtNode *statement):selNode(statement) {};
    StatementNode(IterationStmtNode *statement):iterNode(statement) {};
    StatementNode(ReturnStmtNode *statement):retNode(statement) {};
    
    Value * codeGen();
    void printNode(int layer);
};

class SelectionStmtNode : public Node {
public:
    ExpressionNode *condition;
    StatementNode *ifPart;
    StatementNode *elsePart;

    SelectionStmtNode() {};
    SelectionStmtNode(
        ExpressionNode *condition,
        StatementNode *ifPart,
        StatementNode *elsePart
    ):condition(condition), ifPart(ifPart), elsePart(elsePart) {};

    Value * codeGen();
    void printNode(int layer);
};

class IterationStmtNode : public Node {
public:
    WhileStmtNode *whileNode = nullptr;
    ForStmtNode *forNode = nullptr;

    IterationStmtNode() {};
    IterationStmtNode(WhileStmtNode *iterationStmt):whileNode(iterationStmt) {};
    IterationStmtNode(ForStmtNode *iterationStmt):forNode(iterationStmt) {};

    Value * codeGen();
    void printNode(int layer);
};

class WhileStmtNode : public Node {
public:
    ExpressionNode *condition;
    StatementNode *statement;

    WhileStmtNode() {};
    WhileStmtNode(
        ExpressionNode *condition,
        StatementNode *statement
    ):condition(condition), statement(statement) {};

    Value * codeGen();
    void printNode(int layer);
};

class ForStmtNode : public Node {
public:
    ExpressionNode *first;
    ExpressionNode *second;
    ExpressionNode *third;
    StatementNode *statement;

    ForStmtNode() {};
    ForStmtNode(
        ExpressionNode *first,
        ExpressionNode *second,
        ExpressionNode *third,
        StatementNode *statement
    ):first(first), second(second), third(third), statement(statement) {};

    Value * codeGen();
    void printNode(int layer);
};

class ReturnStmtNode : public Node {
public:
    ExpressionNode *returnExp;

    ReturnStmtNode() {};
    ReturnStmtNode(ExpressionNode *returnExp):returnExp(returnExp) {};

    Value * codeGen();
    void printNode(int layer);
};

class ExpressionNode : public Node {
public:
    string *op;
    VarNode *var;
    ExpressionNode *expression;
    OperandNode * operand;

    ExpressionNode() {};
    ExpressionNode(
        string *op,
        VarNode *var,
        ExpressionNode *expression,
        OperandNode * operand
    ):op(op), var(var), expression(expression), operand(operand) {};

    Value * codeGen();
    void printNode(int layer);
};

class VarNode : public Node {
public:
    string *id;
    vector<int> *arrayPost;

    VarNode() {};
    VarNode(
        string *id,
        vector<int> *arrayPost
    ):id(id), arrayPost(arrayPost) {};

    Value * codeGen();
    void printNode(int layer);
};

class OperandNode : public Node {
public:
    string *op;
    OperandNode *lhs;
    OperandNode *rhs;
    SingleNode *single;

    OperandNode() {};
    OperandNode(
        string *op,
        OperandNode *lhs,
        OperandNode *rhs,
        SingleNode *single
    ):op(op), lhs(lhs), rhs(rhs), single(single) {};

    Value * codeGen();
    void printNode(int layer);
};

class SingleNode : public Node {
public:
    VarNode *varNode = nullptr;
    CallNode *callNode = nullptr;
    IntNode *intNode = nullptr;
    FloatNode *floatNode = nullptr;
    CharNode *charNode = nullptr;
    BoolNode *boolNode = nullptr;

    SingleNode() {};
    SingleNode(VarNode * single):varNode(single) {};
    SingleNode(CallNode *single):callNode(single) {};
    SingleNode(IntNode *single):intNode(single) {};
    SingleNode(FloatNode *single):floatNode(single) {};
    SingleNode(CharNode *single):charNode(single) {};
    SingleNode(BoolNode *single):boolNode(single) {};
    
    Value * codeGen();
    void printNode(int layer);
};

class CallNode : public Node {
public:
    string *id;
    vector<ExpressionNode*> *args;

    CallNode() {};
    CallNode(
        string *id,
        vector<ExpressionNode*> *args
    ):id(id), args(args) {};

    Value * codeGen();
    void printNode(int layer);
};

class IntNode : public Node {
public:
    int value;

    IntNode() {};
    IntNode(int value):value(value){};

    Value * codeGen();
    void printNode(int layer);
};

class FloatNode : public Node {
public:
    double value;

    FloatNode() {};
    FloatNode(double value):value(value){};

    Value * codeGen();
    void printNode(int layer);
};

class CharNode : public Node {
public:
    char value;

    CharNode() {};
    CharNode(char value):value(value){};

    Value * codeGen();
    void printNode(int layer);
};

class BoolNode : public Node {
public:
    bool value;

    BoolNode() {};
    BoolNode(bool value):value(value){};

    Value * codeGen();
    void printNode(int layer);
};