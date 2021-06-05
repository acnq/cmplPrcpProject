#include <iostream>
#include <vector>
#include <llvm/IR/Value.h> 
#include <string>
#include "ASTNodes.hpp"


void printPrefix(int layer) {
    for(int i = layer-1; i > 0; i--) {
        cout << "    ";
    }
    cout << "|---";
}

Value * DeclarationNode::codeGen() {

}

void DeclarationNode::printNode(int layer) {
    printPrefix(layer);
    cout << "Declaration" << endl;

    if(varDecl) {
        printPrefix(layer);
        varDecl->printNode(layer + 1);
    }
    if(funDecl) {
        printPrefix(layer);
        funDecl->printNode(layer + 1);
    }
}

Value * VarDeclarationNode::codeGen() {

}

void VarDeclarationNode::printNode(int layer) {
    printPrefix(layer);
    cout << "VarDeclaration" << endl;

    if(baseType) {
        printPrefix(layer);
        cout << *baseType << endl;
    }

    if(idList) {
        printPrefix(layer);
        for (auto p : *idList) {
            p->printNode(layer + 1);
        }
    }

    if(arrayPost) {
        printPrefix(layer);
        for (auto p : *arrayPost) {
            cout << p << endl;
        }
    }

    if(arrayConstList) {
        printPrefix(layer);
        for (auto p : *arrayConstList) {
            p->printNode(layer + 1);
        }
    }
}

Value * IdListNode::codeGen() {

}

void IdListNode::printNode(int layer) {
    printPrefix(layer);
    cout << "IdList" << endl;
    
    if(id) {
        printPrefix(layer);
        cout << *id << endl;
    }

    if(initExp) {
        printPrefix(layer);
        initExp->printNode(layer + 1);
    }
}

Value * FunDeclarationNode::codeGen() {

}

void FunDeclarationNode::printNode(int layer) {
    printPrefix(layer);
    cout << "FunDeclaration" << endl;

    if(baseType) {
        printPrefix(layer);
        cout << *baseType << endl;
    }

    if(id) {
        printPrefix(layer);
        cout << *id << endl;
    }

    if(params) {
        printPrefix(layer);
        for (auto p : *params) {
            p->printNode(layer + 1);
        }
    }

    if(compoundStmt) {
        printPrefix(layer);
        compoundStmt->printNode(layer + 1);
    }
}

Value * ParamNode::codeGen() {

}

void ParamNode::printNode(int layer) {
    printPrefix(layer);
    cout << "This is Param" << endl;

    if(baseType) {
        printPrefix(layer);
        cout << *baseType << endl;
    }

    if(id) {
        printPrefix(layer);
        cout << *id << endl;
    }
}

Value * CompoundStmtNode::codeGen() {

}

void CompoundStmtNode::printNode(int layer) {
    cout << "This is CompoundStmt" << endl;
}

Value * StatementNode::codeGen() {

}

void StatementNode::printNode(int layer) {
    cout << "This is Statement" << endl;
}

Value * SelectionStmtNode::codeGen() {

}

void SelectionStmtNode::printNode(int layer) {
    cout << "This is SelectionStmt" << endl;
}

Value * IterationStmtNode::codeGen() {

}

void IterationStmtNode::printNode(int layer) {
    cout << "This is IterationStmt" << endl;
}

Value * WhileStmtNode::codeGen() {

}

void WhileStmtNode::printNode(int layer) {
    cout << "This is WhileStmt" << endl;
}

Value * ForStmtNode::codeGen() {

}

void ForStmtNode::printNode(int layer) {
    cout << "This is ForStmt" << endl;
}

Value * ReturnStmtNode::codeGen() {

}

void ReturnStmtNode::printNode(int layer) {
    cout << "This is ReturnStmt" << endl;
}

Value * ExpressionNode::codeGen() {

}

void ExpressionNode::printNode(int layer) {
    cout << "This is Expression" << endl;
}

Value * VarNode::codeGen() {

}

void VarNode::printNode(int layer) {
    cout << "This is Var" << endl;
}

Value * OperandNode::codeGen() {

}

void OperandNode::printNode(int layer) {
    cout << "This is Operand" << endl;
}

Value * SingleNode::codeGen() {

}

void SingleNode::printNode(int layer) {
    cout << "This is Single" << endl;
}

Value * CallNode::codeGen() {

}

void CallNode::printNode(int layer) {
    cout << "This is Call" << endl;
}

Value * IntNode::codeGen() {

}

void IntNode::printNode(int layer) {
    cout << "This is Int" << endl;
}

Value * FloatNode::codeGen() {

}

void FloatNode::printNode(int layer) {
    cout << "This is Float" << endl;
}

Value * CharNode::codeGen() {

}

void CharNode::printNode(int layer) {
    cout << "This is Char" << endl;
}

Value * BoolNode::codeGen() {

}

void BoolNode::printNode(int layer) {
    cout << "This is Bool" << endl;
}
