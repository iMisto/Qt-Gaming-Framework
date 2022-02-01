/**
*\file rightbutton.h
*\brief rightbutton class
*
* class responsible for right button
*/

#ifndef RIGHTBUTTON_H
#define RIGHTBUTTON_H

#include <QObject>
#include <QWidget>
#include <QtWidgets>
#include <QGraphicsPixmapItem>
class rightbutton : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit rightbutton(QObject *parent = nullptr);
    /*! \brief Function that checks collision between right button and objects (discs)
     *
     * \return bool: true if there was collision, false otherwise

    */
    bool checkColl();

signals:

};

#endif // RIGHTBUTTON_H
