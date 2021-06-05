#include <iostream>
#include <vector>
#include <llvm/IR/Value.h> 
#include <string>
#include "ASTNodes.hpp"

DeclarationNode::DeclarationNode() {

}

Value * DeclarationNode::codeGen() {

}

VarDeclarationNode::VarDeclarationNode() {

}

Value * VarDeclarationNode::codeGen() {

}

IdListNode::IdListNode() {

}

Value * IdListNode::codeGen() {

}

// ArrayInitListNode::ArrayInitListNode() {

// }

// Value * ArrayInitListNode::codeGen() {

// }

FunDeclarationNode::FunDeclarationNode() {

}

Value * FunDeclarationNode::codeGen() {
    int a[2][2] = { {3, 4}, {4, 8} };
}

ParamNode::ParamNode() {

}

Value * ParamNode::codeGen() {

}

CompoundStmtNode::CompoundStmtNode() {

}

Value * CompoundStmtNode::codeGen() {

}

StatementNode::StatementNode() {

}

Value * StatementNode::codeGen() {

}

SelectionStmtNode::SelectionStmtNode() {

}

Value * SelectionStmtNode::codeGen() {

}

IterationStmtNode::IterationStmtNode() {

}

Value * IterationStmtNode::codeGen() {

}

WhileStmtNode::WhileStmtNode() {

}

Value * WhileStmtNode::codeGen() {

}

ForStmtNode::ForStmtNode() {

}

Value * ForStmtNode::codeGen() {

}

ReturnStmtNode::ReturnStmtNode() {

}

Value * ReturnStmtNode::codeGen() {

}

ExpressionNode::ExpressionNode() {

}

Value * ExpressionNode::codeGen() {

}

VarNode::VarNode() {

}

Value * VarNode::codeGen() {

}

OperandNode::OperandNode() {

}

Value * OperandNode::codeGen() {

}

SingleNode::SingleNode() {

}

Value * SingleNode::codeGen() {

}

CallNode::CallNode() {

}

Value * CallNode::codeGen() {

}
