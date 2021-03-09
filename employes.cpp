#include "employes.h"
#include <QSqlQuery>
#include <QtDebug>



Employes::Employes()
{
   matemp=0;
   salaire=0;
   dateemb="";
   nom="";
   prenom="";
   fonction="";


}

Employes::Employes(int matemp,float salaire,QString dateemb,QString nom ,QString prenom ,QString fonction)
{
  this->matemp=matemp;
  this->salaire=salaire;
  this->dateemb=dateemb;
  this->nom=nom;
  this->prenom=prenom;
  this->fonction=fonction;
}


int Employes::getmatemp(){ return matemp;}
float Employes::getsalaire(){ return salaire;}
QString Employes::getdateemb(){ return dateemb;}
QString Employes::getnom(){ return nom;}
QString Employes::getprenom(){ return prenom;}
QString Employes::getfonction(){ return fonction;}


void Employes::setmatemp(int matemp){ this->matemp=matemp;}
void Employes::setsalaire(float salaire){ this->salaire=salaire;}
void Employes::setdateemb(QString dateemb){ this->dateemb=dateemb;}
void Employes::setnom(QString nom){ this->nom=nom;}
void Employes::setprenom(QString prenom){ this->prenom=prenom;}
void Employes::setfonction(QString fonction){ this->fonction=fonction;}

bool Employes::ajouter()
{
bool test=false;


QSqlQuery query;
QString mat_string=QString::number(matemp);
query.prepare("INSERT INTO employes (matemp,salaire,dateemb,nom,prenom,fonction) "
              "VALUES (:matemp, :salaire, :dateemb, :nom ,:prenom ,:fonction)");
query.bindValue(":matemp", mat_string);
query.bindValue(":salaire", salaire);
query.bindValue(":dateemb", dateemb);
query.bindValue(":nom", nom);
query.bindValue(":prenom",prenom);
query.bindValue(":fonction",fonction);
query.exec();



return test;

}


