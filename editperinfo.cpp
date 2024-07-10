#include "editperinfo.h"
#include "ui_editperinfo.h"

editPerInfo::editPerInfo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::editPerInfo)
{
    ui->setupUi(this);
    //展示用户ID
    ui->idlabel->setText(USERID);

    if(db.open())
    {
        QSqlQuery p;
        p.exec("select * from user_table;");
        while(p.next())
        {
            if(p.value("user_id").toString() == USERID)
            {
                ui->passwordlabel->setText(p.value("user_password").toString());    //用户密码
                ui->shownameline->setText(p.value("reader_name").toString());       //用户昵称
                ui->showphoneline->setText(p.value("user_phone").toString());       //手机号
                ui->statelabel->setText(p.value("reader_state").toString());        //读者状态
                ui->showfacultyline->setText(p.value("faculty_id").toString());     //学/工号
            }
        }
    }
    else
    {
        QMessageBox::information(this,"连接提示","数据库连接出错");
    }
}

editPerInfo::~editPerInfo()
{
    delete ui;
}

void editPerInfo::on_changepassword_clicked()
{
    changepassword * ch = new changepassword();
    ch->show();
}

void editPerInfo::on_save_clicked()
{
    QSqlQuery query;
    query.prepare("select * from user_table WHERE user_id = ?");
    query.addBindValue(USERID);
    if(query.exec())
    {
        QSqlQuery chinfo;
        chinfo.exec("SELECT * from user_table");
        QSqlQuery upinfo;
        upinfo.prepare("UPDATE user_table SET reader_name = ?, user_phone = ?, faculty_id = ? WHERE user_id = ?");
        upinfo.addBindValue(ui->shownameline->text());
        upinfo.addBindValue(ui->showphoneline->text());
        upinfo.addBindValue(ui->showfacultyline->text());
        upinfo.addBindValue(USERID);
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




void editPerInfo::on_returnButton_clicked()
{
    this->close();
}
