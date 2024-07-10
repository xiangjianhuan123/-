#ifndef BORROW_H
#define BORROW_H

#include <QWidget>
#include <first.h>
#include <QSqlQuery>
#include <QMessageBox>
#include <reserve.h>

namespace Ui {
class borrow;
}

class borrow : public QWidget
{
    Q_OBJECT

public:
    explicit borrow(QWidget *parent = nullptr);
    ~borrow();

private slots:
    void on_searchB_clicked();

    void on_pushButton_clicked();

    void on_borrowButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::borrow *ui;
};

#endif // BORROW_H
