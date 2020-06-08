#include "namelistshow.h"
#include "ui_namelistshow.h"

namelistshow::namelistshow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::namelistshow)
{
    ui->setupUi(this);
}

namelistshow::~namelistshow()
{
    delete ui;
}

void namelistshow::coursenamelistshow(courseinfo c)
{
    QStandardItemModel *model = new QStandardItemModel();
    ui->tableView->setModel(model);
    model->setColumnCount(2);
    model->setHeaderData(0,Qt::Horizontal,"学生id");
    model->setHeaderData(1,Qt::Horizontal,"学生名");
    for(int i = 0; i <c.p.size(); ++i)
    {
        QString str0 = QString::number(c.p[i].id);
        model->setItem(i,0,new QStandardItem(str0));
        model->item(i,0)->setTextAlignment(Qt::AlignCenter);
        model->setItem(i,1,new QStandardItem(c.p[i].name));
        model->item(i,1)->setTextAlignment(Qt::AlignCenter);
    }
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
}
