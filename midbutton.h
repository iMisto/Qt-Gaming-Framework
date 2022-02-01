/**
*\file midbutton.h
*\brief midbutton class
*
* class responsible for mid button
*/
#ifndef MIDBUTTON_H
#define MIDBUTTON_H

#include <QObject>
#include <QWidget>
#include <QtWidgets>
#include <QGraphicsPixmapItem>
class midbutton : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit midbutton(QObject *parent = nullptr);
    /*! \brief Function that checks collision between mid button and objects (discs)
     *
     * \return bool: true if there was collision, false otherwise

    */
    bool checkColl();


signals:

};

#endif // MIDBUTTON_H
