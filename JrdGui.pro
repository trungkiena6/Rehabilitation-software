#-------------------------------------------------
#
# Project created by QtCreator 2016-08-14T09:01:27
#
#-------------------------------------------------

QT       += core gui \
            multimedia serialport sql \
            widgets


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = JrdGui
TEMPLATE = app


SOURCES += main.cpp\
    jrdgui.cpp \
    SideScrollerGame/bullet.cpp \
    SideScrollerGame/enemy.cpp \
    SideScrollerGame/friend.cpp \
    SideScrollerGame/game.cpp \
    SideScrollerGame/health.cpp \
    SideScrollerGame/myrect.cpp \
    SideScrollerGame/myserial.cpp \
    SideScrollerGame/score.cpp

HEADERS  += jrdgui.h \
    SideScrollerGame/bullet.h \
    SideScrollerGame/enemy.h \
    SideScrollerGame/friend.h \
    SideScrollerGame/game.h \
    SideScrollerGame/health.h \
    SideScrollerGame/myrect.h \
    SideScrollerGame/myserial.h \
    SideScrollerGame/score.h

FORMS    += jrdgui.ui

INCLUDEPATH += "/home/hung303mc/JRDProject/JrdGui/SideScrollerGame"


RESOURCES += \
        SideScrollerGame/res.qrc
