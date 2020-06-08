#ifndef COURSESHOW_H
#define COURSESHOW_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class courseshow;
}

class courseshow : public QDialog
{
    Q_OBJECT

public:
    explicit courseshow(QWidget *parent = nullptr);
    ~courseshow();
    void allcourseshow();
    void mycourseshow(stuinfo s);
    void mycourseshow(teainfo t);
private:
    Ui::courseshow *ui;
};

#endif // COURSESHOW_H
