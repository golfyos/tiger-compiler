#include "IRCodegen.hh"
#include "llvm/IR/BasicBlock.h"
#include "llvm/IR/Verifier.h"


namespace Tiger {


	IRCodegen::IRCodegen() {
		TheModule = llvm::make_unique<Module>("Tiger_code.tig", TheContext);
	}

	IRCodegen::~IRCodegen()
	{
	}

	/// CreateEntryBlockAlloca - Create an alloca instruction in the entry block of
	/// the function.  This is used for mutable variables etc.
	static AllocaInst *CreateEntryBlockAlloca(Function *TheFunction,const std::string &VarName) 
	{
		IRBuilder<> TmpB(&TheFunction->getEntryBlock(),TheFunction->getEntryBlock().begin());
		return TmpB.CreateAlloca(Type::getDoubleTy(TheContext), 0,VarName.c_str());
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

	Value* IRCodegen::genIR(Identifier* node)
	{
		Function *TheFunction = Builder.GetInsertBlock()->getParent();
		
		// Create an alloca for this variable.
		AllocaInst *Alloca = CreateEntryBlockAlloca(TheFunction, node->getIdentifier());
		Value* cur = Builder.CreateLoad(Alloca);

		// Store the initial value into the alloca.
		return Builder.CreateStore(cur,Alloca);
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
		for (auto &Arg : TheFunction->args()){
			NamedValues[Arg.getName()] = &Arg;
		}

		for(int i=0;i<(int)node->Body.size();i++){
			Value *val = node->Body.at(i)->accept(this);
			if (val!=nullptr) {
				if(i==((int)node->Body.size())-1){
					// Finish off the function.
					Builder.CreateRetVoid();
					// Validate the generated code, checking for consistency.
					verifyFunction(*TheFunction);
					return TheFunction;
				}
			}
		}
		

		// Error reading body, remove function.
		TheFunction->eraseFromParent();
		return nullptr;
	}

	Function* IRCodegen::genIR(PrototypeAST* node)
	{
		std::vector<Type *> Void(node->Args.size(), Type::getVoidTy(TheContext));
		FunctionType *FT =
			FunctionType::get(Type::getVoidTy(TheContext), Void, false);

		Function *F =
			Function::Create(FT, Function::ExternalLinkage, node->Name, TheModule.get());

		// Set names for all arguments.
		unsigned Idx = 0;
		for (auto &Arg : F->args())
			Arg.setName(node->Args[Idx++]);

		return F;
	}
}