#include "mainwindow.h"
#include <QApplication>
#include <QDebug>
#include <iostream>
#include <fstream>
#include <functional>

//// 下面两行是为了检查内存泄漏
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>

int main(int argc, char *argv[])
{
    // 下面一行是为了检查内存泄漏
//    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
//    char *str = (char *)malloc(sizeof(char) * 10);

    QApplication a(argc, argv);

    QFont font = a.font();
    font.setFamily("微软雅黑");
    a.setFont(font);

    MainWindow mainWindow;
    mainWindow.showMaximized();

    return a.exec();
}
