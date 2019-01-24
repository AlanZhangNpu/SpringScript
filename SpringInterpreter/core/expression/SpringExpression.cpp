#include "SpringExpression.h"
#include "Spring.h"
#include "SpringExpressionList.h"

#include "./core/object/SpringStandardType.h"
#include "./core/statement/SpringParagraph.h"

namespace spr {

    /***********************************************************************
    SpringArrowExpression
    ***********************************************************************/

    SpringArrowExpression::SpringArrowExpression(SpringIDExpression *o, SpringBaseExpression *e):
        objectId(o),
        expression(e)
    {}

    SpringArrowExpression::~SpringArrowExpression()
    {
        if(objectId != nullptr)
            delete objectId;
        if(expression != nullptr)
            delete expression;
    }

    SpringObjectPtr SpringArrowExpression::evaluate(SpringRuntimeEnvironment &env)
    {
        auto structId = objectId->getName();
        SpringObjectPtr structValue = env.symbolTable->get(structId);
        SpringObjectPtr prototypeValue = expression->evaluate(env);
        structValue->setPrototype(prototypeValue, env);
        return structValue;
    }

    /***********************************************************************
    SpringListDefinitionExpression
    ***********************************************************************/

    SpringListDefinitionExpression::SpringListDefinitionExpression(SpringExpressionList *e):
        expList(e)
    {}

    SpringListDefinitionExpression::~SpringListDefinitionExpression()
    {
        if(expList != nullptr)
            delete expList;
    }

    SpringObjectPtr SpringListDefinitionExpression::evaluate(SpringRuntimeEnvironment &env)
    {
        if(expList == nullptr)
            return env.ojbManager->createEmptyList();
        return expList->evaluate(env);
    }

    /***********************************************************************
    SpringObjectDefinitionExpression
    ***********************************************************************/

    SpringObjectDefinitionExpression::SpringObjectDefinitionExpression(SpringParagraph *p):
        body(p)
    {}

    SpringObjectDefinitionExpression::~SpringObjectDefinitionExpression()
    {
        if(body != nullptr)
            delete body;
    }

    SpringObjectPtr SpringObjectDefinitionExpression::evaluate(SpringRuntimeEnvironment &env)
    {
        env.symbolTable->entryScope();
        if(body != nullptr)
            body->run(env);

        SpringStruct* s = env.ojbManager->createEmptyObject();
        std::vector<std::string> symbols = env.symbolTable->getCurrentScopeSymbols();
        for(auto sym : symbols){
            s->addMember(sym, env.symbolTable->get(sym));
        }
        env.symbolTable->exitScope();
        return s;
    }

    /***********************************************************************
    SpringFunctionCallExpression
    ***********************************************************************/

    SpringFunctionCallExpression::SpringFunctionCallExpression(SpringBaseExpression *f, SpringExpressionList *e):
        func(f),
        expList(e)
    {}

    SpringFunctionCallExpression::~SpringFunctionCallExpression()
    {
        if(func != nullptr)
            delete func;
        if(expList != nullptr)
            delete expList;
    }

    SpringObjectPtr SpringFunctionCallExpression::evaluate(SpringRuntimeEnvironment &env)
    {
        auto callable = func->evaluate(env);
        if(expList != nullptr)
            return callable->call(expList->evaluate(env)->toListPointer()->getAll(), env);
        else
            return callable->call({}, env);
    }

    /***********************************************************************
    SpringConstantExpression
    ***********************************************************************/

    SpringConstantExpression::SpringConstantExpression():
        constType(NIL_TYPE)
    {}

    SpringConstantExpression::SpringConstantExpression(bool b):
        constType(BOOL_TYPE),
        bValue(b)
    {}

    SpringConstantExpression::SpringConstantExpression(int n):
        constType(INT_TYPE),
        iValue(n)
    {}

    SpringConstantExpression::SpringConstantExpression(double d):
        constType(DOUBLE_TYPE),
        dValue(d)
    {}

    SpringConstantExpression::SpringConstantExpression(char * c):
        constType(STRING_TYPE)
    {
        sValue = std::string(c);
        free(c);
        sValue = sValue.substr(1, sValue.length() - 2);

        // TODO 下面处理转义字符
    }

    SpringConstantExpression::SpringConstantExpression(SpringBaseExpression * a,
                                           SpringParagraph * b):
        constType(FUNC_TYPE),
        funcBody(b)
    {
        funcArgs = dynamic_cast<SpringIDListExpression *>(a);
        funcArgs->checkSyntax();
    }

    SpringConstantExpression::SpringConstantExpression(SpringParagraph *b):
        constType(FUNC_TYPE),
        funcBody(b)
    {}

    SpringConstantExpression::~SpringConstantExpression()
    {
        if(funcArgs != nullptr)
            delete funcArgs;
        if(funcBody != nullptr)
            delete funcBody;
    }

    SpringObjectPtr SpringConstantExpression::evaluate(SpringRuntimeEnvironment &env)
    {
        switch (constType) {
        case NIL_TYPE:      return env.ojbManager->create();
        case BOOL_TYPE:     return env.ojbManager->create(bValue);
        case INT_TYPE:      return env.ojbManager->create(iValue);
        case DOUBLE_TYPE:   return env.ojbManager->create(dValue);
        case STRING_TYPE:   return env.ojbManager->create(sValue);
        case FUNC_TYPE:
        {
            return env.ojbManager->create(funcArgs, funcBody);
        }
        }
        return env.ojbManager->create();
    }

    /***********************************************************************
    SpringIDListExpression
    ***********************************************************************/

    SpringIDListExpression::SpringIDListExpression()
    {}

    SpringIDListExpression::SpringIDListExpression(SpringIDExpression * id)
    {
        add_front(id);
    }

    SpringIDListExpression::~SpringIDListExpression()
    {
        for (auto id : idList)
            delete id;
    }

    void SpringIDListExpression::add_front(SpringIDExpression * id)
    {
        idList.push_front(id);
    }

    unsigned SpringIDListExpression::size()
    {
        return idList.size();
    }

    int SpringIDListExpression::getNondefaultArgumentNum()
    {
        int n = 0;
        for(auto item : idList){
            if(item->hasDefaultValue())
                break;
            n++;
        }
        return n;
    }

    SpringIDExpression* SpringIDListExpression::at(unsigned id)
    {
        return idList[id];
    }

    SpringIDExpression* SpringIDListExpression::operator[](unsigned id)
    {
        return idList[id];
    }

    void SpringIDListExpression::checkSyntax()
    {
        bool foundIDWithDefaultValue = false;
        for(auto id : idList){
            if(id->hasDefaultValue())
                foundIDWithDefaultValue = true;
            else if (foundIDWithDefaultValue) {
                throw SpringException(SpringException::SPRING_ERROR_SYNTAX_ERROR, "Non-default argument follows default argument");
            }
        }
    }

    std::vector<std::string> SpringIDListExpression::getAllSymbols()
    {
        std::vector<std::string> symbols;
        for (auto id : idList)
        {
            symbols.push_back(id->getName());
        }
        return symbols;
    }

    SpringObjectPtr SpringIDListExpression::evaluate(SpringRuntimeEnvironment &env)
    {
        return env.ojbManager->create();
    }

    /***********************************************************************
    SpringIDExpression
    ***********************************************************************/

    SpringIDExpression::SpringIDExpression(char * id)
    {
        name = std::string(id);
        defaultValue = nullptr;
        free(id);
    }

    SpringIDExpression::SpringIDExpression(char *id, SpringBaseExpression *d)
    {
        name = std::string(id);
        free(id);
        defaultValue = d;
    }

    SpringIDExpression::~SpringIDExpression()
    {
        if(defaultValue != nullptr)
            delete defaultValue;
    }

    std::string SpringIDExpression::getName()
    {
        return name;
    }

    SpringObjectPtr SpringIDExpression::getDefaultValue(SpringRuntimeEnvironment & env)
    {
        if(defaultValue == nullptr)
            return env.ojbManager->create();
        return defaultValue->evaluate(env);
    }

    bool SpringIDExpression::hasDefaultValue()
    {
        return defaultValue != nullptr;
    }

    SpringObjectPtr SpringIDExpression::evaluate(SpringRuntimeEnvironment & env)
    {
        return env.symbolTable->get(name);
    }

    void SpringIDExpression::set(SpringRuntimeEnvironment &env, const SpringObjectPtr &p)
    {
        env.symbolTable->assign(name, p);
    }

    bool SpringIDExpression::isLeftValue()
    {
        return true;
    }

    /***********************************************************************
    SpringSubscriptExpression
    ***********************************************************************/

    SpringSubscriptExpression::SpringSubscriptExpression(SpringBaseExpression * l, SpringBaseExpression * s) :
        targetList(l),
        startIdx(s)
    {}

    SpringSubscriptExpression::~SpringSubscriptExpression()
    {
        if(targetList != nullptr)
            delete targetList;
        if(startIdx != nullptr)
            delete startIdx;
    }

    SpringObjectPtr SpringSubscriptExpression::evaluate(SpringRuntimeEnvironment & env)
    {
        SpringObjectPtr list = targetList->evaluate(env);
        SpringObjectPtr idx = startIdx->evaluate(env);
        return list->getItem(idx, env);
    }

    void SpringSubscriptExpression::set(SpringRuntimeEnvironment &env, const SpringObjectPtr &p)
    {
        SpringObjectPtr target = targetList->evaluate(env);
        SpringObjectPtr idx = startIdx->evaluate(env);
        target->setItem(idx, p, env);
    }

    bool SpringSubscriptExpression::isLeftValue()
    {
        return true;
    }

    /***********************************************************************
    SpringOperatorExpression
    ***********************************************************************/

    SpringOperatorExpression::SpringOperatorExpression()
    {}

    SpringOperatorExpression::SpringOperatorExpression(int t, SpringBaseExpression *l):
        nodeType(t),
        leftTree(l)
    {
        if(nodeType >= 102 && nodeType <= 105 && !(l->isLeftValue()))
            SpringException::throwSyntaxErrorException("cannot assign to rvalue.");
    }

    SpringOperatorExpression::SpringOperatorExpression(int t, SpringBaseExpression * l, SpringBaseExpression * r):
        nodeType(t),
        leftTree(l),
        rightTree(r)
    {
        if(nodeType >= 219 && nodeType <= 229 && !(l->isLeftValue()))
            SpringException::throwSyntaxErrorException("cannot assign to rvalue.");
    }

    SpringOperatorExpression::SpringOperatorExpression(int t, SpringBaseExpression *l, SpringBaseExpression *m, SpringBaseExpression *r):
        nodeType(t),
        leftTree(l),
        midTree(m),
        rightTree(r)
    {}

    SpringOperatorExpression::~SpringOperatorExpression()
    {
        if(leftTree != nullptr)
            delete leftTree;
        if(midTree != nullptr)
            delete midTree;
        if(rightTree != nullptr)
            delete rightTree;
    }

    SpringObjectPtr SpringOperatorExpression::evaluate(SpringRuntimeEnvironment &env)
    {
        switch (this->nodeType)
        {
            /***************************Unary operator*****************************/
        case 100:
        {
            // #exp
            SpringObjectPtr arg0 = leftTree->evaluate(env);
            return arg0->size(env);
        }
        case 101:
        {
            // -exp
            return leftTree->evaluate(env)->opposite(env);
        }
        case 102:
        {
            // ++exp
            auto arg = leftTree->evaluate(env);
            SpringObjectPtr newValue = arg->increment(env);
            leftTree->set(env, newValue);
            return newValue;
        }
        case 103:
        {
            // --exp
            auto arg = leftTree->evaluate(env);
            SpringObjectPtr newValue = arg->decrement(env);
            leftTree->set(env, newValue);
            return newValue;
        }
        case 104:
        {
            // exp++
            auto arg = leftTree->evaluate(env);
            leftTree->set(env, arg->increment(env));
            return arg;
        }
        case 105:
        {
            // exp--
            auto arg = leftTree->evaluate(env);
            leftTree->set(env, arg->decrement(env));
            return arg;
        }
        case 106:
        {
            // ~exp
            return leftTree->evaluate(env)->bitwiseComplement(env);
        }
        case 107:
        {
            // !exp
            return leftTree->evaluate(env)->logicalNot(env);
        }

            /***************************Binary operator*****************************/
        case 200:
        {
            // exp+exp
            SpringObjectPtr arg0 = leftTree->evaluate(env);
            SpringObjectPtr arg1 = rightTree->evaluate(env);
            return arg0->add(arg1, env);
        }
        case 201:
        {
            // exp-exp
            SpringObjectPtr arg0 = leftTree->evaluate(env);
            SpringObjectPtr arg1 = rightTree->evaluate(env);
            return arg0->subtract(arg1, env);
        }
        case 202:
        {
            // exp*exp
            SpringObjectPtr arg0 = leftTree->evaluate(env);
            SpringObjectPtr arg1 = rightTree->evaluate(env);
            return arg0->multiply(arg1, env);
        }
        case 203:
        {
            // exp**exp
            SpringObjectPtr arg0 = leftTree->evaluate(env);
            SpringObjectPtr arg1 = rightTree->evaluate(env);
            return arg0->power(arg1, env);
        }
        case 204:
        {
            // exp/exp
            SpringObjectPtr arg0 = leftTree->evaluate(env);
            SpringObjectPtr arg1 = rightTree->evaluate(env);
            return arg0->divide(arg1, env);
        }
        case 205:
        {
            // exp%exp
            SpringObjectPtr arg0 = leftTree->evaluate(env);
            SpringObjectPtr arg1 = rightTree->evaluate(env);
            return arg0->mod(arg1, env);
        }

            // comparison operation
        case 206:
        {
            // exp>exp
            SpringObjectPtr arg0 = leftTree->evaluate(env);
            SpringObjectPtr arg1 = rightTree->evaluate(env);
            return arg0->greater(arg1, env);
        }
        case 207:
        {
            // exp<exp
            SpringObjectPtr arg0 = leftTree->evaluate(env);
            SpringObjectPtr arg1 = rightTree->evaluate(env);
            return arg0->less(arg1, env);
        }
        case 208:
        {
            // exp>=exp
            SpringObjectPtr arg0 = leftTree->evaluate(env);
            SpringObjectPtr arg1 = rightTree->evaluate(env);
            return arg0->greaterEqual(arg1, env);
        }
        case 209:
        {
            // exp<=exp
            SpringObjectPtr arg0 = leftTree->evaluate(env);
            SpringObjectPtr arg1 = rightTree->evaluate(env);
            return arg0->lessEqual(arg1, env);
        }
        case 210:
        {
            // exp==exp
            SpringObjectPtr arg0 = leftTree->evaluate(env);
            SpringObjectPtr arg1 = rightTree->evaluate(env);
            return arg0->equal(arg1, env);
        }
        case 211:
        {
            // exp!=exp
            SpringObjectPtr arg0 = leftTree->evaluate(env);
            SpringObjectPtr arg1 = rightTree->evaluate(env);
            return arg0->notEqual(arg1, env);
        }

            // logic operation
        case 212:
        {
            // exp&&exp
            SpringObjectPtr arg0 = leftTree->evaluate(env);
            if (!arg0->isStruct() && !(arg0->toBool()))
                return env.ojbManager->create(false);
            return arg0->logicalAnd(rightTree->evaluate(env), env);
        }
        case 213:
        {
            // exp||exp
            SpringObjectPtr arg0 = leftTree->evaluate(env);
            if (!arg0->isStruct() && arg0->toBool())
                return env.ojbManager->create(true);
            return arg0->logicalOr(rightTree->evaluate(env), env);
        }
            // bitwise operation
        case 214:
        {
            // exp&exp
            SpringObjectPtr arg0 = leftTree->evaluate(env);
            SpringObjectPtr arg1 = rightTree->evaluate(env);
            return arg0->bitwiseAnd(arg1, env);
        }
        case 215:
        {
            // exp|exp
            SpringObjectPtr arg0 = leftTree->evaluate(env);
            SpringObjectPtr arg1 = rightTree->evaluate(env);
            return arg0->bitwiseOr(arg1, env);
        }
        case 216:
        {
            // exp^exp
            SpringObjectPtr arg0 = leftTree->evaluate(env);
            SpringObjectPtr arg1 = rightTree->evaluate(env);
            return arg0->bitwiseXor(arg1, env);
        }
        case 217:
        {
            // exp<<exp
            SpringObjectPtr arg0 = leftTree->evaluate(env);
            SpringObjectPtr arg1 = rightTree->evaluate(env);
            return arg0->bitwiseShiftLeft(arg1, env);
        }
        case 218:
        {
            // exp>>exp
            SpringObjectPtr arg0 = leftTree->evaluate(env);
            SpringObjectPtr arg1 = rightTree->evaluate(env);
            return arg0->bitwiseShiftRight(arg1, env);
        }
        case 219:
        {
            // exp+=exp
            auto arg0 = leftTree->evaluate(env);
            auto arg1 = rightTree->evaluate(env);
            SpringObjectPtr newValue;
            newValue = arg0->add(arg1, env);
            leftTree->set(env, newValue);
            return newValue;
        }
        case 220:
        {
            // exp-=exp
            auto arg0 = leftTree->evaluate(env);
            auto arg1 = rightTree->evaluate(env);
            SpringObjectPtr newValue;
            newValue = arg0->subtract(arg1, env);
            leftTree->set(env, newValue);
            return newValue;
        }
        case 221:
        {
            // exp*=exp
            auto arg0 = leftTree->evaluate(env);
            auto arg1 = rightTree->evaluate(env);
            SpringObjectPtr newValue;
            newValue = arg0->multiply(arg1, env);
            leftTree->set(env, newValue);
            return newValue;
        }
        case 222:
        {
            // exp**=exp
            auto arg0 = leftTree->evaluate(env);
            auto arg1 = rightTree->evaluate(env);
            SpringObjectPtr newValue;
            newValue = arg0->power(arg1, env);
            leftTree->set(env, newValue);
            return newValue;
        }
        case 223:
        {
            // exp/=exp
            auto arg0 = leftTree->evaluate(env);
            auto arg1 = rightTree->evaluate(env);
            SpringObjectPtr newValue;
            newValue = arg0->divide(arg1, env);
            leftTree->set(env, newValue);
            return newValue;
        }
        case 224:
        {
            // exp%=exp
            auto arg0 = leftTree->evaluate(env);
            auto arg1 = rightTree->evaluate(env);
            SpringObjectPtr newValue;
            newValue = arg0->mod(arg1, env);
            leftTree->set(env, newValue);
            return newValue;
        }
        case 225:
        {
            // exp&=exp
            auto arg0 = leftTree->evaluate(env);
            auto arg1 = rightTree->evaluate(env);
            SpringObjectPtr newValue;
            newValue = arg0->bitwiseAnd(arg1, env);
            leftTree->set(env, newValue);
            return newValue;
        }
        case 226:
        {
            // exp|=exp
            auto arg0 = leftTree->evaluate(env);
            auto arg1 = rightTree->evaluate(env);
            SpringObjectPtr newValue;
            newValue = arg0->bitwiseOr(arg1, env);
            leftTree->set(env, newValue);
            return newValue;
        }
        case 227:
        {
            // exp^=exp
            auto arg0 = leftTree->evaluate(env);
            auto arg1 = rightTree->evaluate(env);
            SpringObjectPtr newValue;
            newValue = arg0->bitwiseXor(arg1, env);
            leftTree->set(env, newValue);
            return newValue;
        }
        case 228:
        {
            // exp<<=exp
            auto arg0 = leftTree->evaluate(env);
            auto arg1 = rightTree->evaluate(env);
            SpringObjectPtr newValue;
            newValue = arg0->bitwiseShiftLeft(arg1, env);
            leftTree->set(env, newValue);
            return newValue;
        }
        case 229:
        {
            // exp>>=exp
            auto arg0 = leftTree->evaluate(env);
            auto arg1 = rightTree->evaluate(env);
            SpringObjectPtr newValue;
            newValue = arg0->bitwiseShiftRight(arg1, env);
            leftTree->set(env, newValue);
            return newValue;
        }

            /***************************Ternary operator*****************************/
        case 300:
        {
            // exp?exp:exp
            if(leftTree->evaluate(env)->toBool())
                return midTree->evaluate(env);
            return rightTree->evaluate(env);
        }
        default:
            SpringException::throwRawException("Unknown operator " + std::to_string(nodeType));
            break;
        }

        return env.ojbManager->create();
    }

    /***********************************************************************
    SpringPointExpression
    ***********************************************************************/

    SpringPointExpression::SpringPointExpression(SpringBaseExpression *l, SpringIDExpression *r):
        leftTree(l),
        rightTree(r)
    {}

    SpringPointExpression::~SpringPointExpression()
    {
        if(leftTree != nullptr)
            delete leftTree;
        if(rightTree != nullptr)
            delete rightTree;
    }

    bool SpringPointExpression::isLeftValue()
    {
        return true;
    }

    SpringObjectPtr SpringPointExpression::evaluate(SpringRuntimeEnvironment &env)
    {
        auto l = leftTree->evaluate(env);
        return l->getAttribute(rightTree->getName(), env);
    }

    void SpringPointExpression::set(SpringRuntimeEnvironment &env,
                                         const SpringObjectPtr &value)
    {
        auto key = rightTree->getName();
        SpringObjectPtr structValue = leftTree->evaluate(env);
        structValue->setAttribute(key, value, env);
    }

    /***********************************************************************
    SpringNewExpression
    ***********************************************************************/

    SpringNewExpression::SpringNewExpression(SpringIDExpression *i):
        classId(i)
    {}

    SpringNewExpression::~SpringNewExpression()
    {
        if(classId != nullptr)
            delete classId;
    }

    SpringObjectPtr SpringNewExpression::evaluate(SpringRuntimeEnvironment &env)
    {
        auto classObj = classId->evaluate(env);
        auto r = classObj->newInstance(env);
        return r;
    }

}
