#include "changepassword.h"
#include "ui_changepassword.h"

changepassword::changepassword(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::changepassword)
{
    ui->setupUi(this);
}

changepassword::~changepassword()
{
    delete ui;
}

void changepassword::on_commitButton_clicked()
{
    QString pd = ui->password->text();          //原密码
    QString newpd = ui->newpassword->text();    //新密码
    QString cfpd = ui->confirm->text();         //再次输入
    int idnum = USERID.toInt();

    if (newpd != cfpd)
    {
        QMessageBox::warning(this, "提示", "两次输入密码不一致！");
        return;
    }

    if(db.open())
    {
        QSqlQuery p;
        p.exec("select * from user_table;");
        while(p.next())
        {
            if(USERID == p.value("user_id").toString())
            {
                if(p.value("user_password").toString() == pd)
                {   //如果ID与密码匹配
                    QSqlQuery chpd;
                    chpd.exec("SELECT * from user_table");
                    QSqlQuery upd;
                    upd.prepare("UPDATE user_table SET user_password = ? WHERE user_id = ?");
                    upd.addBindValue(newpd);
                    upd.addBindValue(idnum);

                    if (upd.exec())
                    {
                        QMessageBox::information(this,"修改提示","修改成功,退出后可查看更新");
                    }
                    else
                    {
                        QMessageBox::information(this,"修改提示","修改失败");
                    }
                }
                else
                {
                    QMessageBox::information(this,"修改提示","原密码错误");
                }
            }
        }
    }
}


void changepassword::on_returnButton_clicked()
{
    this->close();
}
