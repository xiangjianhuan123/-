#include "editbookinfo.h"
#include "ui_editbookinfo.h"

editBookInfo::editBookInfo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::editBookInfo)
{
    ui->setupUi(this);
}

editBookInfo::~editBookInfo()
{
    delete ui;
}

void editBookInfo::on_searchButton_clicked()
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

void editBookInfo::on_confirmButton_clicked()
{
    QSqlQuery query;
    query.prepare("select * from book_table WHERE book_id = ?");
    query.addBindValue(ui->bookid->text());
    if(query.exec())
    {
        QSqlQuery chinfo;
        chinfo.exec("SELECT * from book_table");
        QSqlQuery upinfo;
        upinfo.prepare("UPDATE book_table SET book_name = ?, author = ?, publishing_house = ?,"
                       "year_of_publication = ?, pages = ?, translator = ?, ISBN = ?,"
                       "price = ?, score = ?, label = ? WHERE book_id = ?");
        upinfo.addBindValue(ui->bookname->text());
        upinfo.addBindValue(ui->author->text());
        upinfo.addBindValue(ui->publish->text());
        upinfo.addBindValue(ui->pubdate->text());
        upinfo.addBindValue(ui->pages->text());
        upinfo.addBindValue(ui->translator->text());
        upinfo.addBindValue(ui->ISBN->text());
        upinfo.addBindValue(ui->price->text());
        upinfo.addBindValue(ui->score->text());
        upinfo.addBindValue(ui->labels->text());
        upinfo.addBindValue(ui->bookid->text());
        if (upinfo.exec())
        {
            QMessageBox::information(this,"修改提示","修改成功,退出后可查看更新");
        }
        else
        {
            QMessageBox::information(this,"修改提示","修改失败");
        }
    }
}

void editBookInfo::on_returnButton_clicked()
{
    this->close();
}
