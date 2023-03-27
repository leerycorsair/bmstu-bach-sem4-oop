QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    lift_cabin.cpp \
    lift_controller.cpp \
    doors.cpp \
    lift.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    lift_cabin.h \
    lift_controller.h \
    direction.h \
    doors.h \
    lift.h \
    mainwindow.h \
    ui_mainwindow.h


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
