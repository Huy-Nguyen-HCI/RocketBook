oTEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
#CONFIG -= qt
QT +=sql

SOURCES += main.cpp \
    databasetester.cpp \
    modeltester.cpp
INCLUDEPATH += googletest                       \
                       ../googletest/src                   \
                       ../googletest/src/gtest             \
                       ../googletest/include               \
                       ../googletest/include/gtest         \
                       ../googletest/include/gtest/internal

        LIBS +=  -L/usr/lib -Wall -Wextra -pthread

        SOURCES += "../googletest/src/gtest.cc"            \
                   "../googletest/src/gtest-death-test.cc" \
                   "../googletest/src/gtest-filepath.cc"   \
                   "../googletest/src/gtest-port.cc"       \
                   "../googletest/src/gtest-printers.cc"   \
                   "../googletest/src/gtest-test-part.cc"  \
                   "../googletest/src/gtest-typed-test.cc" \
                   ../../database/*db.cpp                  \
                   ../../model/accountcontroller.cpp       \
                   ../../model/blog.cpp                    \
                   ../../model/chat.cpp                    \
                   ../../model/chatcontroller.cpp          \
                   ../../model/comment.cpp                 \
                   ../../model/feed.cpp                    \
                   ../../model/message.cpp                 \
                   ../../model/multimedia.cpp              \
                   ../../model/post.cpp                    \
                   ../../model/profile.cpp                 \
                   ../../model/rocketuser.cpp              \
                   ../../model/scrapbook.cpp               \
                   ../../model/tweet.cpp                   \
                   ../../model/group.cpp                   \
                   ../../model/groupcontroller.cpp         \



        HEADERS += ../../database/*.h \
                   ../../model/*.h \
                    modeltester.h      \
                    databasetester.h


