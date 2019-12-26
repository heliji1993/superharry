#ifndef MYPLANE_H
#define MYPLANE_H

#include <QWidget>
#include <QLabel>
#include <QPixmap>
#include <QKeyEvent>

namespace Ui {
class myplane;
}

class myplane : public QLabel
{
    Q_OBJECT

public:
    explicit myplane(QLabel *parent = 0);
    ~myplane();
    void set_life(int life);
    int get_life();
    void setliferange(int min, int max, int initial_life);
    void setcurrent_life(int progress);
private:
    Ui::myplane *ui;
    int life_value;
};

#endif // MYPLANE_H
