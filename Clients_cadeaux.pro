QT       += core gui sql charts
QT       += core gui multimedia multimediawidgets
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
QT += printsupport
 QT +=network
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
DEFINES += QT_DEPRECATED_WARNINGS
SOURCES += \
    Connexion.cpp \
    cadeau.cpp \
    client.cpp \
    clients_cadeaux.cpp \
    jeu.cpp \
    mail.cpp \
     main.cpp \
    mainwindow.cpp \
    stat.cpp\
       traiterimage.cpp

HEADERS += \
    Connexion.h \
    cadeau.h \
    client.h \
    clients_cadeaux.h \
    jeu.h \
    mail.h \
    mainwindow.h \
    stat.h\
       traiterimage.h

FORMS += \
 clients_cadeaux.ui \
 mainwindow.ui \
 stat.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

