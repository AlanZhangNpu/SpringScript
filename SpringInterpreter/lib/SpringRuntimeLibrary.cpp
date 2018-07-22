//#include "SpringRuntimeLibrary.h"

//#include <windows.h>

//#include "Spring.h"
//#include "SpringStandardLibraryBuilder.h"

//namespace spr{

//    SpringRuntimeLibrary::SpringRuntimeLibrary()
//    {
//        SpringStandardLibraryBuilder builder;
//        standardLib = builder.build();
//    }

//    std::string SpringRuntimeLibrary::getExternLibrarySpecification(std::string libPath, SpringLibrarySpecification &specification)
//    {
//        std::string funcName = "getSpringThirdPartyLib";

//        typedef SpringExtensionLibrary (*FuncType)(void);
//        HMODULE handle = LoadLibraryA(libPath.data());
//        if(handle == NULL)
//            return "加载Spring第三方库失败,请检查dll文件是否存在，或是否正被使用。\n" + libPath;

//        FuncType proc = (FuncType)(GetProcAddress(handle, funcName.data()));
//        if(proc == NULL)
//            return "加载Spring第三方库失败: \n\"" + libPath + "\"不是标准的Spring第三方库";

//        SpringExtensionLibrary springLib = proc();
//        specification = springLib.getSpecification();
//        return "";
//    }

//    void SpringRuntimeLibrary::addExtensionLibrary(std::string libPath)
//    {
//        std::string funcName = "getSpringThirdPartyLib";

//        typedef SpringExtensionLibrary (*FuncType)(void);
//        HMODULE handle = LoadLibraryA(libPath.data());
//        if(handle == NULL)
//            Spring::throwRawException("加载Spring第三方库失败,请检查dll文件是否存在，或是否正被使用。(" + libPath + ")");

//        FuncType proc = (FuncType)(GetProcAddress(handle, funcName.data()));
//        if(proc == NULL)
//            Spring::throwRawException("加载Spring第三方库失败: \n\"" + libPath + "\"不是标准的Spring第三方库");

//        SpringExtensionLibrary springLib = proc();
//        extensionLibs.push_back(springLib);
//    //    FreeLibrary(handle);
//    }

//    void SpringRuntimeLibrary::clearupRuntimeLibraries()
//    {
//        extensionLibs.clear();
//    }

//    std::string SpringRuntimeLibrary::getLibrarySpecificationString(std::string libName)
//    {
//        if(libName == standardLib.getLibraryName())
//            return standardLib.getSpecificationString();
//        for(auto lib : extensionLibs){
//            if(lib.getLibraryName() == libName)
//                return lib.getSpecificationString();
//        }
//        Spring::throwRawException("Unknown library: " + libName);
//        return "";
//    }

//    SpringLibrarySpecification SpringRuntimeLibrary::getLibrarySpecification(std::string libName)
//    {
//        if(libName == standardLib.getLibraryName())
//            return standardLib.getSpecification();
//        for(auto lib : extensionLibs){
//            if(lib.getLibraryName() == libName)
//                return lib.getSpecification();
//        }
//        Spring::throwRawException("Unknown library: " + libName);
//        return SpringLibrarySpecification();
//    }

//    bool SpringRuntimeLibrary::existLibrary(std::string libName)
//    {
//        if(libName == standardLib.getLibraryName())
//            return true;
//        for(auto lib : extensionLibs){
//            if(lib.getLibraryName() == libName)
//                return true;
//        }
//        return false;
//    }

//    SpringObjectPtr SpringRuntimeLibrary::invoke(std::string funcName,
//                                             const std::vector<SpringObjectPtr> &args,
//                                             SpringRuntimeEnvironment &runtimeEnvironment)
//    {
//        if(standardLib.existFunction(funcName))
//            return standardLib.invoke(funcName, args, runtimeEnvironment);

//        for(auto lib : extensionLibs){
//            if(lib.existFunction(funcName))
//                return lib.invoke(funcName, args);
//        }
//        Spring::throwRawException("Undefined function: " + funcName);
//        return SPR_BUILD_PTR();
//    }

//    std::string SpringRuntimeLibrary::getFunctionDescription(const std::string &funcName)
//    {
//        if(standardLib.existFunction(funcName))
//            return standardLib.getFunctionDescription(funcName);
//        for(auto lib : extensionLibs){
//            if(lib.existFunction(funcName))
//                return lib.getFunctionDescription(funcName);
//        }
//        Spring::throwRawException("Undefined function: " + funcName);
//        return "";
//    }

//    std::vector<std::string> SpringRuntimeLibrary::getAllLibraries()
//    {
//        std::vector<std::string> libNames;
//        libNames.push_back(standardLib.getLibraryName());
//        for(auto lib : extensionLibs)
//            libNames.push_back(lib.getLibraryName());
//        return libNames;
//    }

//    bool SpringRuntimeLibrary::existFunction(std::string funcName)
//    {
//        if(standardLib.existFunction(funcName))
//            return true;
//        for(auto lib : extensionLibs)
//            if(lib.existFunction(funcName))
//                return true;
//        return false;
//    }

//    std::vector<std::string> SpringRuntimeLibrary::getAllFunctions()
//    {
//        std::vector<std::string> funcList = standardLib.getRegisteredFunctions();
//        for(auto lib : extensionLibs){
//            auto fs = lib.getRegisteredFunctions();
//            for(auto f : fs)
//                funcList.push_back(f);
//        }
//        return funcList;
//    }

//}
