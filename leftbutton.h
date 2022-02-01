/**
*\file leftbutton.h
*\brief leftbutton class
*
* class responsible for left button
*/
#ifndef LEFTBUTTON_H
#define LEFTBUTTON_H

#include <QObject>
#include <QWidget>
#include <QtWidgets>
#include <QGraphicsPixmapItem>
class leftbutton : public QObject, public QGraphicsPixmapItem

{
    Q_OBJECT
public:
    explicit leftbutton(QObject *parent = 0);
    /*! \brief Function that checks collision between left button and objects (discs)
     *
     * \return bool: true if there was collision, false otherwise

    */
    bool checkColl();

signals:


};

#endif // LEFTBUTTON_H

