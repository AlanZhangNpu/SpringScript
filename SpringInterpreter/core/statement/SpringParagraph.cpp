#include "SpringParagraph.h"
#include "Spring.h"
#include "SpringStatement.h"
#include "./core/expression/SpringBaseExpression.h"

namespace spr {

    SpringParagraph::SpringParagraph()
    {}

    SpringParagraph::~SpringParagraph()
    {
        for (SpringBaseStatement* stmt : stmtList)
            delete stmt;
    }

    int SpringParagraph::size()
    {
        return stmtList.size();
    }

    void SpringParagraph::addStmt(SpringBaseStatement * b)
    {
        if(!b->isEmptyStatement())
            stmtList.push_back(b);
        else
            delete b;
    }

    SpringBaseStatement::SpringStatementResultFlag SpringParagraph::run(SpringRuntimeEnvironment &env)
    {
        for (auto stmt : stmtList){
            SpringBaseStatement::SpringStatementResultFlag r = stmt->run(env);
            if(SpringBaseStatement::SpringStatementResultFlag::NORMAL != r)
                return r;
        }
        env.ojbManager->collectGarbage(env.symbolTable);
        return SpringBaseStatement::SpringStatementResultFlag::NORMAL;
    }

    void SpringParagraph::printStructure(int blankNum)
    {
        int i=0;
        std::string str = "";
        while (i++ < blankNum)
            str += "    ";
        blankNum++;
        for (SpringBaseStatement* stmt : stmtList)
            stmt->printStructure(blankNum);
        blankNum--;
    }

    int SpringParagraph::getFirstStmtLineNo()
    {
        if(stmtList.size() >= 1)
            return stmtList[0]->getRealLineNo();
        return -1;
    }

}
