#-------------------------------------------------
#
# Project created by QtCreator 2015-12-26T11:28:48
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Kurs
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    database.cpp \
    editelement.cpp \
    search.cpp

HEADERS  += mainwindow.h \
    vector.h \
    database.h \
    editelement.h \
    search.h

FORMS    += mainwindow.ui \
    editelement.ui \
    search.ui
