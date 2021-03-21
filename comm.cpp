#include "comm.h"

#include <QtDebug>



Commandes::Conmmandes()
{
   idc="";
   duree=0;
   type="";
   datedeb="";
   datefin="";



}

Conmmandes::Conmmandes(int duree,QString idc,QString type ,QString datedeb ,QString datefin)
{this->duree=duree;
  this->idc=idc;
  this->type=type;
  this->datedeb=datedeb;
  this->datefin=datefin;
}






int Conmmandes::getduree(){ return duree;}
QString Conmmandes:: getidc(){ return idc;}
QString Conmmandes::gettype(){ return type;}
QString Conmmandes::getdatebdeb(){ return datedeb;}
QString Conmmandes::getdatefin(){ return datefin;}



void Conmmandes::setduree(int duree){ this->duree=duree;}
void Conmmandes::setidc(QString idc){ this->idc=idc;}
void Conmmandes::settype(QString type){ this->type=type;}
void Conmmandes::setdatedeb(QString datedeb){ this->datedeb=datedeb;}
void Conmmandes::setdatefin(QString datefin){ this->datefin=datefin;}

bool Conmmandes::ajouter()
{

QSqlQuery query;

QString duree_string= QString::number(duree);


query.prepare("INSERT INTO conmmandes (idc,duree,type,datedeb,datefin) "
              "VALUES (:idc, :duree, :type ,:datedeb ,:datefin)");
query.bindValue(":duree", duree_string);
query.bindValue(":idc", idc);
query.bindValue(":type", type);
query.bindValue(":datedeb",datedeb);
query.bindValue(":datefin",datefin);

 return query.exec();


}

QSqlQueryModel * Conges::afficher()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from conges ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("idc"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("duree"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("type"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("datedeb "));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("datefin "));


        return model;
}

bool Conmmandes::supprimer(QString idc)
{
    QSqlQuery query;
    query.prepare("Delete from conmmandes where idc=:idc");
    query.bindValue(0,idc);
    return    query.exec();
}

bool Conmmandes::modifier()
{
    QSqlQuery query;

    QString duree_string= QString::number(duree);


    query.prepare("UPDATE conges set duree='"+duree_string+"',type='"+type+"',datedeb='"+datedeb+"',datefin='"+datefin+"' where idc like '"+idc+"' ");
    return    query.exec();
}


QSqlQueryModel *Conmmandes::rechercher(QString rech)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from conmmandes where type LIKE '"+rech+"%'");
    return model;
}

QSqlQueryModel * Conmmandes::tri()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from conmmandes ORDER BY duree DESC");


    model->setHeaderData(0, Qt::Horizontal, QObject::tr("idc"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("duree"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("type"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("datedeb "));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("datefin "));

        return model;
}


QSqlQueryModel * Conmmandes::modifier_liste_conges()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select idc from conmmandes ");

    return model;
}





