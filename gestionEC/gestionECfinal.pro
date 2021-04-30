QT       += core gui sql network charts quick serialport

greaterThan(QT_MAJOR_VERSION, 4):  QT += widgets multimedia printsupport
TARGET = smtp
TEMPLATE = app



CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    arduino.cpp \
    chat.cpp \
    conges.cpp \
    connection.cpp \
    employes.cpp \
    excel.cpp \
    gesempcong.cpp \
    main.cpp \
    mainwindow.cpp \
    projeth.cpp \
    securritefume.cpp \
    server.cpp \
    smtp.cpp \
    sslserver.cpp \
    statemp.cpp

HEADERS += \
    arduino.h \
    chat.h \
    conges.h \
    connection.h \
    employes.h \
    excel.h \
    gesempcong.h \
    mainwindow.h \
    projeth.h \
    securritefume.h \
    server.h \
    smtp.h \
    sslserver.h \
    statemp.h

FORMS += \
    chat.ui \
    gesempcong.ui \
    mainwindow.ui \
    securritefume.ui \
    server.ui \
    statemp.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    Gestionempcong.qml \
    GestionempcongForm.ui.qml
    music.wav

RESOURCES += \
    resources.qrc
