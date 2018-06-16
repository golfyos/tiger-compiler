
.PHONY: all
# all: parser lexer

# parser: tgc_parser.yy
# 	bison -d -v tgc_parser.yy

# lexer: tgc_lexer.l
# 	flex --outfile=tgc_lexer.yy.cc  $<


CXX   ?= g+
CDEBUG = -g -Wall
CXXDEBUG = -g -Wall
CXXSTD = -std=c++14
EXE = tiger
LLVM = `llvm-config --cxxflags --ldflags --system-libs --libs core`
CXXFLAGS = -Wno-deprecated-register -O0  $(CXXDEBUG) $(CXXSTD) $(LLVM)

#CPPOBJ = main mc_driver
CPPOBJ = ../../ast/Stmt ../../ast/Expr ../../ast/ASTStmtReader ../Compiler ../Tiger_Driver ../../ast/BasedType ../../ast/FunctionAST ../IRCodegen 
SOBJ =  parser lexer

FILES = $(addsuffix .cpp, $(CPPOBJ))
OBJS  = $(addsuffix .o, $(CPPOBJ))



wc: $(FILES)
	$(MAKE) $(SOBJ)
	$(MAKE) $(OBJS) 
	$(CXX) $(CXXFLAGS) -o $(EXE) $(OBJS) parser.o lexer.o $(LIBS)

parser: tiger_parser.yy
	bison -d -v tiger_parser.yy
	$(CXX) $(CXXFLAGS) -c $(LLVM) -o parser.o tiger_parser.tab.cc

lexer: tiger_lexer.l
	flex --outfile=tiger_lexer.yy.cc $<
	$(CXX)  $(CXXFLAGS) -c $(LLVM) tiger_lexer.yy.cc -o lexer.o


CLEANLIST =  $(addsuffix .o, $(OBJ)) $(OBJS) \
				 tiger_parser.tab.cc tiger_parser.tab.hh \
				 location.hh position.hh \
			    stack.hh tiger_parser.output parser.o \
				 lexer.o tiger_lexer.yy.cc $(EXE)\

clean:
	rm -rf $(CLEANLIST)




# Goal : S NEWLINE|END;
# S : ORB L CRB
# 	  |	ID				{driver.add_id( $1 );}
# 	  ;	

# 	L : S
# 	  | L COMMA S
# 	  ;	
