#ifndef REWARD_H
#define REWARD_H

#include <QWidget>

namespace Ui {
class reward;
}

class reward : public QWidget
{
    Q_OBJECT

public:
    explicit reward(QWidget *parent = nullptr);
    ~reward();

private:
    Ui::reward *ui;
};

#endif // REWARD_H
