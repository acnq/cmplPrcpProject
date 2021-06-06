#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <string>
#include "ASTNodes.hpp"
#include "parser.tab.h"


vector<DeclarationNode*> *root;

LLVMContext TheContext;
Module TheModule("Module", TheContext);
IRBuilder<> Builder(TheContext);

// static vector<map<string, Value *> > varTable;
static vector<map<string, pair<Value *, vector<int> > > > varTable;
static map<string, Function *> funcTable;

static AllocaInst *CreateEntryBlockAlloca(Function *func, Type * type, const string name) {
    IRBuilder<> TmpB(&func->getEntryBlock(), func->getEntryBlock().begin());
    return TmpB.CreateAlloca(type, 0, name.c_str());
}

static int type2int(Type * t) {
    if(t == Type::getInt1Ty(TheContext))
        return 0;
    else if(t == Type::getInt8Ty(TheContext))
        return 1;
    else if(t == Type::getInt32Ty(TheContext))
        return 2;
    else if(t == Type::getFloatTy(TheContext))
        return 3;
    return -1;
}

static bool typeNoSmaller(Type * t1, Type * t2) {
    if(type2int(t1) >= type2int(t2))
        return true;
    return false;
}

static Type * str2type(string str) {
    Type * retType = nullptr;
    if(str == "BOOL_TYPE")
        retType = Type::getInt1Ty(TheContext);
    else if(str == "CHAR_TYPE")
        retType = Type::getInt8Ty(TheContext);
    else if(str == "INT_TYPE")
        retType = Type::getInt32Ty(TheContext);
    else if(str == "FLOAT_TYPE")
        retType = Type::getFloatTy(TheContext);
    else if(str == "VOID_TYPE")
        retType = Type::getVoidTy(TheContext);
    return retType;
}

void printPrefix(int layer) {
    for(int i = layer-1; i > 0; i--) {
        cout << "|   ";
    }
    cout << "|---";
}

Value * DeclarationNode::codeGen() {
    cout << "Running codeGen for Declaration." << endl;
    if(funDecl)
        return funDecl->codeGen();
    else if(varDecl)
        return varDecl->codeGen(true);
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

Value * VarDeclarationNode::codeGen(bool global=false) {
    Type * thisType = str2type(*baseType);
    Function * outerLayer;
    if(!global)
         outerLayer = Builder.GetInsertBlock()->getParent();
    if(arrayPost == nullptr && arrayConstList == nullptr) {
        for(auto node : *idList) {
            Value * variable = nullptr;

            if(!global) {
                variable = CreateEntryBlockAlloca(outerLayer, thisType, *(node->id));
                if (node->initExp) {
                    Builder.CreateStore(node->initExp->codeGen(), variable);
                }
            }
            else {
                if(node->initExp == nullptr) {
                    variable = new GlobalVariable(
                            TheModule, thisType, false, GlobalValue::InternalLinkage,
                            ConstantAggregateZero::get(thisType), *(node->id)
                    );
                }
                else {
                    Value * result = node->initExp->codeGen();
                    if(thisType != Type::getFloatTy(TheContext)) {
                        if(result->getType() == Type::getFloatTy(TheContext))
                            result = Builder.CreateFPCast(result, Type::getInt32Ty(TheContext));
                    }
                    else {
                        if(result->getType() != Type::getFloatTy(TheContext))
                            result = Builder.CreateIntCast(result, Type::getFloatTy(TheContext), true);
                    }
                    variable = new GlobalVariable(
                            TheModule, thisType, false, GlobalValue::InternalLinkage,
                            (Constant * )result, *(node->id)  ///////////////////////////////////// 可能有问题
                    );
                }
            }
            varTable.back()[*(node->id)] = pair<Value *, vector<int> >(variable, vector<int>());
        }
    }
    else {
        int size = 1;
        for(auto i : *arrayPost)
            size *= i;
        cout << "Size: " << size << endl;
        Value * variable = nullptr;
        if(!global) {
            variable = CreateEntryBlockAlloca(outerLayer, ArrayType::get(thisType, size), *(idList->at(0)->id));
            if(arrayConstList) {
                vector<Value *> initValues;
                for(auto node : *arrayConstList) {
                    Value * result = node->codeGen();
                    if(thisType != Type::getFloatTy(TheContext)) {
                        if(result->getType() == Type::getFloatTy(TheContext))
                            result = Builder.CreateFPCast(result, Type::getInt32Ty(TheContext));
                    }
                    else {
                        if(result->getType() != Type::getFloatTy(TheContext))
                            result = Builder.CreateIntCast(result, Type::getFloatTy(TheContext), true);
                    }
                    initValues.push_back(result);
                }
                for(int i = 0; i < initValues.size(); i++) {
                    Builder.CreateStore(initValues[i], Builder.CreateGEP(variable, ConstantInt::get(TheContext, APInt(32, i))));
                }
            }
        }
        else {
            if(arrayConstList == nullptr) {
                variable = new GlobalVariable(
                        TheModule, ArrayType::get(thisType, size), false, GlobalValue::InternalLinkage,
                        ConstantAggregateZero::get(ArrayType::get(thisType, size)), *(idList->at(0)->id)
                );
            }
            else {
                vector<Constant *> initValues;
                for(auto node : *arrayConstList) {
                    Value * result = node->codeGen();
                    if(thisType != Type::getFloatTy(TheContext)) {
                        if(result->getType() == Type::getFloatTy(TheContext))
                            result = Builder.CreateFPCast(result, Type::getInt32Ty(TheContext));
                    }
                    else {
                        if(result->getType() != Type::getFloatTy(TheContext))
                            result = Builder.CreateIntCast(result, Type::getFloatTy(TheContext), true);
                    }
                    initValues.push_back((Constant*)result);     ////////////////// 可能有问题
                }
                ArrayRef<Constant *> valRefs(initValues);
                variable = new GlobalVariable(
                        TheModule, ArrayType::get(thisType, size), false, GlobalValue::InternalLinkage,
                        ConstantArray::get(ArrayType::get(thisType, size), valRefs), *(idList->at(0)->id)
                );
            }
        }
        cout << "Size: " << size << endl;
        varTable.back()[*(idList->at(0)->id)] = pair<Value *, vector<int> >(variable, *arrayPost);
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
    cout << "Running codeGen for FunDeclaration." << endl;
    vector<Type *> argTypes;
    if(params)
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

    Type * thisType = (baseType == nullptr)? Type::getVoidTy(TheContext) : str2type(*baseType);
    FunctionType * FT = FunctionType::get(thisType, argTypes, false);    ///////// To do:检查多维数组形状

//    Function * context = Builder.GetInsertBlock()->getParent();
    BasicBlock * afterBlock = BasicBlock::Create(TheContext, "outOfFunction");
    
    Function * F = Function::Create(FT, Function::ExternalLinkage, *id, &TheModule);

    varTable.push_back(map<string, pair<Value *, vector<int> > > ());
    BasicBlock * currBlock = BasicBlock::Create(TheContext, "intoFunction", F);
    Builder.SetInsertPoint(currBlock);

    funcTable[*id] = F;

    unsigned Idx = 0;
    for (auto &Arg : F->args()) {
        AllocaInst *Alloca = CreateEntryBlockAlloca(F, Arg.getType(), Arg.getName().str());
        Builder.CreateStore(&Arg, Alloca);
        Arg.setName(*(params->at(Idx++)->id));
        varTable.back()[string(Arg.getName())] = pair<Value *, vector<int> >(Alloca, vector<int>());
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
    cout << "Running codeGen for FunctionBody." << endl;
    if(localDeclarations)
        for(auto node : * localDeclarations)
            node->codeGen();
    if(statementList)
        for(auto node : * statementList)
            node->codeGen();
//    Builder.CreateBr(afterBlock);
//    Builder.SetInsertPoint(afterBlock);
    return nullptr;
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
    cout << "Running codeGen for CompoundStmt." << endl;
    varTable.push_back(map<string, pair<Value *, vector<int> > > ());
    Function * context = Builder.GetInsertBlock()->getParent();
    BasicBlock * currBlock = BasicBlock::Create(TheContext, "intoBlock", context);
//    BasicBlock * afterBlock = BasicBlock::Create(TheContext, "outOfBlock", context);
    Builder.SetInsertPoint(currBlock);
    if(localDeclarations)
        for(auto node : * localDeclarations)
            node->codeGen();
    if(statementList)
        for(auto node : * statementList)
            node->codeGen();
//    Builder.CreateBr(afterBlock);
//    Builder.SetInsertPoint(afterBlock);
    return nullptr;
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
    cout << "Running codeGen for Statement." << endl;
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
    cout << "Running codeGen for SelectionStmt." << endl;
    Value * cond = condition->codeGen();
    Function *TheFunction = Builder.GetInsertBlock()->getParent();
    BasicBlock *ifBlock = BasicBlock::Create(TheContext, "if", TheFunction);
    BasicBlock *elseBlock = BasicBlock::Create(TheContext, "else");
    BasicBlock *afterBlock = BasicBlock::Create(TheContext, "after");

    Builder.CreateCondBr(cond, ifBlock, elseBlock);

    Builder.SetInsertPoint(ifBlock);

    Value *ifValue = ifPart->codeGen();

    Builder.CreateBr(afterBlock);
    afterBlock = Builder.GetInsertBlock();

    TheFunction->getBasicBlockList().push_back(elseBlock);
    Builder.SetInsertPoint(elseBlock);

    Value *elseValue;
    if(elsePart)
        elseValue = elsePart->codeGen();

    Builder.CreateBr(afterBlock);
    elseBlock = Builder.GetInsertBlock();

    TheFunction->getBasicBlockList().push_back(afterBlock);
    Builder.SetInsertPoint(afterBlock);
//    PHINode *PN = Builder.CreatePHI(Type::getDoubleTy(TheContext), 2, "iftmp");

//    PN->addIncoming(ifValue, ifBlock);
//    PN->addIncoming(elseValue, elseBlock);
//    return PN;
    return nullptr;
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
    cout << "Running codeGen for IterationStmt." << endl;
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
    cout << "Running codeGen for WhileStmt." << endl;

    Function *TheFunction = Builder.GetInsertBlock()->getParent();
    BasicBlock *mainBlock = BasicBlock::Create(TheContext, "whileLoop", TheFunction);

    Builder.CreateBr(mainBlock);
    Builder.SetInsertPoint(mainBlock);

    Value * cond = condition->codeGen();
    BasicBlock *loopBlock = BasicBlock::Create(TheContext, "actualLoop");
    BasicBlock *afterBlock = BasicBlock::Create(TheContext, "afterFor");
    Builder.CreateCondBr(cond, loopBlock, afterBlock);

    TheFunction->getBasicBlockList().push_back(loopBlock);
    Builder.SetInsertPoint(loopBlock);
    statement->codeGen();
    Builder.CreateBr(mainBlock);

    TheFunction->getBasicBlockList().push_back(afterBlock);
    Builder.SetInsertPoint(afterBlock);

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
    cout << "Running codeGen for ForStmt." << endl;
    first->codeGen();
    Function *TheFunction = Builder.GetInsertBlock()->getParent();
    BasicBlock *mainBlock = BasicBlock::Create(TheContext, "forLoop", TheFunction);

    Builder.CreateBr(mainBlock);
    Builder.SetInsertPoint(mainBlock);

    Value * cond = second->codeGen();
    BasicBlock *loopBlock = BasicBlock::Create(TheContext, "actualLoop");
    BasicBlock *afterBlock = BasicBlock::Create(TheContext, "afterFor");
    Builder.CreateCondBr(cond, loopBlock, afterBlock);

    TheFunction->getBasicBlockList().push_back(loopBlock);
    Builder.SetInsertPoint(loopBlock);
    statement->codeGen();
    third->codeGen();
    Builder.CreateBr(mainBlock);

    TheFunction->getBasicBlockList().push_back(afterBlock);
    Builder.SetInsertPoint(afterBlock);

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
    cout << "Running codeGen for ReturnStmt." << endl;
    Value * ret = returnExp->codeGen();
    return Builder.CreateRet(ret);
}

void ReturnStmtNode::printNode(int layer) {
    printPrefix(layer);
    cout << "ReturnStmt" << endl;

    if(returnExp) {
        returnExp->printNode(layer + 1);
    }
}

Value * ExpressionNode::codeGen() {
    cout << "Running codeGen for ExpressionNode." << endl;
    if(operand)
        return operand->codeGen();
    else {
        Value *rhs = expression->codeGen();
        Value *variable = var->codeGen();
        Value *varValue = Builder.CreateLoad(variable, *(var->id));
        Value *result = rhs;

        if (varValue->getType() != rhs->getType())
            rhs = Builder.CreateIntCast(rhs, varValue->getType(), true);


        if (*op == "ASSIGN") {
            Builder.CreateStore(rhs, variable);
        } else if (*op == "BANDASSIGN") {
            result = Builder.CreateAnd(varValue, rhs);
            Builder.CreateStore(result, variable);
        } else if (*op == "BORASSIGN") {
            result = Builder.CreateOr(varValue, rhs);
            Builder.CreateStore(result, variable);
        } else if (*op == "BXORASSIGN") {
            result = Builder.CreateXor(varValue, rhs);
            Builder.CreateStore(result, variable);
        } else if (*op == "SLASSIGN") {
            result = Builder.CreateShl(varValue, rhs);
            Builder.CreateStore(result, variable);
        } else if (*op == "SLASSIGN") {
            result = Builder.CreateAShr(varValue, rhs);
            Builder.CreateStore(result, variable);
        } else if (rhs->getType() != Type::getFloatTy(TheContext)) {
            if (*op == "PLUSASSIGN") {
                result = Builder.CreateAdd(varValue, rhs);
                Builder.CreateStore(result, variable);
            } else if (*op == "MINUSASSIGN") {
                result = Builder.CreateSub(varValue, rhs);
                Builder.CreateStore(result, variable);
            } else if (*op == "MULTASSIGN") {
                result = Builder.CreateMul(varValue, rhs);
                Builder.CreateStore(result, variable);
            } else if (*op == "DIVASSIGN") {
                result = Builder.CreateSDiv(varValue, rhs);
                Builder.CreateStore(result, variable);
            } else if (*op == "MODASSIGN") {
                result = Builder.CreateSRem(varValue, rhs);
                Builder.CreateStore(result, variable);
            }
        } else {
            if (*op == "PLUSASSIGN") {
                result = Builder.CreateFAdd(varValue, rhs);
                Builder.CreateStore(result, variable);
            } else if (*op == "MINUSASSIGN") {
                result = Builder.CreateFSub(varValue, rhs);
                Builder.CreateStore(result, variable);
            } else if (*op == "MULTASSIGN") {
                result = Builder.CreateFMul(varValue, rhs);
                Builder.CreateStore(result, variable);
            } else if (*op == "DIVASSIGN") {
                result = Builder.CreateFDiv(varValue, rhs);
                Builder.CreateStore(result, variable);
            } else if (*op == "MODASSIGN") {
                result = Builder.CreateFRem(varValue, rhs);
                Builder.CreateStore(result, variable);
            }
        }
        return result;
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
    cout << "Running codeGen for VarNode." << endl;
    if(arrayPost == nullptr) {
        for (auto it = varTable.rbegin(); it != varTable.rend(); it++)
            if ((*it).count(*id) > 0)
                return (*it)[*id].first;
    }
    else {
        Value * array;
        vector<int> size;
        for(auto it = varTable.rbegin(); it != varTable.rend(); it++)
            if((*it).count(*id) > 0) {
                array = (*it)[*id].first;
                size = (*it)[*id].second;
                break;
            }
        if(arrayPost->size() != size.size()) {
            // Error !
        }
        for(int i = 0; i < size.size(); i++)
            if(arrayPost->at(i) >= size[i]) {
                // Error !
            }
        vector<int> products(size.size() + 1);
        products[size.size()] = 1;
        for(int i = size.size() - 1; i >= 0; i--)
            products[i] = products[i+1] * size[i];
        products[size.size()] = 0;
        int ind = 0;
        for(int i = size.size() - 1; i >= 0; i--)
            ind = ind * products[i+1] + products[i];
        return Builder.CreateGEP(array, ConstantInt::get(TheContext, APInt(32, ind)));
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
    cout << "Running codeGen for Operand." << endl;
    if(rhs == nullptr && single == nullptr) {
        Value * result = lhs->codeGen();
        if(op == nullptr)
            return result;
        else if(*op == "MINUS")
            if(result->getType() == Type::getFloatTy(TheContext))
                return Builder.CreateFNeg(result);
            else
                return Builder.CreateNeg(result);
        else if(*op == "BNOT")
            return Builder.CreateNot(result);
        else if(*op == "LNOT")
            if(result->getType() == Type::getFloatTy(TheContext))
                return Builder.CreateFCmpONE(result, ConstantFP::get(TheContext, APFloat(0.0)));
            else
                return Builder.CreateICmpNE(result, ConstantInt::getBool(TheContext, false));
    }
    else if(single != nullptr) {
        Value * result = single->codeGen();
        if(op == nullptr)
            return result;
        else if(*op == "MINUS")
            if(result->getType() == Type::getFloatTy(TheContext))
                return Builder.CreateFNeg(result);
            else
                return Builder.CreateNeg(result);
        else if(*op == "BNOT")
            return Builder.CreateNot(result);
        else if(*op == "LNOT")
            if(result->getType() == Type::getFloatTy(TheContext))
                return Builder.CreateFCmpONE(result, ConstantFP::get(TheContext, APFloat(0.0)));
            else
                return Builder.CreateICmpNE(result, ConstantInt::getBool(TheContext, false));
        
    }
    else {
        Value * left = lhs->codeGen();
        Value * right = rhs->codeGen();
        if(left->getType() != right->getType()) {
            if(type2int(left->getType()) > type2int(right->getType()))
                right = Builder.CreateIntCast(right, left->getType(), true);
            else if(type2int(right->getType()) > type2int(left->getType()))
                left = Builder.CreateIntCast(left, right->getType(), true);
        }
        if(*op == "BOR") {
            return Builder.CreateOr(left, right);
        }
        else if(*op == "BAND") {
            return Builder.CreateAnd(left, right);
        }
        else if(*op == "SL") {
            return Builder.CreateShl(left, right);
        }
        else if(*op == "SR") {
            return Builder.CreateAShr(left, right);
        }
        else if(left->getType() != Type::getFloatTy(TheContext)) {
            if(*op == "LOR") {
                Value * tmp = Builder.CreateOr(left, right);
                return Builder.CreateICmpNE(tmp, ConstantInt::getBool(TheContext, false));
            }
            else if(*op == "LAND") {
                Value * leftTrue = Builder.CreateICmpNE(left, ConstantInt::getBool(TheContext, false));
                Value * rightTrue = Builder.CreateICmpNE(right, ConstantInt::getBool(TheContext, false));
                return Builder.CreateAnd(leftTrue, rightTrue);
            }
            else if(*op == "EQ") {
                return Builder.CreateICmpEQ(left, right);
            }
            else if(*op == "NEQ") {
                return Builder.CreateICmpNE(left, right);
            }
            else if(*op == "LT") {
                return Builder.CreateICmpSLT(left, right);
            }
            else if(*op == "GT") {
                return Builder.CreateICmpSGT(left, right);
            }
            else if(*op == "LTE") {
                return Builder.CreateICmpSLE(left, right);
            }
            else if(*op == "GTE") {
                return Builder.CreateICmpSGE(left, right);
            }
            else if(*op == "PLUS") {
                return Builder.CreateAdd(left, right);
            }
            else if(*op == "MINUS") {
                return Builder.CreateSub(left, right);
            }
            else if(*op == "MULT") {
                return Builder.CreateMul(left, right);
            }
            else if(*op == "DIV") {
                return Builder.CreateSDiv(left, right);
            }
            else if(*op == "MOD") {
                return Builder.CreateSRem(left, right);
            }
        }
        else {
            if(*op == "LOR") {
                Value * tmp = Builder.CreateOr(left, right);
                return Builder.CreateFCmpONE(tmp, ConstantInt::getBool(TheContext, false));
            }
            else if(*op == "LAND") {
                Value * leftTrue = Builder.CreateFCmpONE(left, ConstantInt::getBool(TheContext, false));
                Value * rightTrue = Builder.CreateFCmpONE(right, ConstantInt::getBool(TheContext, false));
                return Builder.CreateAnd(leftTrue, rightTrue);
            }
            else if(*op == "EQ") {
                return Builder.CreateFCmpOEQ(left, right);
            }
            else if(*op == "NEQ") {
                return Builder.CreateFCmpONE(left, right);
            }
            else if(*op == "LT") {
                return Builder.CreateFCmpOLT(left, right);
            }
            else if(*op == "GT") {
                return Builder.CreateFCmpOGT(left, right);
            }
            else if(*op == "LTE") {
                return Builder.CreateFCmpOLE(left, right);
            }
            else if(*op == "GTE") {
                return Builder.CreateFCmpOGE(left, right);
            }
            else if(*op == "PLUS") {
                return Builder.CreateFAdd(left, right);
            }
            else if(*op == "MINUS") {
                return Builder.CreateFSub(left, right);
            }
            else if(*op == "MULT") {
                return Builder.CreateFMul(left, right);
            }
            else if(*op == "DIV") {
                return Builder.CreateFDiv(left, right);
            }
            else if(*op == "MOD") {
                return Builder.CreateFRem(left, right);
            }
        }
    }
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
    cout << "Running codeGen for Single." << endl;
    if(varNode != nullptr){
        Value *varValue = Builder.CreateLoad(varNode->codeGen(), *(varNode->id));
        return varValue;
    }
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
    cout << "Running codeGen for Call." << endl;
    const char * p = id->data();
    Function * calleeF = TheModule.getFunction(StringRef(p));
    vector<Value *> ArgsV;
    for (unsigned i = 0, e = args->size(); i != e; ++i)
        ArgsV.push_back(args->at(i)->codeGen());
    return Builder.CreateCall(calleeF, ArgsV, "calltmp");
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
    cout << "Running codeGen for Int." << endl;
    // APInt(uint64_t *val, unsigned int bits)
    return ConstantInt::get(TheContext, APInt(32, value));
}

void IntNode::printNode(int layer) {
    printPrefix(layer);
    cout << "Int: " << value << endl;
}

Value * FloatNode::codeGen() {
    cout << "Running codeGen for Float." << endl;
    return ConstantFP::get(TheContext, APFloat(value));
}

void FloatNode::printNode(int layer) {
    printPrefix(layer);
    cout << "Float: " << value << endl;
}

Value * CharNode::codeGen() {
    cout << "Running codeGen for Char." << endl;
    // APInt(uint64_t *val, unsigned int bits)
    return ConstantInt::get(TheContext, APInt(8, value));
}

void CharNode::printNode(int layer) {
    printPrefix(layer);
    cout << "Char: " << value << endl;
}

Value * BoolNode::codeGen() {
    cout << "Running codeGen for Bool." << endl;
    return ConstantInt::getBool(TheContext, value);
}

void BoolNode::printNode(int layer) {
    printPrefix(layer);
    cout << "Bool: " << value << endl;
}

int main() {

    varTable.push_back(map<string, pair<Value *, vector<int> > > ());
    yyparse();
    cout << "Program" << endl;
    for(auto p : *root) {
        p->printNode(1);
    }
    int cnt = 0;
    for(auto p : *root) {
        p->codeGen();
        cout << cnt++ << endl;
    }
    TheModule.print(errs(), nullptr);

    return 0;
}