#include "loginshow.h"
#include "ui_loginshow.h"

loginshow::loginshow(int x,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::loginshow),judge(x)
{
    ui->setupUi(this);
}

loginshow::~loginshow()
{
    delete ui;
}

void loginshow::on_loginok_clicked()
{
    t.id = ui->loginid->text().toInt();
    t.name = ui->loginname->text();
    t.password = ui->loginpass->text();
    if(judge == 1)
    {
        QString temp = "../"+ui->loginid->text()+ui->loginname->text()+"stu.txt";
        QFile file;
        file.setFileName(temp);
        bool isOK = file.open(QIODevice::ReadOnly);
        if(!isOK)
        {
            cout << "open failed!" << endl;
            QMessageBox::warning(this,tr("警告！"),tr("该用户不存在"),QMessageBox::Yes);
            ui->loginid->clear();
            ui->loginname->clear();
            ui->loginpass->clear();
            ui->loginid->setFocus();
            return;
        }
        QTextStream in(&file);
        QString line = in.readLine();
        int a = line.section(',',0,0).toInt();
        QString b = line.section(',',1,1);
        QString c = line.section(',',2,2);
        file.close();
        if((t.id == a)&&(t.name == b)&&(t.password == c))
        {
            accept();
            return;
        }
        else
        {
            QMessageBox::warning(this,tr("警告！"),tr("密码错误"),QMessageBox::Yes);
            ui->loginid->clear();
            ui->loginname->clear();
            ui->loginpass->clear();
            ui->loginid->setFocus();
            return;
        }
    }
    else if(judge == 2)
    {
        QString temp = "../"+ui->loginid->text()+ui->loginname->text()+"tea.txt";
        QFile file;
        file.setFileName(temp);
        bool isOK = file.open(QIODevice::ReadOnly);
        if(!isOK)
        {
            cout << "open failed!" << endl;
            QMessageBox::warning(this,tr("警告！"),tr("该用户不存在"),QMessageBox::Yes);
            ui->loginid->clear();
            ui->loginname->clear();
            ui->loginpass->clear();
            ui->loginid->setFocus();
            return;
        }
        QTextStream in(&file);
        QString line = in.readLine();
        int a = line.section(',',0,0).toInt();
        QString b = line.section(',',1,1);
        QString c = line.section(',',2,2);
        file.close();
        if((t.id == a)&&(t.name == b)&&(t.password == c))
        {
            accept();
            return;
        }
        else
        {
            QMessageBox::warning(this,tr("警告！"),tr("密码错误"),QMessageBox::Yes);
            ui->loginid->clear();
            ui->loginname->clear();
            ui->loginpass->clear();
            ui->loginid->setFocus();
            return;
        }
    }
}
