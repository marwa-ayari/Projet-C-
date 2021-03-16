#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QSound>

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
    void on_pushButton_clicked();



    void on_sonon_clicked();

    void on_sonoff_clicked();

    void on_login_clicked();

private:
    Ui::MainWindow *ui;
    QSound *son;




};
#endif // MAINWINDOW_H
