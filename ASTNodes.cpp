#include <iostream>
#include <vector>
#include <llvm/IR/Value.h> 
#include <string>
#include "ASTNodes.hpp"

Value * DeclarationNode::codeGen() {

}

void DeclarationNode::printNode(void) {
    cout << "This is Declaration" << endl;
}

Value * VarDeclarationNode::codeGen() {

}

void VarDeclarationNode::printNode(void) {
    cout << "This is VarDeclaration" << endl;
}

Value * IdListNode::codeGen() {

}

void IdListNode::printNode(void) {
    cout << "This is IdList" << endl;
}

Value * FunDeclarationNode::codeGen() {

}

void FunDeclarationNode::printNode(void) {
    cout << "This is FunDeclaration" << endl;
}

Value * ParamNode::codeGen() {

}

void ParamNode::printNode(void) {
    cout << "This is Param" << endl;
}

Value * CompoundStmtNode::codeGen() {

}

void CompoundStmtNode::printNode(void) {
    cout << "This is CompoundStmt" << endl;
}

Value * StatementNode::codeGen() {

}

void StatementNode::printNode(void) {
    cout << "This is Statement" << endl;
}

Value * SelectionStmtNode::codeGen() {

}

void SelectionStmtNode::printNode(void) {
    cout << "This is SelectionStmt" << endl;
}

Value * IterationStmtNode::codeGen() {

}

void IterationStmtNode::printNode(void) {
    cout << "This is IterationStmt" << endl;
}

Value * WhileStmtNode::codeGen() {

}

void WhileStmtNode::printNode(void) {
    cout << "This is WhileStmt" << endl;
}

Value * ForStmtNode::codeGen() {

}

void ForStmtNode::printNode(void) {
    cout << "This is ForStmt" << endl;
}

Value * ReturnStmtNode::codeGen() {

}

void ReturnStmtNode::printNode(void) {
    cout << "This is ReturnStmt" << endl;
}

Value * ExpressionNode::codeGen() {

}

void ExpressionNode::printNode(void) {
    cout << "This is Expression" << endl;
}

Value * VarNode::codeGen() {

}

void VarNode::printNode(void) {
    cout << "This is Var" << endl;
}

Value * OperandNode::codeGen() {

}

void OperandNode::printNode(void) {
    cout << "This is Operand" << endl;
}

Value * SingleNode::codeGen() {

}

void SingleNode::printNode(void) {
    cout << "This is Single" << endl;
}

Value * CallNode::codeGen() {

}

void CallNode::printNode(void) {
    cout << "This is Call" << endl;
}

Value * IntNode::codeGen() {

}

void IntNode::printNode(void) {
    cout << "This is Int" << endl;
}

Value * FloatNode::codeGen() {

}

void FloatNode::printNode(void) {
    cout << "This is Float" << endl;
}

Value * CharNode::codeGen() {

}

void CharNode::printNode(void) {
    cout << "This is Char" << endl;
}

Value * BoolNode::codeGen() {

}

void BoolNode::printNode(void) {
    cout << "This is Bool" << endl;
}
