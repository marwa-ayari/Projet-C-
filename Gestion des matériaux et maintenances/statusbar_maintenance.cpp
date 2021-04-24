#include "statusbar_maintenance.h"
#include "ui_statusbar_maintenance.h"

statusbar_maintenance::statusbar_maintenance(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::statusbar_maintenance)
{
    ui->setupUi(this);




}

statusbar_maintenance::~statusbar_maintenance()
{
    delete ui;
}
