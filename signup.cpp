#include "signup.h"
#include "ui_signup.h"

signup::signup(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::signup)
{
    ui->setupUi(this);
}

signup::~signup()
{
    delete ui;
}

void signup::on_returnButton_clicked()
{
    this->close();
    Widget * w=new Widget(); //分配空间
    w->show(); //跳转
}

void signup::on_confirmButton_clicked()
{
    QString id = ui->idEdit->text();
    QString pd = ui->passwordEdit->text();
    QString pd2 = ui->passwordEdit_2->text();


    if(pd != pd2)
    {
        QMessageBox::information(this,"注册提示","两次输入的密码不一致");
        return;
    }
    else
    {
        if (db.open())
        {
            QSqlQuery query;
            query.exec("select * from user_table;");
            QSqlQuery q;
            q.prepare("INSERT INTO user_table (user_id,user_password) VALUES(?,?)");
            q.addBindValue(id);
            q.addBindValue(pd);

            if(q.exec())
            {
                QMessageBox::information(this,"注册提示","注册成功,请登录");
            }
            else
            {
                QMessageBox::information(this,"注册提示","注册失败,请换个id");
            }
            this->close();
        }

    }
}
