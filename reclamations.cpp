#include "reclamations.h"
#include <QDebug>
reclamations::reclamations()
{
nom_categorie="";
date_rec="";
id_client="";
avis="";
}
reclamations::reclamations(QString catg,QString client,QString dat,QString aviss)
{
    nom_categorie=catg;
    date_rec=dat;
    id_client=client;
    avis=aviss;
}
QString reclamations::get_Nomcatg(){return nom_categorie;}
QString reclamations::get_Idclient(){return id_client;}
QString reclamations::get_Daterec(){return date_rec;}
QString reclamations::get_avis(){return avis;}
void reclamations::set_Nomcatg(QString ch){nom_categorie=ch;}
void reclamations::set_Idclient(QString ch){id_client=ch;}
void reclamations::set_Daterec(QString ch){avis=ch;}
void reclamations::set_avis(QString ch){avis=ch;}

bool reclamations::ajouter()
{
    QSqlQuery query;
    query.prepare("INSERT INTO Reclamations (NOM_CATEGORIE, ID_CLIENT, DATE_REC, AVIS) "
                        "VALUES (:nom_categorie, :id_client, :date_rec, :avis)");
    query.bindValue(":nom_categorie", nom_categorie);
    query.bindValue(":id_client", id_client);
    query.bindValue(":date_rec", date_rec);
    query.bindValue(":avis", avis);
    return    query.exec();

}
QSqlQueryModel * reclamations::afficher()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from RECLAMATIONS ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_CLIENT"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM_CATEGORIE"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("DATE_REC"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("AVIS"));

        return model;
}

bool reclamations::supprimer(QString nom,QString id)
{
    QSqlQuery query;

        query.prepare("Delete from RECLAMATIONS where ((NOM_CATEGORIE like '"+nom+"')AND (id_client like '"+id+"'))  ");
    return    query.exec();
}
bool reclamations::modifier()
{
    QSqlQuery query;
    //if()
    //{
        query.prepare("UPDATE RECLAMATIONS set DATE_REC=:date , AVIS=:aviss where (NOM_CATEGORIE=:nom AND ID_CLIENT=:id )");
            //lezem naamel ntesti ken fama menha la reclamation 9bal manaamel update
            //ou bien tester si une ligne a été mise a joiur ou non
        query.bindValue(":nom", nom_categorie);
        query.bindValue(":date", date_rec);
        query.bindValue(":id", id_client);
        query.bindValue(":aviss", avis);
        return    query.exec();




}

QSqlQueryModel * reclamations::rechercher(QString rech)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from RECLAMATIONS where NOM_CATEGORIE LIKE '"+rech+"%' or DATE_REC LIKE '"+rech+"%' or ID_CLIENT like '"+rech+"%' ");
    return model;
}
QSqlQueryModel *reclamations::tri()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from RECLAMATIONS ORDER BY DATE_REC DESC");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_CLIENT"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM_CATEGORIE"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("DATE_REC"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("AVIS"));

        return model;
}
QSqlQueryModel * reclamations::affecter_Categorie()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select nom_categorie from categories ");

        return model;
}
QSqlQueryModel * reclamations::affecter_Client()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select id_client from clients ");

        return model;
}
