#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"gestion_categories_reclamations.h"

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

void MainWindow::on_pushButton_clicked()
{
Gestion_categories_reclamations fenetre;
fenetre.exec();
}
