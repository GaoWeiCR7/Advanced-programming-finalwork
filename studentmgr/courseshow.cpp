#include "courseshow.h"
#include "ui_courseshow.h"

courseshow::courseshow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::courseshow)
{
    ui->setupUi(this);
}

courseshow::~courseshow()
{
    delete ui;
}

void courseshow::allcourseshow()
{
    QStandardItemModel *model = new QStandardItemModel();
    ui->tableView->setModel(model);
    model->setColumnCount(7);
    model->setHeaderData(0,Qt::Horizontal,"课程id");
    model->setHeaderData(1,Qt::Horizontal,"课程名");
    model->setHeaderData(2,Qt::Horizontal,"学分");
    model->setHeaderData(3,Qt::Horizontal,"课程老师");
    model->setHeaderData(4,Qt::Horizontal,"上课时间");
    model->setHeaderData(5,Qt::Horizontal,"选课人数");
    model->setHeaderData(6,Qt::Horizontal,"课程最大人数");
    for(int i = 0; i < courselist.size(); ++i)
    {
        QString str0 = QString::number(courselist[i].id);
        QString str2 = QString::number(courselist[i].score);
        QString str5 = QString::number(courselist[i].num);
        QString str6 = QString::number(courselist[i].maxnum);
        model->setItem(i,0,new QStandardItem(str0));
        model->item(i,0)->setTextAlignment(Qt::AlignCenter);
        model->setItem(i,1,new QStandardItem(courselist[i].name));
        model->item(i,1)->setTextAlignment(Qt::AlignCenter);
        model->setItem(i,2,new QStandardItem(str2));
        model->item(i,2)->setTextAlignment(Qt::AlignCenter);
        model->setItem(i,3,new QStandardItem(courselist[i].teacher));
        model->item(i,3)->setTextAlignment(Qt::AlignCenter);
        model->setItem(i,4,new QStandardItem(courselist[i].time));
        model->item(i,4)->setTextAlignment(Qt::AlignCenter);
        model->setItem(i,5,new QStandardItem(str5));
        model->item(i,5)->setTextAlignment(Qt::AlignCenter);
        model->setItem(i,6,new QStandardItem(str6));
        model->item(i,6)->setTextAlignment(Qt::AlignCenter);
    }
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

void courseshow::mycourseshow(stuinfo s)
{
    QStandardItemModel *model = new QStandardItemModel();
    ui->tableView->setModel(model);
    model->setColumnCount(5);
    model->setHeaderData(0,Qt::Horizontal,"课程id");
    model->setHeaderData(1,Qt::Horizontal,"课程名");
    model->setHeaderData(2,Qt::Horizontal,"学分");
    model->setHeaderData(3,Qt::Horizontal,"课程老师");
    model->setHeaderData(4,Qt::Horizontal,"上课时间");
    for(int i = 0; i < s.mycourse.size(); ++i)
    {
        QString str0 = QString::number(s.mycourse[i].id);
        QString str2 = QString::number(s.mycourse[i].score);
        model->setItem(i,0,new QStandardItem(str0));
        model->item(i,0)->setTextAlignment(Qt::AlignCenter);
        model->setItem(i,1,new QStandardItem(s.mycourse[i].name));
        model->item(i,1)->setTextAlignment(Qt::AlignCenter);
        model->setItem(i,2,new QStandardItem(str2));
        model->item(i,2)->setTextAlignment(Qt::AlignCenter);
        model->setItem(i,3,new QStandardItem(s.mycourse[i].teacher));
        model->item(i,3)->setTextAlignment(Qt::AlignCenter);
        model->setItem(i,4,new QStandardItem(s.mycourse[i].time));
        model->item(i,4)->setTextAlignment(Qt::AlignCenter);
    }
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

void courseshow::mycourseshow(teainfo t)
{
    QStandardItemModel *model = new QStandardItemModel();
    ui->tableView->setModel(model);
    model->setColumnCount(6);
    model->setHeaderData(0,Qt::Horizontal,"课程id");
    model->setHeaderData(1,Qt::Horizontal,"课程名");
    model->setHeaderData(2,Qt::Horizontal,"学分");
    model->setHeaderData(3,Qt::Horizontal,"上课时间");
    model->setHeaderData(4,Qt::Horizontal,"选课人数");
    model->setHeaderData(5,Qt::Horizontal,"最大选课人数");
    for(int i = 0; i < t.mycourse.size(); ++i)
    {
        QString str0 = QString::number(t.mycourse[i].id);
        QString str2 = QString::number(t.mycourse[i].score);
        QString str4 = QString::number(t.mycourse[i].num);
        QString str5 = QString::number(t.mycourse[i].maxnum);
        model->setItem(i,0,new QStandardItem(str0));
        model->item(i,0)->setTextAlignment(Qt::AlignCenter);
        model->setItem(i,1,new QStandardItem(t.mycourse[i].name));
        model->item(i,1)->setTextAlignment(Qt::AlignCenter);
        model->setItem(i,2,new QStandardItem(str2));
        model->item(i,2)->setTextAlignment(Qt::AlignCenter);
        model->setItem(i,3,new QStandardItem(t.mycourse[i].time));
        model->item(i,3)->setTextAlignment(Qt::AlignCenter);
        model->setItem(i,4,new QStandardItem(str4));
        model->item(i,4)->setTextAlignment(Qt::AlignCenter);
        model->setItem(i,5,new QStandardItem(str5));
        model->item(i,5)->setTextAlignment(Qt::AlignCenter);
    }
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
}
