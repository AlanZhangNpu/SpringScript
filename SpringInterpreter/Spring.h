#ifndef SPRING_H
#define SPRING_H

#include <string>

#include "SpringKeywords.h"
#include "SpringException.h"
#include "SpringIOHelper.h"
#include "SpringRuntimeController.h"
#include "SpringRuntimeEnvironment.h"

#include "./core/object/SpringObject.h"
#include "./core/object/SpringSymbolTable.h"
#include "./lib/SpringExtensionLibrary.h"

//#include <QDebug>

//#define zzzz qDebug()<<
#define zzzz std::cout <<

#define SPR_EXTENSION_LIBRARY_BEGIN extern "C" { \
    __declspec(dllexport) SpringExtensionLibrary getSpringThirdPartyLib(){

#define SPR_EXTENSION_LIBRARY_END }\
}

#ifdef __GNUC__
#include <cxxabi.h>
#endif
#ifdef __GNUC__
#define SPR_GET_TYPE(x) abi::__cxa_demangle(typeid(x).name(), nullptr, nullptr, nullptr)
#endif
#ifdef _MSC_VER
#define SPR_GET_TYPE(x) typeid(x).name()
#endif

namespace spr {

    class SpringParagraph;
    class __declspec(dllexport) Spring
    {
    public:
        virtual ~Spring();

        static Spring* getInstance();
        static int test();

        virtual void init(SpringIOHelper * h = nullptr, SpringRuntimeController *c = nullptr) = 0;
        virtual void registerFunction(const std::string &funcName, const std::string & funcDescription, const SpringStandardFunctionType &f) = 0;
        virtual void interprete(const char *codeFilePath) = 0;
        virtual SpringObjectPtr getValue(const std::string &name) = 0;
        virtual void clear() = 0;
        virtual SpringRuntimeEnvironment* getEnv() = 0;
        virtual SpringSymbolTable* getSymbolTable() = 0;

    };

}
#endif // SPRING_H
