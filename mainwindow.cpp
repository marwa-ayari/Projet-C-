#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"clients_cadeaux.h"
#include <QMediaPlayer>
#include<QMessageBox>
#include<QString>
#include <QSound>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

       son = new QSound("C:/images_projets/music.wav");
          son->play();
          son->setLoops(20);
          setFixedSize(800,600);
          animation = new QPropertyAnimation(ui->pushButton_connecter,"geometry");
             animation->setDuration(20000);
             animation->setStartValue(ui->pushButton_connecter->geometry());
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




void MainWindow::on_pushButton_connecter_clicked()
{
    QMediaPlayer *player = new QMediaPlayer;
        player->setMedia(QUrl::fromLocalFile("C:/images_projets/button.mp3"));
        player->setVolume(2000);
        player->play();

            QString id = ui->lineEdit_login->text();
            QString mdp = ui->lineEdit_mdp->text();

              /*     if((id ==  "Ben Amor")&&(mdp =="prop")) {*/
        clients_cadeaux fenetre;
        fenetre.exec();

                   /*else
                   {
                       QMessageBox::warning(this,"Connection", "Vérifier svp ");
                   }

    */

}
void MainWindow::on_pushButton_off_clicked()
{  QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile("C:/images_projets/button.mp3"));
    player->setVolume(2000);
    player->play();


    son->stop();

}

void MainWindow::on_pushButton_on_clicked()
{  QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile("C:/images_projets/button.mp3"));
    player->setVolume(2000);
    player->play();
    son->play();


}
