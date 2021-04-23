#include "securite.h"
#include "ui_securite.h"
#include<qdebug.h>
securite::securite(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::securite)
{
    ui->setupUi(this);
    // arduino
          int ret=Arduino.connect_arduino();
          switch(ret){
          case(0):qDebug()<< "arduino is availble and connected to :"<< Arduino.getarduino_port_name();
              break;
          case(1):qDebug()<< "arduino is availble but not connected to :"<< Arduino.getarduino_port_name();
              break;
          case(-1):qDebug()<< "arduino is not availble";
          }
          QObject::connect(Arduino.getserial(),SIGNAL(readyRead()),this,SLOT(update_temperature()));
DataAsString="";
          //fin arduino
}
void securite::update_temperature()
{

    //lamina l data w nafichiwha ki ta5let lel 5 caratcteres
    // 5ater ldata dji d'une façons discontinu par exemple l temperature "21.50" ta5let data="2" mbaed data="1.5" data="0"
    if(DataAsString.length()<5)
    {
        data=Arduino.read_from_arduino();
        DataAsString += QString(data);

    }
    else {
            qDebug()<< DataAsString;

            //naffichiw ldata afficher temperature
            ui->label_temperature->setText("Temperature : "+DataAsString+"°C");




           //WRITE TO ARDUINO

           //on change la couleur si data >=21 :rouge sinon bleu
            if( DataAsString >="21")
            {
                ui->label_temperature->setStyleSheet("QLabel {font: 75 16pt 'Script MT Bold';background-color: rgb(255, 0, 0);color: rgb(0, 0, 127);}");
                //WRITE TO ARDUINO allumer led rouge
                Arduino.write_to_arduino("1");
            }
            else if(DataAsString < "21")
              {
               ui->label_temperature->setStyleSheet("QLabel {font: 75 16pt 'Script MT Bold';background-color: rgb(0, 0, 127);color: rgb(255, 0, 0);}");
               //WRITE TO ARDUINO allumer led bleu
               Arduino.write_to_arduino("0");
              }


            DataAsString="";
         }




}


securite::~securite()
{
    delete ui;
}
