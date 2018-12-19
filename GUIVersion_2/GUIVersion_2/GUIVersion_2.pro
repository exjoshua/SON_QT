#-------------------------------------------------
#
# Project created by QtCreator 2018-10-31T13:45:28
#
#-------------------------------------------------

QT       += core gui network
CONFIG += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport


TARGET = GUIVersion_2
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
        widget.cpp \
    iconhelper.cpp \
    appinit.cpp \
    config_mainwindow.cpp \
    sontcpserver.cpp \
    socketthread.cpp \
    qcustomplot.cpp \
    optimize_mainwindow.cpp \
    heal_mainwindow.cpp \
    bsone_mainwindow.cpp \
    bstwo_mainwindow.cpp \
    bsthree_mainwindow.cpp \
    log_mainwindow.cpp \
    threadreadpy.cpp \
    alwaysdopython.cpp

HEADERS += \
        widget.h \
    iconhelper.h \
    appinit.h \
    config_mainwindow.h \
    sontcpserver.h \
    socketthread.h \
    qcustomplot.h \
    optimize_mainwindow.h \
    heal_mainwindow.h \
    bsone_mainwindow.h \
    bstwo_mainwindow.h \
    bsthree_mainwindow.h \
    log_mainwindow.h \
    threadreadpy.h \
    alwaysdopython.h

FORMS += \
        widget.ui \
    config_mainwindow.ui \
    optimize_mainwindow.ui \
    heal_mainwindow.ui \
    bsone_mainwindow.ui \
    bstwo_mainwindow.ui \
    bsthree_mainwindow.ui \
    log_mainwindow.ui

RESOURCES += \
    main.qrc \
    qss.qrc


OTHER_FILES +=
