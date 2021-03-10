#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"gestion_materiaux_maintenances.h"
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


void MainWindow::on_pushButton_maher_clicked()
{
    Gestion_materiaux_maintenances gestion;
    gestion.setModal(true);
    gestion.exec();
}
