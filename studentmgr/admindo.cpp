#include "admindo.h"
#include "ui_admindo.h"
#include "admin__info_look.h"
#include "admin_info_change.h"

admindo::admindo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::admindo)
{
    ui->setupUi(this);
    QFile file;
    file.setFileName("../admin.txt");
    bool isOK = file.open(QIODevice::ReadOnly);
    if(!isOK)
        cout << "open failed!" << endl;
    QTextStream in(&file);
    bool flag = true;
    while(!in.atEnd())
    {
        QString line = in.readLine();
        if(line == "###")
            flag = false;
        else
        {
            QString first = line.section(',',0,0);
            QString second = line.section(',',1,1);
            int firstint = first.toInt();
            if(true == flag)
            {
                admin.stu.push_back({firstint,second});
            }
            else
            {
                admin.tea.push_back({firstint,second});
            }
        }
    }
    file.close();
    /*cout << "学生名单:" << endl;
    for(int i = 0; i < admin.stu.size(); ++i)
    {
        cout << admin.stu[i].id << ' ' << admin.stu[i].name << endl;
    }
    cout << "教师名单:" << endl;
    for(int i = 0; i < admin.tea.size(); ++i)
    {
        cout << admin.tea[i].id << ' ' << admin.tea[i].name << endl;
    }*/
}

admindo::~admindo()
{
    delete ui;
}

void admindo::on_stulook_clicked()
{
    admin__info_look table;
    table.infolook(admin,true);
    table.exec();
}

void admindo::on_tealook_clicked()
{
    admin__info_look table;
    table.infolook(admin,false);
    table.exec();
}

void admindo::on_stuin_clicked()
{
    admin_info_change info;
    if(info.exec() == QDialog::Accepted)
    {
        admintempnode t = info.getinfo();
        adminnode temp;
        temp.id = t.id;
        temp.name = t.name;
        QString pass = t.password;
        for(int i = 0; i < admin.stu.size(); ++i)
            if(admin.stu[i].id == temp.id)
            {
                QMessageBox::warning(this,tr("提示"),tr("添加失败，此id已存在"),QMessageBox::Yes);
                return;
            }
        admin.stu.push_back(temp);
        QString idstr = QString::number(temp.id);
        QString crestr = "../"+idstr+temp.name+"stu.txt";
        QFile file;
        file.setFileName(crestr);
        bool isOK = file.open(QIODevice::Text|QIODevice::WriteOnly);
        if(!isOK)
            cout << "open failed!" << endl;
        QTextStream out(&file);
        out << temp.id << ',' << temp.name << ',' << pass;
        file.close();
        QMessageBox::warning(this,tr("提示"),tr("添加成功"),QMessageBox::Yes);
    }
}

void admindo::on_teain_clicked()
{
    admin_info_change info;
    if(info.exec() == QDialog::Accepted)
    {
        admintempnode t = info.getinfo();
        adminnode temp;
        temp.id = t.id;
        temp.name = t.name;
        QString pass = t.password;
        for(int i = 0; i < admin.tea.size(); ++i)
            if(admin.tea[i].id == temp.id)
            {
                QMessageBox::warning(this,tr("提示"),tr("添加失败，此id已存在"),QMessageBox::Yes);
                return;
            }
        admin.tea.push_back(temp);
        QString idstr = QString::number(temp.id);
        QString crestr = "../"+idstr+temp.name+"tea.txt";
        QFile file;
        file.setFileName(crestr);
        bool isOK = file.open(QIODevice::Text|QIODevice::WriteOnly);
        if(!isOK)
            cout << "open failed!" << endl;
        QTextStream out(&file);
        out << temp.id << ',' << temp.name << ',' << pass;
        file.close();
        QMessageBox::warning(this,tr("提示"),tr("添加成功"),QMessageBox::Yes);
    }
}

void admindo::on_studel_clicked()
{
    admin_info_change info;
    if(info.exec() == QDialog::Accepted)
    {
        admintempnode t = info.getinfo();
        admintempnode temp;
        temp.id = t.id;
        temp.name = t.name;
        for(int i = 0; i < admin.stu.size(); ++i)
        {
            if(admin.stu[i].id == temp.id&&admin.stu[i].name == temp.name)
            {
                for(int a = 0; a < courselist.size(); ++a)
                    for(int b = 0; b <courselist[a].p.size(); ++b)
                        if(courselist[a].p[b].id == admin.stu[i].id&&courselist[a].p[b].name == admin.stu[i].name)
                        {
                            courselist[a].p.erase(b+courselist[a].p.begin());
                            courselist[a].num--;
                        }
                QString idstr = QString::number(admin.stu[i].id);
                QString removestr = "../"+idstr + admin.stu[i].name+"stu.txt";
                remove(removestr.toLocal8Bit());
                admin.stu.erase(i+admin.stu.begin());
                QMessageBox::warning(this,tr("提示"),tr("删除成功"),QMessageBox::Yes);
                return;
            }
            else if(admin.stu[i].id == temp.id&&admin.stu[i].name != temp.name)
            {
                i = -1;
                QMessageBox::warning(this,tr("提示"),tr("id与学生名不对应"),QMessageBox::Yes);
                return;
            }
        }
        QMessageBox::warning(this,tr("提示"),tr("删除失败,无此id"),QMessageBox::Yes);
    }
}

void admindo::on_teadel_clicked()
{
    admin_info_change info;
    if(info.exec() == QDialog::Accepted)
    {
        admintempnode t = info.getinfo();
        adminnode temp;
        temp.id = t.id;
        temp.name = t.name;
        for(int i = 0; i < admin.tea.size(); ++i)
        {
            if(admin.tea[i].id == temp.id&&admin.tea[i].name == temp.name)
            {
                QFile file;
                QString idstr = QString::number(temp.id);
                QString crestr = "../"+idstr+temp.name+"tea.txt";
                file.setFileName(crestr);
                bool isOK = file.open(QIODevice::ReadOnly);
                if(!isOK)
                    cout << "open failed!" << endl;
                QTextStream in(&file);
                teainfo admintea;
                QString line = in.readLine();
                admintea.id = line.section(',',0,0).toInt();
                admintea.name = line.section(',',1,1);
                admintea.password = line.section(',',2,2);
                QVector <QString> tstr;
                while(!in.atEnd())
                {
                    line = in.readLine();
                    tstr.push_back(line);
                }
                file.close();
                for(int j = 0; j < tstr.size(); ++j)
                {
                    QFile file2;
                    QString crestr2 = "../"+tstr[j]+".txt";
                    file2.setFileName(crestr2);
                    isOK = file2.open(QIODevice::ReadOnly);
                    if(!isOK)
                        cout << "open failed!" << endl;
                    QTextStream in(&file2);
                    line = in.readLine();
                    file2.close();
                    int rid = line.section(",",0,0).toInt();
                    for(int k = 0; k < courselist.size(); ++k)
                        if(courselist[k].id == rid)
                        {
                            courselist.erase(k+courselist.begin());
                            break;
                        }
                    remove(crestr2.toLocal8Bit());
                }
                remove(crestr.toLocal8Bit());
                admin.tea.erase(i+admin.tea.begin());
                QMessageBox::warning(this,tr("提示"),tr("删除成功"),QMessageBox::Yes);
                return;
            }
            else if(admin.tea[i].id == temp.id&&admin.tea[i].name != temp.name)
            {
                i = -1;
                QMessageBox::warning(this,tr("提示"),tr("id与教师名不匹配"),QMessageBox::Yes);
                return;
            }
        }
        QMessageBox::warning(this,tr("提示"),tr("删除失败,无此id"),QMessageBox::Yes);
    }
}

void admindo::on_loginout_clicked()
{
    QFile file;
    file.setFileName("../admin.txt");
    bool isOK = file.open(QIODevice::Text|QIODevice::WriteOnly);
    if(!isOK)
        cout << "open failed!" << endl;
    QTextStream out(&file);
    for(int i = 0; i < admin.stu.size(); ++i)
    {
        out << admin.stu[i].id << ',' << admin.stu[i].name << endl;
    }
    out << "###" << endl;
    int num = admin.tea.size();
    num--;
    for(int i = 0; i < num; ++i)
    {
        out << admin.tea[i].id << ',' << admin.tea[i].name << endl;
    }
    if(admin.tea.size() != 0)
        out << admin.tea[admin.tea.size()-1].id << ',' << admin.tea[admin.tea.size()-1].name;
    file.close();
    courselist_to_file();
    close();
}
