#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "employes.h"
#include"gesempcong.h"
#include"securritefume.h"




MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    son = new QSound("../resources/music.wav");
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

}





void MainWindow::on_arduinofenetrefume_clicked()
{ securritefume *p = new securritefume();
    p->setWindowModality(Qt::ApplicationModal);
    p->show();

}
