#include "commande.h"
#include <QDebug>
#include<QSqlDatabase>
#include<QSqlQuery>
#include "connection.h"
Commande::Commande()
{
    id=0;
    num=0;
    cl="";
    com="";

}
Commande:: Commande(int id,int num,QString cl, QString com)
{
  this->id=id;
  this->num=num;
  this->cl=cl;
  this->com=com;

}
void Commande::set_cl(QString client){ cl=client; }
void Commande::set_com(QString commande){ com=commande; }
void Commande::set_num(int numero){ num=numero; }
void Commande::set_id(int idcom){ id=idcom; }


bool Commande::ajouter()
{
QSqlQuery query;
QString res= QString::number(id);
query.prepare("INSERT INTO COMMANDES (ID, NUM, CL, COM) "
                    "VALUES (:id, :num, :cl ,:com )");
query.bindValue(":id", res);

query.bindValue(":num", num);
query.bindValue(":cl", cl);
query.bindValue(":com", com);

return    query.exec();
}

QSqlQueryModel * Commande::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from COMMANDES");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Numéro "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Nom Client"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Nom Livraison"));


    return model;
}

bool Commande::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from COMMANDES where ID = :id ");
query.bindValue(":id", res);
return    query.exec();
}
bool Commande::modifier (int id,int num,QString cl,QString com)
{
    QSqlQuery query;
    query.prepare("UPDATE COMMANDES SET id= :id,num= :num,cl= :cl,com = :com  WHERE id= :id ");
    query.bindValue(":id",id);
    query.bindValue(":num",num);
    query.bindValue(":cl",cl);
    query.bindValue(":com",com);
    return    query.exec();
}



