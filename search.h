#ifndef SEARCH_H
#define SEARCH_H

#include <QWidget>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlTableModel>
#include <findout.h>

namespace Ui {
class search;
}

class search : public QWidget
{
    Q_OBJECT

public:
    explicit search(QWidget *parent = nullptr);
    ~search();

private slots:
    void on_selectButton_clicked();

    void on_returnButton_clicked();

    void on_searchOne_clicked();

public:
    Ui::search *ui;
    QSqlTableModel *m;
};

#endif // SEARCH_H
