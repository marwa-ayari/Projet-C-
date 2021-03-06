#include "gestion_materiaux_maintenances.h"
#include "ui_gestion_materiaux_maintenances.h"
#include"materiaux.h"
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QMessageBox>
#include<QIntValidator>
#include<QValidator>
Gestion_materiaux_maintenances::Gestion_materiaux_maintenances(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Gestion_materiaux_maintenances)
{
    ui->setupUi(this);
}

Gestion_materiaux_maintenances::~Gestion_materiaux_maintenances()
{
    delete ui;
}

void Gestion_materiaux_maintenances::on_pushButton_materiel_16_clicked()
{
    QString reference= ui->lineEdit_materiel_12->text();
    QString nom= ui->lineEdit_materiel_13->text();
    QString type= ui->lineEdit_materiel_15->text();
    QString date_achat= ui->dateEdit_materiel_7->text();
    float prix=ui->lineEdit_materiel_17->text().toFloat();
    Materiaux materiel(reference,nom,type,date_achat,prix);
    if(materiel.ajouter()) {
        QMessageBox::information(nullptr, QObject::tr("Ajouter matériel"),
                    QObject::tr("Ajout Bien effectué." ), QMessageBox::Cancel);
        ui->lineEdit_materiel_12->setText("");
        ui->lineEdit_materiel_13->setText("");
        ui->lineEdit_materiel_15->setText("");
        ui->lineEdit_materiel_17->setText("");

}else{
        QMessageBox::information(nullptr, QObject::tr("Ajout matériel"),
                    QObject::tr("Echec de l'ajout . Ce matériel existe déja."), QMessageBox::Cancel);
    }

}

void Gestion_materiaux_maintenances::on_tabWidget_4_currentChanged(int index)
{
    ui->tableView_materiel_2->setEnabled(true);
    ui->tableView_materiel_2->setModel(tmpmateriel.afficher());
    ui->comboBox_materiel_1->setModel(tmpmateriel.liste_materiaux());
    ui->comboBox_materiel_2->setModel(tmpmateriel.liste_materiaux());

}


void Gestion_materiaux_maintenances::on_pushButton_materiel_17_clicked()
{
    ui->tableView_materiel_2->setModel(tmpmateriel.tri());

}

void Gestion_materiaux_maintenances::on_pushButton_materiel_13_clicked()
{
    QString recherche =ui->lineEdit_materiel->text();
    ui->tableView_materiel_2->setModel(tmpmateriel.rechercher(recherche));
}

void Gestion_materiaux_maintenances::on_pushButton_materiel_8_clicked()
{
    QString refer= ui->comboBox_materiel_2->currentText();
    if(tmpmateriel.supprimer(refer))
    {
        QMessageBox::information(nullptr, QObject::tr("Supprimer un matériel"),
                    QObject::tr("Suppression avec succés.\n" ), QMessageBox::Cancel);
        ui->comboBox_materiel_2->setModel(tmpmateriel.liste_materiaux());
    }
    else
    { QMessageBox::critical(nullptr, QObject::tr("Suppression matériel!"),
                    QObject::tr("Vous ne pouvez pas supprimer ce matériel car il est en maintenance.\n"
                                ), QMessageBox::Cancel);

    }
}

void Gestion_materiaux_maintenances::on_pushButton_materiel_5_clicked()
{
    QString reference= ui->comboBox_materiel_1->currentText();
    QString nom= ui->lineEdit_materiel_18->text();
    QString type= ui->lineEdit_materiel_19->text();
    QString date_achat= ui->dateEdit_materiel_8->text();
    float prix=ui->lineEdit_materiel_20->text().toFloat();
    Materiaux materiel(reference,nom,type,date_achat,prix);
    if(materiel.modifier())
    {
              QMessageBox::information(nullptr, QObject::tr("Modifier un matériel"),
                          QObject::tr("Modification effectuée avec succées.\n"), QMessageBox::Cancel);

    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Modifier un matériel"),
                          QObject::tr("Echec ,les champs ne sont pas bien remplis!\n"), QMessageBox::Cancel);
    }
}
