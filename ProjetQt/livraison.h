#ifndef LIVRAISON_H
#define LIVRAISON_H
#include<QString>
#include <QSqlQuery>
#include <QSqlQueryModel>


class Livraison
{
public:
    Livraison();
    Livraison(int,int,QString,QString);

    int get_num();
    QString get_adr_c();
    int get_prix();
    QString get_datel();
    void set_num(int);
    void set_adr_c(QString);
    void set_prix(int);
    void set_datel(QString);
    bool ajouter();
    QSqlQueryModel *afficher();
private:
    int num,prix ;
    QString datel,adr_c;


};

#endif // LIVRAISON_H
