TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
#CONFIG -= qt
QT +=sql

LIBS    += -l sqlite3

SOURCES += main.cpp \
    rocketuser.cpp \
    profile.cpp \
    ../database/accountdb.cpp \
    ../database/frienddb.cpp \
    blog.cpp \
    comment.cpp \
    multimediacontent.cpp \
    post.cpp \
    scrapbook.cpp \
    tweet.cpp \
    feed.cpp \
    accountcontroller.cpp

HEADERS += \
    rocketuser.h \
    profile.h \
    ../database/*.h \
    blog.h \
    comment.h \
    multimediacontent.h \
    post.h \
    scrapbook.h \
    tweet.h \
    feed.h \
    accountcontroller.h
