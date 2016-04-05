TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
#CONFIG -= qt

LIBS    += -l sqlite3

SOURCES += main.cpp \
    rocketuser.cpp \
    profile.cpp \
#    ../database/*.cpp
    blog.cpp \
    comment.cpp \
    multimediacontent.cpp \
    post.cpp \
    scrapbook.cpp \
    tweet.cpp \
    feed.cpp

HEADERS += \
    rocketuser.h \
    profile.h \
#    ../database/*.h
    blog.h \
    comment.h \
    multimediacontent.h \
    post.h \
    scrapbook.h \
    tweet.h \
    feed.h
