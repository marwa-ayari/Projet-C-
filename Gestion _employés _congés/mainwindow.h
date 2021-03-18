#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QSound>
#include <QPropertyAnimation>



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

signals :
    void sig();
private:
    Ui::MainWindow *ui;
    QSound *son;
    QPropertyAnimation *animation;




};
#endif // MAINWINDOW_H
