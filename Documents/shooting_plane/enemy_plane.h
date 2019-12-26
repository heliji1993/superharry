#ifndef ENEMY_PLANE_H
#define ENEMY_PLANE_H

#include <QWidget>

namespace Ui {
class enemy_plane;
}

class enemy_plane : public QWidget
{
    Q_OBJECT

public:
    explicit enemy_plane(QWidget *parent = 0);
    ~enemy_plane();

private:
    Ui::enemy_plane *ui;
};

#endif // ENEMY_PLANE_H
