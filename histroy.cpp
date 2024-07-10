#include "histroy.h"
#include "ui_histroy.h"

histroy::histroy(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::histroy)
{
    ui->setupUi(this);
}

histroy::~histroy()
{
    delete ui;
}
