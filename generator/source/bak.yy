%require"2.3"
%skeleton"lalr1.cc"
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
#include "../ast/AST.h"
#include "../statement/SpringParagraph.h"
#include "../statement/SpringControlException.h"
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
	 spr::BaseExpression* ast;
	 spr::SpringParagraph * paragraph;
	 spr::SpringBaseLeftValueExpression* leftValue;
	 std::vector<spr::SpringBaseLeftValueExpression*>* leftValueList;

	 spr::SpringExpressionList *expList;
};

// 无属性的记号
%token LBRACE RBRACE
%token EOL
%token IF ELSE WHILE END FOR IN LOOP SWITCH USING
%token INCREMENT DECREMENT
%token ARROW LAMBDA FUNCTION
%token RETURN BREAK CONTINUE TRUE FALSE FUNC

%token LOGICAL_AND LOGICAL_OR LOGICAL_NOT
%token CMP_G CMP_L CMP_GE CMP_LE CMP_E CMP_NE

%token DEBUG NEW OBJECT VAR NIL DECL_INIT

// 有属性的记号
%token<m_id> ID STRING
%token<m_Int>T_INT
%token<m_Double>REAL
%type<ast> exp ID_list_with_default_value lambda
%type<leftValue> left_value
%type<leftValueList> multi_left_value
%type<paragraph> stmt object_body_stmt

%type<expList> exp_list


// 结合性与优先级
%right '?' ':'
%left LOGICAL_AND LOGICAL_OR LOGICAL_NOT
%right '=' ASSIGN ARROW
%nonassoc CMP_G CMP_L CMP_GE CMP_LE CMP_E CMP_NE
%left '+' '-'
%left '*' '/' '%'
%nonassoc UMINUS
%right '^'
%left FUNC_CALL
%left '[' '('
%left '.'
%nonassoc '#'


%start program
%%

program: stmt { 
	
		SpringParagraph* program = (yysemantic_stack_[(1) - (1)].paragraph);
        try{
            try{
                program->run(env);
            }catch(SpringContinueException &exception){
                throw SpringException(SpringException::SPRING_ERROR_SYNTAX_ERROR,
                                      "Continue statement can only be used in \"for\", \"while\", or \"loop\" statements.",
                                      exception.lineNo);
            }
            catch(SpringBreakException &exception){
                throw SpringException(SpringException::SPRING_ERROR_SYNTAX_ERROR,
                                      "Break statement can only be used in \"for\", \"while\", or \"loop\" statements.",
                                      exception.lineNo);
            }
            catch(SpringReturnException &exception){
                throw SpringException(SpringException::SPRING_ERROR_SYNTAX_ERROR,
                                      "Return statement can only be used in functions.",
                                      exception.lineNo);
            }
            catch(SpringExitException &exception){

            }
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

        BaseExpression::release(program);
        env.springIOHelper->onFinish();
	
	}
	
stmt: { $$ = new SpringParagraph(); }
 | stmt ';' { $$ = $1; }

 | stmt USING ID { auto u = new SpringUsingStatement($3); SpringParagraph * p = $1; p->addStmt(scanner.lineno(), u); $$ = p;}

 | stmt exp ';' { SpringParagraph * p = $1; p->add(scanner.lineno(), $2); $$ = p; }
 | stmt multi_left_value '=' exp_list ';'{ auto as = new SpringAssignStatement($2, $4); $1->addStmt(scanner.lineno(), as); $$ = $1; }

 | stmt BREAK ';' { SpringParagraph * p = $1; p->addBreakStmt(scanner.lineno()); $$ = p; }
 | stmt CONTINUE ';' { SpringParagraph * p = $1; p->addContinueStmt(scanner.lineno()); $$ = p; }
 | stmt DEBUG ';' { SpringParagraph * p = $1; p->addDebugStmt(scanner.lineno()); $$ = p; }
 | stmt RETURN ';' { SpringParagraph * p = $1; p->addReturnStmt(scanner.lineno()); $$ = p; }
 | stmt RETURN exp_list ';' { SpringParagraph * p = $1; p->addReturnStmt(scanner.lineno(), $3); $$ = p; }
 
 | stmt IF exp '{' stmt '}' {
		FlowStatement * f = new FlowStatement(FlowStatement::T_IF, $3, $5); 
		SpringParagraph * p = $1; 
		p->addStmt(scanner.lineno(),f);
		$$ = p; }
 | stmt IF exp '{' stmt '}' ELSE '{' stmt '}' {
		FlowStatement * f = new FlowStatement(FlowStatement::T_IF, $3, $5, $9); 
		SpringParagraph * p = $1; 
		p->addStmt(scanner.lineno(),f); 
		$$ = p;}
 | stmt WHILE exp '{' stmt '}' { 
		FlowStatement * f = new FlowStatement(FlowStatement::T_WHILE, $3, $5); 
		SpringParagraph * p = $1; 
		p->addStmt(scanner.lineno(),f); 
		$$ = p;}
 | stmt LOOP exp '{' stmt '}' { 
		FlowStatement * f = new FlowStatement(FlowStatement::T_LOOP, $3, $5); 
		SpringParagraph * p = $1; 
		p->addStmt(scanner.lineno(),f); 
		$$ = p;}
 | stmt FOR ID IN exp '{' stmt '}' {
		IDExpression * i = new IDExpression($3);
		FlowStatement * f = new FlowStatement(i, $5, $7);
		SpringParagraph * p = $1;
		p->addStmt(scanner.lineno(),f);
		$$ = p;}
		
 | stmt VAR ID_list_with_default_value ';' { auto d = new SpringDeclarationStatement($3); SpringParagraph * p = $1; p->addStmt(scanner.lineno(), d); $$ = p;}
 | stmt ID DECL_INIT exp ';' {auto id = new IDExpression($2, $4); auto d = new SpringDeclarationStatement(new IDListExpression(id)); $1->addStmt(scanner.lineno(), d); $$ = $1; }
 | stmt FUNC ID '(' ID_list_with_default_value ')' '{' stmt '}' {
		auto id = new IDExpression($3, new ConstantExpression($5, $8));
		auto dec = new SpringDeclarationStatement(new IDListExpression(id));
		SpringParagraph * p = $1; 
		p->addStmt(scanner.lineno(), dec);
		$$ = p; }
 | stmt FUNC ID '(' ')' '{' stmt '}' {
		auto id = new IDExpression($3, new ConstantExpression(new IDListExpression(), $7));
		auto dec = new SpringDeclarationStatement(new IDListExpression(id));
		SpringParagraph * p = $1; 
		p->addStmt(scanner.lineno(), dec);
		$$ = p; }
 | stmt OBJECT ID '{' object_body_stmt '}' {		
		auto id = new IDExpression($3);
		auto c = new SpringClassDefinitionStatement(id, $5);
		$1->addStmt(scanner.lineno(), c);
		$$ = $1; }

 ;

object_body_stmt : {$$ = new SpringParagraph();}
 | object_body_stmt ';' { $$ = $1; }
 | object_body_stmt VAR ID_list_with_default_value ';' { auto d = new SpringDeclarationStatement($3); SpringParagraph * p = $1; p->addStmt(scanner.lineno(), d); $$ = p;}
 | object_body_stmt ID DECL_INIT exp ';' { auto d = new SpringDeclarationStatement(new IDListExpression(new IDExpression($2, $4))); $1->addStmt(scanner.lineno(), d); $$ = $1; }
 | object_body_stmt FUNC ID '(' ID_list_with_default_value ')' '{' stmt '}' {
		auto id = new IDExpression($3, new ConstantExpression($5, $8));
		auto dec = new SpringDeclarationStatement(new IDListExpression(id));
		SpringParagraph * p = $1;
		p->addStmt(scanner.lineno(), dec);
		$$ = p; }
 | object_body_stmt FUNC ID '(' ')' '{' stmt '}' {
		auto id = new IDExpression($3, new ConstantExpression(new IDListExpression(), $7));
		auto dec = new SpringDeclarationStatement(new IDListExpression(id));
		SpringParagraph * p = $1; 
		p->addStmt(scanner.lineno(), dec);
		$$ = p; }
 | object_body_stmt '+' '(' ID ')' '{' stmt '}' {
	 auto id = new IDExpression("+", new ConstantExpression(new IDListExpression(new IDExpression($4)), $7));
	 $1->addStmt(scanner.lineno(), new SpringDeclarationStatement(new IDListExpression(id))); $$ = $1;}
 | object_body_stmt '-' '(' ID ')' '{' stmt '}' {
	 auto id = new IDExpression("-", new ConstantExpression(new IDListExpression(new IDExpression($4)), $7));
	 $1->addStmt(scanner.lineno(), new SpringDeclarationStatement(new IDListExpression(id))); $$ = $1;}
 | object_body_stmt '*' '(' ID ')' '{' stmt '}' {
	 auto id = new IDExpression("*", new ConstantExpression(new IDListExpression(new IDExpression($4)), $7));
	 $1->addStmt(scanner.lineno(), new SpringDeclarationStatement(new IDListExpression(id))); $$ = $1;}
 | object_body_stmt '^' '(' ID ')' '{' stmt '}' {
	 auto id = new IDExpression("^", new ConstantExpression(new IDListExpression(new IDExpression($4)), $7));
	 $1->addStmt(scanner.lineno(), new SpringDeclarationStatement(new IDListExpression(id))); $$ = $1;}
 | object_body_stmt '/' '(' ID ')' '{' stmt '}' {
	 auto id = new IDExpression("/", new ConstantExpression(new IDListExpression(new IDExpression($4)), $7));
	 $1->addStmt(scanner.lineno(), new SpringDeclarationStatement(new IDListExpression(id))); $$ = $1;}
 | object_body_stmt '%' '(' ID ')' '{' stmt '}' {
	 auto id = new IDExpression("%", new ConstantExpression(new IDListExpression(new IDExpression($4)), $7));
	 $1->addStmt(scanner.lineno(), new SpringDeclarationStatement(new IDListExpression(id))); $$ = $1;}

 | object_body_stmt CMP_G '(' ID ')' '{' stmt '}' {
	 auto id = new IDExpression(">", new ConstantExpression(new IDListExpression(new IDExpression($4)), $7));
	 $1->addStmt(scanner.lineno(), new SpringDeclarationStatement(new IDListExpression(id))); $$ = $1;}
 | object_body_stmt CMP_L '(' ID ')' '{' stmt '}' {
	 auto id = new IDExpression("<", new ConstantExpression(new IDListExpression(new IDExpression($4)), $7));
	 $1->addStmt(scanner.lineno(), new SpringDeclarationStatement(new IDListExpression(id))); $$ = $1;}
 | object_body_stmt CMP_GE '(' ID ')' '{' stmt '}' {
	 auto id = new IDExpression(">=", new ConstantExpression(new IDListExpression(new IDExpression($4)), $7));
	 $1->addStmt(scanner.lineno(), new SpringDeclarationStatement(new IDListExpression(id))); $$ = $1;}
 | object_body_stmt CMP_LE '(' ID ')' '{' stmt '}' {
	 auto id = new IDExpression("<=", new ConstantExpression(new IDListExpression(new IDExpression($4)), $7));
	 $1->addStmt(scanner.lineno(), new SpringDeclarationStatement(new IDListExpression(id))); $$ = $1;}
 | object_body_stmt CMP_E '(' ID ')' '{' stmt '}' {
	 auto id = new IDExpression("?=", new ConstantExpression(new IDListExpression(new IDExpression($4)), $7));
	 $1->addStmt(scanner.lineno(), new SpringDeclarationStatement(new IDListExpression(id))); $$ = $1;}
 | object_body_stmt CMP_NE '(' ID ')' '{' stmt '}' {
	 auto id = new IDExpression("!=", new ConstantExpression(new IDListExpression(new IDExpression($4)), $7));
	 $1->addStmt(scanner.lineno(), new SpringDeclarationStatement(new IDListExpression(id))); $$ = $1;}
	 
 | object_body_stmt LOGICAL_AND '(' ID ')' '{' stmt '}' {
	 auto id = new IDExpression("&&", new ConstantExpression(new IDListExpression(new IDExpression($4)), $7));
	 $1->addStmt(scanner.lineno(), new SpringDeclarationStatement(new IDListExpression(id))); $$ = $1;}
 | object_body_stmt LOGICAL_OR '(' ID ')' '{' stmt '}' {
	 auto id = new IDExpression("||", new ConstantExpression(new IDListExpression(new IDExpression($4)), $7));
	 $1->addStmt(scanner.lineno(), new SpringDeclarationStatement(new IDListExpression(id))); $$ = $1;}

 | object_body_stmt '[' ']' '(' ID ')' '{' stmt '}' {
	 auto id = new IDExpression("[]", new ConstantExpression(new IDListExpression(new IDExpression($5)), $8));
	 $1->addStmt(scanner.lineno(), new SpringDeclarationStatement(new IDListExpression(id))); $$ = $1;}

 | object_body_stmt '-' '{' stmt '}' {
	 auto id = new IDExpression("--", new ConstantExpression($4));
	 $1->addStmt(scanner.lineno(), new SpringDeclarationStatement(new IDListExpression(id))); $$ = $1;}
 | object_body_stmt LOGICAL_NOT '{' stmt '}' {
	 auto id = new IDExpression("!", new ConstantExpression($4));
	 $1->addStmt(scanner.lineno(), new SpringDeclarationStatement(new IDListExpression(id))); $$ = $1;}
 | object_body_stmt '#' '{' stmt '}' {
	 auto id = new IDExpression("#", new ConstantExpression($4));
	 $1->addStmt(scanner.lineno(), new SpringDeclarationStatement(new IDListExpression(id))); $$ = $1;}
 ;


exp: NIL { $$ = new ConstantExpression();}
 | TRUE { $$ = new ConstantExpression(true);}
 | FALSE { $$ = new ConstantExpression(false);}
 | T_INT { $$ = new ConstantExpression($1); }
 | REAL { $$ = new ConstantExpression($1); }
 | STRING { $$ = new ConstantExpression($1); }
 | lambda {$$ = $1; }
 
 | '[' ']' { $$ = new SpringListDefinition(); }
 | '[' exp_list ']' { $$ = new SpringListDefinition($2); }

 | left_value { $$ = $1;}
 | ID ARROW exp { $$ = new SpringArrowExpression(new IDExpression($1), $3); }

 | exp '+' exp { $$ = new BinaryExpression(0, $1, $3); }
 | exp '-' exp { $$ = new BinaryExpression(1, $1, $3); }
 | exp '*' exp { $$ = new BinaryExpression(2, $1, $3); }
 | exp '^' exp { $$ = new BinaryExpression(3, $1, $3); }
 | exp '/' exp { $$ = new BinaryExpression(4, $1, $3); }
 | exp '%' exp { $$ = new BinaryExpression(5, $1, $3); }
 | exp CMP_G exp { $$ = new BinaryExpression(6, $1, $3); }
 | exp CMP_L exp { $$ = new BinaryExpression(7, $1, $3); }
 | exp CMP_GE exp { $$ = new BinaryExpression(8, $1, $3); }
 | exp CMP_LE exp { $$ = new BinaryExpression(9, $1, $3); }
 | exp CMP_E exp { $$ = new BinaryExpression(10, $1, $3); }
 | exp CMP_NE exp { $$ = new BinaryExpression(11, $1, $3); }
 | exp LOGICAL_AND exp { $$ = new BinaryExpression(12, $1, $3); }
 | exp LOGICAL_OR exp { $$ = new BinaryExpression(13, $1, $3); }

 | '#' exp { $$ = new BinaryExpression(100, $2, 0); } 
 | '-' exp { $$ = new BinaryExpression(101, $2, 0); }
 | LOGICAL_NOT exp { $$ = new BinaryExpression(102, $2, 0); }

 | exp '?' exp ':' exp { $$ = new BinaryExpression(200, $1, $3, $5); }

 | '(' exp ')' { $$ = $2; }
 | exp '(' ')'{ $$ = new SpringFunctionCall($1); }
 | exp '(' exp_list ')'{ $$ = new SpringFunctionCall($1, $3); }

 | NEW ID {$$ = new SpringNewExpression(new IDExpression($2));}

 ;

lambda: FUNC ID_list_with_default_value '{' stmt '}' { $$ = new ConstantExpression($2, $4); }
 | FUNC '{' stmt '}' { $$ = new ConstantExpression($3); }
 ;

ID_list_with_default_value: ID { IDExpression* id = new IDExpression($1); $$ = new IDListExpression(id); }
 | ID '=' exp { IDExpression* id = new IDExpression($1, $3); $$ = new IDListExpression(id); }
 | ID ',' ID_list_with_default_value { IDExpression* id = new IDExpression($1); IDListExpression * n = (IDListExpression *)($3); n->add_front(id); $$ = n; }
 | ID '=' exp ',' ID_list_with_default_value { IDExpression* id = new IDExpression($1, $3); IDListExpression * n = (IDListExpression *)($5); n->add_front(id); $$ = n; }
 ;

exp_list : exp { $$ = new SpringExpressionList($1); }
 | exp_list ',' exp { $1->add($3); $$ = $1; }
 ;

left_value : ID {$$ = new IDExpression($1);}
 | exp '.' ID { $$ = new SpringPointExpression($1, new IDExpression($3));}
 | exp '[' exp ']' { $$ = new MemberExpression($1, $3);}
 ;

multi_left_value : left_value { $$ = new std::vector<spr::SpringBaseLeftValueExpression*>(); $$->push_back($1); }
 | multi_left_value ',' left_value { $$ = $1; $$->push_back($3); }
 ;

%%


// 必须自己定义一个错误处理函数
void Exa1::Exa1Parser::error(const Exa1Parser::location_type &loc, const std::string &msg)
{
    throw SpringException(SpringException::SPRING_ERROR_SYNTAX_ERROR, "syntax error");
}
int yyerror(char *s)
{
  fprintf(stderr, "error: %s\n", s);
  getchar();
  return 1;
}
