#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "adminjudge.h"
#include "admindo.h"
#include "loginshow.h"
#include "studo.h"
#include "teado.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QVector<QString> coursestr;
    QFile file;
    file.setFileName("../allcourse.txt");
    bool isOK = file.open(QIODevice::ReadOnly);
    if(!isOK)
        cout << "open failed!" << endl;
    QTextStream in(&file);
    while(!in.atEnd())
    {
        QString str = in.readLine();
        coursestr.push_back(str);
    }
    file.close();
    for(int i = 0; i < coursestr.size(); ++i)
    {
        courseinfo t;
        QString str = "../"+coursestr[i]+".txt";
        QFile file2;
        file2.setFileName(str);
        bool isOK = file2.open(QIODevice::ReadOnly);
        if(!isOK)
            cout << "open failed!" << endl;
        QTextStream in2(&file2);
        QString line = in2.readLine();
        t.id = line.section(',',0,0).toInt();
        t.name = line.section(',',1,1);
        t.score = line.section(',',2,2).toInt();
        t.teacher = line.section(',',3,3);
        t.time = line.section(',',4,4);
        t.num = line.section(',',5,5).toInt();
        t.maxnum = line.section(',',6,6).toInt();
        while(!in2.atEnd())
        {
            line = in2.readLine();
            int a = line.section(',',0,0).toInt();
            QString b = line.section(',',1,1);
            int c = line.section(',',2,2).toInt();
            t.p.push_back({a,b,c});
        }
        courselist.push_back(t);
        file2.close();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_mainadmin_clicked()
{
    Adminjudge adminj_dialog;
    if(adminj_dialog.exec() == QDialog::Accepted)
    {
        QMessageBox::warning(this,tr("提示"),tr("登录成功"),QMessageBox::Yes);
        admindo admin_dialog;
        admin_dialog.exec();
    }
}

void MainWindow::on_mainstu_clicked()
{
    loginshow login_dialog(1);
    if(login_dialog.exec() == QDialog::Accepted)
    {
        QMessageBox::warning(this,tr("提示"),tr("登录成功"),QMessageBox::Yes);
        admintempnode t = login_dialog.getinfo();
        studo stu_dialog(t);
        stu_dialog.exec();
    }
}

void MainWindow::on_maintea_clicked()
{
    loginshow login_dialog(2);
    if(login_dialog.exec() == QDialog::Accepted)
    {
        QMessageBox::warning(this,tr("提示"),tr("登录成功"),QMessageBox::Yes);
        admintempnode t = login_dialog.getinfo();
        teado tea_dialog(t);
        tea_dialog.exec();
    }
}
