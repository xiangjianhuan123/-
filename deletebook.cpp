#include "deletebook.h"
#include "ui_deletebook.h"

deletebook::deletebook(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::deletebook)
{
    ui->setupUi(this);
}

deletebook::~deletebook()
{
    delete ui;
}

void deletebook::on_returnButton_clicked()
{
    this->close();
}

void deletebook::on_searchButton_clicked()
{
    QString bID = ui->bookid->text();
    if(db.open())
    {
        bool isfind = false;
        QSqlQuery p;
        p.exec("select * from book_table;");
        while(p.next())
        {
            if(p.value("book_id").toString() == bID)
            {
                isfind = true;
                ui->bookname->setText(p.value("book_name").toString());
                ui->author->setText(p.value("author").toString());
                ui->publish->setText(p.value("publishing_house").toString());
                ui->pubdate->setText(p.value("year_of_publication").toString());
                ui->ISBN->setText(p.value("ISBN").toString());
                ui->pages->setText(p.value("pages").toString());
                ui->translator->setText(p.value("translator").toString());
                ui->price->setText(p.value("price").toString());
                ui->score->setText(p.value("score").toString());
                ui->labels->setText(p.value("label").toString());
                break;
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

void deletebook::on_confirmButton_clicked()
{
    if(db.open())
    {
        QSqlQuery q;
        q.exec("select * from book_table;");
        QSqlQuery query;

        query.prepare("DELETE FROM book_table WHERE book_id = ?");
        query.addBindValue(ui->bookid->text());
        if(query.exec())
        {
            QMessageBox::information(this,"删除提示","删除成功");
        }
        else
        {
            QMessageBox::information(this,"删除提示","删除失败");
        }
    }
    else
    {
        QMessageBox::information(this,"连接提示","数据库连接出错");
    }
}
