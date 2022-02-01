/**
*\file left_disks.cpp
*\brief left discs
*
* implementation of the left_disks class
*/
#include "left_disks.h"
#include <qgraphicsscene.h>
#include <QKeyEvent>
#include <QPoint>
#include <iostream>
#include "extern_vars.h"
#include "lose_screen.h"
#include "victory_screen.h"
#include "game2_main_menu.h"
#include "game2.h"
left_disks::left_disks(QObject *parent) : QObject(parent)
{
    //int random_number = rand() % 700;
    this->setPos(67,0);
    setPixmap((QPixmap(":/game2/redbutt.png").scaled(50,50)));
    QTimer *timer = new QTimer();
    timer->setInterval(100);
    QObject::connect(timer,SIGNAL(timeout()),this,SLOT(update()));
    timer->start();
}

void left_disks::update()
{
    setPos(x(),y()+35);

    if (y() > 850)
    {
        missed_disks += 1;
        qWarning() << "left missed" << missed_disks;
        scene()->removeItem(this);
        delete this;

    }


}



