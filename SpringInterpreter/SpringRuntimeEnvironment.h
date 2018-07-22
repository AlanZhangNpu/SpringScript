#ifndef SPRINGRUNTIMEENVIRONMENT_H
#define SPRINGRUNTIMEENVIRONMENT_H

#include "SpringRuntimeController.h"
#include "SpringIOHelper.h"

#include "./core/object/SpringSymbolTable.h"
#include "./core/object/SpringObjectManager.h"

namespace spr {

    class SpringIOHelper;
    class SpringRuntimeController;
    class __declspec(dllexport) SpringRuntimeEnvironment
    {
    public:
        SpringRuntimeEnvironment(){}
        ~SpringRuntimeEnvironment(){}

        void init(SpringIOHelper * h = nullptr, SpringRuntimeController *c = nullptr){
            clear();

            ojbManager = new SpringObjectManager();
            symbolTable = new SpringSymbolTable();

            if(h == nullptr){
                springIOHelper = new SpringIOHelper();
                useDefaultIOHelper = true;
            }else{
                springIOHelper = h;
                useDefaultIOHelper = false;
            }

            runtimeController = c;
            if(runtimeController != nullptr){
                runtimeController->setIOHelper(springIOHelper);
            }
        }

        void clear(){
            if(ojbManager != nullptr){
                delete ojbManager;
                ojbManager = nullptr;
            }

            if(symbolTable != nullptr){
                delete symbolTable;
                symbolTable = nullptr;
            }

            if(useDefaultIOHelper){
                if(springIOHelper != nullptr){
                    delete springIOHelper;
                    springIOHelper = nullptr;
                }
            }else
                springIOHelper = nullptr;

            if(runtimeController != nullptr){
                runtimeController->removeIOHelper();
                runtimeController = nullptr;
            }
        }

        SpringObjectManager* ojbManager = nullptr;
        SpringSymbolTable* symbolTable = nullptr;
        SpringIOHelper * springIOHelper = nullptr;
        SpringRuntimeController* runtimeController = nullptr;

    private:
        bool useDefaultIOHelper = true;
    };

}

#endif // SPRINGRUNTIMEENVIRONMENT_H
