#include "search.h"
#include "ui_search.h"

search::search(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::search)
{
    ui->setupUi(this);
    m = new QSqlTableModel;
    m->setTable("book_table");
    ui->show->setModel(m);

}

search::~search()
{
    delete ui;
}

void search::on_selectButton_clicked()
{

    m->select();
}

void search::on_returnButton_clicked()
{
    this->close();
}

void search::on_searchOne_clicked()
{
    findout * fd = new findout();
    fd->show();
}
