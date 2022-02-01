#include <qgraphicsscene.h>
#include <QKeyEvent>
#include <QPoint>
#include "right_disks.h"
#include "extern_vars.h"
#include <iostream>
#include <lose_screen.h>
#include <victory_screen.h>
#include "game2_main_menu.h"

right_disks::right_disks(QObject *parent) : QObject(parent)
{
    //int random_number = rand() % 700;
    this->setPos(465,0);
    setPixmap((QPixmap(":/game2/bluebutt.png").scaled(50,50)));
    QTimer *timer = new QTimer();
    timer->setInterval(100);
    QObject::connect(timer,SIGNAL(timeout()),this,SLOT(update()));
    timer->start();
}

void right_disks::update(){
    setPos(x(),y()+35);

    if (y() > 850){
        missed_disks += 1;
        //std::cout << "right missed" << missed_disks << std::endl;
        scene()->removeItem(this);
        delete this;

        /*if (missed_disks == 3 && total_score < 150)
        {
            game2().view->close();
            //view->close();
            lose_screen *lose = new lose_screen();
            lose->show();
        }

        else if (missed_disks == 3 && total_score >= 150)
        {
            game2().view->close();
            //view->close();
            victory_screen *win = new victory_screen();
            win->show();
        }*/

    }


}
