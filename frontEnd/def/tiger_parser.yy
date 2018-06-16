%skeleton "lalr1.cc"
%require  "3.0"
%debug 
%defines 
%define api.namespace {Tiger}
%define parser_class_name {Tiger_Parser}

%code requires{
	   namespace Tiger {
		  class Tiger_Driver;
		  class Tiger_Scanner;
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

%parse-param { Tiger_Scanner &scanner  }
%parse-param { Tiger_Driver  &driver  }

%code{
	#include <iostream>
	#include <cstdlib>
	#include <fstream>
   
	/* include for all driver functions */
	#include "../Tiger_Driver.hpp"

	#undef yylex
	#define yylex scanner.yylex
}

%define api.value.type variant
%define parse.assert

%token					END    0     "end of file"
%token					NEWLINE
%token					COMMENT
%token					VAR
%token					LET
%token					TYPE
%token					IF
%token					THEN
%token					FOR
%token					WHILE
%token					LBRAC
%token					RBRAC
%token					LPAREN
%token					RPAREN
%token					NIL
%token					ARRAY
%token					ELSE
%token					TO
%token					DO
%token					IN
%token					ENDD
%token					OF
%token					BREAK
%token					IMPORT
%token					PRIMITIVE
%token					TRY
%token					FUNCTION

%token					CLASS
%token					EXTENDS
%token					METHOD
%token					NEW

%token					ADD
%token					SUB
%token					MULTI
%token					DIVIDE
%token					EQ
%token					ASSIGNEQ
%token					LOWER
%token					GREATER
%token					LOWEREQ
%token					GREATEREQ
%token					AND
%token					OR
%token					COLON
%token					SEMICOLON
%token					BECOMES
%token					DOT
%token					COMMA

%token  <std::string>   STRING_ID
%token	<std::string>	NUMBER
%token	<std::string>	TYPE_ID
%token  <std::string>	ID

%locations
%define parse.error verbose

// %destructor {printf("token %d.%d discarded\n",@$.begin.line,@$.begin.column);} <*> 

/* Function : LET ID ORB args CRB Stmt		{
												driver.add_function_def($2.c_str());
											} */

%%
	Goal 	: Goal Stmt 			{}
			| Stmt 					{}
			| Goal FunctionDecl		{}
			| FunctionDecl			{}
			| END 					{}
			;
	

	Stmt 	: Expr AllowNewline 			{std::cout << "Stmt\n"; }
			| error AllowNewline			{}
			| SeqExpr AllowNewline			{std::cout << "SeqExpr \n";}
			| IfStmt AllowNewline			{std::cout << "If Stmt\n";}
			| ForStmt AllowNewline			{std::cout << "For Stmt\n";}
			| Declaration AllowNewline		{std::cout << "Declaration Stmt\n";}
			| WhileStmt AllowNewline		{std::cout << "While Stmt\n";}
			| ArrayDecl AllowNewline		{std::cout << "Array Decl\n";}
			| ArrayBuild AllowNewline		{std::cout << "Array Build\n";}
			| FunctionCall AllowNewline		{std::cout << "Function call\n";}
			| STRING_ID						{	
												std::cout << "String value\n";

											}
			| NUMBER						{
												int number = atoi($1.c_str());
												driver.addIntegerLiteral(number);
												std::cout << "number\n";
											}
			;

	Expr	: Expr ADD Term 		{
										std::cout<<"expr\n";
										driver.addBinaryOperator(Expr::ADD);
										
									}
			| Expr SUB Term			{
										driver.addBinaryOperator(Expr::SUB);
									}
			| Term 					{}
			;
	
	Term 	: Term MULTI NUMBER 	{
										driver.addBinaryOperator(Expr::MUL);
									}
			| Term DIVIDE NUMBER	{
										driver.addBinaryOperator(Expr::DIV);
									}
			| NUMBER 				{
										int number = atoi($1.c_str());
										driver.addIntegerLiteral(number);
										std::cout << "number\n";
									}
			| ID					{
										driver.add_id($1.c_str(),"void");
										std::cout << "Identifier\n";
									}
			;
	
	Declaration		: TypeDecl		{}
					| VarDecl		{}
					;
	
	SeqExpr			: LPAREN AllowNewline Stmts	RPAREN		{}
					;
	
	Stmts			: Stmts  Stmt	{}
					| Stmt			{}
					;

	FunctionDecl 	: FUNCTION ID LPAREN RPAREN ASSIGNEQ AllowNewline Stmt 						{
																									std::cout << "FunctionDec No return type \n";
																									driver.addToBodyStmt();
																									driver.add_function_def($2.c_str(),"void");
																								}
				 	| FUNCTION ID LPAREN RPAREN COLON TYPE_ID ASSIGNEQ AllowNewline Stmt 		{	
																									std::cout <<"FunctionDef has return type\n";
																									driver.addToBodyStmt();
																									driver.add_function_def($2.c_str(),$6.c_str());
																								}
				 	;


	Args			: ID COLON TYPE_ID COMMA Args				{std::cout<<"args\n";}	  
					| ID COLON TYPE_ID							{
																	std::cout<<"args last\n";
																	driver.add_id($1.c_str(),$3.c_str()); 
																}
					| %empty									{std::cout<<"no arg\n";}
					;

	VarDecl			: VAR ID BECOMES Stmt						{
																	std::cout << "ID type int\n";
																}

					| VAR ID COLON TYPE_ID BECOMES Stmt			{
																	std::cout << "ID with type\n";
																	driver.add_id($2.c_str(),$4.c_str());
																}

					;
	

	AllowNewline	: NEWLINE 		{}
					| %empty		{}
					;

	IfStmt			: IF Stmt THEN Stmt ELSE Stmt			{std::cout<<"if else stmt\n";}
					| IF Stmt THEN Stmt						{std::cout<<"only if stmt\n";}
					;
					
	ForStmt			: FOR ID BECOMES Stmt TO Stmt DO Stmt	{std::cout<< "for stmt\n";}
					;
	
	WhileStmt		: WHILE Stmt DO Stmt			{}
					;

	
	ArrayDecl		: ARRAY OF TYPE_ID				{}
					;

	ArrayBuild		: VAR ID BECOMES ID LBRAC Stmt RBRAC OF Stmt	{}
					;

	TypeDecl		: TYPE ID ASSIGNEQ TYPE_ID		{}
					;
	

	FunctionCall	: ID LPAREN Args RPAREN			{}
					;

	
%%
void 
Tiger::Tiger_Parser::error( const location_type &l, 
						const std::string &err_message )
{
   std::cerr << "Error: " << err_message << " at " << l << "\n";
}