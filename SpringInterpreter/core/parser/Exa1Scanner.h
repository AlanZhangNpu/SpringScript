#pragma once
#include <iostream>
#include "Exa1.tab.hh"

typedef Exa1::Exa1Parser::token TOKENS;

#define YY_DECL int Exa1::Exa1Scanner::yylex()

#ifndef yyFlexLexer
#define yyFlexLexer Exa1FlexLexer
#include "FlexLexer.h"
#endif // !yyFlexLexer

namespace Exa1 {
    class Exa1Scanner : public Exa1FlexLexer
	{
	public:
        Exa1Scanner() : Exa1FlexLexer(0, 0) {
        }
        virtual ~Exa1Scanner() {}
		virtual int yylex(Exa1::Exa1Parser::semantic_type *lval) {
			yylval = lval;
			return yylex();
		}

	private:
        virtual int yylex();
		Exa1::Exa1Parser::semantic_type *yylval;
	};
}
