#include "IRCodegen.hh"
#include "../ast/FunctionAST.hpp"
#include <string>

using namespace TGC;
using namespace std;

int main() {
	std::string FnName("foo");
	std::vector<std::string> ArgNames;
	ArgNames.push_back("x");
	ArgNames.push_back("y");
	unique_ptr<PrototypeAST> proto=llvm::make_unique<PrototypeAST>(FnName, std::move(ArgNames));
	IntegerLiteral* lhs=new IntegerLiteral(200);
	IntegerLiteral* rhs = new IntegerLiteral(7);
	unique_ptr<Expr> e = llvm::make_unique<TGC::BinaryOperator>(std::move(lhs), std::move(rhs), Expr::ADD);
	unique_ptr<FunctionAST> fn=llvm::make_unique<FunctionAST>(std::move(proto), std::move(e));

	IRCodegen* visitorCodegen = new IRCodegen();
	fn->accept(visitorCodegen);
	visitorCodegen->print();
	delete visitorCodegen;

	return 0;
}