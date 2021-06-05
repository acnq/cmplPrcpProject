#include <iostream>
#include <vector>
#include <llvm/IR/Value.h> 
#include <string>

using namespace std;
using namespace llvm;

class Node {
public:
    virtual ~Node() = default;
    virtual llvm::Value * codeGen() = 0;

};

class DeclarationNode : public Node {
public:
    DeclarationNode();
    Value * codeGen();
};

class VarDeclarationNode : public Node {
public:
    VarDeclarationNode();
    Value * codeGen();
};

class IdListNode : public Node {
public:
    IdListNode();
    Value * codeGen();
};

// class ArrayInitListNode : public Node {
// public:
//     ArrayInitListNode();
//     Value * codeGen();
// };

class FunDeclarationNode : public Node {
public:
    FunDeclarationNode();
    Value * codeGen();
};

class ParamNode : public Node {
public:
    ParamNode();
    Value * codeGen();
};

class CompoundStmtNode : public Node {
public:
    CompoundStmtNode();
    Value * codeGen();
};

class StatementNode : public Node {
public:
    StatementNode();
    Value * codeGen();
};

class SelectionStmtNode : public Node {
public:
    SelectionStmtNode();
    Value * codeGen();
};

class IterationStmtNode : public Node {
public:
    IterationStmtNode();
    Value * codeGen();
};

class WhileStmtNode : public Node {
public:
    WhileStmtNode();
    Value * codeGen();
};

class ForStmtNode : public Node {
public:
    ForStmtNode();
    Value * codeGen();
};

class ReturnStmtNode : public Node {
public:
    ReturnStmtNode();
    Value * codeGen();
};

class ExpressionNode : public Node {
public:
    ExpressionNode();
    Value * codeGen();
};

class VarNode : public Node {
public:
    VarNode();
    Value * codeGen();
};

class OperandNode : public Node {
public:
    OperandNode();
    Value * codeGen();
};

class SingleNode : public Node {
public:
    SingleNode();
    Value * codeGen();
};

class CallNode : public Node {
public:
    unique_ptr<string> id;
    unique_ptr<vector<unique_ptr<ExpressionNode>>> args;

    CallNode();
    Value * codeGen();
};
