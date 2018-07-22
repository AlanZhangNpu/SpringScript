#include "SpringSymbolTable.h"
#include <ctype.h>
#include <time.h>

#include "Spring.h"
#include "./core/object/SpringObjectManager.h"

namespace spr {

    double SpringSymbolTable::time = 0;

    SpringSymbolTable::SpringSymbolTable()
    {
        entryScope();
    }

    SpringSymbolTable::~SpringSymbolTable()
    {
        clear();
    }

    void SpringSymbolTable::declare(const std::string &key, const SpringObjectPtr &p)
    {
        double c = (double)(clock())/(double)CLK_TCK;////////////**************

        auto iter = symbolTable.rbegin();
        if(iter->count(key) != 0)
            Spring::throwRawException("Variable redefinition: " + key);

        iter->insert(std::make_pair(key, p));

        time += (double)(clock())/(double)CLK_TCK - c;////////////**************
    }

    void SpringSymbolTable::assign(const std::string &key, const spr::SpringObjectPtr &p)
    {
        double c = (double)(clock())/(double)CLK_TCK;////////////**************

        for(auto iter = symbolTable.rbegin(); iter != symbolTable.rend(); iter++){

            auto mapIter = iter->find(key);
            if(mapIter != iter->end()){
                if(std::isupper(key[0]))
                    Spring::throwRawException("A constant cannot be changed after initialization.");
                mapIter->second = p;

                time += (double)(clock())/(double)CLK_TCK - c;////////////**************
                return;
            }
        }
        Spring::throwRawException("Undefined symbol: " + key);
    }

    void SpringSymbolTable::clear()
    {
        time = 0;
        symbolTable.clear();
        entryScope();
    }

    SpringObjectPtr SpringSymbolTable::operator[](const std::string &key)
    {
        return get(key);
    }

    SpringObjectPtr SpringSymbolTable::get(const std::string &key)
    {
        for(auto iter = symbolTable.rbegin(); iter != symbolTable.rend(); iter++){
            auto mapIter = iter->find(key);
            if(mapIter != iter->end())
                return mapIter->second;
        }
        Spring::throwRuntimeError("Undefined variable " + key);
        return nullptr;
    }

    std::map<std::string, SpringObjectPtr> SpringSymbolTable::getAll()
    {
        std::map<std::string, SpringObjectPtr> allSymbols;
        for(auto iter = symbolTable.rbegin(); iter != symbolTable.rend(); iter++)
            for(auto sym : *iter)
                allSymbols.insert(std::make_pair(sym.first, sym.second));
        return allSymbols;
    }

//    bool SpringSymbolTable::exist(const std::string &key)
//    {
//        double c = (double)(clock())/(double)CLK_TCK;////////////**************
//        int cnt = symbols.count(key);
//        time += (double)(clock())/(double)CLK_TCK - c;////////////**************
//        return cnt != 0;
//    }

    void SpringSymbolTable::entryScope()
    {
        symbolTable.push_back({});
    }

    void SpringSymbolTable::exitScope()
    {
        double c = (double)(clock())/(double)CLK_TCK;

        auto iter = symbolTable.end();
        iter--;
        symbolTable.erase(iter);

        time += (double)(clock())/(double)CLK_TCK - c;
    }

    std::vector<std::string> SpringSymbolTable::getCurrentScopeSymbols()
    {
        double c = (double)(clock())/(double)CLK_TCK;////////////**************

        std::vector<std::string> symbolList;

        auto iter = symbolTable.rbegin();
        for(auto sym : *iter)
            symbolList.push_back(sym.first);

        time += (double)(clock())/(double)CLK_TCK - c;////////////**************

        return symbolList;
    }

    void SpringSymbolTable::getAllPtrs(std::vector<SpringObjectPtr> &ptrList) const
    {
        for(auto iter = symbolTable.rbegin(); iter != symbolTable.rend(); iter++){
            for(auto sym : *iter){
                sym.second->getPtr(ptrList);
            }
        }
    }

    void SpringSymbolTable::getAllRelatedPtrs(std::set<SpringObjectPtr> &ptrList) const
    {
        for(auto iter = symbolTable.rbegin(); iter != symbolTable.rend(); iter++){
            for(auto sym : *iter){
                sym.second->getRelatedPtr(ptrList);
            }
        }
    }

    void SpringSymbolTable::print()
    {
        for(auto iter = symbolTable.rbegin(); iter != symbolTable.rend(); iter++){
            for(auto sym : *iter){
                zzzz QString::fromStdString(sym.first);
                zzzz QString::fromStdString(sym.second->getPrintString());
            }
        }
    }

}
