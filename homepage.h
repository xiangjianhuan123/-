#ifndef HOMEPAGE_H
#define HOMEPAGE_H

#include <QWidget>
#include <borrow.h>
#include <first.h>
#include <perinfo.h>
#include <search.h>
#include <sendback.h>

namespace Ui {
class homepage;
}

class homepage : public QWidget
{
    Q_OBJECT

public:
    explicit homepage(QWidget *parent = nullptr);
    ~homepage();

private slots:

    void on_borrowButton_clicked();

    void on_infoButton_clicked();

    void on_searchButton_clicked();

    void on_sendbackButton_clicked();

private:
    Ui::homepage *ui;
};

#endif // HOMEPAGE_H
