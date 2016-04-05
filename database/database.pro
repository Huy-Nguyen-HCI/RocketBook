TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

LIBS    += -l sqlite3

SOURCES += \
    dbtool.cpp \
    dbtable.cpp \
    accountdb.cpp \
    main.cpp \
    dbmanager.cpp

HEADERS += \
    dbtool.h \
    dbtable.h \
    accountdb.h \
    dbmanager.h

QT += sql
