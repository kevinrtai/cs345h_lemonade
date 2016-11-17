CC = g++
CFLAGS = -g -Wall -std=c++0x
INC=-. ./ast
INC_PARAMS=$(foreach d, $(INC), -I$d)

OBJs =   parser.tab.o lex.yy.o  Expression.o SymbolTable.o frontend.o Evaluator.o AstRead.o AstNil.o AstList.o AstUnOp.o AstBranch.o AstExpressionList.o AstIdentifierList.o AstBinOp.o  AstIdentifier.o AstInt.o AstLambda.o AstLet.o AstString.o 
rOBJs =   parser.tab.o lex.yy.o  Expression.o SymbolTable.o repl.o Evaluator.o AstRead.o AstNil.o AstList.o AstUnOp.o AstBranch.o AstExpressionList.o AstIdentifierList.o AstBinOp.o  AstIdentifier.o AstInt.o AstLambda.o AstLet.o AstString.o 

default: parser

parser: ${OBJs}
	${CC} ${CFLAGS} ${INC_PARAMS} ${OBJs} -o l-interpreter -lfl

repl:   ${rOBJs}
	${CC} ${CFLAGS} ${INC_PARAMS} ${rOBJs} -o l-repl -lfl

lex.yy.o: lex.yy.c

parser.tab.o: parser.tab.c  parser-defs.h

frontend.o:	frontend.cpp Evaluator.cpp 
	${CC} ${CFLAGS} ${INC_PARAMS} -c frontend.cpp Evaluator.cpp 

repl.o: repl.cpp Evaluator.cpp
	${CC} ${CFLAGS} ${INC_PARAMS} -c repl.cpp Evaluator.cpp 
	
SymbolTable.o:	SymbolTable.cpp
	${CC} ${CFLAGS} ${INC_PARAMS} -c SymbolTable.cpp 

Expression.o:	ast/*.h ast/*.cpp #ast/Expression.cpp ast/Expression.h ast/AstString.cpp ast/AstString.h
	${CC} ${CFLAGS} ${INC_PARAMS} -c ast/*.cpp


clean:
	rm -f l-interpreter  parser.output *.o

depend:
	makedepend -I. *.c
