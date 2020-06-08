#ifndef ADMIN_INFO_CHANGE_H
#define ADMIN_INFO_CHANGE_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class admin_info_change;
}

class admin_info_change : public QDialog
{
    Q_OBJECT

public:
    explicit admin_info_change(QWidget *parent = nullptr);
    ~admin_info_change();
    admintempnode getinfo()
    {
        return t;
    }

private slots:
    void on_changeok_clicked();

private:
    Ui::admin_info_change *ui;
    admintempnode t;
};

#endif // ADMIN_INFO_CHANGE_H
