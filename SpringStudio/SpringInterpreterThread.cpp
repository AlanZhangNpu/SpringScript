#include "SpringInterpreterThread.h"
#include <time.h>
#include <fstream>
#include <iostream>
#include <QWidget>
#include <QMetaType>
#include <QDebug>

using namespace spr;

SpringInterpreterThread::SpringInterpreterThread(QWidget *widgetPointer, QString f, spr::Spring *s):
    pointer(widgetPointer),
    codeFile(f),
    springInterpreter(s)
{
    setAutoDelete(true);

    qRegisterMetaType<std::string>("std::string");
    qRegisterMetaType<std::vector<std::string>>("std::deque<std::string>");
}

SpringInterpreterThread::~SpringInterpreterThread()
{

}

void SpringInterpreterThread::run()
{
    int i=0;
    while (i++ < 1) {
        springInterpreter->interprete(codeFile.toStdString().c_str());
        springInterpreter->clear();
        delete springInterpreter;
    }
    onFinish();
}

void SpringInterpreterThread::onPause(int lineno)
{
    QMetaObject::invokeMethod(pointer,"onPause",
                              Qt::BlockingQueuedConnection, Q_ARG(int, lineno));
}

void SpringInterpreterThread::onStop(int lineno)
{
    QMetaObject::invokeMethod(pointer,"onStop",
                              Qt::BlockingQueuedConnection, Q_ARG(int, lineno));
}

void SpringInterpreterThread::onFinish()
{
    QMetaObject::invokeMethod(pointer,"onFinish",
                              Qt::AutoConnection);
}

void SpringInterpreterThread::onError(int lineno, std::string msg)
{
    QMetaObject::invokeMethod(pointer,"onError",
                              Qt::BlockingQueuedConnection,
                              Q_ARG(int, lineno),
                              Q_ARG(std::string, msg));
}

void SpringInterpreterThread::print(std::string msg)
{
    QString qMsg = QString::fromStdString(msg);
    QMetaObject::invokeMethod(pointer,"onPrint",
                              Qt::BlockingQueuedConnection, Q_ARG(QString, qMsg));
}

void SpringInterpreterThread::clearOutput()
{
    QMetaObject::invokeMethod(pointer,"onClearOutput",
                              Qt::AutoConnection);
}

std::string SpringInterpreterThread::input(std::string tip)
{
    std::string inputStr = "";
    QMetaObject::invokeMethod(pointer,"input",
                              Qt::BlockingQueuedConnection,
                              Q_ARG(std::string, tip),
                              Q_ARG(std::string&, inputStr)
                              );
    return inputStr;
}
