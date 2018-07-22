#ifndef BASEEXPRESSION_H
#define BASEEXPRESSION_H

#include <memory>
#include <string>

#include "SpringRuntimeEnvironment.h"
#include "./core/object/SpringObject.h"

namespace spr{

    class SpringBaseExpression
    {
    public:
        virtual ~SpringBaseExpression();
        virtual SpringObjectPtr evaluate(SpringRuntimeEnvironment &) = 0;
        virtual void set(SpringRuntimeEnvironment &, const SpringObjectPtr &);
        virtual bool isLeftValue();
    };

}

#endif // BASEEXPRESSION_H
