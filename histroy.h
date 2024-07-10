#ifndef HISTROY_H
#define HISTROY_H

#include <QWidget>
#include <error.h>
#include <borrow.h>
#include <first.h>
#include <sendback.h>
#include <editperinfo.h>
#include <perinfo.h>

namespace Ui {
class histroy;
}

class histroy : public QWidget
{
    Q_OBJECT

public:
    explicit histroy(QWidget *parent = nullptr);
    ~histroy();

private:
    Ui::histroy *ui;
};

#endif // HISTROY_H
