#ifndef SPRINGSTATEMENT_H
#define SPRINGSTATEMENT_H
#include "SpringBaseStatement.h"

namespace spr {

    class SpringImportStatement;
    class SpringDeclarationStatement;
    class SpringAssignStatement;
    class SpringExpressionStatement;
    class SpringJumpStatement;
    class SpringControlFlowStatement;

    class SpringIDListExpression;
    class SpringExpressionList;
    class SpringBaseExpression;
    class SpringParagraph;
    class SpringIDExpression;

    /***********************************************************************
    SpringImportStatement
    ***********************************************************************/

    class SpringImportStatement : public SpringBaseStatement
    {
    public:
        SpringImportStatement(char * id, int l);
        virtual ~SpringImportStatement() override;
        virtual void printStructure(int blankNum) override;

    private:
        SpringStatementResultFlag evaluate(SpringRuntimeEnvironment &env);
        std::string name = "";
    };

    /***********************************************************************
    SpringDeclarationStatement
    ***********************************************************************/

    class SpringDeclarationStatement : public SpringBaseStatement
    {
    public:
        SpringDeclarationStatement(SpringIDListExpression * i = nullptr);
        SpringDeclarationStatement(SpringIDListExpression * i, int line);
        virtual ~SpringDeclarationStatement() override;
        virtual bool isEmptyStatement() override;
        virtual void printStructure(int blankNum) override;

    private:
        virtual SpringStatementResultFlag evaluate(SpringRuntimeEnvironment &env) override;
        SpringIDListExpression * idList = nullptr;
    };

    /***********************************************************************
    SpringAssignStatement
    ***********************************************************************/

    class SpringAssignStatement : public SpringBaseStatement
    {
    public:
        SpringAssignStatement(SpringExpressionList *lft, SpringExpressionList* v, int l);
        virtual ~SpringAssignStatement() override;
        virtual void printStructure(int blankNum) override;

    private:
        SpringExpressionList* leftValueList = nullptr;
        SpringExpressionList* rightValueList = nullptr;
        virtual SpringStatementResultFlag evaluate(SpringRuntimeEnvironment &env) override;
    };

    /***********************************************************************
    SpringExpressionStatement
    ***********************************************************************/

    class SpringExpressionStatement : public SpringBaseStatement
    {
    public:
        SpringExpressionStatement(SpringBaseExpression * e, int l);
        virtual ~SpringExpressionStatement() override;
        virtual void printStructure(int blankNum) override;

    private:
        SpringBaseExpression * exp = nullptr;
        virtual SpringStatementResultFlag evaluate(SpringRuntimeEnvironment & env) override;
    };

    /***********************************************************************
    SpringJumpStatement
    ***********************************************************************/

    class SpringJumpStatement : public SpringBaseStatement
    {
    public:
        SpringJumpStatement(int t, int l);
        SpringJumpStatement(SpringExpressionList * e, int l);
        virtual ~SpringJumpStatement() override;
        virtual void printStructure(int blankNum) override;

    private:
        int type;
        SpringExpressionList * expList = nullptr;
        virtual SpringStatementResultFlag evaluate(SpringRuntimeEnvironment & env) override;
    };

    /***********************************************************************
    SpringControlFlowStatement
    ***********************************************************************/

    class SpringControlFlowStatement : public SpringBaseStatement
    {
    public:
        SpringControlFlowStatement(int t,
                                   SpringBaseExpression *c,
                                   SpringParagraph *d,
                                   int l);
        SpringControlFlowStatement(SpringBaseExpression *c,
                                   SpringParagraph *d,
                                   SpringParagraph *e,
                                   int l);
        SpringControlFlowStatement(SpringIDExpression *i,
                                   SpringBaseExpression *lst,
                                   SpringParagraph *d,
                                   int l);
        virtual ~SpringControlFlowStatement() override;
        virtual int getRealLineNo() override;
        virtual void printStructure(int blankNum) override;

    private:
        int type = 'i';
        SpringBaseExpression *condition = nullptr;
        SpringParagraph *directParagraph = nullptr;
        SpringParagraph *elseParagraph = nullptr;

        // for loop variables
        SpringIDExpression * id = nullptr;
        SpringBaseExpression * list = nullptr;

        virtual SpringStatementResultFlag evaluate(SpringRuntimeEnvironment & env) override;
    };
}

#endif // SPRINGSTATEMENT_H
