#-------------------------------------------------
#
# Project created by QtCreator 2024-09-14T19:16:46
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DrivingAssitanceItem
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
        main.cpp \
        view/bootwidget.cpp \
    view/mainwidget.cpp \
    Thread/camdecode.cpp \
    Thread/decode.cpp \
    Thread/readthread.cpp \
    Thread/heartbeatthread.cpp \
    Thread/sendtask.cpp \
    Thread/splitfile.cpp \
    Thread/writethread.cpp \
    socketconnect.cpp \
    videolistitem.cpp \
    view/loginwidget.cpp \
    view/regwidget.cpp \
    view/videowidget.cpp

HEADERS += \
        view/bootwidget.h \
    view/mainwidget.h \
    Thread/camdecode.h \
    Thread/decode.h \
    Thread/readthread.h \
    Thread/heartbeatthread.h \
    Thread/sendtask.h \
    Thread/splitfile.h \
    Thread/writethread.h \
    protocol.h \
    socketconnect.h \
    videolistitem.h \
    view/loginwidget.h \
    view/regwidget.h \
    view/videowidget.h

FORMS += \
        view/bootwidget.ui \
    view/mainwidget.ui \
    videolistitem.ui \
    view/loginwidget.ui \
    view/regwidget.ui \
    view/videowidget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

#Linux opencv
INCLUDEPATH +=/usr/local/include/
LIBS+=/usr/local/lib/libopencv_world.so
