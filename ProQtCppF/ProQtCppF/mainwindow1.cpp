/*#include "mainwindow1.h"
#include "ui_mainwindow.h"
#include"mainwindow.h"

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
          setStyleSheet(" QPushButton {"
                        "border-radius: 5px; "
                        "border: 1.5px solid rgb(91,231,255); "
                        "background-color: red; }"
                        "QPushButton:pressed {"
                        "border: 1.4px solid rgb(73,186,205); }"
                        "QPushButton:hover {"
                        "font-size: 16px;"
                        "transition: 0.9s; }");

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
 ui->pushButton_connecter->setStyleSheet(QString::fromUtf8("background-color: #de1c58;"));
            QString id = ui->lineEdit_login->text();
            QString mdp = ui->lineEdit_mdp->text();

                   if((id ==  "prop")&&(mdp =="prop")) {
        MainWindow fenetre;
        fenetre.exec();


                   }

                   else
                       QMessageBox::warning(this,"Connection", "Vérifier svp ");

}
void MainWindow::on_pushButton_off_clicked()
{  QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile("C:/images_projets/button.mp3"));
    player->setVolume(2000);
    player->play();
 ui->pushButton_off->setStyleSheet(QString::fromUtf8("background-color: #de1c58;"));

    son->stop();

}

void MainWindow::on_pushButton_on_clicked()
{  QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile("C:/images_projets/button.mp3"));
    player->setVolume(2000);
    player->play();
    son->play();
 ui->pushButton_on->setStyleSheet(QString::fromUtf8("background-color: #de1c58;"));

}

*/
