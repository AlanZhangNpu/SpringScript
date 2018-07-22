#ifndef PARAGRAPH_H
#define PARAGRAPH_H
#include <vector>
#include "SpringBaseStatement.h"

namespace spr {

    class SpringParagraph
    {
    public:
        SpringParagraph();
        ~SpringParagraph();

        void addStmt(SpringBaseStatement * b);
        int size();
        int getFirstStmtLineNo();
        SpringBaseStatement::SpringStatementResultFlag run(SpringRuntimeEnvironment & env);

        void printStructure(int blankNum);

    private:
        std::vector<SpringBaseStatement*> stmtList;
    };
}

#endif // SPRINGPARAGRAPH_H
