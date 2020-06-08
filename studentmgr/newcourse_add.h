#ifndef NEWCOURSE_ADD_H
#define NEWCOURSE_ADD_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class newcourse_add;
}

class newcourse_add : public QDialog
{
    Q_OBJECT

public:
    explicit newcourse_add(QWidget *parent = nullptr);
    courseinfo getinfo()
    {
        return c;
    }
    ~newcourse_add();

private slots:
    void on_addok_clicked();

private:
    Ui::newcourse_add *ui;
    courseinfo c;
};

#endif // NEWCOURSE_ADD_H
