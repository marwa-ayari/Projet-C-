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
    son->setLoops(50);
    setFixedSize(791,511);  //fixe la taille de la fenêtre

    animation = new QPropertyAnimation(ui->login,"geometry");
    animation->setDuration(3000);
    animation->setStartValue(ui->login->geometry());
    animation->setEndValue(QRectF(200,300,70,70));


    QEasingCurve curve;
    curve.setType(QEasingCurve::OutBounce);
    animation->setEasingCurve(curve);
    animation->start();









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


