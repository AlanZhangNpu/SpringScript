#include "SpringStandardFunction.h"

#include <time.h>

#include "SpringIOHelper.h"
#include "Spring.h"
#include "SpringLibraryLoader.h"

namespace spr {

/***********************************************************************
BASIC
***********************************************************************/

    SpringObjectPtr refCount(const std::vector<SpringObjectPtr> &args, SpringRuntimeEnvironment &env)
    {
//        if(args.size() != 1)
//            Spring::throwRawException("refCount函数只接受一个参数");

//        SpringObjectPtr p = args[0];
//        if(!p->isString())
//            Spring::throwRawException("refCount函数只接受一个字符串类型的参数");

//        std::string symbol = p->toString();
//        int n = env.springSymbolTable.refCount(symbol);
//        env.springIOHelper->print(std::to_string(n));
//        return env.ojbManager.create(n);
        return env.ojbManager->create();
    }

    SpringObjectPtr print(const std::vector<SpringObjectPtr> &args, SpringRuntimeEnvironment &env)
    {
        if(args.size() == 0){
            // print the entire Symbol table
            auto symbols = env.symbolTable->getAll();
            std::string output = "";
            for (auto sym : symbols)
            {
                output += sym.first;
                output += "		";
                output += sym.second->getTypeString();
                output += "		";
                output += sym.second->getPrintString();
                output += "\n";
            }
            env.springIOHelper->print(output);
        }else{
            std::string output = "";
            for(auto c : args)
                output += c->getPrintString() + " ";
            output = output.substr(0, output.length() - 1);
            env.springIOHelper->print(output);
        }
        return env.ojbManager->create();
    }

    SpringObjectPtr input(const std::vector<SpringObjectPtr> &args, SpringRuntimeEnvironment &env)
    {

        return env.ojbManager->create();
    }

    SpringObjectPtr clear(const std::vector<SpringObjectPtr> &args, SpringRuntimeEnvironment &env)
    {
        env.springIOHelper->clearOutput();
        return env.ojbManager->create();
    }

    SpringObjectPtr clearall(const std::vector<SpringObjectPtr> &args, SpringRuntimeEnvironment &env)
    {

        return env.ojbManager->create();
    }

    SpringObjectPtr type(const std::vector<SpringObjectPtr> &args, SpringRuntimeEnvironment &env)
    {

        return env.ojbManager->create();
    }

    SpringObjectPtr import(const std::vector<SpringObjectPtr> &args, SpringRuntimeEnvironment &env)
    {
        if(args.size() > 1)
            throw std::runtime_error("Too many arguments");
        if(args.size() < 1)
            throw std::runtime_error("Too few arguments");

        auto arg = args[0];
        if(!arg->isString())
            throw std::runtime_error("import函数包含一个字符串类型的参数");
        std::string libName = arg->toString();
        SpringLibraryLoader::loadStandardLib(libName, env);
        return env.ojbManager->create();
    }

    SpringObjectPtr easterEgg(const std::vector<SpringObjectPtr> &, SpringRuntimeEnvironment &env)
    {
        env.springIOHelper->print(SpringKeywords::getEasterEggsSentences());
        return env.ojbManager->create();
    }

    /***********************************************************************
    OS
    ***********************************************************************/

    SpringObjectPtr os_clock(const std::vector<SpringObjectPtr> &, SpringRuntimeEnvironment &env)
    {
        double c = (double)(clock())/(double)CLK_TCK;
        return env.ojbManager->create(c);
    }

    SpringObjectPtr os_time(const std::vector<SpringObjectPtr> &, SpringRuntimeEnvironment &env)
    {
        Spring::throwRawException("TODO: os_time()");
        return env.ojbManager->create();
    }

    SpringObjectPtr os_getenv(const std::vector<SpringObjectPtr> &args, SpringRuntimeEnvironment &env)
    {
        Spring::throwRawException("TODO: os_getenv()");
        return env.ojbManager->create();
    }

    SpringObjectPtr os_system(const std::vector<SpringObjectPtr> &args, SpringRuntimeEnvironment &env)
    {
        if(args.size() != 1)
            Spring::throwRawException("system函数接收1个字符串类型参数，即命令字符串");

        SpringObjectPtr a = args[0];
        if(!a->isString())
            Spring::throwRawException("system函数的参数必须为字符串类型");

        int code = system(a->toString().data());
        return env.ojbManager->create(code);
    }

    /***********************************************************************
    STRING
    ***********************************************************************/

    SpringObjectPtr string_lower(const std::vector<SpringObjectPtr> &args, SpringRuntimeEnvironment &env)
    {

        return env.ojbManager->create();
    }

    SpringObjectPtr string_upper(const std::vector<SpringObjectPtr> &args, SpringRuntimeEnvironment &env)
    {

        return env.ojbManager->create();
    }

    SpringObjectPtr string_find(const std::vector<SpringObjectPtr> &args, SpringRuntimeEnvironment &env)
    {

        return env.ojbManager->create();
    }

    SpringObjectPtr string_sub(const std::vector<SpringObjectPtr> &args, SpringRuntimeEnvironment &env)
    {

        return env.ojbManager->create();
    }

    SpringObjectPtr string_format(const std::vector<SpringObjectPtr> &args, SpringRuntimeEnvironment &env)
    {

        return env.ojbManager->create();
    }

/***********************************************************************
LIST
***********************************************************************/

    SpringObjectPtr list_sort(const std::vector<SpringObjectPtr> &args, SpringRuntimeEnvironment &env)
    {

        return env.ojbManager->create();
    }

/***********************************************************************
MATH
***********************************************************************/

    SpringObjectPtr math_randu(const std::vector<SpringObjectPtr> &args, SpringRuntimeEnvironment &env)
    {

        return env.ojbManager->create();
    }

}
