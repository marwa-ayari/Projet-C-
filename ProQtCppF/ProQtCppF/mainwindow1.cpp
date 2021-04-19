/*#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "commande.h"
#include"livraison.h"

#include <QtMultimedia/QSound>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{ QSound son;
    ui->setupUi(this);
    son = new QSound("../imagesQT/music.wav");
    son->play();
    son->setLoops(50);
    setFixedSize(990,600);  //fixe la taille de la fenêtre

    animation = new QPropertyAnimation(ui->login,"geometry");
    animation->setDuration(8000);
    animation->setStartValue(ui->login->geometry());
    animation->setEndValue(QRectF(200,300,90,70));


    QEasingCurve curve;
    curve.setType(QEasingCurve::OutBounce);
    animation->setEasingCurve(curve);
    animation->start();









}

MainWindow::~MainWindow()
{
    delete ui;
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

}*/


