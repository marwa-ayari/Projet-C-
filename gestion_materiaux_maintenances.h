#ifndef GESTION_MATERIAUX_MAINTENANCES_H
#define GESTION_MATERIAUX_MAINTENANCES_H
#include"materiaux.h"
#include <QDialog>

namespace Ui {
class Gestion_materiaux_maintenances;
}

class Gestion_materiaux_maintenances : public QDialog
{
    Q_OBJECT

public:
    explicit Gestion_materiaux_maintenances(QWidget *parent = nullptr);
    ~Gestion_materiaux_maintenances();

private slots:
    void on_pushButton_materiel_16_clicked();

    void on_tabWidget_4_currentChanged(int index);

private:
    Ui::Gestion_materiaux_maintenances *ui;
    Materiaux tmpmateriel;
};

#endif // GESTION_MATERIAUX_MAINTENANCES_H
