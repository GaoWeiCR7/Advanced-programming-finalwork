#include "newcourse_add.h"
#include "ui_newcourse_add.h"

newcourse_add::newcourse_add(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::newcourse_add)
{
    ui->setupUi(this);
}

newcourse_add::~newcourse_add()
{
    delete ui;
}

void newcourse_add::on_addok_clicked()
{
    c.id = ui->addid->text().toInt();
    c.name = ui->addname->text();
    c.score = ui->addscore->text().toInt();
    c.time = ui->addtime->text();
    c.maxnum = ui->addmaxnum->text().toInt();
    accept();
}
