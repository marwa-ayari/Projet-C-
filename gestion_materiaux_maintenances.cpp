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

}
