#include "clients_cadeaux.h"
#include "ui_clients_cadeaux.h"
#include"client.h"

#include<QString>
#include<QMessageBox>
#include<QPixmap>
#include <QSqlQuery>
#include <QSqlQueryModel>
clients_cadeaux::clients_cadeaux(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::clients_cadeaux)
{
    ui->setupUi(this);

}

clients_cadeaux::~clients_cadeaux()
{
    delete ui;
}
void clients_cadeaux::on_pushButton_ajouterCl_2_clicked()
{
    QString nom= ui->lineEdit_nom_ajout_2->text();
    QString prenom= ui->lineEdit_prenom_ajout_2->text();
    QString adresse= ui->lineEdit_adresse_ajout_2->text();
    int tel= ui->lineEdit_tel_ajout_2->text().toInt();
      int pts= ui->spinBox_pt_fid_ajout_2->text().toInt();
      int matricule= ui->lineEdit_cin_ajout_2->text().toInt();
    Client a(nom,prenom,adresse,tel,pts,matricule);
    bool test=a.ajouter1();
    if(test)
  {

  QMessageBox::information(nullptr, QObject::tr("Ajouter un client"),
  QObject::tr("Client ajouté.\nClick Cancel to exit."), QMessageBox::Cancel);

  }
    else
        QMessageBox::critical(nullptr, QObject::tr("Ajouter un client "),
                    QObject::tr("Erreur else !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);




}

void clients_cadeaux::on_pushButton_cherch_2_clicked()
{
     ui->comboBox_suppCl_2->setModel(tmpclient.modifier_liste_matricule());
}

void clients_cadeaux::on_pushButton_suppCl_2_clicked()
{
    int matricule= ui->comboBox_suppCl_2->currentText().toInt();
 bool test=tmpclient.supprimer1(matricule);
       if(test)

           {ui->comboBox_suppCl_2->setModel(tmpclient.afficher1());//refresh

                   QMessageBox::information(nullptr, QObject::tr("Supprimer un client"),
                               QObject::tr("client supprimé.\n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);
                    ui->comboBox_suppCl_2->setModel(tmpclient.modifier_liste_matricule());

               }
               else
                   QMessageBox::critical(nullptr, QObject::tr("Supprimer un client"),
                               QObject::tr("Erreur !.\n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);
}







void clients_cadeaux::on_pushButton_modifCl_2_clicked()
{
    int matricule= ui->comboBox_client_2->currentText().toInt();
       QString nom= ui->lineEdit_nom_modif_2->text();
       QString prenom= ui->lineEdit_prenom_modif_2->text();
       QString adresse= ui->lineEdit_adresse_modif_2->text();
      int  tel=ui->lineEdit_tel_modif_2->text().toInt();
        int  pts=ui->spinBox_pt_fid_modif_2->text().toInt();
       Client a(nom,prenom,adresse,tel,pts,matricule);
       bool test=a.modifier1(matricule);
        if(test)
       {
                 QMessageBox::information(nullptr, QObject::tr("Modifier un client"),
                             QObject::tr("client modifié.\n"), QMessageBox::Cancel);

       }
       else
       {
           QMessageBox::critical(nullptr, QObject::tr("Modifier un client"),
                             QObject::tr("Erreur de modification !\n"), QMessageBox::Cancel);
       }
}


void clients_cadeaux::on_tabWidget_2_currentChanged(int index)
{
    ui->tableWidget_2->setEnabled(true);
     ui->tableWidget_2->setModel(tmpclient.afficher1());
 ui->comboBox_suppCl_2->setModel(tmpclient.modifier_liste_matricule());
}


