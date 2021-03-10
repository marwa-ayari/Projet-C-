#include "gesempcong.h"
#include "ui_gesempcong.h"
#include "employes.h"
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QMessageBox>
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
    int matemp=ui->matricule ->text().toInt();
    float salaire=ui->salaire->text().toFloat();
    QString dateemb=ui->dateemb->text();
    QString nom=ui->nom->text();
    QString prenom=ui->prenom->text();
    QString fonction=ui->fonction->text();

    Employes E(matemp,salaire,dateemb,nom,prenom,fonction);
    if(E.ajouter()) {
        QMessageBox::information(nullptr, QObject::tr("BRAVO!!!"),
                    QObject::tr("Ajout effectuer avec succés.\n" ), QMessageBox::Cancel);

        ui->matricule->setText("");
        ui->salaire->setText("");
        ui->dateemb->setText("");
                ui->nom->setText("");
                ui->prenom->setText("");
                ui->fonction->setText("");


}else{
        QMessageBox::information(nullptr, QObject::tr("ECHEC!!!"),
                    QObject::tr("employé existe déja.\n"), QMessageBox::Cancel);
    }

}



void gesempcong::on_tabWidget_employes_currentChanged(int index)
{
    ui->tableemp->setEnabled(true);
    ui->tableemp->setModel(insemployes.afficher());


}


void gesempcong::on_suppemp_clicked()
{
    Employes e1;
    e1.setmatemp(ui->comboBox_employes_sup->text().toInt());
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

    int matemp=ui->mmatricule ->text().toInt();
    float salaire=ui->msalaire->text().toFloat();
    QString dateemb=ui->mdateemb->text();
    QString nom=ui->mnom->text();
    QString prenom=ui->mprenom->text();
    QString fonction=ui->mfonction->text();
   Employes E(matemp,salaire,dateemb,nom,prenom,fonction);
    if(E.modifier())
    {
              QMessageBox::information(nullptr, QObject::tr("Modifier un employé"),
                          QObject::tr("employé modifie.\n"), QMessageBox::Cancel);

    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Modifier une employé"),
                          QObject::tr("Erreur !\n"), QMessageBox::Cancel);
    }
}




