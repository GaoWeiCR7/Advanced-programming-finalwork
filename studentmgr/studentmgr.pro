#-------------------------------------------------
#
# Project created by QtCreator 2019-06-09T00:36:51
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = studentmgr
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

CONFIG += c++11

SOURCES += \
        admin__info_look.cpp \
        admin_info_change.cpp \
        admindo.cpp \
        adminjudge.cpp \
        changestuscoreshow.cpp \
        course_info_change.cpp \
        courseshow.cpp \
        loginshow.cpp \
        main.cpp \
        mainwindow.cpp \
        namelistshow.cpp \
        newcourse_add.cpp \
        studo.cpp \
        teado.cpp

HEADERS += \
        admin__info_look.h \
        admin_info_change.h \
        admindo.h \
        adminjudge.h \
        changestuscoreshow.h \
        course_info_change.h \
        courseshow.h \
        loginshow.h \
        mainwindow.h \
        namelistshow.h \
        newcourse_add.h \
        studo.h \
        teado.h

FORMS += \
        admin__info_look.ui \
        admin_info_change.ui \
        admindo.ui \
        adminjudge.ui \
        changestuscoreshow.ui \
        course_info_change.ui \
        courseshow.ui \
        loginshow.ui \
        mainwindow.ui \
        namelistshow.ui \
        newcourse_add.ui \
        studo.ui \
        teado.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
