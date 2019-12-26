#ifndef MYPLANE_H
#define MYPLANE_H

#include <QWidget>

namespace Ui {
class myplane;
}

class myplane : public QWidget
{
    Q_OBJECT

public:
    explicit myplane(QWidget *parent = 0);
    ~myplane();

private:
    Ui::myplane *ui;
};

#endif // MYPLANE_H
