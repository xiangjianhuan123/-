#include "borrow.h"
#include "ui_borrow.h"

borrow::borrow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::borrow)
{
    ui->setupUi(this);
}

borrow::~borrow()
{
    delete ui;
}

void borrow::on_searchB_clicked()
{   //查找图书并展示信息
    if(db.open())
    {
        QSqlQuery p;
        p.exec("select * from book_table;");
        bool isfind = false;
        while(p.next())
        {
            if(p.value("book_name").toString() == ui->lineEdit->text())
            {
                isfind = true;
                ui->idEdit->setText(p.value("book_id").toString());
                ui->nameEdit->setText(p.value("book_name").toString());
                ui->authorEdit->setText(p.value("author").toString());
                ui->bookstate->setText(p.value("bstate").toString());
                ui->userid->setText(USERID);
            }
        }
        if(isfind==false)
        {
            QMessageBox::information(this,"查询提示","查无此书");
        }
    }
    else
    {
        QMessageBox::information(this,"连接提示","数据库连接出错");
    }
}

void borrow::on_borrowButton_clicked()
{
    if(db.open())
    {   //检查读者身份状态
        QSqlQuery rs;
        rs.prepare("select * from user_table WHERE user_id = ?;");
        rs.addBindValue(USERID.toInt());
        rs.exec();
        if(rs.value("user_id").toString() == USERID && rs.value("reader_state").toBool()==false)
        {
            QMessageBox::information(this,"借阅提示","未激活读者身份");
            return;
        }
        else if(ui->bookstate->text().toInt() > 0)
        {

            QSqlQuery q;
            q.exec("select * from book_table;");
            QSqlQuery query;

            query.prepare("UPDATE book_table SET bstate = ? WHERE book_id = ?");
            query.addBindValue(0);
            query.addBindValue(ui->idEdit->text().toInt());

            if(query.exec())
            {
                QMessageBox::information(this,"借阅提示","借阅成功");
                return;
            }
            else
            {
                QMessageBox::information(this,"借阅提示","借阅失败");
            }
        }
        if(ui->bookstate->text().toInt()==0)
        {
            QMessageBox::information(this,"借阅提示","借阅失败,该书暂无库存");
            return;
        }
    }
    else
    {
        QMessageBox::information(this,"连接提示","数据库连接失败");
    }
}

void borrow::on_pushButton_clicked()
{
    this->close();
}

void borrow::on_pushButton_2_clicked()
{
    reserve *r = new reserve();
    r->show();
}
