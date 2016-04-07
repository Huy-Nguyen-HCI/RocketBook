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
    bloggui.cpp

HEADERS  += logingui.h \
    mainwindow.h \
    bloggui.h

FORMS    += logingui.ui \
    mainwindow.ui \
    bloggui.ui

RESOURCES += \
    icons.qrc
