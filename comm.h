#ifndef COMM_H
#define COMM_H


#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Commandes
{
private:

    int duree;
    QString idc,type,datedeb,datefin;

public:

    Commandes();
    Commandes(int,QString,QString,QString,QString);



  int getduree();
    QString getidc();
    QString gettype();
    QString getdatebdeb();
    QString getdatefin();



    void setduree(int);

    void setidc(QString);
    void settype(QString);
    void setdatedeb(QString);
    void setdatefin(QString);


    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(QString);
    bool modifier();

    QSqlQueryModel * rechercher(QString);
    QSqlQueryModel *tri();

    QSqlQueryModel * modifier_liste_Commandess();











};

#endif // COMM_H
