#pragma once
#include <iostream>
#include <stack>
#include <vector>

#include "tiger_scanner.hpp"
#include "def/tiger_parser.tab.hh"
#include "../ast/Expr.hpp"
#include "../ast/FunctionAST.hpp"

namespace Tiger {
	class Tiger_Driver
	{
	public:
		Tiger_Driver() = default;

		~Tiger_Driver();

		/**
		* parse - parse from a file
		* @param filename - valid string with input file
		*/
		void parse(const char * const filename);

		void add_id( const std::string &id , const std::string &type);

		std::ostream& print(std::ostream &stream);

		void addIntegerLiteral(int number);

		void addBinaryOperator(Expr::Opcode opcode);

		Tiger::Stmt* getAST();

		void add_function_def(std::string FnName,std::string returnType);

		std::vector<Tiger::Stmt*> getASTList();

		void addAST(Tiger::Stmt*);

		void addToBodyStmt();



	private:
		void parse_helper(std::istream &stream);

		std::size_t	ids = 0;
		int countStmt = 0;

		std::vector<Tiger::Stmt*> bodyStmt;
		Tiger::Tiger_Parser  *parser = nullptr;
		Tiger::Tiger_Scanner *scanner = nullptr;

		Tiger::Stmt* ast = nullptr;
		std::vector<Tiger::Stmt*> ast_list;

		std::stack<Tiger::Stmt*> expStack;

		// std::unique_ptr<FunctionAST> faster;
		
		void addNode(Stmt* node);


		
		
	};
}
