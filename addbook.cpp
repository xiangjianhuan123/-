#include "addbook.h"
#include "ui_addbook.h"

addbook::addbook(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::addbook)
{
    ui->setupUi(this);

}

addbook::~addbook()
{
    delete ui;
}

void addbook::on_pushButton_2_clicked()
{
    this->close();
}

void addbook::on_pushButton_clicked()
{
    QString id = ui->idEdit->text();
    QString name = ui->nameEdit->text();
    QString author = ui->authorEdit->text();

    if (db.open())
    {
        QSqlQuery q;
        q.exec("select * from book_table;");
        //QString sql = QString("INSERT INTO book_table VALUES('%1','%2','%3')").arg(id,name,author);
        QSqlQuery query;

        query.prepare("INSERT INTO book_table (book_id,book_name,author) VALUES(?,?,?)");
        query.addBindValue(id);
        query.addBindValue(name);
        query.addBindValue(author);

        if(query.exec())
        {
            QMessageBox::information(this,"插入提示","插入成功");
        }
        else
        {
            QMessageBox::information(this,"插入提示","插入失败");
        }
    }
}
