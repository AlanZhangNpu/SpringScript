#ifndef SPRINGLIBINFORMATION_H
#define SPRINGLIBINFORMATION_H
#include <string>
#include <vector>


namespace spr{

class __declspec(dllexport) SpringLibrarySpecification
{
public:
    SpringLibrarySpecification(){}

    class SpringFunctionInformation{
    public:
        SpringFunctionInformation(){}
        std::string funcName;
        std::string funcDescription;
    };

    std::string libName = "";
    std::string libDescription;
    std::string libVersion;
    std::string libAuthor;

    std::vector<SpringFunctionInformation> functions;

    std::string toString(){
        std::string specification;
        specification += "Library name: " + libName;
        specification += "\nLibrary description: " + libDescription;
        specification += "\nLibrary author: " + libAuthor;
        specification += "\nLibrary version: " + libVersion;
        specification += "\nLibrary functions: ("+ std::to_string(functions.size()) +")\n";

        for(auto f : functions){
            specification += "   " + f.funcName + ": " + f.funcDescription + "\n";
        }

        specification += "\n";
        return specification;
    }
};
}

#endif // SPRINGLIBINFORMATION_H
