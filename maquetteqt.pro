
QT       += core gui sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    categories.cpp \
    connexion.cpp \
    gestion_categories_reclamations.cpp \
    gestion_materiaux_maintenances.cpp \
    main.cpp \
    maintenances.cpp \
    mainwindow.cpp \
    materiaux.cpp \
    reclamations.cpp

HEADERS += \
    categories.h \
    connexion.h \
    gestion_categories_reclamations.h \
    gestion_materiaux_maintenances.h \
    maintenances.h \
    mainwindow.h \
    materiaux.h \
    reclamations.h

FORMS += \
    gestion_categories_reclamations.ui \
    gestion_materiaux_maintenances.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
