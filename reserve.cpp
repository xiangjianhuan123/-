#include "reserve.h"
#include "ui_reserve.h"

reserve::reserve(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::reserve)
{
    ui->setupUi(this);
}

reserve::~reserve()
{
    delete ui;
}
