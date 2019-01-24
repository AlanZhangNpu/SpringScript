%require"2.3"
%skeleton"lalr1.cc"
%locations
%defines
%define namespace "Exa1"
%define parser_class_name "Exa1Parser"
%parse-param {Exa1::Exa1Scanner &scanner}

%code requires
{
namespace Exa1{class Exa1Scanner;}
}

%{
#include <stdio.h>
#include <vector>
#include <memory>
#include "Spring.h"
#include "Exa1Scanner.h"
#include "./core/expression/SpringExpression.h"
#include "./core/expression/SpringExpressionList.h"
#include "./core/statement/SpringStatement.h"
#include "./core/statement/SpringParagraph.h"
using namespace spr;

extern int yylineno;

#undef yylex
#define yylex scanner.yylex
%}

%union 
{
     int m_Int;
	 double m_Double;	 
	 char* m_id;
	 spr::SpringBaseExpression* exp;
     spr::SpringExpressionList *expList;
	 spr::SpringBaseStatement* stmt;
	 spr::SpringParagraph* paragraph;
};

// 运算符
%token EXP INCREMENT DECREMENT
%token CMP_G CMP_L CMP_GE CMP_LE CMP_E CMP_NE
%token LOGICAL_AND LOGICAL_OR LOGICAL_NOT
%token BIT_AND BIT_OR BIT_XOR BIT_COM BIT_SHIFT_LEFT BIT_SHIFT_RIGHT

// 有属性运算符
%token<m_Int> COM_ASSIGN

// 无属性的记号
%token IF ELSE WHILE END FOR IN LOOP SWITCH USING
%token ARROW
%token RETURN BREAK CONTINUE DEBUG EXIT TRUE FALSE FUNC
%token NEW OBJECT LET NIL EOL

// 有属性的记号
%token<m_id> ID STRING WHY
%token<m_Int> T_INT 
%token<m_Double> REAL
%type<exp> exp ID_list_with_default_value 
%type<paragraph> stmt_list object_body_stmts block
%type<stmt> stmt declaration_stmt operator_overload_stmt

%type<expList> exp_list zero_or_more_exp
%type<m_Int> end_of_stmt

// 结合性与优先级
%nonassoc IF
%nonassoc ELSE

%right ARROW
%right COM_ASSIGN
%right '?' ':'
%left LOGICAL_OR
%left LOGICAL_AND
%left BIT_OR
%left BIT_XOR
%left BIT_AND
%nonassoc CMP_E CMP_NE
%nonassoc CMP_G CMP_L CMP_GE CMP_LE
%left BIT_SHIFT_LEFT BIT_SHIFT_RIGHT
%left '+' '-'
%left '*' '/' '%'
%right '#' INCREMENT DECREMENT LOGICAL_NOT BIT_COM
%right EXP
%left '[' ']' '(' ')' '.'

%start program
%%

program: stmt_list { 
	
		SpringParagraph* program = (yysemantic_stack_[(1) - (1)].paragraph);
        try{
            program->run(env);
        }
        catch(SpringException &runtimeError)
        {
            env.springIOHelper->onError(runtimeError.getLineNo(), runtimeError.toString());
        }
        catch(std::exception &except)
        {
            std::string errorMsg = except.what();
            env.springIOHelper->onError(-1, errorMsg);
        }
        delete program;
	}

stmt: USING ID end_of_stmt { $$ = new SpringImportStatement($2, $3); }
 | declaration_stmt { $$ = $1; }
 | exp_list '=' exp_list end_of_stmt{ $$ = new SpringAssignStatement($1, $3, $4); }
 | exp end_of_stmt { $$ = new SpringExpressionStatement($1, $2); zzzz "tttt"; zzzz @1; }

 | BREAK end_of_stmt { $$ = new SpringJumpStatement('b', $2); }
 | CONTINUE end_of_stmt { $$ = new SpringJumpStatement('c', $2); }
 | DEBUG end_of_stmt { $$ = new SpringJumpStatement('d', $2); }
 | EXIT end_of_stmt { $$ = new SpringJumpStatement('e', $2); }
 | RETURN zero_or_more_exp end_of_stmt { $$ = new SpringJumpStatement($2, $3); }

 | IF exp block ELSE block { $$ = new SpringControlFlowStatement($2, $3, $5, $3->getFirstStmtLineNo()); }
 | IF exp block { $$ = new SpringControlFlowStatement('i', $2, $3, $3->getFirstStmtLineNo()); }
 | WHILE exp block { $$ = new SpringControlFlowStatement('w', $2, $3, $3->getFirstStmtLineNo()); }
 | LOOP exp block { $$ = new SpringControlFlowStatement('l', $2, $3, $3->getFirstStmtLineNo()); }
 | FOR ID IN exp block { $$ = new SpringControlFlowStatement(new SpringIDExpression($2), $4, $5, $5->getFirstStmtLineNo()); }  
 ;

declaration_stmt: end_of_stmt { $$ = new SpringDeclarationStatement(); }
 | LET ID_list_with_default_value end_of_stmt { $$ = new SpringDeclarationStatement(dynamic_cast<SpringIDListExpression*>$2, $3); }
 | ID ':' exp end_of_stmt { $$ = new SpringDeclarationStatement(new SpringIDListExpression(new SpringIDExpression($1, $3)), $4); }
 | FUNC ID '(' ID_list_with_default_value ')' '{' stmt_list '}' { $$ = new SpringDeclarationStatement(new SpringIDListExpression(new SpringIDExpression($2, new SpringConstantExpression($4, $7))), $7->getFirstStmtLineNo()); }
 | FUNC ID '(' ')' '{' stmt_list '}' { $$ = new SpringDeclarationStatement(new SpringIDListExpression(new SpringIDExpression($2, new SpringConstantExpression(new SpringIDListExpression(), $6))), $6->getFirstStmtLineNo()); }
 | OBJECT ID '{' object_body_stmts '}' { $$ = new SpringDeclarationStatement(new SpringIDListExpression(new SpringIDExpression($2, new SpringObjectDefinitionExpression($4))), $4->getFirstStmtLineNo()); }
 | OBJECT ID ARROW ID '{' object_body_stmts '}' { /*TODO*/ }
 ;

//运算符重载
operator_overload_stmt: '+' ID '{' stmt_list '}' {
	auto id = new SpringIDExpression("+", new SpringConstantExpression(new SpringIDListExpression(new SpringIDExpression($2)), $4));
    $$ = new SpringDeclarationStatement(new SpringIDListExpression(id), $4->getFirstStmtLineNo()); }
 | '-' ID '{' stmt_list '}' {
	auto id = new SpringIDExpression("-", new SpringConstantExpression(new SpringIDListExpression(new SpringIDExpression($2)), $4));
    $$ = new SpringDeclarationStatement(new SpringIDListExpression(id), $4->getFirstStmtLineNo()); }
 | '*' ID '{' stmt_list '}' {
	auto id = new SpringIDExpression("*", new SpringConstantExpression(new SpringIDListExpression(new SpringIDExpression($2)), $4));
    $$ = new SpringDeclarationStatement(new SpringIDListExpression(id), $4->getFirstStmtLineNo()); }
 | EXP ID '{' stmt_list '}' {
	auto id = new SpringIDExpression("**", new SpringConstantExpression(new SpringIDListExpression(new SpringIDExpression($2)), $4));
    $$ = new SpringDeclarationStatement(new SpringIDListExpression(id), $4->getFirstStmtLineNo()); }
 | '/' ID '{' stmt_list '}' {
	auto id = new SpringIDExpression("/", new SpringConstantExpression(new SpringIDListExpression(new SpringIDExpression($2)), $4));
    $$ = new SpringDeclarationStatement(new SpringIDListExpression(id), $4->getFirstStmtLineNo()); }
 | '%' ID '{' stmt_list '}' {
	auto id = new SpringIDExpression("%", new SpringConstantExpression(new SpringIDListExpression(new SpringIDExpression($2)), $4));
    $$ = new SpringDeclarationStatement(new SpringIDListExpression(id), $4->getFirstStmtLineNo()); }

 | CMP_G ID '{' stmt_list '}' {
	auto id = new SpringIDExpression(">", new SpringConstantExpression(new SpringIDListExpression(new SpringIDExpression($2)), $4));
    $$ = new SpringDeclarationStatement(new SpringIDListExpression(id), $4->getFirstStmtLineNo()); }
 | CMP_L ID '{' stmt_list '}' {
	auto id = new SpringIDExpression("<", new SpringConstantExpression(new SpringIDListExpression(new SpringIDExpression($2)), $4));
    $$ = new SpringDeclarationStatement(new SpringIDListExpression(id), $4->getFirstStmtLineNo()); }
 | CMP_GE ID '{' stmt_list '}' {
	auto id = new SpringIDExpression(">=", new SpringConstantExpression(new SpringIDListExpression(new SpringIDExpression($2)), $4));
    $$ = new SpringDeclarationStatement(new SpringIDListExpression(id), $4->getFirstStmtLineNo()); }
 | CMP_LE ID '{' stmt_list '}' {
	auto id = new SpringIDExpression("<=", new SpringConstantExpression(new SpringIDListExpression(new SpringIDExpression($2)), $4));
    $$ = new SpringDeclarationStatement(new SpringIDListExpression(id), $4->getFirstStmtLineNo()); }
 | CMP_E ID '{' stmt_list '}' {
	auto id = new SpringIDExpression("==", new SpringConstantExpression(new SpringIDListExpression(new SpringIDExpression($2)), $4));
    $$ = new SpringDeclarationStatement(new SpringIDListExpression(id), $4->getFirstStmtLineNo()); }
 | CMP_NE ID '{' stmt_list '}' {
	auto id = new SpringIDExpression("!=", new SpringConstantExpression(new SpringIDListExpression(new SpringIDExpression($2)), $4));
    $$ = new SpringDeclarationStatement(new SpringIDListExpression(id), $4->getFirstStmtLineNo()); }
	 
 | LOGICAL_AND ID '{' stmt_list '}' {
	auto id = new SpringIDExpression("&&", new SpringConstantExpression(new SpringIDListExpression(new SpringIDExpression($2)), $4));
    $$ = new SpringDeclarationStatement(new SpringIDListExpression(id), $4->getFirstStmtLineNo()); }
 | LOGICAL_OR ID '{' stmt_list '}' {
	auto id = new SpringIDExpression("||", new SpringConstantExpression(new SpringIDListExpression(new SpringIDExpression($2)), $4));
    $$ = new SpringDeclarationStatement(new SpringIDListExpression(id), $4->getFirstStmtLineNo()); }

 | BIT_AND ID '{' stmt_list '}' {
	auto id = new SpringIDExpression("&", new SpringConstantExpression(new SpringIDListExpression(new SpringIDExpression($2)), $4));
    $$ = new SpringDeclarationStatement(new SpringIDListExpression(id), $4->getFirstStmtLineNo()); }
 | BIT_OR ID '{' stmt_list '}' {
	auto id = new SpringIDExpression("|", new SpringConstantExpression(new SpringIDListExpression(new SpringIDExpression($2)), $4));
    $$ = new SpringDeclarationStatement(new SpringIDListExpression(id), $4->getFirstStmtLineNo()); }
 | BIT_XOR ID '{' stmt_list '}' {
	auto id = new SpringIDExpression("^", new SpringConstantExpression(new SpringIDListExpression(new SpringIDExpression($2)), $4));
    $$ = new SpringDeclarationStatement(new SpringIDListExpression(id), $4->getFirstStmtLineNo()); }
 | BIT_SHIFT_LEFT ID '{' stmt_list '}' {
	auto id = new SpringIDExpression("<<", new SpringConstantExpression(new SpringIDListExpression(new SpringIDExpression($2)), $4));
    $$ = new SpringDeclarationStatement(new SpringIDListExpression(id), $4->getFirstStmtLineNo()); }
 | BIT_SHIFT_RIGHT ID '{' stmt_list '}' {
	auto id = new SpringIDExpression(">>", new SpringConstantExpression(new SpringIDListExpression(new SpringIDExpression($2)), $4));
    $$ = new SpringDeclarationStatement(new SpringIDListExpression(id), $4->getFirstStmtLineNo()); }

 // 点运算符重载
 | '.' ID '{' stmt_list '}' {
	auto id = new SpringIDExpression(".", new SpringConstantExpression(new SpringIDListExpression(new SpringIDExpression($2)), $4));
    $$ = new SpringDeclarationStatement(new SpringIDListExpression(id), $4->getFirstStmtLineNo()); }

 // 成员运算符重载
 | '[' ID ']' '{' stmt_list '}' {
	auto id = new SpringIDExpression("[]", new SpringConstantExpression(new SpringIDListExpression(new SpringIDExpression($2)), $5));
    $$ = new SpringDeclarationStatement(new SpringIDListExpression(id), $5->getFirstStmtLineNo()); }

 // 调用运算符重载
 | '(' ')' '{' stmt_list '}' {
	auto id = new SpringIDExpression("()", new SpringConstantExpression($4));
    $$ = new SpringDeclarationStatement(new SpringIDListExpression(id), $4->getFirstStmtLineNo()); }
 | '(' ID_list_with_default_value ')' '{' stmt_list '}' {
	auto id = new SpringIDExpression("()", new SpringConstantExpression($2, $5));
    $$ = new SpringDeclarationStatement(new SpringIDListExpression(id), $5->getFirstStmtLineNo()); }

 // 一元运算符重载
 | '#' '{' stmt_list '}' {
	auto id = new SpringIDExpression("#", new SpringConstantExpression($3));
	$$ = new SpringDeclarationStatement(new SpringIDListExpression(id), $3->getFirstStmtLineNo()); }
 | '-' '{' stmt_list '}' {
	auto id = new SpringIDExpression("---", new SpringConstantExpression($3));
	$$ = new SpringDeclarationStatement(new SpringIDListExpression(id), $3->getFirstStmtLineNo()); }
 | INCREMENT '{' stmt_list '}' {
	auto id = new SpringIDExpression("++", new SpringConstantExpression($3));
	$$ = new SpringDeclarationStatement(new SpringIDListExpression(id), $3->getFirstStmtLineNo()); }
 | DECREMENT '{' stmt_list '}' {
	auto id = new SpringIDExpression("--", new SpringConstantExpression($3));
	$$ = new SpringDeclarationStatement(new SpringIDListExpression(id), $3->getFirstStmtLineNo()); }
 | BIT_COM '{' stmt_list '}' {
	auto id = new SpringIDExpression("~", new SpringConstantExpression($3));
	$$ = new SpringDeclarationStatement(new SpringIDListExpression(id), $3->getFirstStmtLineNo()); }
 | LOGICAL_NOT '{' stmt_list '}' {
	auto id = new SpringIDExpression("!", new SpringConstantExpression($3));
	$$ = new SpringDeclarationStatement(new SpringIDListExpression(id), $3->getFirstStmtLineNo()); }
 ;

end_of_stmt: ';' { $$ = scanner.lineno(); }
 | EOL { $$ = scanner.lineno() - 1; }
 ;

stmt_list: stmt { $$ = new SpringParagraph(); $$->addStmt($1); }
 | stmt_list stmt { $1->addStmt($2); $$ = $1; }
 ;

block: EOL stmt { $$ = new SpringParagraph(); $$->addStmt($2); }
 | '{' stmt_list '}' { $$ = $2; }
 ;
 
object_body_stmts: declaration_stmt { $$ = new SpringParagraph(); $$->addStmt($1); }
 | operator_overload_stmt { $$ = new SpringParagraph(); $$->addStmt($1); }
 | object_body_stmts declaration_stmt { $1->addStmt($2); $$ = $1; }
 | object_body_stmts operator_overload_stmt { $1->addStmt($2); $$ = $1; }
 ;

exp: NIL { $$ = new SpringConstantExpression();}
 | TRUE { $$ = new SpringConstantExpression(true);}
 | FALSE { $$ = new SpringConstantExpression(false);}
 | T_INT { $$ = new SpringConstantExpression($1); }
 | REAL { $$ = new SpringConstantExpression($1); }
 | STRING { $$ = new SpringConstantExpression($1); }

 | FUNC '(' ID_list_with_default_value ')' '{' stmt_list '}' { $$ = new SpringConstantExpression($3, $6); }
 | FUNC '(' ')' '{' stmt_list '}' { $$ = new SpringConstantExpression($5); }
 | FUNC '(' ID_list_with_default_value ')' ARROW exp {
	auto p = new SpringParagraph(); 
	p->addStmt(new SpringJumpStatement(new SpringExpressionList($6), scanner.lineno()));
	$$ = new SpringConstantExpression($3, p); }
 | FUNC '(' ')' ARROW exp {
	auto p = new SpringParagraph(); 
	p->addStmt(new SpringJumpStatement(new SpringExpressionList($5), scanner.lineno()));
	$$ = new SpringConstantExpression(p); }

 | '[' zero_or_more_exp ']' { $$ = new SpringListDefinitionExpression($2); }
 | '{' object_body_stmts '}' { $$ = new SpringObjectDefinitionExpression($2); }
 | '{' '}' { $$ = new SpringObjectDefinitionExpression(); }

 | ID {$$ = new SpringIDExpression($1);}
 | exp '.' ID { $$ = new SpringPointExpression($1, new SpringIDExpression($3));}
 | exp '[' exp ']' { $$ = new SpringSubscriptExpression($1, $3);}

 | '(' exp ')' { $$ = $2; }
 | exp '(' zero_or_more_exp ')'{ $$ = new SpringFunctionCallExpression($1, $3); }
 | ID ARROW exp { $$ = new SpringArrowExpression(new SpringIDExpression($1), $3); }
 | NEW ID {$$ = new SpringNewExpression(new SpringIDExpression($2));}

 // Unary expression//////////////////////////////////////////////////////////////
 | '#' exp { $$ = new SpringOperatorExpression(100, $2); }
 | '-' exp { $$ = new SpringOperatorExpression(101, $2); }
 | INCREMENT exp { $$ = new SpringOperatorExpression(102, $2); }
 | DECREMENT exp { $$ = new SpringOperatorExpression(103, $2); }
 | exp INCREMENT { $$ = new SpringOperatorExpression(104, $1); }
 | exp DECREMENT { $$ = new SpringOperatorExpression(105, $1); }
 | BIT_COM exp { $$ = new SpringOperatorExpression(106, $2); }
 | LOGICAL_NOT exp { $$ = new SpringOperatorExpression(107, $2); }

 // Binary expression////////////////////////////////////////////////////////////// 
 | exp '+' exp { $$ = new SpringOperatorExpression(200, $1, $3); }
 | exp '-' exp { $$ = new SpringOperatorExpression(201, $1, $3); }
 | exp '*' exp { $$ = new SpringOperatorExpression(202, $1, $3); }
 | exp EXP exp { $$ = new SpringOperatorExpression(203, $1, $3); }
 | exp '/' exp { $$ = new SpringOperatorExpression(204, $1, $3); }
 | exp '%' exp { $$ = new SpringOperatorExpression(205, $1, $3); }
 | exp CMP_G exp { $$ = new SpringOperatorExpression(206, $1, $3); }
 | exp CMP_L exp { $$ = new SpringOperatorExpression(207, $1, $3); }
 | exp CMP_GE exp { $$ = new SpringOperatorExpression(208, $1, $3); }
 | exp CMP_LE exp { $$ = new SpringOperatorExpression(209, $1, $3); }
 | exp CMP_E exp { $$ = new SpringOperatorExpression(210, $1, $3); }
 | exp CMP_NE exp { $$ = new SpringOperatorExpression(211, $1, $3); }
 | exp LOGICAL_AND exp { $$ = new SpringOperatorExpression(212, $1, $3); }
 | exp LOGICAL_OR exp { $$ = new SpringOperatorExpression(213, $1, $3); }
 | exp BIT_AND exp { $$ = new SpringOperatorExpression(214, $1, $3); }
 | exp BIT_OR exp { $$ = new SpringOperatorExpression(215, $1, $3); }
 | exp BIT_XOR exp { $$ = new SpringOperatorExpression(216, $1, $3); }
 | exp BIT_SHIFT_LEFT exp { $$ = new SpringOperatorExpression(217, $1, $3); }
 | exp BIT_SHIFT_RIGHT exp { $$ = new SpringOperatorExpression(218, $1, $3); }
 | exp COM_ASSIGN exp { $$ = new SpringOperatorExpression($2, $1, $3); }

 // Ternary expression//////////////////////////////////////////////////////////////
 | exp '?' exp ':' exp { $$ = new SpringOperatorExpression(300, $1, $3, $5); }
 ;

ID_list_with_default_value: ID { SpringIDExpression* id = new SpringIDExpression($1); $$ = new SpringIDListExpression(id); }
 | ID '=' exp { SpringIDExpression* id = new SpringIDExpression($1, $3); $$ = new SpringIDListExpression(id); }
 | ID ',' ID_list_with_default_value { SpringIDExpression* id = new SpringIDExpression($1); SpringIDListExpression * n = (SpringIDListExpression *)($3); n->add_front(id); $$ = n; }
 | ID '=' exp ',' ID_list_with_default_value { SpringIDExpression* id = new SpringIDExpression($1, $3); SpringIDListExpression * n = (SpringIDListExpression *)($5); n->add_front(id); $$ = n; }
 ;

exp_list: exp { $$ = new SpringExpressionList($1); }
 | exp_list ',' exp { $1->add($3); $$ = $1; }
 ;

zero_or_more_exp: { $$ = nullptr; }
 | exp_list { $$ = $1; }
 ;


%%


// 必须自己定义一个错误处理函数
void Exa1::Exa1Parser::error(const Exa1Parser::location_type &loc, const std::string &msg)
{
	    // FIXME: 这里存在内存泄漏的问题
//    throw SpringException(SpringException::SPRING_ERROR_SYNTAX_ERROR, msg + "syntax error\nTODO: 这里要防止内存泄漏");
    zzzz "begin";
//    zzzz QString::fromStdString(loc.begin.filename);
    zzzz loc.begin.line;
    zzzz loc.begin.column;

    zzzz "end";
//    zzzz QString::fromStdString(*loc.end.filename);
    zzzz loc.end.line;
    zzzz loc.end.column;

    zzzz "error description:";
    zzzz QString::fromStdString(msg);

    throw SpringException(SpringException::SPRING_ERROR_SYNTAX_ERROR, msg);
}
int yyerror(char *s)
{
  fprintf(stderr, "error: %s\n", s);
  getchar();
  return 1;
}
