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
    SideScrollerGame/enemy.cpp \
    SideScrollerGame/friend.cpp \
    SideScrollerGame/game.cpp \
    SideScrollerGame/health.cpp \
    SideScrollerGame/myserial.cpp \
    SideScrollerGame/score.cpp \
    SideScrollerGame/dialog.cpp \
    SideScrollerGame/player.cpp

HEADERS  += jrdgui.h \
    SideScrollerGame/enemy.h \
    SideScrollerGame/friend.h \
    SideScrollerGame/game.h \
    SideScrollerGame/health.h \
    SideScrollerGame/myserial.h \
    SideScrollerGame/score.h \
    SideScrollerGame/dialog.h \
    SideScrollerGame/player.h

FORMS    += jrdgui.ui

INCLUDEPATH += "/home/hung303mc/JRDProject/JrdGui/SideScrollerGame"


RESOURCES += \
        SideScrollerGame/res.qrc
