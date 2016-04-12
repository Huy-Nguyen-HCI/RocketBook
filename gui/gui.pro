#-------------------------------------------------
#
# Project created by QtCreator 2016-04-05T13:54:19
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
CONFIG -= app_bundle
QT +=sql
TARGET = gui
TEMPLATE = app


SOURCES += logingui.cpp \
    mainwindow.cpp \
    main.cpp \
    createpostgui.cpp \
    scrapbook.cpp \
    ../database/accountdb.cpp

HEADERS  += logingui.h \
    mainwindow.h \
    createpostgui.h \
    scrapbook.h \
    ../database/accountdb.h

FORMS    += logingui.ui \
    mainwindow.ui \
    createpostgui.ui \
    scrapbook.ui

RESOURCES += \
    icons.qrc \



