#-------------------------------------------------
#
# Project created by QtCreator 2018-05-03T12:07:58
#
#-------------------------------------------------

QT       -= core gui
QT       += core

TARGET = SpringInterpreter
TEMPLATE = lib

DEFINES += SPRINGINTERPRETER_LIBRARY

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += Spring.cpp \
    SpringRuntimeController.cpp \
    SpringKeywords.cpp \
    SpringException.cpp \
    core/expression/SpringBaseExpression.cpp \
    core/expression/SpringExpression.cpp \
    core/expression/SpringExpressionList.cpp \
    core/statement/SpringBaseStatement.cpp \
    core/statement/SpringStatement.cpp \
    core/statement/SpringParagraph.cpp \
    core/object/SpringObjectManager.cpp \
    core/object/SpringObject.cpp \
    core/object/SpringStandardType.cpp \
    core/object/SpringSymbolTable.cpp \
    core/parser/Exa1.tab.cc \
    core/parser/lex.Exa1.cc \
    lib/SpringExtensionLibrary.cpp \
    lib/SpringRuntimeLibrary.cpp \
    lib/SpringStandardLibrary.cpp \
    lib/SpringStandardLibraryBuilder.cpp \
    lib/SpringStandardFunction.cpp \
    lib/SpringLibraryLoader.cpp \
    SpringInterpreter.cpp

unix {
    target.path = /usr/lib
    INSTALLS += target
}

CONFIG += c++11
INCLUDEPATH += ./core/parser/includepath
LIBS += -L./core/parser/lib/libfl.a

INCLUDEPATH+= ../arma\include
LIBS += -L../arma\lib_win64\blas.lib
        -L../arma\lib_win64\lapack.lib
        -L../arma\lib_win64\libf2c.lib

HEADERS += \
    Spring.h \
    SpringRuntimeEnvironment.h \
    SpringRuntimeController.h \
    SpringKeywords.h \
    SpringIOHelper.h \
    SpringException.h \
    core/expression/SpringBaseExpression.h \
    core/expression/SpringExpression.h \
    core/expression/SpringExpressionList.h \
    core/statement/SpringBaseStatement.h \
    core/statement/SpringStatement.h \
    core/statement/SpringParagraph.h \
    core/object/SpringObjectManager.h \
    core/object/SpringObject.h \
    core/object/SpringStandardType.h \
    core/object/SpringSymbolTable.h \
    core/parser/Exa1.tab.hh \
    core/parser/Exa1Scanner.h \
    core/parser/FlexLexer.h \
    core/parser/location.hh \
    core/parser/position.hh \
    core/parser/stack.hh \
    lib/SpringExtensionLibrary.h \
    lib/SpringLibrarySpecification.h \
    lib/SpringRuntimeLibrary.h \
    lib/SpringStandardLibrary.h \
    lib/SpringStandardLibraryBuilder.h \
    lib/SpringStandardFunction.h \
    lib/SpringLibraryLoader.h \
    SpringInterpreter.h
