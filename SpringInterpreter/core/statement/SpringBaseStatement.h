#ifndef BASESTATEMENT_H
#define BASESTATEMENT_H

#include "./core/object/SpringObject.h"

namespace spr {

    class SpringRuntimeEnvironment;
    class SpringRuntimeController;
    class SpringBaseStatement
    {
    public:
        SpringBaseStatement();
        virtual ~SpringBaseStatement();

        enum SpringStatementResultFlag{
            NORMAL,
            CONTINUE,
            BREAK,
            RETURN,
            EXIT
        };

        SpringStatementResultFlag run(SpringRuntimeEnvironment &env);
        void setDefaultLineNo(int l);
        virtual int getRealLineNo();
        virtual bool isEmptyStatement();
        virtual void printStructure(int blankNum);

    private:
        int lineno = -1;
        bool isRun(SpringRuntimeController* runtimeController);
        virtual SpringStatementResultFlag evaluate(SpringRuntimeEnvironment &) = 0;
    };

}

#endif // BASESTATEMENT_H
