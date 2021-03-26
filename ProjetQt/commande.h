#ifndef COMMANDE_H
#define COMMANDE_H
#include<QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Commande
{
public:
    Commande();
    Commande(int,int,QString,QString);
    int get_id();
    int get_num();
    QString get_com();
    QString get_cl();
    void set_id(int);
    void set_num(int);
    void set_com(QString);
    void set_cl(QString);
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier(int,int,QString,QString);
private:
    QString com,cl;
    int id,num;
};

#endif // COMMANDE_H
