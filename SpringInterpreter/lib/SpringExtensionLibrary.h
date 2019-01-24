#ifndef SPRINGTHIRDPARTYLIB_H
#define SPRINGTHIRDPARTYLIB_H
#include <map>
#include <memory>
#include <functional>
#include <vector>

#include "SpringLibrarySpecification.h"
#include "./core/object/SpringObject.h"

namespace spr {

    using SpringExtensionFunctionType = std::function<SpringObjectPtr(const std::vector<SpringObjectPtr> &)>;

    class __declspec(dllexport) SpringExtensionLibrary
    {
    public:
        SpringExtensionLibrary(std::string name,
                      std::string description = "",
                      std::string author = "",
                      std::string version = "");
        void setLibraryName(const std::string &name);
        void setLibraryDescription(const std::string &description);
        void setLibraryAuthor(const std::string &author);
        void setLibraryVersion(const std::string &version);
        void registerFunction(std::string funcName, std::string funcDescription, SpringExtensionFunctionType func);
        SpringLibrarySpecification getSpecification();
        std::string getSpecificationString();
        std::string getLibraryName();
        std::vector<std::string> getRegisteredFunctions();
        std::string getFunctionDescription(std::string funcName);
        bool existFunction(std::string funcName);
        SpringObjectPtr invoke(std::string funcName, const std::vector<SpringObjectPtr> & args);

    private:
        class SpringExtensionFunction{
        public:
            SpringExtensionFunction();
            SpringExtensionFunction(std::string name, std::string description, SpringExtensionFunctionType f);
            std::string funcName;
            std::string funcDescription;
            SpringExtensionFunctionType func;
        };

        SpringLibrarySpecification libSpecification;
        std::map<std::string, SpringExtensionFunction> exeFunctions;
    };

}

#endif // SPRINGTHIRDPARTYLIB_H
