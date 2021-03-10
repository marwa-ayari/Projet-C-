#ifndef EMPLOYES_H
#define EMPLOYES_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Employes
{
public:
    Employes();
    Employes(int,float,QString,QString,QString,QString);

     private:
    int matemp;
    float salaire;
    QString dateemb,nom,prenom,fonction;

    int getmatemp();
    float getsalaire();
    QString getdateemb();
    QString getnom();
    QString getprenom();
    QString getfonction();



    void setmatemp(int);
    void setsalaire(float);
    void setdateemb(QString);
    void setnom(QString);
    void setprenom(QString);
    void setfonction(QString);
    bool ajouter();





};

#endif // EMPLOYES_H
