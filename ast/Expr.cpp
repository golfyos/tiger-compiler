#include "Expr.hpp"
#include "ASTStmtReader.hpp"
#include "../frontEnd/IRCodegen.hh"
#include <iostream>

namespace Tiger {
	Expr::~Expr()
	{
	}
	Value* Expr::accept(IRCodegen* v)
	{
		return v->genIR(this);
	}
	void Expr::accept(ASTStmtReader* v)
	{	
		v->visit(this);
	}

	BinaryOperator::~BinaryOperator()
	{
		std::cout << "BinaryOp Destructor\n";
		delete(lhs);
		delete(rhs);
		lhs = rhs = nullptr;
	}

	BinaryOperator::BinaryOperator(Expr* l, Expr* r, Opcode o)
		:lhs(l), rhs(r), opc(o)
	{

	}
	void BinaryOperator::accept(ASTStmtReader* v)
	{
		v->visit(this);
	}

	Value* BinaryOperator::accept(IRCodegen* v)
	{
		return v->genIR(this);
	}
	IntegerLiteral::IntegerLiteral(int value): val(value) 
	{
		setType(INT);
	}
	IntegerLiteral::~IntegerLiteral()
	{
	}

	void IntegerLiteral::accept(ASTStmtReader* v)
	{
		v->visit(this);
	}

	Value* IntegerLiteral::accept(IRCodegen* v)
	{
		return v->genIR(this);
	}

	Identifier::Identifier(std::string name, std::string typeName): id(name), type(typeName)
	{
	}
	Identifier::~Identifier()
	{
	}

	void Identifier::accept(ASTStmtReader* v)
	{
		v->visit(this);
	}

	Value* Identifier::accept(IRCodegen* v)
	{
		return v->genIR(this);
	}
}

