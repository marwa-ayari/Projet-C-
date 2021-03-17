#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"clients_cadeaux.h"
#include <QMediaPlayer>
#include<QMessageBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QMediaPlayer *music=new QMediaPlayer();
       music->setMedia(QUrl("C:/images_projets/music.wav"));
       music->play();


}
MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_clicked()
{  
    QString nom = ui->lineEdit_nom_prop->text();
        QString prenom = ui->lineEdit_prenom_prop->text();
        QString mdp = ui->lineEdit_mdp_prop->text();

          /*     if((nom ==  "Ben Amor")&&(prenom=="Eya")&&(mdp =="prop")) {*/
    clients_cadeaux fenetre;
    fenetre.exec();
               }
               /*else
               {
                   QMessageBox::warning(this,"Connection", "Vérifier svp ");
               }
}
*/
