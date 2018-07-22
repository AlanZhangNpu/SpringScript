#ifndef SPRINGEXCEPTION_H
#define SPRINGEXCEPTION_H
#include <exception>
#include <string>

namespace spr{

    class __declspec(dllexport) SpringException : public std::exception
    {
    public:
         enum SpringErrorType{
             SPRING_ERROR_FAILED_TO_OPEN_FILE,
             SPRING_ERROR_LEXICAL_ERROR,
             SPRING_ERROR_SYNTAX_ERROR,
             SPRING_TYPE_ERROR,
             SPRING_RUNTIME_ERROR,
             SPRING_LOGIC_ERROR,
             SPRING_ERROR_OTHER,
             SPRING_ACTIVE_TERMINATION
         };

        SpringException(SpringException::SpringErrorType type, std::string msg, int lineNo = -1);
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
    };

}

#endif // SPRINGEXCEPTION_H
