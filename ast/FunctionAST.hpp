#pragma once
#include "Expr.hpp"
#include "llvm/IR/Function.h"
#include <string>
#include <vector>
#include <memory>
#include "Stmt.hpp"



using namespace llvm;
namespace Tiger {


	class PrototypeAST :public Stmt{
		
		friend IRCodegen;
		std::string Name;
		std::vector<std::string> Args;
		// std::vector<Identifier*> Args;
		std::string returnType;

	public:
		// PrototypeAST(const std::string &Name, std::vector<std::string> Args)
		// 	: Name(Name), Args(std::move(Args)) {}

		PrototypeAST(const std::string &Name, std::vector<std::string> Args , std::string &returnType)
			: Name(Name), Args(std::move(Args)),returnType(returnType) {}

		const std::string &getName() const { return Name; }
		const std::string &getRType() const {return returnType;}

		// std::vector<std::string> getArgs() { return Args;}

		Function* accept(IRCodegen* v);

		void accept(ASTStmtReader *v);
	};

	class FunctionAST :public Stmt
	{
		friend ASTStmtReader;
		friend IRCodegen;
		PrototypeAST* Proto;
		// Expr* Body;
		std::vector<Stmt*> Body;

	public:
		// FunctionAST(PrototypeAST* Proto,Expr* Body)
		// 	: Proto(std::move(Proto)), Body(std::move(Body)) {}

		FunctionAST(PrototypeAST* Proto,std::vector<Stmt*> Body)
			: Proto(std::move(Proto)), Body(std::move(Body)) {}
		
		virtual Function* accept(IRCodegen* v);

		void accept(ASTStmtReader *v);

		
	};

}

