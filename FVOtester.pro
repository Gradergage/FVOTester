#-------------------------------------------------
#
# Project created by QtCreator 2018-02-17T00:44:37
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = FVOtester
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    Test.cpp \
    Question.cpp

HEADERS  += mainwindow.h \
    Test.h \
    Question.h \
    Funcs.h

FORMS    += mainwindow.ui

OTHER_FILES += \
    tests/3.txt \
    tests/2.txt \
    tests/1.txt
