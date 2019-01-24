#include "SpringBaseStatement.h"
#include "Spring.h"

namespace spr {

    SpringBaseStatement::SpringBaseStatement()
    {}

    SpringBaseStatement::~SpringBaseStatement()
    {}

    SpringBaseStatement::SpringStatementResultFlag SpringBaseStatement::run(SpringRuntimeEnvironment &env)
    {
        if(!isRun(env.runtimeController))
            return SpringBaseStatement::EXIT;

        try{
//            zzzz "SpringBaseStatement::evaluate";
            auto r = evaluate(env);
            env.ojbManager->collectGarbage(env.symbolTable);
            return r;
        }
        catch(std::runtime_error &error)
        {
            std::string errorMsg = error.what();
            SpringException::throwRuntimeError(errorMsg, getRealLineNo());
        }
        catch(std::logic_error &logicError)
        {
            std::string errorMsg = logicError.what();
            SpringException::throwRuntimeError(errorMsg, getRealLineNo());
        }
        return SpringBaseStatement::SpringStatementResultFlag::NORMAL;
    }

    void SpringBaseStatement::setDefaultLineNo(int l)
    {
        lineno = l;
    }

    bool SpringBaseStatement::isRun(SpringRuntimeController *runtimeController)
    {
        if(runtimeController == nullptr)
            return true;

        int realLineNo = getRealLineNo();
        return runtimeController->isRun(realLineNo);
    }

    int SpringBaseStatement::getRealLineNo()
    {
        return lineno;
    }

    bool SpringBaseStatement::isEmptyStatement()
    {
        return false;
    }

    void SpringBaseStatement::printStructure(int blankNum)
    {
        int i = 0;
        std::string str = "";
        while (i++ < blankNum)
            str += "    ";
//        qDebug() << QString::fromStdString(str + "SpringBaseStatement") << getRealLineNo();
    }

}
