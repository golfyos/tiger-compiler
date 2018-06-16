#include "ASTStmtReader.hpp"

namespace Tiger {

	ASTStmtReader::~ASTStmtReader()
	{
	}

	void ASTStmtReader::visit(Identifier* node){
		os << "ID :" << node->getIdentifier() << " : " << node->getIdentifierType() << "\n" ;
	}

	void ASTStmtReader::visit(FunctionAST* node)
	{
		os << "\n========FunctionAST========\nfunction name: ";
		os << node->Proto->getName().c_str() << " , return type: "<< node->Proto->getRType().c_str() <<"\n";
		
		// os << "\t" << node->Proto->getArgs().size() << " Args : ";
		// for (int i=0;i< (int)node->Proto->getArgs().size();i++){
		// 	os << node->Proto->getArgs().at(i)->getIdentifier() << ":" << node->Proto->getArgs().at(i)->getIdentifierType();
		// }
		// os << "\n";
		for(int i=0;i<(int)node->Body.size();i++){
			node->Body.at(i)->accept(this);
		}
		os << "\n";
		// node->Body->accept(this);
	}

	void ASTStmtReader::visit(PrototypeAST* node)
	{
		os << "PrototypeAST\n";
	}


	void ASTStmtReader::visit(Stmt* node)
	{
		os << "Stmt\n";
	}

	void ASTStmtReader::visit(Expr* node)
	{
		os << "Expr\n";
	}

	void ASTStmtReader::visit(BinaryOperator* node)
	{
		os << "visit BinaryOperator (" << node->getOpcode() << ")\n";

		node->left()->accept(this);
		node->right()->accept(this);
	}

	void ASTStmtReader::visit(IntegerLiteral* node)
	{
		os << "IntegerLiteral (" << node->getVal() << ")\n";
	}
}