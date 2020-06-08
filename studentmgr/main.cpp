#include "mainwindow.h"
#include <QApplication>

QVector<courseinfo> courselist;
void courselist_to_file()
{
    QFile file;
    file.setFileName("../allcourse.txt");
    bool isOK = file.open(QIODevice::Text|QIODevice::WriteOnly);
    if(!isOK)
        cout << "open failed!" << endl;
    QTextStream out(&file);
    int num = courselist.size();
    num--;
    for(int i = 0; i < num; ++i)
    {
        QString cidstr = QString::number(courselist[i].id);
        QString resstr = cidstr+courselist[i].name;
        out << resstr << endl;
    }
    if(num >= 0)
    {
        QString cidstr = QString::number(courselist[num].id);
        QString resstr = cidstr+courselist[num].name;
        out << resstr;
    }
    file.close();
    for(int i = 0; i < courselist.size(); ++i)
    {
        QString a = QString::number(courselist[i].id);
        QString tempstr = "../"+a+courselist[i].name+".txt";
        QFile file2;
        file2.setFileName(tempstr);
        bool isOK = file2.open(QIODevice::Text|QIODevice::WriteOnly);
        if(!isOK)
            cout << "open failed!" << endl;
        QTextStream out2(&file2);
        out2 << courselist[i].id << ',';
        out2 << courselist[i].name << ',';
        out2 << courselist[i].score << ',';
        out2 << courselist[i].teacher << ',';
        out2 << courselist[i].time << ',';
        out2 << courselist[i].num << ',';
        out2 << courselist[i].maxnum;
        int num2 = courselist[i].p.size();
        //num2--;
        for(int j = 0; j < num2; ++j)
        {
            out2 << endl;
            out2 << courselist[i].p[j].id << ',';
            out2 << courselist[i].p[j].name << ',';
            out2 << courselist[i].p[j].score;
        }
        /*if(num2 >= 0)
        {
            out2 << courselist[i].p[num2].id << ',';
            out2 << courselist[i].p[num2].name << ',';
            out2 << courselist[i].p[num2].score;
        }*/
        file2.close();
    }
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
