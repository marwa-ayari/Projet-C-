#include "client.h"
#include <QString>
#include <QDebug>
Client::Client()
{
matricule=0;
nom="";
prenom="";
adresse="";
tel=0;
pts=0;
}
Client::Client(QString nom,QString prenom,QString adresse,int tel,int pts,int matricule)
{
    this->matricule=matricule;
    this->nom=nom;
    this->prenom=prenom;
    this->adresse=adresse;
    this->tel=tel;
    this->pts=pts;
}
QString Client::get_nom(){return  nom;}
QString Client::get_prenom(){return prenom;}
QString Client::get_adresse(){return adresse;}
int Client::get_tel(){return tel;}
int Client::get_pts(){return pts;}
int Client::get_matricule(){return matricule;}
void Client::set_nom(QString n){nom=n;}
void Client::set_prenom(QString p){prenom=p;}
void Client::set_adresse(QString ad){adresse=ad;}
void Client::set_tel(int t){tel=t;}
void Client::set_pts(int pt){pts=pt;}
void Client::set_matricule(int mat){matricule=mat;}


bool Client::supprimer1(int mat)
{
QSqlQuery query;
QString matricule= QString::number(mat);
query.prepare("Delete from client where matricule = :matricule ");
query.bindValue(":matricule", matricule);
return    query.exec();
}
bool Client::ajouter1()
{
QSqlQuery query;
QString mat= QString::number(matricule);
QString t= QString::number(tel);
QString p= QString::number(pts);
query.prepare("INSERT INTO client ( nom, prenom, adresse, tel, pts, matricule) "
                    "VALUES (:nom, :prenom, :adresse, :tel, :pts, :matricule)");
query.bindValue(":matricule", mat);
query.bindValue(":nom", nom);
query.bindValue(":prenom", prenom);
query.bindValue(":adresse", adresse);
query.bindValue(":tel", t);
query.bindValue(":pts", p);

return    query.exec();
}
QSqlQueryModel * Client::afficher1()
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from client");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("MATRICULE"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("ADRESSE"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("TEL"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("PTS"));
    return model;
}
QSqlQueryModel * Client::modifier_liste_matricule()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select matricule from client ");

    return model;
}
bool Client::modifier1(int mat)
{
    QSqlQuery query;
    QString te= QString::number(tel);
      QString pt= QString::number(pts);
        QString matr= QString::number(mat);
    query.prepare("UPDATE client SET NOM=:nom,PRENOM=:prenom,ADRESSE=:adresse,TEL=:tel,PTS=:pts,MATRICULE=:matricule WHERE matricule=:matricule");

    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":adresse",adresse);
    query.bindValue(":tel",te);
     query.bindValue(":pts",pt);
      query.bindValue(":matricule",matr);

    return    query.exec();
}
