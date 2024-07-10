#ifndef PERINFO_H
#define PERINFO_H

#include <QWidget>
#include <error.h>
#include <borrow.h>
#include <first.h>
#include <sendback.h>
#include <editperinfo.h>
#include <histroy.h>

namespace Ui {
class perInfo;
}

class perInfo : public QWidget
{
    Q_OBJECT

public:
    explicit perInfo(QWidget *parent = nullptr);
    ~perInfo();

private slots:
    void on_testButton_clicked();

    void on_histroyButton_clicked();

    void on_Button_clicked();

    void on_editinfoButton_clicked();

    void on_borrowButton_2_clicked();

    void on_sendbackButton_2_clicked();

    void on_returnButton_clicked();

private:
    Ui::perInfo *ui;
};

#endif // PERINFO_H
