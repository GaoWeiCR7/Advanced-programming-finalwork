#include "studo.h"
#include "ui_studo.h"
#include "courseshow.h"
#include "course_info_change.h"

studo::studo(admintempnode x,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::studo),stu(x.id,x.name,x.password)
{
    ui->setupUi(this);
    QString idstr = QString::number(stu.id);
    QString str = "../"+idstr+stu.name+"stu.txt";
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
        if(isOK)
        {
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
            stu.mycourse.push_back(c);
        }
    }
}

studo::~studo()
{
    delete ui;
}

void studo::on_coursealllook_clicked()
{
    courseshow c;
    c.allcourseshow();
    c.exec();
}

void studo::on_coursemylook_clicked()
{
    //cout << stu.id << ' ' << stu.name << endl;
    //cout << stu.mycourse.size() << endl;
    courseshow c;
    c.mycourseshow(stu);
    c.exec();
}

void studo::on_courseadd_clicked()
{
    course_info_change c;
    if(c.exec() == QDialog::Accepted)
    {
        courseinfo cour;
        cour = c.getinfo();
        for(int i = 0; i < courselist.size(); ++i)
        {
            if(cour.id == courselist[i].id&&cour.name == courselist[i].name)
            {
                for(int j = 0; j < stu.mycourse.size(); ++j)
                {
                    if(stu.mycourse[j].id == cour.id)
                    {
                        QMessageBox::warning(this,tr("警告！"),tr("该课程已添加，请勿重复添加"),QMessageBox::Yes);
                        return;
                    }
                }
                if(courselist[i].num == courselist[i].maxnum)
                {
                    QMessageBox::warning(this,tr("警告！"),tr("该课程已满员"),QMessageBox::Yes);
                    return;
                }
                stu.mycourse.push_back(courselist[i]);
                courselist[i].num++;
                courselist[i].p.push_back({stu.id,stu.name,0});
                QMessageBox::warning(this,tr("提示！"),tr("添加成功"),QMessageBox::Yes);
                return;
            }
            else if(cour.id == courselist[i].id&&cour.name!=courselist[i].name)
            {
                i = -1;
                QMessageBox::warning(this,tr("警告！"),tr("ID与课程名不对应"),QMessageBox::Yes);
                return;
            }
        }
        QMessageBox::warning(this,tr("警告！"),tr("未找到课程"),QMessageBox::Yes);
    }
}

void studo::on_coursedel_clicked()
{
    course_info_change c;
    if(c.exec() == QDialog::Accepted)
    {
        courseinfo cour;
        cour = c.getinfo();
        for(int i = 0; i < stu.mycourse.size(); ++i)
        {
            if(cour.id == stu.mycourse[i].id && cour.name == stu.mycourse[i].name)
            {
                stu.mycourse.erase(stu.mycourse.begin()+i);
                courselist[i].num--;
                for(int j = 0; j < courselist[i].p.size(); ++j)
                {
                    if(courselist[i].p[j].id == stu.id)
                        courselist[i].p.erase(courselist[i].p.begin()+j);
                }
                QMessageBox::warning(this,tr("提示！"),tr("退选成功"),QMessageBox::Yes);
                return;
            }
            else if(cour.id == stu.mycourse[i].id && cour.name != stu.mycourse[i].name)
            {
                i = -1;
                QMessageBox::warning(this,tr("警告！"),tr("ID与课程名不对应"),QMessageBox::Yes);
                return;
            }
        }
        QMessageBox::warning(this,tr("警告！"),tr("未选择该课程，无法退选"),QMessageBox::Yes);
    }
}

void studo::on_coursescorelook_clicked()
{
    course_info_change c;
    if(c.exec() == QDialog::Accepted)
    {
        courseinfo cour;
        cour = c.getinfo();
        for(int i = 0; i < stu.mycourse.size(); ++i)
        {
            //cout << stu.mycourse[i].id << ' ' << stu.mycourse[i].name << endl;
            //cout << cour.id << ' ' << cour.name << endl;
            if(cour.id == stu.mycourse[i].id && cour.name == stu.mycourse[i].name)
            {
                for(int j = 0; j < courselist.size(); ++j)
                {
                    if(cour.id == courselist[j].id)
                    {
                        for(int k = 0; k < courselist[j].p.size(); ++k)
                        {
                            if(courselist[j].p[k].id == stu.id)
                            {
                                QString sco = QString::number(courselist[j].p[k].score);
                                QMessageBox::warning(this,tr("提示！"),tr("该课程分数为："+sco.toLocal8Bit()),QMessageBox::Yes);
                                return;
                            }
                        }
                    }
                }
            }
            else if(cour.id == stu.mycourse[i].id && cour.name != stu.mycourse[i].name)
            {
                i = -1;
                QMessageBox::warning(this,tr("警告！"),tr("ID与课程名不对应"),QMessageBox::Yes);
                return;
            }
        }
        QMessageBox::warning(this,tr("警告！"),tr("未选择该课程，无法查询成绩"),QMessageBox::Yes);
    }
}

void studo::on_loginout_clicked()
{
    QString idstr = QString::number(stu.id);
    QString str = "../"+idstr+stu.name+"stu.txt";
    QFile file;
    file.setFileName(str);
    bool isOK = file.open(QIODevice::Text|QIODevice::WriteOnly);
    if(!isOK)
        cout << "open failed!" << endl;
    QTextStream out(&file);
    out << stu.id << ',' << stu.name << ',' << stu.password;
    int num = stu.mycourse.size();
    for(int i = 0; i < num; ++i)
    {
        out << endl;
        QString cidstr = QString::number(stu.mycourse[i].id);
        QString resstr = cidstr+stu.mycourse[i].name;
        out << resstr;
    }
    /*if(num >= 0)
    {
        QString cidstr = QString::number(stu.mycourse[num].id);
        QString resstr = cidstr+stu.mycourse[num].name;
        out << resstr;
    }*/
    file.close();
    courselist_to_file();
    close();
}
