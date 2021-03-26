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
ui->tableView->setModel(tmpcommande.afficher());
ui->tableView_2->setModel(tmplivraison.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_4_clicked()

    {
        int num = ui->lineEdit_5->text().toInt();
            int id = ui->lineEdit_12->text().toInt();

            QString com= ui->lineEdit_4->text();
            QString cl= ui->lineEdit_3->text();

          Commande c(id,num,cl,com);
          bool test=c.ajouter();
          if(test)
        {

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
    int id = ui->lineEdit_16->text().toInt();
    bool test=tmpcommande.supprimer(id);
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
        int id = ui->lineEdit_14->text().toInt();
        int num = ui->lineEdit_13->text().toInt();

        QString cl = ui->lineEdit_6->text();
        QString com = ui->lineEdit_9->text();

        Commande c;
        bool test=c.modifier(id,num,cl,com);

        if(test)
        {
            QMessageBox::information(nullptr, QObject::tr("modifie une commande"),
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

void MainWindow::on_pushButton_5_clicked()
{
    int num=ui->lineEdit_2->text().toInt();
    int prix=ui->lineEdit->text().toInt();
    QString adr_c=ui->lineEdit_17->text();
    QString datel=ui->lineEdit_15->text();

    Livraison l(num,prix,datel,adr_c);
    bool test=l.ajouter();
    if(test)
  {

        ui->tableView_2->setModel(tmplivraison.afficher());//refresh
  QMessageBox::information(nullptr, QObject::tr("Ajouter une commande"),
                    QObject::tr("Commande ajoutée.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

  }
    else
        QMessageBox::critical(nullptr, QObject::tr("Ajouter une commande"),
                    QObject::tr("Erreur !\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

