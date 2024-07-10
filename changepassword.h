#ifndef CHANGEPASSWORD_H
#define CHANGEPASSWORD_H

#include <QWidget>
#include <first.h>
#include <QSqlQuery>
#include <QMessageBox>

namespace Ui {
class changepassword;
}

class changepassword : public QWidget
{
    Q_OBJECT

public:
    explicit changepassword(QWidget *parent = nullptr);
    ~changepassword();

private slots:
    void on_commitButton_clicked();

    void on_returnButton_clicked();

private:
    Ui::changepassword *ui;
};

#endif // CHANGEPASSWORD_H
