#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#define cout qDebug() << "[" <<__FILE__ <<":"<<__FUNCTION__<<":"<<__LINE__ <<"]"

#include <QMainWindow>
#include <QVector>
#include <QtAlgorithms>
#include <QTextStream>
#include <QFile>
#include <QDebug>
#include <QFileDialog>
#include<QStandardItemModel>
#include <QMessageBox>
#include <QTextStream>

namespace Ui {
class MainWindow;
}

struct changescorenode
{
    int courseid;
    int stuid;
    int score;
};

struct adminnode
{
    int id;
    QString name;
};

struct admintempnode
{
    int id;
    QString name;
    QString password;
};

struct namelistscore
{
    int id;
    QString name;
    int score;
};

class courseinfo
{
public:
    int id;
    QString name;
    int score;
    QString teacher;
    QString time;
    int num;
    int maxnum;
    QVector<namelistscore> p;
    courseinfo()
    {
        id = 0;
        name = "";
        score = 0;
        teacher = "";
        time = "";
        num = 0;
        maxnum = 0;
    }
};

class stuinfo
{
public:
    int id;
    QString name;
    QString password;
    QVector<courseinfo> mycourse;
    stuinfo()
    {
        id = 0;
        name = "";
        password = "";
    }
    stuinfo(int a,QString b, QString c)
    {
        id = a;
        name = b;
        password = c;
    }
};

class teainfo
{
public:
    int id;
    QString name;
    QString password;
    QVector<courseinfo> mycourse;
    teainfo()
    {
        id = 0;
        name = "";
        password = "";
    }
    teainfo(int a,QString b, QString c)
    {
        id = a;
        name = b;
        password = c;
    }
};

class admininfo
{
public:
    QVector<adminnode> tea;
    QVector<adminnode> stu;
};


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_mainadmin_clicked();

    void on_mainstu_clicked();

    void on_maintea_clicked();

private:
    Ui::MainWindow *ui;
};

extern QVector<courseinfo> courselist;
void courselist_to_file();

#endif // MAINWINDOW_H
