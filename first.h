#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <signup.h>
#include <homepage.h>
#include <borrow.h>
#include <QtSql/QSqlDatabase>
#include <QMessageBox>
#include <QDebug>
#include <QSqlQuery>
#include <adminlogin.h>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();


private slots:
    void on_signupButton_clicked();

    void on_loginButton_clicked();


    void on_adminLogin_clicked();

private:
    Ui::Widget *ui;

};
extern     QSqlDatabase db;
extern     QString USERID;
#endif // WIDGET_H
