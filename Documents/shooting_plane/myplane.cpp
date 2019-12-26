#include "myplane.h"
#include "ui_myplane.h"

myplane::myplane(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::myplane)
{
    ui->setupUi(this);
}

myplane::~myplane()
{
    delete ui;
}
