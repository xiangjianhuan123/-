#include "homepage.h"
#include "ui_homepage.h"

homepage::homepage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::homepage)
{
    ui->setupUi(this);
}

homepage::~homepage()
{
    delete ui;
}



void homepage::on_borrowButton_clicked()
{

    borrow * bor = new borrow(); //分配空间
    bor->show();//跳转
}

void homepage::on_infoButton_clicked()
{

    perInfo * pinfo = new perInfo();
    pinfo->show();
}

void homepage::on_searchButton_clicked()
{

    search * se = new search();
    se->show();
}

void homepage::on_sendbackButton_clicked()
{
    sendback * sd = new sendback();
    sd->show();
}
