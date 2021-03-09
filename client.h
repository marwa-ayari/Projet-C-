#ifndef CLIENT_H
#define CLIENT_H

#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
class Client
{
public:
    Client();
    Client(QString,QString,QString,int,int,int);
    int get_matricule();
    QString get_nom();
    QString get_prenom();
    QString get_adresse();
   int get_tel();
    int get_pts();
    void set_matricule(int);
    void set_nom(QString);
        void set_prenom(QString);
        void set_adresse(QString);
        void set_tel(int);
        void set_pts(int);
    bool ajouter1();
 bool supprimer1(int);
 QSqlQueryModel * afficher1();
    QSqlQueryModel * afficherorder1();
    QSqlQueryModel * recherche1(const QString&);
QSqlQueryModel * modifier_liste_matricule();


    bool modifier1(int);
    QVector<double> statistique();
private:
    QString nom,prenom,adresse;
    int matricule,tel,pts;
};

#endif // CLIENT_H
