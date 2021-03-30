#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QApplication>
#include <QMessageBox>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <QMediaPlayer>
#include "connection.h"
using namespace std;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->sendBtn, SIGNAL(clicked()),this, SLOT(sendMail()));
    connect(ui->browseBtn, SIGNAL(clicked()), this, SLOT(browse()));

    connection c;
    bool test=c.database();
    if(test)
    {
        ui->conex->setText("BD Connecté   ");
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                    QObject::tr("connection failed"), QMessageBox::Cancel);
        ui->conex->setText("Connection");

    }
    Player = new QMediaPlayer(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::browse()
{
    files.clear();

    QFileDialog dialog(this);
    dialog.setDirectory(QDir::homePath());
    dialog.setFileMode(QFileDialog::ExistingFiles);

    if (dialog.exec())
        files = dialog.selectedFiles();

    QString fileListString;
    foreach(QString file, files)
        fileListString.append( "\"" + QFileInfo(file).fileName() + "\" " );

    ui->file->setText( fileListString );

}

void MainWindow::sendMail()
{
    Smtp* smtp = new Smtp(ui->uname->text(), ui->paswd->text(), ui->server->text(), ui->port->text().toInt());
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

    if( !files.isEmpty() )
        smtp->sendMail(ui->uname->text(), ui->rcpt->text() , ui->subject->text(),ui->msg->toPlainText(), files );
    else
        smtp->sendMail(ui->uname->text(), ui->rcpt->text() , ui->subject->text(),ui->msg->toPlainText());
}

void MainWindow::mailSent(QString status)
{
    if(status == "Message sent")
        QMessageBox::warning( 0, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );
}

void MainWindow::on_toolButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);

}

void MainWindow::on_affficherp_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    ui->produit_2->setModel(tabproduit.afficherp());

}

void MainWindow::on_pushButton_3_clicked()//trie
{
    ui->fournisseurtable->setModel(tabfour.trief());
}



void MainWindow::on_mofidifierp_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    QString ref=ui->idmodif->currentText();
    QSqlQueryModel *mod= new QSqlQueryModel();
    mod->setQuery("select REF from PRODUIT ");
    ui->idmodif->setModel(mod);
    QSqlQuery q;
    q.prepare("select * from PRODUIT where REF = '"+ref+"'");
    if(q.exec())
    {
        while(q.next())
        {
            ui->lineEdit_5->setText(q.value(1).toString());
            ui->lineEdit_6->setText(q.value(2).toString());
            ui->lineEdit_7->setText(q.value(3).toString());
            ui->comboBox_4->setCurrentText(q.value(4).toString());
        }
    }


}

void MainWindow::on_supprimerp_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    ui->tableView->setModel(tabproduit.afficherp());
    QSqlQueryModel *mod= new QSqlQueryModel();
    mod->setQuery("select REF from PRODUIT ");
    ui->comboBox->setModel(mod);
}

void MainWindow::on_pushButton_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);

}

void MainWindow::on_ajouterp_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
    ui->comboBox_2->setModel(tabproduit.affecter_fournisseur());

}

void MainWindow::on_toolButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);

}

void MainWindow::on_retourfromaf_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);

}

void MainWindow::on_ajout_clicked()
{
    QString ref=ui->lineEdit_ref->text();
    QString nom=ui->lineEdit_nom->text();
    int prix=ui->lineEdit_prix->text().toInt();
    int stock=ui->lineEdit_stock->text().toInt();
    int x=0;
    QString m_f=ui->comboBox_2->currentText();

    string str_prix=to_string(prix);

    string str_stock= to_string(stock);
    if(ref=="")
    {
        QMessageBox::critical(nullptr, QObject::tr("WARNING"),
                    QObject::tr("la refernce est vide"), QMessageBox::Ok);
              x++;
    }
    else if(nom=="")
    {
        QMessageBox::critical(nullptr, QObject::tr("WARNING"),
                    QObject::tr("la nom est vide"), QMessageBox::Ok);
              x++;
    }
    else if(x==0)
    {
        produit p(ref,nom,m_f,stock,prix);
        bool t=p.ajouterp();
        if(t)
        {
            QMessageBox::information(nullptr, QObject::tr("produit ajouter"),
                              QObject::tr("base de données mise à jour"), QMessageBox::Ok);
            ui->lineEdit_ref->clear();
            ui->lineEdit_nom->clear();
            ui->lineEdit_prix->clear();
            ui->lineEdit_stock->clear();
            ui->stackedWidget->setCurrentIndex(4);
        }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("WARNING"),
                        QObject::tr("Veuillez réessayer"), QMessageBox::Ok);

        }
    }
}

void MainWindow::on_supp_clicked()
{
    int ref=ui->comboBox->currentText().toInt();
    if(tabproduit.supprmierp(ref))
    {
        QMessageBox::information(nullptr, QObject::tr("produit supprimer"),
                          QObject::tr("base de données mise à jour"), QMessageBox::Ok);
        ui->stackedWidget->setCurrentIndex(1);

    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("WARNING"),
                    QObject::tr("Veuillez réessayer"), QMessageBox::Ok);
    }
}

void MainWindow::on_produit_2_activated(const QModelIndex &index)
{
    QString val=ui->produit_2->model()->data(index).toString();
    QSqlQuery q;
    q.prepare("SELECT * FROM PRODUIT WHERE REF = '"+val+"' OR NOM = '"+val+"' OR STOCK = '"+val+"' OR PRIX = '"+val+"' ");
    if(q.exec())
    {
        while(q.next())
        {   QSqlQueryModel *mod= new QSqlQueryModel();
            mod->setQuery("select REF from PRODUIT WHERE REF ='"+val+"' ");
            ui->idmodif->setModel(mod);
            ui->stackedWidget->setCurrentIndex(2);
            ui->lineEdit_5->setText(q.value(1).toString());
            ui->lineEdit_6->setText(q.value(2).toString());
            ui->lineEdit_7->setText(q.value(3).toString());
            ui->comboBox_4->setCurrentText(q.value(4).toString());
        }
    }


}

void MainWindow::on_modif_clicked()
{
    QString ref=ui->idmodif->currentText();
    QString nom=ui->lineEdit_5->text();
    int stock=ui->lineEdit_6->text().toInt();
    int prix=ui->lineEdit_7->text().toInt();
    int x=0;
    if(ref=="")
    {
        QMessageBox::critical(nullptr, QObject::tr("WARNING"),
                    QObject::tr("la refernce est vide"), QMessageBox::Ok);
              x++;
    }
    else if(nom=="")
    {
        QMessageBox::critical(nullptr, QObject::tr("WARNING"),
                    QObject::tr("la nom est vide"), QMessageBox::Ok);
              x++;
    }
    else if(x==0)
    {
        produit p(ref,nom,stock,prix);
        bool t=p.modifierp(ref);
        if(t)
        {
            QMessageBox::information(nullptr, QObject::tr("produit modifier"),
                              QObject::tr("base de données mise à jour"), QMessageBox::Ok);
            ui->idmodif->clear();
            ui->lineEdit_5->clear();
            ui->lineEdit_6->clear();
            ui->lineEdit_7->clear();
            ui->stackedWidget->setCurrentIndex(0);
        }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("WARNING"),
                        QObject::tr("Veuillez réessayer"), QMessageBox::Ok);
            ui->idmodif->clear();
            ui->lineEdit_5->clear();
            ui->lineEdit_6->clear();
            ui->lineEdit_7->clear();
        }
    }


}

void MainWindow::on_trie_clicked()
{
    ui->produit_2->setModel(tabproduit.triep());
}

void MainWindow::on_ajoutf_clicked()
{
    QString matricule =ui->lineEdit_m->text();
    QString nom=ui->lineEdit_n->text();
    QString adresse=ui->lineEdit_a->text();
    QString email=ui->lineEdit_e->text();
    int tel=ui->lineEdit_t->text().toInt();
     int x=0;
    string str_tel = to_string(tel);
    string m = email.toStdString();
    if(matricule=="")
    {
        QMessageBox::critical(nullptr, QObject::tr("WARNING"),
                    QObject::tr("la matricule est vide"), QMessageBox::Ok);
              x++;
    }
    else if(nom=="")
    {
        QMessageBox::critical(nullptr, QObject::tr("WARNING"),
                    QObject::tr("le nom est vide"), QMessageBox::Ok);
              x++;
    }
    else if(adresse=="")
    {
        QMessageBox::critical(nullptr, QObject::tr("WARNING"),
                    QObject::tr("l'adress est vide"), QMessageBox::Ok);
              x++;
    }
    else if(m.find("@gmail.com")== std:: string::npos)
    {
        QMessageBox::critical(nullptr, QObject::tr("WARNING"),
                    QObject::tr("Email must end with @gmail.com"), QMessageBox::Ok);
              x++;
    }
    else if(str_tel.length()!=8)
    {
        QMessageBox::critical(nullptr, QObject::tr("WARNING"),
                    QObject::tr("Phone number must be composed of 8 numbers"), QMessageBox::Ok);
              x++;
    }
    else if(x==0)
    {
        fournisseur f(matricule,nom,adresse,email,tel);
        bool t=f.ajouterf();
        if(t)
        {
            QMessageBox::information(nullptr, QObject::tr("fournisseur ajouter"),
                              QObject::tr("base de données mise à jour"), QMessageBox::Ok);
            ui->lineEdit_m->clear();
            ui->lineEdit_n->clear();
            ui->lineEdit_a->clear();
            ui->lineEdit_e->clear();
            ui->lineEdit_t->clear();
            //ui->stackedWidget->setCurrentIndex(0);
        }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("WARNING"),
                        QObject::tr("Veuillez réessayer"), QMessageBox::Ok);
        }
    }

}

void MainWindow::on_toolButton_AF_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);
}

void MainWindow::on_toolButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);

}

void MainWindow::on_toolButton_fromajoutf_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);

}

void MainWindow::on_toolButton_AFF_clicked()
{
    ui->stackedWidget->setCurrentIndex(8);
    ui->fournisseurtable->setModel(tabfour.afficherf());
}

void MainWindow::on_toolButton_7_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}

void MainWindow::on_toolButton_SF_clicked()
{
    ui->stackedWidget->setCurrentIndex(9);
    ui->tableView_3->setModel(tabfour.afficherf());
    ui->comboBox_3->setModel(tabfour.affichercf());
    /*QSqlQueryModel *mod= new QSqlQueryModel();
    mod->setQuery("select MATRICULE from fournisseur ");
    ui->comboBox_3->setModel(mod);*/

}

void MainWindow::on_toolButton_8_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}

void MainWindow::on_tableView_3_activated(const QModelIndex &index)
{
    QString val=ui->produit_2->model()->data(index).toString();

   qDebug() << val ;
    //QSqlQueryModel *mod= new QSqlQueryModel();
    //mod->setQuery("select MATRICULE from fournisseur WHERE MATRICULE ='"+val+"' ");
    //ui->comboBox_3->setModel(mod);




}

void MainWindow::on_idmodif_currentIndexChanged(const QString &arg1)
{

    QString val=ui->idmodif->currentText();
    QSqlQuery q;
    q.prepare("select * from produit where ref='"+val+"'");
    if(q.exec())
    {
        while(q.next())
        {
            ui->lineEdit_5->setText(q.value(1).toString());
            ui->lineEdit_6->setText(q.value(2).toString());
            ui->lineEdit_7->setText(q.value(3).toString());
            ui->comboBox_4->setCurrentText(q.value(4).toString());
        }
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("WARNING"),
                    QObject::tr("Veuillez réessayer"), QMessageBox::Ok);
    }


}

void MainWindow::on_tableView_activated(const QModelIndex &index)
{
    QString val=ui->tableView->model()->data(index).toString();
    QSqlQuery q;
    q.prepare("SELECT * FROM PRODUIT WHERE REF = '"+val+"' OR NOM = '"+val+"' OR STOCK = '"+val+"' OR PRIX = '"+val+"' ");
    if(q.exec())
    {
        while(q.next())
        {
            ui->comboBox->setCurrentText(q.value(0).toString());
        }
    }

}

void MainWindow::on_toolButton_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_toolButton_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_rech_clicked()
{
    QString m=ui->recherche->text();
    ui->fournisseurtable->setModel(tabfour.cherchef(m));
}

void MainWindow::on_cherchep_clicked()
{
    QString ref=ui->cherchp->text();
    ui->produit_2->setModel(tabproduit.recherchep(ref));
}

void MainWindow::on_pl_clicked()
{
    QString login=ui->login->text();
    QString pwd=ui->pwd->text();
    int x=0;
    QSqlQuery q;
    if(login=="")
    {
        QMessageBox::critical(nullptr, QObject::tr("WARNING"),
                    QObject::tr("login vide"), QMessageBox::Ok);
        x++;
    }
    else if (pwd=="")
    {
        QMessageBox::critical(nullptr, QObject::tr("WARNING"),
                    QObject::tr("mot de passe vide"), QMessageBox::Ok);
        x++;
    }
    else if(x==0)
    {
        q.prepare("select LOGIN from COMPTE where LOGIN=:login AND PWD=:PWD ");
        q.bindValue(":login",login);
        q.bindValue(":PWD",pwd);
        if(q.exec())
        {   if(login=="admin"&&pwd=="admin")
            {
            QMessageBox::information(nullptr, QObject::tr("E_pastry"),
                        QObject::tr("Bienvenue"), QMessageBox::Cancel);
            ui->stackedWidget->setCurrentIndex(5);
            }
            else
                QMessageBox::critical(nullptr, QObject::tr("WARNING"),
                            QObject::tr("Veuillez réessayer"), QMessageBox::Ok);
        }
        else
            QMessageBox::critical(nullptr, QObject::tr("WARNING"),
                        QObject::tr("Veuillez réessayer"), QMessageBox::Ok);
    }


}


void MainWindow::on_pushButton_modf_clicked()
{
    QString matricule =ui->comboBox_mat->currentText();
    QString nom=ui->lineEdit_nf->text();
    int tel=ui->lineEdit_numf->text().toInt();
    QString adresse=ui->lineEdit_ad->text();
    QString email=ui->lineEdit_mail->text();
    int x=0;
    string str_tel = to_string(tel);
    string m = email.toStdString();
    if(matricule=="")
    {
        QMessageBox::critical(nullptr, QObject::tr("WARNING"),
                    QObject::tr("la matricule est vide"), QMessageBox::Ok);
              x++;
    }
    else if(nom=="")
    {
        QMessageBox::critical(nullptr, QObject::tr("WARNING"),
                    QObject::tr("le nom est vide"), QMessageBox::Ok);
              x++;
    }
    else if(adresse=="")
    {
        QMessageBox::critical(nullptr, QObject::tr("WARNING"),
                    QObject::tr("l'adress est vide"), QMessageBox::Ok);
              x++;
    }
    else if(m.find("@gmail.com")== std:: string::npos)
    {
        QMessageBox::critical(nullptr, QObject::tr("WARNING"),
                    QObject::tr("Email must end with @gmail.com"), QMessageBox::Ok);
              x++;
    }
    else if(str_tel.length()!=8)
    {
        QMessageBox::critical(nullptr, QObject::tr("WARNING"),
                    QObject::tr("Phone number must be composed of 8 numbers"), QMessageBox::Ok);
              x++;
    }
    else if(x==0)
    {
        fournisseur f(matricule,nom,adresse,email,tel);
        bool t=f.modifierf(matricule);
        if(t)
        {
            QMessageBox::information(nullptr, QObject::tr("fournisseur ajouter"),
                              QObject::tr("base de données mise à jour"), QMessageBox::Ok);
            ui->lineEdit_nf->clear();
            ui->lineEdit_numf->clear();
            ui->lineEdit_ad->clear();
            ui->lineEdit_mail->clear();
            ui->stackedWidget->setCurrentIndex(6);
        }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("WARNING"),
                        QObject::tr("Veuillez réessayer"), QMessageBox::Ok);
        }
    }

}

void MainWindow::on_toolButton_MF_clicked()
{
    ui->stackedWidget->setCurrentIndex(11);
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("select MATRICULE from FOURNISSEUR");
    ui->comboBox_mat->setModel(model);

}

void MainWindow::on_comboBox_mat_currentIndexChanged(const QString &arg1)
{
    QString val=ui->comboBox_mat->currentText();
    QSqlQuery q;
    q.prepare("select * from FOURNISSEUR where matricule = '"+val+"'");
    if(q.exec())
    {
        while(q.next())
        {
            ui->lineEdit_nf->setText(q.value(1).toString());
            ui->lineEdit_numf->setText(q.value(4).toString());
            ui->lineEdit_ad->setText(q.value(2).toString());
            ui->lineEdit_mail->setText(q.value(3).toString());

        }
    }

}

void MainWindow::on_fournisseurtable_activated(const QModelIndex &index)
{
    QString val=ui->fournisseurtable->model()->data(index).toString();
    QSqlQuery q;
    q.prepare("select * from FOURNISSEUR where matricule = '"+val+"'");
    if(q.exec())
    {
        ui->stackedWidget->setCurrentIndex(11);
        while(q.next())
        {
            ui->comboBox_mat->setCurrentText(q.value(0).toString());
            ui->lineEdit_nf->setText(q.value(1).toString());
            ui->lineEdit_numf->setText(q.value(4).toString());
            ui->lineEdit_ad->setText(q.value(2).toString());
            ui->lineEdit_mail->setText(q.value(3).toString());

        }
    }


}

void MainWindow::on_frommod_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);

}

void MainWindow::on_stop_clicked()
{
    Player->stop();
}

void MainWindow::on_start_clicked()
{
    Player->setMedia(QUrl::fromLocalFile("C:/Users/ASUS/Music/Kalash - Mwaka Moon ft. Damso.mp3"));
    Player->play();
    qDebug() << Player->errorString();
}

void MainWindow::on_horizontalSlider_sliderMoved(int position)
{
    Player->setVolume(position);
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(12);
    ui->tableView_mailing->setModel(tabproduit.mailing());

}

void MainWindow::on_frommaling_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}
