#include "course_info_change.h"
#include "ui_course_info_change.h"

course_info_change::course_info_change(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::course_info_change)
{
    ui->setupUi(this);
}

course_info_change::~course_info_change()
{
    delete ui;
}

void course_info_change::on_changecourseok_clicked()
{
    c.id = ui->changecourseid->text().toInt();
    c.name = ui->changecoursename->text();
    accept();
}
