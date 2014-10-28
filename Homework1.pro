#-------------------------------------------------
#
# Project created by QtCreator 2014-10-22T16:05:27
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Homework1
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    curvewidget.cpp

HEADERS  += mainwindow.h \
    curvewidget.h \
    Angel.h \
    CheckError.h \
    mat.h \
    vec.h

FORMS    += mainwindow.ui

OTHER_FILES +=

unix|win32: LIBS += -lglew32

LIBS += -L"C:\Program Files (x86)\Microsoft Visual Studio 12.0\VC\lib" -lpsapi
LIBS += -L"C:\Program Files (x86)\Windows Kits\8.1\Lib\winv6.3\um\x86" -lpsapi

INCLUDEPATH += "C:\Program Files (x86)\Microsoft Visual Studio 12.0\VC\include"
INCLUDEPATH += "C:\Program Files (x86)\Windows Kits\8.1\Include\shared"
INCLUDEPATH += "C:\Program Files (x86)\Windows Kits\8.1\Include\um"

RESOURCES += \
    resources.qrc
