#include "SpringStandardLibrary.h"

#include "Spring.h"

namespace spr{

    SpringStandardLibrary::SpringStandardLibrary(std::string name,
                                                 std::string description,
                                                 std::string author,
                                                 std::string version)
    {
        libSpecification.libName = name;
        libSpecification.libDescription = description;
        libSpecification.libVersion = version;
        libSpecification.libAuthor = author;
    }

    void SpringStandardLibrary::setLibraryName(const std::string &name)
    {
        libSpecification.libName = name;
    }

    void SpringStandardLibrary::setLibraryDescription(const std::string &description)
    {
        libSpecification.libDescription = description;
    }

    void SpringStandardLibrary::setLibraryAuthor(const std::string &author)
    {
        libSpecification.libAuthor = author;
    }

    void SpringStandardLibrary::setLibraryVersion(const std::string &version)
    {
        libSpecification.libVersion = version;
    }

    std::string SpringStandardLibrary::getLibraryName()
    {
        return libSpecification.libName;
    }

    SpringLibrarySpecification SpringStandardLibrary::getSpecification(){
        libSpecification.functions.clear();
        for(auto it = exeFunctions.begin(); it != exeFunctions.end(); it++)
        {
            SpringLibrarySpecification::SpringFunctionInformation funcInfo;
            funcInfo.funcName = it->first;
            funcInfo.funcDescription = it->second.funcDescription;
            libSpecification.functions.push_back(funcInfo);
        }
        return libSpecification;
    }

    std::string SpringStandardLibrary::getSpecificationString(){
        libSpecification.functions.clear();
        for(auto it = exeFunctions.begin(); it != exeFunctions.end(); it++)
        {
            SpringLibrarySpecification::SpringFunctionInformation funcInfo;
            funcInfo.funcName = it->first;
            funcInfo.funcDescription = it->second.funcDescription;
            libSpecification.functions.push_back(funcInfo);
        }
        return libSpecification.toString();
    }

    SpringObjectPtr SpringStandardLibrary::invoke(std::string funcName,
                                              const std::vector<SpringObjectPtr> &args,
                                              SpringRuntimeEnvironment &runtimeEnvironment)
    {
        auto it = exeFunctions.find(funcName);
        if(it == exeFunctions.end())
            Spring::throwRawException("Undefined function: " + funcName);
        return it->second.func(args, runtimeEnvironment);
    }

    std::vector<std::string> SpringStandardLibrary::getRegisteredFunctions()
    {
        std::vector<std::string> functionName;
        for(auto it = exeFunctions.begin(); it != exeFunctions.end(); it++)
        {
            functionName.push_back(it->first);
        }
        return functionName;
    }

    bool SpringStandardLibrary::existFunction(std::string funcName)
    {
        auto it = exeFunctions.find(funcName);
        if(it == exeFunctions.end())
            return false;
        return true;
    }

    std::string SpringStandardLibrary::getFunctionDescription(std::string funcName)
    {
        auto it = exeFunctions.find(funcName);
        if(it == exeFunctions.end())
            Spring::throwRawException("Undefined function: " + funcName);
        return it->second.funcDescription;
    }

    void SpringStandardLibrary::registerFunction(SpringStandardLibrary::SpringStandardLibraryFunction standardFunction)
    {
        exeFunctions.insert(std::make_pair(standardFunction.funcName, standardFunction));
    }

    void SpringStandardLibrary::registerFunction(std::string funcName, std::string funcDescription, SpringStandardLibraryFunctionType f)
    {
        SpringStandardLibraryFunction springFunc(funcName, funcDescription, f);
        registerFunction(springFunc);
    }

/***********************************************************************
SpringStandardLibrary::SpringStandardLibraryFunction
***********************************************************************/

    SpringStandardLibrary::SpringStandardLibraryFunction::SpringStandardLibraryFunction():
        funcName(""),
        funcDescription("")
    {}

    SpringStandardLibrary::SpringStandardLibraryFunction::SpringStandardLibraryFunction(std::string name,
                                                                                        std::string description,
                                                                                        SpringStandardLibraryFunctionType f):
        funcName(name),
        funcDescription(description),
        func(f)
    {}

    SpringStandardLibrary::SpringStandardLibraryFunction::SpringStandardLibraryFunction(std::string name,
                                                                                        std::string description,
                                                                                        std::function<SpringObjectPtr (const std::vector<SpringObjectPtr> &)> f):
        funcName(name),
        funcDescription(description)
    {
        func = [f](const std::vector<SpringObjectPtr> &args, SpringRuntimeEnvironment &) -> SpringObjectPtr{
            return f(args);
        };
    }

    SpringStandardLibrary::SpringStandardLibraryFunction::SpringStandardLibraryFunction(std::string name,
                                                                                        std::string description,
                                                                                        std::function<void (SpringRuntimeEnvironment &)> f):
        funcName(name),
        funcDescription(description)
    {
        func = [f](const std::vector<SpringObjectPtr> &, SpringRuntimeEnvironment &env) -> SpringObjectPtr{
            f(env);
            return env.ojbManager->create();
        };
    }

    SpringStandardLibrary::SpringStandardLibraryFunction::SpringStandardLibraryFunction(std::string name,
                                                                                        std::string description,
                                                                                        std::function<SpringObjectPtr ()> f):
        funcName(name),
        funcDescription(description)
    {
        func = [f](const std::vector<SpringObjectPtr> &, SpringRuntimeEnvironment &) -> SpringObjectPtr{
            return f();
        };
    }

}
