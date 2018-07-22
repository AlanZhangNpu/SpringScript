#include "SpringExtensionLibrary.h"

#include "Spring.h"

namespace spr {

    SpringExtensionLibrary::SpringExtensionLibrary(std::string name,
                                                   std::string description,
                                                   std::string author,
                                                   std::string version)
    {
        libSpecification.libName = name;
        libSpecification.libDescription = description;
        libSpecification.libVersion = version;
        libSpecification.libAuthor = author;
    }

    void SpringExtensionLibrary::setLibraryName(const std::string &name)
    {
        libSpecification.libName = name;
    }

    void SpringExtensionLibrary::setLibraryDescription(const std::string &description)
    {
        libSpecification.libDescription = description;
    }

    void SpringExtensionLibrary::setLibraryAuthor(const std::string &author)
    {
        libSpecification.libAuthor = author;
    }

    void SpringExtensionLibrary::setLibraryVersion(const std::string &version)
    {
        libSpecification.libVersion = version;
    }

    void SpringExtensionLibrary::registerFunction(std::string funcName,
                                                  std::string funcDescription,
                                                  SpringExtensionFunctionType func)
    {
        SpringExtensionFunction thirdPartyFunc(funcName, funcDescription, func);
        exeFunctions.insert(std::make_pair(funcName, thirdPartyFunc));
    }

    SpringLibrarySpecification SpringExtensionLibrary::getSpecification(){
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

    std::string SpringExtensionLibrary::getSpecificationString(){
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

    std::string SpringExtensionLibrary::getLibraryName()
    {
        return libSpecification.libName;
    }

    std::vector<std::string> SpringExtensionLibrary::getRegisteredFunctions(){
        std::vector<std::string> nameList;
        for(auto it = exeFunctions.begin(); it != exeFunctions.end(); it++)
        {
            nameList.push_back(it->first);
        }
        return nameList;
    }

    bool SpringExtensionLibrary::existFunction(std::string funcName){
        auto it = exeFunctions.find(funcName);
        if(it == exeFunctions.end()){
            return false;
        }
        return true;
    }

    std::string SpringExtensionLibrary::getFunctionDescription(std::string funcName){
        auto it = exeFunctions.find(funcName);
        if(it == exeFunctions.end())
            Spring::throwRawException("Undefined function: " + funcName);
        return it->second.funcDescription;
    }

    SpringObjectPtr SpringExtensionLibrary::invoke(std::string funcName, const std::vector<SpringObjectPtr> &args)
    {
        auto it = exeFunctions.find(funcName);
        if(it == exeFunctions.end())
            Spring::throwRawException("Undefined function: " + funcName);
        return it->second.func(args);
    }

/***********************************************************************
SpringExtensionLibrary::SpringExtensionFunction
***********************************************************************/

    SpringExtensionLibrary::SpringExtensionFunction::SpringExtensionFunction():
        funcName(""),
        funcDescription("")
    {}

    SpringExtensionLibrary::SpringExtensionFunction::SpringExtensionFunction(std::string name,
                                                                             std::string description,
                                                                             SpringExtensionFunctionType f):
        funcName(name),
        funcDescription(description),
        func(f)
    {}

}
