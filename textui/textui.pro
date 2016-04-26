TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
#CONFIG -= qt
QT +=sql

LIBS    += -lncurses


SOURCES += main.cpp \
    mainmenu.cpp \
    screen.cpp \
    loginui.cpp \
    ../model/accountcontroller.cpp \
    ../database/*db.cpp  \
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
    ../model/group.cpp \
    ../model/groupcontroller.cpp \
    ../model/friendcontroller.cpp \
    ../model/chat.cpp  \
    ../model/message.cpp  \
    friendsui.cpp \
    chatui.cpp \
    enterui.cpp \
    createaccountui.cpp \
    profileui.cpp \
    scrapbookui.cpp \
    feedui.cpp \
    groupsui.cpp

HEADERS += \
    mainmenu.h \
    screen.h \
    loginui.h \
    ../database/*.h \
    ../model/*.h \
    friendsui.h \
    chatui.h \
    enterui.h \
    createaccountui.h \
    profileui.h \
    scrapbookui.h \
    feedui.h \
    groupsui.h
