#include "gesempcong.h"
#include "ui_gesempcong.h"
#include "employes.h"
#include "conges.h"
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QMessageBox>
#include <QComboBox>
#include <QSpinBox>
#include<QIntValidator>
#include<QValidator>

gesempcong::gesempcong(QWidget *parent) :
    QDialog(parent),

    ui(new Ui::gesempcong)
{
    ui->setupUi(this);
}

gesempcong::~gesempcong()
{
    delete ui;
}

void gesempcong::on_ajoutemp_clicked()
{
    QString matemp=ui->matricule ->text();
    QString congeemp="";
    QString dateemb=ui->dateemb->text();
    QString nom=ui->nom->text();
    QString prenom=ui->prenom->text();
    QString fonction=ui->fonction->text();
    float salaire=ui->salaire->text().toFloat();

    Employes E(matemp,congeemp,dateemb,nom,prenom,fonction,salaire);
    if(E.ajouter()) {
        QMessageBox::information(nullptr, QObject::tr("BRAVO!!!"),
                    QObject::tr("Ajout effectuer avec succés.\n" ), QMessageBox::Cancel);

                ui->matricule->setText("");


                ui->dateemb->setText("");
                ui->nom->setText("");
                ui->prenom->setText("");
                ui->fonction->setText("");
                ui->salaire->setText("");


}else{
        QMessageBox::information(nullptr, QObject::tr("ECHEC!!!"),
                    QObject::tr("employé existe déja.\n"), QMessageBox::Cancel);
    }

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
{
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
{

    QString matemp=ui->mmatricule->currentText();
    QString congeemp=ui->mconge->text();
    QString dateemb=ui->mdateemb->text();
    QString nom=ui->mnom->text();
    QString prenom=ui->mprenom->text();
    QString fonction=ui->mfonction->text();
     float salaire=ui->msalaire->text().toFloat();
   Employes E(matemp,congeemp,dateemb,nom,prenom,fonction,salaire);
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
{
       QString rech =ui->rechercheemp->text();
      ui->tableemp->setModel(insemployes.rechercher(rech));
}


void gesempcong::on_triemp_clicked()
{
      ui->tableemp->setModel(insemployes.tri());
}






void gesempcong::on_pushButton_ajouterconges_clicked()
{int duree=ui->duree->text().toInt();
 QString idc=ui->idc->text();
 QString type=ui->type->text();
 QString datedeb=ui->datedeb->text();
 QString datefin=ui->datefin->text();



    Conges c(duree,idc,type,datedeb,datefin);
    if(c.ajouter()) {
        QMessageBox::information(nullptr, QObject::tr("BRAVO!!!"),
                    QObject::tr("Ajout effectuer avec succés.\n" ), QMessageBox::Cancel);

        ui->idc->setText("");
        ui->duree->setText("");
            ui->type->setText("");
                ui->datedeb->setText("");
                ui->datefin->setText("");


}else{
        QMessageBox::information(nullptr, QObject::tr("ECHEC!!!"),
                    QObject::tr("congé existe déja.\n"), QMessageBox::Cancel);
    }

}

void gesempcong::on_pushButton_modifierconges_clicked()
{
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
{

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
{  QString rech =ui->edit_recherchecong->text();
    ui->tableViewconges->setModel(insconges.rechercher(rech));

}

void gesempcong::on_tricong_clicked()
{ ui->tableViewconges->setModel(insconges.tri());

}











void gesempcong::on_affecterbouton_clicked()
{

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
                    QObject::tr("non supprimé.\n"
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


           ui->msalaire->setText(query.value(1).toString());
           ui->mdateemb->setText(query.value(2).toString());
           ui->mnom->setText(query.value(3).toString());
           ui->mprenom->setText(query.value(4).toString());
           ui->mfonction->setText(query.value(5).toString());
           ui->mconge->setText(query.value(6).toString());

        }
    }else{
        QMessageBox::information(nullptr, QObject::tr("Modifier un employé"),
                    QObject::tr("erreur requete.\n"), QMessageBox::Cancel);
    }
}
