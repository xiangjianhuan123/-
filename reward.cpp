#include "reward.h"
#include "ui_reward.h"

reward::reward(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::reward)
{
    ui->setupUi(this);

    QPixmap pix("D:\\0library\\Qt\\library\\images\\money.png");
    ui->label->setPixmap(pix);
}

reward::~reward()
{
    delete ui;
}
