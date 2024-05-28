#-------------------------------------------------
#
# Project created by QtCreator 2023-03-27T10:25:16
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TrainControlSystem
TEMPLATE = app


SOURCES += main.cpp \
    mainWindow.cpp \
    speedometer.cpp \
    traininfo.cpp \
    trainnumber.cpp \
    distance.cpp

HEADERS  += mainwindow.h \
    speedometer.h \
    traininfo.h \
    trainnumber.h \
    distance.h

FORMS    += mainwindow.ui \
    traininfo.ui

RESOURCES += \
    resource.qrc
