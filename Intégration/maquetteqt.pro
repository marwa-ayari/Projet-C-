
QT       += core gui sql charts printsupport
QT       += serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets multimedia

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    arduino.cpp \
    categories.cpp \
    connexion.cpp \
    gestion.cpp \
    gestion_categories_reclamations.cpp \
    main.cpp \
    mainwindow.cpp \
    reclamationbar.cpp \
    reclamations.cpp \
    securite.cpp \
    statistiquereclamations.cpp

HEADERS += \
    arduino.h \
    categories.h \
    connexion.h \
    gestion.h \
    gestion_categories_reclamations.h \
    mainwindow.h \
    reclamationbar.h \
    reclamations.h \
    securite.h \
    statistiquereclamations.h

FORMS += \
    gestion.ui \
    gestion_categories_reclamations.ui \
    mainwindow.ui \
    reclamationbar.ui \
    securite.ui \
    statistiquereclamations.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
