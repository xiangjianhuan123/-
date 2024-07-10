#ifndef DELETEUSER_H
#define DELETEUSER_H

#include <QWidget>
#include <first.h>
#include <QSqlQuery>

namespace Ui {
class deleteuser;
}

class deleteuser : public QWidget
{
    Q_OBJECT

public:
    explicit deleteuser(QWidget *parent = nullptr);
    ~deleteuser();

private slots:
    void on_pushButton_clicked();

    void on_returnButton_clicked();

private:
    Ui::deleteuser *ui;
};

#endif // DELETEUSER_H
