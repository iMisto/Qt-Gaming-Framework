/**
*\file right_disks.h
*\brief right discs class
*
* class responsible for handling right discs
*/
#ifndef RIGHT_DISKS_H
#define RIGHT_DISKS_H

#include <QObject>

#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QGraphicsPathItem>

class right_disks: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    explicit right_disks(QObject *parent = 0);

signals:
public slots:
    /*! \brief Function that updates the position of right discs
     *
     * This function updates the x,y position of a right disc on screen
     *
     * The function also checks the y() position of a disc and increments missed_disks if that y() position is above a certain value
    */
    void update();
};

#endif // RIGHT_DISKS_H
