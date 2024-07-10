#ifndef DELETEBOOK_H
#define DELETEBOOK_H

#include <QWidget>
#include <first.h>
#include <QMessageBox>
#include <QSqlQuery>

namespace Ui {
class deletebook;
}

class deletebook : public QWidget
{
    Q_OBJECT

public:
    explicit deletebook(QWidget *parent = nullptr);
    ~deletebook();

private slots:
    void on_returnButton_clicked();

    void on_searchButton_clicked();

    void on_confirmButton_clicked();

private:
    Ui::deletebook *ui;
};

#endif // DELETEBOOK_H
