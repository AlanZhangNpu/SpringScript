#include "SpringBaseExpression.h"
#include "Spring.h"

namespace spr{

    SpringBaseExpression::~SpringBaseExpression()
    {}

    void SpringBaseExpression::set(SpringRuntimeEnvironment &, const SpringObjectPtr &)
    {
        Spring::throwSyntaxErrorException("cannot assign to rvalue");
    }

    bool SpringBaseExpression::isLeftValue()
    {
        return false;
    }

}
