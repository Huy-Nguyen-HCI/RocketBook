TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
#CONFIG -= qt
QT +=sql

SOURCES += main.cpp
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
                   "../../database/accountdb.cpp"          \
             #      "../../model/blog.cpp"                  \
             #       "../../model/comment.cpp"

        HEADERS += "../../database/accountdb.h"            \
              #     "../../model/blog.h"                  \
              #      "../../model/comment.h"


