#include "Stmt.hpp"
#include "ASTStmtReader.hpp"
#include "../frontEnd/IRCodegen.hh"


namespace Tiger {

	Stmt::~Stmt()
	{
	}

	void Stmt::accept(ASTStmtReader *v)
	{
		v->visit(this);
	}

	Value* Stmt::accept(IRCodegen* v)
	{
		return v->genIR(this);
	}

}


