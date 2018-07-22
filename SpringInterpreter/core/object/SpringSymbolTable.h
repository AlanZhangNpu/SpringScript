#ifndef SPRINGSYMBOLTABLE_H
#define SPRINGSYMBOLTABLE_H

#include <map>
#include <vector>
#include <string>

#include "SpringObject.h"

namespace spr {

    class SpringObjectManager;
    class __declspec(dllexport) SpringSymbolTable
    {
    public:
        SpringSymbolTable();
        ~SpringSymbolTable();

        void declare(const std::string &key, const SpringObjectPtr &p);
        void assign(const std::string &key, const SpringObjectPtr &p);
        void entryScope();
        void exitScope();
        void clear();
        void getAllPtrs(std::vector<SpringObjectPtr> &ptrList) const;
        void getAllRelatedPtrs(std::set<SpringObjectPtr> &ptrList) const;
        void print();

        SpringObjectPtr operator[](const std::string &key);
        SpringObjectPtr get(const std::string &key);
        std::map<std::string, SpringObjectPtr> getAll();
        std::vector<std::string> getCurrentScopeSymbols();

        static double time;

    private:
        std::vector<std::map<std::string, SpringObjectPtr>> symbolTable;
    };

}
#endif // SPRINGSYMBOLTABLE_H
