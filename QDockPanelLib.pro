#-------------------------------------------------
#
# Project created by QtCreator 2014-07-22T13:42:50
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QDockPanelLib
TEMPLATE = app


SOURCES += main.cpp\
        QDockFrame.cpp \
    QDockArrows.cpp \
    QDockPanel.cpp

HEADERS  += QDockFrame.h \
    QDockArrows.h \
    QDockCommon.h \
    QDockPanel.h

RESOURCES += \
    DockResource.qrc
