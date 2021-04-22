#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QComboBox>
#include <QSpinBox>
#include<QIntValidator>
#include<QValidator>
#include<QFileDialog>
#include"commande.h"
#include"livraison.h"
#include"smtp.h"
#include<QtPrintSupport/QPrinter>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit_2->setValidator(new QIntValidator(0,99999,this));
     ui->lineEdit_5->setValidator(new QIntValidator(0,99999,this));
     connect(ui->sendBtn, SIGNAL(clicked()),this, SLOT(sendMail()));
     connect(ui->exitBtn, SIGNAL(clicked()),this, SLOT(close()));
     connect(ui->browseBtn, SIGNAL(clicked()), this, SLOT(browse()));
ui->tableView->setModel(tmpcommande.afficher());
ui->tableView_2->setModel(tmplivraison.afficher());
ui->comboLiv->setModel(tmpcommande.affecter_Livraison());
ui->comboClient->setModel(tmpcommande.affecter_client());
ui->comboLiv_2->setModel(tmpcommande.affecter_Livraison());
ui->comboClient_2->setModel(tmpcommande.affecter_client());
ui->comboCommande->setModel(tmpcommande.affecter_commande());
ui->comboCommande_2->setModel(tmpcommande.affecter_commande());
ui->combols->setModel(tmpcommande.affecter_Livraison());
ui->combolk->setModel(tmpcommande.affecter_Livraison());
ui->comboCat->setModel(tmpcommande.affecter_categorie());
ui->comboCat2->setModel(tmpcommande.affecter_categorie());
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

    ui->file_2->setText( fileListString );

}

void MainWindow::sendMail()
{
    Smtp* smtp = new Smtp(ui->uname_2->text(), ui->paswd_2->text(), ui->server_2->text(), ui->port_2->text().toInt());
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

    if( !files.isEmpty() )
        smtp->sendMail(ui->uname_2->text(), ui->rcpt_2->text() , ui->subject_2->text(),ui->msg_2->toPlainText(), files );
    else
        smtp->sendMail(ui->uname_2->text(), ui->rcpt_2->text() , ui->subject_2->text(),ui->msg_2->toPlainText());
}

void MainWindow::mailSent(QString status)
{
    if(status == "Message sent")
        QMessageBox::warning( 0, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_4_clicked()

    {
        int num_l = ui->comboLiv->currentText().toInt();
            int id_com = ui->lineEdit_5->text().toInt();

            QString nom_cat= ui->comboCat->currentText();


            QString nom_cl= ui->comboClient->currentText();

          Commande c(id_com,num_l,nom_cl,nom_cat);
          bool test=c.ajouter();
          if(test)
        {
              ui->comboCommande_2->setModel(tmpcommande.affecter_commande());
              ui->comboCommande->setModel(tmpcommande.affecter_commande());

              ui->tableView->setModel(tmpcommande.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Ajouter une commande"),
                          QObject::tr("Commande ajoutée.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);

        }
          else
              QMessageBox::critical(nullptr, QObject::tr("Ajouter une commande"),
                          QObject::tr("Erreur !\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
    }



void MainWindow::on_pushButton_6_clicked()
{
    int id_com = ui->comboCommande_2->currentText().toInt();
    bool test=tmpcommande.supprimer(id_com);
    if(test)
    {ui->tableView->setModel(tmpcommande.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer une commande"),
                    QObject::tr("commande supprimée.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer une commande"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_7_clicked()
{
    {
        int id_com = ui->comboCommande->currentText().toInt();
        int num_l = ui->comboLiv_2->currentText().toInt();

        QString nom_cl = ui->comboClient_2->currentText();
        QString nom_cat = ui->comboCat2->currentText();

        Commande c;
        bool test=c.modifier(id_com,num_l,nom_cat,nom_cl);

        if(test)
        {
            QMessageBox::information(nullptr, QObject::tr("modifier une commande"),
                              QObject::tr("commande modifiee.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
        }
        else
            QMessageBox::critical(nullptr, QObject::tr("non modifie"),
                        QObject::tr("Erreur !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
            ui->tableView->setModel(tmpcommande.afficher());

    }
}




void MainWindow::on_pushButton_clicked()
{ int num_l = ui->lineEdit_2->text().toInt();
    int prix_l = ui->lineEdit->text().toInt();
    QString datel= ui->lineEdit_15->text();
    QString adr_c= ui->lineEdit_17->text();

  Livraison l(num_l,prix_l,datel,adr_c);
  bool test=l.ajouter();
  if(test)
{

      ui->tableView_2->setModel(tmplivraison.afficher());//refresh
      ui->comboLiv->setModel(tmpcommande.affecter_Livraison());
      ui->combols->setModel(tmpcommande.affecter_Livraison());
      ui->combolk->setModel(tmpcommande.affecter_Livraison());
QMessageBox::information(nullptr, QObject::tr("Ajouter une livraison"),
                  QObject::tr("Livraison ajoutée.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter une livraison"),
                  QObject::tr("Erreur !\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_pushButton_2_clicked()
{{
        int prix_l = ui->lineEdit_7->text().toInt();
        int num_l = ui->combolk->currentText().toInt();

        QString datel = ui->lineEdit_18->text();
        QString adr_c = ui->lineEdit_19->text();

       Livraison l;
        bool test=l.modifier(num_l,prix_l,datel,adr_c);

        if(test)
        {
            QMessageBox::information(nullptr, QObject::tr("modifie une livraison"),
                              QObject::tr("Livraison modifiee.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
        }
        else
            QMessageBox::critical(nullptr, QObject::tr("non modifie"),
                        QObject::tr("Erreur !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
            ui->tableView_2->setModel(tmplivraison.afficher());

    }

}

void MainWindow::on_pushButton_3_clicked()
{
    int num_l = ui->combols->currentText().toInt();
    bool test=tmplivraison.supprimer(num_l);
    if(test)
    {ui->tableView_2->setModel(tmplivraison.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer une livraison"),
                    QObject::tr("livraison supprimée.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer une livraison"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_14_clicked()
{
    {ui->tableView->setModel(tmpcommande.tri());

    }
}



void MainWindow::on_pushButton_12_clicked()
{
ui->tableView_2->setModel(tmplivraison.tri());
    }








void MainWindow::on_lineEdit_10_cursorPositionChanged(int arg1, int arg2)
{
    QString rech =ui->lineEdit_10->text();

     ui->tableView->setModel(tmpcommande.rechercher(rech));

}

void MainWindow::on_lineEdit_20_cursorPositionChanged(int arg1, int arg2)
{
    QString rech =ui->lineEdit_20->text();

       ui->tableView_2->setModel(tmplivraison.rechercher(rech));
}






void MainWindow::on_pushButton_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    QString utilisateur=ui->username->text();
        QString mdp=ui->password->text();
    MainWindow w;
        if ((utilisateur=="eya")&&(mdp=="eya"))
        {

            //w.show();

        }

        else{ QMessageBox::critical(nullptr, QObject::tr("Problème de connexion"),
                                          QObject::tr("Veuillez revérifier vos informations"), QMessageBox::Cancel);

            hide();
        }
}

void MainWindow::on_pushButton_8_clicked()
{
    QString strStream;
                     QTextStream out(&strStream);

                     const int rowCount = ui->tableView->model()->rowCount();
                     const int columnCount = ui->tableView->model()->columnCount();
                     QString TT = QDateTime::currentDateTime().toString("yyyy/MM/dd hh:mm:ss");
                     out <<  "<html>\n"
                         "<head>\n"
                         "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                         <<  QString("<title>%1</title>\n").arg("strTitle")
                         <<  "</head>\n"
                         "<body bgcolor=#E7E7E7 link=#5000A1>\n"

                            "<h1 style=\"text-align: center;\"><strong> ********Liste Des Commandes******** "+TT+"</strong></h1>"
                        //     "<align='right'> " << datefich << "</align>"
                         "<center></br><table border=3 cellspacing=1 cellpadding=2>\n";

                     // headers
                     out << "<thead><tr bgcolor=#FFF9F6> <th>Numero</th>";
                     for (int column = 0; column < columnCount; column++)
                         if (!ui->tableView->isColumnHidden(column))
                             out << QString("<th>%1</th>").arg(ui->tableView->model()->headerData(column, Qt::Horizontal).toString());
                     out << "</tr></thead>\n";

                     // data table
                     for (int row = 0; row < rowCount; row++) {
                         out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
                         for (int column = 0; column < columnCount; column++) {
                             if (!ui->tableView->isColumnHidden(column)) {
                                 QString data = ui->tableView->model()->data(ui->tableView->model()->index(row, column)).toString().simplified();
                                 out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                             }
                         }
                         out << "</tr>\n";
                     }
                     out <<  "</table> </center>\n"

                         "</body>\n"

                         "</html>\n";

               QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Sauvegarder en PDF", QString(), "*.pdf");
                 if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

                QPrinter printer (QPrinter::PrinterResolution);
                 printer.setOutputFormat(QPrinter::PdfFormat);
                printer.setPaperSize(QPrinter::A4);
               printer.setOutputFileName(fileName);

                QTextDocument doc;
                 doc.setHtml(strStream);
                 doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
                 doc.print(&printer);
}

void MainWindow::on_pushButton_9_clicked()
{ ui->stackedWidget->setCurrentIndex(1);
    QString utilisateur=ui->username->text();
        QString mdp=ui->password->text();
    MainWindow w;
        if ((utilisateur=="eya")&&(mdp=="eya"))
        {

            //w.show();

        }

        else{ QMessageBox::critical(nullptr, QObject::tr("Problème de connexion"),
                                          QObject::tr("Veuillez revérifier vos informations"), QMessageBox::Cancel);

            hide();
        }
}

