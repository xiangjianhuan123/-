#include "findout.h"
#include "ui_findout.h"

findout::findout(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::findout)
{
    ui->setupUi(this);
}

findout::~findout()
{
    delete ui;
}

void findout::on_pushButton_clicked()
{
    this->close();
}

void findout::on_pushButton_2_clicked()
{
    if(db.open())
    {
        bool isfind = false;
        QSqlQuery p;
        p.exec("select * from book_table;");
        while(p.next())
        {
            QString bookname = ui->lineEdit->text();
            if(p.value("book_name").toString() == bookname)
            {
                isfind = true;
                ui->idEdit->setText(p.value("book_id").toString());
                ui->nameEdit->setText(p.value("book_name").toString());
                ui->authorEdit->setText(p.value("author").toString());
            }
        }
        if(isfind==false)
        {
            QMessageBox::information(this,"查询提示","查无此书");
        }
    }
    else
    {
        QMessageBox::information(this,"连接提示","数据库连接失败");
    }
}
