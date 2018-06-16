%{
	#include <string>
	/* Implementation of yyFlexScanner */ 
	#include "../tgc_scanner.hpp"
	#undef  YY_DECL
	#define YY_DECL int TGC::TGC_Scanner::yylex( TGC::TGC_Parser::semantic_type * const lval, TGC::TGC_Parser::location_type *loc )

	/* typedef to make the returns for the tokens shorter */
	using token = TGC::TGC_Parser::token;

	/* define yyterminate as this instead of NULL */
	#define yyterminate() return( token::END )

	/* msvc2010 requires that we exclude this header file. */
	#define YY_NO_UNISTD_H

	/* update location on matching */
	#define YY_USER_ACTION loc->step(); loc->columns(yyleng);
%}

%option debug
%option yyclass="TGC::TGC_Scanner"
%option noyywrap
%option c++

COMMENT (\/\*)(.*\n*.*)*(\*\/)
VAR var
ID [a-zA-Z0-9_]

DIGIT [0-9]
FUNCTION function
TYPE type
IF if
THEN then
FOR for
WHILE while
LBRAC \[
RBRAC \]
LPAREN \(
RPAREN \)
NIL nil
ARRAY array
ELSE else
TO to
DO do
IN in
END end
OF of
BREAK break
IMPORT import
PRIMITIVE primitive
LET let
TRY try

RESERVED function|type|if|then|for|while|nil|array|else|to|do|in|end|of|break|import|primitive|let|try

CLASS class
EXTENDS extends
METHOD method
NEW new

OBJECT_RESERVED class|extends|method|new

PLUS \+
MINUS -
MULTI \*
DIVIDE \/
EQ (=|<>)
LW <
GT >
LEQ <=
GEQ >=
AND &
OR \|
COLON :
SEMICOLON ;
BECOMES :=

SINGLEQUOTE (\')
DOUBLEQUOTE (\")
DOT \.

typeID (int|string)
STRINGID (\"[a-zA-Z0-9\.\\W\\s\\n\\t\\^c\\ddd\\\ ]*\")

%%
%{
	/** Code executed at the beginning of yylex **/
	yylval = lval;
%}

"("			{return( token::ORB);}

")"			{return( token::CRB);}

","			{return( token::COMMA);}

"+"			{return( token::ADD);}
"-"			{return (token::SUB);}
"*"			{return (token::MULTI);}
"/"			{return (token::DIVIDE);}

"int" 		{return (token::INT);}
"float" 	{return(token::FLOAT);}

"let" 		{return (token::LET); }


[0-9]+		{
				yylval->build< std::string >( yytext );
				return ( token::NUMBER);
			}

\n			{
				// Update line number
				loc->lines();
				return( token::NEWLINE );
			}

[a-zA-Z]+   {
               /**
                * Section 10.1.5.1 of the 3.0.2 Bison Manual says the 
                * following should work:
                * yylval.build( yytext );
                * but it doesn't.
                * ref: http://goo.gl/KLn0w2
                */
               yylval->build< std::string >( yytext );
               return( token::ID );
            }
%%
