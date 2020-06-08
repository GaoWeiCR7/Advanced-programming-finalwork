#ifndef ADMINJUDGE_H
#define ADMINJUDGE_H

#include <QDialog>

namespace Ui {
class Adminjudge;
}

class Adminjudge : public QDialog
{
    Q_OBJECT

public:
    explicit Adminjudge(QWidget *parent = nullptr);
    ~Adminjudge();

private slots:
    void on_adminloginbtn_clicked();

private:
    Ui::Adminjudge *ui;
};

#endif // ADMINJUDGE_H
