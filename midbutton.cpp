/**
*\file midbutton.cpp
*\brief midbutton
*
* implementation of midbutton class
*/
#include "midbutton.h"
#include "mid_disks.h"
midbutton::midbutton(QObject *parent) : QObject(parent)
{
    setPixmap((QPixmap(":/game2/mainyellow.png")).scaled(70,70));

}

bool midbutton::checkColl()
{

    if(!scene()->collidingItems(this).isEmpty())
        {
        
            QList<QGraphicsItem*> L = scene()->collidingItems(this);
            foreach(QGraphicsItem* i,L)
            {
                mid_disks* disk = dynamic_cast<mid_disks *>(i);
                if(disk)
                {
                    delete disk;
                }
            }

            qWarning() << "hit mid";
            return true;
        }

    else {
        qWarning() << "Miss";
    }


    return false;
}
