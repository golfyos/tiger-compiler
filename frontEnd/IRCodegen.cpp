#include "IRCodegen.hh"
#include "llvm/IR/BasicBlock.h"
#include "llvm/IR/Verifier.h"


namespace Tiger {

	IRCodegen::IRCodegen() {
		TheModule = llvm::make_unique<Module>("my cool jit", TheContext);
	}

	IRCodegen::~IRCodegen()
	{
	}

	void IRCodegen::print()
	{
		TheModule->print(errs(), nullptr);
	}

	Value* IRCodegen::genIR(Stmt* node)
	{
		return nullptr;
	}
	Value* IRCodegen::genIR(Expr* node)
	{
		return nullptr;
	}
	Value* IRCodegen::genIR(BinaryOperator* node)
	{
		Value *L = node->left()->accept(this);
		Value *R = node->right()->accept(this);
		if (!L || !R)
			return nullptr;

		switch (node->getOpcode()) {
		case BinaryOperator::ADD:
			return Builder.CreateFAdd(L, R, "addtmp");
		case BinaryOperator::SUB:
			return Builder.CreateFSub(L, R, "subtmp");
		case BinaryOperator::MUL:
			return Builder.CreateFMul(L, R, "multmp");
		case BinaryOperator::DIV:
			return Builder.CreateFDiv(L, R, "divtmp");
		default:
			fprintf(stderr, "invalid binary operator\n");
		}
		return nullptr;
	}
	Value* IRCodegen::genIR(IntegerLiteral* node)
	{
		return ConstantFP::get(TheContext, APFloat((float)node->getVal()));
	}

	Function* IRCodegen::genIR(FunctionAST* node){
		Function *TheFunction = TheModule->getFunction(node->Proto->getName());
		if (!TheFunction)
			TheFunction = node->Proto->accept(this);

		if (!TheFunction)
			return nullptr;

		// Create a new basic block to start insertion into.
		BasicBlock *BB = BasicBlock::Create(TheContext, "entry", TheFunction);
		Builder.SetInsertPoint(BB);

		// Record the function arguments in the NamedValues map.
		NamedValues.clear();
		for (auto &Arg : TheFunction->args())
			NamedValues[Arg.getName()] = &Arg;

		bool checker = false;
		for(int i=0;i<(int)node->Body.size();i++){
			if (Value *RetVal = node->Body.at(i)->accept(this)) {
				// Finish off the function.
				Builder.CreateRet(RetVal);

				// Validate the generated code, checking for consistency.
				verifyFunction(*TheFunction);

				if(i==((int)node->Body.size())-1){
					checker = true;
				}
			}
		}
		if(checker == true)
			return TheFunction;
		

		// Error reading body, remove function.
		TheFunction->eraseFromParent();
		return nullptr;
	}

	Function* IRCodegen::genIR(PrototypeAST* node)
	{
		std::vector<Type *> Doubles(node->Args.size(), Type::getDoubleTy(TheContext));
		FunctionType *FT =
			FunctionType::get(Type::getDoubleTy(TheContext), Doubles, false);

		Function *F =
			Function::Create(FT, Function::ExternalLinkage, node->Name, TheModule.get());

		// Set names for all arguments.
		unsigned Idx = 0;
		for (auto &Arg : F->args())
			Arg.setName(node->Args[Idx++]);

		return F;
	}
}