#include <iostream>
#include <vector>
#include <llvm/IR/Value.h> 
#include <string>
#include "ASTNodes.hpp"


void printPrefix(int layer) {
    for(int i = layer-1; i > 0; i--) {
        cout << "|   ";
    }
    cout << "|---";
}

Value * DeclarationNode::codeGen() {

}

void DeclarationNode::printNode(int layer) {
    printPrefix(layer);
    cout << "Declaration" << endl;

    if(varDecl) {
        varDecl->printNode(layer + 1);
    }

    if(funDecl) {
        funDecl->printNode(layer + 1);
    }
}

Value * VarDeclarationNode::codeGen() {

}

void VarDeclarationNode::printNode(int layer) {
    printPrefix(layer);
    cout << "VarDeclaration" << endl;

    if(baseType) {
        printPrefix(layer + 1);
        cout << *baseType << endl;
    }

    if(idList) {
        for (auto p : *idList) {
            p->printNode(layer + 1);
        }
    }

    if(arrayPost && !arrayPost->empty()) {
        printPrefix(layer + 1);
        cout << "ArrayPost" << endl;
        for (auto p : *arrayPost) {
            printPrefix(layer + 2);
            cout << p << endl;
        }
    }

    if(arrayConstList) {
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
        printPrefix(layer + 1);
        cout << *id << endl;
    }

    if(initExp) {
        initExp->printNode(layer + 1);
    }
}

Value * FunDeclarationNode::codeGen() {

}

void FunDeclarationNode::printNode(int layer) {
    printPrefix(layer);
    cout << "FunDeclaration" << endl;

    if(baseType) {
        printPrefix(layer + 1);
        cout << *baseType << endl;
    } else {
        printPrefix(layer + 1);
        cout << "void" << endl;
    }

    if(id) {
        printPrefix(layer + 1);
        cout << *id << endl;
    }

    if(params) {
        for (auto p : *params) {
            p->printNode(layer + 1);
        }
    }

    if(compoundStmt) {
        compoundStmt->printNode(layer + 1);
    }
}

Value * ParamNode::codeGen() {

}

void ParamNode::printNode(int layer) {
    printPrefix(layer);
    cout << "Param" << endl;

    if(baseType) {
        printPrefix(layer + 1);
        cout << *baseType << endl;
    }

    if(id) {
        printPrefix(layer + 1);
        cout << *id << endl;
    }

    if(arrayPostParam && !arrayPostParam->empty()) {
        printPrefix(layer + 1);
        cout << "ArrayPostParam" << endl;
        for (auto p : *arrayPostParam) {
            printPrefix(layer + 2);
            cout << p << endl;
        }
    }
}

Value * CompoundStmtNode::codeGen() {

}

void CompoundStmtNode::printNode(int layer) {
    printPrefix(layer);
    cout << "CompoundStmt" << endl;

    if(localDeclarations) {
        for (auto p : *localDeclarations) {
            p->printNode(layer + 1);
        }
    }

    if(statementList) {
        for (auto p : *statementList) {
            p->printNode(layer + 1);
        }
    }
}

Value * StatementNode::codeGen() {

}

void StatementNode::printNode(int layer) {
    printPrefix(layer);
    cout << "Statement" << endl;

    if(expNode) {
        expNode->printNode(layer + 1);
    }

    if(compNode) {
        compNode->printNode(layer + 1);
    }
    
    if(selNode) {
        selNode->printNode(layer + 1);
    }
    
    if(iterNode) {
        iterNode->printNode(layer + 1);
    }
    
    if(retNode) {
        retNode->printNode(layer + 1);
    }
    
}

Value * SelectionStmtNode::codeGen() {

}

void SelectionStmtNode::printNode(int layer) {
    printPrefix(layer);
    cout << "SelectionStmt" << endl;

    if(condition) {
        condition->printNode(layer + 1);
    }

    if(ifPart) {
        ifPart->printNode(layer + 1);
    }

    if(ifPart) {
        ifPart->printNode(layer + 1);
    }
}

Value * IterationStmtNode::codeGen() {

}

void IterationStmtNode::printNode(int layer) {
    printPrefix(layer);
    cout << "IterationStmt" << endl;

    if(whileNode) {
        whileNode->printNode(layer + 1);
    }

    if(forNode) {
        forNode->printNode(layer + 1);
    }
}

Value * WhileStmtNode::codeGen() {

}

void WhileStmtNode::printNode(int layer) {
    printPrefix(layer);
    cout << "WhileStmt" << endl;

    if(condition) {
        condition->printNode(layer + 1);
    }

    if(statement) {
        statement->printNode(layer + 1);
    }
}

Value * ForStmtNode::codeGen() {

}

void ForStmtNode::printNode(int layer) {
    printPrefix(layer);
    cout << "ForStmt" << endl;

    if(first) {
        first->printNode(layer + 1);
    }

    if(second) {
        second->printNode(layer + 1);
    }

    if(third) {
        third->printNode(layer + 1);
    }

    if(statement) {
        statement->printNode(layer + 1);
    }
}

Value * ReturnStmtNode::codeGen() {

}

void ReturnStmtNode::printNode(int layer) {
    printPrefix(layer);
    cout << "ReturnStmt" << endl;

    if(returnExp) {
        returnExp->printNode(layer + 1);
    }
}

Value * ExpressionNode::codeGen() {

}

void ExpressionNode::printNode(int layer) {
    printPrefix(layer);
    cout << "Expression" << endl;

    if(op) {
        printPrefix(layer + 1);
        cout << *op << endl;
    }

    if(var) {
        var->printNode(layer + 1);
    }

    if(expression) {
        expression->printNode(layer + 1);
    }

    if(operand) {
        operand->printNode(layer + 1);
    }
}

Value * VarNode::codeGen() {

}

void VarNode::printNode(int layer) {
    printPrefix(layer);
    cout << "Var" << endl;

    if(id) {
        printPrefix(layer + 1);
        cout << *id << endl;
    }

    if(arrayPost && !arrayPost->empty()) {
        printPrefix(layer + 1);
        cout << "ArrayPost" << endl;
        for (auto p : *arrayPost) {
            printPrefix(layer + 2);
            cout << p << endl;
        }
    }
}

Value * OperandNode::codeGen() {

}

void OperandNode::printNode(int layer) {
    printPrefix(layer);
    cout << "Operand" << endl;

    if(op) {
        printPrefix(layer + 1);
        cout << *op << endl;
    }
    
    if(lhs) {
        lhs->printNode(layer + 1);
    }

    if(rhs) {
        rhs->printNode(layer + 1);
    }

    if(single) {
        single->printNode(layer + 1);
    }
}

Value * SingleNode::codeGen() {

}

void SingleNode::printNode(int layer) {
    printPrefix(layer);
    cout << "Single" << endl;

    if(varNode) {
        varNode->printNode(layer + 1);
    }

    if(callNode) {
        callNode->printNode(layer + 1);
    }

    if(intNode) {
        intNode->printNode(layer + 1);
    }
    
    if(floatNode) {
        floatNode->printNode(layer + 1);
    }

    if(charNode) {
        charNode->printNode(layer + 1);
    }

    if(boolNode) {
        boolNode->printNode(layer + 1);
    }
}

Value * CallNode::codeGen() {

}

void CallNode::printNode(int layer) {
    printPrefix(layer);
    cout << "Call" << endl;

    if(id) {
        printPrefix(layer + 1);
        cout << *id << endl;
    }

    if(args) {
        for (auto p : *args) {
            p->printNode(layer + 1);
        }
    }
}

Value * IntNode::codeGen() {

}

void IntNode::printNode(int layer) {
    printPrefix(layer);
    cout << "Int: " << value << endl;
}

Value * FloatNode::codeGen() {

}

void FloatNode::printNode(int layer) {
    printPrefix(layer);
    cout << "Float: " << value << endl;
}

Value * CharNode::codeGen() {

}

void CharNode::printNode(int layer) {
    printPrefix(layer);
    cout << "Char: " << value << endl;
}

Value * BoolNode::codeGen() {

}

void BoolNode::printNode(int layer) {
    printPrefix(layer);
    cout << "Bool: " << value << endl;
}
