#ifndef SPRINGINTERPRETER_H
#define SPRINGINTERPRETER_H

#include "Spring.h"

namespace spr {

    class SpringInterpreter : public Spring
    {
    public:
        SpringInterpreter();
        ~SpringInterpreter();

        virtual void init(SpringIOHelper * h = nullptr, SpringRuntimeController *c = nullptr) override;
        virtual void registerFunction(const std::string &funcName, const std::string &funcDescription, const SpringStandardFunctionType &f) override;
        virtual void interprete(const char *codeFilePath) override;
        virtual SpringObjectPtr getValue(const std::string &name) override;
        virtual SpringSymbolTable* getSymbolTable() override;
        virtual SpringRuntimeEnvironment* getEnv() override;
        virtual void clear() override;

    private:
        SpringRuntimeEnvironment runtimeEnvironment;
    };

}
#endif // SPRINGINTERPRETER_H
