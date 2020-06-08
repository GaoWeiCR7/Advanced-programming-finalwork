#ifndef COURSE_INFO_CHANGE_H
#define COURSE_INFO_CHANGE_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class course_info_change;
}

class course_info_change : public QDialog
{
    Q_OBJECT

public:
    explicit course_info_change(QWidget *parent = nullptr);
    ~course_info_change();
    courseinfo getinfo()
    {
        return c;
    }

private slots:
    void on_changecourseok_clicked();

private:
    Ui::course_info_change *ui;
    courseinfo c;
};

#endif // COURSE_INFO_CHANGE_H
