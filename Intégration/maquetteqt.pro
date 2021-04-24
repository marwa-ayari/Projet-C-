
QT       += core gui sql charts printsupport
QT       += serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets multimedia multimediawidgets

CONFIG += c++11
QT +=network
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    arduino.cpp \
    cadeau.cpp \
    categories.cpp \
    client.cpp \
    clients_cadeaux.cpp \
    connexion.cpp \
    gestion.cpp \
    gestion_categories_reclamations.cpp \
    gestion_materiaux_maintenances.cpp \
    jeu.cpp \
    mail.cpp \
    main.cpp \
    maintenanceetat.cpp \
    maintenances.cpp \
    mainwindow.cpp \
    materiaux.cpp \
    reclamationbar.cpp \
    reclamations.cpp \
    securite.cpp \
    stat.cpp \
    statistique.cpp \
    statistiquereclamations.cpp

HEADERS += \
    arduino.h \
    cadeau.h \
    categories.h \
    client.h \
    clients_cadeaux.h \
    connexion.h \
    gestion.h \
    gestion_categories_reclamations.h \
    gestion_materiaux_maintenances.h \
    jeu.h \
    mail.h \
    maintenanceetat.h \
    maintenances.h \
    mainwindow.h \
    materiaux.h \
    reclamationbar.h \
    reclamations.h \
    securite.h \
    stat.h \
    statistique.h \
    statistiquereclamations.h

FORMS += \
    gestion.ui \
    gestion_categories_reclamations.ui \
    gestion_materiaux_maintenances.ui \
    maintenanceetat.ui \
    mainwindow.ui \
    reclamationbar.ui \
    securite.ui \
    stat.ui \
    statistiquereclamations.ui\
    clients_cadeaux.ui \

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    maquetteqt.pro.user
