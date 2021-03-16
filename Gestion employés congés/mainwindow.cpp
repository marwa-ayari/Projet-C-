#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "employes.h"
#include"gesempcong.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    son = new QSound("../music.wav");
    son->play();
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_clicked()
{

gesempcong fenetre;
fenetre.exec();
}

void MainWindow::on_login_clicked()
{
    QString username=ui->username->text();
    QString password=ui->password->text();
    if((username=="eya")&&(password=="eya"))
    {
        gesempcong gestion;
        gestion.setModal(true);
        gestion.exec();

    }else QMessageBox::critical(nullptr, QObject::tr("acces refuse"),
                                QObject::tr("Vérifiez vos coordonnées."), QMessageBox::Cancel);
}








void MainWindow::on_sonon_clicked()
{ son->play();

}

void MainWindow::on_sonoff_clicked()
{son->stop();

}


