#include "livraison.h"
#include<QString>
#include<QSqlQuery>
#include <QDebug>
#include<QSqlDatabase>

#include"connection.h"

Livraison::Livraison()
{
num=0;
datel="";
prix=0;
adr_c="";
}
Livraison::Livraison(int num,int prix,QString datel,QString adr_c)
{
    this->num=num;
    this->prix=prix;
    this->datel=datel;
    this->adr_c=adr_c;
}

void Livraison::set_num(int numero){num=numero;}
void Livraison::set_prix(int px){prix=px;}
void Livraison::set_adr_c(QString adr){adr_c=adr;}
void Livraison::set_datel(QString date){datel=date;}

bool Livraison::ajouter()
{
    QSqlQuery query ;
    QString res=QString::number(num);
    QString res1=QString::number(prix);
    query.prepare("INSERT TO LIVRAISONS (NUM,PRIX,DATEL,ADR_C)"
"VALUES(:num,:prix,:datel,:adr_c)");
    query.bindValue(":num",res);
    query.bindValue(":prix",res1);
    query.bindValue(":datel",datel);
    query.bindValue(":adr_c",adr_c);
    return query.exec();

}
QSqlQueryModel * Livraison::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from LIVRAISONS");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("NUM"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("PRIX"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("DATEL"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("ADR_C"));
return model ;}
