#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include"commande.h"
#include"livraison.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit_2->setValidator(new QIntValidator(0,99999,this));
     ui->lineEdit_5->setValidator(new QIntValidator(0,99999,this));
ui->tableView->setModel(tmpcommande.afficher());
ui->tableView_2->setModel(tmplivraison.afficher());
ui->comboLiv->setModel(tmpcommande.affecter_Livraison());
ui->comboClient->setModel(tmpcommande.affecter_client());
ui->comboLiv_2->setModel(tmpcommande.affecter_Livraison());
ui->comboClient_2->setModel(tmpcommande.affecter_client());
ui->comboCommande->setModel(tmpcommande.affecter_commande());
ui->comboCommande_2->setModel(tmpcommande.affecter_commande());
ui->combols->setModel(tmpcommande.affecter_Livraison());
ui->combolk->setModel(tmpcommande.affecter_Livraison());
ui->comboCat->setModel(tmpcommande.affecter_categorie());
ui->comboCat2->setModel(tmpcommande.affecter_categorie());
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_4_clicked()

    {
        int num_l = ui->comboLiv->currentText().toInt();
            int id_com = ui->lineEdit_5->text().toInt();

            QString nom_cat= ui->comboCat->currentText();


            QString nom_cl= ui->comboClient->currentText();

          Commande c(id_com,num_l,nom_cl,nom_cat);
          bool test=c.ajouter();
          if(test)
        {
              ui->comboCommande_2->setModel(tmpcommande.affecter_commande());
              ui->comboCommande->setModel(tmpcommande.affecter_commande());

              ui->tableView->setModel(tmpcommande.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Ajouter une commande"),
                          QObject::tr("Commande ajoutée.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);

        }
          else
              QMessageBox::critical(nullptr, QObject::tr("Ajouter une commande"),
                          QObject::tr("Erreur !\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
    }



void MainWindow::on_pushButton_6_clicked()
{
    int id_com = ui->comboCommande_2->currentText().toInt();
    bool test=tmpcommande.supprimer(id_com);
    if(test)
    {ui->tableView->setModel(tmpcommande.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer une commande"),
                    QObject::tr("commande supprimée.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer une commande"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_7_clicked()
{
    {
        int id_com = ui->comboCommande->currentText().toInt();
        int num_l = ui->comboLiv_2->currentText().toInt();

        QString nom_cl = ui->comboClient_2->currentText();
        QString nom_cat = ui->comboCat2->currentText();

        Commande c;
        bool test=c.modifier(id_com,num_l,nom_cat,nom_cl);

        if(test)
        {
            QMessageBox::information(nullptr, QObject::tr("modifier une commande"),
                              QObject::tr("commande modifiee.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
        }
        else
            QMessageBox::critical(nullptr, QObject::tr("non modifie"),
                        QObject::tr("Erreur !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
            ui->tableView->setModel(tmpcommande.afficher());

    }
}




void MainWindow::on_pushButton_clicked()
{ int num_l = ui->lineEdit_2->text().toInt();
    int prix_l = ui->lineEdit->text().toInt();
    QString datel= ui->lineEdit_15->text();
    QString adr_c= ui->lineEdit_17->text();

  Livraison l(num_l,prix_l,datel,adr_c);
  bool test=l.ajouter();
  if(test)
{

      ui->tableView_2->setModel(tmplivraison.afficher());//refresh
      ui->comboLiv->setModel(tmpcommande.affecter_Livraison());
      ui->combols->setModel(tmpcommande.affecter_Livraison());
      ui->combolk->setModel(tmpcommande.affecter_Livraison());
QMessageBox::information(nullptr, QObject::tr("Ajouter une livraison"),
                  QObject::tr("Livraison ajoutée.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter une livraison"),
                  QObject::tr("Erreur !\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_pushButton_2_clicked()
{{
        int prix_l = ui->lineEdit_7->text().toInt();
        int num_l = ui->combolk->currentText().toInt();

        QString datel = ui->lineEdit_18->text();
        QString adr_c = ui->lineEdit_19->text();

       Livraison l;
        bool test=l.modifier(num_l,prix_l,datel,adr_c);

        if(test)
        {
            QMessageBox::information(nullptr, QObject::tr("modifie une livraison"),
                              QObject::tr("Livraison modifiee.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
        }
        else
            QMessageBox::critical(nullptr, QObject::tr("non modifie"),
                        QObject::tr("Erreur !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
            ui->tableView_2->setModel(tmplivraison.afficher());

    }

}

void MainWindow::on_pushButton_3_clicked()
{
    int num_l = ui->combols->currentText().toInt();
    bool test=tmplivraison.supprimer(num_l);
    if(test)
    {ui->tableView_2->setModel(tmplivraison.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer une livraison"),
                    QObject::tr("livraison supprimée.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer une livraison"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_14_clicked()
{
    {ui->tableView->setModel(tmpcommande.tri());

    }
}



void MainWindow::on_pushButton_12_clicked()
{
ui->tableView_2->setModel(tmplivraison.tri());
    }








void MainWindow::on_lineEdit_10_cursorPositionChanged(int arg1, int arg2)
{
    QString rech =ui->lineEdit_10->text();

     ui->tableView->setModel(tmpcommande.rechercher(rech));

}

void MainWindow::on_lineEdit_20_cursorPositionChanged(int arg1, int arg2)
{
    QString rech =ui->lineEdit_20->text();

       ui->tableView_2->setModel(tmplivraison.rechercher(rech));
}




