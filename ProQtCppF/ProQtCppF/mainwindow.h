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


   void on_pushButton_4_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_12_clicked();

    void on_lineEdit_10_cursorPositionChanged(int arg1, int arg2);

    void on_lineEdit_20_cursorPositionChanged(int arg1, int arg2);



    void on_lineEdit_4_cursorPositionChanged(int arg1, int arg2);

    void sendMail();
    void mailSent(QString);
    void browse();
    void on_pushButton_5_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_label_32_linkActivated(const QString &link);

private:
    Ui::MainWindow *ui;
     Commande tmpcommande;
     Livraison tmplivraison;
     QStringList files;

};
#endif // MAINWINDOW_H
