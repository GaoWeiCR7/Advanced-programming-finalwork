#include "admin__info_look.h"
#include "ui_admin__info_look.h"

admin__info_look::admin__info_look(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::admin__info_look)
{
    ui->setupUi(this);
}

admin__info_look::~admin__info_look()
{
    delete ui;
}

void admin__info_look::infolook(admininfo admin,bool flag)
{
    QStandardItemModel *model = new QStandardItemModel();
    ui->tableView->setModel(model);
    model->setColumnCount(2);
    model->setHeaderData(0,Qt::Horizontal,"ID");
    model->setHeaderData(1,Qt::Horizontal,"姓名");
    if(true == flag)
    {
        for(int i = 0; i < admin.stu.size(); ++i)
        {
            QString str = QString::number(admin.stu[i].id);
            model->setItem(i,0,new QStandardItem(str));
            model->item(i,0)->setTextAlignment(Qt::AlignCenter);
            model->setItem(i,1,new QStandardItem(admin.stu[i].name));
            model->item(i,1)->setTextAlignment(Qt::AlignCenter);
        }
    }
    else
    {
        for(int i = 0; i < admin.tea.size(); ++i)
        {
            QString str = QString::number(admin.tea[i].id);
            model->setItem(i,0,new QStandardItem(str));
            model->item(i,0)->setTextAlignment(Qt::AlignCenter);
            model->setItem(i,1,new QStandardItem(admin.tea[i].name));
            model->item(i,1)->setTextAlignment(Qt::AlignCenter);
        }
    }
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
}
