#include "SpringLibraryLoader.h"
#include "SpringStandardFunction.h"
#include "./core/object/SpringStandardType.h"
#include "./core/object/SpringSymbolTable.h"

namespace spr {

    SpringLibraryLoader::SpringLibraryLoader()
    {}

    void SpringLibraryLoader::loadBasicLib(SpringRuntimeEnvironment &env)
    {
        env.symbolTable->declare("ref", env.ojbManager->create(refCount, ""));
        env.symbolTable->declare("print", env.ojbManager->create(print, ""));
        env.symbolTable->declare("input", env.ojbManager->create(input, ""));
        env.symbolTable->declare("clear", env.ojbManager->create(clear, ""));
        env.symbolTable->declare("clearall", env.ojbManager->create(clearall, ""));
        env.symbolTable->declare("type", env.ojbManager->create(type, ""));
        env.symbolTable->declare("import", env.ojbManager->create(import, ""));
        env.symbolTable->declare("why", env.ojbManager->create(easterEgg, ""));
    }

    void SpringLibraryLoader::loadStandardLib(const std::string &libName, SpringRuntimeEnvironment &env)
    {
        if(libName == "string")
        {
            auto obj = env.ojbManager->createEmptyObject();
            obj->addMember("lower", env.ojbManager->create(string_lower, ""));
            obj->addMember("upper", env.ojbManager->create(string_upper, ""));
            obj->addMember("find", env.ojbManager->create(string_find, ""));
            obj->addMember("substr", env.ojbManager->create(string_sub, ""));
            obj->addMember("format", env.ojbManager->create(string_format, ""));
            env.symbolTable->declare(libName, obj);

        }else if(libName == "os")
        {
            auto obj = env.ojbManager->createEmptyObject();
            obj->addMember("clock", env.ojbManager->create(os_clock, ""));
            obj->addMember("time", env.ojbManager->create(os_time, ""));
            obj->addMember("getenv", env.ojbManager->create(os_getenv, ""));
            obj->addMember("system", env.ojbManager->create(os_system, ""));
            env.symbolTable->declare(libName, obj);

        }else if(libName == "list")
        {
            auto obj = env.ojbManager->createEmptyObject();
            obj->addMember("sort", env.ojbManager->create(list_sort, ""));
            env.symbolTable->declare(libName, obj);

        }else if(libName == "math")
        {
            auto obj = env.ojbManager->createEmptyObject();
            obj->addMember("randu", env.ojbManager->create(math_randu, ""));
            obj->addMember("range", env.ojbManager->create(math_range, ""));

            env.symbolTable->declare(libName, obj);

        }else{
            loadExtensionLib(libName, env);
        }
    }

    void SpringLibraryLoader::loadExtensionLib(const std::string &libPath, SpringRuntimeEnvironment &)
    {
        throw std::runtime_error("Undefined library name: " +libPath);
    }

}
