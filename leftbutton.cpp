/**
*\file leftbutton.cpp
*\brief leftbutton
*
* implementation of leftbutton class
*/
#include "leftbutton.h"
#include "left_disks.h"
#include "game2.h"
leftbutton::leftbutton(QObject *parent) : QObject(parent)
{
    setPixmap((QPixmap(":/game2/mainredd.png")).scaled(70,70));


}


bool leftbutton::checkColl()
{

    if(!scene()->collidingItems(this).isEmpty())
        {
            QList<QGraphicsItem*> L = scene()->collidingItems(this);
            foreach(QGraphicsItem* i,L)
            {
                left_disks* disk = dynamic_cast<left_disks *>(i);
                if(disk)
                {
                    delete disk;
                }
            }
            qWarning() << "hit left";
            return true;
         }

    else {
        qWarning() << "Miss";
    }

    return false;


}
