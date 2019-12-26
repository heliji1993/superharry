#include "enemy_plane.h"
#include "ui_enemy_plane.h"

enemy_plane::enemy_plane(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::enemy_plane)
{
    ui->setupUi(this);
}

enemy_plane::~enemy_plane()
{
    delete ui;
}
