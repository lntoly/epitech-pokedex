#-------------------------------------------------
#
# Project created by QtCreator 2010-11-14T07:52:52
#
#-------------------------------------------------

QT       += core gui xml

TARGET = Pokedex
TEMPLATE = app


SOURCES += \
    graphic/master.cpp \
    graphic/manageteam.cpp \
    graphic/managemasterslots.cpp \
    graphic/managemaster.cpp \
    graphic/mainwindowslots.cpp \
    graphic/mainwindow.cpp \
    graphic/main.cpp \
    graphic/equipe.cpp \
    graphic/addteamslots.cpp \
    graphic/addteam.cpp \
    graphic/addmasterslots.cpp \
    graphic/addmaster.cpp \
    graphic/aboutslots.cpp \
    graphic/about.cpp \
    parser/pokedexmanager.cpp \
    parser/move.cpp \
    parser/handler.cpp \
    parser/evo.cpp \
    parser/dpokemon.cpp

HEADERS  += \
    graphic/master.h \
    graphic/manageteam.h \
    graphic/managemaster.h \
    graphic/mainwindow.h \
    graphic/equipe.h \
    graphic/addteam.h \
    graphic/addmaster.h \
    graphic/about.h \
    parser/pokedexmanager.h \
    parser/move.h \
    parser/handler.h \
    parser/evo.h \
    parser/dpokemon.h

FORMS    += \
    view/manageteam.ui \
    view/managemaster.ui \
    view/mainwindow.ui \
    view/addteam.ui \
    view/addmaster.ui \
    view/about.ui

RESOURCES += \
    ressources.qrc
