#ifndef RESERVE_H
#define RESERVE_H

#include <QWidget>

namespace Ui {
class reserve;
}

class reserve : public QWidget
{
    Q_OBJECT

public:
    explicit reserve(QWidget *parent = nullptr);
    ~reserve();

private:
    Ui::reserve *ui;
};

#endif // RESERVE_H
