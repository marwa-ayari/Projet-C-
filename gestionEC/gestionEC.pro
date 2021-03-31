QT       += core gui sql network

greaterThan(QT_MAJOR_VERSION, 4):  QT += widgets multimedia
TARGET = smtp
TEMPLATE = app



CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    conges.cpp \
    connection.cpp \
    employes.cpp \
    gesempcong.cpp \
    main.cpp \
    mainwindow.cpp \
    smtp.cpp

HEADERS += \
    conges.h \
    connection.h \
    employes.h \
    gesempcong.h \
    mainwindow.h \
    smtp.h

FORMS += \
    gesempcong.ui \
    mainwindow.ui

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