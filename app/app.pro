TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    editor.c \
    load.c \
    myfunc.c \
    save.c \
    show.c \
    showonempty.c \
    text/append_line.c \
    text/create_text.c \
    text/m.c \
    text/mwbb.c \
    text/process_forward.c \
    text/rc.c \
    text/remove_all.c

HEADERS += \
    common.h \
    myfunc.h \
    text/_text.h \
    text/text.h

# gcov

QMAKE_CFLAGS += -fprofile-arcs -ftest-coverage
LIBS += -lgcov
