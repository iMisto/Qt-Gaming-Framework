#include "rightbutton.h"
#include "right_disks.h"
rightbutton::rightbutton(QObject *parent) : QObject(parent)
{
    setPixmap((QPixmap(":/game2/mainblue.png")).scaled(70,70));
}


bool rightbutton::checkColl()
{


    if(!scene()->collidingItems(this).isEmpty())
        {


            QList<QGraphicsItem*> L = scene()->collidingItems(this);
            foreach(QGraphicsItem* i,L)
            {
                right_disks* disk = dynamic_cast<right_disks *>(i);
                if(disk)
                {
                    delete disk;
                }
            }
           // scene()->removeItem(scene()->collidingItems(this).at(0)->toGraphicsObject());
            qWarning() << "hit right";
            return true;

        }

    else {
        qWarning() << "Miss";
    }

    return false;


}
