#include <iostream>
#include <vector>
#include <llvm/IR/Value.h> 
#include <string>

class Node {
public:
    virtual ~Node() = default;
    virtual llvm::Value * codeGen() = 0;

    std::vector<Node> subnodes;
};

class declarationListNode : public Node {
public:
    declarationListNode(std::vector<Node> subnodes);
    llvm::Value * codeGen();
};

class declarationNode : public Node {
public:
    declarationNode(std::vector<Node> subnodes);
    llvm::Value * codeGen();
};

class varDeclarationNode : public Node {
public:
    varDeclarationNode(std::vector<Node> subnodes);
    llvm::Value * codeGen();
};

class typeSpecifierNode : public Node {
public:
    typeSpecifierNode(std::vector<Node> subnodes);
    llvm::Value * codeGen();
};

class arrayTypeNode : public Node {
public:
    arrayTypeNode(std::vector<Node> subnodes);
    llvm::Value * codeGen();
};

class arrayInitListNode : public Node {
public:
    arrayInitListNode(std::vector<Node> subnodes);
    llvm::Value * codeGen();
};

class arrayInitNode : public Node {
public:
    arrayInitNode(std::vector<Node> subnodes);
    llvm::Value * codeGen();
};

class baseTypeNode : public Node {
public:
    baseTypeNode(std::vector<Node> subnodes);
    llvm::Value * codeGen();
};

class funDeclarationNode : public Node {
public:
    funDeclarationNode(std::vector<Node> subnodes);
    llvm::Value * codeGen();
};

class paramsNode : public Node {
public:
    paramsNode(std::vector<Node> subnodes);
    llvm::Value * codeGen();
};

class compoundStmtNode : public Node {
public:
    compoundStmtNode(std::vector<Node> subnodes);
    llvm::Value * codeGen();
};

class localDeclarationsNode : public Node {
public:
    localDeclarationsNode(std::vector<Node> subnodes);
    llvm::Value * codeGen();
};

class statementListNode : public Node {
public:
    statementListNode(std::vector<Node> subnodes);
    llvm::Value * codeGen();
};

class statementNode : public Node {
public:
    statementNode(std::vector<Node> subnodes);
    llvm::Value * codeGen();
};

class expressionStmtNode : public Node {
public:
    expressionStmtNode(std::vector<Node> subnodes);
    llvm::Value * codeGen();
};

class selectionStmtNode : public Node {
public:
    selectionStmtNode(std::vector<Node> subnodes);
    llvm::Value * codeGen();
};

class iterationStmtNode : public Node {
public:
    iterationStmtNode(std::vector<Node> subnodes);
    llvm::Value * codeGen();
};

class whileStmtNode : public Node {
public:
    whileStmtNode(std::vector<Node> subnodes);
    llvm::Value * codeGen();
};

class forStmtNode : public Node {
public:
    forStmtNode(std::vector<Node> subnodes);
    llvm::Value * codeGen();
};

class returnStmtNode : public Node {
public:
    returnStmtNode(std::vector<Node> subnodes);
    llvm::Value * codeGen();
};

class expressionNode : public Node {
public:
    expressionNode(std::vector<Node> subnodes);
    llvm::Value * codeGen();
};

class assopNode : public Node {
public:
    assopNode(std::vector<Node> subnodes);
    llvm::Value * codeGen();
};

class varNode : public Node {
public:
    varNode(std::vector<Node> subnodes);
    llvm::Value * codeGen();
};

class operandNode : public Node {
public:
    operandNode(std::vector<Node> subnodes);
    llvm::Value * codeGen();
};

class prefixNode : public Node {
public:
    prefixNode(std::vector<Node> subnodes);
    llvm::Value * codeGen();
};

class singleNode : public Node {
public:
    singleNode(std::vector<Node> subnodes);
    llvm::Value * codeGen();
};

class callNode : public Node {
public:
    callNode(std::vector<Node> subnodes);
    llvm::Value * codeGen();
};

class argsNode : public Node {
public:
    argsNode(std::vector<Node> subnodes);
    llvm::Value * codeGen();
};

class argListNode : public Node {
public:
    argListNode(std::vector<Node> subnodes);
    llvm::Value * codeGen();
};
