#include "SpringKeywords.h"

#include "Spring.h"
#include <ctime>

namespace spr{

    SpringKeywords::SpringKeywords()
    {}

    std::vector<std::string> SpringKeywords::getKeywords()
    {
        std::vector<std::string> keywords;
        keywords.push_back("and");
        keywords.push_back("exec");
        keywords.push_back("not");
        keywords.push_back("assert");
        keywords.push_back("finally");
        keywords.push_back("or");
        keywords.push_back("break");
        keywords.push_back("for");
        keywords.push_back("pass");
        keywords.push_back("class");
        keywords.push_back("from");
        keywords.push_back("print");
        keywords.push_back("continue");
        keywords.push_back("global");
        keywords.push_back("def");
        keywords.push_back("if");
        keywords.push_back("return");
        keywords.push_back("del");
        keywords.push_back("import");
        keywords.push_back("in");
        keywords.push_back("while");
        keywords.push_back("loop");
        keywords.push_back("else");
        keywords.push_back("is");
        keywords.push_back("with ");
        keywords.push_back("lambda");
        keywords.push_back("yield");
        keywords.push_back("nil");
        keywords.push_back("true");
        keywords.push_back("false");

//        auto libList = Spring::runtimeEnvironment.springRuntimeLib.getAllLibraries();
//        for(auto f : libList)
//            keywords.push_back(f);

//        auto funcList = Spring::runtimeEnvironment.springRuntimeLib.getAllFunctions();
//        for(auto f : funcList)
//            keywords.push_back(f);

        return keywords;
    }

    std::string SpringKeywords::getEasterEggsSentences()
    {
        std::vector<std::string> sentences;
        sentences.push_back("集中起来的意志，可以击穿顽石。\nThe focused mind can pierce through stone.");
        sentences.push_back("真正的大师永远都怀着一颗学徒的心。\nA true master is an eternal student.");
        sentences.push_back("我宁愿犯错，也不愿什么都不做。\nI'd rather make mistakes than make nothing at all.");

        srand((unsigned)time(NULL));

        int i = rand()%(sentences.size());
        return sentences[i];
    }

}
