#ifndef SENDBACK_H
#define SENDBACK_H

#include <QWidget>
#include <first.h>
#include <QSqlQuery>

namespace Ui {
class sendback;
}

class sendback : public QWidget
{
    Q_OBJECT

public:
    explicit sendback(QWidget *parent = nullptr);
    ~sendback();

private slots:
    void on_sendbackButton_clicked();

    void on_returnButton_clicked();

private:
    Ui::sendback *ui;
};

#endif // SENDBACK_H
