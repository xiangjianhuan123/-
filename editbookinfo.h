#ifndef EDITBOOKINFO_H
#define EDITBOOKINFO_H

#include <QWidget>
#include <first.h>
#include <QMessageBox>
#include <QSqlQuery>

namespace Ui {
class editBookInfo;
}

class editBookInfo : public QWidget
{
    Q_OBJECT

public:
    explicit editBookInfo(QWidget *parent = nullptr);
    ~editBookInfo();

private slots:
    void on_searchButton_clicked();

    void on_confirmButton_clicked();

    void on_returnButton_clicked();

private:
    Ui::editBookInfo *ui;
};

#endif // EDITBOOKINFO_H
