#include "Spring.h"

#include <fstream>

#include "./core/parser/Exa1Scanner.h"
#include "./core/expression/SpringBaseExpression.h"
#include "./lib/SpringLibraryLoader.h"
#include "SpringInterpreter.h"

#include "SpringException.h"

namespace spr {


    Spring *Spring::getInstance()
    {
        return new SpringInterpreter();
    }

    Spring::~Spring()
    {}

    int Spring::test()
    {
        return 1;
    }

}
