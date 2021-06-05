#include <iostream>
#include <vector>
#include <llvm/IR/Value.h> 
#include <string>

using namespace std;
using namespace llvm;

class Node {
public:
    virtual ~Node() = default;
    virtual Value * codeGen() = 0;
    virtual void printNode(void) = 0;
};

class DeclarationNode : public Node {
public:
    enum {VarDeclNode, FunDeclNode} childType;
    unique_ptr<Node> declaration;

    DeclarationNode() {};
    DeclarationNode(unique_ptr<VarDeclarationNode> node):childType(VarDeclNode), declaration(move(node)) {};
    DeclarationNode(unique_ptr<FunDeclarationNode> node):childType(FunDeclNode), declaration(move(node)) {};
    
    Value * codeGen();
    void printNode(void);
};

class VarDeclarationNode : public Node {
public:
    unique_ptr<string> baseType;
    unique_ptr<vector<unique_ptr<IdListNode>>> idList;
    unique_ptr<vector<int>> arrayPost;
    unique_ptr<vector<unique_ptr<SingleNode>>> arrayConstList;

    VarDeclarationNode() {};
    VarDeclarationNode(
        unique_ptr<string> baseType, 
        unique_ptr<vector<unique_ptr<IdListNode>>> idList,
        unique_ptr<vector<int>> arrayPost,
        unique_ptr<vector<unique_ptr<SingleNode>>> arrayConstList
        ):baseType(move(baseType)), idList(move(idList)), arrayPost(move(arrayPost)), arrayConstList(move(arrayConstList)) {};

    Value * codeGen();
    void printNode(void);
};

class IdListNode : public Node {
public:
    unique_ptr<string> id;
    unique_ptr<ExpressionNode> initExp;

    IdListNode() {};
    IdListNode(
        unique_ptr<string> id,
        unique_ptr<ExpressionNode> initExp
    ):id(move(id)), initExp(move(initExp)) {}; 

    Value * codeGen();
    void printNode(void);
};

// class ArrayInitListNode : public Node {
// public:
//     ArrayInitListNode();
//     Value * codeGen();
// };

class FunDeclarationNode : public DeclarationNode {
public:
    unique_ptr<string> baseType;
    unique_ptr<string> id;
    unique_ptr<CompoundStmtNode> compoundStmt;
    bool isExtern;

    
    FunDeclarationNode() {};
    FunDeclarationNode(
        unique_ptr<string> baseType,
        unique_ptr<string> id,
        unique_ptr<CompoundStmtNode> compoundStmt,
        bool isExtern
    ):baseType(move(baseType)), id(move(id)), compoundStmt(move(compoundStmt)), isExtern(move(isExtern)) {};

    Value * codeGen();
    void printNode(void);
};

class ParamNode : public Node {
public:
    unique_ptr<string> baseType;
    unique_ptr<string> id;
    unique_ptr<vector<int>> arrayPostParam;


    ParamNode() {};
    ParamNode(
        unique_ptr<string> baseType,
        unique_ptr<string> id,
        unique_ptr<vector<int>> arrayPostParam
    ):baseType(move(baseType)), id(move(id)), arrayPostParam(move(arrayPostParam)) {};

    Value * codeGen();
    void printNode(void);
};

class CompoundStmtNode : public Node {
public:
    unique_ptr<vector<unique_ptr<VarDeclarationNode>>> localDeclarations;
    unique_ptr<vector<unique_ptr<StatementNode>>> statementList;

    CompoundStmtNode() {};
    CompoundStmtNode(
        unique_ptr<vector<unique_ptr<VarDeclarationNode>>> localDeclarations,
        unique_ptr<vector<unique_ptr<StatementNode>>> statementList
    ):localDeclarations(move(localDeclarations)), statementList(move(statementList)) {};
    
    Value * codeGen();
    void printNode(void);
};

class StatementNode : public Node {
public:
    enum {expNode, compNode, seleNode, iterNode, retNode} childType;
    unique_ptr<Node> statement;

    StatementNode() {};
    StatementNode(unique_ptr<ExpressionNode> statement):childType(expNode) ,statement(move(statement)) {};
    StatementNode(unique_ptr<CompoundStmtNode> statement):childType(compNode) ,statement(move(statement)) {};
    StatementNode(unique_ptr<SelectionStmtNode> statement):childType(seleNode) ,statement(move(statement)) {};
    StatementNode(unique_ptr<IterationStmtNode> statement):childType(iterNode) ,statement(move(statement)) {};
    StatementNode(unique_ptr<ReturnStmtNode> statement):childType(retNode) ,statement(move(statement)) {};
    
    Value * codeGen();
    void printNode(void);
};

class SelectionStmtNode : public Node {
public:
    unique_ptr<ExpressionNode> condition;
    unique_ptr<StatementNode> ifPart;
    unique_ptr<StatementNode> elsePart;

    SelectionStmtNode() {};
    SelectionStmtNode(
        unique_ptr<ExpressionNode> condition,
        unique_ptr<StatementNode> ifPart,
        unique_ptr<StatementNode> elsePart
    ):condition(move(condition)), ifPart(move(ifPart)), elsePart(move(elsePart)) {};

    Value * codeGen();
    void printNode(void);
};

class IterationStmtNode : public Node {
public:
    enum {whileNode, forNode} childType;
    unique_ptr<Node> iterationStmt;

    IterationStmtNode() {};
    IterationStmtNode(unique_ptr<WhileStmtNode> iterationStmt):childType(whileNode), iterationStmt(move(iterationStmt)) {};
    IterationStmtNode(unique_ptr<ForStmtNode> iterationStmt):childType(forNode), iterationStmt(move(iterationStmt)) {};

    Value * codeGen();
    void printNode(void);
};

class WhileStmtNode : public Node {
public:
    unique_ptr<ExpressionNode> condition;
    unique_ptr<StatementNode> statement;

    WhileStmtNode() {};
    WhileStmtNode(
        unique_ptr<ExpressionNode> condition,
        unique_ptr<StatementNode> statement
    ):condition(move(condition)), statement(move(statement)) {};

    Value * codeGen();
    void printNode(void);
};

class ForStmtNode : public Node {
public:
    unique_ptr<ExpressionNode> first;
    unique_ptr<ExpressionNode> second;
    unique_ptr<ExpressionNode> third;
    unique_ptr<StatementNode> statement;

    ForStmtNode() {};
    ForStmtNode(
        unique_ptr<ExpressionNode> first,
        unique_ptr<ExpressionNode> second,
        unique_ptr<ExpressionNode> third,
        unique_ptr<StatementNode> statement
    ):first(move(first)), second(move(second)), third(move(third)), statement(move(statement)) {};

    Value * codeGen();
    void printNode(void);
};

class ReturnStmtNode : public Node {
public:
    unique_ptr<ExpressionNode> returnExp;

    ReturnStmtNode() {};
    ReturnStmtNode(unique_ptr<ExpressionNode> returnExp):returnExp(move(returnExp)) {};
    
    Value * codeGen();
    void printNode(void);
};

class ExpressionNode : public Node {
public:
    unique_ptr<string> op;
    unique_ptr<VarNode> var;
    unique_ptr<ExpressionNode> expression;

    ExpressionNode() {};
    ExpressionNode(
        unique_ptr<string> op,
        unique_ptr<VarNode> var,
        unique_ptr<ExpressionNode> expression
    ):op(move(op)), var(move(var)), expression(move(expression)) {};

    Value * codeGen();
    void printNode(void);
};

class VarNode : public Node {
public:
    unique_ptr<string> id;
    unique_ptr<vector<int>> arrayPost;

    VarNode() {};
    VarNode(
        unique_ptr<string> id,
        unique_ptr<vector<int>> arrayPost
    ):id(move(id)), arrayPost(move(arrayPost)) {};

    Value * codeGen();
    void printNode(void);
};

class OperandNode : public Node {
public:
    unique_ptr<string> op;
    unique_ptr<OperandNode> lhs;
    unique_ptr<OperandNode> rhs;

    OperandNode() {};
    OperandNode(
        unique_ptr<string> op,
        unique_ptr<OperandNode> lhs,
        unique_ptr<OperandNode> rhs
    ):op(move(op)), lhs(move(lhs)), rhs(move(rhs)) {};

    Value * codeGen();
    void printNode(void);
};

class SingleNode : public Node {
public:
    enum {varNode, callNode, intNode, floatNode, charNode, boolNode} childType;
    unique_ptr<Node> signle;

    SingleNode() {};
    SingleNode(unique_ptr<VarNode>):childType(varNode), signle(move(signle)) {};
    SingleNode(unique_ptr<CallNode>):childType(callNode), signle(move(signle)) {};
    SingleNode(unique_ptr<IntNode>):childType(intNode), signle(move(signle)) {};
    SingleNode(unique_ptr<FloatNode>):childType(floatNode), signle(move(signle)) {};
    SingleNode(unique_ptr<CharNode>):childType(charNode), signle(move(signle)) {};
    SingleNode(unique_ptr<BoolNode>):childType(boolNode), signle(move(signle)) {};
    
    Value * codeGen();
    void printNode(void);
};

class CallNode : public Node {
public:
    unique_ptr<string> id;
    unique_ptr<vector<unique_ptr<ExpressionNode>>> args;

    CallNode() {};
    CallNode(
        unique_ptr<string> id,
        unique_ptr<vector<unique_ptr<ExpressionNode>>> args
    ):id(move(id)), args(move(args)) {};

    Value * codeGen();
    void printNode(void);
};

class IntNode : public Node {
public:
    int value;

    IntNode() {};
    IntNode(int value):value(value){};

    Value * codeGen();
    void printNode(void);
};

class FloatNode : public Node {
public:
    double value;

    FloatNode() {};
    FloatNode(double value):value(value){};

    Value * codeGen();
    void printNode(void);
};

class CharNode : public Node {
public:
    char value;

    CharNode() {};
    CharNode(char value):value(value){};

    Value * codeGen();
    void printNode(void);
};

class BoolNode : public Node {
public:
    bool value;

    BoolNode() {};
    BoolNode(bool value):value(value){};

    Value * codeGen();
    void printNode(void);
};