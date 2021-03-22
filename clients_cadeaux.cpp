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
#include <QMediaPlayer>
#include <QSound>
#include <QPropertyAnimation>
#include<QIntValidator>
#include<QValidator>
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
{ QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile("C:/images_projets/button.mp3"));
    player->setVolume(2000);
    player->play();
    ui->pushButton_ajouterCl_2->setStyleSheet(QString::fromUtf8("background-color: #de1c58;"));

    QString nom= ui->lineEdit_nom_ajout_2->text();

    QString prenom= ui->lineEdit_prenom_ajout_2->text();

    QString adresse= ui->lineEdit_adresse_ajout_2->text();

    QString tel= ui->lineEdit_tel_ajout_2->text();
   ui->lineEdit_tel_ajout_2->setMaxLength(7);
      int pts=0;
      QString matricule= ui->lineEdit_cin_ajout_2->text();
      QString id_cadeau="";
    Client a(matricule,nom,prenom,adresse,tel,pts,id_cadeau);
    bool test=a.ajouter1();
    if(test)
  {

  QMessageBox::information(nullptr, QObject::tr("Ajouter un client"),
  QObject::tr("Client ajouté.\nClick Cancel to exit."), QMessageBox::Cancel);
  ui->lineEdit_adresse_ajout_2->setText("");


                  ui->lineEdit_tel_ajout_2->setText("");
                  ui->lineEdit_cin_ajout_2->setText("");
                  ui->lineEdit_nom_ajout_2->setText("");
                  ui->lineEdit_prenom_ajout_2->setText("");


  }
    else
        QMessageBox::critical(nullptr, QObject::tr("Ajouter un client "),
                    QObject::tr("Cin existe déjà !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);




}


void clients_cadeaux::on_pushButton_suppCl_2_clicked()
{ QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile("C:/images_projets/button.mp3"));
    player->setVolume(2000);
    player->play();
  ui->pushButton_suppCl_2->setStyleSheet(QString::fromUtf8("background-color: #de1c58;"));
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
{ QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile("C:/images_projets/button.mp3"));
    player->setVolume(2000);
    player->play();
ui->pushButton_modifCl_2->setStyleSheet(QString::fromUtf8("background-color: #de1c58;"));
    QString matricule= ui->comboBox_client_2->currentText();
       QString nom= ui->lineEdit_nom_modif_2->text();
       QString prenom= ui->lineEdit_prenom_modif_2->text();
       QString adresse= ui->lineEdit_adresse_modif_2->text();
      QString  tel=ui->lineEdit_tel_modif_2->text();
        int  pts=ui->lineEdit_2->text().toInt();


       Client a(matricule,nom,prenom,adresse,tel,pts);
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
{ QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile("C:/images_projets/button.mp3"));
    player->setVolume(2000);
    player->play();
     ui->tableView_2->setModel(tmpclient.afficher1());
     ui->comboBox_suppCl_2->setModel(tmpclient.modifier_liste_matricule());
      ui->comboBox_client_2->setModel(tmpclient.modifier_liste_matricule());

 ui->comboBox_Matclient->setModel(tmpclient.modifier_liste_matricule());
 setStyleSheet(" QPushButton {"
               "border-radius: 5px; "
               "border: 1.5px solid rgb(91,231,255); "
               "background-color: red; }"
               "QPushButton:pressed {"
               "border: 1.4px solid rgb(73,186,205); }"
               "QPushButton:hover {"
               "font-size: 16px;"
               "transition: 0.9s; }");
}

void clients_cadeaux::on_pushButton_triCl_2_clicked()
{ QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile("C:/images_projets/button.mp3"));
    player->setVolume(2000);
    player->play();
    ui->pushButton_triCl_2->setStyleSheet(QString::fromUtf8("background-color: #de1c58;"));
     ui->tableView_2->setModel(tmpclient.tri_DESC());
}

void clients_cadeaux::on_pushButton_rechCl_3_clicked()
{ QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile("C:/images_projets/button.mp3"));
    player->setVolume(2000);
    player->play();
       ui->pushButton_rechCl_3->setStyleSheet(QString::fromUtf8("background-color: #de1c58;"));
    QString nom_client =ui->lineEdit_rech_nom->text();
      ui->tableView_2->setModel(tmpclient.recherche1(nom_client));
}




void clients_cadeaux::on_pushButton_suppCa_2_clicked()
{ QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile("C:/images_projets/button.mp3"));
    player->setVolume(2000);
    player->play();
       ui->pushButton_suppCa_2->setStyleSheet(QString::fromUtf8("background-color: #ffff00;"));
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
{ QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile("C:/images_projets/button.mp3"));
    player->setVolume(2000);
    player->play();
       ui->pushButton_triCa_2->setStyleSheet(QString::fromUtf8("background-color: #ffff00;"));
     ui->tableView->setModel(tmpcadeau.tri2());
}

void clients_cadeaux::on_pushButton_rechCa_2_clicked()
{ QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile("C:/images_projets/button.mp3"));
    player->setVolume(2000);
    player->play();
     ui->pushButton_rechCa_2->setStyleSheet(QString::fromUtf8("background-color: #ffff00;"));
    QString categorie =ui->lineEdit->text();
      ui->tableView->setModel(tmpcadeau.recherche2(categorie));
}

void clients_cadeaux::on_tabWidget_4_currentChanged(int index)
{QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile("C:/images_projets/button.mp3"));
    player->setVolume(2000);
    player->play();
    ui->tableView->setModel(tmpcadeau.affiche2());
    ui->comboBox->setModel(tmpcadeau.modifier_liste_id());
     ui->comboBox_Cadeau_2->setModel(tmpcadeau.modifier_liste_id());
     setStyleSheet(" QPushButton {"
                   "border-radius: 5px; "
                   "border: 1.5px solid rgb(91,231,255); "
                   "background-color: red; }"
                   "QPushButton:pressed {"
                   "border: 1.4px solid rgb(73,186,205); }"
                   "QPushButton:hover {"
                   "font-size: 16px;"
                   "transition: 0.9s; }");

}

void clients_cadeaux::on_pushButton_modifCa_2_clicked()
{ QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile("C:/images_projets/button.mp3"));
    player->setVolume(2000);
    player->play();
 ui->pushButton_modifCa_2->setStyleSheet(QString::fromUtf8("background-color: #ffff00;"));
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
{ QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile("C:/images_projets/button.mp3"));
    player->setVolume(2000);
    player->play();
     ui->pushButton_statCa_2->setStyleSheet(QString::fromUtf8("background-color: #ffff00;"));
    int res;
            statistiques w(this);
            w.setWindowTitle("Statistiques des cadeaux");

            res = w.exec();
            qDebug() << res;
            if (res == QDialog::Rejected)
              return;
}



void clients_cadeaux::on_comboBox_client_2_currentIndexChanged(const QString &arg1)
{ QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile("C:/images_projets/button.mp3"));
    player->setVolume(2000);
    player->play();
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







        }



}
}

void clients_cadeaux::on_comboBox_Matclient_currentIndexChanged(const QString &arg1)
{ QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile("C:/images_projets/button.mp3"));
    player->setVolume(2000);
    player->play();
    QString mat=ui->comboBox_Matclient->currentText();

    QSqlQuery q;
       q.prepare("select * from client where matricule LIKE '"+mat+"'" );

    if(q.exec())
    {
        while(q.next())
        {

                ui->comboBox_affecCadeau_2->setModel(tmpclient.affecter_cadeau(mat));



        }
}
}
void clients_cadeaux::on_pushButton_modifCl_3_clicked()
{ QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile("C:/images_projets/button.mp3"));
    player->setVolume(2000);
    player->play();
     ui->pushButton_modifCl_3->setStyleSheet(QString::fromUtf8("background-color: #de1c58;"));
   QString id= ui->comboBox_Matclient->currentText();
    QString  id_cadeau=ui->comboBox_affecCadeau_2->currentText();
int aff=tmpclient.tester_affectation(id);
   Client a(id_cadeau);
Cadeau ca;
Client ca2;
   bool test=a.modifier2(id);
    if(test)
   { if (aff==0)
        {

bool test_mis_a_jour_nb=ca.mettre_a_jour_nb_exp(id_cadeau);
bool test_mis_a_jour_pt=ca2.mettre_a_jour_pts(id,id_cadeau);
if(test_mis_a_jour_pt&&test_mis_a_jour_nb)
{QMessageBox::information(nullptr, QObject::tr("affecter cadeau "),
                          QObject::tr("cadeau affecté et mise à jour en cours.\n"), QMessageBox::Cancel);

        }
else
{ QMessageBox::critical(nullptr, QObject::tr("affecter un cadeau"),
                        QObject::tr("pas de mise à jour  !\n"), QMessageBox::Cancel);

        }
        }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("affecter un cadeau"),
                              QObject::tr("Le client sélectionné a déjà gangé un cadeau !\n"), QMessageBox::Cancel);
}

    }
   else
   {
       QMessageBox::critical(nullptr, QObject::tr("affecter un cadeau"),
                         QObject::tr("Erreur d'affectation !\n"), QMessageBox::Cancel);
   }


}
void clients_cadeaux::on_comboBox_Cadeau_2_currentIndexChanged(const QString &arg1)
{ QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile("C:/images_projets/button.mp3"));
    player->setVolume(2000);
    player->play();
    QString id=ui->comboBox_Cadeau_2->currentText();

    QSqlQuery q;
       q.prepare("select * from cadeau where id LIKE '"+id+"'" );

    if(q.exec())
    {
        while(q.next())
        {
            ui->lineEdit_5->setText(q.value(2).toString());
            ui->lineEdit_6->setText(q.value(3).toString());
            ui->comboBox_3->setCurrentText(q.value(1).toString());




        }



}
}

void clients_cadeaux::on_pushButton_triCl_3_clicked()
{
    QMediaPlayer *player = new QMediaPlayer;
        player->setMedia(QUrl::fromLocalFile("C:/images_projets/button.mp3"));
        player->setVolume(2000);
        player->play();
         ui->pushButton_triCl_3->setStyleSheet(QString::fromUtf8("background-color: #de1c58;"));
         ui->tableView_2->setModel(tmpclient.tri_ASC());
}

void clients_cadeaux::on_pushButton_ajouterCa_3_clicked()
{
    QMediaPlayer *player = new QMediaPlayer;
        player->setMedia(QUrl::fromLocalFile("C:/images_projets/button.mp3"));
        player->setVolume(2000);
        player->play();
        ui->pushButton_ajouterCa_3->setStyleSheet(QString::fromUtf8("background-color: #ffff00;"));
        QString categorie=ui->comboBox_2->currentText();
        QString id= ui->lineEdit_categ_ajout_2->text();
          int somme= ui->lineEdit_3->text().toInt();
          QIntValidator *roll=new QIntValidator(20,10000);

               ui->lineEdit_3->setValidator(roll);


          int nb= ui->lineEdit_4->text().toInt();
        Cadeau ca(id,categorie,somme,nb);
        bool test=ca.ajouter2();
        if(test)
      {

      QMessageBox::information(nullptr, QObject::tr("Ajouter un cadeau"),
      QObject::tr("Cadeau ajouté.\nClick Cancel to exit."), QMessageBox::Cancel);
      ui->lineEdit_categ_ajout_2->setText("");


                      ui->lineEdit_3->setText("");
                      ui->lineEdit_4->setText("");


      }
        else
            QMessageBox::critical(nullptr, QObject::tr("Ajouter un cadeau "),
                        QObject::tr("Cadeau existe déjà !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);


}
