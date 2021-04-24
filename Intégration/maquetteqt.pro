
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
    chat.cpp \
    client.cpp \
    clients_cadeaux.cpp \
    conges.cpp \
    connexion.cpp \
    employes.cpp \
    excel.cpp \
    gesempcong.cpp \
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
    securritefume.cpp \
    server.cpp \
    smtp.cpp \
    sslserver.cpp \
    stat.cpp \
    statemp.cpp \
    statistique.cpp \
    statistiquereclamations.cpp

HEADERS += \
    arduino.h \
    cadeau.h \
    categories.h \
    chat.h \
    client.h \
    clients_cadeaux.h \
    conges.h \
    connexion.h \
    employes.h \
    excel.h \
    gesempcong.h \
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
    securritefume.h \
    server.h \
    smtp.h \
    sslserver.h \
    stat.h \
    statemp.h \
    statistique.h \
    statistiquereclamations.h

FORMS += \
    chat.ui \
    clients_cadeaux.ui \
    gesempcong.ui \
    gestion.ui \
    gestion_categories_reclamations.ui \
    gestion_materiaux_maintenances.ui \
    maintenanceetat.ui \
    mainwindow.ui \
    reclamationbar.ui \
    securite.ui \
    securritefume.ui \
    server.ui \
    stat.ui \
    statemp.ui \
    statistiquereclamations.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    maquetteqt.pro.user \
    maquetteqt.pro.user.576aff2
