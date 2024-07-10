#include "sendback.h"
#include "ui_sendback.h"

sendback::sendback(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::sendback)
{
    ui->setupUi(this);
    ui->userid->setText(USERID);
}

sendback::~sendback()
{
    delete ui;
}

void sendback::on_sendbackButton_clicked()
{
    if(db.open())
    {
        bool isfind = false;
        QString bname = ui->bookname->text();
        QSqlQuery p;
        p.exec("SELECT * from book_table");
        while(p.next())
        {
            if(p.value("book_name").toString() == bname && p.value("bstate").toInt() == 0)
            {
                isfind = true;
                int bid = p.value("book_id").toInt();
                QSqlQuery q;
                q.prepare("UPDATE book_table SET bstate = ? WHERE book_id = ?");
                q.addBindValue(1);
                q.addBindValue(bid);
                if(q.exec())
                {
                    QMessageBox::information(this,"归还提示","归还成功");
                    break;
                }
                else
                {
                    QMessageBox::information(this,"归还提示","归还失败");
                    break;
                }
            }
        }
        if(isfind==false)
        {
            QMessageBox::information(this,"查询提示","查无此书");
        }
    }
}

void sendback::on_returnButton_clicked()
{
    this->close();
}
