#include "adminlogin.h"
#include "ui_adminlogin.h"

adminlogin::adminlogin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::adminlogin)
{
    ui->setupUi(this);
}

adminlogin::~adminlogin()
{
    delete ui;
}

void adminlogin::on_confirmlog_clicked()
{
    QString adminid = ui->adminid->text();
    QString adminpassword = ui->adminpassword->text();
    if (adminid == "8888" && adminpassword == "tsg")
    {
        QMessageBox::warning(this, "登录提示", "登录成功");
        this->close();
        administrator * ad = new administrator();
        ad->show();
    }
    else
    {
        QMessageBox::warning(this, "登录提示", "登录失败，请重新尝试！");
    }
}
