#include "adminjudge.h"
#include "ui_adminjudge.h"
#include <QMessageBox>

Adminjudge::Adminjudge(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Adminjudge)
{
    ui->setupUi(this);
}

Adminjudge::~Adminjudge()
{
    delete ui;
}

void Adminjudge::on_adminloginbtn_clicked()
{
    if(ui->adminname->text() == tr("admin")&&ui->adminpassword->text() == tr("123456"))
        accept();
    else {
        QMessageBox::warning(this,tr("警告！"),tr("用户名或密码错误！"),QMessageBox::Yes);
        ui->adminname->clear();
        ui->adminpassword->clear();
        ui->adminname->setFocus();
    }
}
