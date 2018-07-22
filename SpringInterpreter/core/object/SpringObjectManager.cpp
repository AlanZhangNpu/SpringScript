#include "SpringObjectManager.h"
#include <algorithm>
#include "Spring.h"
#include "SpringStandardType.h"
#include "SpringSymbolTable.h"

namespace spr {

    SpringObjectManager::SpringObjectManager()
    {}

    SpringObjectManager::~SpringObjectManager()
    {
        clear();
    }

    SpringNilPtr SpringObjectManager::create()
    {
        return &sprNil;
    }

    SpringBoolPtr SpringObjectManager::create(const bool &b)
    {
        return b ? &sprTrue : &sprFalse;
    }

    SpringIntPtr SpringObjectManager::create(const unsigned &i)
    {
        auto obj = new SpringInt((int)i);
        objHeap.push_back(obj);
        return obj;
    }

    SpringIntPtr SpringObjectManager::create(const int &i)
    {
        auto obj = new SpringInt(i);
        objHeap.push_back(obj);
        return obj;
    }

    SpringDoublePtr SpringObjectManager::create(const double &d)
    {
        auto obj = new SpringDouble(d);
        objHeap.push_back(obj);
        return obj;
    }

    SpringStringPtr SpringObjectManager::create(const std::string &s)
    {
        auto obj = new SpringString(s);
        objHeap.push_back(obj);
        return obj;
    }

    SpringListPtr SpringObjectManager::create(const std::vector<SpringObjectPtr> &l)
    {
        auto obj = new SpringList(l);
        objHeap.push_back(obj);
        return obj;
    }

    SpringFunctionPtr SpringObjectManager::create(SpringIDListExpression *i, SpringParagraph *b)
    {
        auto obj = new SpringFunction(i, b);
        objHeap.push_back(obj);
        return obj;
    }

    SpringFunctionPtr SpringObjectManager::create(const SpringStandardFunctionType &f, const std::string &d)
    {
        auto obj = new SpringFunction(f, d);
        objHeap.push_back(obj);
        return obj;
    }

    SpringStructPtr SpringObjectManager::create(const std::map<std::string, SpringObjectPtr> &m)
    {
        auto obj = new SpringStruct(m);
        objHeap.push_back(obj);
        return obj;
    }

    SpringStructPtr SpringObjectManager::createEmptyObject()
    {
        std::map<std::string, SpringObjectPtr> m;
        return create(m);
    }

    SpringListPtr SpringObjectManager::createEmptyList()
    {
        std::vector<SpringObjectPtr> l;
        return create(l);
    }

    SpringVoidPointerPtr SpringObjectManager::create(void *p, const std::string &className)
    {
        auto obj = new SpringVoidPointer(p, className);
        objHeap.push_back(obj);
        return obj;
    }

    void SpringObjectManager::push(const SpringObjectPtr &p)
    {
        objHeap.push_back(p);
    }

    void SpringObjectManager::clear()
    {
        if(objHeap.size() == 0)
            return;

        auto iter = objHeap.begin();
        while (iter != objHeap.end()) {
            delete *iter;
            *iter = nullptr;
            iter = objHeap.erase(iter);
        }
    }

    void SpringObjectManager::tempPrintAllObject()
    {
        zzzz "tempPrintAllObject{";
        for(auto i : objHeap)
            zzzz QString::fromStdString(i->getPrintString());
        zzzz "}";
    }

    void SpringObjectManager::tempPrintUsefulObject(std::vector<SpringObjectPtr> u)
    {
        zzzz "tempPrintUsefulObject{";
        for(auto i : u)
            zzzz QString::fromStdString(i->getPrintString());
        zzzz "}";
    }

    int SpringObjectManager::collectGarbage(SpringSymbolTable* symbolTable)
    {
        if(objHeap.size() < 100000)
            return 0;

//        qDebug() <<"垃圾回收" << objHeap.size();

        std::vector<SpringObjectPtr> usefulObjects;
        symbolTable->getAllPtrs(usefulObjects);

        int garbageNum = 0;
        auto iter = objHeap.begin();
        while (iter != objHeap.end()) {
            auto findResult = std::find(usefulObjects.begin(), usefulObjects.end(), *iter);
            if(findResult != usefulObjects.end()){
                iter++;
            }else{
                auto findResult2 = std::find(returnValueStack.begin(), returnValueStack.end(), *iter);
                if(findResult2 != returnValueStack.end()){
                    iter++;
                }else{
                    delete *iter;
                    *iter = nullptr;
                    iter = objHeap.erase(iter);
                    garbageNum++;
                }
            }
        }
//        qDebug()<<"删除：" << garbageNum << objHeap.size();
        return garbageNum;
    }

    int SpringObjectManager::collectGarbage2(const std::set<SpringObjectPtr> &usefulObjects)
    {
//        if(objHeap.size() < 500)
//            return 0;

        int garbageNum = 0;
        auto iter = objHeap.begin();
        while (iter != objHeap.end()) {
            if(usefulObjects.count(*iter) != 0){
                iter++;
                continue;
            }

            auto findResult2 = std::find(returnValueStack.begin(), returnValueStack.end(), *iter);
            if(findResult2 != returnValueStack.end()){
                iter++;
            }else{
                delete *iter;
                *iter = nullptr;
                iter = objHeap.erase(iter);
                garbageNum++;
            }
        }
        return garbageNum;
    }

    void SpringObjectManager::pushReturnValue(const SpringObjectPtr &r)
    {
        returnValueStack.push_back(r);
    }

    SpringObjectPtr SpringObjectManager::popReturnValue()
    {
        auto iter = returnValueStack.end();
        iter--;
        SpringObjectPtr r = *iter;
        returnValueStack.pop_back();
        return r;
    }

}
