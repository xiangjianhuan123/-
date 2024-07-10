#include "administrator.h"
#include "ui_administrator.h"

administrator::administrator(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::administrator)
{
    ui->setupUi(this);
}

administrator::~administrator()
{
    delete ui;
}

void administrator::on_shownewbook_clicked()
{
    error * er = new error();
    er->show();
}

void administrator::on_showtag_clicked()
{
    error * er = new error();
    er->show();
}

void administrator::on_tagmanage_clicked()
{
    error * er = new error();
    er->show();
}

void administrator::on_offshelf_clicked()
{
    error * er = new error();
    er->show();
}

void administrator::on_addbook_clicked()
{
    addbook * ab = new addbook();
    ab->show();
}

void administrator::on_deletebook_clicked()
{
    deletebook * del = new deletebook();
    del->show();
}

void administrator::on_deletereader_clicked()
{
    deleteuser * deluser = new deleteuser();
    deluser->show();
}

void administrator::on_overdue_clicked()
{
    error * er = new error();
    er->show();
}



void administrator::on_editbook_clicked()
{
    editBookInfo * b = new editBookInfo();
    b->show();
}
