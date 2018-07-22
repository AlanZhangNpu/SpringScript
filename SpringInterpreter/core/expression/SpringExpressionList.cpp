#include "SpringExpressionList.h"

namespace spr {

    SpringExpressionList::SpringExpressionList()
    {}

    SpringExpressionList::SpringExpressionList(SpringBaseExpression *e)
    {
        add(e);
    }

    SpringExpressionList::~SpringExpressionList()
    {
        for (auto exp : expList)
            delete exp;
    }

    void SpringExpressionList::add(SpringBaseExpression *e)
    {
        expList.push_back(e);
    }

    unsigned SpringExpressionList::size()
    {
        return expList.size();
    }

    SpringBaseExpression *SpringExpressionList::at(const unsigned &i)
    {
        return expList.at(i);
    }

    SpringObjectPtr SpringExpressionList::evaluate(SpringRuntimeEnvironment &env)
    {
        std::vector<SpringObjectPtr> ptrList;
        for (auto exp : expList)
        {
            SpringObjectPtr response = exp->evaluate(env);
            ptrList.push_back(response);
        }
        return env.ojbManager->create(ptrList);
    }

    void SpringExpressionList::getRightValues(std::vector<unsigned> &rvalueIds)
    {
        rvalueIds.clear();
        for(unsigned i = 0; i < expList.size(); i++)
            if(!expList.at(i)->isLeftValue())
                rvalueIds.push_back(i);
    }

}
