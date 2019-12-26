#include "myplane.h"
#include "ui_myplane.h"

myplane::myplane(QLabel *parent) :
    QLabel(parent),
    ui(new Ui::myplane)
{
    ui->setupUi(this);
    QPixmap map("myplane.png");
    this->setPixmap(map);
}

myplane::~myplane()
{
    delete ui;
}
void myplane::set_life(int life)
{
    life_value = life;
}
int myplane::get_life()
{
    return life_value;
}
void myplane::setliferange(int min, int max,int initial_life)
{
    ui->progressBar->setMinimum(min);
    ui->progressBar->setMaximum(max);
    ui->progressBar->setFormat("%v");
    ui->progressBar->setValue(initial_life);
}
void myplane::setcurrent_life(int progress)
{
    ui->progressBar->setValue(progress);
}
