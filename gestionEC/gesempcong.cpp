#include "gesempcong.h"
#include "ui_gesempcong.h"
#include "employes.h"
#include "conges.h"
#include "smtp.h"
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QMessageBox>
#include <QComboBox>
#include <QSpinBox>
#include<QIntValidator>
#include<QValidator>
#include<QMediaPlayer>


gesempcong::gesempcong(QWidget *parent) :
    QDialog(parent),

    ui(new Ui::gesempcong)
{
    ui->setupUi(this);
    connect(ui->sendBtn, SIGNAL(clicked()),this, SLOT(sendMail()));
    connect(ui->exitBtn, SIGNAL(clicked()),this, SLOT(close()));
    connect(ui->browseBtn, SIGNAL(clicked()), this, SLOT(browse()));
    setFixedSize(990,600);  //fixe la taille de la fenêtre

    QMediaPlayer *player = new QMediaPlayer;
        player->setMedia(QUrl::fromLocalFile("../imagesQT//button.wav"));
        player->setVolume(2000);
        player->play();

      ;



}

void gesempcong::browse()
{
    files.clear();

    QFileDialog dialog(this);
    dialog.setDirectory(QDir::homePath());
    dialog.setFileMode(QFileDialog::ExistingFiles);

    if (dialog.exec())
        files = dialog.selectedFiles();

    QString fileListString;
    foreach(QString file, files)
        fileListString.append( "\"" + QFileInfo(file).fileName() + "\" " );

    ui->file->setText( fileListString );

}

void gesempcong::sendMail()
{
    Smtp* smtp = new Smtp(ui->uname->text(), ui->paswd->text(), ui->server->text(), ui->port->text().toInt());
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

    if( !files.isEmpty() )
        smtp->sendMail(ui->uname->text(), ui->rcpt->text() , ui->subject->text(),ui->msg->toPlainText(), files );
    else
        smtp->sendMail(ui->uname->text(), ui->rcpt->text() , ui->subject->text(),ui->msg->toPlainText());
}

void gesempcong::mailSent(QString status)
{
    if(status == "Message sent")
        QMessageBox::warning( 0, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );
}

gesempcong::~gesempcong()
{
    delete ui;
}

void gesempcong::on_ajoutemp_clicked()
{
    QMediaPlayer *player = new QMediaPlayer;
        player->setMedia(QUrl::fromLocalFile("../imagesQT//button.wav"));
        player->setVolume(2000);
        player->play();
          ui->matricule->setMaxLength(5);
    QString matemp=ui->matricule ->text();

    QString congeemp="";

    QString dateemb=ui->dateemb->text();
        ui->nom->setMaxLength(15);
    QString nom=ui->nom->text();
    ui->prenom->setMaxLength(15);
    QString prenom=ui->prenom->text();

    QString fonction=ui->fonction->text();


    QIntValidator *rolll=new QIntValidator(1,100);
        ui->age->setValidator(rolll);
    int age=ui->age->text().toInt();


      float salaire=ui->salaire->text().toFloat();



      if((nom!="")&&(prenom!="")&&(fonction!="")&&(age<70)&&(age>0)&&(salaire>0))

          {

    Employes E(matemp,congeemp,dateemb,nom,prenom,fonction,salaire,age);



    if(E.ajouter()) {
        QMessageBox::information(nullptr, QObject::tr("BRAVO!!!"),
                    QObject::tr("Ajout effectuer avec succés.\n" ), QMessageBox::Cancel);

                ui->matricule->setText("");



                ui->nom->setText("");
                ui->prenom->setText("");
                ui->fonction->setText("");
                ui->salaire->setText("");
                ui->age->setText("");


}else{
        QMessageBox::information(nullptr, QObject::tr("ECHEC!!!"),
                    QObject::tr("employé existe déja.\n"), QMessageBox::Cancel);
    }

      }else QMessageBox::information(nullptr, QObject::tr("controle de saisie!"),
                                        QObject::tr(" verifier la saisie.\n"), QMessageBox::Cancel);


     }



void gesempcong::on_tabWidget_employes_currentChanged(int index)
{
    ui->tableemp->setEnabled(true);
    ui->tableemp->setModel(insemployes.afficher());
    ui->mmatricule->setModel(insemployes.modifier_liste_employes());
    ui->comboBoxempsup->setModel(insemployes.modifier_liste_employes());
    ui->mmatricule_2->setModel(insemployes.modifier_liste_employes());
    ui->comboBoxconges_2->setModel(insemployes.affecter_conge());




}


void gesempcong::on_suppemp_clicked()
{  QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile("../imagesQT//button.wav"));
    player->setVolume(2000);
    player->play();
    Employes e1;
    e1.setmatemp(ui->comboBoxempsup->currentText());
    if(e1.supprimer(e1.getmatemp()))
    {
        QMessageBox::information(nullptr, QObject::tr("Supprimer un employé"),
                    QObject::tr("Suppression avec succés.\n" ), QMessageBox::Cancel);

    }
    else
    { QMessageBox::critical(nullptr, QObject::tr("Erreur!"),
                    QObject::tr("non supprimé.\n"
                                ), QMessageBox::Cancel);

    }



}

void gesempcong::on_modifemp_clicked()
{  QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile("../imagesQT//button.wav"));
    player->setVolume(2000);
    player->play();

    QString matemp=ui->mmatricule->currentText();
    QString congeemp=ui->mconge->text();
    QString dateemb=ui->mdateemb->text();
    QString nom=ui->mnom->text();
    QString prenom=ui->mprenom->text();
    QString fonction=ui->mfonction->text();

    int age=ui->mage->text().toInt();

     float salaire=ui->msalaire->text().toFloat();


   Employes E(matemp,congeemp,dateemb,nom,prenom,fonction,salaire,age);
    if(E.modifier(matemp))
    {
              QMessageBox::information(nullptr, QObject::tr("Modifier un employé"),
                          QObject::tr("employé modifie.\n"), QMessageBox::Cancel);

    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Modifier un employé"),
                          QObject::tr("Erreur !\n"), QMessageBox::Cancel);
    }
}

void gesempcong::on_pushButton_rechercheemp_clicked()
{  QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile("../imagesQT//button.wav"));
    player->setVolume(2000);
    player->play();
       QString rech =ui->rechercheemp->text();
      ui->tableemp->setModel(insemployes.rechercher(rech));
}


void gesempcong::on_triemp_clicked()
{  QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile("../imagesQT//button.wav"));
    player->setVolume(2000);
    player->play();
      ui->tableemp->setModel(insemployes.tri());
}






void gesempcong::on_pushButton_ajouterconges_clicked()
{  QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile("../imagesQT//button.wav"));
    player->setVolume(2000);
    player->play();




   int duree=ui->duree->text().toInt();


 QString idc=ui->idc->text();
 QString type=ui->type->text();



 QString datedeb= ui->datedeb->date().toString("yyyy/MM/dd");
  QString datefin= ui->datefin->date().toString("yyyy/MM/dd");

  if((duree>0)&&(datefin>datedeb)&&(idc!="")&&(type!=""))

     {

       datedeb= ui->datedeb->text();
        datefin= ui->datefin->text();

    Conges c(duree,idc,type,datedeb,datefin);
    if(c.ajouter()) {
        QMessageBox::information(nullptr, QObject::tr("BRAVO!!!"),
                    QObject::tr("Ajout effectuer avec succés.\n" ), QMessageBox::Cancel);

        ui->idc->setText("");
        ui->duree->setText("");
            ui->type->setText("");



}else{
        QMessageBox::information(nullptr, QObject::tr("ECHEC!!!"),
                    QObject::tr("congé existe déja.\n"), QMessageBox::Cancel);
    }

  }else QMessageBox::information(nullptr, QObject::tr("controle de saisie!"),
                                    QObject::tr("verifier la saisie"), QMessageBox::Cancel);


 }


void gesempcong::on_pushButton_modifierconges_clicked()
{QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile("../imagesQT//button.wav"));
    player->setVolume(2000);
    player->play();


    QString idc=ui->idcm->currentText();
    int duree=ui->dureem->text().toInt();
    QString type=ui->typem->text();
    QString datedeb=ui->datedebm->text();
    QString datefin=ui->datefinm->text();


    Conges c(duree,idc,type,datedeb,datefin);
    if(c.modifier())
    {
              QMessageBox::information(nullptr, QObject::tr("Modifier un congé"),
                          QObject::tr("congé modifie.\n"), QMessageBox::Cancel);

    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Modifier un congé"),
                          QObject::tr("Erreur !\n"), QMessageBox::Cancel);
    }

}

void gesempcong::on_pushButton_supprimerconges_clicked()
{QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile("../imagesQT//button.wav"));
    player->setVolume(2000);
    player->play();

    Conges c;
    c.setidc(ui->suppcong->currentText());
    if(c.supprimer(c.getidc()))
    {
        QMessageBox::information(nullptr, QObject::tr("Supprimer un congé"),
                    QObject::tr("Suppression avec succés.\n" ), QMessageBox::Cancel);

    }
    else
    { QMessageBox::critical(nullptr, QObject::tr("Erreur!"),
                    QObject::tr("non supprimé.\n"
                                ), QMessageBox::Cancel);

    }



}


void gesempcong::on_tabWidget_conges_currentChanged(int index)
{
    ui->tableViewconges->setEnabled(true);

    ui->tableViewconges->setModel(insconges.afficher());
    ui->idcm->setModel(insconges.modifier_liste_conges());
    ui->suppcong->setModel(insconges.modifier_liste_conges());

}


void gesempcong::on_recherchecong_clicked()
{ QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile("../imagesQT//button.wav"));
    player->setVolume(2000);
    player->play();

    QString rech =ui->edit_recherchecong->text();
    ui->tableViewconges->setModel(insconges.rechercher(rech));

}

void gesempcong::on_tricong_clicked()
{QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile("../imagesQT//button.wav"));
    player->setVolume(2000);
    player->play();

    ui->tableViewconges->setModel(insconges.tri());

}











void gesempcong::on_affecterbouton_clicked()
{QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile("../imagesQT//button.wav"));
    player->setVolume(2000);
    player->play();

    Employes e1;
    e1.setmatemp(ui->mmatricule_2->currentText());
    e1.setcongeemp(ui->comboBoxconges_2->currentText());
    if(e1.affecter(e1.getmatemp()))
    {
        QMessageBox::information(nullptr, QObject::tr("affecter un employé"),
                    QObject::tr("affectation avec succés.\n" ), QMessageBox::Cancel);

    }
    else
    { QMessageBox::critical(nullptr, QObject::tr("Erreur!"),
                    QObject::tr("non affecté.\n"
                                ), QMessageBox::Cancel);

    }


}

void gesempcong::on_mmatricule_currentIndexChanged(const QString &arg1)
{
    QString matemp=ui->mmatricule->currentText();
    QSqlQuery query=insemployes.recuperer(matemp);
    if(query.exec())
    {
        while(query.next())
        {


           ui->mdateemb->setDate(query.value(1).toDate());
           ui->mnom->setText(query.value(2).toString());
           ui->mprenom->setText(query.value(3).toString());
           ui->mfonction->setText(query.value(4).toString());
           ui->mconge->setText(query.value(5).toString());
           ui->msalaire->setText(query.value(6).toString());
           ui->mage->setText(query.value(7).toString());

        }
    }else{
        QMessageBox::information(nullptr, QObject::tr("Modifier un employé"),
                    QObject::tr("erreur requete.\n"), QMessageBox::Cancel);
    }
}

void gesempcong::on_idcm_currentIndexChanged(const QString &arg1)
{ QString idc=ui->idcm->currentText();
    QSqlQuery query=insconges.recupererc(idc);
    if(query.exec())
    {
        while(query.next())
        {
           ui->dureem->setText(query.value(1).toString());
           ui->typem->setText(query.value(2).toString());
          ui->datedebm->setDate(query.value(3).toDate());
          ui->datefinm->setDate(query.value(4).toDate());



        }
    }else{
        QMessageBox::information(nullptr, QObject::tr("Modifier un congé"),
                    QObject::tr("erreur requete.\n"), QMessageBox::Cancel);
    }

}