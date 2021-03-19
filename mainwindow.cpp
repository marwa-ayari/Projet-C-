#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QApplication>
#include <QMessageBox>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
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


void MainWindow::on_toolButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);

}

void MainWindow::on_affficherp_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    ui->produit_2->setModel(tabproduit.afficherp());

}

void MainWindow::on_pushButton_3_clicked()//trie
{
    ui->fournisseurtable->setModel(tabfour.trief());
}



void MainWindow::on_mofidifierp_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    QString ref=ui->idmodif->currentText();
    QSqlQueryModel *mod= new QSqlQueryModel();
    mod->setQuery("select REF from PRODUIT ");
    ui->idmodif->setModel(mod);
    QSqlQuery q;
    q.prepare("select * from PRODUIT where REF = '"+ref+"'");
    if(q.exec())
    {
        while(q.next())
        {
            ui->lineEdit_5->setText(q.value(1).toString());
            ui->lineEdit_6->setText(q.value(2).toString());
            ui->lineEdit_7->setText(q.value(3).toString());
            ui->comboBox_4->setCurrentText(q.value(4).toString());
        }
    }


}

void MainWindow::on_supprimerp_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    ui->tableView->setModel(tabproduit.afficherp());
    QSqlQueryModel *mod= new QSqlQueryModel();
    mod->setQuery("select REF from PRODUIT ");
    ui->comboBox->setModel(mod);
}

void MainWindow::on_pushButton_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);

}

void MainWindow::on_ajouterp_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
    ui->comboBox_2->setModel(tabproduit.affecter_fournisseur());

}

void MainWindow::on_toolButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);

}

void MainWindow::on_retourfromaf_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);

}

void MainWindow::on_ajout_clicked()
{
    QString ref=ui->lineEdit_ref->text();
    QString nom=ui->lineEdit_nom->text();
    int prix=ui->lineEdit_prix->text().toInt();
    int stock=ui->lineEdit_stock->text().toInt();
    int x=0;
    QString m_f=ui->comboBox_2->currentText();

    string str_prix=to_string(prix);

    string str_stock= to_string(stock);
    if(ref=="")
    {
        QMessageBox::critical(nullptr, QObject::tr("WARNING"),
                    QObject::tr("la refernce est vide"), QMessageBox::Ok);
              x++;
    }
    else if(nom=="")
    {
        QMessageBox::critical(nullptr, QObject::tr("WARNING"),
                    QObject::tr("la nom est vide"), QMessageBox::Ok);
              x++;
    }
    else if(x==0)
    {
        produit p(ref,nom,m_f,stock,prix);
        bool t=p.ajouterp();
        if(t)
        {
            QMessageBox::information(nullptr, QObject::tr("produit ajouter"),
                              QObject::tr("base de données mise à jour"), QMessageBox::Ok);
            ui->lineEdit_ref->clear();
            ui->lineEdit_nom->clear();
            ui->lineEdit_prix->clear();
            ui->lineEdit_stock->clear();
            ui->stackedWidget->setCurrentIndex(4);
        }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("WARNING"),
                        QObject::tr("Veuillez réessayer"), QMessageBox::Ok);

        }
    }
}

void MainWindow::on_supp_clicked()
{
    int ref=ui->comboBox->currentText().toInt();
    if(tabproduit.supprmierp(ref))
    {
        QMessageBox::information(nullptr, QObject::tr("produit supprimer"),
                          QObject::tr("base de données mise à jour"), QMessageBox::Ok);
        ui->stackedWidget->setCurrentIndex(1);

    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("WARNING"),
                    QObject::tr("Veuillez réessayer"), QMessageBox::Ok);
    }
}

void MainWindow::on_produit_2_activated(const QModelIndex &index)
{
    QString val=ui->produit_2->model()->data(index).toString();
    QSqlQuery q;
    q.prepare("SELECT * FROM PRODUIT WHERE REF = '"+val+"' OR NOM = '"+val+"' OR STOCK = '"+val+"' OR PRIX = '"+val+"' ");
    if(q.exec())
    {
        while(q.next())
        {   QSqlQueryModel *mod= new QSqlQueryModel();
            mod->setQuery("select REF from PRODUIT WHERE REF ='"+val+"' ");
            ui->idmodif->setModel(mod);
            ui->stackedWidget->setCurrentIndex(2);
            ui->lineEdit_5->setText(q.value(1).toString());
            ui->lineEdit_6->setText(q.value(2).toString());
            ui->lineEdit_7->setText(q.value(3).toString());
            ui->comboBox_4->setCurrentText(q.value(4).toString());
        }
    }


}

void MainWindow::on_modif_clicked()
{
    QString ref=ui->idmodif->currentText();
    QString nom=ui->lineEdit_5->text();
    int stock=ui->lineEdit_6->text().toInt();
    int prix=ui->lineEdit_7->text().toInt();
    int x=0;
    if(ref=="")
    {
        QMessageBox::critical(nullptr, QObject::tr("WARNING"),
                    QObject::tr("la refernce est vide"), QMessageBox::Ok);
              x++;
    }
    else if(nom=="")
    {
        QMessageBox::critical(nullptr, QObject::tr("WARNING"),
                    QObject::tr("la nom est vide"), QMessageBox::Ok);
              x++;
    }
    else if(x==0)
    {
        produit p(ref,nom,stock,prix);
        bool t=p.modifierp(ref);
        if(t)
        {
            QMessageBox::information(nullptr, QObject::tr("produit modifier"),
                              QObject::tr("base de données mise à jour"), QMessageBox::Ok);
            ui->idmodif->clear();
            ui->lineEdit_5->clear();
            ui->lineEdit_6->clear();
            ui->lineEdit_7->clear();
            ui->stackedWidget->setCurrentIndex(0);
        }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("WARNING"),
                        QObject::tr("Veuillez réessayer"), QMessageBox::Ok);
            ui->idmodif->clear();
            ui->lineEdit_5->clear();
            ui->lineEdit_6->clear();
            ui->lineEdit_7->clear();
        }
    }


}

void MainWindow::on_trie_clicked()
{
    ui->produit_2->setModel(tabproduit.triep());
}

void MainWindow::on_ajoutf_clicked()
{
    QString matricule =ui->lineEdit_m->text();
    QString nom=ui->lineEdit_n->text();
    QString adresse=ui->lineEdit_a->text();
    QString email=ui->lineEdit_e->text();
    int tel=ui->lineEdit_t->text().toInt();
     int x=0;
    string str_tel = to_string(tel);
    string m = email.toStdString();
    if(matricule=="")
    {
        QMessageBox::critical(nullptr, QObject::tr("WARNING"),
                    QObject::tr("la matricule est vide"), QMessageBox::Ok);
              x++;
    }
    else if(nom=="")
    {
        QMessageBox::critical(nullptr, QObject::tr("WARNING"),
                    QObject::tr("le nom est vide"), QMessageBox::Ok);
              x++;
    }
    else if(adresse=="")
    {
        QMessageBox::critical(nullptr, QObject::tr("WARNING"),
                    QObject::tr("l'adress est vide"), QMessageBox::Ok);
              x++;
    }
    else if(m.find("@gmail.com")== std:: string::npos)
    {
        QMessageBox::critical(nullptr, QObject::tr("WARNING"),
                    QObject::tr("Email must end with @gmail.com"), QMessageBox::Ok);
              x++;
    }
    else if(str_tel.length()!=8)
    {
        QMessageBox::critical(nullptr, QObject::tr("WARNING"),
                    QObject::tr("Phone number must be composed of 8 numbers"), QMessageBox::Ok);
              x++;
    }
    else if(x==0)
    {
        fournisseur f(matricule,nom,adresse,email,tel);
        bool t=f.ajouterf();
        if(t)
        {
            QMessageBox::information(nullptr, QObject::tr("fournisseur ajouter"),
                              QObject::tr("base de données mise à jour"), QMessageBox::Ok);
            ui->lineEdit_m->clear();
            ui->lineEdit_n->clear();
            ui->lineEdit_a->clear();
            ui->lineEdit_e->clear();
            ui->lineEdit_t->clear();
            //ui->stackedWidget->setCurrentIndex(0);
        }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("WARNING"),
                        QObject::tr("Veuillez réessayer"), QMessageBox::Ok);
        }
    }

}

void MainWindow::on_toolButton_AF_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);
}

void MainWindow::on_toolButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);

}

void MainWindow::on_toolButton_fromajoutf_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);

}

void MainWindow::on_toolButton_AFF_clicked()
{
    ui->stackedWidget->setCurrentIndex(8);
    ui->fournisseurtable->setModel(tabfour.afficherf());
}

void MainWindow::on_toolButton_7_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}

void MainWindow::on_toolButton_SF_clicked()
{
    ui->stackedWidget->setCurrentIndex(9);
    ui->tableView_3->setModel(tabfour.afficherf());
    QSqlQueryModel *mod= new QSqlQueryModel();
    mod->setQuery("select MATRICULE from fournisseur ");
    ui->comboBox_3->setModel(mod);

}

void MainWindow::on_toolButton_8_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}

void MainWindow::on_tableView_3_activated(const QModelIndex &index)
{
    QString val=ui->produit_2->model()->data(index).toString();
    QSqlQueryModel *mod= new QSqlQueryModel();
    mod->setQuery("select matricule from fournisseur WHERE matricule ='"+val+"'");
    ui->comboBox_3->setModel(mod);




}

void MainWindow::on_idmodif_currentIndexChanged(const QString &arg1)
{

    QString val=ui->idmodif->currentText();
    QSqlQuery q;
    q.prepare("select * from produit where ref='"+val+"'");
    if(q.exec())
    {
        while(q.next())
        {
            ui->lineEdit_5->setText(q.value(1).toString());
            ui->lineEdit_6->setText(q.value(2).toString());
            ui->lineEdit_7->setText(q.value(3).toString());
            ui->comboBox_4->setCurrentText(q.value(4).toString());
        }
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("WARNING"),
                    QObject::tr("Veuillez réessayer"), QMessageBox::Ok);
    }


}

void MainWindow::on_tableView_activated(const QModelIndex &index)
{
    QString val=ui->tableView->model()->data(index).toString();
    QSqlQuery q;
    q.prepare("SELECT * FROM PRODUIT WHERE REF = '"+val+"' OR NOM = '"+val+"' OR STOCK = '"+val+"' OR PRIX = '"+val+"' ");
    if(q.exec())
    {
        while(q.next())
        {
            ui->comboBox->setCurrentText(q.value(0).toString());
        }
    }

}

void MainWindow::on_toolButton_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_toolButton_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_rech_clicked()
{
    QString m=ui->recherche->text();
    ui->fournisseurtable->setModel(tabfour.cherchef(m));
}

void MainWindow::on_cherchep_clicked()
{
    QString ref=ui->cherchp->text();
    ui->produit_2->setModel(tabproduit.recherchep(ref));
}
