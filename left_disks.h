/**
*\file left_disks.h
*\brief left discs class
*
* class responsible for handling left discs
*/
#ifndef LEFT_DISKS_H
#define LEFT_DISKS_H
#include "game2.h"
#include <QObject>
#include <QWidget>
#include <QDebug>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QGraphicsPathItem>
class left_disks: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    explicit left_disks(QObject *parent = 0);
signals:

public slots:
    /*! \brief Function that updates the position of left discs
     *
     * This function updates the x,y position of a left disc on screen
     *
     * The function also checks the y() position of a disc and increments missed_disks if that y() position is above a certain value
    */
    void update();

};

#endif // LEFT_DISKS_H
