#ifndef CHANGESTUSCORESHOW_H
#define CHANGESTUSCORESHOW_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class changestuscoreshow;
}

class changestuscoreshow : public QDialog
{
    Q_OBJECT

public:
    explicit changestuscoreshow(QWidget *parent = nullptr);
    changescorenode csshow()
    {
        return x;
    }
    ~changestuscoreshow();

private slots:
    void on_changeok_clicked();

private:
    Ui::changestuscoreshow *ui;
    changescorenode x;
};

#endif // CHANGESTUSCORESHOW_H
