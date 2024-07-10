#ifndef ERROR_H
#define ERROR_H

#include <QWidget>
#include <QMessageBox>
#include <reward.h>

namespace Ui {
class error;
}

class error : public QWidget
{
    Q_OBJECT

public:
    explicit error(QWidget *parent = nullptr);
    ~error();

private slots:

    void on_rewardButton_clicked();

    void on_returnButton_clicked();

private:
    Ui::error *ui;
};

#endif // ERROR_H
