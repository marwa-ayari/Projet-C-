#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"commande.h"
#include <QMainWindow>
#include "livraison.h"


namespace Ui { class MainWindow; }


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pb_ajout_c_clicked();

    void on_lineEdit_3_cursorPositionChanged(int arg1, int arg2);

    void on_pushButton_4_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::MainWindow *ui;
     Commande tmpcommande;
     Livraison tmplivraison;
};
#endif // MAINWINDOW_H
