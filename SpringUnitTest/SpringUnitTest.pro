#-------------------------------------------------
#
# Project created by QtCreator 2018-05-03T14:38:44
#
#-------------------------------------------------

QT       += testlib

QT       -= gui

TARGET = tst_springunittesttest
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        tst_springunittesttest.cpp   

DEFINES += SRCDIR=\\\"$$PWD/\\\"

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../SpringInterpreter/release/ -lSpringInterpreter
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../SpringInterpreter/debug/ -lSpringInterpreter
else:unix: LIBS += -L$$OUT_PWD/../SpringInterpreter/ -lSpringInterpreter

INCLUDEPATH += $$PWD/../SpringInterpreter
DEPENDPATH += $$PWD/../SpringInterpreter

HEADERS +=

INCLUDEPATH+= ../arma\include
LIBS += -L../arma\lib_win64\blas.lib
        -L../arma\lib_win64\lapack.lib
        -L../arma\lib_win64\libf2c.lib
