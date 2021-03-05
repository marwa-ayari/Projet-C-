#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"categories.h"
#include"reclamations.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_4_clicked();

    void on_pushButton_6_clicked();

    void on_tabWidget_4_currentChanged(int index);

    void on_pushButton_13_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_7_clicked();

    void on_bouton_ajout_reclamation_clicked();

    void on_tabWidget_3_currentChanged(int index);

    void on_pushButton_3_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_12_clicked();

    void on_comboBox_categorie_modifi_currentIndexChanged(const QString &arg1);

    void on_comboBox_reclamation_3_currentIndexChanged(const QString &arg1);

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    Categories tmpcategorie;
    reclamations tmpreclamation;
};
#endif // MAINWINDOW_H
