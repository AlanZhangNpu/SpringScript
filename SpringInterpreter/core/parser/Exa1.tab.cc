
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison LALR(1) parsers in C++
   
      Copyright (C) 2002, 2003, 2004, 2005, 2006, 2007, 2008 Free Software
   Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */


/* First part of user declarations.  */


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




#include "Exa1.tab.hh"

/* User implementation prologue.  */



#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* FIXME: INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#define YYUSE(e) ((void) (e))

/* Enable debugging if requested.  */
#if YYDEBUG

/* A pseudo ostream that takes yydebug_ into account.  */
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)	\
do {							\
  if (yydebug_)						\
    {							\
      *yycdebug_ << Title << ' ';			\
      yy_symbol_print_ ((Type), (Value), (Location));	\
      *yycdebug_ << std::endl;				\
    }							\
} while (false)

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug_)				\
    yy_reduce_print_ (Rule);		\
} while (false)

# define YY_STACK_PRINT()		\
do {					\
  if (yydebug_)				\
    yystack_print_ ();			\
} while (false)

#else /* !YYDEBUG */

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_REDUCE_PRINT(Rule)
# define YY_STACK_PRINT()

#endif /* !YYDEBUG */

#define yyerrok		(yyerrstatus_ = 0)
#define yyclearin	(yychar = yyempty_)

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)


namespace Exa1 {

#if YYERROR_VERBOSE

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  Exa1Parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr = "";
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              /* Fall through.  */
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }

#endif

  /// Build a parser object.
  Exa1Parser::Exa1Parser (Exa1::Exa1Scanner &scanner_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      scanner (scanner_yyarg)
  {
  }

  Exa1Parser::~Exa1Parser ()
  {
  }

#if YYDEBUG
  /*--------------------------------.
  | Print this symbol on YYOUTPUT.  |
  `--------------------------------*/

  inline void
  Exa1Parser::yy_symbol_value_print_ (int yytype,
			   const semantic_type* yyvaluep, const location_type* yylocationp)
  {
    YYUSE (yylocationp);
    YYUSE (yyvaluep);
    switch (yytype)
      {
         default:
	  break;
      }
  }


  void
  Exa1Parser::yy_symbol_print_ (int yytype,
			   const semantic_type* yyvaluep, const location_type* yylocationp)
  {
    *yycdebug_ << (yytype < yyntokens_ ? "token" : "nterm")
	       << ' ' << yytname_[yytype] << " ("
	       << *yylocationp << ": ";
    yy_symbol_value_print_ (yytype, yyvaluep, yylocationp);
    *yycdebug_ << ')';
  }
#endif

  void
  Exa1Parser::yydestruct_ (const char* yymsg,
			   int yytype, semantic_type* yyvaluep, location_type* yylocationp)
  {
    YYUSE (yylocationp);
    YYUSE (yymsg);
    YYUSE (yyvaluep);

    YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

    switch (yytype)
      {
  
	default:
	  break;
      }
  }

  void
  Exa1Parser::yypop_ (unsigned int n)
  {
    yystate_stack_.pop (n);
    yysemantic_stack_.pop (n);
    yylocation_stack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  Exa1Parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  Exa1Parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  Exa1Parser::debug_level_type
  Exa1Parser::debug_level () const
  {
    return yydebug_;
  }

  void
  Exa1Parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif

  int
  Exa1Parser::parse (SpringRuntimeEnvironment &env)
  {
    /// Lookahead and lookahead in internal form.
    int yychar = yyempty_;
    int yytoken = 0;

    /* State.  */
    int yyn;
    int yylen = 0;
    int yystate = 0;

    /* Error handling.  */
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// Semantic value of the lookahead.
    semantic_type yylval;
    /// Location of the lookahead.
    location_type yylloc;
    /// The locations where the error started and ended.
    location_type yyerror_range[2];

    /// $$.
    semantic_type yyval;
    /// @$.
    location_type yyloc;

    int yyresult;

    YYCDEBUG << "Starting parse" << std::endl;


    /* Initialize the stacks.  The initial state will be pushed in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystate_stack_ = state_stack_type (0);
    yysemantic_stack_ = semantic_stack_type (0);
    yylocation_stack_ = location_stack_type (0);
    yysemantic_stack_.push (yylval);
    yylocation_stack_.push (yylloc);

    /* New state.  */
  yynewstate:
    yystate_stack_.push (yystate);
    YYCDEBUG << "Entering state " << yystate << std::endl;

    /* Accept?  */
    if (yystate == yyfinal_)
      goto yyacceptlab;

    goto yybackup;

    /* Backup.  */
  yybackup:

    /* Try to take a decision without lookahead.  */
    yyn = yypact_[yystate];
    if (yyn == yypact_ninf_)
      goto yydefault;

    /* Read a lookahead token.  */
    if (yychar == yyempty_)
      {
	YYCDEBUG << "Reading a token: ";
	yychar = yylex (&yylval);
      }


    /* Convert token to internal form.  */
    if (yychar <= yyeof_)
      {
	yychar = yytoken = yyeof_;
	YYCDEBUG << "Now at end of input." << std::endl;
      }
    else
      {
	yytoken = yytranslate_ (yychar);
	YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
      }

    /* If the proper action on seeing token YYTOKEN is to reduce or to
       detect an error, take that action.  */
    yyn += yytoken;
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yytoken)
      goto yydefault;

    /* Reduce or error.  */
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
	if (yyn == 0 || yyn == yytable_ninf_)
	goto yyerrlab;
	yyn = -yyn;
	goto yyreduce;
      }

    /* Shift the lookahead token.  */
    YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

    /* Discard the token being shifted.  */
    yychar = yyempty_;

    yysemantic_stack_.push (yylval);
    yylocation_stack_.push (yylloc);

    /* Count tokens shifted since error; after three, turn off error
       status.  */
    if (yyerrstatus_)
      --yyerrstatus_;

    yystate = yyn;
    goto yynewstate;

  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystate];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;

  /*-----------------------------.
  | yyreduce -- Do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    /* If YYLEN is nonzero, implement the default value of the action:
       `$$ = $1'.  Otherwise, use the top of the stack.

       Otherwise, the following line sets YYVAL to garbage.
       This behavior is undocumented and Bison
       users should not rely upon it.  */
    if (yylen)
      yyval = yysemantic_stack_[yylen - 1];
    else
      yyval = yysemantic_stack_[0];

    {
      slice<location_type, location_stack_type> slice (yylocation_stack_, yylen);
      YYLLOC_DEFAULT (yyloc, slice, yylen);
    }
    YY_REDUCE_PRINT (yyn);
    switch (yyn)
      {
	  case 2:

    { 
		SpringParagraph* program = (yysemantic_stack_[(1) - (1)].paragraph);
        //program->printStructure(0);
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
    break;

  case 3:

    { (yyval.stmt) = new SpringImportStatement((yysemantic_stack_[(3) - (2)].m_id), (yysemantic_stack_[(3) - (3)].m_Int)); }
    break;

  case 4:

    { (yyval.stmt) = (yysemantic_stack_[(1) - (1)].stmt); }
    break;

  case 5:

    { (yyval.stmt) = new SpringAssignStatement((yysemantic_stack_[(4) - (1)].expList), (yysemantic_stack_[(4) - (3)].expList), (yysemantic_stack_[(4) - (4)].m_Int)); }
    break;

  case 6:

    { (yyval.stmt) = new SpringExpressionStatement((yysemantic_stack_[(2) - (1)].exp), (yysemantic_stack_[(2) - (2)].m_Int)); }
    break;

  case 7:

    { (yyval.stmt) = new SpringJumpStatement('b', (yysemantic_stack_[(2) - (2)].m_Int)); }
    break;

  case 8:

    { (yyval.stmt) = new SpringJumpStatement('c', (yysemantic_stack_[(2) - (2)].m_Int)); }
    break;

  case 9:

    { (yyval.stmt) = new SpringJumpStatement('d', (yysemantic_stack_[(2) - (2)].m_Int)); }
    break;

  case 10:

    { (yyval.stmt) = new SpringJumpStatement('e', (yysemantic_stack_[(2) - (2)].m_Int)); }
    break;

  case 11:

    { (yyval.stmt) = new SpringJumpStatement((yysemantic_stack_[(3) - (2)].expList), (yysemantic_stack_[(3) - (3)].m_Int)); }
    break;

  case 12:

    { (yyval.stmt) = new SpringControlFlowStatement((yysemantic_stack_[(5) - (2)].exp), (yysemantic_stack_[(5) - (3)].paragraph), (yysemantic_stack_[(5) - (5)].paragraph), (yysemantic_stack_[(5) - (3)].paragraph)->getFirstStmtLineNo()); }
    break;

  case 13:

    { (yyval.stmt) = new SpringControlFlowStatement('i', (yysemantic_stack_[(3) - (2)].exp), (yysemantic_stack_[(3) - (3)].paragraph), (yysemantic_stack_[(3) - (3)].paragraph)->getFirstStmtLineNo()); }
    break;

  case 14:

    { (yyval.stmt) = new SpringControlFlowStatement('w', (yysemantic_stack_[(3) - (2)].exp), (yysemantic_stack_[(3) - (3)].paragraph), (yysemantic_stack_[(3) - (3)].paragraph)->getFirstStmtLineNo()); }
    break;

  case 15:

    { (yyval.stmt) = new SpringControlFlowStatement('l', (yysemantic_stack_[(3) - (2)].exp), (yysemantic_stack_[(3) - (3)].paragraph), (yysemantic_stack_[(3) - (3)].paragraph)->getFirstStmtLineNo()); }
    break;

  case 16:

    { (yyval.stmt) = new SpringControlFlowStatement(new SpringIDExpression((yysemantic_stack_[(5) - (2)].m_id)), (yysemantic_stack_[(5) - (4)].exp), (yysemantic_stack_[(5) - (5)].paragraph), (yysemantic_stack_[(5) - (5)].paragraph)->getFirstStmtLineNo()); }
    break;

  case 17:

    { (yyval.stmt) = new SpringDeclarationStatement(); }
    break;

  case 18:

    { (yyval.stmt) = new SpringDeclarationStatement(dynamic_cast<SpringIDListExpression*>(yysemantic_stack_[(3) - (2)].exp), (yysemantic_stack_[(3) - (3)].m_Int)); }
    break;

  case 19:

    { (yyval.stmt) = new SpringDeclarationStatement(new SpringIDListExpression(new SpringIDExpression((yysemantic_stack_[(4) - (1)].m_id), (yysemantic_stack_[(4) - (3)].exp))), (yysemantic_stack_[(4) - (4)].m_Int)); }
    break;

  case 20:

    { (yyval.stmt) = new SpringDeclarationStatement(new SpringIDListExpression(new SpringIDExpression((yysemantic_stack_[(8) - (2)].m_id), new SpringConstantExpression((yysemantic_stack_[(8) - (4)].exp), (yysemantic_stack_[(8) - (7)].paragraph)))), (yysemantic_stack_[(8) - (7)].paragraph)->getFirstStmtLineNo()); }
    break;

  case 21:

    { (yyval.stmt) = new SpringDeclarationStatement(new SpringIDListExpression(new SpringIDExpression((yysemantic_stack_[(7) - (2)].m_id), new SpringConstantExpression(new SpringIDListExpression(), (yysemantic_stack_[(7) - (6)].paragraph)))), (yysemantic_stack_[(7) - (6)].paragraph)->getFirstStmtLineNo()); }
    break;

  case 22:

    { (yyval.stmt) = new SpringDeclarationStatement(new SpringIDListExpression(new SpringIDExpression((yysemantic_stack_[(5) - (2)].m_id), new SpringObjectDefinitionExpression((yysemantic_stack_[(5) - (4)].paragraph)))), (yysemantic_stack_[(5) - (4)].paragraph)->getFirstStmtLineNo()); }
    break;

  case 23:

    { /*TODO*/ }
    break;

  case 24:

    {
	auto id = new SpringIDExpression("+", new SpringConstantExpression(new SpringIDListExpression(new SpringIDExpression((yysemantic_stack_[(5) - (2)].m_id))), (yysemantic_stack_[(5) - (4)].paragraph)));
    (yyval.stmt) = new SpringDeclarationStatement(new SpringIDListExpression(id), (yysemantic_stack_[(5) - (4)].paragraph)->getFirstStmtLineNo()); }
    break;

  case 25:

    {
	auto id = new SpringIDExpression("-", new SpringConstantExpression(new SpringIDListExpression(new SpringIDExpression((yysemantic_stack_[(5) - (2)].m_id))), (yysemantic_stack_[(5) - (4)].paragraph)));
    (yyval.stmt) = new SpringDeclarationStatement(new SpringIDListExpression(id), (yysemantic_stack_[(5) - (4)].paragraph)->getFirstStmtLineNo()); }
    break;

  case 26:

    {
	auto id = new SpringIDExpression("*", new SpringConstantExpression(new SpringIDListExpression(new SpringIDExpression((yysemantic_stack_[(5) - (2)].m_id))), (yysemantic_stack_[(5) - (4)].paragraph)));
    (yyval.stmt) = new SpringDeclarationStatement(new SpringIDListExpression(id), (yysemantic_stack_[(5) - (4)].paragraph)->getFirstStmtLineNo()); }
    break;

  case 27:

    {
	auto id = new SpringIDExpression("**", new SpringConstantExpression(new SpringIDListExpression(new SpringIDExpression((yysemantic_stack_[(5) - (2)].m_id))), (yysemantic_stack_[(5) - (4)].paragraph)));
    (yyval.stmt) = new SpringDeclarationStatement(new SpringIDListExpression(id), (yysemantic_stack_[(5) - (4)].paragraph)->getFirstStmtLineNo()); }
    break;

  case 28:

    {
	auto id = new SpringIDExpression("/", new SpringConstantExpression(new SpringIDListExpression(new SpringIDExpression((yysemantic_stack_[(5) - (2)].m_id))), (yysemantic_stack_[(5) - (4)].paragraph)));
    (yyval.stmt) = new SpringDeclarationStatement(new SpringIDListExpression(id), (yysemantic_stack_[(5) - (4)].paragraph)->getFirstStmtLineNo()); }
    break;

  case 29:

    {
	auto id = new SpringIDExpression("%", new SpringConstantExpression(new SpringIDListExpression(new SpringIDExpression((yysemantic_stack_[(5) - (2)].m_id))), (yysemantic_stack_[(5) - (4)].paragraph)));
    (yyval.stmt) = new SpringDeclarationStatement(new SpringIDListExpression(id), (yysemantic_stack_[(5) - (4)].paragraph)->getFirstStmtLineNo()); }
    break;

  case 30:

    {
	auto id = new SpringIDExpression(">", new SpringConstantExpression(new SpringIDListExpression(new SpringIDExpression((yysemantic_stack_[(5) - (2)].m_id))), (yysemantic_stack_[(5) - (4)].paragraph)));
    (yyval.stmt) = new SpringDeclarationStatement(new SpringIDListExpression(id), (yysemantic_stack_[(5) - (4)].paragraph)->getFirstStmtLineNo()); }
    break;

  case 31:

    {
	auto id = new SpringIDExpression("<", new SpringConstantExpression(new SpringIDListExpression(new SpringIDExpression((yysemantic_stack_[(5) - (2)].m_id))), (yysemantic_stack_[(5) - (4)].paragraph)));
    (yyval.stmt) = new SpringDeclarationStatement(new SpringIDListExpression(id), (yysemantic_stack_[(5) - (4)].paragraph)->getFirstStmtLineNo()); }
    break;

  case 32:

    {
	auto id = new SpringIDExpression(">=", new SpringConstantExpression(new SpringIDListExpression(new SpringIDExpression((yysemantic_stack_[(5) - (2)].m_id))), (yysemantic_stack_[(5) - (4)].paragraph)));
    (yyval.stmt) = new SpringDeclarationStatement(new SpringIDListExpression(id), (yysemantic_stack_[(5) - (4)].paragraph)->getFirstStmtLineNo()); }
    break;

  case 33:

    {
	auto id = new SpringIDExpression("<=", new SpringConstantExpression(new SpringIDListExpression(new SpringIDExpression((yysemantic_stack_[(5) - (2)].m_id))), (yysemantic_stack_[(5) - (4)].paragraph)));
    (yyval.stmt) = new SpringDeclarationStatement(new SpringIDListExpression(id), (yysemantic_stack_[(5) - (4)].paragraph)->getFirstStmtLineNo()); }
    break;

  case 34:

    {
	auto id = new SpringIDExpression("==", new SpringConstantExpression(new SpringIDListExpression(new SpringIDExpression((yysemantic_stack_[(5) - (2)].m_id))), (yysemantic_stack_[(5) - (4)].paragraph)));
    (yyval.stmt) = new SpringDeclarationStatement(new SpringIDListExpression(id), (yysemantic_stack_[(5) - (4)].paragraph)->getFirstStmtLineNo()); }
    break;

  case 35:

    {
	auto id = new SpringIDExpression("!=", new SpringConstantExpression(new SpringIDListExpression(new SpringIDExpression((yysemantic_stack_[(5) - (2)].m_id))), (yysemantic_stack_[(5) - (4)].paragraph)));
    (yyval.stmt) = new SpringDeclarationStatement(new SpringIDListExpression(id), (yysemantic_stack_[(5) - (4)].paragraph)->getFirstStmtLineNo()); }
    break;

  case 36:

    {
	auto id = new SpringIDExpression("&&", new SpringConstantExpression(new SpringIDListExpression(new SpringIDExpression((yysemantic_stack_[(5) - (2)].m_id))), (yysemantic_stack_[(5) - (4)].paragraph)));
    (yyval.stmt) = new SpringDeclarationStatement(new SpringIDListExpression(id), (yysemantic_stack_[(5) - (4)].paragraph)->getFirstStmtLineNo()); }
    break;

  case 37:

    {
	auto id = new SpringIDExpression("||", new SpringConstantExpression(new SpringIDListExpression(new SpringIDExpression((yysemantic_stack_[(5) - (2)].m_id))), (yysemantic_stack_[(5) - (4)].paragraph)));
    (yyval.stmt) = new SpringDeclarationStatement(new SpringIDListExpression(id), (yysemantic_stack_[(5) - (4)].paragraph)->getFirstStmtLineNo()); }
    break;

  case 38:

    {
	auto id = new SpringIDExpression("&", new SpringConstantExpression(new SpringIDListExpression(new SpringIDExpression((yysemantic_stack_[(5) - (2)].m_id))), (yysemantic_stack_[(5) - (4)].paragraph)));
    (yyval.stmt) = new SpringDeclarationStatement(new SpringIDListExpression(id), (yysemantic_stack_[(5) - (4)].paragraph)->getFirstStmtLineNo()); }
    break;

  case 39:

    {
	auto id = new SpringIDExpression("|", new SpringConstantExpression(new SpringIDListExpression(new SpringIDExpression((yysemantic_stack_[(5) - (2)].m_id))), (yysemantic_stack_[(5) - (4)].paragraph)));
    (yyval.stmt) = new SpringDeclarationStatement(new SpringIDListExpression(id), (yysemantic_stack_[(5) - (4)].paragraph)->getFirstStmtLineNo()); }
    break;

  case 40:

    {
	auto id = new SpringIDExpression("^", new SpringConstantExpression(new SpringIDListExpression(new SpringIDExpression((yysemantic_stack_[(5) - (2)].m_id))), (yysemantic_stack_[(5) - (4)].paragraph)));
    (yyval.stmt) = new SpringDeclarationStatement(new SpringIDListExpression(id), (yysemantic_stack_[(5) - (4)].paragraph)->getFirstStmtLineNo()); }
    break;

  case 41:

    {
	auto id = new SpringIDExpression("<<", new SpringConstantExpression(new SpringIDListExpression(new SpringIDExpression((yysemantic_stack_[(5) - (2)].m_id))), (yysemantic_stack_[(5) - (4)].paragraph)));
    (yyval.stmt) = new SpringDeclarationStatement(new SpringIDListExpression(id), (yysemantic_stack_[(5) - (4)].paragraph)->getFirstStmtLineNo()); }
    break;

  case 42:

    {
	auto id = new SpringIDExpression(">>", new SpringConstantExpression(new SpringIDListExpression(new SpringIDExpression((yysemantic_stack_[(5) - (2)].m_id))), (yysemantic_stack_[(5) - (4)].paragraph)));
    (yyval.stmt) = new SpringDeclarationStatement(new SpringIDListExpression(id), (yysemantic_stack_[(5) - (4)].paragraph)->getFirstStmtLineNo()); }
    break;

  case 43:

    {
	auto id = new SpringIDExpression(".", new SpringConstantExpression(new SpringIDListExpression(new SpringIDExpression((yysemantic_stack_[(5) - (2)].m_id))), (yysemantic_stack_[(5) - (4)].paragraph)));
    (yyval.stmt) = new SpringDeclarationStatement(new SpringIDListExpression(id), (yysemantic_stack_[(5) - (4)].paragraph)->getFirstStmtLineNo()); }
    break;

  case 44:

    {
	auto id = new SpringIDExpression("[]", new SpringConstantExpression(new SpringIDListExpression(new SpringIDExpression((yysemantic_stack_[(6) - (2)].m_id))), (yysemantic_stack_[(6) - (5)].paragraph)));
    (yyval.stmt) = new SpringDeclarationStatement(new SpringIDListExpression(id), (yysemantic_stack_[(6) - (5)].paragraph)->getFirstStmtLineNo()); }
    break;

  case 45:

    {
	auto id = new SpringIDExpression("()", new SpringConstantExpression((yysemantic_stack_[(5) - (4)].paragraph)));
    (yyval.stmt) = new SpringDeclarationStatement(new SpringIDListExpression(id), (yysemantic_stack_[(5) - (4)].paragraph)->getFirstStmtLineNo()); }
    break;

  case 46:

    {
	auto id = new SpringIDExpression("()", new SpringConstantExpression((yysemantic_stack_[(6) - (2)].exp), (yysemantic_stack_[(6) - (5)].paragraph)));
    (yyval.stmt) = new SpringDeclarationStatement(new SpringIDListExpression(id), (yysemantic_stack_[(6) - (5)].paragraph)->getFirstStmtLineNo()); }
    break;

  case 47:

    {
	auto id = new SpringIDExpression("#", new SpringConstantExpression((yysemantic_stack_[(4) - (3)].paragraph)));
	(yyval.stmt) = new SpringDeclarationStatement(new SpringIDListExpression(id), (yysemantic_stack_[(4) - (3)].paragraph)->getFirstStmtLineNo()); }
    break;

  case 48:

    {
	auto id = new SpringIDExpression("---", new SpringConstantExpression((yysemantic_stack_[(4) - (3)].paragraph)));
	(yyval.stmt) = new SpringDeclarationStatement(new SpringIDListExpression(id), (yysemantic_stack_[(4) - (3)].paragraph)->getFirstStmtLineNo()); }
    break;

  case 49:

    {
	auto id = new SpringIDExpression("++", new SpringConstantExpression((yysemantic_stack_[(4) - (3)].paragraph)));
	(yyval.stmt) = new SpringDeclarationStatement(new SpringIDListExpression(id), (yysemantic_stack_[(4) - (3)].paragraph)->getFirstStmtLineNo()); }
    break;

  case 50:

    {
	auto id = new SpringIDExpression("--", new SpringConstantExpression((yysemantic_stack_[(4) - (3)].paragraph)));
	(yyval.stmt) = new SpringDeclarationStatement(new SpringIDListExpression(id), (yysemantic_stack_[(4) - (3)].paragraph)->getFirstStmtLineNo()); }
    break;

  case 51:

    {
	auto id = new SpringIDExpression("~", new SpringConstantExpression((yysemantic_stack_[(4) - (3)].paragraph)));
	(yyval.stmt) = new SpringDeclarationStatement(new SpringIDListExpression(id), (yysemantic_stack_[(4) - (3)].paragraph)->getFirstStmtLineNo()); }
    break;

  case 52:

    {
	auto id = new SpringIDExpression("!", new SpringConstantExpression((yysemantic_stack_[(4) - (3)].paragraph)));
	(yyval.stmt) = new SpringDeclarationStatement(new SpringIDListExpression(id), (yysemantic_stack_[(4) - (3)].paragraph)->getFirstStmtLineNo()); }
    break;

  case 53:

    { (yyval.m_Int) = scanner.lineno(); }
    break;

  case 54:

    { (yyval.m_Int) = scanner.lineno() - 1; }
    break;

  case 55:

    { (yyval.paragraph) = new SpringParagraph(); (yyval.paragraph)->addStmt((yysemantic_stack_[(1) - (1)].stmt)); }
    break;

  case 56:

    { (yysemantic_stack_[(2) - (1)].paragraph)->addStmt((yysemantic_stack_[(2) - (2)].stmt)); (yyval.paragraph) = (yysemantic_stack_[(2) - (1)].paragraph); }
    break;

  case 57:

    { (yyval.paragraph) = new SpringParagraph(); (yyval.paragraph)->addStmt((yysemantic_stack_[(2) - (2)].stmt)); }
    break;

  case 58:

    { (yyval.paragraph) = (yysemantic_stack_[(3) - (2)].paragraph); }
    break;

  case 59:

    { (yyval.paragraph) = new SpringParagraph(); (yyval.paragraph)->addStmt((yysemantic_stack_[(1) - (1)].stmt)); }
    break;

  case 60:

    { (yyval.paragraph) = new SpringParagraph(); (yyval.paragraph)->addStmt((yysemantic_stack_[(1) - (1)].stmt)); }
    break;

  case 61:

    { (yysemantic_stack_[(2) - (1)].paragraph)->addStmt((yysemantic_stack_[(2) - (2)].stmt)); (yyval.paragraph) = (yysemantic_stack_[(2) - (1)].paragraph); }
    break;

  case 62:

    { (yysemantic_stack_[(2) - (1)].paragraph)->addStmt((yysemantic_stack_[(2) - (2)].stmt)); (yyval.paragraph) = (yysemantic_stack_[(2) - (1)].paragraph); }
    break;

  case 63:

    { (yyval.exp) = new SpringConstantExpression();}
    break;

  case 64:

    { (yyval.exp) = new SpringConstantExpression(true);}
    break;

  case 65:

    { (yyval.exp) = new SpringConstantExpression(false);}
    break;

  case 66:

    { (yyval.exp) = new SpringConstantExpression((yysemantic_stack_[(1) - (1)].m_Int)); }
    break;

  case 67:

    { (yyval.exp) = new SpringConstantExpression((yysemantic_stack_[(1) - (1)].m_Double)); }
    break;

  case 68:

    { (yyval.exp) = new SpringConstantExpression((yysemantic_stack_[(1) - (1)].m_id)); }
    break;

  case 69:

    { (yyval.exp) = new SpringConstantExpression((yysemantic_stack_[(7) - (3)].exp), (yysemantic_stack_[(7) - (6)].paragraph)); }
    break;

  case 70:

    { (yyval.exp) = new SpringConstantExpression((yysemantic_stack_[(6) - (5)].paragraph)); }
    break;

  case 71:

    {
	auto p = new SpringParagraph(); 
	p->addStmt(new SpringJumpStatement(new SpringExpressionList((yysemantic_stack_[(6) - (6)].exp)), scanner.lineno()));
	(yyval.exp) = new SpringConstantExpression((yysemantic_stack_[(6) - (3)].exp), p); }
    break;

  case 72:

    {
	auto p = new SpringParagraph(); 
	p->addStmt(new SpringJumpStatement(new SpringExpressionList((yysemantic_stack_[(5) - (5)].exp)), scanner.lineno()));
	(yyval.exp) = new SpringConstantExpression(p); }
    break;

  case 73:

    { (yyval.exp) = new SpringListDefinitionExpression((yysemantic_stack_[(3) - (2)].expList)); }
    break;

  case 74:

    { (yyval.exp) = new SpringObjectDefinitionExpression((yysemantic_stack_[(3) - (2)].paragraph)); }
    break;

  case 75:

    { (yyval.exp) = new SpringObjectDefinitionExpression(); }
    break;

  case 76:

    {(yyval.exp) = new SpringIDExpression((yysemantic_stack_[(1) - (1)].m_id));}
    break;

  case 77:

    { (yyval.exp) = new SpringPointExpression((yysemantic_stack_[(3) - (1)].exp), new SpringIDExpression((yysemantic_stack_[(3) - (3)].m_id)));}
    break;

  case 78:

    { (yyval.exp) = new SpringSubscriptExpression((yysemantic_stack_[(4) - (1)].exp), (yysemantic_stack_[(4) - (3)].exp));}
    break;

  case 79:

    { (yyval.exp) = (yysemantic_stack_[(3) - (2)].exp); }
    break;

  case 80:

    { (yyval.exp) = new SpringFunctionCallExpression((yysemantic_stack_[(4) - (1)].exp), (yysemantic_stack_[(4) - (3)].expList)); }
    break;

  case 81:

    { (yyval.exp) = new SpringArrowExpression(new SpringIDExpression((yysemantic_stack_[(3) - (1)].m_id)), (yysemantic_stack_[(3) - (3)].exp)); }
    break;

  case 82:

    {(yyval.exp) = new SpringNewExpression(new SpringIDExpression((yysemantic_stack_[(2) - (2)].m_id)));}
    break;

  case 83:

    { (yyval.exp) = new SpringOperatorExpression(100, (yysemantic_stack_[(2) - (2)].exp)); }
    break;

  case 84:

    { (yyval.exp) = new SpringOperatorExpression(101, (yysemantic_stack_[(2) - (2)].exp)); }
    break;

  case 85:

    { (yyval.exp) = new SpringOperatorExpression(102, (yysemantic_stack_[(2) - (2)].exp)); }
    break;

  case 86:

    { (yyval.exp) = new SpringOperatorExpression(103, (yysemantic_stack_[(2) - (2)].exp)); }
    break;

  case 87:

    { (yyval.exp) = new SpringOperatorExpression(104, (yysemantic_stack_[(2) - (1)].exp)); }
    break;

  case 88:

    { (yyval.exp) = new SpringOperatorExpression(105, (yysemantic_stack_[(2) - (1)].exp)); }
    break;

  case 89:

    { (yyval.exp) = new SpringOperatorExpression(106, (yysemantic_stack_[(2) - (2)].exp)); }
    break;

  case 90:

    { (yyval.exp) = new SpringOperatorExpression(107, (yysemantic_stack_[(2) - (2)].exp)); }
    break;

  case 91:

    { (yyval.exp) = new SpringOperatorExpression(200, (yysemantic_stack_[(3) - (1)].exp), (yysemantic_stack_[(3) - (3)].exp)); }
    break;

  case 92:

    { (yyval.exp) = new SpringOperatorExpression(201, (yysemantic_stack_[(3) - (1)].exp), (yysemantic_stack_[(3) - (3)].exp)); }
    break;

  case 93:

    { (yyval.exp) = new SpringOperatorExpression(202, (yysemantic_stack_[(3) - (1)].exp), (yysemantic_stack_[(3) - (3)].exp)); }
    break;

  case 94:

    { (yyval.exp) = new SpringOperatorExpression(203, (yysemantic_stack_[(3) - (1)].exp), (yysemantic_stack_[(3) - (3)].exp)); }
    break;

  case 95:

    { (yyval.exp) = new SpringOperatorExpression(204, (yysemantic_stack_[(3) - (1)].exp), (yysemantic_stack_[(3) - (3)].exp)); }
    break;

  case 96:

    { (yyval.exp) = new SpringOperatorExpression(205, (yysemantic_stack_[(3) - (1)].exp), (yysemantic_stack_[(3) - (3)].exp)); }
    break;

  case 97:

    { (yyval.exp) = new SpringOperatorExpression(206, (yysemantic_stack_[(3) - (1)].exp), (yysemantic_stack_[(3) - (3)].exp)); }
    break;

  case 98:

    { (yyval.exp) = new SpringOperatorExpression(207, (yysemantic_stack_[(3) - (1)].exp), (yysemantic_stack_[(3) - (3)].exp)); }
    break;

  case 99:

    { (yyval.exp) = new SpringOperatorExpression(208, (yysemantic_stack_[(3) - (1)].exp), (yysemantic_stack_[(3) - (3)].exp)); }
    break;

  case 100:

    { (yyval.exp) = new SpringOperatorExpression(209, (yysemantic_stack_[(3) - (1)].exp), (yysemantic_stack_[(3) - (3)].exp)); }
    break;

  case 101:

    { (yyval.exp) = new SpringOperatorExpression(210, (yysemantic_stack_[(3) - (1)].exp), (yysemantic_stack_[(3) - (3)].exp)); }
    break;

  case 102:

    { (yyval.exp) = new SpringOperatorExpression(211, (yysemantic_stack_[(3) - (1)].exp), (yysemantic_stack_[(3) - (3)].exp)); }
    break;

  case 103:

    { (yyval.exp) = new SpringOperatorExpression(212, (yysemantic_stack_[(3) - (1)].exp), (yysemantic_stack_[(3) - (3)].exp)); }
    break;

  case 104:

    { (yyval.exp) = new SpringOperatorExpression(213, (yysemantic_stack_[(3) - (1)].exp), (yysemantic_stack_[(3) - (3)].exp)); }
    break;

  case 105:

    { (yyval.exp) = new SpringOperatorExpression(214, (yysemantic_stack_[(3) - (1)].exp), (yysemantic_stack_[(3) - (3)].exp)); }
    break;

  case 106:

    { (yyval.exp) = new SpringOperatorExpression(215, (yysemantic_stack_[(3) - (1)].exp), (yysemantic_stack_[(3) - (3)].exp)); }
    break;

  case 107:

    { (yyval.exp) = new SpringOperatorExpression(216, (yysemantic_stack_[(3) - (1)].exp), (yysemantic_stack_[(3) - (3)].exp)); }
    break;

  case 108:

    { (yyval.exp) = new SpringOperatorExpression(217, (yysemantic_stack_[(3) - (1)].exp), (yysemantic_stack_[(3) - (3)].exp)); }
    break;

  case 109:

    { (yyval.exp) = new SpringOperatorExpression(218, (yysemantic_stack_[(3) - (1)].exp), (yysemantic_stack_[(3) - (3)].exp)); }
    break;

  case 110:

    { (yyval.exp) = new SpringOperatorExpression((yysemantic_stack_[(3) - (2)].m_Int), (yysemantic_stack_[(3) - (1)].exp), (yysemantic_stack_[(3) - (3)].exp)); }
    break;

  case 111:

    { (yyval.exp) = new SpringOperatorExpression(300, (yysemantic_stack_[(5) - (1)].exp), (yysemantic_stack_[(5) - (3)].exp), (yysemantic_stack_[(5) - (5)].exp)); }
    break;

  case 112:

    { SpringIDExpression* id = new SpringIDExpression((yysemantic_stack_[(1) - (1)].m_id)); (yyval.exp) = new SpringIDListExpression(id); }
    break;

  case 113:

    { SpringIDExpression* id = new SpringIDExpression((yysemantic_stack_[(3) - (1)].m_id), (yysemantic_stack_[(3) - (3)].exp)); (yyval.exp) = new SpringIDListExpression(id); }
    break;

  case 114:

    { SpringIDExpression* id = new SpringIDExpression((yysemantic_stack_[(3) - (1)].m_id)); SpringIDListExpression * n = (SpringIDListExpression *)((yysemantic_stack_[(3) - (3)].exp)); n->add_front(id); (yyval.exp) = n; }
    break;

  case 115:

    { SpringIDExpression* id = new SpringIDExpression((yysemantic_stack_[(5) - (1)].m_id), (yysemantic_stack_[(5) - (3)].exp)); SpringIDListExpression * n = (SpringIDListExpression *)((yysemantic_stack_[(5) - (5)].exp)); n->add_front(id); (yyval.exp) = n; }
    break;

  case 116:

    { (yyval.expList) = new SpringExpressionList((yysemantic_stack_[(1) - (1)].exp)); }
    break;

  case 117:

    { (yysemantic_stack_[(3) - (1)].expList)->add((yysemantic_stack_[(3) - (3)].exp)); (yyval.expList) = (yysemantic_stack_[(3) - (1)].expList); }
    break;

  case 118:

    { (yyval.expList) = nullptr; }
    break;

  case 119:

    { (yyval.expList) = (yysemantic_stack_[(1) - (1)].expList); }
    break;



	default:
          break;
      }
    YY_SYMBOL_PRINT ("-> $$ =", yyr1_[yyn], &yyval, &yyloc);

    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();

    yysemantic_stack_.push (yyval);
    yylocation_stack_.push (yyloc);

    /* Shift the result of the reduction.  */
    yyn = yyr1_[yyn];
    yystate = yypgoto_[yyn - yyntokens_] + yystate_stack_[0];
    if (0 <= yystate && yystate <= yylast_
	&& yycheck_[yystate] == yystate_stack_[0])
      yystate = yytable_[yystate];
    else
      yystate = yydefgoto_[yyn - yyntokens_];
    goto yynewstate;

  /*------------------------------------.
  | yyerrlab -- here on detecting error |
  `------------------------------------*/
  yyerrlab:
    /* If not already recovering from an error, report this error.  */
    if (!yyerrstatus_)
      {
	++yynerrs_;
	error (yylloc, yysyntax_error_ (yystate));
      }

    yyerror_range[0] = yylloc;
    if (yyerrstatus_ == 3)
      {
	/* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

	if (yychar <= yyeof_)
	  {
	  /* Return failure if at end of input.  */
	  if (yychar == yyeof_)
	    YYABORT;
	  }
	else
	  {
	    yydestruct_ ("Error: discarding", yytoken, &yylval, &yylloc);
	    yychar = yyempty_;
	  }
      }

    /* Else will try to reuse lookahead token after shifting the error
       token.  */
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:

    /* Pacify compilers like GCC when the user code never invokes
       YYERROR and the label yyerrorlab therefore never appears in user
       code.  */
    if (false)
      goto yyerrorlab;

    yyerror_range[0] = yylocation_stack_[yylen - 1];
    /* Do not reclaim the symbols of the rule which action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    yystate = yystate_stack_[0];
    goto yyerrlab1;

  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;	/* Each real token shifted decrements this.  */

    for (;;)
      {
	yyn = yypact_[yystate];
	if (yyn != yypact_ninf_)
	{
	  yyn += yyterror_;
	  if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
	    {
	      yyn = yytable_[yyn];
	      if (0 < yyn)
		break;
	    }
	}

	/* Pop the current state because it cannot handle the error token.  */
	if (yystate_stack_.height () == 1)
	YYABORT;

	yyerror_range[0] = yylocation_stack_[0];
	yydestruct_ ("Error: popping",
		     yystos_[yystate],
		     &yysemantic_stack_[0], &yylocation_stack_[0]);
	yypop_ ();
	yystate = yystate_stack_[0];
	YY_STACK_PRINT ();
      }

    yyerror_range[1] = yylloc;
    // Using YYLLOC is tempting, but would change the location of
    // the lookahead.  YYLOC is available though.
    YYLLOC_DEFAULT (yyloc, (yyerror_range - 1), 2);
    yysemantic_stack_.push (yylval);
    yylocation_stack_.push (yyloc);

    /* Shift the error token.  */
    YY_SYMBOL_PRINT ("Shifting", yystos_[yyn],
		     &yysemantic_stack_[0], &yylocation_stack_[0]);

    yystate = yyn;
    goto yynewstate;

    /* Accept.  */
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;

    /* Abort.  */
  yyabortlab:
    yyresult = 1;
    goto yyreturn;

  yyreturn:
    if (yychar != yyempty_)
      yydestruct_ ("Cleanup: discarding lookahead", yytoken, &yylval, &yylloc);

    /* Do not reclaim the symbols of the rule which action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (yystate_stack_.height () != 1)
      {
	yydestruct_ ("Cleanup: popping",
		   yystos_[yystate_stack_[0]],
		   &yysemantic_stack_[0],
		   &yylocation_stack_[0]);
	yypop_ ();
      }

    return yyresult;
  }

  // Generate an error message.
  std::string
  Exa1Parser::yysyntax_error_ (int yystate)
  {
    std::string res;
    YYUSE (yystate);
#if YYERROR_VERBOSE
    int yyn = yypact_[yystate];
    if (yypact_ninf_ < yyn && yyn <= yylast_)
      {
	/* Start YYX at -YYN if negative to avoid negative indexes in
	   YYCHECK.  */
	int yyxbegin = yyn < 0 ? -yyn : 0;

	/* Stay within bounds of both yycheck and yytname.  */
	int yychecklim = yylast_ - yyn + 1;
	int yyxend = yychecklim < yyntokens_ ? yychecklim : yyntokens_;
	int count = 0;
	for (int x = yyxbegin; x < yyxend; ++x)
	  if (yycheck_[x + yyn] == x && x != yyterror_)
	    ++count;

	// FIXME: This method of building the message is not compatible
	// with internationalization.  It should work like yacc.c does it.
	// That is, first build a string that looks like this:
	// "syntax error, unexpected %s or %s or %s"
	// Then, invoke YY_ on this string.
	// Finally, use the string as a format to output
	// yytname_[tok], etc.
	// Until this gets fixed, this message appears in English only.
	res = "syntax error, unexpected ";
	res += yytnamerr_ (yytname_[tok]);
	if (count < 5)
	  {
	    count = 0;
	    for (int x = yyxbegin; x < yyxend; ++x)
	      if (yycheck_[x + yyn] == x && x != yyterror_)
		{
		  res += (!count++) ? ", expecting " : " or ";
		  res += yytnamerr_ (yytname_[x]);
		}
	  }
      }
    else
#endif
      res = YY_("syntax error");
    return res;
  }


  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
  const short int Exa1Parser::yypact_ninf_ = -145;
  const short int
  Exa1Parser::yypact_[] =
  {
      2755,   267,   267,   267,   267,   267,   267,   -30,   267,     6,
     267,   -28,   -28,   -28,   -28,  -145,  -145,   -36,    21,    37,
      38,  -145,  -145,    -8,  -145,  -145,  -145,   267,   267,   267,
     267,   454,  -145,    85,  -145,  -145,  -145,  2755,   774,   -49,
     -43,    58,    50,    50,    50,    50,  2819,  2819,    64,  2819,
     -28,  2977,    25,   -28,  -145,  -145,  -145,  -145,    34,   -39,
    -145,   -20,    17,   -28,   267,   267,    44,    50,    42,  2838,
      60,    39,    45,    66,    68,    69,    70,    71,    72,    73,
      74,    56,    77,    80,    81,    63,    83,    86,    88,    79,
      89,    11,    90,    92,    93,    97,   117,    12,   121,  -145,
    -145,  -145,   518,  -145,  -145,   267,  -145,  -145,   267,   267,
     267,   267,   267,   267,   267,   267,   267,   267,   267,   267,
     267,   267,   267,   267,   267,   267,   267,   267,   267,   267,
     122,  -145,   267,   267,  2755,  2755,   145,  -145,   267,  -145,
    -145,  -145,    20,   -19,   111,   128,   710,   267,    38,  -145,
    2977,   774,  -145,  -145,   110,  2755,  2755,   113,   115,   116,
     118,   119,   120,   123,   125,  2755,   129,   130,   131,  2755,
     132,   133,   134,   137,  2755,   138,   139,   142,  2755,   126,
     143,   114,   144,  -145,  -145,  -145,    28,  3290,  3290,  3290,
    3290,  3212,  3212,  3074,  3056,  3230,  3134,  3152,    16,    16,
    2977,  2898,    44,    44,    50,    50,    50,  2917,   127,  -145,
      -4,  2977,  -145,   817,   -14,  2819,   146,   150,   267,  2755,
     -18,   148,   582,   389,  -145,  -145,  2755,   874,   931,  2755,
    2755,  2755,  2755,  2755,  2755,  2755,  2755,   988,  2755,  2755,
    2755,  1045,  2755,  2755,  2755,  2755,  1102,  2755,  2755,  2755,
    1159,   152,  2755,   153,  2755,   267,  -145,  -145,  -145,  -145,
    -145,  -145,  2755,   154,  2977,  1216,   267,  2755,   710,  -145,
      38,  1273,  -145,  -145,  1330,  1387,  1444,  1501,  1558,  1615,
    1672,  1729,  -145,  1786,  1843,  1900,  -145,  1957,  2014,  2071,
    2128,  -145,  2185,  2242,  2299,  -145,  2755,  2356,  2755,  2413,
    2996,  2470,  2755,  -145,  2977,  2527,   646,  -145,  -145,  -145,
    -145,  -145,  -145,  -145,  -145,  -145,  -145,  -145,  -145,  -145,
    -145,  -145,  -145,  -145,  -145,  -145,  -145,  2584,  -145,  2641,
    -145,  -145,  2698,  -145,  -145,  -145,  -145,  -145
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned char
  Exa1Parser::yydefact_[] =
  {
         0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     118,     0,     0,     0,     0,    64,    65,     0,     0,     0,
       0,    63,    54,    76,    68,    66,    67,     0,     0,   118,
       0,     0,    53,     0,    55,     4,    17,     2,   116,     0,
       0,    76,    85,    86,    90,    89,     0,     0,     0,     0,
       0,   116,   119,     0,     7,     8,     9,    10,     0,     0,
      82,     0,   112,     0,     0,     0,    84,    83,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    75,
      59,    60,     0,     1,    56,     0,    87,    88,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   118,
       0,     6,     0,     0,     0,     0,    13,    14,     0,    15,
       3,    11,     0,     0,     0,     0,     0,     0,     0,    18,
      81,     0,    73,    79,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    74,    61,    62,    94,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,     0,    91,    92,    93,    95,    96,     0,     0,    77,
       0,   117,    57,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   113,   114,    19,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    78,    80,     5,    58,
      12,    16,     0,     0,    72,     0,     0,     0,     0,    22,
       0,     0,    49,    50,     0,     0,     0,     0,     0,     0,
       0,     0,    52,     0,     0,     0,    51,     0,     0,     0,
       0,    48,     0,     0,     0,    47,     0,     0,     0,     0,
     111,     0,     0,    70,    71,     0,     0,   115,    27,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    24,    25,    26,    28,    29,     0,    45,     0,
      43,    21,     0,    69,    23,    44,    46,    20
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  Exa1Parser::yypgoto_[] =
  {
      -145,  -145,   -37,   -23,  -101,    14,   124,   -44,  -144,    31,
     -55,     0,   -22
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  Exa1Parser::yydefgoto_[] =
  {
        -1,    33,    34,    35,   101,    36,    37,   136,   102,    38,
      63,    39,    53
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const signed char Exa1Parser::yytable_ninf_ = -1;
  const short int
  Exa1Parser::yytable_[] =
  {
       104,   185,   222,   137,   144,   139,    62,    68,   100,    58,
      52,   145,   218,   266,   132,    48,    22,    59,   133,   105,
     106,   107,   143,    64,    59,    54,    55,    56,    57,    52,
     134,   105,    42,    43,    44,    45,    46,    47,    32,    49,
      22,    51,   181,    65,   146,   219,   267,   105,   106,   107,
     135,    50,   131,   105,   106,   107,   173,    62,    66,    67,
      51,    69,    32,   133,   140,    62,    60,   141,   123,   124,
     125,   126,   127,   180,   128,   174,   129,   149,   130,   184,
     147,   216,    61,    62,   148,   103,   128,   217,   129,    64,
     130,   138,   133,   224,   142,   150,   151,   212,   125,   126,
     127,   152,   128,   155,   129,   154,   130,   208,   128,   156,
     129,   157,   130,   158,   159,   160,   161,   162,   163,   164,
     165,   185,   166,   100,   306,   167,   168,   169,   170,    52,
      65,   171,   210,    58,   172,   175,   186,   176,   177,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
      51,   178,   179,    51,   211,   225,   182,   209,   214,   215,
     260,   261,   220,   221,   226,   253,   104,   229,   223,   230,
     231,     0,   232,   233,   234,   251,     0,   235,   257,   236,
     104,   104,     0,   238,   239,   240,   242,   243,   244,   184,
     104,   245,   247,   248,   104,   185,   249,   252,   254,   104,
     262,   263,   268,   104,     0,   307,   296,   298,   302,     0,
       0,     0,     0,     0,   258,     0,     0,     0,   104,     0,
       0,     0,     0,     0,   104,     0,     0,   104,   104,   104,
     104,   104,   104,   104,   104,   100,   104,   104,   104,   264,
     104,   104,   104,   104,     0,   104,   104,   104,     0,   213,
     104,     0,   104,     0,   104,     0,     0,     0,   104,     0,
       0,     1,     2,     0,     0,     0,     0,     0,     0,   227,
     228,     3,     0,   184,     0,     4,   300,     0,     0,   237,
     104,     0,   104,   241,     0,   104,     0,   304,   246,     0,
       0,     0,   250,     0,    15,    16,    40,    18,     0,     0,
      21,     0,    41,    24,     0,    25,    26,     0,     0,     0,
      27,     0,     0,     0,    28,    29,     0,    30,     0,     0,
       0,    31,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   265,     0,     0,     0,     0,     0,     0,
     271,     0,     0,   274,   275,   276,   277,   278,   279,   280,
     281,     0,   283,   284,   285,     0,   287,   288,   289,   290,
       0,   292,   293,   294,     0,     0,   297,     0,   299,     0,
       0,     0,     0,     0,     0,     0,   301,     0,     0,     0,
       0,   305,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,     0,   116,   117,   118,     0,   119,   120,
     121,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     327,     0,   329,     0,     0,     0,   332,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   122,
       0,   123,   124,   125,   126,   127,     0,   128,     0,   129,
       0,   130,     0,     0,     0,     0,   270,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    88,     0,    19,    20,     0,    22,    89,
       0,     0,     0,     0,     0,     0,    90,    91,    92,    93,
      94,    95,    96,     0,    97,     0,    98,     0,     0,    99,
      32,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    88,     0,    19,
      20,     0,    22,    89,     0,     0,     0,     0,     0,     0,
      90,    91,    92,    93,    94,    95,    96,     0,    97,     0,
      98,     0,     0,   183,    32,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    88,     0,    19,    20,     0,    22,    89,     0,     0,
       0,     0,     0,     0,    90,    91,    92,    93,    94,    95,
      96,     0,    97,     0,    98,     0,     0,   269,    32,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    88,     0,    19,    20,     0,
      22,    89,     0,     0,     0,     0,     0,     0,    90,    91,
      92,    93,    94,    95,    96,     0,    97,     0,    98,     0,
       0,   334,    32,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    88,
       0,    19,    20,     0,    22,    89,     0,     0,     0,     0,
       0,     0,    90,    91,    92,    93,    94,    95,    96,     0,
      97,     0,    98,     0,     0,     0,    32,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,     0,   116,
     117,   118,     0,   119,   120,   121,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    22,     0,
       0,     1,     2,     0,   122,     0,   123,   124,   125,   126,
     127,     3,   128,     0,   129,     4,   130,     0,     0,     5,
      32,     6,     0,     7,     0,     8,     0,     9,     0,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,     0,    25,    26,     0,     0,     0,
      27,     0,     0,     0,    28,    29,     0,    30,     1,     2,
       0,    31,   259,    32,     0,     0,     0,     0,     3,     0,
       0,     0,     4,     0,     0,     0,     5,     0,     6,     0,
       7,     0,     8,     0,     9,     0,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,     0,    25,    26,     0,     0,     0,    27,     0,     0,
       0,    28,    29,     0,    30,     1,     2,     0,    31,   272,
      32,     0,     0,     0,     0,     3,     0,     0,     0,     4,
       0,     0,     0,     5,     0,     6,     0,     7,     0,     8,
       0,     9,     0,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,     0,    25,
      26,     0,     0,     0,    27,     0,     0,     0,    28,    29,
       0,    30,     1,     2,     0,    31,   273,    32,     0,     0,
       0,     0,     3,     0,     0,     0,     4,     0,     0,     0,
       5,     0,     6,     0,     7,     0,     8,     0,     9,     0,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,     0,    25,    26,     0,     0,
       0,    27,     0,     0,     0,    28,    29,     0,    30,     1,
       2,     0,    31,   282,    32,     0,     0,     0,     0,     3,
       0,     0,     0,     4,     0,     0,     0,     5,     0,     6,
       0,     7,     0,     8,     0,     9,     0,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,     0,    25,    26,     0,     0,     0,    27,     0,
       0,     0,    28,    29,     0,    30,     1,     2,     0,    31,
     286,    32,     0,     0,     0,     0,     3,     0,     0,     0,
       4,     0,     0,     0,     5,     0,     6,     0,     7,     0,
       8,     0,     9,     0,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,     0,
      25,    26,     0,     0,     0,    27,     0,     0,     0,    28,
      29,     0,    30,     1,     2,     0,    31,   291,    32,     0,
       0,     0,     0,     3,     0,     0,     0,     4,     0,     0,
       0,     5,     0,     6,     0,     7,     0,     8,     0,     9,
       0,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,     0,    25,    26,     0,
       0,     0,    27,     0,     0,     0,    28,    29,     0,    30,
       1,     2,     0,    31,   295,    32,     0,     0,     0,     0,
       3,     0,     0,     0,     4,     0,     0,     0,     5,     0,
       6,     0,     7,     0,     8,     0,     9,     0,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,     0,    25,    26,     0,     0,     0,    27,
       0,     0,     0,    28,    29,     0,    30,     1,     2,     0,
      31,   303,    32,     0,     0,     0,     0,     3,     0,     0,
       0,     4,     0,     0,     0,     5,     0,     6,     0,     7,
       0,     8,     0,     9,     0,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
       0,    25,    26,     0,     0,     0,    27,     0,     0,     0,
      28,    29,     0,    30,     1,     2,     0,    31,   308,    32,
       0,     0,     0,     0,     3,     0,     0,     0,     4,     0,
       0,     0,     5,     0,     6,     0,     7,     0,     8,     0,
       9,     0,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,     0,    25,    26,
       0,     0,     0,    27,     0,     0,     0,    28,    29,     0,
      30,     1,     2,     0,    31,   309,    32,     0,     0,     0,
       0,     3,     0,     0,     0,     4,     0,     0,     0,     5,
       0,     6,     0,     7,     0,     8,     0,     9,     0,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,     0,    25,    26,     0,     0,     0,
      27,     0,     0,     0,    28,    29,     0,    30,     1,     2,
       0,    31,   310,    32,     0,     0,     0,     0,     3,     0,
       0,     0,     4,     0,     0,     0,     5,     0,     6,     0,
       7,     0,     8,     0,     9,     0,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,     0,    25,    26,     0,     0,     0,    27,     0,     0,
       0,    28,    29,     0,    30,     1,     2,     0,    31,   311,
      32,     0,     0,     0,     0,     3,     0,     0,     0,     4,
       0,     0,     0,     5,     0,     6,     0,     7,     0,     8,
       0,     9,     0,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,     0,    25,
      26,     0,     0,     0,    27,     0,     0,     0,    28,    29,
       0,    30,     1,     2,     0,    31,   312,    32,     0,     0,
       0,     0,     3,     0,     0,     0,     4,     0,     0,     0,
       5,     0,     6,     0,     7,     0,     8,     0,     9,     0,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,     0,    25,    26,     0,     0,
       0,    27,     0,     0,     0,    28,    29,     0,    30,     1,
       2,     0,    31,   313,    32,     0,     0,     0,     0,     3,
       0,     0,     0,     4,     0,     0,     0,     5,     0,     6,
       0,     7,     0,     8,     0,     9,     0,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,     0,    25,    26,     0,     0,     0,    27,     0,
       0,     0,    28,    29,     0,    30,     1,     2,     0,    31,
     314,    32,     0,     0,     0,     0,     3,     0,     0,     0,
       4,     0,     0,     0,     5,     0,     6,     0,     7,     0,
       8,     0,     9,     0,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,     0,
      25,    26,     0,     0,     0,    27,     0,     0,     0,    28,
      29,     0,    30,     1,     2,     0,    31,   315,    32,     0,
       0,     0,     0,     3,     0,     0,     0,     4,     0,     0,
       0,     5,     0,     6,     0,     7,     0,     8,     0,     9,
       0,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,     0,    25,    26,     0,
       0,     0,    27,     0,     0,     0,    28,    29,     0,    30,
       1,     2,     0,    31,   316,    32,     0,     0,     0,     0,
       3,     0,     0,     0,     4,     0,     0,     0,     5,     0,
       6,     0,     7,     0,     8,     0,     9,     0,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,     0,    25,    26,     0,     0,     0,    27,
       0,     0,     0,    28,    29,     0,    30,     1,     2,     0,
      31,   317,    32,     0,     0,     0,     0,     3,     0,     0,
       0,     4,     0,     0,     0,     5,     0,     6,     0,     7,
       0,     8,     0,     9,     0,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
       0,    25,    26,     0,     0,     0,    27,     0,     0,     0,
      28,    29,     0,    30,     1,     2,     0,    31,   318,    32,
       0,     0,     0,     0,     3,     0,     0,     0,     4,     0,
       0,     0,     5,     0,     6,     0,     7,     0,     8,     0,
       9,     0,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,     0,    25,    26,
       0,     0,     0,    27,     0,     0,     0,    28,    29,     0,
      30,     1,     2,     0,    31,   319,    32,     0,     0,     0,
       0,     3,     0,     0,     0,     4,     0,     0,     0,     5,
       0,     6,     0,     7,     0,     8,     0,     9,     0,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,     0,    25,    26,     0,     0,     0,
      27,     0,     0,     0,    28,    29,     0,    30,     1,     2,
       0,    31,   320,    32,     0,     0,     0,     0,     3,     0,
       0,     0,     4,     0,     0,     0,     5,     0,     6,     0,
       7,     0,     8,     0,     9,     0,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,     0,    25,    26,     0,     0,     0,    27,     0,     0,
       0,    28,    29,     0,    30,     1,     2,     0,    31,   321,
      32,     0,     0,     0,     0,     3,     0,     0,     0,     4,
       0,     0,     0,     5,     0,     6,     0,     7,     0,     8,
       0,     9,     0,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,     0,    25,
      26,     0,     0,     0,    27,     0,     0,     0,    28,    29,
       0,    30,     1,     2,     0,    31,   322,    32,     0,     0,
       0,     0,     3,     0,     0,     0,     4,     0,     0,     0,
       5,     0,     6,     0,     7,     0,     8,     0,     9,     0,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,     0,    25,    26,     0,     0,
       0,    27,     0,     0,     0,    28,    29,     0,    30,     1,
       2,     0,    31,   323,    32,     0,     0,     0,     0,     3,
       0,     0,     0,     4,     0,     0,     0,     5,     0,     6,
       0,     7,     0,     8,     0,     9,     0,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,     0,    25,    26,     0,     0,     0,    27,     0,
       0,     0,    28,    29,     0,    30,     1,     2,     0,    31,
     324,    32,     0,     0,     0,     0,     3,     0,     0,     0,
       4,     0,     0,     0,     5,     0,     6,     0,     7,     0,
       8,     0,     9,     0,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,     0,
      25,    26,     0,     0,     0,    27,     0,     0,     0,    28,
      29,     0,    30,     1,     2,     0,    31,   325,    32,     0,
       0,     0,     0,     3,     0,     0,     0,     4,     0,     0,
       0,     5,     0,     6,     0,     7,     0,     8,     0,     9,
       0,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,     0,    25,    26,     0,
       0,     0,    27,     0,     0,     0,    28,    29,     0,    30,
       1,     2,     0,    31,   326,    32,     0,     0,     0,     0,
       3,     0,     0,     0,     4,     0,     0,     0,     5,     0,
       6,     0,     7,     0,     8,     0,     9,     0,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,     0,    25,    26,     0,     0,     0,    27,
       0,     0,     0,    28,    29,     0,    30,     1,     2,     0,
      31,   328,    32,     0,     0,     0,     0,     3,     0,     0,
       0,     4,     0,     0,     0,     5,     0,     6,     0,     7,
       0,     8,     0,     9,     0,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
       0,    25,    26,     0,     0,     0,    27,     0,     0,     0,
      28,    29,     0,    30,     1,     2,     0,    31,   330,    32,
       0,     0,     0,     0,     3,     0,     0,     0,     4,     0,
       0,     0,     5,     0,     6,     0,     7,     0,     8,     0,
       9,     0,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,     0,    25,    26,
       0,     0,     0,    27,     0,     0,     0,    28,    29,     0,
      30,     1,     2,     0,    31,   331,    32,     0,     0,     0,
       0,     3,     0,     0,     0,     4,     0,     0,     0,     5,
       0,     6,     0,     7,     0,     8,     0,     9,     0,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,     0,    25,    26,     0,     0,     0,
      27,     0,     0,     0,    28,    29,     0,    30,     1,     2,
       0,    31,   333,    32,     0,     0,     0,     0,     3,     0,
       0,     0,     4,     0,     0,     0,     5,     0,     6,     0,
       7,     0,     8,     0,     9,     0,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,     0,    25,    26,     0,     0,     0,    27,     0,     0,
       0,    28,    29,     0,    30,     1,     2,     0,    31,   335,
      32,     0,     0,     0,     0,     3,     0,     0,     0,     4,
       0,     0,     0,     5,     0,     6,     0,     7,     0,     8,
       0,     9,     0,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,     0,    25,
      26,     0,     0,     0,    27,     0,     0,     0,    28,    29,
       0,    30,     1,     2,     0,    31,   336,    32,     0,     0,
       0,     0,     3,     0,     0,     0,     4,     0,     0,     0,
       5,     0,     6,     0,     7,     0,     8,     0,     9,     0,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,     0,    25,    26,     0,     0,
       0,    27,     0,     0,     0,    28,    29,     0,    30,     1,
       2,     0,    31,   337,    32,     0,     0,     0,     0,     3,
       0,     0,     0,     4,     0,     0,     0,     5,     0,     6,
       0,     7,     0,     8,     0,     9,     0,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,     0,    25,    26,     0,     0,     0,    27,     0,
       0,     0,    28,    29,     0,    30,     0,     0,     0,    31,
       0,    32,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,     0,   116,   117,   118,     0,   119,   120,
     121,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,     0,   116,   117,   118,     0,   119,   120,   121,
       0,     0,     0,   134,     0,     0,     0,     0,     0,   122,
       0,   123,   124,   125,   126,   127,     0,   128,     0,   129,
       0,   130,     0,   135,     0,     0,     0,     0,   122,     0,
     123,   124,   125,   126,   127,     0,   128,     0,   129,   153,
     130,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,     0,   116,   117,   118,     0,   119,   120,   121,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,     0,   116,   117,   118,     0,   119,   120,   121,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   122,   255,
     123,   124,   125,   126,   127,     0,   128,     0,   129,     0,
     130,     0,     0,     0,     0,     0,     0,   122,     0,   123,
     124,   125,   126,   127,     0,   128,   256,   129,     0,   130,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,     0,   116,   117,   118,     0,   119,   120,   121,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
       0,   116,   117,   118,     0,   119,   120,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   122,     0,   123,
     124,   125,   126,   127,     0,   128,     0,   129,     0,   130,
       0,     0,     0,     0,     0,     0,   122,     0,   123,   124,
     125,   126,   127,     0,   128,     0,   129,     0,   130,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,     0,
       0,   116,   117,   118,     0,   119,   120,   105,   106,   107,
     108,   109,   110,   111,   112,   113,     0,     0,     0,   116,
     117,   118,     0,   119,   120,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   123,   124,
     125,   126,   127,     0,   128,     0,   129,     0,   130,     0,
       0,     0,     0,     0,     0,     0,   123,   124,   125,   126,
     127,     0,   128,     0,   129,     0,   130,   105,   106,   107,
     108,   109,   110,   111,   112,   113,     0,     0,     0,   116,
       0,   118,     0,   119,   120,   105,   106,   107,   108,   109,
     110,   111,   112,   113,     0,     0,     0,   116,     0,     0,
       0,   119,   120,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   123,   124,   125,   126,
     127,     0,   128,     0,   129,     0,   130,     0,     0,     0,
       0,     0,     0,     0,   123,   124,   125,   126,   127,     0,
     128,     0,   129,     0,   130,   105,   106,   107,   108,   109,
     110,   111,    -1,    -1,     0,     0,     0,     0,     0,     0,
       0,   119,   120,   105,   106,   107,   108,   109,   110,   111,
     112,   113,     0,     0,     0,     0,     0,     0,     0,   119,
     120,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   123,   124,   125,   126,   127,     0,
     128,     0,   129,     0,   130,     0,     0,     0,     0,     0,
       0,     0,   123,   124,   125,   126,   127,     0,   128,     0,
     129,     0,   130,   105,   106,   107,    -1,    -1,    -1,    -1,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   119,
     120,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   123,   124,   125,   126,   127,     0,   128,     0,
     129,     0,   130
  };

  /* YYCHECK.  */
  const short int
  Exa1Parser::yycheck_[] =
  {
        37,   102,   146,    47,    59,    49,    45,    29,    31,    45,
      10,    31,    31,    31,    63,    45,    44,    60,    67,     3,
       4,     5,    61,    31,    60,    11,    12,    13,    14,    29,
      44,     3,     1,     2,     3,     4,     5,     6,    66,     8,
      44,    10,    97,    51,    64,    64,    64,     3,     4,     5,
      64,    45,    38,     3,     4,     5,    45,    45,    27,    28,
      29,    30,    66,    67,    50,    45,    45,    53,    52,    53,
      54,    55,    56,    61,    58,    64,    60,    63,    62,   102,
      63,    61,    45,    45,    67,     0,    58,   142,    60,    31,
      62,    27,    67,   148,    60,    64,    65,   134,    54,    55,
      56,    59,    58,    64,    60,    45,    62,   129,    58,    64,
      60,    45,    62,    45,    45,    45,    45,    45,    45,    45,
      64,   222,    45,   146,   268,    45,    45,    64,    45,   129,
      51,    45,   132,    45,    45,    45,   105,    45,    45,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,    64,    45,   132,   133,   151,    45,    45,    23,   138,
     214,   215,    61,    45,    64,    61,   213,    64,   147,    64,
      64,    -1,    64,    64,    64,    59,    -1,    64,    61,    64,
     227,   228,    -1,    64,    64,    64,    64,    64,    64,   222,
     237,    64,    64,    64,   241,   306,    64,    64,    64,   246,
      64,    61,    64,   250,    -1,   270,    64,    64,    64,    -1,
      -1,    -1,    -1,    -1,   210,    -1,    -1,    -1,   265,    -1,
      -1,    -1,    -1,    -1,   271,    -1,    -1,   274,   275,   276,
     277,   278,   279,   280,   281,   268,   283,   284,   285,   218,
     287,   288,   289,   290,    -1,   292,   293,   294,    -1,   135,
     297,    -1,   299,    -1,   301,    -1,    -1,    -1,   305,    -1,
      -1,     4,     5,    -1,    -1,    -1,    -1,    -1,    -1,   155,
     156,    14,    -1,   306,    -1,    18,   255,    -1,    -1,   165,
     327,    -1,   329,   169,    -1,   332,    -1,   266,   174,    -1,
      -1,    -1,   178,    -1,    37,    38,    39,    40,    -1,    -1,
      43,    -1,    45,    46,    -1,    48,    49,    -1,    -1,    -1,
      53,    -1,    -1,    -1,    57,    58,    -1,    60,    -1,    -1,
      -1,    64,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   219,    -1,    -1,    -1,    -1,    -1,    -1,
     226,    -1,    -1,   229,   230,   231,   232,   233,   234,   235,
     236,    -1,   238,   239,   240,    -1,   242,   243,   244,   245,
      -1,   247,   248,   249,    -1,    -1,   252,    -1,   254,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   262,    -1,    -1,    -1,
      -1,   267,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    -1,    15,    16,    17,    -1,    19,    20,
      21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     296,    -1,   298,    -1,    -1,    -1,   302,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,
      -1,    52,    53,    54,    55,    56,    -1,    58,    -1,    60,
      -1,    62,    -1,    -1,    -1,    -1,    67,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    39,    -1,    41,    42,    -1,    44,    45,
      -1,    -1,    -1,    -1,    -1,    -1,    52,    53,    54,    55,
      56,    57,    58,    -1,    60,    -1,    62,    -1,    -1,    65,
      66,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    39,    -1,    41,
      42,    -1,    44,    45,    -1,    -1,    -1,    -1,    -1,    -1,
      52,    53,    54,    55,    56,    57,    58,    -1,    60,    -1,
      62,    -1,    -1,    65,    66,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    39,    -1,    41,    42,    -1,    44,    45,    -1,    -1,
      -1,    -1,    -1,    -1,    52,    53,    54,    55,    56,    57,
      58,    -1,    60,    -1,    62,    -1,    -1,    65,    66,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    39,    -1,    41,    42,    -1,
      44,    45,    -1,    -1,    -1,    -1,    -1,    -1,    52,    53,
      54,    55,    56,    57,    58,    -1,    60,    -1,    62,    -1,
      -1,    65,    66,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    39,
      -1,    41,    42,    -1,    44,    45,    -1,    -1,    -1,    -1,
      -1,    -1,    52,    53,    54,    55,    56,    57,    58,    -1,
      60,    -1,    62,    -1,    -1,    -1,    66,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    -1,    15,
      16,    17,    -1,    19,    20,    21,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,    -1,
      -1,     4,     5,    -1,    50,    -1,    52,    53,    54,    55,
      56,    14,    58,    -1,    60,    18,    62,    -1,    -1,    22,
      66,    24,    -1,    26,    -1,    28,    -1,    30,    -1,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    -1,    48,    49,    -1,    -1,    -1,
      53,    -1,    -1,    -1,    57,    58,    -1,    60,     4,     5,
      -1,    64,    65,    66,    -1,    -1,    -1,    -1,    14,    -1,
      -1,    -1,    18,    -1,    -1,    -1,    22,    -1,    24,    -1,
      26,    -1,    28,    -1,    30,    -1,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    -1,    48,    49,    -1,    -1,    -1,    53,    -1,    -1,
      -1,    57,    58,    -1,    60,     4,     5,    -1,    64,    65,
      66,    -1,    -1,    -1,    -1,    14,    -1,    -1,    -1,    18,
      -1,    -1,    -1,    22,    -1,    24,    -1,    26,    -1,    28,
      -1,    30,    -1,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    -1,    48,
      49,    -1,    -1,    -1,    53,    -1,    -1,    -1,    57,    58,
      -1,    60,     4,     5,    -1,    64,    65,    66,    -1,    -1,
      -1,    -1,    14,    -1,    -1,    -1,    18,    -1,    -1,    -1,
      22,    -1,    24,    -1,    26,    -1,    28,    -1,    30,    -1,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    -1,    48,    49,    -1,    -1,
      -1,    53,    -1,    -1,    -1,    57,    58,    -1,    60,     4,
       5,    -1,    64,    65,    66,    -1,    -1,    -1,    -1,    14,
      -1,    -1,    -1,    18,    -1,    -1,    -1,    22,    -1,    24,
      -1,    26,    -1,    28,    -1,    30,    -1,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    -1,    48,    49,    -1,    -1,    -1,    53,    -1,
      -1,    -1,    57,    58,    -1,    60,     4,     5,    -1,    64,
      65,    66,    -1,    -1,    -1,    -1,    14,    -1,    -1,    -1,
      18,    -1,    -1,    -1,    22,    -1,    24,    -1,    26,    -1,
      28,    -1,    30,    -1,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    -1,
      48,    49,    -1,    -1,    -1,    53,    -1,    -1,    -1,    57,
      58,    -1,    60,     4,     5,    -1,    64,    65,    66,    -1,
      -1,    -1,    -1,    14,    -1,    -1,    -1,    18,    -1,    -1,
      -1,    22,    -1,    24,    -1,    26,    -1,    28,    -1,    30,
      -1,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    -1,    48,    49,    -1,
      -1,    -1,    53,    -1,    -1,    -1,    57,    58,    -1,    60,
       4,     5,    -1,    64,    65,    66,    -1,    -1,    -1,    -1,
      14,    -1,    -1,    -1,    18,    -1,    -1,    -1,    22,    -1,
      24,    -1,    26,    -1,    28,    -1,    30,    -1,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    -1,    48,    49,    -1,    -1,    -1,    53,
      -1,    -1,    -1,    57,    58,    -1,    60,     4,     5,    -1,
      64,    65,    66,    -1,    -1,    -1,    -1,    14,    -1,    -1,
      -1,    18,    -1,    -1,    -1,    22,    -1,    24,    -1,    26,
      -1,    28,    -1,    30,    -1,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      -1,    48,    49,    -1,    -1,    -1,    53,    -1,    -1,    -1,
      57,    58,    -1,    60,     4,     5,    -1,    64,    65,    66,
      -1,    -1,    -1,    -1,    14,    -1,    -1,    -1,    18,    -1,
      -1,    -1,    22,    -1,    24,    -1,    26,    -1,    28,    -1,
      30,    -1,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    -1,    48,    49,
      -1,    -1,    -1,    53,    -1,    -1,    -1,    57,    58,    -1,
      60,     4,     5,    -1,    64,    65,    66,    -1,    -1,    -1,
      -1,    14,    -1,    -1,    -1,    18,    -1,    -1,    -1,    22,
      -1,    24,    -1,    26,    -1,    28,    -1,    30,    -1,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    -1,    48,    49,    -1,    -1,    -1,
      53,    -1,    -1,    -1,    57,    58,    -1,    60,     4,     5,
      -1,    64,    65,    66,    -1,    -1,    -1,    -1,    14,    -1,
      -1,    -1,    18,    -1,    -1,    -1,    22,    -1,    24,    -1,
      26,    -1,    28,    -1,    30,    -1,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    -1,    48,    49,    -1,    -1,    -1,    53,    -1,    -1,
      -1,    57,    58,    -1,    60,     4,     5,    -1,    64,    65,
      66,    -1,    -1,    -1,    -1,    14,    -1,    -1,    -1,    18,
      -1,    -1,    -1,    22,    -1,    24,    -1,    26,    -1,    28,
      -1,    30,    -1,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    -1,    48,
      49,    -1,    -1,    -1,    53,    -1,    -1,    -1,    57,    58,
      -1,    60,     4,     5,    -1,    64,    65,    66,    -1,    -1,
      -1,    -1,    14,    -1,    -1,    -1,    18,    -1,    -1,    -1,
      22,    -1,    24,    -1,    26,    -1,    28,    -1,    30,    -1,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    -1,    48,    49,    -1,    -1,
      -1,    53,    -1,    -1,    -1,    57,    58,    -1,    60,     4,
       5,    -1,    64,    65,    66,    -1,    -1,    -1,    -1,    14,
      -1,    -1,    -1,    18,    -1,    -1,    -1,    22,    -1,    24,
      -1,    26,    -1,    28,    -1,    30,    -1,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    -1,    48,    49,    -1,    -1,    -1,    53,    -1,
      -1,    -1,    57,    58,    -1,    60,     4,     5,    -1,    64,
      65,    66,    -1,    -1,    -1,    -1,    14,    -1,    -1,    -1,
      18,    -1,    -1,    -1,    22,    -1,    24,    -1,    26,    -1,
      28,    -1,    30,    -1,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    -1,
      48,    49,    -1,    -1,    -1,    53,    -1,    -1,    -1,    57,
      58,    -1,    60,     4,     5,    -1,    64,    65,    66,    -1,
      -1,    -1,    -1,    14,    -1,    -1,    -1,    18,    -1,    -1,
      -1,    22,    -1,    24,    -1,    26,    -1,    28,    -1,    30,
      -1,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    -1,    48,    49,    -1,
      -1,    -1,    53,    -1,    -1,    -1,    57,    58,    -1,    60,
       4,     5,    -1,    64,    65,    66,    -1,    -1,    -1,    -1,
      14,    -1,    -1,    -1,    18,    -1,    -1,    -1,    22,    -1,
      24,    -1,    26,    -1,    28,    -1,    30,    -1,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    -1,    48,    49,    -1,    -1,    -1,    53,
      -1,    -1,    -1,    57,    58,    -1,    60,     4,     5,    -1,
      64,    65,    66,    -1,    -1,    -1,    -1,    14,    -1,    -1,
      -1,    18,    -1,    -1,    -1,    22,    -1,    24,    -1,    26,
      -1,    28,    -1,    30,    -1,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      -1,    48,    49,    -1,    -1,    -1,    53,    -1,    -1,    -1,
      57,    58,    -1,    60,     4,     5,    -1,    64,    65,    66,
      -1,    -1,    -1,    -1,    14,    -1,    -1,    -1,    18,    -1,
      -1,    -1,    22,    -1,    24,    -1,    26,    -1,    28,    -1,
      30,    -1,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    -1,    48,    49,
      -1,    -1,    -1,    53,    -1,    -1,    -1,    57,    58,    -1,
      60,     4,     5,    -1,    64,    65,    66,    -1,    -1,    -1,
      -1,    14,    -1,    -1,    -1,    18,    -1,    -1,    -1,    22,
      -1,    24,    -1,    26,    -1,    28,    -1,    30,    -1,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    -1,    48,    49,    -1,    -1,    -1,
      53,    -1,    -1,    -1,    57,    58,    -1,    60,     4,     5,
      -1,    64,    65,    66,    -1,    -1,    -1,    -1,    14,    -1,
      -1,    -1,    18,    -1,    -1,    -1,    22,    -1,    24,    -1,
      26,    -1,    28,    -1,    30,    -1,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    -1,    48,    49,    -1,    -1,    -1,    53,    -1,    -1,
      -1,    57,    58,    -1,    60,     4,     5,    -1,    64,    65,
      66,    -1,    -1,    -1,    -1,    14,    -1,    -1,    -1,    18,
      -1,    -1,    -1,    22,    -1,    24,    -1,    26,    -1,    28,
      -1,    30,    -1,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    -1,    48,
      49,    -1,    -1,    -1,    53,    -1,    -1,    -1,    57,    58,
      -1,    60,     4,     5,    -1,    64,    65,    66,    -1,    -1,
      -1,    -1,    14,    -1,    -1,    -1,    18,    -1,    -1,    -1,
      22,    -1,    24,    -1,    26,    -1,    28,    -1,    30,    -1,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    -1,    48,    49,    -1,    -1,
      -1,    53,    -1,    -1,    -1,    57,    58,    -1,    60,     4,
       5,    -1,    64,    65,    66,    -1,    -1,    -1,    -1,    14,
      -1,    -1,    -1,    18,    -1,    -1,    -1,    22,    -1,    24,
      -1,    26,    -1,    28,    -1,    30,    -1,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    -1,    48,    49,    -1,    -1,    -1,    53,    -1,
      -1,    -1,    57,    58,    -1,    60,     4,     5,    -1,    64,
      65,    66,    -1,    -1,    -1,    -1,    14,    -1,    -1,    -1,
      18,    -1,    -1,    -1,    22,    -1,    24,    -1,    26,    -1,
      28,    -1,    30,    -1,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    -1,
      48,    49,    -1,    -1,    -1,    53,    -1,    -1,    -1,    57,
      58,    -1,    60,     4,     5,    -1,    64,    65,    66,    -1,
      -1,    -1,    -1,    14,    -1,    -1,    -1,    18,    -1,    -1,
      -1,    22,    -1,    24,    -1,    26,    -1,    28,    -1,    30,
      -1,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    -1,    48,    49,    -1,
      -1,    -1,    53,    -1,    -1,    -1,    57,    58,    -1,    60,
       4,     5,    -1,    64,    65,    66,    -1,    -1,    -1,    -1,
      14,    -1,    -1,    -1,    18,    -1,    -1,    -1,    22,    -1,
      24,    -1,    26,    -1,    28,    -1,    30,    -1,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    -1,    48,    49,    -1,    -1,    -1,    53,
      -1,    -1,    -1,    57,    58,    -1,    60,     4,     5,    -1,
      64,    65,    66,    -1,    -1,    -1,    -1,    14,    -1,    -1,
      -1,    18,    -1,    -1,    -1,    22,    -1,    24,    -1,    26,
      -1,    28,    -1,    30,    -1,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      -1,    48,    49,    -1,    -1,    -1,    53,    -1,    -1,    -1,
      57,    58,    -1,    60,     4,     5,    -1,    64,    65,    66,
      -1,    -1,    -1,    -1,    14,    -1,    -1,    -1,    18,    -1,
      -1,    -1,    22,    -1,    24,    -1,    26,    -1,    28,    -1,
      30,    -1,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    -1,    48,    49,
      -1,    -1,    -1,    53,    -1,    -1,    -1,    57,    58,    -1,
      60,     4,     5,    -1,    64,    65,    66,    -1,    -1,    -1,
      -1,    14,    -1,    -1,    -1,    18,    -1,    -1,    -1,    22,
      -1,    24,    -1,    26,    -1,    28,    -1,    30,    -1,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    -1,    48,    49,    -1,    -1,    -1,
      53,    -1,    -1,    -1,    57,    58,    -1,    60,     4,     5,
      -1,    64,    65,    66,    -1,    -1,    -1,    -1,    14,    -1,
      -1,    -1,    18,    -1,    -1,    -1,    22,    -1,    24,    -1,
      26,    -1,    28,    -1,    30,    -1,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    -1,    48,    49,    -1,    -1,    -1,    53,    -1,    -1,
      -1,    57,    58,    -1,    60,     4,     5,    -1,    64,    65,
      66,    -1,    -1,    -1,    -1,    14,    -1,    -1,    -1,    18,
      -1,    -1,    -1,    22,    -1,    24,    -1,    26,    -1,    28,
      -1,    30,    -1,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    -1,    48,
      49,    -1,    -1,    -1,    53,    -1,    -1,    -1,    57,    58,
      -1,    60,     4,     5,    -1,    64,    65,    66,    -1,    -1,
      -1,    -1,    14,    -1,    -1,    -1,    18,    -1,    -1,    -1,
      22,    -1,    24,    -1,    26,    -1,    28,    -1,    30,    -1,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    -1,    48,    49,    -1,    -1,
      -1,    53,    -1,    -1,    -1,    57,    58,    -1,    60,     4,
       5,    -1,    64,    65,    66,    -1,    -1,    -1,    -1,    14,
      -1,    -1,    -1,    18,    -1,    -1,    -1,    22,    -1,    24,
      -1,    26,    -1,    28,    -1,    30,    -1,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    -1,    48,    49,    -1,    -1,    -1,    53,    -1,
      -1,    -1,    57,    58,    -1,    60,    -1,    -1,    -1,    64,
      -1,    66,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    -1,    15,    16,    17,    -1,    19,    20,
      21,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    -1,    15,    16,    17,    -1,    19,    20,    21,
      -1,    -1,    -1,    44,    -1,    -1,    -1,    -1,    -1,    50,
      -1,    52,    53,    54,    55,    56,    -1,    58,    -1,    60,
      -1,    62,    -1,    64,    -1,    -1,    -1,    -1,    50,    -1,
      52,    53,    54,    55,    56,    -1,    58,    -1,    60,    61,
      62,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    -1,    15,    16,    17,    -1,    19,    20,    21,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    -1,    15,    16,    17,    -1,    19,    20,    21,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,    51,
      52,    53,    54,    55,    56,    -1,    58,    -1,    60,    -1,
      62,    -1,    -1,    -1,    -1,    -1,    -1,    50,    -1,    52,
      53,    54,    55,    56,    -1,    58,    59,    60,    -1,    62,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    -1,    15,    16,    17,    -1,    19,    20,    21,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      -1,    15,    16,    17,    -1,    19,    20,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,    -1,    52,
      53,    54,    55,    56,    -1,    58,    -1,    60,    -1,    62,
      -1,    -1,    -1,    -1,    -1,    -1,    50,    -1,    52,    53,
      54,    55,    56,    -1,    58,    -1,    60,    -1,    62,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    -1,
      -1,    15,    16,    17,    -1,    19,    20,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    -1,    -1,    -1,    15,
      16,    17,    -1,    19,    20,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    52,    53,
      54,    55,    56,    -1,    58,    -1,    60,    -1,    62,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    52,    53,    54,    55,
      56,    -1,    58,    -1,    60,    -1,    62,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    -1,    -1,    -1,    15,
      -1,    17,    -1,    19,    20,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    -1,    -1,    -1,    15,    -1,    -1,
      -1,    19,    20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    52,    53,    54,    55,
      56,    -1,    58,    -1,    60,    -1,    62,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    52,    53,    54,    55,    56,    -1,
      58,    -1,    60,    -1,    62,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    19,    20,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    19,
      20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    52,    53,    54,    55,    56,    -1,
      58,    -1,    60,    -1,    62,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    52,    53,    54,    55,    56,    -1,    58,    -1,
      60,    -1,    62,     3,     4,     5,     6,     7,     8,     9,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    19,
      20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    52,    53,    54,    55,    56,    -1,    58,    -1,
      60,    -1,    62
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned char
  Exa1Parser::yystos_[] =
  {
         0,     4,     5,    14,    18,    22,    24,    26,    28,    30,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    48,    49,    53,    57,    58,
      60,    64,    66,    69,    70,    71,    73,    74,    77,    79,
      39,    45,    77,    77,    77,    77,    77,    77,    45,    77,
      45,    77,    79,    80,    73,    73,    73,    73,    45,    60,
      45,    45,    45,    78,    31,    51,    77,    77,    80,    77,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    39,    45,
      52,    53,    54,    55,    56,    57,    58,    60,    62,    65,
      71,    72,    76,     0,    70,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    15,    16,    17,    19,
      20,    21,    50,    52,    53,    54,    55,    56,    58,    60,
      62,    73,    63,    67,    44,    64,    75,    75,    27,    75,
      73,    73,    60,    61,    78,    31,    64,    63,    67,    73,
      77,    77,    59,    61,    45,    64,    64,    45,    45,    45,
      45,    45,    45,    45,    45,    64,    45,    45,    45,    64,
      45,    45,    45,    45,    64,    45,    45,    45,    64,    45,
      61,    78,    45,    65,    71,    72,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    80,    45,
      79,    77,    70,    74,    23,    77,    61,    78,    31,    64,
      61,    45,    76,    77,    78,    73,    64,    74,    74,    64,
      64,    64,    64,    64,    64,    64,    64,    74,    64,    64,
      64,    74,    64,    64,    64,    64,    74,    64,    64,    64,
      74,    59,    64,    61,    64,    51,    59,    61,    73,    65,
      75,    75,    64,    61,    77,    74,    31,    64,    64,    65,
      67,    74,    65,    65,    74,    74,    74,    74,    74,    74,
      74,    74,    65,    74,    74,    74,    65,    74,    74,    74,
      74,    65,    74,    74,    74,    65,    64,    74,    64,    74,
      77,    74,    64,    65,    77,    74,    76,    78,    65,    65,
      65,    65,    65,    65,    65,    65,    65,    65,    65,    65,
      65,    65,    65,    65,    65,    65,    65,    74,    65,    74,
      65,    65,    74,    65,    65,    65,    65,    65
  };

#if YYDEBUG
  /* TOKEN_NUMBER_[YYLEX-NUM] -- Internal symbol number corresponding
     to YYLEX-NUM.  */
  const unsigned short int
  Exa1Parser::yytoken_number_[] =
  {
         0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
      63,    58,    43,    45,    42,    47,    37,    35,    91,    93,
      40,    41,    46,    61,   123,   125,    59,    44
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned char
  Exa1Parser::yyr1_[] =
  {
         0,    68,    69,    70,    70,    70,    70,    70,    70,    70,
      70,    70,    70,    70,    70,    70,    70,    71,    71,    71,
      71,    71,    71,    71,    72,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      72,    72,    72,    73,    73,    74,    74,    75,    75,    76,
      76,    76,    76,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    78,    78,    78,    78,    79,    79,    80,    80
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  Exa1Parser::yyr2_[] =
  {
         0,     2,     1,     3,     1,     4,     2,     2,     2,     2,
       2,     3,     5,     3,     3,     3,     5,     1,     3,     4,
       8,     7,     5,     7,     5,     5,     5,     5,     5,     5,
       5,     5,     5,     5,     5,     5,     5,     5,     5,     5,
       5,     5,     5,     5,     6,     5,     6,     4,     4,     4,
       4,     4,     4,     1,     1,     1,     2,     2,     3,     1,
       1,     2,     2,     1,     1,     1,     1,     1,     1,     7,
       6,     6,     5,     3,     3,     2,     1,     3,     4,     3,
       4,     3,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     5,     1,     3,     3,     5,     1,     3,     0,     1
  };

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
  /* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
     First, the terminals, then, starting at \a yyntokens_, nonterminals.  */
  const char*
  const Exa1Parser::yytname_[] =
  {
    "$end", "error", "$undefined", "EXP", "INCREMENT", "DECREMENT", "CMP_G",
  "CMP_L", "CMP_GE", "CMP_LE", "CMP_E", "CMP_NE", "LOGICAL_AND",
  "LOGICAL_OR", "LOGICAL_NOT", "BIT_AND", "BIT_OR", "BIT_XOR", "BIT_COM",
  "BIT_SHIFT_LEFT", "BIT_SHIFT_RIGHT", "COM_ASSIGN", "IF", "ELSE", "WHILE",
  "END", "FOR", "IN", "LOOP", "SWITCH", "USING", "ARROW", "RETURN",
  "BREAK", "CONTINUE", "DEBUG", "EXIT", "TRUE", "FALSE", "FUNC", "NEW",
  "OBJECT", "LET", "NIL", "EOL", "ID", "STRING", "WHY", "T_INT", "REAL",
  "'?'", "':'", "'+'", "'-'", "'*'", "'/'", "'%'", "'#'", "'['", "']'",
  "'('", "')'", "'.'", "'='", "'{'", "'}'", "';'", "','", "$accept",
  "program", "stmt", "declaration_stmt", "operator_overload_stmt",
  "end_of_stmt", "stmt_list", "block", "object_body_stmts", "exp",
  "ID_list_with_default_value", "exp_list", "zero_or_more_exp", 0
  };
#endif

#if YYDEBUG
  /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
  const Exa1Parser::rhs_number_type
  Exa1Parser::yyrhs_[] =
  {
        69,     0,    -1,    74,    -1,    30,    45,    73,    -1,    71,
      -1,    79,    63,    79,    73,    -1,    77,    73,    -1,    33,
      73,    -1,    34,    73,    -1,    35,    73,    -1,    36,    73,
      -1,    32,    80,    73,    -1,    22,    77,    75,    23,    75,
      -1,    22,    77,    75,    -1,    24,    77,    75,    -1,    28,
      77,    75,    -1,    26,    45,    27,    77,    75,    -1,    73,
      -1,    42,    78,    73,    -1,    45,    51,    77,    73,    -1,
      39,    45,    60,    78,    61,    64,    74,    65,    -1,    39,
      45,    60,    61,    64,    74,    65,    -1,    41,    45,    64,
      76,    65,    -1,    41,    45,    31,    45,    64,    76,    65,
      -1,    52,    45,    64,    74,    65,    -1,    53,    45,    64,
      74,    65,    -1,    54,    45,    64,    74,    65,    -1,     3,
      45,    64,    74,    65,    -1,    55,    45,    64,    74,    65,
      -1,    56,    45,    64,    74,    65,    -1,     6,    45,    64,
      74,    65,    -1,     7,    45,    64,    74,    65,    -1,     8,
      45,    64,    74,    65,    -1,     9,    45,    64,    74,    65,
      -1,    10,    45,    64,    74,    65,    -1,    11,    45,    64,
      74,    65,    -1,    12,    45,    64,    74,    65,    -1,    13,
      45,    64,    74,    65,    -1,    15,    45,    64,    74,    65,
      -1,    16,    45,    64,    74,    65,    -1,    17,    45,    64,
      74,    65,    -1,    19,    45,    64,    74,    65,    -1,    20,
      45,    64,    74,    65,    -1,    62,    45,    64,    74,    65,
      -1,    58,    45,    59,    64,    74,    65,    -1,    60,    61,
      64,    74,    65,    -1,    60,    78,    61,    64,    74,    65,
      -1,    57,    64,    74,    65,    -1,    53,    64,    74,    65,
      -1,     4,    64,    74,    65,    -1,     5,    64,    74,    65,
      -1,    18,    64,    74,    65,    -1,    14,    64,    74,    65,
      -1,    66,    -1,    44,    -1,    70,    -1,    74,    70,    -1,
      44,    70,    -1,    64,    74,    65,    -1,    71,    -1,    72,
      -1,    76,    71,    -1,    76,    72,    -1,    43,    -1,    37,
      -1,    38,    -1,    48,    -1,    49,    -1,    46,    -1,    39,
      60,    78,    61,    64,    74,    65,    -1,    39,    60,    61,
      64,    74,    65,    -1,    39,    60,    78,    61,    31,    77,
      -1,    39,    60,    61,    31,    77,    -1,    58,    80,    59,
      -1,    64,    76,    65,    -1,    64,    65,    -1,    45,    -1,
      77,    62,    45,    -1,    77,    58,    77,    59,    -1,    60,
      77,    61,    -1,    77,    60,    80,    61,    -1,    45,    31,
      77,    -1,    40,    45,    -1,    57,    77,    -1,    53,    77,
      -1,     4,    77,    -1,     5,    77,    -1,    77,     4,    -1,
      77,     5,    -1,    18,    77,    -1,    14,    77,    -1,    77,
      52,    77,    -1,    77,    53,    77,    -1,    77,    54,    77,
      -1,    77,     3,    77,    -1,    77,    55,    77,    -1,    77,
      56,    77,    -1,    77,     6,    77,    -1,    77,     7,    77,
      -1,    77,     8,    77,    -1,    77,     9,    77,    -1,    77,
      10,    77,    -1,    77,    11,    77,    -1,    77,    12,    77,
      -1,    77,    13,    77,    -1,    77,    15,    77,    -1,    77,
      16,    77,    -1,    77,    17,    77,    -1,    77,    19,    77,
      -1,    77,    20,    77,    -1,    77,    21,    77,    -1,    77,
      50,    77,    51,    77,    -1,    45,    -1,    45,    63,    77,
      -1,    45,    67,    78,    -1,    45,    63,    77,    67,    78,
      -1,    77,    -1,    79,    67,    77,    -1,    -1,    79,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned short int
  Exa1Parser::yyprhs_[] =
  {
         0,     0,     3,     5,     9,    11,    16,    19,    22,    25,
      28,    31,    35,    41,    45,    49,    53,    59,    61,    65,
      70,    79,    87,    93,   101,   107,   113,   119,   125,   131,
     137,   143,   149,   155,   161,   167,   173,   179,   185,   191,
     197,   203,   209,   215,   221,   228,   234,   241,   246,   251,
     256,   261,   266,   271,   273,   275,   277,   280,   283,   287,
     289,   291,   294,   297,   299,   301,   303,   305,   307,   309,
     317,   324,   331,   337,   341,   345,   348,   350,   354,   359,
     363,   368,   372,   375,   378,   381,   384,   387,   390,   393,
     396,   399,   403,   407,   411,   415,   419,   423,   427,   431,
     435,   439,   443,   447,   451,   455,   459,   463,   467,   471,
     475,   479,   485,   487,   491,   495,   501,   503,   507,   508
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  Exa1Parser::yyrline_[] =
  {
         0,    92,    92,   110,   111,   112,   113,   115,   116,   117,
     118,   119,   121,   122,   123,   124,   125,   128,   129,   130,
     131,   132,   133,   134,   138,   141,   144,   147,   150,   153,
     157,   160,   163,   166,   169,   172,   176,   179,   183,   186,
     189,   192,   195,   200,   205,   210,   213,   218,   221,   224,
     227,   230,   233,   238,   239,   242,   243,   246,   247,   250,
     251,   252,   253,   256,   257,   258,   259,   260,   261,   263,
     264,   265,   269,   274,   275,   276,   278,   279,   280,   282,
     283,   284,   285,   288,   289,   290,   291,   292,   293,   294,
     295,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,   309,   310,   311,   312,   313,   314,   315,   316,
     317,   320,   323,   324,   325,   326,   329,   330,   333,   334
  };

  // Print the state stack on the debug stream.
  void
  Exa1Parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (state_stack_type::const_iterator i = yystate_stack_.begin ();
	 i != yystate_stack_.end (); ++i)
      *yycdebug_ << ' ' << *i;
    *yycdebug_ << std::endl;
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  Exa1Parser::yy_reduce_print_ (int yyrule)
  {
    unsigned int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    /* Print the symbols being reduced, and their result.  */
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
	       << " (line " << yylno << "):" << std::endl;
    /* The symbols being reduced.  */
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
		       yyrhs_[yyprhs_[yyrule] + yyi],
		       &(yysemantic_stack_[(yynrhs) - (yyi + 1)]),
		       &(yylocation_stack_[(yynrhs) - (yyi + 1)]));
  }
#endif // YYDEBUG

  /* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
  Exa1Parser::token_number_type
  Exa1Parser::yytranslate_ (int t)
  {
    static
    const token_number_type
    translate_table[] =
    {
           0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,    57,     2,    56,     2,     2,
      60,    61,    54,    52,    67,    53,    62,    55,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    51,    66,
       2,    63,     2,    50,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    58,     2,    59,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    64,     2,    65,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int Exa1Parser::yyeof_ = 0;
  const int Exa1Parser::yylast_ = 3352;
  const int Exa1Parser::yynnts_ = 13;
  const int Exa1Parser::yyempty_ = -2;
  const int Exa1Parser::yyfinal_ = 103;
  const int Exa1Parser::yyterror_ = 1;
  const int Exa1Parser::yyerrcode_ = 256;
  const int Exa1Parser::yyntokens_ = 68;

  const unsigned int Exa1Parser::yyuser_token_number_max_ = 304;
  const Exa1Parser::token_number_type Exa1Parser::yyundef_token_ = 2;


} // Exa1


// 必须自己定义一个错误处理函数
void Exa1::Exa1Parser::error(const Exa1Parser::location_type &loc, const std::string &msg)
{
    throw SpringException(SpringException::SPRING_ERROR_SYNTAX_ERROR, "syntax error\nTODO: 这里要防止内存泄漏");
}

int yyerror(char *s)
{
  fprintf(stderr, "error: %s\n", s);
  getchar();
  return 1;
}

