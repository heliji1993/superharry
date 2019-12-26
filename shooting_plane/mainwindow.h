#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Mine/myplane.h"
#include "Enemy/enemy_plane.h"
#include <QKeyEvent>
#include <QMultiMap>
#include <QDebug>
#include <QTimer>
#include <QMapIterator>
#include <iterator>
#include <QRect>
#include <QPainter>
#include <QTime>
#include <QList>
#include <QMessageBox>
#include <QFile>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    int getrandom(int min,int max);
    bool collide_bullets_test(int x,int y,int x1,int y1);
    bool collide_mine_test(int x,int y,int x1,int y1);
    bool collide_enemy_test(int x,int y,int x1,int y1);
    void save();
    void readsave();
public slots:
    void repainted();
protected:
    void keyPressEvent(QKeyEvent *event);
    void paintEvent(QPaintEvent *event);
private:
    Ui::MainWindow *ui;
    myplane *mine;
    enemy_plane *enemy;
    QMultiMap<int,int> bullets;
    long num;
    QList<int> *mine_bullets_x,*mine_bullets_y,*enemy_bullets_x,*enemy_bullets_y;
    int count = 0,enemy_bullets_count = 0,s = 0;
    QTimer *timer;
    QMessageBox *messagebox;
};

#endif // MAINWINDOW_H
