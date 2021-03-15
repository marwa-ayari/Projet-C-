#include "clients_cadeaux.h"
#include "ui_clients_cadeaux.h"
#include"client.h"
#include"cadeau.h"
#include "stat.h"
#include "QDebug"
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
    ui->comboBox_2->addItem("Chocolat");
    ui->comboBox_2->addItem("Bande d'achat");
    ui->comboBox_2->addItem("Accessoires cuisine");
    ui->comboBox_3->addItem("Chocolat");
    ui->comboBox_3->addItem("Bande d'achat");
    ui->comboBox_3->addItem("Accessoires cuisine");

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
    QString tel= ui->lineEdit_tel_ajout_2->text();

      int pts=0;
      QString matricule= ui->lineEdit_cin_ajout_2->text();
      QString id_cadeau="";
    Client a(matricule,nom,prenom,adresse,tel,pts,id_cadeau);
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


void clients_cadeaux::on_pushButton_suppCl_2_clicked()
{
    QString matricule= ui->comboBox_suppCl_2->currentText();

       if(tmpclient.supprimer1(matricule))

           {

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
    QString matricule= ui->comboBox_client_2->currentText();
       QString nom= ui->lineEdit_nom_modif_2->text();
       QString prenom= ui->lineEdit_prenom_modif_2->text();
       QString adresse= ui->lineEdit_adresse_modif_2->text();
      QString  tel=ui->lineEdit_tel_modif_2->text();
        int  pts=ui->lineEdit_2->text().toInt();

       QString  id_cadeau=ui->comboBox_affecCadeau_2->currentText();

       Client a(matricule,nom,prenom,adresse,tel,pts,id_cadeau);
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
     ui->tableView_2->setModel(tmpclient.afficher1());
     ui->comboBox_suppCl_2->setModel(tmpclient.modifier_liste_matricule());
      ui->comboBox_client_2->setModel(tmpclient.modifier_liste_matricule());


}

void clients_cadeaux::on_pushButton_triCl_2_clicked()
{
     ui->tableView_2->setModel(tmpclient.tri());
}

void clients_cadeaux::on_pushButton_rechCl_3_clicked()
{
    QString nom_client =ui->lineEdit_rech_nom->text();
      ui->tableView_2->setModel(tmpclient.recherche1(nom_client));
}


void clients_cadeaux::on_pushButton_ajoutCa_2_clicked()
{
    QString categorie=ui->comboBox_2->currentText();
    QString id= ui->lineEdit_categ_ajout_2->text();
      int somme= ui->lineEdit_3->text().toInt();
      int nb= ui->lineEdit_4->text().toInt();
    Cadeau ca(id,categorie,somme,nb);
    bool test=ca.ajouter2();
    if(test)
  {

  QMessageBox::information(nullptr, QObject::tr("Ajouter un cadeau"),
  QObject::tr("Cadeau ajouté.\nClick Cancel to exit."), QMessageBox::Cancel);

  }
    else
        QMessageBox::critical(nullptr, QObject::tr("Ajouter un cadeau "),
                    QObject::tr("Erreur else !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);



}

void clients_cadeaux::on_pushButton_suppCa_2_clicked()
{
   QString id= ui->comboBox->currentText();
       if(tmpcadeau.supprimer2(id))

           {

                   QMessageBox::information(nullptr, QObject::tr("Supprimer un cadeau"),
                               QObject::tr("cadeau supprimé.\n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);
                    ui->comboBox->setModel(tmpcadeau.modifier_liste_id());

               }
               else
                   QMessageBox::critical(nullptr, QObject::tr("Supprimer un cadeau"),
                               QObject::tr("Erreur !.\n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);
}

void clients_cadeaux::on_pushButton_triCa_2_clicked()
{
     ui->tableView->setModel(tmpcadeau.tri2());
}

void clients_cadeaux::on_pushButton_rechCa_2_clicked()
{
    QString categorie =ui->lineEdit->text();
      ui->tableView->setModel(tmpcadeau.recherche2(categorie));
}

void clients_cadeaux::on_tabWidget_4_currentChanged(int index)
{
    ui->tableView->setModel(tmpcadeau.affiche2());
    ui->comboBox->setModel(tmpcadeau.modifier_liste_id());
     ui->comboBox_Cadeau_2->setModel(tmpcadeau.modifier_liste_id());


}

void clients_cadeaux::on_pushButton_modifCa_2_clicked()
{
    QString id= ui->comboBox_Cadeau_2->currentText();
       QString categorie= ui->comboBox_3->currentText();

      int  somme=ui->lineEdit_5->text().toInt();
        int  nb=ui->lineEdit_6->text().toInt();
       Cadeau ca(id,categorie,somme,nb);
       bool test=ca.modifier2(id);
        if(test)
       {


                 QMessageBox::information(nullptr, QObject::tr("Modifier un cadeau"),
                             QObject::tr("cadeau modifié.\n"), QMessageBox::Cancel);

       }
       else
       {
           QMessageBox::critical(nullptr, QObject::tr("Modifier un cadeau"),
                             QObject::tr("Erreur de modification !\n"), QMessageBox::Cancel);
       }
}

void clients_cadeaux::on_pushButton_statCa_2_clicked()
{
    int res;
            statistiques w(this);
            w.setWindowTitle("Statistiques des cadeaux");

            res = w.exec();
            qDebug() << res;
            if (res == QDialog::Rejected)
              return;
}



void clients_cadeaux::on_comboBox_client_2_currentIndexChanged(const QString &arg1)
{
    QString mat=ui->comboBox_client_2->currentText();

    QSqlQuery q;
       q.prepare("select * from client where matricule LIKE '"+mat+"'" );

    if(q.exec())
    {
        while(q.next())
        {
            ui->lineEdit_nom_modif_2->setText(q.value(1).toString());
            ui->lineEdit_prenom_modif_2->setText(q.value(2).toString());
             ui->lineEdit_2->setText(q.value(5).toString());
           ui->lineEdit_adresse_modif_2->setText(q.value(3).toString());
             ui->lineEdit_tel_modif_2->setText(q.value(4).toString());




             if(tmpclient.tester_affectation(mat)==0)
                 ui->comboBox_affecCadeau_2->setModel(tmpclient.affecter_cadeau(mat));




        }



}
}
