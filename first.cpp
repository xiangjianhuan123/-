#include "first.h"
#include "ui_widget.h"

QSqlDatabase db;
QString USERID;

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //连接数据库
    db = QSqlDatabase::addDatabase("QODBC");
    db.setHostName("127.0.0.1");
    db.setPort(3306);
    db.setDatabaseName("2");    //特别注意，这里是ODBC上设置的 Data Source Name
    db.setUserName("root");
    db.setPassword("123456");

    /*if (db.open())
    {
        QMessageBox::information(this, "连接提示", "连接成功");
    }
    else
    {
        QMessageBox::warning(this, "连接提示", "连接失败");
    }*/
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_signupButton_clicked()
{
    signup * su = new signup(); //分配空间
    su->show();//跳转
}

void Widget::on_loginButton_clicked()
{
    QString id = ui->idEdit->text();
    int idnum = id.toInt();
    QString pass = ui->passwordEdit->text();


    //不知道为什么，加上这个判断才能open database，故不建议删去if，signup.cpp和addbook.cpp也是如此
    if(db.open())
    {
        bool t = false;
        QSqlQuery p;
        p.exec("select * from user_table;");
        while(p.next())
        {
            if(idnum == p.value("user_id").toInt())
            {
                if(p.value("user_password").toString() == pass)
                {
                    USERID = id;
                    QMessageBox::information(this,"登录提示","登录成功");
                    t = true;
                    homepage * hp = new homepage(); //分配空间
                    hp->show();//跳转
                }
                else
                {
                    QMessageBox::information(this,"登录提示","密码错误");
                }
            }
        }
        if(t==false)
        {
            QMessageBox::information(this,"登录提示","登录失败");
        }
    }
    else
    {
        QMessageBox::warning(this, "连接提示", "数据库连接失败");
    }
}

void Widget::on_adminLogin_clicked()
{
    adminlogin * adlog = new adminlogin(); //分配空间
    adlog->show();//跳转
}


