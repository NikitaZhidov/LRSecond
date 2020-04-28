include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt

QMAKE_CXXFLAGS += -Wall -Wextra
QMAKE_CFLAGS += -Wall -Wextra

# gcov
QMAKE_CXXFLAGS += -fprofile-arcs -ftest-coverage
QMAKE_CFLAGS += -fprofile-arcs -ftest-coverage
LIBS += -lgcov


HEADERS +=     \
    ../app/common.h \
    ../app/myfunc.h \
    ../app/text/_text.h \
    ../app/text/text.h \
    m_test.h \
    mwbb.h \
    rc_test.h \
    sEmpty_test.h \
    save_test.h

SOURCES +=     main.cpp \
    ../app/load.c \
    ../app/myfunc.c \
    ../app/save.c \
    ../app/show.c \
    ../app/showonempty.c \
    ../app/text/append_line.c \
    ../app/text/create_text.c \
    ../app/text/m.c \
    ../app/text/mwbb.c \
    ../app/text/process_forward.c \
    ../app/text/rc.c \
    ../app/text/remove_all.c

INCLUDEPATH += ../app
