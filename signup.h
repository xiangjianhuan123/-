#ifndef SIGNUP_H
#define SIGNUP_H

#include <QWidget>
#include <QMessageBox>
#include <QSqlQuery>
#include <first.h>

namespace Ui {
class signup;
}

class signup : public QWidget
{
    Q_OBJECT

public:
    explicit signup(QWidget *parent = nullptr);
    ~signup();

private slots:
    void on_returnButton_clicked();

    void on_confirmButton_clicked();

private:
    Ui::signup *ui;
};

#endif // SIGNUP_H
