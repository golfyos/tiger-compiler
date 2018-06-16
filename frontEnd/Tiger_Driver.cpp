#include <cassert>
#include <cctype>
#include <fstream>
#include <typeinfo>
#include <stack>

#include "Tiger_Driver.hpp"
#include "../ast/Expr.hpp"
#include "../ast/FunctionAST.hpp"

Tiger::Tiger_Driver::~Tiger_Driver()
{
	/* point to int type or float type */

	delete(scanner);
	scanner = nullptr;
	delete(parser);
	parser = nullptr;

	// while(!expStack.empty()){
	// 	Stmt* t = (Stmt*)expStack.top();
	// 	delete t;
	// 	expStack.pop();
	// }

	while(!ast_list.empty()){
		Stmt* t = (Stmt*)ast_list.back();
		delete t;
		ast_list.pop_back();
	}
}

/**
* parse - parse from a file
* @param filename - valid string with input file
*/
void Tiger::Tiger_Driver::parse(const char * const filename)
{
	assert(filename != nullptr);
	std::ifstream in_file(filename);
	if (in_file.good())
	{
		parse_helper( in_file );
	}
	else
		exit(EXIT_FAILURE);
	return;
}

void Tiger::Tiger_Driver::add_id(const std::string &id,const std::string &type)
{
	ids++;
	Identifier* identifier = new Identifier(id,type);
	expStack.push(identifier);
}



void Tiger::Tiger_Driver::parse_helper(std::istream &stream)
{

	delete(scanner);
	try
	{
		scanner = new Tiger::Tiger_Scanner(&stream);
	}
	catch (std::bad_alloc &ba)
	{
		std::cerr << "Failed to allocate scanner: (" <<
			ba.what() << "), exiting!!\n";
		exit(EXIT_FAILURE);
	}

	delete(parser);
	try
	{
		parser = new Tiger::Tiger_Parser((*scanner) /* scanner */,
			(*this) /* driver */);
	}
	catch (std::bad_alloc &ba)
	{
		std::cerr << "Failed to allocate parser: (" <<
			ba.what() << "), exiting!!\n";
		exit(EXIT_FAILURE);
	}
	const int accept(0);
	if (parser->parse() != accept)
	{
		std::cerr << "Parse failed!!\n";
	}else{
		std::cout << "Accept\n";
	}
	return;
}

std::ostream&
Tiger::Tiger_Driver::print(std::ostream &stream)
{
	stream << "---- Tiger Compiler Frontend ----\n";
	stream << ids << " IDs found.\n";
	return(stream);
}

void Tiger::Tiger_Driver::addNode(Stmt* node){
	expStack.push(node);
	ast = node;
}

void Tiger::Tiger_Driver::addIntegerLiteral(int number){
	IntegerLiteral* node = new IntegerLiteral(number);
	addNode(node);
	
}

void Tiger::Tiger_Driver::addBinaryOperator(Expr::Opcode opcode){
	Expr* r = (Expr*)expStack.top();
	expStack.pop();
	Expr* l = (Expr*)expStack.top();
	expStack.pop();
	

	BinaryOperator* node = new BinaryOperator(l,r,opcode);
	addNode(node);

}

Tiger::Stmt* Tiger::Tiger_Driver::getAST(){
	return ast;
}

std::vector<Tiger::Stmt*> Tiger::Tiger_Driver::getASTList(){
	return ast_list;
}


void Tiger::Tiger_Driver::add_function_def(std::string id,std::string returnType){

	// Expr* expr = (Expr*)expStack.top();
	// expStack.pop();
	// Identifier* arg = (Identifier*)expStack.top();
	// expStack.pop();
	
	std::vector<std::string> ArgNames;
	// ArgNames.push_back(arg->getIdentifier());

	PrototypeAST* proto = new PrototypeAST(id,std::move(ArgNames),returnType);
	FunctionAST* fn = new FunctionAST(std::move(proto),std::move(bodyStmt));
	// FunctionAST* fn = new FunctionAST(std::move(proto),std::move(expr));
	addNode(fn);
	addAST(fn);
	while(!bodyStmt.empty()){
		Stmt* t = bodyStmt.back();
		delete t;
		bodyStmt.pop_back();
	}
	
}

void Tiger::Tiger_Driver::addAST(Stmt* ast){
	ast_list.push_back(ast);
}

void Tiger::Tiger_Driver::addToBodyStmt(){
	std::stack<Tiger::Stmt*> temp;

	if(countStmt == 0){
		while(!expStack.empty()){

			temp.push(expStack.top());
			expStack.pop();
			countStmt ++;
		}
	}else{
		int c = countStmt;
		for(int i=0;i<((int)expStack.size())-c;i++){
			temp.push(expStack.top());
			expStack.pop();
			countStmt++;
		}
	}
	
	while(!temp.empty()){
		expStack.push(temp.top());
		temp.pop();
		bodyStmt.push_back(expStack.top());
	}
}
