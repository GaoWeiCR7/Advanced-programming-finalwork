#include "changestuscoreshow.h"
#include "ui_changestuscoreshow.h"

changestuscoreshow::changestuscoreshow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::changestuscoreshow)
{
    ui->setupUi(this);
}

changestuscoreshow::~changestuscoreshow()
{
    delete ui;
}
void changestuscoreshow::on_changeok_clicked()
{
    x.courseid = ui->coursechange->text().toInt();
    x.stuid = ui->stuchange->text().toInt();
    x.score = ui->scorechange->text().toInt();
    accept();
}
