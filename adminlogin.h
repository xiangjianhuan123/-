#ifndef ADMINLOGIN_H
#define ADMINLOGIN_H

#include <QWidget>
#include <first.h>
#include <administrator.h>
#include <QMessageBox>

namespace Ui {
class adminlogin;
}

class adminlogin : public QWidget
{
    Q_OBJECT

public:
    explicit adminlogin(QWidget *parent = nullptr);
    ~adminlogin();

private slots:
    void on_confirmlog_clicked();

private:
    Ui::adminlogin *ui;
};

#endif // ADMINLOGIN_H
