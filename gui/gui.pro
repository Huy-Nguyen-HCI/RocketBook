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
    ../database/*db.cpp \
    ../model/accountcontroller.cpp \
    ../model/blog.cpp \
    ../model/comment.cpp \
    ../model/feed.cpp \
    ../model/post.cpp \
    ../model/rocketuser.cpp \
    ../model/tweet.cpp \
    ../model/multimedia.cpp \
    ../model/scrapbook.cpp \
    ../model/profile.cpp


HEADERS  += logingui.h \
    mainwindow.h \
    createpostgui.h \
    ../database/*db.h \
    ../model/*.h

FORMS    += logingui.ui \
    mainwindow.ui \
    createpostgui.ui

RESOURCES += \
    icons.qrc \



