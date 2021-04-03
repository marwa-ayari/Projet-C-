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
    ui->comboBox_2->addItem("Bon d'achat");
    ui->comboBox_2->addItem("Accessoires cuisine");
    ui->comboBox_3->addItem("Chocolat");
    ui->comboBox_3->addItem("Bon d'achat");
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
  

    QString nom= ui->lineEdit_nom_ajout_2->text();

    QString prenom= ui->lineEdit_prenom_ajout_2->text();

    QString adresse= ui->lineEdit_adresse_ajout_2->text();
     QString tel= ui->lineEdit_tel_ajout_2->text();
 ui->lineEdit_tel_ajout_2->setMaxLength(8);

      int pts=0;
      QString matricule= ui->lineEdit_cin_ajout_2->text();
      QString id_cadeau="";
    Client a(matricule,nom,prenom,adresse,tel,pts,id_cadeau);
    if((nom=="")&&(prenom=="")&&(adresse=="")&&(matricule=="")&&(tel==""))
    {
        QMessageBox::critical(nullptr, QObject::tr("WARNING"),
                    QObject::tr("Tous les champs sont vides"), QMessageBox::Ok);
     }
    else if(matricule =="")
       {
           QMessageBox::critical(nullptr, QObject::tr("WARNING"),
                       QObject::tr("matricule vide"), QMessageBox::Ok);

       }
    else if(nom =="")
       {
           QMessageBox::critical(nullptr, QObject::tr("WARNING"),
                       QObject::tr("nom vide"), QMessageBox::Ok);

       }
    else if(prenom =="")
       {
           QMessageBox::critical(nullptr, QObject::tr("WARNING"),
                       QObject::tr("prenom vide"), QMessageBox::Ok);

       }
    else if(adresse =="")
       {
           QMessageBox::critical(nullptr, QObject::tr("WARNING"),
                       QObject::tr("adresse vide"), QMessageBox::Ok);

       }

    else if(tel =="")
       {
           QMessageBox::critical(nullptr, QObject::tr("WARNING"),
                       QObject::tr("Télephone vide"), QMessageBox::Ok);

       }

else if(nom.contains(QRegExp("^[A-Za-z]+$"))==false)
{
   QMessageBox::critical(nullptr, QObject::tr("WARNING"),
               QObject::tr("faut nom"), QMessageBox::Ok);

}
    else if(prenom.contains(QRegExp("^[A-Za-z]+$"))==false)
    {
       QMessageBox::critical(nullptr, QObject::tr("WARNING"),
                   QObject::tr("faut prenom"), QMessageBox::Ok);

    }
    else if(tel.contains(QRegExp("^[0-9]+$"))==false)
    {
       QMessageBox::critical(nullptr, QObject::tr("WARNING"),
                   QObject::tr("le numéro de téléphone doit se composer par des chiffres seulement"), QMessageBox::Ok);

    }
    else if (tel.size()!=8)
{
   QMessageBox::critical(nullptr, QObject::tr("WARNING"),
               QObject::tr("le numéro de téléphone doit se composer par 8 chiffres"), QMessageBox::Ok);

}
    else
    {
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
                    QObject::tr("client existe déjà !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}
}


void clients_cadeaux::on_pushButton_suppCl_2_clicked()
{ QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile("C:/images_projets/button.mp3"));
    player->setVolume(2000);
    player->play();
 
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
  
    QString matricule= ui->comboBox_client_2->currentText();
       QString nom= ui->lineEdit_nom_modif_2->text();
       QString prenom= ui->lineEdit_prenom_modif_2->text();
       QString adresse= ui->lineEdit_adresse_modif_2->text();
      QString  tel=ui->lineEdit_tel_modif_2->text();
        int  pts=ui->lineEdit_2->text().toInt();


       Client a(matricule,nom,prenom,adresse,tel,pts);
       if((nom=="")&&(prenom=="")&&(adresse=="")&&(tel==""))
       {
           QMessageBox::critical(nullptr, QObject::tr("WARNING"),
                       QObject::tr("Tous les champs sont vides"), QMessageBox::Ok);
        }

       else if(nom =="")
          {
              QMessageBox::critical(nullptr, QObject::tr("WARNING"),
                          QObject::tr("nom vide"), QMessageBox::Ok);

          }
       else if(prenom =="")
          {
              QMessageBox::critical(nullptr, QObject::tr("WARNING"),
                          QObject::tr("prenom vide"), QMessageBox::Ok);

          }
       else if(adresse =="")
          {
              QMessageBox::critical(nullptr, QObject::tr("WARNING"),
                          QObject::tr("adresse vide"), QMessageBox::Ok);

          }

       else if(tel =="")
          {
              QMessageBox::critical(nullptr, QObject::tr("WARNING"),
                          QObject::tr("Télephone vide"), QMessageBox::Ok);

          }

   else if(nom.contains(QRegExp("^[A-Za-z]+$"))==false)
   {
      QMessageBox::critical(nullptr, QObject::tr("WARNING"),
                  QObject::tr("faut nom"), QMessageBox::Ok);

   }
       else if(prenom.contains(QRegExp("^[A-Za-z]+$"))==false)
       {
          QMessageBox::critical(nullptr, QObject::tr("WARNING"),
                      QObject::tr("faut prenom"), QMessageBox::Ok);

       }
       else if(tel.contains(QRegExp("^[0-9]+$"))==false)
       {
          QMessageBox::critical(nullptr, QObject::tr("WARNING"),
                      QObject::tr("le numéro de téléphone doit se composer par des chiffres seulement"), QMessageBox::Ok);

       }
       else if (tel.size()!=8)
   {
      QMessageBox::critical(nullptr, QObject::tr("WARNING"),
                  QObject::tr("le numéro de téléphone doit se composer par 8 chiffres"), QMessageBox::Ok);

   }
       else
       {
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



}









void clients_cadeaux::on_tabWidget_2_currentChanged(int index)
{ QMediaPlayer *player = new QMediaPlayer;

     ui->tableView_2->setModel(tmpclient.afficher1());
     ui->comboBox_suppCl_2->setModel(tmpclient.modifier_liste_matricule());
      ui->comboBox_client_2->setModel(tmpclient.modifier_liste_matricule());

 ui->comboBox_Matclient->setModel(tmpclient.modifier_liste_matricule());
 }

void clients_cadeaux::on_pushButton_triCl_2_clicked()
{ QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile("C:/images_projets/button.mp3"));
    player->setVolume(2000);
    player->play();
  
     ui->tableView_2->setModel(tmpclient.tri_DESC());
}

void clients_cadeaux::on_pushButton_rechCl_3_clicked()
{ QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile("C:/images_projets/button.mp3"));
    player->setVolume(2000);
    player->play();
    
    QString nom_client =ui->lineEdit_rech_nom->text();
      ui->tableView_2->setModel(tmpclient.recherche1(nom_client));
}




void clients_cadeaux::on_pushButton_suppCa_2_clicked()
{ QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile("C:/images_projets/button.mp3"));
    player->setVolume(2000);
    player->play();
      
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
   
     ui->tableView->setModel(tmpcadeau.tri2());
}

void clients_cadeaux::on_pushButton_rechCa_2_clicked()
{ QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile("C:/images_projets/button.mp3"));
    player->setVolume(2000);
    player->play();
   
    QString categorie =ui->lineEdit->text();
      ui->tableView->setModel(tmpcadeau.recherche2(categorie));
}

void clients_cadeaux::on_tabWidget_4_currentChanged(int index)
{QMediaPlayer *player = new QMediaPlayer;

    ui->tableView->setModel(tmpcadeau.affiche2());
    ui->comboBox->setModel(tmpcadeau.modifier_liste_id());
     ui->comboBox_Cadeau_2->setModel(tmpcadeau.modifier_liste_id());
 
}

void clients_cadeaux::on_pushButton_modifCa_2_clicked()
{ QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile("C:/images_projets/button.mp3"));
    player->setVolume(2000);
    player->play();
 
    QString id= ui->comboBox_Cadeau_2->currentText();
       QString categorie= ui->comboBox_3->currentText();

      int  somme=ui->lineEdit_5->text().toInt();
        int  nb=ui->lineEdit_6->text().toInt();
       Cadeau ca(id,categorie,somme,nb);



             if(somme<20||somme>10000)
          {
              QMessageBox::critical(nullptr, QObject::tr("WARNING"),
                          QObject::tr("La somme doit etre entre 20 et 10000 points"), QMessageBox::Ok);

          }
       else if(nb==0)
       {
           QMessageBox::critical(nullptr, QObject::tr("WARNING"),
                       QObject::tr("le nombre d'exemplaires ne doit pas etre nul"), QMessageBox::Ok);
       }

       else
       {
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
}

void clients_cadeaux::on_pushButton_statCa_2_clicked()
{ QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile("C:/images_projets/button.mp3"));
    player->setVolume(2000);
    player->play();
  
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
     
         ui->tableView_2->setModel(tmpclient.tri_ASC());
}

void clients_cadeaux::on_pushButton_ajouterCa_3_clicked()
{
    QMediaPlayer *player = new QMediaPlayer;
        player->setMedia(QUrl::fromLocalFile("C:/images_projets/button.mp3"));
        player->setVolume(2000);
        player->play();
     
        QString categorie=ui->comboBox_2->currentText();
        QString id= ui->lineEdit_categ_ajout_2->text();
          int somme= ui->lineEdit_3->text().toInt();
          QIntValidator *roll=new QIntValidator(20,10000);

               ui->lineEdit_3->setValidator(roll);


          int nb= ui->lineEdit_4->text().toInt();
        Cadeau ca(id,categorie,somme,nb);

       if(id=="")
        {
            QMessageBox::critical(nullptr, QObject::tr("WARNING"),
                        QObject::tr("id vide"), QMessageBox::Ok);
        }
        else if(id.contains(QRegExp("^[A-Za-z-0-9]+-ch"))==false)
        {
            QMessageBox::critical(nullptr, QObject::tr("WARNING"),
                        QObject::tr("id nom valide"), QMessageBox::Ok);
        }
                else if(somme<20||somme>10000)
           {
               QMessageBox::critical(nullptr, QObject::tr("WARNING"),
                           QObject::tr("La somme doit etre entre 20 et 10000 points"), QMessageBox::Ok);

           }
        else if(nb==0)
        {
            QMessageBox::critical(nullptr, QObject::tr("WARNING"),
                        QObject::tr("le nombre d'exemplaires ne doit pas etre nul"), QMessageBox::Ok);
        }

        else
        {
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
}

void clients_cadeaux::on_comboBox_affecCadeau_2_currentIndexChanged(const QString &arg1)
{

     QString id=ui->comboBox_affecCadeau_2->currentText();
 ui->comboBox_categorie->setModel(tmpcadeau.chercher_categ(id));
 QString categorie=ui->comboBox_categorie->currentText();

      QImage image(tr("C:/images_projets/choc.jpg"));
      QImage image1(tr("C:/images_projets/Cheques-Cadeaux.png"));
       QImage image2(tr("C:/images_projets/acc.jpg"));
     if(categorie=="Chocolat")
     {

         ui->label_2->setPixmap(QPixmap::fromImage(image));
     }
     else if (categorie=="Bon d'achat")
     {

         ui->label_2->setPixmap(QPixmap::fromImage(image1));
     }
     else if (categorie=="Accessoires cuisine")
     {

         ui->label_2->setPixmap(QPixmap::fromImage(image2));
   }
     else
     {
//rien
     }

}
