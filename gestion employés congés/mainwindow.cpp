#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "employes.h"



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





void MainWindow::on_ajoutemp_clicked()
{
    int matemp=ui->matricule->text().toInt();
    float salaire=ui->salaire->text().toInt();
    QString dateemb=ui->dateemb->text();
    QString nom=ui->nom->text();
    QString prenom=ui->prenom->text();
    QString fonction=ui->fonction->text();

    Employes E(matemp,salaire,dateemb,nom,prenom,fonction);



}
