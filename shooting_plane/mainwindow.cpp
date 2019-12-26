#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    enemy = new enemy_plane;
    mine = new myplane;
    timer = new QTimer;
    messagebox = new QMessageBox;
    num = 50000;

    mine->set_life(100);
    mine->setliferange(0,100,100);
    enemy->set_life(200);
    enemy->setliferange(0,200,200);

    mine_bullets_x = new QList<int>;
    mine_bullets_y = new QList<int>;
    enemy_bullets_x = new QList<int>;
    enemy_bullets_y = new QList<int>;
    enemy->setParent(ui->centralWidget);
    mine->setParent(ui->centralWidget);
    enemy->show();
    mine->show();

    enemy->setGeometry(this->pos().x()+this->width()/2,this->pos().y(),100,100);
    mine->setGeometry(this->pos().x()+this->width()/2,this->pos().y()+this->height()-100,100,100);

    enemy_bullets_x->append(enemy->pos().x());
    enemy_bullets_y->append(enemy->pos().y());
    enemy_bullets_count++;
    timer->start(200);

    connect(timer,SIGNAL(timeout()),this,SLOT(repainted()));
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::keyPressEvent(QKeyEvent *event)
{
   int x1 = mine->pos().x();
   int y1 = mine->pos().y();
   if(event->key() == Qt::Key_Up)
   {
       mine->setGeometry(x1,y1-10,100,100);
   }else if(event->key() == Qt::Key_Down)
   {
       mine->setGeometry(x1,y1+10,100,100);
   }else if(event->key() == Qt::Key_Left)
   {
       mine->setGeometry(x1-10,y1,100,100);
   }else if(event->key() == Qt::Key_Right)
   {
       mine->setGeometry(x1+10,y1,100,100);
   }
   if(event->key() == Qt::Key_Z)
   {
       mine_bullets_x->append(mine->pos().x());
       mine_bullets_y->append(mine->pos().y());
       count++;
       qDebug() << "bullest长度"<<count;
   }
   if(event->key() == Qt::Key_C)
   {
       readsave();
   }
   if(event->key() == Qt::Key_X)
   {
       save();
   }

}
void MainWindow::repainted()
{   
    for(int i =0;i<enemy_bullets_x->size();i++)
    {
        if(collide_mine_test(mine->pos().x(),mine->pos().y(),enemy_bullets_x->at(i),enemy_bullets_y->at(i)))
        {
            qDebug() <<"我机碰撞检测";
            enemy_bullets_x->removeAt(i);
            enemy_bullets_y->removeAt(i);
            enemy_bullets_count--;
            qDebug() << "enemy counts:" << enemy_bullets_count;
            int hurt = mine->get_life();
            mine->set_life(hurt - 20);
            mine->setcurrent_life(hurt-20);
            if(hurt == 20)
            {
                timer->stop();
                messagebox->setText("你被击落了，你输了！");
                messagebox->exec();
                return;
            }
        }
    }
    for(int i = 0;i<mine_bullets_x->size();i++)
    {
        if(collide_enemy_test(mine_bullets_x->at(i),mine_bullets_y->at(i),enemy->pos().x(),enemy->pos().y()))
        {
            qDebug() << "敌机碰撞检测";
            mine_bullets_x->removeAt(i);
            mine_bullets_y->removeAt(i);
            count--;
            int hurt = enemy->get_life();
            enemy->set_life(hurt-20);
            enemy->set_currentlife(hurt-20);
            if(hurt == 20)
            {
                timer->stop();
                messagebox->setText("敌机被击落，你赢了！");
                messagebox->exec();
                return;
            }
        }
    }
    for(int i =0;i<enemy_bullets_x->size();i++)
    {
        for(int j = 0;j<mine_bullets_x->size();j++)
        {
            qDebug() << "waiceng";
            qDebug() << "j" <<j;
            if(collide_bullets_test(mine_bullets_x->at(j),mine_bullets_y->at(j),enemy_bullets_x->at(i),enemy_bullets_y->at(i)))
            {
                qDebug() << "子弹碰撞检测";
                enemy_bullets_x->removeAt(i);
                enemy_bullets_y->removeAt(i);
                mine_bullets_x->removeAt(j);
                mine_bullets_y->removeAt(j);
                count--;
                qDebug() << "count:" <<count;
                enemy_bullets_count--;
                qDebug() <<"enemy_count:" <<enemy_bullets_count;
            }
            qDebug() << "neiceng";
        }
    }

    for(int i = 0;i<mine_bullets_x->size();i++)
    {
        int x = mine_bullets_y->at(i)-10;
        mine_bullets_y->removeAt(i);
        mine_bullets_y->insert(i,x);
    }
    for(int i = 0;i<enemy_bullets_x->size();i++)
    {
        int x = enemy_bullets_y->at(i)+10;
        enemy_bullets_y->removeAt(i);
        enemy_bullets_y->insert(i,x);
    }
    if(s<=this->width())
    {
        s+=10;
        enemy->setGeometry(enemy->pos().x()+10,this->pos().y(),100,100);
    }else if(2*this->width()>=s>=this->width())
    {
        s+=10;
        enemy->setGeometry(enemy->pos().x()-10,this->pos().y(),100,100);
    }
//    enemy->setGeometry(getrandom(this->pos().x(),this->pos().x()+this->width()),this->pos().y(),100,100);
    enemy_bullets_x->append(enemy->pos().x());
    enemy_bullets_y->append(enemy->pos().y()+100);
    enemy_bullets_count++;

    repaint();
}
void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter;
    painter.begin(this);
    painter.setPen(QPen(Qt::blue));


    for(int i =0;i<mine_bullets_x->size();i++)
    {
        painter.drawRect(mine_bullets_x->at(i),mine_bullets_y->at(i),10,10);
    }
    for(int i =0;i<enemy_bullets_x->size();i++)
    {
        painter.drawRect(enemy_bullets_x->at(i),enemy_bullets_y->at(i),10,10);
    }
    painter.end();
}
int MainWindow::getrandom(int min, int max)
{
    int num = qrand()%(max-min);
    return num+min;
}
bool MainWindow::collide_bullets_test(int x, int y, int x1, int y1)
{
    if(x>=x1&&x<=x1+10&&y<=y1+10)
    {
        return true;
    }else if(x<=x1&&x1<=x+10&&y<=y1+10)
    {
        return true;
    }else
    {
        return false;
    }
}
bool MainWindow::collide_mine_test(int x, int y, int x1, int y1)
{
    if(x>=x1&&x<=x1+10&&y<=y1+10)
    {
        return true;
    }else if(x<=x1&&x>=x1-100&&y<=y1+10)
    {
        return true;
    }else
    {
        return false;
    }
}
bool MainWindow::collide_enemy_test(int x, int y, int x1, int y1)
{
    if(x>=x1&&x<=x1+110&&y<=y1+100)
    {
        return true;
    }else if(x<=x1&&x>=x1-10&&y<=y1+100)
    {
        return true;
    }else
    {
        return false;
    }
}
void MainWindow::save()
{
    QFile file("bullets_geometry.txt");
    file.open(QIODevice::WriteOnly|QIODevice::Text);
    QTextStream out(&file);
    out << "myplane bullets geometry: ";
    for(int i = 0;i<mine_bullets_x->size();i++)
    {
        out << QString::number(mine_bullets_x->at(i));
        out << " ";
        out << QString::number(mine_bullets_y->at(i));
        out << " ";
    }
    out << "\n" <<"enemy bullets geometry: ";
    for(int i = 0;i<enemy_bullets_x->size();i++)
    {
        out << QString::number(enemy_bullets_x->at(i));
        out << " ";
        out << QString::number(enemy_bullets_y->at(i));
        out << " ";
    }
    file.close();
    QFile newfile("plane_geometry.txt");
    newfile.open(QIODevice::WriteOnly);
    QTextStream newout(&newfile);

    newout<<"mine plane geometry: " << mine->pos().x() << " " << mine->pos().y()<<
         "\nenemy plane geometry: " << enemy->pos().x() << " " << enemy->pos().y();
    newfile.close();
}
void MainWindow::readsave()
{
    QFile file("bullets_geometry.txt");
    file.open(QIODevice::ReadOnly);
    QTextStream in(&file);
    QString  data = in.readAll();
    qDebug() << "data:" <<data;
    file.close();
    qDebug () << data.remove("myplane bullets geometry: ");
    qDebug () << data.remove("enemy bullets geometry: ");
    for(int i =0;i<data.size();i++)
    {
        if(data.at(i) == "\r")
        {

        }
    }
}
