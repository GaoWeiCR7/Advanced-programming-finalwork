#ifndef ADMIN__INFO_LOOK_H
#define ADMIN__INFO_LOOK_H

#include <QDialog>
#include <mainwindow.h>


namespace Ui {
class admin__info_look;
}

class admin__info_look : public QDialog
{
    Q_OBJECT

public:
    explicit admin__info_look(QWidget *parent = nullptr);
    ~admin__info_look();
    void infolook(admininfo admin,bool flag);

private:
    Ui::admin__info_look *ui;
};

#endif // ADMIN__INFO_LOOK_H
