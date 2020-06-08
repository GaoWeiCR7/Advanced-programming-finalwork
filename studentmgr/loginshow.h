#ifndef LOGINSHOW_H
#define LOGINSHOW_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class loginshow;
}

class loginshow : public QDialog
{
    Q_OBJECT

public:
    explicit loginshow(int x,QWidget *parent = nullptr);
    ~loginshow();
    admintempnode getinfo()
    {
        return t;
    }

private slots:
    void on_loginok_clicked();

private:
    Ui::loginshow *ui;
    admintempnode t;
    int judge;
};

#endif // LOGINSHOW_H
