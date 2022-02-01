/**
*\file game2.h
*\brief game2 class
*
* class responsible for the shooting discs game
*/
#ifndef GAME2_H
#define GAME2_H

#include <QObject>
#include <QWidget>
#include <QtWidgets>
#include <QGraphicsScene>
#include <QTimer>
#include "leftbutton.h"
#include "midbutton.h"
#include "rightbutton.h"
#include "qgraphicsview.h"
#include <QMediaPlayer>
class game2 : public QGraphicsScene, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit game2(QGraphicsScene *parent = nullptr);
    void keyPressEvent(QKeyEvent* event);

signals:
public:



    QMediaPlayer *music;
    QLabel *counter_label;  //!< Label to keep track of total score and display it
    QGridLayout *background; //!< Background of the game
    leftbutton *leftButton;
    rightbutton *rightButton;
    midbutton *midButton;
    QGraphicsView *view; //!< Graphics View

public slots:
    /*! \brief Function that creates discs in the left lane
     *
     * This function creates discs in the left lane
     *
     * It adjusts the speed at which the discs are created based on the score of the player
     *
     * It starts at 1x speed, increases to 2x, then to 8x
    */
    void create_left();

    /*! \brief Function that creates discs in the middle lane
     *
     * This function creates discs in the middle lane
     *
     * It adjusts the speed at which the discs are created based on the score of the player
     *
     * It starts at 1x speed, increases to 2x, then to 8x
    */
    void create_mid();

    /*! \brief Function that creates discs in the right lane
     *
     * This function creates discs in the right lane
     *
     * It adjusts the speed at which the discs are created based on the score of the player
     *
     * It starts at 1x speed, increases to 2x, then to 8x
    */
    void create_right();

    /*! \brief Function that checks number of missed disks
     *
     * Checks if number of missed disks is 3 to end the game
    */
    void checkMisses();

};

#endif // GAME2_H
