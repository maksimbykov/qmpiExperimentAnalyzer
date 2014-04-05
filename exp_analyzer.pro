#-------------------------------------------------
#
# Project created by QtCreator 2014-02-07T10:35:30
#
#-------------------------------------------------

QT       += core gui xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = exp_analyzer
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    qcustomplot.cpp \
    mycustomplot.cpp \
    optionsdialog.cpp \
    runexperimentdialog.cpp

HEADERS  += mainwindow.h \
    qcustomplot.h \
    mycustomplot.h \
    optionsdialog.h \
    runexperimentdialog.h

FORMS    += mainwindow.ui
