#ifndef STATUSBAR_MAINTENANCE_H
#define STATUSBAR_MAINTENANCE_H

#include <QDialog>

namespace Ui {
class statusbar_maintenance;
}

class statusbar_maintenance : public QDialog
{
    Q_OBJECT

public:
    explicit statusbar_maintenance(QWidget *parent = nullptr);
    ~statusbar_maintenance();

private:
    Ui::statusbar_maintenance *ui;
};

#endif // STATUSBAR_MAINTENANCE_H
