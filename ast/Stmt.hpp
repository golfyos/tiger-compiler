#pragma once
/*!
*  \addtogroup TGC
*  @{
*/
#include "llvm/IR/Value.h"

using namespace llvm;

/*! TGC namespace */
namespace Tiger {

	class ASTStmtReader;
	class IRCodegen;

	/*! A test class */
	class Stmt
	{
		friend class ASTStmtReader;
	public:
		Stmt() = default;
		virtual ~Stmt();

		virtual void accept(ASTStmtReader *v);
		virtual Value* accept(IRCodegen* v);
	};
}// End namespace TGC
 /** @}*/