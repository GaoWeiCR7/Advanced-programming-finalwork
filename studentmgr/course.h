#ifndef COURSE_H
#define COURSE_H

#include <QDialog>

namespace Ui {
class course;
}

class course : public QDialog
{
    Q_OBJECT

public:
    explicit course(QWidget *parent = nullptr);
    ~course();

private:
    Ui::course *ui;
};

#endif // COURSE_H
