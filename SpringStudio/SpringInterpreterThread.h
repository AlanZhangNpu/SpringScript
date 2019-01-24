#ifndef SPRINGINTERPRETERTHREAD_H
#define SPRINGINTERPRETERTHREAD_H

#include <QRunnable>
#include <QString>

#include "Spring.h"

class QWidget;

class SpringInterpreterThread : public QRunnable, public spr::SpringIOHelper
{
public:
    SpringInterpreterThread(QWidget *widgetPointer, QString f, spr::Spring *s);
    ~SpringInterpreterThread();

protected:
    void run();

    void print(const std::string &msg);
    std::string input(const std::string &tip = "");
    void clearOutput();
    void onError(int lineno, std::string msg);
    void onFinish();
    void onPause(int lineno);
    void onStop(int lineno);

private:
    QWidget *pointer;
    QString codeFile;
    spr::Spring *springInterpreter;
};

#endif // SPRINGINTERPRETERTHREAD_H
