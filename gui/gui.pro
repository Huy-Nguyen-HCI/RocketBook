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
    ../database/*db.cpp \
    ../model/accountcontroller.cpp \
    ../model/chatcontroller.cpp \
    ../model/blog.cpp \
    ../model/comment.cpp \
    ../model/feed.cpp \
    ../model/post.cpp \
    ../model/rocketuser.cpp \
    ../model/tweet.cpp \
    ../model/multimedia.cpp \
    ../model/scrapbook.cpp \
    ../model/profile.cpp \
    createaccountgui.cpp \
    dashboardgui.cpp \
    scrapbookgui.cpp \
    createbloggui.cpp \
    createtweetgui.cpp \
    createmultimediagui.cpp \
    displaybloggui.cpp \
    displaytweetgui.cpp \
    displaymultimediagui.cpp


HEADERS  += logingui.h \
    mainwindow.h \
    ../database/*.h \
    ../model/*.h \
    createaccountgui.h \
    dashboardgui.h \
    scrapbookgui.h \
    createbloggui.h \
    createtweetgui.h \
    displaybloggui.h \
    displaytweetgui.h \
    displaymultimediagui.h \
    createmultimediagui.h

FORMS    += logingui.ui \
    mainwindow.ui \
    createaccountgui.ui \
    dashboardgui.ui \
    scrapbookgui.ui \
    createbloggui.ui \
    createtweetgui.ui \
    createmultimediagui.ui \
    displaybloggui.ui \
    displaytweetgui.ui \
    displaymultimediagui.ui

RESOURCES += \
    icons.qrc \



