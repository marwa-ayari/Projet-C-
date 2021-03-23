#include "gestion.h"
#include "ui_gestion.h"
#include"gestion_categories_reclamations.h"
#include<QMediaPlayer>
Gestion::Gestion(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Gestion)
{
    ui->setupUi(this);
    son=new QSound("C:/i/music.wav");
    son->play();
}

Gestion::~Gestion()
{
    delete ui;
}
void Gestion::on_pushButton_clicked()
{
    QMediaPlayer *player = new QMediaPlayer;
        player->setMedia(QUrl::fromLocalFile("C:/i/button.mp3"));
        player->setVolume(2000);
        player->play();

Gestion_categories_reclamations fenetre;
fenetre.exec();
}

void Gestion::on_sonon_clicked()
{
    QMediaPlayer *player = new QMediaPlayer;
        player->setMedia(QUrl::fromLocalFile("C:/i/button.mp3"));
        player->setVolume(2000);
        player->play();

    son->play();
}

void Gestion::on_sonoff_clicked()
{
    QMediaPlayer *player = new QMediaPlayer;
        player->setMedia(QUrl::fromLocalFile("C:/i/button.mp3"));
        player->setVolume(2000);
        player->play();

    son->stop();
}
