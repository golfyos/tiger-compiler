#include <cstdlib>
#include "Tiger_Driver.hpp"
#include "../ast/ASTStmtReader.hpp"
#include "IRCodegen.hh"

#include "../ast/Stmt.hpp"

int main(const int argc, const char **argv)
{
	if (argc == 2)
	{
		Tiger::Tiger_Driver driver;
		driver.parse(argv[1]);
		driver.print(std::cout) << "reading file " << argv[1] << " \n";

		Tiger::ASTStmtReader reader;
		// driver.getAST()->accept(&reader);




		/* Visitor visits each tree */

		// std::vector<Tiger::Stmt*> trees = driver.getASTList();
		// std::cout << trees.size() << " << size \n"; 
		// for(int i=0;i<(int)trees.size();i++){
		// 	trees.at(i)->accept(&reader);
		// 	// reader->print();
		// }



		Tiger::IRCodegen* visitor;
		std::vector<Tiger::Stmt*> trees = driver.getASTList();
		std::cout << trees.size() << " << size \n"; 
		for(int i=0;i<(int)trees.size();i++){
		 	visitor = new Tiger::IRCodegen();
		 	trees.at(i)->accept(visitor);
		 	visitor->print();
		}

	}
	else
		return(EXIT_FAILURE);
	return (EXIT_SUCCESS);
}