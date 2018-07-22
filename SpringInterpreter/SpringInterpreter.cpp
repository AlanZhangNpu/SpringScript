#include "SpringInterpreter.h"

#include <fstream>

#include "./lib/SpringLibraryLoader.h"
#include "./core/parser/Exa1Scanner.h"

namespace spr {

    SpringInterpreter::SpringInterpreter()
    {}

    SpringInterpreter::~SpringInterpreter()
    {
        runtimeEnvironment.clear();
    }

    void SpringInterpreter::init(SpringIOHelper *h, SpringRuntimeController *c)
    {
        runtimeEnvironment.init(h, c);
        SpringLibraryLoader::loadBasicLib(runtimeEnvironment);
    }

    void SpringInterpreter::registerFunction(const std::string &funcName, const std::string &funcDescription, const SpringStandardFunctionType &f)
    {
        runtimeEnvironment.symbolTable->declare(funcName, runtimeEnvironment.ojbManager->create(f, funcDescription));
    }

    void SpringInterpreter::interprete(const char *codeFilePath)
    {
        std::string codeFilePathStr = codeFilePath;

        Exa1::Exa1Scanner sc;

        std::filebuf fbIn;
        if (!fbIn.open(codeFilePath, std::ios::in)) {
            SpringException error(SpringException::SPRING_ERROR_FAILED_TO_OPEN_FILE, "Failed to open file: " + codeFilePathStr);
            runtimeEnvironment.springIOHelper->onError(-1, error.toString());
            return;
        }

        std::istream iss(&fbIn);
        sc.yyrestart(&iss);

        Exa1::Exa1Parser parser(sc);
        try{
            parser.parse(runtimeEnvironment);
        }catch(SpringException &exception){
            exception.setLineNo(sc.lineno());
            runtimeEnvironment.springIOHelper->onError(sc.lineno(), exception.toString());
            return;
        }
    }

    SpringObjectPtr SpringInterpreter::getValue(const std::string &name)
    {
        return runtimeEnvironment.symbolTable->get(name);
    }

    SpringSymbolTable *SpringInterpreter::getSymbolTable()
    {
        return runtimeEnvironment.symbolTable;
    }

    void SpringInterpreter::clear()
    {
        runtimeEnvironment.clear();
    }

}


