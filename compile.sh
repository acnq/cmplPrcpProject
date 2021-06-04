bison -d parser.y
flex lexer.l
clang++ -g -O3 lex.yy.c parser.tab.c ASTNodes.cpp `llvm-config --cxxflags`  -w  -DLLVM_DISABLE_ABI_BREAKING_CHECKS_ENFORCING=1