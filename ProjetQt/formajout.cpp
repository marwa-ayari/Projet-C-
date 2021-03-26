#include "formajout.h"
#include "ui_formajout.h"

formajout::formajout(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::formajout)
{
    ui->setupUi(this);
}

formajout::~formajout()
{
    delete ui;
}
