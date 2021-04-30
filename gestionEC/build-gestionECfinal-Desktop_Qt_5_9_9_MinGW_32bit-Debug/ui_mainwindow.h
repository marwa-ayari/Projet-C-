/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QFrame *frame;
    QLabel *label_4;
    QGroupBox *groupBox_2;
    QLabel *label_17;
    QLabel *label_20;
    QLineEdit *username;
    QLineEdit *password;
    QPushButton *login;
    QPushButton *sonon;
    QPushButton *sonoff;
    QPushButton *arduinofenetrefume;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(998, 602);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        frame = new QFrame(centralwidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(810, 20, 171, 91));
        frame->setStyleSheet(QStringLiteral("background-color:qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0.0720339 rgba(153, 153, 153, 130), stop:1 rgba(255, 10, 164, 71))"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(-30, -170, 1841, 791));
        label_4->setPixmap(QPixmap(QString::fromUtf8("../resources/pink-cupcake-wallpaper-mural.jpg")));
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setEnabled(true);
        groupBox_2->setGeometry(QRect(40, 40, 641, 471));
        QFont font;
        font.setFamily(QStringLiteral("Lucida Calligraphy"));
        font.setPointSize(21);
        font.setBold(true);
        font.setItalic(true);
        font.setUnderline(true);
        font.setWeight(75);
        groupBox_2->setFont(font);
        groupBox_2->setAutoFillBackground(false);
        groupBox_2->setStyleSheet(QLatin1String("\n"
"color: rgb(130, 0, 98);\n"
"background-color:qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0.0720339 rgba(153, 153, 153, 130), stop:1 rgba(255, 10, 164, 71))"));
        groupBox_2->setFlat(false);
        groupBox_2->setCheckable(false);
        label_17 = new QLabel(groupBox_2);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(60, 90, 291, 31));
        QFont font1;
        font1.setFamily(QStringLiteral("Lucida Calligraphy"));
        font1.setPointSize(20);
        label_17->setFont(font1);
        label_17->setAutoFillBackground(false);
        label_20 = new QLabel(groupBox_2);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setGeometry(QRect(70, 200, 281, 31));
        label_20->setFont(font1);
        username = new QLineEdit(groupBox_2);
        username->setObjectName(QStringLiteral("username"));
        username->setGeometry(QRect(270, 130, 211, 41));
        password = new QLineEdit(groupBox_2);
        password->setObjectName(QStringLiteral("password"));
        password->setGeometry(QRect(280, 250, 201, 41));
        password->setStyleSheet(QStringLiteral(""));
        login = new QPushButton(groupBox_2);
        login->setObjectName(QStringLiteral("login"));
        login->setGeometry(QRect(410, 380, 181, 71));
        QFont font2;
        font2.setFamily(QStringLiteral("Lucida Calligraphy"));
        font2.setPointSize(21);
        font2.setBold(true);
        font2.setWeight(75);
        login->setFont(font2);
        login->setStyleSheet(QLatin1String("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(255, 0, 127, 142), stop:0.991525 rgba(233, 170, 255, 195));\n"
"color: rgb(130, 0, 98);"));
        sonon = new QPushButton(centralwidget);
        sonon->setObjectName(QStringLiteral("sonon"));
        sonon->setGeometry(QRect(910, 30, 61, 61));
        QIcon icon;
        icon.addFile(QStringLiteral("../resources/sonon.png"), QSize(), QIcon::Normal, QIcon::Off);
        sonon->setIcon(icon);
        sonon->setIconSize(QSize(50, 50));
        sonon->setAutoDefault(true);
        sonon->setFlat(true);
        sonoff = new QPushButton(centralwidget);
        sonoff->setObjectName(QStringLiteral("sonoff"));
        sonoff->setGeometry(QRect(840, 40, 51, 41));
        QIcon icon1;
        icon1.addFile(QStringLiteral("../resources/sonof.png"), QSize(), QIcon::Normal, QIcon::Off);
        sonoff->setIcon(icon1);
        sonoff->setIconSize(QSize(50, 50));
        sonoff->setFlat(true);
        arduinofenetrefume = new QPushButton(centralwidget);
        arduinofenetrefume->setObjectName(QStringLiteral("arduinofenetrefume"));
        arduinofenetrefume->setGeometry(QRect(750, 310, 191, 61));
        QFont font3;
        font3.setPointSize(21);
        arduinofenetrefume->setFont(font3);
        arduinofenetrefume->setStyleSheet(QLatin1String("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0.0635593 rgba(170, 0, 127, 164), stop:1 rgba(255, 214, 0, 82));\n"
"color:rgb(106, 0, 0);"));
        MainWindow->setCentralWidget(centralwidget);
        label_4->raise();
        frame->raise();
        groupBox_2->raise();
        sonon->raise();
        sonoff->raise();
        arduinofenetrefume->raise();
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 998, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        sonon->setDefault(true);
        sonoff->setDefault(true);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        label_4->setText(QString());
        groupBox_2->setTitle(QApplication::translate("MainWindow", "gestion employ\303\251s cong\303\251s", Q_NULLPTR));
        label_17->setText(QApplication::translate("MainWindow", "USERNAME", Q_NULLPTR));
        label_20->setText(QApplication::translate("MainWindow", "PASSWORD", Q_NULLPTR));
        login->setText(QApplication::translate("MainWindow", "login", Q_NULLPTR));
        sonon->setText(QString());
        sonoff->setText(QString());
        arduinofenetrefume->setText(QApplication::translate("MainWindow", "ARDUINO", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
