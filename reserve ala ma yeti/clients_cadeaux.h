#ifndef CLIENTS_CADEAUX_H
#define CLIENTS_CADEAUX_H
#include"client.h"
#include"cadeau.h"
#include"jeu.h"
#include <QFile>
#include <QDialog>
#include <QPropertyAnimation>
#include "mail.h"
namespace Ui {
class clients_cadeaux;
}

class clients_cadeaux : public QDialog
{
    Q_OBJECT

public:
    explicit clients_cadeaux(QWidget *parent = nullptr);
    ~clients_cadeaux();
private slots:
void on_pushButton_ajouterCl_3_clicked();

void on_pushButton_suppCl_3_clicked();

void on_pushButton_modifCl_4_clicked();

void on_tabWidget_5_currentChanged(int index);

void on_pushButton_triCl_4_clicked();

void on_pushButton_rechCl_5_clicked();



void on_pushButton_suppCa_3_clicked();

void on_pushButton_triCa_3_clicked();

void on_pushButton_rechCa_3_clicked();

void on_tabWidget_6_currentChanged(int index);

void on_pushButton_modifCa_3_clicked();

void on_pushButton_statCa_3_clicked();



void on_comboBox_client_3_currentIndexChanged(const QString &arg1);

void on_comboBox_Matclient_2_currentIndexChanged(const QString &arg1);

void on_pushButton_modifCl_5_clicked();

void on_comboBox_Cadeau_3_currentIndexChanged(const QString &arg1);

void on_pushButton_triCl_5_clicked();

void on_pushButton_ajouterCa_4_clicked();

void on_comboBox_affecCadeau_3_currentIndexChanged(const QString &arg1);

void on_pushButton_pdf_2_clicked();

void on_pushButton_notif_2_clicked();

void sendMail();
   void mailSent(QString);

   void on_browseBtn_2_clicked();

   void on_pushButton_ajouterJeu_2_clicked();

   void on_pushButton_suppjeu_2_clicked();

   void on_tabWidget_7_currentChanged(int index);

   void on_pushButton_modifjeu_2_clicked();

   void on_comboBox_idjeu_2_currentIndexChanged(const QString &arg1);

   void on_pushButton_rechCl_6_clicked();

   void on_pushButton_triJeu_2_clicked();



private:
    Ui::clients_cadeaux *ui;
 QPixmap originalPixmap;
       Client tmpclient;
       Cadeau tmpcadeau;
        jeu tmpjeu;
       QPropertyAnimation *animation;
        QStringList files;
};

#endif // CLIENTS_CADEAUX_H
