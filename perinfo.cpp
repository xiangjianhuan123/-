#include "perinfo.h"
#include "ui_perinfo.h"

perInfo::perInfo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::perInfo)
{
    ui->setupUi(this);
    ui->idlabel->setText(USERID);

    if(db.open())
    {
        QSqlQuery p;
        p.exec("select * from user_table;");
        while(p.next())
        {
            if(p.value("user_id").toString() == USERID)
            {
                ui->namelabel->setText(p.value("reader_name").toString());
                ui->phonelabel->setText(p.value("user_phone").toString());
                ui->facultylabel->setText(p.value("faculty_id").toString());
                ui->statelabel->setText(p.value("reader_state").toString());
            }
        }
    }
    else
    {
        QMessageBox::information(this,"连接提示","数据库连接出错");
    }
}

perInfo::~perInfo()
{
    delete ui;
}

void perInfo::on_testButton_clicked()
{
    error * er = new error();
    er->show();
}

void perInfo::on_histroyButton_clicked()
{
    histroy *h = new histroy();
    h->show();
    /*error * er = new error();
    er->show();*/
}

void perInfo::on_Button_clicked()
{
    error * er = new error();
    er->show();
}

void perInfo::on_editinfoButton_clicked()
{
    editPerInfo * ed = new editPerInfo();
    ed->show();
}

void perInfo::on_borrowButton_2_clicked()
{
    borrow * br = new borrow();
    br->show();
}

void perInfo::on_sendbackButton_2_clicked()
{
    sendback * sd = new sendback();
    sd->show();
}

void perInfo::on_returnButton_clicked()
{
    this->close();
}
