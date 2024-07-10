#include "error.h"
#include "ui_error.h"

error::error(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::error)
{
    ui->setupUi(this);
}

error::~error()
{
    delete ui;
}


void error::on_rewardButton_clicked()
{
    this->close();
    reward * r = new reward();
    r->show();
}

void error::on_returnButton_clicked()
{
    this->close();
}
