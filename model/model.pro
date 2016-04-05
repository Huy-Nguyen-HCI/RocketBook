TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

LIBS    += -l sqlite3

SOURCES += main.cpp \
    rocketuser.cpp \
    profile.cpp \
    ../database/*.cpp

HEADERS += \
    rocketuser.h \
    profile.h \
    ../database/*.h
