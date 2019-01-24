#include "CharEncoding.h"

#include <iostream>
#include <fstream>
#include <windows.h>

CharEncoding::CharEncoding()
{

}

std::string CharEncoding::UTF8ToGBK(const char *strUTF8)
{
    int len = MultiByteToWideChar(CP_UTF8, 0, strUTF8, -1, NULL, 0);
    wchar_t* wszGBK = new wchar_t[len + 1];
    memset(wszGBK, 0, len * 2 + 2);
    MultiByteToWideChar(CP_UTF8, 0, strUTF8, -1, wszGBK, len);
    len = WideCharToMultiByte(CP_ACP, 0, wszGBK, -1, NULL, 0, NULL, NULL);
    char* szGBK = new char[len + 1];
    memset(szGBK, 0, len + 1);
    WideCharToMultiByte(CP_ACP, 0, wszGBK, -1, szGBK, len, NULL, NULL);
    std::string strTemp(szGBK);

    if (wszGBK) delete[] wszGBK;
    if (szGBK) delete[] szGBK;

    return strTemp;
}

std::string CharEncoding::GBKToUTF8(const char *strGBK)
{
    int len = MultiByteToWideChar(CP_ACP, 0, strGBK, -1, NULL, 0);
    wchar_t* wstr = new wchar_t[len + 1];
    memset(wstr, 0, len + 1);
    MultiByteToWideChar(CP_ACP, 0, strGBK, -1, wstr, len);
    len = WideCharToMultiByte(CP_UTF8, 0, wstr, -1, NULL, 0, NULL, NULL);
    char* str = new char[len + 1];
    memset(str, 0, len + 1);
    WideCharToMultiByte(CP_UTF8, 0, wstr, -1, str, len, NULL, NULL);
    std::string strTemp = str;

    if (wstr) delete[] wstr;
    if (str) delete[] str;

    return strTemp;
}

std::string CharEncoding::GbkToUtf8(const std::string &strGbk)//传入的strGbk是GBK编码
{
    //gbk转unicode
    int len = MultiByteToWideChar(CP_ACP, 0, strGbk.c_str(), -1, NULL, 0);
    wchar_t *strUnicode = new wchar_t[len];
    wmemset(strUnicode, 0, len);
    MultiByteToWideChar(CP_ACP, 0, strGbk.c_str(), -1, strUnicode, len);

    //unicode转UTF-8
    len = WideCharToMultiByte(CP_UTF8, 0, strUnicode, -1, NULL, 0, NULL, NULL);
    char * strUtf8 = new char[len];
    WideCharToMultiByte(CP_UTF8, 0, strUnicode, -1, strUtf8, len, NULL, NULL);

    std::string strTemp(strUtf8);//此时的strTemp是UTF-8编码
    delete[]strUnicode;
    delete[]strUtf8;
    strUnicode = NULL;
    strUtf8 = NULL;
    return strTemp;
}
