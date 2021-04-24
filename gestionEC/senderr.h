#ifndef SENDERR_H
#define SENDERR_H

#include <QSslSocket>
#include <QMainWindow>

namespace Ui {
  class sender;
}

class sender : public QMainWindow
{
  Q_OBJECT

public:
  explicit sender(QWidget *parent = 0);
  ~sender();

protected slots:
  // Slots to receive signals from UI
  void connectDisconnectButtonPressed();
  void sendButtonPressed();

  // Slots to receive signals from QSslSocket
  void connectedToServer();
  void sslErrors(const QList<QSslError> &errors);
  void receiveMessage();
  void connectionClosed();
  void socketError();

private:
  QSslSocket socket;
  Ui::sender *ui;
};

#endif // SENDERR_H
