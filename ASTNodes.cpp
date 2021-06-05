#include <iostream>
#include <vector>
#include <map>
#include <string>
#include "ASTNodes.hpp"
#include "parser.tab.h"


vector<DeclarationNode*> *root;

static std::unique_ptr<LLVMContext> TheContext;
static std::unique_ptr<Module> TheModule;
static std::unique_ptr<IRBuilder<>> Builder;

static vector<map<string, Value *> > varTable;
static map<string, Function *> funcTable;

static AllocaInst *CreateEntryBlockAlloca(Function *func, Type * type, const string name) {
    IRBuilder<> TmpB(&func->getEntryBlock(), func->getEntryBlock().begin());
        TmpB.CreateAlloca(type, 0, name.c_str());
}

static Type * str2type(string str) {
    Type * retType;
    if(str == "BOOL_type")
        retType = Type::getInt1Ty(*TheContext);
    else if(str == "CHAR_type")
        retType = Type::getInt8Ty(*TheContext);
    else if(str == "INT_type")
        retType = Type::getInt32Ty(*TheContext);
    else if(str == "FLOAT_type")
        retType = Type::getFloatTy(*TheContext);
    else if(str == "VOID_type")
        retType = Type::getVoidTy(*TheContext);
}

void printPrefix(int layer) {
    for(int i = layer-1; i > 0; i--) {
        cout << "|   ";
    }
    cout << "|---";
}

Value * DeclarationNode::codeGen() {
    if(funDecl)
        return funDecl->codeGen();
    else if(varDecl)
        return varDecl->codeGen();
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
    Type * thisType = str2type(*baseType);
    Function * outerLayer = Builder->GetInsertBlock()->getParent();
    if(arrayPost == nullptr && arrayConstList == nullptr) {
        for(auto node : *idList) {
            AllocaInst * variable = CreateEntryBlockAlloca(outerLayer, thisType, *(node->id));
            varTable.back()[*(node->id)] = variable;
            if(node->initExp)
                Builder->CreateStore(node->initExp->codeGen(), variable);
        }
    }
    else {
        int size = 1;
        for(auto i : *arrayPost)
            size *= i;
        AllocaInst * variable = CreateEntryBlockAlloca(outerLayer, ArrayType::get(thisType, size), *(idList->at(0)->id));
        varTable.back()[*(idList->at(0)->id)] = variable;
        if(arrayConstList) {
            for(int i = 0; i < arrayConstList->size(); i++)
                Builder->CreateStore(arrayConstList->at(i)->codeGen(), Builder->CreateGEP(variable, ConstantInt::get(*TheContext, APInt(i, 32))));
        }
    }
    return nullptr; ///////////////////////////////////////////////////////////////////////可能有问题
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
    vector<Type *> argTypes;
    for(auto param : *params) {
        int size = 1;
        if(param->arrayPost) {
            for(auto i : *param->arrayPost)
                size *= i;
            argTypes.push_back(ArrayType::get(str2type(*(param->baseType)), size));
        }
        else
            argTypes.push_back(str2type(*(param->baseType)));
    }
    Type * thisType = (baseType == nullptr)? Type::getVoidTy(*TheContext) : str2type(*baseType);
    FunctionType * FT = FunctionType::get(thisType, argTypes, false);    ///////// To do:检查多维数组形状

    Function * context = Builder->GetInsertBlock()->getParent();
    BasicBlock * afterBlock = BasicBlock::Create(*TheContext, "outOfFunction", context);
    
    Function * F = Function::Create(FT, Function::ExternalLinkage, *id, TheModule.get());

    varTable.push_back(map<string, Value *>());
    BasicBlock * currBlock = BasicBlock::Create(*TheContext, "intoFunction", F);
    Builder->SetInsertPoint(currBlock);

    funcTable[*id] = F;
    unsigned Idx = 0;
    for (auto &Arg : F->args()) {
        Arg.setName(*(params->at(Idx++)->id));
        varTable.back()[string(Arg.getName())] = &Arg;
    }
    if(!isExtern)
        return functionBody->codeGen(afterBlock);
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

    if(functionBody) {
        functionBody->printNode(layer + 1);
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

    if(arrayPost && !arrayPost->empty()) {
        printPrefix(layer + 1);
        cout << "ArrayPost" << endl;
        for (auto p : *arrayPost) {
            printPrefix(layer + 2);
            cout << p << endl;
        }
    }
}

Value * FunctionBodyNode::codeGen(BasicBlock * afterBlock) {
    if(localDeclarations)
        for(auto node : * localDeclarations)
            node->codeGen();
    if(statementList)
        for(auto node : * statementList)
            node->codeGen();
    Builder->CreateBr(afterBlock);
    Builder->SetInsertPoint(afterBlock);
}

void FunctionBodyNode::printNode(int layer) {
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

Value * CompoundStmtNode::codeGen() {
    varTable.push_back(map<string, Value *>());
    Function * context = Builder->GetInsertBlock()->getParent();
    BasicBlock * currBlock = BasicBlock::Create(*TheContext, "intoBlock", context);
    BasicBlock * afterBlock = BasicBlock::Create(*TheContext, "outOfBlock", context);
    Builder->SetInsertPoint(currBlock);
    if(localDeclarations)
        for(auto node : * localDeclarations)
            node->codeGen();
    if(statementList)
        for(auto node : * statementList)
            node->codeGen();
    Builder->CreateBr(afterBlock);
    Builder->SetInsertPoint(afterBlock);
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
    if(expNode != nullptr)
        return expNode->codeGen();
    else if(compNode != nullptr)
        return compNode->codeGen();
    else if(selNode != nullptr)
        return selNode->codeGen();
    else if(iterNode != nullptr)
        return iterNode->codeGen();
    else if(retNode != nullptr)
        return retNode->codeGen();
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
    Value * cond = condition->codeGen();
    Function *TheFunction = Builder->GetInsertBlock()->getParent();
    BasicBlock *ifBlock = BasicBlock::Create(*TheContext, "if", TheFunction);
    BasicBlock *elseBlock = BasicBlock::Create(*TheContext, "else");
    BasicBlock *afterBlock = BasicBlock::Create(*TheContext, "after");

    Builder->CreateCondBr(cond, ifBlock, elseBlock);

    Builder->SetInsertPoint(ifBlock);

    Value *ifValue = ifPart->codeGen();

    Builder->CreateBr(afterBlock);
    afterBlock = Builder->GetInsertBlock();

    TheFunction->getBasicBlockList().push_back(elseBlock);
    Builder->SetInsertPoint(elseBlock);

    Value *elseValue = elsePart->codeGen();

    Builder->CreateBr(afterBlock);
    elseBlock = Builder->GetInsertBlock();

    TheFunction->getBasicBlockList().push_back(afterBlock);
    Builder->SetInsertPoint(afterBlock);
    PHINode *PN = Builder->CreatePHI(Type::getDoubleTy(*TheContext), 2, "iftmp");

    PN->addIncoming(ifValue, ifBlock);
    PN->addIncoming(elseValue, elseBlock);
    return PN;
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
    if(whileNode)
        return whileNode->codeGen();
    else if(forNode)
        return forNode->codeGen();
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
    Function *TheFunction = Builder->GetInsertBlock()->getParent();
    BasicBlock *mainBlock = BasicBlock::Create(*TheContext, "whileLoop", TheFunction);

    Builder->CreateBr(mainBlock);
    Builder->SetInsertPoint(mainBlock);

    Value * cond = condition->codeGen();
    BasicBlock *afterBlock = BasicBlock::Create(*TheContext, "afterWhile", TheFunction);
    Builder->CreateCondBr(cond, mainBlock, afterBlock);

    statement->codeGen();

    Builder->CreateBr(mainBlock);
    Builder->SetInsertPoint(afterBlock);

    return nullptr;
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
    first->codeGen();
    Function *TheFunction = Builder->GetInsertBlock()->getParent();
    BasicBlock *mainBlock = BasicBlock::Create(*TheContext, "forLoop", TheFunction);

    Builder->CreateBr(mainBlock);
    Builder->SetInsertPoint(mainBlock);

    Value * cond = second->codeGen();
    BasicBlock *afterBlock = BasicBlock::Create(*TheContext, "afterFor", TheFunction);
    Builder->CreateCondBr(cond, mainBlock, afterBlock);

    statement->codeGen();
    third->codeGen();

    Builder->CreateBr(mainBlock);
    Builder->SetInsertPoint(afterBlock);

    return nullptr;
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
    Value * ret = returnExp->codeGen();
    return Builder->CreateRet(ret);
}

void ReturnStmtNode::printNode(int layer) {
    printPrefix(layer);
    cout << "ReturnStmt" << endl;

    if(returnExp) {
        returnExp->printNode(layer + 1);
    }
}

Value * ExpressionNode::codeGen() {
    if(operand)
        return operand->codeGen();
    else {
        // if(*op == "ASSIGN") {
        //     Value * result = expression->codeGen();
        //     Builder->CreateStore(result, )
        // }
    }
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
    if(arrayPost == nullptr)
        for(auto it = varTable.rbegin(); it != varTable.rend(); it++) {
            if((*it).count(*id) > 0)
                return (*it)[*id];
        }
    else {

    }
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
    // if(single != nullptr) {
    //     if(*op == "MINUS")
    //         if(single->floatNode != nullptr)
    //             return Builder->CreateFNeg(single->codeGen());
    //         else
    //             return Builder->CreateNeg(single->codeGen());
    //     else if(*op == "LNOT")
    //         return Builder->CreateNot(single->codeGen());
    //     else if(*op == "BNOT")
    //         return Builder->CreateNot(single->codeGen());   /////////////////////////////////////////////
        
    // }
    // else if()
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
    if(varNode != nullptr)
        return varNode->codeGen();
    else if(callNode != nullptr)
        return callNode->codeGen();
    else if(intNode != nullptr)
        return intNode->codeGen();
    else if(floatNode != nullptr)
        return floatNode->codeGen();
    else if(charNode != nullptr)
        return charNode->codeGen();
    else if(boolNode != nullptr)
        return boolNode->codeGen();
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
    const char * p = id->data();
    Function * calleeF = TheModule->getFunction(StringRef(p));
    vector<Value *> ArgsV;
    for (unsigned i = 0, e = args->size(); i != e; ++i)
        ArgsV.push_back(args->at(i)->codeGen());
    return Builder->CreateCall(calleeF, ArgsV, "calltmp");
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
    // APInt(uint64_t *val, unsigned int bits)
    return ConstantInt::get(*TheContext, APInt(value, 32));
}

void IntNode::printNode(int layer) {
    printPrefix(layer);
    cout << "Int: " << value << endl;
}

Value * FloatNode::codeGen() {
    return ConstantFP::get(*TheContext, APFloat(value));
}

void FloatNode::printNode(int layer) {
    printPrefix(layer);
    cout << "Float: " << value << endl;
}

Value * CharNode::codeGen() {
    // APInt(uint64_t *val, unsigned int bits)
    return ConstantInt::get(*TheContext, APInt(value, 8));
}

void CharNode::printNode(int layer) {
    printPrefix(layer);
    cout << "Char: " << value << endl;
}

Value * BoolNode::codeGen() {
    return ConstantInt::getBool(*TheContext, value);
}

void BoolNode::printNode(int layer) {
    printPrefix(layer);
    cout << "Bool: " << value << endl;
}

int main() {
    varTable.push_back(map<string, Value *>());
    yyparse();
    cout << "Program" << endl;
    for(auto p : *root) {
        p->printNode(1);
    }
    return 0;
}