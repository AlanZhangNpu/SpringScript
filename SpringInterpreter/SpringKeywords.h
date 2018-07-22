#ifndef SPRINGKEYWORDS_H
#define SPRINGKEYWORDS_H

#include <vector>
#include <string>

namespace spr{

    class __declspec(dllexport) SpringKeywords
    {
    public:
        SpringKeywords();
        static std::vector<std::string> getKeywords();
        static std::string getEasterEggsSentences();
    };

}

#endif // SPRINGKEYWORDS_H
