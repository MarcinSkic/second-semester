#-------------------------------------------------
#
# Project created by QtCreator 2021-06-09T10:44:40
#
#-------------------------------------------------
QMAKE_CXXFLAGS += -std=c++0x
QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Lab13_LissajousApp
TEMPLATE = app


SOURCES += main.cpp\
    model.cpp \
    sterowanie.cpp \
    wyswietlanie.cpp

HEADERS  += \
    model.h \
    sterowanie.h \
    wyswietlanie.h

FORMS    += mainwindow.ui
