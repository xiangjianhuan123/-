#ifndef FINDOUT_H
#define FINDOUT_H

#include <QWidget>
#include <search.h>
#include <first.h>

namespace Ui {
class findout;
}

class findout : public QWidget
{
    Q_OBJECT

public:
    explicit findout(QWidget *parent = nullptr);
    ~findout();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::findout *ui;
};

#endif // FINDOUT_H
