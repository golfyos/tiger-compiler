#pragma once

#if ! defined(yyFlexLexerOnce)
#include <FlexLexer.h>
#endif

#include "def/tiger_parser.tab.hh"
#include "def/location.hh"

namespace Tiger {
	class Tiger_Scanner :public yyFlexLexer {
	public:
		Tiger_Scanner(std::istream *in) : yyFlexLexer(in)
		{
		};

		virtual ~Tiger_Scanner() {};

		using FlexLexer::yylex;

		virtual
		int yylex(Tiger::Tiger_Parser::semantic_type * const lval,
				Tiger::Tiger_Parser::location_type *location);

	private:
		Tiger_Parser::semantic_type *yylval = nullptr;
	};
}