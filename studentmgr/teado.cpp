#include "teado.h"
#include "ui_teado.h"
#include "courseshow.h"
#include "newcourse_add.h"
#include "course_info_change.h"
#include "namelistshow.h"
#include "changestuscoreshow.h"

teado::teado(admintempnode x,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::teado),tea(x.id, x.name, x.password)
{
    ui->setupUi(this);
    QString idstr = QString::number(tea.id);
    QString str = "../"+idstr+tea.name+"tea.txt";
    QFile file;
    file.setFileName(str);
    bool isOK = file.open(QIODevice::ReadOnly);
    if(!isOK)
        cout << "open failed!" << endl;
    QVector <QString> t;
    QTextStream in(&file);
    QString temp = in.readLine();
    while(!in.atEnd())
    {
        temp = in.readLine();
        t.push_back(temp);
    }
    file.close();
    for(int i = 0; i < t.size(); ++i)
    {
        QString name = "../"+t[i] + ".txt";
        QFile file2;
        file2.setFileName(name);
        isOK = file2.open(QIODevice::ReadOnly);
        if(!isOK)
            cout << "open failed!" << endl;
        QTextStream in2(&file2);
        QString line = in2.readLine();
        file2.close();
        courseinfo c;
        c.id = line.section(',',0,0).toInt();
        c.name = line.section(',',1,1);
        c.score = line.section(',',2,2).toInt();
        c.teacher = line.section(',',3,3);
        c.time = line.section(',',4,4);
        c.num = line.section(',',5,5).toInt();
        c.maxnum = line.section(',',6,6).toInt();
        tea.mycourse.push_back(c);
    }
}

teado::~teado()
{
    delete ui;
}

void teado::on_courselook_clicked()
{
    courseshow c;
    c.mycourseshow(tea);
    c.exec();
}

void teado::on_courseadd_clicked()
{
    newcourse_add c;
    if(c.exec() == QDialog::Accepted)
    {
        courseinfo cour;
        cour = c.getinfo();
        for(int i = 0; i < courselist.size(); ++i)
        {
            if(courselist[i].id == cour.id)
            {
                QMessageBox::warning(this,tr("警告！"),tr("该课程id已存在"),QMessageBox::Yes);
                return;
            }
        }
        cour.teacher = tea.name;
        cour.num = 0;
        courselist.push_back(cour);
        tea.mycourse.push_back(cour);
        QString idstr = QString::number(cour.id);
        QString str = "../"+idstr + cour.name + ".txt";
        QFile file;
        file.setFileName(str);
        bool isOK = file.open(QIODevice::Text|QIODevice::WriteOnly);
        if(!isOK)
            cout << "open failed!" << endl;
        QTextStream out(&file);
        out << cour.id << ',';
        out << cour.name << ',';
        out << cour.score << ',';
        out << cour.teacher << ',';
        out << cour.time << ',';
        out << cour.num << ',';
        out << cour.maxnum;
        QMessageBox::warning(this,tr("提示！"),tr("添加成功"),QMessageBox::Yes);
    }
}

void teado::on_coursedel_clicked()
{
    course_info_change c;
    if(c.exec() == QDialog::Accepted)
    {
        courseinfo cour;
        cour = c.getinfo();
        for(int i = 0; i < tea.mycourse.size(); ++i)
        {
            if(cour.id == tea.mycourse[i].id && cour.name == tea.mycourse[i].name)
            {
                QString idstr = QString::number(tea.mycourse[i].id);
                QString str = "../" + idstr + tea.mycourse[i].name + ".txt";
                tea.mycourse.erase(i + tea.mycourse.begin());
                for(int j = 0; j < courselist.size(); ++j)
                {
                    if(courselist[j].id == cour.id)
                        courselist.erase(j + courselist.begin());
                }
                remove(str.toLocal8Bit());
                QMessageBox::warning(this,tr("提示！"),tr("删除成功"),QMessageBox::Yes);
                return;
            }
            else if(cour.id == tea.mycourse[i].id && cour.name != tea.mycourse[i].name)
            {
                i = -1;
                QMessageBox::warning(this,tr("警告！"),tr("ID与课程名不对应"),QMessageBox::Yes);
                return;
            }
        }
        QMessageBox::warning(this,tr("警告！"),tr("未发布该课程，无法删除"),QMessageBox::Yes);
    }
}

void teado::on_listlook_clicked()
{
    course_info_change c;
    if(c.exec() == QDialog::Accepted)
    {
        courseinfo cour;
        cour = c.getinfo();
        for(int i = 0; i < tea.mycourse.size(); ++i)
        {
            if(cour.id == tea.mycourse[i].id && cour.name == tea.mycourse[i].name)
            {
                for(int j = 0; j < courselist.size(); ++j)
                {
                    if(cour.id == courselist[j].id)
                    {
                        namelistshow nl;
                        nl.coursenamelistshow(courselist[j]);
                        nl.exec();
                        return;
                    }
                }
            }
            else if(cour.id == tea.mycourse[i].id && cour.name != tea.mycourse[i].name)
            {
                i = -1;
                QMessageBox::warning(this,tr("警告！"),tr("ID与课程名不对应"),QMessageBox::Yes);
                return;
            }
        }
        QMessageBox::warning(this,tr("警告！"),tr("未发布该课程，无法查看选课名单"),QMessageBox::Yes);
    }
}

void teado::on_scorechange_clicked()
{
    changestuscoreshow css;
    if(css.exec() == QDialog::Accepted)
    {
        changescorenode x;
        x = css.csshow();
        for(int i = 0; i < courselist.size(); ++i)
        {
            if(courselist[i].id == x.courseid)
            {
                for(int j = 0; j < courselist[i].p.size(); ++j)
                {
                    if(courselist[i].p[j].id == x.stuid)
                    {
                        courselist[i].p[j].score = x.score;
                        QMessageBox::warning(this,tr("提示！"),tr("修改成绩成功"),QMessageBox::Yes);
                        return;
                    }
                }
                QMessageBox::warning(this,tr("警告！"),tr("该学生未选择该门课程"),QMessageBox::Yes);
                return;
            }
        }
        QMessageBox::warning(this,tr("警告！"),tr("未发布该课程，无法修改成绩"),QMessageBox::Yes);
    }
}

void teado::on_loginout_clicked()
{
    QString idstr = QString::number(tea.id);
    QString str = "../"+idstr+tea.name+"tea.txt";
    QFile file;
    file.setFileName(str);
    bool isOK = file.open(QIODevice::Text|QIODevice::WriteOnly);
    if(!isOK)
        cout << "open failed!" << endl;
    QTextStream out(&file);
    out << tea.id << ',' << tea.name << ',' << tea.password;
    int num = tea.mycourse.size();
    //num--;
    for(int i = 0; i < num; ++i)
    {
        out << endl;
        QString cidstr = QString::number(tea.mycourse[i].id);
        QString resstr = cidstr+tea.mycourse[i].name;
        out << resstr;
    }
    /*if(num >= 0)
    {
        QString cidstr = QString::number(tea.mycourse[num].id);
        QString resstr = cidstr+tea.mycourse[num].name;
        out << resstr;
    }*/
    file.close();
    courselist_to_file();
    close();
}
