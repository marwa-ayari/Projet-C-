#include "gestion_materiaux_maintenances.h"
#include "ui_gestion_materiaux_maintenances.h"

Gestion_materiaux_maintenances::Gestion_materiaux_maintenances(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Gestion_materiaux_maintenances)
{
    ui->setupUi(this);
}

Gestion_materiaux_maintenances::~Gestion_materiaux_maintenances()
{
    delete ui;
}
