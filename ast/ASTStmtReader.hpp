#pragma once

#include "Expr.hpp"
#include "FunctionAST.hpp"
#include <iostream>


namespace Tiger {
	class ASTStmtReader
	{
	public:
		ASTStmtReader() :os(std::cout) {};
		~ASTStmtReader();

		void visit(Identifier* node);
		void visit(Stmt* node);
		void visit(Expr* node);
		void visit(BinaryOperator* node);
		void visit(IntegerLiteral* node);
		void visit(FunctionAST* node);
		void visit(PrototypeAST* node);
		
	private:
		std::ostream &os; 
	};
}
