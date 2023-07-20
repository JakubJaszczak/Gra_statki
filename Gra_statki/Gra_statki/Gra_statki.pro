#-------------------------------------------------
#
# Project created by QtCreator 2020-03-05T11:51:37
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Gra_statki
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    model.cpp \
    controller.cpp

HEADERS  += mainwindow.h \
    model.h \
    controller.h

FORMS    += mainwindow.ui
