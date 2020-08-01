#-------------------------------------------------
#
# Project created by QtCreator 2018-05-03T12:06:06
#
#-------------------------------------------------

QT       += core gui charts network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SpringStudio
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
        main.cpp \
        mainwindow.cpp \
    SpringInterpreterThread.cpp \
    utils/FileUtils.cpp \
    SpringLibrarySpecificationForm.cpp \
    view/InputDialog.cpp \
    WorkspaceView.cpp \
    utils/email/emailaddress.cpp \
    utils/email/EmailHelper.cpp \
    utils/email/mimeattachment.cpp \
    utils/email/mimecontentformatter.cpp \
    utils/email/mimefile.cpp \
    utils/email/mimehtml.cpp \
    utils/email/mimeinlinefile.cpp \
    utils/email/mimemessage.cpp \
    utils/email/mimemultipart.cpp \
    utils/email/mimepart.cpp \
    utils/email/mimetext.cpp \
    utils/email/quotedprintable.cpp \
    utils/email/sender.cpp

HEADERS += \
        mainwindow.h \
    SpringInterpreterThread.h \
    utils/FileUtils.h \
    SpringLibrarySpecificationForm.h \
    view/InputDialog.h \
    WorkspaceView.h \
    utils/email/emailaddress.h \
    utils/email/emailaddress_p.h \
    utils/email/EmailHelper.h \
    utils/email/mimeattachment.h \
    utils/email/mimecontentformatter.h \
    utils/email/mimefile.h \
    utils/email/mimehtml.h \
    utils/email/mimeinlinefile.h \
    utils/email/mimemessage.h \
    utils/email/mimemessage_p.h \
    utils/email/mimemultipart.h \
    utils/email/mimemultipart_p.h \
    utils/email/mimepart.h \
    utils/email/mimepart_p.h \
    utils/email/mimetext.h \
    utils/email/mimetext_p.h \
    utils/email/quotedprintable.h \
    utils/email/sender.h \
    utils/email/sender_p.h \
    utils/email/smtpexports.h

FORMS += \
        mainwindow.ui \
    SpringLibInformationForm.ui \
    view/InputDialog.ui \
    WorkspaceView.ui

RESOURCES += \
    img.qrc


CONFIG += c++11


INCLUDEPATH+= ../arma\include
LIBS += -L../arma\lib_win64\blas.lib
        -L../arma\lib_win64\lapack.lib
        -L../arma\lib_win64\libf2c.lib



# qscintilla2
CONFIG += qscintilla2_qt5

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/Qsci_lib/ -lqscintilla2_qt5
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/Qsci_lib/ -lqscintilla2_qt5d

INCLUDEPATH += $$PWD/Qsci_lib/
DEPENDPATH += $$PWD/Qsci_lib/

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/Qsci_lib/libqscintilla2_qt5.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/Qsci_lib/libqscintilla2_qt5d.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/Qsci_lib/qscintilla2_qt5.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/Qsci_lib/qscintilla2_qt5d.lib




# SpringInterpreter
win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../SpringInterpreter/release/ -lSpringInterpreter
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../SpringInterpreter/debug/ -lSpringInterpreter

INCLUDEPATH += $$PWD/../SpringInterpreter
DEPENDPATH += $$PWD/../SpringInterpreter
