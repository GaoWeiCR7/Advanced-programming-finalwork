#ifndef ADMINDO_H
#define ADMINDO_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class admindo;
}

class admindo : public QDialog
{
    Q_OBJECT

public:
    explicit admindo(QWidget *parent = nullptr);
    ~admindo();

private slots:

    void on_stulook_clicked();

    void on_tealook_clicked();

    void on_stuin_clicked();

    void on_teain_clicked();

    void on_studel_clicked();

    void on_teadel_clicked();

    void on_loginout_clicked();

private:
    Ui::admindo *ui;
    admininfo admin;
};

#endif // ADMINDO_H
