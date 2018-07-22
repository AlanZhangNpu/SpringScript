//#ifndef SPRINGRUNTIMELIB_H
//#define SPRINGRUNTIMELIB_H

//#include <vector>

//#include "SpringStandardLibrary.h"
//#include "SpringExtensionLibrary.h"
//#include "SpringLibrarySpecification.h"

//namespace spr{

//    class __declspec(dllexport) SpringRuntimeLibrary
//    {
//    public:
//        SpringRuntimeLibrary();

//        static std::string getExternLibrarySpecification(std::string libPath,
//                                                         SpringLibrarySpecification &specification);
//        void addExtensionLibrary(std::string libPath);
//        void clearupRuntimeLibraries();
//        SpringLibrarySpecification getLibrarySpecification(std::string libName);
//        std::string getLibrarySpecificationString(std::string libName);
//        bool existLibrary(std::string libName);
//        std::vector<std::string> getAllLibraries();
//        bool existFunction(std::string funcName);
//        std::vector<std::string> getAllFunctions();
//        SpringObjectPtr invoke(std::string funcName,
//                           const std::vector<SpringObjectPtr> & args,
//                           SpringRuntimeEnvironment &runtimeEnvironment);
//        std::string getFunctionDescription(const std::string &funcName);

//    private:
//        SpringStandardLibrary standardLib;
//        std::vector<SpringExtensionLibrary> extensionLibs;
//    };

//}

//#endif // SPRINGRUNTIMELIB_H
