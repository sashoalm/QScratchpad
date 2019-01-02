#-------------------------------------------------
#
# Project created by QtCreator 2019-01-02T18:24:59
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QScratchpad
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    scratchpadedit.cpp

HEADERS  += mainwindow.h \
    scratchpadedit.h

FORMS    += mainwindow.ui

CONFIG += c++11
