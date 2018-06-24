#pragma once
#include "../ast/Expr.hpp"
#include "../ast/FunctionAST.hpp"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/Support/raw_ostream.h"
#include <memory>

using namespace llvm;

namespace Tiger {

	static LLVMContext TheContext;
	static IRBuilder<> Builder(TheContext);
	static std::unique_ptr< Module > TheModule;
	static std::map<std::string, Value *> NamedValues;

	class IRCodegen
	{
	public:
		IRCodegen();
		virtual ~IRCodegen();

		Value* genIR(Stmt* node);
		Value* genIR(Expr* node);
		Value* genIR(BinaryOperator* node);
		Value* genIR(IntegerLiteral* node);
		Value* genIR(Identifier* node);
		Function* genIR(FunctionAST* node);
		Function* genIR(PrototypeAST* node);

		void print();
	private:
	};
}
