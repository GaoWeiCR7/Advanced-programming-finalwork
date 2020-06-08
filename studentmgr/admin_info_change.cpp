#include "admin_info_change.h"
#include "ui_admin_info_change.h"

admin_info_change::admin_info_change(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::admin_info_change)
{
    ui->setupUi(this);
}

admin_info_change::~admin_info_change()
{
    delete ui;
}

void admin_info_change::on_changeok_clicked()
{
    t.id = ui-> changeid->text().toInt();
    t.name = ui->changename->text();
    t.password = ui->changepass->text();
    accept();
}
