#ifndef FORMAJOUT_H
#define FORMAJOUT_H

#include <QDialog>

namespace Ui {
class formajout;
}

class formajout : public QDialog
{
    Q_OBJECT

public:
    explicit formajout(QWidget *parent = nullptr);
    ~formajout();

private:
    Ui::formajout *ui;
};

#endif // FORMAJOUT_H
