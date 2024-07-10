#include "deleteuser.h"
#include "ui_deleteuser.h"

deleteuser::deleteuser(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::deleteuser)
{
    ui->setupUi(this);
}

deleteuser::~deleteuser()
{
    delete ui;
}

void deleteuser::on_pushButton_clicked()
{
    if(db.open())
    {
        QSqlQuery q;
        q.exec("select * from user_table;");
        QSqlQuery query;

        query.prepare("DELETE FROM user_table WHERE user_id = ?");
        query.addBindValue(ui->idEdit->text());
        if(query.exec())
        {
            QMessageBox::information(this,"删除提示","删除成功");
        }
        else
        {
            QMessageBox::information(this,"删除提示","删除失败");
        }
    }
    else
    {
        QMessageBox::information(this,"连接提示","数据库连接出错");
    }
}

void deleteuser::on_returnButton_clicked()
{
    this->close();
}
