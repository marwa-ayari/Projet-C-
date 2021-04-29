/********************************************************************************
** Form generated from reading UI file 'securite.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SECURITE_H
#define UI_SECURITE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_securite
{
public:
    QLabel *label_temperature;
    QLabel *label;
    QLabel *label_temperature_2;

    void setupUi(QDialog *securite)
    {
        if (securite->objectName().isEmpty())
            securite->setObjectName(QStringLiteral("securite"));
        securite->resize(820, 439);
        label_temperature = new QLabel(securite);
        label_temperature->setObjectName(QStringLiteral("label_temperature"));
        label_temperature->setGeometry(QRect(30, 60, 291, 91));
        label_temperature->setStyleSheet(QLatin1String("font: 75 16pt 'Script MT Bold';background-color: rgb(0, 0, 127);color: rgb(255, 0, 0);\n"
""));
        label = new QLabel(securite);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, -20, 871, 481));
        label->setPixmap(QPixmap(QString::fromUtf8("../../../../../../../../../../i/sec.png")));
        label_temperature_2 = new QLabel(securite);
        label_temperature_2->setObjectName(QStringLiteral("label_temperature_2"));
        label_temperature_2->setGeometry(QRect(510, 320, 291, 91));
        label_temperature_2->setStyleSheet(QLatin1String("font: 75 16pt 'Script MT Bold';background-color: rgb(0, 0, 127);color: rgb(255, 0, 0);\n"
""));
        label->raise();
        label_temperature->raise();
        label_temperature_2->raise();

        retranslateUi(securite);

        QMetaObject::connectSlotsByName(securite);
    } // setupUi

    void retranslateUi(QDialog *securite)
    {
        securite->setWindowTitle(QApplication::translate("securite", "Gestion de la s\303\251curit\303\251", Q_NULLPTR));
        label_temperature->setText(QApplication::translate("securite", "   Veuillez patientez un moment...", Q_NULLPTR));
        label->setText(QString());
        label_temperature_2->setText(QApplication::translate("securite", "   Veuillez patientez un moment...", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class securite: public Ui_securite {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SECURITE_H
