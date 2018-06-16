#include "FunctionAST.hpp"
#include "../frontEnd/IRCodegen.hh"
#include "ASTStmtReader.hpp"


namespace Tiger {

	Function* PrototypeAST::accept(IRCodegen* v)
	{
		return v->genIR(this);
	}

	void FunctionAST::accept(ASTStmtReader *v)
	{
		v->visit(this);
	}

	Function* FunctionAST::accept(IRCodegen* v)
	{
		return v->genIR(this);
	}

	void PrototypeAST::accept(ASTStmtReader *v)
	{
		v->visit(this);
	}
	
}