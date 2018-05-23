#-------------------------------------------------
#
# Project created by QtCreator 2018-04-28T17:29:23
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TestingSystem
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
    registration.cpp \
    dbconnection.cpp \
    login.cpp \
    editor.cpp \
    highlighter.cpp \
    problem.cpp \
    problemset.cpp \
    python.cpp \
    newproblem.cpp \
    hope.cpp

HEADERS += \
    registration.h \
    dbconnection.h \
    login.h \
    highlighter.h \
    problem.h \
    editor.h \
    problemset.h \
    python.h \
    newproblem.h \
    hope.h

FORMS += \
    registration.ui \
    login.ui \
    editor.ui \
    problem.ui \
    problemset.ui \
    newproblem.ui \
    hope.ui

RESOURCES += \
    info.qrc
