#include "SpringException.h"

namespace spr{

    SpringException::SpringException():
        errorType(SPRING_ERROR_OTHER),
        errorMsg(""),
        errorLineNo(-1)
    {}

    SpringException::SpringException(SpringException::SpringErrorType type,
                                     std::string msg,
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
        case SPRING_ERROR_FAILED_TO_OPEN_FILE:
            strErrorType = "File error";
            break;

        case SPRING_ERROR_LEXICAL_ERROR:
            strErrorType = "Lexical error";
            break;

        case SPRING_ERROR_SYNTAX_ERROR:
            strErrorType = "Syntax error";
            break;

        case SPRING_RUNTIME_ERROR:
            strErrorType = "Runtime error";
            break;

        case SPRING_LOGIC_ERROR:
            strErrorType = "Logic error";
            break;

        case SPRING_ACTIVE_TERMINATION:
            strErrorType = "Active termination";
            break;

        case SPRING_TYPE_ERROR:
            strErrorType = "TypeError";
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

}
