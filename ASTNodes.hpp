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

class declarationNode : public Node {
public:
    declarationNode();
    Value * codeGen();
};

class varDeclarationNode : public Node {
public:
    varDeclarationNode();
    Value * codeGen();
};

class idListNode : public Node {
public:
    idListNode();
    Value * codeGen();
};

class arrayInitListNode : public Node {
public:
    arrayInitListNode();
    Value * codeGen();
};

class funDeclarationNode : public Node {
public:
    funDeclarationNode();
    Value * codeGen();
};

class paramNode : public Node {
public:
    paramNode();
    Value * codeGen();
};

class compoundStmtNode : public Node {
public:
    compoundStmtNode();
    Value * codeGen();
};

class statementNode : public Node {
public:
    statementNode();
    Value * codeGen();
};

class selectionStmtNode : public Node {
public:
    selectionStmtNode();
    Value * codeGen();
};

class whileStmtNode : public Node {
public:
    whileStmtNode();
    Value * codeGen();
};

class forStmtNode : public Node {
public:
    forStmtNode();
    Value * codeGen();
};

class returnStmtNode : public Node {
public:
    returnStmtNode();
    Value * codeGen();
};

class expressionNode : public Node {
public:
    expressionNode();
    Value * codeGen();
};

class varNode : public Node {
public:
    varNode();
    Value * codeGen();
};

class operandNode : public Node {
public:
    operandNode();
    Value * codeGen();
};

class singleNode : public Node {
public:
    singleNode();
    Value * codeGen();
};

class callNode : public Node {
public:
    callNode();
    Value * codeGen();
};
