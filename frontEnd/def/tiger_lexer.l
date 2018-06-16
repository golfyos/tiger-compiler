/*  CS335  Phase 1       */
/*  Yossapol  5709680051  */
/*  Tiger Scanner        */

%{

    #include <string>
    /* Implementation of yyFlexScanner */ 
    #include "../tiger_scanner.hpp"
    #undef  YY_DECL
    #define YY_DECL int Tiger::Tiger_Scanner::yylex( Tiger::Tiger_Parser::semantic_type * const lval, Tiger::Tiger_Parser::location_type *loc )

    /* typedef to make the returns for the tokens shorter */
    using token = Tiger::Tiger_Parser::token;

    /* define yyterminate as this instead of NULL */
    #define yyterminate() return( token::END )

    /* msvc2010 requires that we exclude this header file. */
    #define YY_NO_UNISTD_H

    /* update location on matching */
    #define YY_USER_ACTION loc->step(); loc->columns(yyleng);

    //%option reentrant stack noyywrap never-interactive
%}
%option debug
%option yyclass="Tiger::Tiger_Scanner"
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
EQ <>
ASSIGNEQ =
LW <
GT >
LEQ <=
GEQ >=
AND &
OR \|
COLON :
SEMICOLON ;
BECOMES :=
COMMA ,

SINGLEQUOTE (\')
DOUBLEQUOTE (\")
DOT \.

typeID (int|string)
STRINGID (\"[a-zA-Z0-9\.\\W\\s\\n\\t\\^c\\ddd\\\ ]*\")

%%
%{
	yylval = lval;
%}

\n              {
                    loc->lines();
			        return( token::NEWLINE );
                }
[ \t]           {}
{COMMENT}       { return( token::COMMENT );  }

{VAR}           { return( token::VAR );      }
{TRY}           { return( token::TRY );      }
{LET}           { return( token::LET );      }
{TYPE}          { return( token::TYPE );     }
{IF}            { return( token::IF );       }
{THEN}          { return( token::THEN );     }
{FOR}           { return( token::FOR );      }
{WHILE}         { return( token::WHILE );    }
{LBRAC}         { return( token::LBRAC );    }
{RBRAC}         { return( token::RBRAC );    }
{LPAREN}        { return( token::LPAREN );   }
{RPAREN}        { return( token::RPAREN );   }
{NIL}           { return( token::NIL );      }
{ARRAY}         { return( token::ARRAY );    }
{ELSE}          { return( token::ELSE );     }
{TO}            { return( token::TO );       }
{DO}            { return( token::DO );       }
{IN}            { return( token::IN );       }
{END}           { return( token::ENDD );     }
{OF}            { return( token::OF );       }   
{BREAK}         { return( token::BREAK );    }
{IMPORT}        { return( token::IMPORT );   }
{PRIMITIVE}     { return( token::PRIMITIVE );}
{FUNCTION}      { return( token::FUNCTION ); }

{CLASS}         { return( token::CLASS );    }
{EXTENDS}       { return( token::EXTENDS );  }
{METHOD}        { return( token::METHOD );   }
{NEW}           { return( token::NEW );      }

{PLUS}          { return( token::ADD );      }
{MINUS}         { return( token::SUB );      }
{MULTI}         { return( token::MULTI );    }
{DIVIDE}        { return( token::DIVIDE );   }
{EQ}            { return( token::EQ );       }
{ASSIGNEQ}      { return( token::ASSIGNEQ);  }
{LW}            { return( token::LOWER );    }
{GT}            { return( token::GREATER );  }
{LEQ}           { return( token::LOWEREQ );  }
{GEQ}           { return( token::GREATEREQ );}
{AND}           { return( token::AND );      }
{OR}            { return( token::OR );       }
{COLON}         { return( token::COLON );    }
{SEMICOLON}     { return( token::SEMICOLON );}
{BECOMES}       { return( token::BECOMES );  }
{COMMA}         { return( token::COMMA);     }
{DOT}           { return( token::DOT );      }



{STRINGID}      {
                    yylval->build< std::string >( yytext );
                    return( token::STRING_ID );
                }
{DIGIT}+        {
                    yylval->build< std::string >( yytext );
                    return( token::NUMBER );
                }
{typeID}        {
                    yylval->build< std::string >( yytext );
                    return( token::TYPE_ID );
                }

[a-zA-Z]{ID}*   {
                    yylval->build< std::string >( yytext );
                    return( token::ID );
                }

%{
// \n cout << "NEWLINE" << endl;
// [ \t] cout << "";
// {COMMENT} cout << "" << endl;

// {VAR} cout << "VAR" << endl;
// {TRY} cout << "try" << endl;
// {LET} cout << "let" << endl;
// {TYPE} cout << "TYPE" << endl;
// {IF} cout << "IF" << endl;
// {THEN} cout << "THEN" << endl;
// {FOR} cout << "FOR" << endl;
// {WHILE} cout << "WHILE" << endl;
// {LBRAC} cout << "LBRAC" << endl;
// {RBRAC} cout << "RBRAC" << endl;
// {LPAREN} cout << "LPAREN" << endl;
// {RPAREN} cout << "RPAREN" << endl;
// {NIL} cout << "NIL" << endl;
// {ARRAY} cout << "ARRAY" << endl;
// {ELSE} cout << "ELSE" << endl;
// {TO} cout << "TO" << endl;
// {DO} cout << "DO" << endl;
// {IN} cout << "IN" << endl;
// {END} cout << "END" << endl;
// {OF} cout << "OF" << endl;
// {BREAK} cout << "BREAK" << endl;
// {IMPORT} cout << "IMPORT" << endl;
// {PRIMITIVE} cout << "PRIMITIVE" << endl;
// {FUNCTION} cout << "FUNCTION" << endl;

// {CLASS} cout << "CLASS" << endl;
// {EXTENDS} cout << "EXTENDS" << endl;
// {METHOD} cout << "METHOD" << endl;
// {NEW} cout << "NEW" << endl;

// {PLUS} cout << "PLUS" << endl;
// {MINUS} cout << "MINUS" << endl;
// {MULTI} cout << "MULTI" << endl;
// {DIVIDE} cout << "DIVIDE" << endl;
// {EQ} cout << "EQ" << endl;
// {LW} cout << "LOWER" << endl;
// {GT} cout << "GREATER" << endl;
// {LEQ} cout << "LOWEREQ" << endl;
// {GEQ}  cout << "GREATEREQ" << endl;
// {AND} cout << "AND" << endl;
// {OR} cout << "OR" << endl;
// {COLON} cout << "COLON" << endl; 
// {SEMICOLON} cout << "SEMICOLON" << endl;
// {BECOMES} cout << "BECOMES" << endl;
// {DOT} cout << "DOT" << endl;


// {STRINGID} cout << "STRING(" << yytext << ")" << endl;
// {DIGIT}+ cout << "INTEGER(" << yytext << ")" << endl;
// {typeID} cout << "typeID(" << yytext << ")" << endl;

// [a-zA-Z]{ID}* cout << "ID("<< yytext << ")" << endl;
%}

%%
     
