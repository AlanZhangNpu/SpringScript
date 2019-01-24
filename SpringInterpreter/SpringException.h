#ifndef SPRINGEXCEPTION_H
#define SPRINGEXCEPTION_H
#include <exception>
#include <string>
#include <vector>

#include "./core/object/SpringObject.h"

namespace spr{

    class __declspec(dllexport) SpringException : public std::exception
    {
    public:
         enum SpringErrorType{
             SPRING_ERROR_LEXICAL_ERROR,
             SPRING_ERROR_SYNTAX_ERROR,
             SPRING_RUNTIME_ERROR,
             SPRING_ERROR_OTHER
         };

        SpringException(SpringException::SpringErrorType type,
                        const std::string &msg,
                        int lineNo = -1);
        SpringException();
        ~SpringException()throw(){}

        void setErrorMessage(const std::string &msg);
        void setLineNo(const int &l);
        std::string toString();
        const char *what();
        int getLineNo();

    private:
        SpringErrorType errorType;
        std::string errorMsg;
        int errorLineNo;

    public:

        /***********************************************************************
        static functions
        ***********************************************************************/

        static void throwRawException(std::string msg);
        static void throwRuntimeError(std::string msg, int lineNo = -1);
        static void throwSyntaxErrorException(std::string msg);
        static void throwUnknownOperatorException(const std::string &op, const std::vector<SpringObject::SpringObjectType> &argList);
        static void throwTypeErrorException(const std::string &targetType, const std::string &sourceType);
        static void throwNoAttributeException(const std::string &key);
    };

}

#endif // SPRINGEXCEPTION_H
