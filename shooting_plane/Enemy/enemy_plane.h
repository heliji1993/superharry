#ifndef ENEMY_PLANE_H
#define ENEMY_PLANE_H

#include <QWidget>
#include <QLabel>
#include <QPixmap>

namespace Ui {
class enemy_plane;
}

class enemy_plane : public QLabel
{
    Q_OBJECT

public:
    explicit enemy_plane(QLabel *parent = 0);
    ~enemy_plane();
    void set_life(int life);
    int get_life();
    void setliferange(int min,int max,int initial_life);
    void set_currentlife(int lifevalue);
private:
    Ui::enemy_plane *ui;
    int life_value;
};

#endif // ENEMY_PLANE_H
