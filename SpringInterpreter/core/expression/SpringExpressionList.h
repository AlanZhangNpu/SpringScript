#ifndef SPRINGEXPRESSIONLIST_H
#define SPRINGEXPRESSIONLIST_H
#include <vector>
#include "SpringBaseExpression.h"

namespace spr {

    class SpringBaseExpression;
    class SpringExpressionList
    {
    public:
        SpringExpressionList();
        SpringExpressionList(SpringBaseExpression *e);
        ~SpringExpressionList();

        void add(SpringBaseExpression * e);
        unsigned size();
        SpringBaseExpression* at(const unsigned &i);

        SpringObjectPtr evaluate(SpringRuntimeEnvironment & env);
//        void release();
        void getRightValues(std::vector<unsigned> &rvalueIds);

    private:
        std::vector<SpringBaseExpression *> expList;
    };

}
#endif // SPRINGEXPRESSIONLIST_H
