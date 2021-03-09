#ifndef CLIENTS_CADEAUX_H
#define CLIENTS_CADEAUX_H
#include"client.h"

#include <QDialog>

namespace Ui {
class clients_cadeaux;
}

class clients_cadeaux : public QDialog
{
    Q_OBJECT

public:
    explicit clients_cadeaux(QWidget *parent = nullptr);
    ~clients_cadeaux();
private slots:
void on_pushButton_ajouterCl_2_clicked();

void on_pushButton_cherch_2_clicked();

void on_pushButton_suppCl_2_clicked();

void on_pushButton_modifCl_2_clicked();



void on_tabWidget_2_currentChanged(int index);




private:
    Ui::clients_cadeaux *ui;

       Client tmpclient;
};

#endif // CLIENTS_CADEAUX_H
