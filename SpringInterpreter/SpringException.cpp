#include "SpringException.h"

namespace spr{

    SpringException::SpringException():
        errorType(SPRING_ERROR_OTHER),
        errorMsg(""),
        errorLineNo(-1)
    {}

    SpringException::SpringException(SpringException::SpringErrorType type,
                                     const std::string &msg,
                                     int lineNo):
        errorType(type),
        errorMsg(msg),
        errorLineNo(lineNo)
    {}

    void SpringException::setErrorMessage(const std::string &msg)
    {
        this->errorMsg = msg;
    }

    const char *SpringException::what()
    {
        return toString().data();
    }

    std::string SpringException::toString()
    {
        std::string strErrorType = "";
        switch (errorType) {
        case SPRING_ERROR_LEXICAL_ERROR:
            strErrorType = "Lexical error";
            break;

        case SPRING_ERROR_SYNTAX_ERROR:
            strErrorType = "Syntax error";
            break;

        case SPRING_RUNTIME_ERROR:
            strErrorType = "Runtime error";
            break;

        case SPRING_ERROR_OTHER:
        default:
            strErrorType = "Other error";
            break;
        }

        std::string str = "[";
        if(errorLineNo != -1)
            str += "Line" + std::to_string(errorLineNo) + ", ";
        str += strErrorType + "] " + errorMsg;
        return str;
    }

    int SpringException::getLineNo()
    {
        return errorLineNo;
    }

    void SpringException::setLineNo(const int &l)
    {
        errorLineNo = l;
    }

    /***********************************************************************
    static functions
    ***********************************************************************/

    void SpringException::throwRawException(std::string msg)
    {
        throw std::runtime_error(msg);
    }

    void SpringException::throwSyntaxErrorException(std::string msg)
    {
        throw SpringException(SpringException::SPRING_ERROR_SYNTAX_ERROR, msg);
    }

    void SpringException::throwRuntimeError(std::string msg, int lineNo)
    {
        throw SpringException(SpringException::SPRING_RUNTIME_ERROR, msg, lineNo);
    }

    void SpringException::throwUnknownOperatorException(const std::string &op,
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
        SpringException::throwRawException("Undefined operator " + op + " on " + k);
    }

    void SpringException::throwTypeErrorException(const std::string &targetType, const std::string &sourceType)
    {
        throw SpringException(SpringException::SPRING_RUNTIME_ERROR, "cannot assign " + sourceType + " to " + targetType);
    }

    void SpringException::throwNoAttributeException(const std::string &key)
    {
        SpringException::throwRawException("Undefined member named \"" + key + "\"");
    }
}
