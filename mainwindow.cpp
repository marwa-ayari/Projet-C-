#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "categories.h"
#include"reclamations.h"
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QMessageBox>

#include<QIntValidator>
#include<QValidator>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}
MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_categorie_4_clicked()
{
    QString nom= ui->lineEdit_categorie_12->text();
    QString date_fab= ui->dateEdit_categorie_7->text();
    float prix=ui->lineEdit_categorie_13->text().toFloat();
    Categories catg(nom,date_fab,prix);
    if(catg.ajouter()) {
        QMessageBox::information(nullptr, QObject::tr("BRAVO!!!"),
                    QObject::tr("Ajout effectuer avec succés.\n" ), QMessageBox::Cancel);
        ui->lineEdit_categorie_12->setText("");
        ui->lineEdit_categorie_13->setText("");

}else{
        QMessageBox::information(nullptr, QObject::tr("ECHEC!!!"),
                    QObject::tr("Cette catégorie existe déja.\n"), QMessageBox::Cancel);
    }

}


void MainWindow::on_pushButton_categorie_6_clicked()
{
    QString nom= ui->comboBox_categorie_sup->currentText();
    if(tmpcategorie.supprimer(nom))
    {
        QMessageBox::information(nullptr, QObject::tr("Supprimer une categorie"),
                    QObject::tr("Suppression avec succés.\n" ), QMessageBox::Cancel);
        ui->comboBox_categorie_sup->setModel(tmpcategorie.modifier_aff_id());
    }
    else
    { QMessageBox::critical(nullptr, QObject::tr("Erreur!"),
                    QObject::tr("Cette catégorie est affectée à une ou plusieurs réclamations,\n Veuillez supprimer les réclamations qui la concerne avant.\n"
                                ), QMessageBox::Cancel);

    }
}

void MainWindow::on_tabWidget_categorie_4_currentChanged(int index)
{
    ui->tab_categorie->setEnabled(true);
    ui->tab_categorie->setModel(tmpcategorie.afficher());
    ui->comboBox_categorie_modifi->setModel(tmpcategorie.modifier_aff_id());
    ui->comboBox_categorie_sup->setModel(tmpcategorie.modifier_aff_id());

}

void MainWindow::on_pushButton_categorie_13_clicked()
{
    QString rech =ui->lineEdit_categorie_17->text();
    ui->tab_categorie->setModel(tmpcategorie.rechercher(rech));
}


void MainWindow::on_pushButton_categorie_14_clicked()
{
    ui->tab_categorie->setModel(tmpcategorie.tri());
}
void MainWindow::on_comboBox_categorie_modifi_currentIndexChanged(const QString &arg1)
{
    QString nom=ui->comboBox_categorie_modifi->currentText();
    QSqlQuery query;
    query.prepare("select * from categories where nom_categorie='"+nom+"'");
    if(query.exec())
    {
        while(query.next())
        {
            ui->lineEdit_categorie_5->setText(query.value(2).toString());
            ui->dateEdit_categorie_2->setDate(query.value(1).toDate());
        }
    }else{
        QMessageBox::information(nullptr, QObject::tr("Modifier une catégorie"),
                    QObject::tr("erreur requete.\n"), QMessageBox::Cancel);
    }

}

void MainWindow::on_pushButton_categorie_7_clicked()
{
    QString nom= ui->comboBox_categorie_modifi->currentText();
    QString date_fab= ui->dateEdit_categorie_2->text();
    float prix=ui->lineEdit_categorie_5->text().toFloat();
    Categories catg(nom,date_fab,prix);
    if(catg.modifier())
    {
              QMessageBox::information(nullptr, QObject::tr("Modifier une catégorie"),
                          QObject::tr("Catégorie modifiée.\n"), QMessageBox::Cancel);

    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Modifier une catégorie"),
                          QObject::tr("Erreur !\n"), QMessageBox::Cancel);
    }
}

void MainWindow::on_bouton_ajout_reclamation_clicked()
{
    QString nom_categ= ui->comboBox_reclamation_1->currentText();
    QString id= ui->comboBox_reclamation_2->currentText();
    QString avis_c= ui->avis_reclamation->text();
    QString date_rec= ui->date_reclamation->text();
    reclamations rec(nom_categ,id,date_rec,avis_c);
    if(rec.ajouter()) {
        QMessageBox::information(nullptr, QObject::tr("BRAVO!!!"),
                    QObject::tr("Ajout effectuer avec succés.\n"), QMessageBox::Cancel);
        ui->avis_reclamation->setText("");

    } else
    {
        QMessageBox::information(nullptr, QObject::tr("ECHEC!!!"),
                    QObject::tr("Cette réclamation existe déja.\n"), QMessageBox::Cancel);
    }

}

void MainWindow::on_tabWidget_reclamation_3_currentChanged(int index)
{
    ui->tab_reclamation->setEnabled(true);
    ui->tab_reclamation->setModel(tmpreclamation.afficher());
    ui->comboBox_reclamation_1->setModel(tmpreclamation.affecter_Categorie());
    ui->comboBox_reclamation_2->setModel(tmpreclamation.affecter_Client());
    ui->comboBox_reclamation_3->setModel(tmpreclamation.affecter_Categorie());
    ui->comboBox_reclamation_4->setModel(tmpreclamation.affecter_Client());
    ui->comboBox_reclamation_5->setModel(tmpreclamation.affecter_Categorie());
    ui->comboBox_reclamation_6->setModel(tmpreclamation.affecter_Client());
}

void MainWindow::on_pushButton_3_clicked()
{
    QString nom= ui->comboBox_reclamation_5->currentText();
    QString id=ui->comboBox_reclamation_6->currentText();
    if(tmpreclamation.supprimer(nom,id))
    {
        QMessageBox::information(nullptr, QObject::tr("Supprimer une réclamation"),
                    QObject::tr("Suppression avec succés.\n"), QMessageBox::Cancel);
    }
    else
    { QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                    QObject::tr("Cette réclamation n'existe plus.\n"), QMessageBox::Cancel);

    }
}

void MainWindow::on_pushButton_11_clicked()
{
    QString rech =ui->rech_reclamation->text();
    ui->tab_reclamation->setModel(tmpreclamation.rechercher(rech));
}

void MainWindow::on_pushButton_12_clicked()
{
    ui->tab_reclamation->setModel(tmpreclamation.tri());
}






void MainWindow::on_comboBox_reclamation_3_currentIndexChanged(const QString &arg1)
{
    QString nom=ui->comboBox_reclamation_3->currentText();
    QString id=ui->comboBox_reclamation_4->currentText();
    QSqlQuery query;
    query.prepare("select * from reclamations where (nom_categorie='"+nom+"' and id_client='"+id+"') ");
    if(query.exec())
    {
        while(query.next())
        {
            ui->LineEdit_reclamation_3->setText(query.value(3).toString());
            ui->dateEdit_reclamation_2->setDate(query.value(2).toDate());
        }
    }else{
        QMessageBox::information(nullptr, QObject::tr("Modifier une réclamation"),
                    QObject::tr("erreur requete.\n"), QMessageBox::Cancel);
    }

}

void MainWindow::on_pushButton_2_clicked()
{
    QString nom= ui->comboBox_reclamation_3->currentText();
    QString id_client= ui->comboBox_reclamation_4->currentText();
    QString avis= ui->LineEdit_reclamation_3->text();
    QString date_rec= ui->dateEdit_reclamation_2->text();
    reclamations rec(nom,id_client,date_rec,avis);
    if(rec.modifier())
    {
              QMessageBox::information(nullptr, QObject::tr("Modifier une réclamation"),
                          QObject::tr("Réclamtion modifié.\n"), QMessageBox::Cancel);

    }
else
    {
        QMessageBox::critical(nullptr, QObject::tr("Erreur !"),
                          QObject::tr("Cette réclamation n'existe pas.\nVeuillez vérifier le nom de catégorie et le id client."), QMessageBox::Cancel);
    }
}
