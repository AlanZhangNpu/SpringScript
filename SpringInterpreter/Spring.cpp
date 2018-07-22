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

    void Spring::throwRawException(std::string msg)
    {
        throw std::runtime_error(msg);
    }

    void Spring::throwSyntaxErrorException(std::string msg)
    {
        throw SpringException(SpringException::SPRING_ERROR_SYNTAX_ERROR, msg);
    }

    void Spring::throwLogicErrorException(std::string msg, int lineNo)
    {
        throw SpringException(SpringException::SPRING_LOGIC_ERROR, msg, lineNo);
    }

    void Spring::throwRuntimeError(std::string msg, int lineNo)
    {
        throw SpringException(SpringException::SPRING_RUNTIME_ERROR, msg, lineNo);
    }

    void Spring::throwUnknownOperatorException(const std::string &op,
                                               const std::vector<SpringObject::SpringObjectType> &argList)
    {
        std::string k = "(";
        for(unsigned i = 0; i < argList.size(); i++)
        {
            k += SpringObject::typeToString(argList[i]);
            if(i != argList.size() - 1)
                k += ",";
            else
                k += ")";
        }
        Spring::throwRawException("Undefined operator " + op + " on " + k);
    }

    void Spring::throwTypeErrorException(const std::string &targetType, const std::string &sourceType)
    {
        throw SpringException(SpringException::SPRING_TYPE_ERROR, "cannot assign " + sourceType + " to " + targetType);
    }

    void Spring::throwNoAttributeException(const std::string &key)
    {
        Spring::throwRawException("Undefined member named \"" + key + "\"");
    }

    Spring::~Spring()
    {}

}
