#-------------------------------------------------
#
# Project created by QtCreator 2016-12-18T15:24:10
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = RegulatorMLS
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    wizualizacja.cpp \
    symulacja.cpp \
    kulka.cpp \
    podstawka.cpp

HEADERS  += mainwindow.h \
    wizualizacja.h \
    symulacja.h \
    kulka.h \
    podstawka.h

FORMS    += mainwindow.ui
