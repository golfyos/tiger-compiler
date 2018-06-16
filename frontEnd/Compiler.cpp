#include <cstdlib>
#include "Tiger_Driver.hpp"
#include "../ast/ASTStmtReader.hpp"
#include "IRCodegen.hh"

#include "../ast/Stmt.hpp"


// void acceptAll(std::vector<Tiger::Stmt*> all_ast){
	
// 	Tiger::IRCodegen* visitor;
// 	for(int i=0; i<(int)all_ast.size(); i++){
// 		visitor = new Tiger::IRCodegen();
// 		all_ast.at(i)->accept(visitor);
// 		visitor->print();
// 	}
// }

int main(const int argc, const char **argv)
{
	if (argc == 2)
	{
		Tiger::Tiger_Driver driver;
		driver.parse(argv[1]);
		driver.print(std::cout) << "reading file " << argv[1] << " \n";

		Tiger::ASTStmtReader reader;
		// driver.getAST()->accept(&reader);

		// acceptAll(driver,driver.getASTList());
		

		// Code IRCodeGen visitor 
		// Tiger::IRCodegen* visitor = new Tiger::IRCodegen();
		// driver.getAST()->accept(visitor);
		// visitor->print();


		std::vector<Tiger::Stmt*> trees = driver.getASTList();
		std::cout << trees.size() << " << size \n"; 
		for(int i=0;i<(int)trees.size();i++){
			trees.at(i)->accept(&reader);
			// reader->print();
		}



		// Tiger::IRCodegen* visitor;
		// std::vector<Tiger::Stmt*> trees = driver.getASTList();
		// std::cout << trees.size() << " << size \n"; 
		// for(int i=0;i<(int)trees.size();i++){
		// 	visitor = new Tiger::IRCodegen();
		// 	trees.at(i)->accept(visitor);
		// 	visitor->print();
		// }

	}
	else
		return(EXIT_FAILURE);
	return (EXIT_SUCCESS);
}