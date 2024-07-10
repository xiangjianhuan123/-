#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include <QWidget>
#include <error.h>
#include <addbook.h>
#include <first.h>
#include <deleteuser.h>
#include <deletebook.h>
#include <editbookinfo.h>

namespace Ui {
class administrator;
}

class administrator : public QWidget
{
    Q_OBJECT

public:
    explicit administrator(QWidget *parent = nullptr);
    ~administrator();

private slots:
    void on_shownewbook_clicked();

    void on_showtag_clicked();

    void on_tagmanage_clicked();

    void on_offshelf_clicked();

    void on_addbook_clicked();

    void on_deletebook_clicked();

    void on_deletereader_clicked();

    void on_overdue_clicked();

    void on_editbook_clicked();

private:
    Ui::administrator *ui;
};

#endif // ADMINISTRATOR_H
