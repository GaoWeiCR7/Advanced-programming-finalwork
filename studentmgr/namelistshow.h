#ifndef NAMELISTSHOW_H
#define NAMELISTSHOW_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class namelistshow;
}

class namelistshow : public QDialog
{
    Q_OBJECT

public:
    explicit namelistshow(QWidget *parent = nullptr);
    ~namelistshow();
    void coursenamelistshow(courseinfo c);

private:
    Ui::namelistshow *ui;
};

#endif // NAMELISTSHOW_H
