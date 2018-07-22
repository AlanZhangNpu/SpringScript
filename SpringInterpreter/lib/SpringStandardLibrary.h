#ifndef SPRINGSTANDARDLIB_H
#define SPRINGSTANDARDLIB_H
#include <map>
#include <vector>
#include <functional>

#include "SpringLibrarySpecification.h"
#include "./core/object/SpringObject.h"

namespace spr{

    class SpringRuntimeEnvironment;

    typedef std::function<SpringObjectPtr(const std::vector<SpringObjectPtr> &, SpringRuntimeEnvironment &)> SpringStandardLibraryFunctionType;

    class SpringStandardLibrary
    {
    public:
        class SpringStandardLibraryFunction{
        public:
            SpringStandardLibraryFunction();
            SpringStandardLibraryFunction(std::string name,
                                          std::string description,
                                          SpringStandardLibraryFunctionType f);
            SpringStandardLibraryFunction(std::string name,
                                          std::string description,
                                          std::function<SpringObjectPtr(const std::vector<SpringObjectPtr> &)> f);
            SpringStandardLibraryFunction(std::string name,
                                          std::string description,
                                          std::function<void(SpringRuntimeEnvironment &)> f);
            SpringStandardLibraryFunction(std::string name,
                                          std::string description,
                                          std::function<SpringObjectPtr()> f);
            std::string funcName;
            std::string funcDescription;
            SpringStandardLibraryFunctionType func;
        };

        SpringStandardLibrary(std::string name = "Spring",
                              std::string description = "",
                              std::string author = "",
                              std::string version = "");
        void setLibraryName(const std::string &name);
        void setLibraryDescription(const std::string &description);
        void setLibraryAuthor(const std::string &author);
        void setLibraryVersion(const std::string &version);
        std::string getLibraryName();
        SpringLibrarySpecification getSpecification();
        std::string getSpecificationString();
        void registerFunction(SpringStandardLibraryFunction standardFunction);
        void registerFunction(std::string funcName, std::string funcDescription, SpringStandardLibraryFunctionType f);
        std::vector<std::string> getRegisteredFunctions();
        bool existFunction(std::string funcName);
        std::string getFunctionDescription(std::string funcName);
        SpringObjectPtr invoke(std::string funcName,
                           const std::vector<SpringObjectPtr> & args,
                           SpringRuntimeEnvironment &runtimeEnvironment);
    private:
        SpringLibrarySpecification libSpecification;
        std::map<std::string, SpringStandardLibraryFunction> exeFunctions;
    };

}

#endif // SPRINGSTANDARDLIB_H
