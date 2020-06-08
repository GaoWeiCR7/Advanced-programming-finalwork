#ifndef TEADO_H
#define TEADO_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class teado;
}

class teado : public QDialog
{
    Q_OBJECT

public:
    explicit teado(admintempnode x,QWidget *parent = nullptr);
    ~teado();

private slots:
    void on_courselook_clicked();

    void on_courseadd_clicked();

    void on_coursedel_clicked();

    void on_listlook_clicked();

    void on_scorechange_clicked();

    void on_loginout_clicked();

private:
    Ui::teado *ui;
    teainfo tea;
};

#endif // TEADO_H
