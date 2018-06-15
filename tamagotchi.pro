#-------------------------------------------------
#
# Project created by QtCreator 2018-05-25T22:53:01
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = tamagotchi
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
    scene/cleanbutton.cpp \
    scene/feedbutton.cpp \
    scene/nursebutton.cpp \
    scene/pet.cpp \
    scene/petbutton.cpp \
    scene/petwidget.cpp \
    scene/statsbutton.cpp \
    scene/widget.cpp

HEADERS += \
    scene/cleanbutton.h \
    scene/feedbutton.h \
    scene/nursebutton.h \
    scene/pet.h \
    scene/petbutton.h \
    scene/petwidget.h \
    scene/statsbutton.h \
    scene/widget.h

DISTFILES +=

RESOURCES += \
    taco.qrc
