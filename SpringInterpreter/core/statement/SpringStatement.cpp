#include "SpringStatement.h"
#include "Spring.h"
#include "./core/expression/SpringExpression.h"
#include "./core/expression/SpringExpressionList.h"
#include "./core/statement/SpringParagraph.h"
#include "./core/object/SpringStandardType.h"
#include "./lib/SpringLibraryLoader.h"

namespace spr {

    /***********************************************************************
    SpringImportStatement
    ***********************************************************************/

    SpringImportStatement::SpringImportStatement(char *id, int l)
    {
        name = std::string(id);
        free(id);
        setDefaultLineNo(l);
    }

    SpringImportStatement::~SpringImportStatement()
    {}

    void SpringImportStatement::printStructure(int blankNum)
    {
        int i = 0;
        std::string str = "";
        while (i++ < blankNum)
            str += "    ";
        qDebug() << QString::fromStdString(str + "SpringImportStatement") << getRealLineNo();
    }

    SpringBaseStatement::SpringStatementResultFlag SpringImportStatement::evaluate(SpringRuntimeEnvironment &env)
    {
        SpringLibraryLoader::loadStandardLib(name, env);
        return SpringBaseStatement::SpringStatementResultFlag::NORMAL;
    }

    /***********************************************************************
    SpringDeclarationStatement
    ***********************************************************************/

    SpringDeclarationStatement::SpringDeclarationStatement(SpringIDListExpression *i)
    {
        idList = i;
    }

    SpringDeclarationStatement::SpringDeclarationStatement(SpringIDListExpression *i, int line)
    {
        idList = i;
        setDefaultLineNo(line);
    }

    SpringDeclarationStatement::~SpringDeclarationStatement()
    {
        if(idList != nullptr)
            delete idList;
    }

    bool SpringDeclarationStatement::isEmptyStatement()
    {
        if(idList == nullptr)
            return true;
        return false;
    }

    void SpringDeclarationStatement::printStructure(int blankNum)
    {
        int i = 0;
        std::string str = "";
        while (i++ < blankNum)
            str += "    ";
        qDebug() << QString::fromStdString(str + "SpringDeclarationStatement") << getRealLineNo();
    }

    SpringBaseStatement::SpringStatementResultFlag SpringDeclarationStatement::evaluate(SpringRuntimeEnvironment &env)
    {
        if(idList != nullptr){
            for(unsigned i = 0; i < idList->size(); i++){
                SpringIDExpression * id = idList->at(i);
                env.symbolTable->declare(id->getName(), id->getDefaultValue(env));
            }
        }
        return SpringBaseStatement::SpringStatementResultFlag::NORMAL;
    }

    /***********************************************************************
    SpringAssignStatement
    ***********************************************************************/

    SpringAssignStatement::SpringAssignStatement(SpringExpressionList *lft,
                                                 SpringExpressionList *v,
                                                 int l):
        leftValueList(lft),
        rightValueList(v)
    {
        setDefaultLineNo(l);
        std::vector<unsigned> rvalues;
        leftValueList->getRightValues(rvalues);
        if(rvalues.size() != 0)
            Spring::throwSyntaxErrorException("cannot assign to rvalue.");
    }

    SpringAssignStatement::~SpringAssignStatement()
    {
        if(leftValueList != nullptr)
            delete leftValueList;
        if(rightValueList != nullptr)
            delete rightValueList;
    }

    void SpringAssignStatement::printStructure(int blankNum)
    {
        int i = 0;
        std::string str = "";
        while (i++ < blankNum)
            str += "    ";
        qDebug() << QString::fromStdString(str + "SpringAssignStatement") << getRealLineNo();
    }

    SpringBaseStatement::SpringStatementResultFlag SpringAssignStatement::evaluate(SpringRuntimeEnvironment &env)
    {
        unsigned leftNum = leftValueList->size();
        auto right = rightValueList->evaluate(env);
        unsigned rightNum = right->toListPointer()->getLength();

        while (leftNum == rightNum || leftNum == 1 || rightNum == 1) {
            if(leftNum == rightNum){
                for(unsigned i = 0; i < leftNum; i++)
                    leftValueList->at(i)->set(env, right->toListPointer()->at(i));
                return SpringBaseStatement::SpringStatementResultFlag::NORMAL;
            }
            if(leftNum == 1){
                leftValueList->at(0)->set(env, right);
                return SpringBaseStatement::SpringStatementResultFlag::NORMAL;
            }
            right = right->toListPointer()->at(0);
            if(!right->isList())
                break;
            rightNum = right->toListPointer()->getLength();
        }
        Spring::throwRawException("The number of variables does not match: there are "
                                  + std::to_string(leftNum) + " left value(s) and "
                                  + std::to_string(rightNum) + " right value(s).");
        return SpringBaseStatement::SpringStatementResultFlag::NORMAL;
    }

    /***********************************************************************
    SpringExpressionStatement
    ***********************************************************************/

    SpringExpressionStatement::SpringExpressionStatement(SpringBaseExpression * e, int l):
        exp(e)
    {
        setDefaultLineNo(l);
    }

    SpringExpressionStatement::~SpringExpressionStatement()
    {
        if(exp != nullptr)
            delete exp;
    }

    void SpringExpressionStatement::printStructure(int blankNum)
    {
        int i = 0;
        std::string str = "";
        while (i++ < blankNum)
            str += "    ";
        qDebug() << QString::fromStdString(str + "SpringExpressionStatement") << getRealLineNo();
    }

    SpringBaseStatement::SpringStatementResultFlag SpringExpressionStatement::evaluate(SpringRuntimeEnvironment &env)
    {
        if (exp != nullptr)
            exp->evaluate(env);
        return SpringBaseStatement::SpringStatementResultFlag::NORMAL;
    }

    /***********************************************************************
    SpringJumpStatement
    ***********************************************************************/

    SpringJumpStatement::SpringJumpStatement(int t, int l):
        type(t),
        expList(nullptr)
    {
        setDefaultLineNo(l);
    }

    SpringJumpStatement::SpringJumpStatement(SpringExpressionList * e, int l):
        type('r'),
        expList(e)
    {
        setDefaultLineNo(l);
    }

    SpringJumpStatement::~SpringJumpStatement()
    {
        if(expList != nullptr)
            delete expList;
    }

    void SpringJumpStatement::printStructure(int blankNum)
    {
        int i = 0;
        std::string str = "";
        while (i++ < blankNum)
            str += "    ";
        qDebug() << QString::fromStdString(str + "SpringJumpStatement") << getRealLineNo();
    }

    SpringBaseStatement::SpringStatementResultFlag SpringJumpStatement::evaluate(SpringRuntimeEnvironment &env)
    {
        SpringStatementResultFlag r = SpringBaseStatement::SpringStatementResultFlag::NORMAL;
        switch (type)
        {
        case 'b':
            r = SpringBaseStatement::SpringStatementResultFlag::BREAK;
            break;

        case 'c':
            r = SpringBaseStatement::SpringStatementResultFlag::CONTINUE;
            break;

        case 'r':
            r = SpringBaseStatement::SpringStatementResultFlag::RETURN;
            if (expList != nullptr)
            {
                SpringObjectPtr result = expList->evaluate(env);
                if(result->toListPointer()->getLength() == 1)
                    env.ojbManager->pushReturnValue(result->toListPointer()->at(0));
                else
                    env.ojbManager->pushReturnValue(result);
            }else{
                env.ojbManager->pushReturnValue(env.ojbManager->create());
            }
            break;

        case 'e':
            r = SpringBaseStatement::SpringStatementResultFlag::EXIT;
            break;

        default:
            break;
        }
        return r;
    }

    /***********************************************************************
    SpringControlFlowStatement
    ***********************************************************************/

    SpringControlFlowStatement::SpringControlFlowStatement(int t,
                                                           SpringBaseExpression * c,
                                                           SpringParagraph * d,
                                                           int l):
        type(t),
        condition(c),
        directParagraph(d)
    {
        setDefaultLineNo(l);
    }

    SpringControlFlowStatement::SpringControlFlowStatement(SpringBaseExpression *c,
                                                           SpringParagraph *d,
                                                           SpringParagraph *e,
                                                           int l):
        type('i'),
        condition(c),
        directParagraph(d),
        elseParagraph(e)
    {
        setDefaultLineNo(l);
    }

    SpringControlFlowStatement::SpringControlFlowStatement(SpringIDExpression * i,
                                                           SpringBaseExpression * lst,
                                                           SpringParagraph * d,
                                                           int l):
        type('f'),
        directParagraph(d),
        id(i),
        list(lst)
    {
        setDefaultLineNo(l);
    }

    SpringControlFlowStatement::~SpringControlFlowStatement()
    {
        if(condition != nullptr)
            delete condition;
        if(directParagraph != nullptr)
            delete directParagraph;
        if(elseParagraph != nullptr)
            delete elseParagraph;
        if(id != nullptr)
            delete id;
        if(list != nullptr)
            delete list;
    }

    SpringBaseStatement::SpringStatementResultFlag SpringControlFlowStatement::evaluate(SpringRuntimeEnvironment &env)
    {
        SpringBaseStatement::SpringStatementResultFlag r = SpringBaseStatement::SpringStatementResultFlag::NORMAL;
        switch (type)
        {
        case 'i':
        {
            env.symbolTable->entryScope();
            SpringObjectPtr conditionValue = condition->evaluate(env);
            if (conditionValue->toBool()) {
                if (directParagraph != nullptr)
                    r = directParagraph->run(env);
            }else if (elseParagraph != nullptr)
                r = elseParagraph->run(env);
            env.symbolTable->exitScope();
            return r;
        }

        case 'w':
        {
            SpringObjectPtr conditionValue = condition->evaluate(env);
            while (conditionValue->toBool()) {
                env.symbolTable->entryScope();
                r = directParagraph->run(env);
                switch (r) {
                case SpringBaseStatement::SpringStatementResultFlag::NORMAL:
                case SpringBaseStatement::SpringStatementResultFlag::CONTINUE:
                    break;

                case SpringBaseStatement::SpringStatementResultFlag::BREAK:
                    r = SpringBaseStatement::SpringStatementResultFlag::NORMAL;
                default:
                    env.symbolTable->exitScope();
                    return r;
                }
                conditionValue = condition->evaluate(env);
                env.symbolTable->exitScope();
            }
            r = SpringBaseStatement::SpringStatementResultFlag::NORMAL;
            return r;
        }

        case 'l':
        {
            double v = condition->evaluate(env)->toDouble();
            while ((--v) >= 0)
            {
                env.symbolTable->entryScope();
                r = directParagraph->run(env);
                switch (r) {
                case SpringBaseStatement::SpringStatementResultFlag::NORMAL:
                case SpringBaseStatement::SpringStatementResultFlag::CONTINUE:
                    break;

                case SpringBaseStatement::SpringStatementResultFlag::BREAK:
                    r = SpringBaseStatement::SpringStatementResultFlag::NORMAL;
                default:
                    env.symbolTable->exitScope();
                    return r;
                }
                env.symbolTable->exitScope();
            }
            r = SpringBaseStatement::SpringStatementResultFlag::NORMAL;
            return r;
        }

        case 'f':
        {
            SpringObjectPtr listContent = list->evaluate(env);
            if (!listContent->isList())
                Spring::throwLogicErrorException(listContent->getTypeString() + " is not iterable", getRealLineNo());

            env.symbolTable->entryScope();
            auto ptrList = listContent->toListPointer()->getAll();
            env.symbolTable->declare(id->getName(), env.ojbManager->create());
            for (auto v : ptrList) {
                id->set(env, v);
                env.symbolTable->entryScope();
                r = directParagraph->run(env);
                switch (r) {
                case SpringBaseStatement::SpringStatementResultFlag::NORMAL:
                case SpringBaseStatement::SpringStatementResultFlag::CONTINUE:
                    break;

                case SpringBaseStatement::SpringStatementResultFlag::BREAK:
                    r = SpringBaseStatement::SpringStatementResultFlag::NORMAL;
                default:
                    env.symbolTable->exitScope();
                    env.symbolTable->exitScope();
                    return r;
                }
                env.symbolTable->exitScope();
            }
            r = SpringBaseStatement::SpringStatementResultFlag::NORMAL;
            env.symbolTable->exitScope();
            return r;
        }

        default:
            return r;
        }
    }

    int SpringControlFlowStatement::getRealLineNo()
    {
        switch (type)
        {
        case 'i':
        case 'w':
        case 'l':
        case 'f':
            if(directParagraph != nullptr){
                int first = directParagraph->getFirstStmtLineNo();
                return first - 1;
            }
            return -1;

        default:
            return SpringBaseStatement::getRealLineNo();
        }
    }

    void SpringControlFlowStatement::printStructure(int blankNum)
    {
        int i = 0;
        std::string str = "";
        while (i++ < blankNum)
            str += "    ";
        qDebug() << QString::fromStdString(str + "SpringControlFlowStatement") << getRealLineNo();
    }

}
