#ifndef STUDO_H
#define STUDO_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class studo;
}

class studo : public QDialog
{
    Q_OBJECT

public:
    explicit studo(admintempnode x,QWidget *parent = nullptr);
    ~studo();

private slots:
    void on_coursealllook_clicked();

    void on_coursemylook_clicked();

    void on_courseadd_clicked();

    void on_coursedel_clicked();

    void on_coursescorelook_clicked();

    void on_loginout_clicked();

private:
    Ui::studo *ui;
    stuinfo stu;
};

#endif // STUDO_H
