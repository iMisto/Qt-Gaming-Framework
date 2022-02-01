/**
*\file mid_disks.h
*\brief mid discs class
*
* class responsible for handling mid discs
*/
#ifndef MID_DISKS_H
#define MID_DISKS_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QGraphicsPathItem>

class mid_disks: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    explicit mid_disks(QObject *parent = 0);

signals:
public slots:
    /*! \brief Function that updates the position of mid discs
     *
     * This function updates the x,y position of a mid disc on screen
     *
     * The function also checks the y() position of a disc and increments missed_disks if that y() position is above a certain value
    */
    void update();
};


#endif // MID_DISKS_H
