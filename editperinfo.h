#ifndef EDITPERINFO_H
#define EDITPERINFO_H

#include <QWidget>
#include <first.h>
#include <QMessageBox>
#include <changepassword.h>

namespace Ui {
class editPerInfo;
}

class editPerInfo : public QWidget
{
    Q_OBJECT

public:
    explicit editPerInfo(QWidget *parent = nullptr);
    ~editPerInfo();

private slots:
    void on_changepassword_clicked();

    void on_save_clicked();

    void on_returnButton_clicked();

private:
    Ui::editPerInfo *ui;
};

#endif // EDITPERINFO_H
