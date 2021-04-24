#ifndef ARDUINO_H
#define ARDUINO_H
#include <qbytearray.h>
#include <QtSerialPort/QSerialPort>
#include <qstring.h>

class arduino
{
public: // mÃƒÆ’Ã‚Â©thodes de classe arduino
    arduino();
    int connect_arduino(); //permet de connecter le PC a arduino
    int close_arduino(); // permet de fermer la connexion
    int write_to_arduino( QByteArray ); //envoyer des donnÃƒÆ’Ã‚Â©es vers arduino
    QByteArray read_from_arduino(); //recevoir des donnÃƒÆ’Ã‚Â©es de la carte Arduino
    QSerialPort* getserial();
    QString getarduino_port_name();

private :
    QSerialPort * serial; //Cet objet rassemble des informations(vitesse,bits de donnÃƒÆ’Ã‚Â©es,etc..)
   static const quint16 arduino_uno_vendor_id=9025;
   static const quint16 arduino_uno_producy_id=67;
   QString arduino_port_name;
   bool arduino_is_available;
   QByteArray data; //contenant les donnÃƒÆ’Ã‚Â©es lues a partir de l'arduino


};

#endif // ARDUINO_H
