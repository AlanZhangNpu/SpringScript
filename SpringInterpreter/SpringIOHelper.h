#ifndef SPRINGIOHELPER_H
#define SPRINGIOHELPER_H

#include <string>
#include <vector>
#include <iostream>

namespace spr{

    class __declspec(dllexport) SpringIOHelper
    {
    public:
        SpringIOHelper(){}
        virtual ~SpringIOHelper(){}

        virtual void print(const std::string &msg){
            printf("%s\n", msg.c_str());
        }

        virtual std::string input(const std::string &tip = ""){
            this->print(tip);
            std::string s = "";
            std::cin >> s;
//            scanf("%s", &s);
            return s;
        }

        virtual void clearOutput(){}

        virtual void onError(int lineno, std::string msg){
            this->print("Error in Line" + std::to_string(lineno) + ": " + msg);
        }

        virtual void onFinish(){
            this->print("finish");
        }

        virtual void onPause(int lineno){
            this->print("Suspended on Line" + std::to_string(lineno));
        }

        virtual void onStop(int lineno){
            this->print("Stopped on Line" + std::to_string(lineno));
        }
    };

}

#endif // SPRINGIOHELPER_H
