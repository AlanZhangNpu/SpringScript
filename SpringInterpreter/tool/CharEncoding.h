#ifndef CHARENCODING_H
#define CHARENCODING_H

#include <string>

class CharEncoding
{
public:
    CharEncoding();

    /*
    UTF-8 转 GBK
    */
    static std::string UTF8ToGBK(const char* strUTF8);


    /*
    GBK 转 UTF-8
    */
    static std::string GBKToUTF8(const char* strGBK);

    //gbk转UTF-8
    static std::string GbkToUtf8(const std::string& strGbk);

};

#endif // CHARENCODING_H
