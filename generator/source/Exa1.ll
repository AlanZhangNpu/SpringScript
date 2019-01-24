%{ 

#include "Exa1Scanner.h"
#include <stdio.h>
#include <stdlib.h>
#include "Spring.h"

%}

%option prefix="Exa1" noyywrap nodefault yylineno c++

EXP ([Ee][-+]?[0-9]+)
LABEL [a-zA-Z_][a-zA-Z_0-9]*

%% 
"+" |
"-" |
"*" |
"/" |
"%"		{ yylloc->step(); 	yylloc->columns(); 		return yytext[0]; }
"**"	{ yylloc->step(); 	yylloc->columns(2);		return TOKENS::EXP; }
"++"	{ yylloc->step(); 	yylloc->columns(2);		return TOKENS::INCREMENT; }
"--" 	{ yylloc->step(); 	yylloc->columns(2);		return TOKENS::DECREMENT; }

">"  	{ yylloc->step(); 	yylloc->columns();		return TOKENS::CMP_G; } 
"<"  	{ yylloc->step(); 	yylloc->columns();		return TOKENS::CMP_L; }
">=" 	{ yylloc->step(); 	yylloc->columns(2);		return TOKENS::CMP_GE; }
"<=" 	{ yylloc->step(); 	yylloc->columns(2);		return TOKENS::CMP_LE; }
"==" 	{ yylloc->step(); 	yylloc->columns(2);		return TOKENS::CMP_E; }
"!=" 	{ yylloc->step(); 	yylloc->columns(2);		return TOKENS::CMP_NE; }

"&&" 	{ yylloc->step(); 	yylloc->columns(2);		return TOKENS::LOGICAL_AND; }
"||" 	{ yylloc->step(); 	yylloc->columns(2);		return TOKENS::LOGICAL_OR; }
"!"  	{ yylloc->step(); 	yylloc->columns();		return TOKENS::LOGICAL_NOT; }

"&"  	{ yylloc->step(); 	yylloc->columns();		return TOKENS::BIT_AND; }
"|"  	{ yylloc->step(); 	yylloc->columns();		return TOKENS::BIT_OR; }
"^"  	{ yylloc->step(); 	yylloc->columns();		return TOKENS::BIT_XOR; }
"~"  	{ yylloc->step(); 	yylloc->columns();		return TOKENS::BIT_COM; }
"<<" 	{ yylloc->step(); 	yylloc->columns(2);		return TOKENS::BIT_SHIFT_LEFT; }
">>" 	{ yylloc->step(); 	yylloc->columns(2);		return TOKENS::BIT_SHIFT_RIGHT; }

":"  	{ yylloc->step(); 	yylloc->columns();		return ':'; }
"="  	{ yylloc->step(); 	yylloc->columns();		return '='; }

"+=" 	{ yylloc->step(); 	yylloc->columns(2);		yylval->m_Int = 219; return TOKENS::COM_ASSIGN; }
"-=" 	{ yylloc->step(); 	yylloc->columns(2);		yylval->m_Int = 220; return TOKENS::COM_ASSIGN; }
"*=" 	{ yylloc->step(); 	yylloc->columns(2);		yylval->m_Int = 221; return TOKENS::COM_ASSIGN; }
"**=" 	{ yylloc->step(); 	yylloc->columns(3);		yylval->m_Int = 222; return TOKENS::COM_ASSIGN; }
"/=" 	{ yylloc->step(); 	yylloc->columns(2);		yylval->m_Int = 223; return TOKENS::COM_ASSIGN; }
"%=" 	{ yylloc->step(); 	yylloc->columns(2);		yylval->m_Int = 224; return TOKENS::COM_ASSIGN; }
"&=" 	{ yylloc->step(); 	yylloc->columns(2);		yylval->m_Int = 225; return TOKENS::COM_ASSIGN; }
"|=" 	{ yylloc->step(); 	yylloc->columns(2);		yylval->m_Int = 226; return TOKENS::COM_ASSIGN; }
"^=" 	{ yylloc->step(); 	yylloc->columns(2);		yylval->m_Int = 227; return TOKENS::COM_ASSIGN; }
"<<=" 	{ yylloc->step(); 	yylloc->columns(3);		yylval->m_Int = 228; return TOKENS::COM_ASSIGN; }
">>=" 	{ yylloc->step(); 	yylloc->columns(3);		yylval->m_Int = 229; return TOKENS::COM_ASSIGN; }

"#" |
"(" |
")" | 
"{" | 
"}" | 
"[" | 
"]" |
"," |
";" |
"?" |
"." |
"_"  		{ yylloc->step(); yylloc->columns();	return yytext[0]; }
"->" 		{ yylloc->step(); yylloc->columns(2);	return TOKENS::ARROW; }

"if" |
"如果" 		{ yylloc->step(); yylloc->columns(strlen(yytext));	return TOKENS::IF; }

"else" |
"否则" 		{ yylloc->step(); yylloc->columns(strlen(yytext));	return TOKENS::ELSE; }

"while" |
"当" 	{ yylloc->step(); yylloc->columns(strlen(yytext));	return TOKENS::WHILE; }

"for" |
"对于每个"	{ yylloc->step(); yylloc->columns(strlen(yytext));	return TOKENS::FOR; }

"in" |
"在" 		{ yylloc->step(); yylloc->columns(strlen(yytext));	return TOKENS::IN; }

"switch" 	{ yylloc->step(); yylloc->columns(strlen(yytext));	return TOKENS::SWITCH; }

"loop" |
"循环" 		{ yylloc->step(); yylloc->columns(strlen(yytext));	return TOKENS::LOOP; }

"return" |
"返回" 	{ yylloc->step(); yylloc->columns(strlen(yytext));	return TOKENS::RETURN; }

"break" |
"跳出" 	{ yylloc->step(); yylloc->columns(strlen(yytext));	return TOKENS::BREAK; }

"continue" |
"下一次" { yylloc->step(); yylloc->columns(strlen(yytext));	return TOKENS::CONTINUE; }

"exit" |
"结束" 		{ yylloc->step(); yylloc->columns(strlen(yytext));	return TOKENS::EXIT; }
"debug" 	{ yylloc->step(); yylloc->columns(strlen(yytext));	return TOKENS::DEBUG; }

"import" |
"导入" 	{ yylloc->step(); yylloc->columns(strlen(yytext));	return TOKENS::USING; }

"new" |
"新建" 		{ yylloc->step(); yylloc->columns(strlen(yytext));	return TOKENS::NEW; }

"nil" |
"空" 		{ yylloc->step(); yylloc->columns(strlen(yytext));	return TOKENS::NIL; }
"true" |
"真" 		{ yylloc->step(); yylloc->columns(strlen(yytext));	return TOKENS::TRUE; }
"false" |
"假" 		{ yylloc->step(); yylloc->columns(strlen(yytext));	return TOKENS::FALSE; }

"let" |
"var" |
"变量" 		{ yylloc->step(); yylloc->columns(strlen(yytext));	return TOKENS::LET; }

"func" |
"函数" 		{ yylloc->step(); yylloc->columns(strlen(yytext));	return TOKENS::FUNC; }

"obj" |
"class" |
"对象" 		{ yylloc->step(); yylloc->columns(strlen(yytext));	return TOKENS::OBJECT; }


[0-9]+ { yylloc->step(); yylloc->columns(strlen(yytext)); 				yylval->m_Int = atoi(yytext); 	return TOKENS::T_INT;}

[0-9]+"."[0-9]*{EXP}? |
"."?[0-9]+{EXP}? { yylloc->step(); yylloc->columns(strlen(yytext)); 	yylval->m_Double = atof(yytext); return TOKENS::REAL;}

{LABEL}	{ 
	int len = strlen(yytext);
	yylloc->step(); yylloc->columns(len);
	yylval->m_id = (char *)malloc((len+1)*sizeof(char));
    strcpy(yylval->m_id, yytext);
	return TOKENS::ID; 
}

[u4e00-u9fa5] {
	std::cout << "发现中文了";
	int len = strlen(yytext);
	yylloc->step(); yylloc->columns(len);
}

^[\u4e00-\u9fa5_a-zA-Z0-9]+$ {
	std::cout << "发现中文";
	int len = strlen(yytext);
	yylloc->step(); yylloc->columns(len);
}

\"[^\"\n]*\" {
	int len = strlen(yytext);
	yylval->m_id = (char *)malloc((len+1)*sizeof(char));
    strcpy(yylval->m_id, yytext);	
	yylloc->step(); yylloc->columns(len);
	return TOKENS::STRING; 
}

[\n] { yylloc->step(); yylloc->lines();		return TOKENS::EOL; }

"\\\r" 		{ yylloc->step(); 	yylloc->lines(); }
"\\\n" 		{ yylloc->step(); 	yylloc->lines(); }
"\\\r\n" 	{ yylloc->step(); 	yylloc->lines(); }
"\\\n\r" 	{ yylloc->step(); 	yylloc->lines(); }

[ \t] 		{ yylloc->step(); 	yylloc->columns(1); }
"//".* 		{ yylloc->step(); 	yylloc->columns(strlen(yytext)); }
"'''"[^\']*"'''" |
\"\"\"[^\']*\"\"\" {
	yylloc->step(); 
	std::string str = yytext;
	unsigned nCount = std::count(std::begin(str), std::end(str), '\n');
	unsigned lastLineCol = str.length();
	if(nCount != 0)
		lastLineCol = lastLineCol - str.find_last_of('\n') - 1;
	yylloc->lines(nCount);
	yylloc->columns(lastLineCol);
	//qDebug() << yytext; 
}

. { 
	yylloc->step();
	yylloc->columns(strlen(yytext));
	std::string tip(yytext);
	tip = "Unknown character: " + tip;
	std::cout << tip;
	/*if(Spring::springIOHelper != nullptr)
		Spring::springIOHelper->onError(SpringErrorCode::SPRING_ERROR_LEXICAL_ERROR, tip, lineno());*/
} 

%%
/*由于我们在Exa1Scanner.h中重新定义了YYDDECL，因此在此处必须对Exa1FlexLexer::yylex()给予定义*/
int Exa1FlexLexer::yylex()
{
    std::cout << "can not use Exa1FlexLexer::yylex()" << std::endl;
	return 0;
}
