#-------------------------------------------------
#
# Project created by QtCreator 2016-04-05T13:54:19
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = gui
TEMPLATE = app


SOURCES += logingui.cpp \
    mainwindow.cpp \
    main.cpp \
    createpostgui.cpp \
    scrapbook.cpp

HEADERS  += logingui.h \
    mainwindow.h \
    createpostgui.h \
    scrapbook.h

FORMS    += logingui.ui \
    mainwindow.ui \
    createpostgui.ui \
    scrapbook.ui

RESOURCES += \
    icons.qrc
