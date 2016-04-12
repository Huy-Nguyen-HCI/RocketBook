TEMPLATE = app

#QT += qml quick
CONFIG += c++11

SOURCES += main.cpp \
    accountdb.cpp \
    profiledb.cpp \
    commentdb.cpp \
    multimediadb.cpp \
    frienddb.cpp    \
    tweetdb.cpp \
    blogdb.cpp \
    postdb.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    accountdb.h \
    profiledb.h \
    commentdb.h \
    multimediadb.h \
    frienddb.h  \
    tweetdb.h \
    blogdb.h \
    postdb.h

QT +=sql
