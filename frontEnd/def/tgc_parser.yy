%skeleton "lalr1.cc"
%require  "3.0"
%debug 
%defines 
%define api.namespace {TGC}
%define parser_class_name {TGC_Parser}

%code requires{
	   namespace TGC {
		  class TGC_Driver;
		  class TGC_Scanner;
	   }

	// The following definitions is missing when %locations isn't used
	# ifndef YY_NULLPTR
	#  if defined __cplusplus && 201103L <= __cplusplus
	#   define YY_NULLPTR nullptr
	#  else
	#   define YY_NULLPTR 0
	#  endif
	# endif
}

%parse-param { TGC_Scanner &scanner  }
%parse-param { TGC_Driver  &driver  }

%code{
	#include <iostream>
	#include <cstdlib>
	#include <fstream>
   
	/* include for all driver functions */
	#include "../TGC_Driver.hpp"

	#undef yylex
	#define yylex scanner.yylex
}

%define api.value.type variant
%define parse.assert

%token					END    0     "end of file"
%token	<std::string>	ID
%token					ORB
%token					CRB
%token					COMMA
%token					NEWLINE

%token	<std::string>	NUMBER
%token					ADD
%token					SUB
%token					MULTI
%token					DIVIDE

%token					INT
%token					FLOAT

%token					LET

%locations
%define parse.error verbose

// %destructor {printf("token %d.%d discarded\n",@$.begin.line,@$.begin.column);} <*> 

%%
	Goal 	: Goal Stmt 			{}
			| Stmt 					{}
			| Goal Function			{}
			| Function				{}
			| END 					{}
			;

	Stmt 	: Expr NEWLINE 			{std::cout << "Stmt\n"; }
			| error NEWLINE			{}
			| Dec NEWLINE 			{}
			;
	Expr	: Expr ADD Term 		{
										driver.addBinaryOperator(Expr::ADD);
									}
			| Expr SUB Term			{
										driver.addBinaryOperator(Expr::SUB);
									}
			| Term 					{}
			;
	
	Term 	: Term MULTI NUMBER 	{
										int number = atoi($3.c_str());
										driver.addIntegerLiteral(number);
										driver.addBinaryOperator(Expr::MUL);
									}
			| Term DIVIDE NUMBER	{
										driver.addBinaryOperator(Expr::DIV);
									}
			| NUMBER 				{
										int number = atoi($1.c_str());
										driver.addIntegerLiteral(number);
									}
			;

	Dec		: varType ID			{}
			;
	
	varType : INT					{}
			| FLOAT					{}
			;
	
	Function : LET ID ORB args CRB Stmt		{
												driver.add_function_def($2.c_str());
											}

	args	: ID					{
										driver.add_id($1.c_str());
									} 
			


	
%%
void 
TGC::TGC_Parser::error( const location_type &l, 
						const std::string &err_message )
{
   std::cerr << "Error: " << err_message << " at " << l << "\n";
}