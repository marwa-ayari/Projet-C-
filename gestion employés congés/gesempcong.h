#ifndef GESEMPCONG_H
#define GESEMPCONG_H

#include"employes.h"
#include <QDialog>




namespace Ui {
class gesempcong;
}

class gesempcong : public QDialog
{
    Q_OBJECT

public:
    explicit gesempcong(QWidget *parent = nullptr);
    ~gesempcong();

private slots:
 void on_ajoutemp_clicked();
 void on_tabWidget_employes_currentChanged(int index);
 void on_suppemp_clicked();
 void on_modifemp_clicked();


 void on_pushButton_rechercheemp_clicked();
 void on_triemp_clicked();

private:
    Ui::gesempcong *ui;
    Employes insemployes;



};


#endif // GESEMPCONG_H
