#include "enemy_plane.h"
#include "ui_enemy_plane.h"

enemy_plane::enemy_plane(QLabel *parent) :
    QLabel(parent),
    ui(new Ui::enemy_plane)
{
    ui->setupUi(this);
    QPixmap map("enemy_plane.png");
    this->setPixmap(map);
}

enemy_plane::~enemy_plane()
{
    delete ui;
}
void enemy_plane::set_life(int life)
{
    life_value = life;
}
int enemy_plane::get_life()
{
    return life_value;
}
void enemy_plane::setliferange(int min, int max, int initial_life)
{
    ui->progressBar->setMaximum(max);
    ui->progressBar->setMinimum(min);
    ui->progressBar->setFormat("%v");
    ui->progressBar->setValue(initial_life);
}
void enemy_plane::set_currentlife(int lifevalue)
{
    ui->progressBar->setValue(lifevalue);
}
