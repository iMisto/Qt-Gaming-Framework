/**
*\file game2.cpp
*\brief game2
*
* implementation of game2 class
*/
#include "game2.h"
#include "left_disks.h"
#include "mid_disks.h"
#include "right_disks.h"
#include "welcome_screen.h"
#include <QObject>
#include <QWidget>
#include <QDebug>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QGraphicsPathItem>
#include "victory_screen.h"
#include "lose_screen.h"
#include "extern_vars.h"
#include <QMediaPlaylist>

// red yellow blue
// red is worth 3 pts
// yellow is worth 5 pts
// blue is worth 7 pts

// individuals counters to display how many total disks
// of each color the user hits after the game ends

// total_score keeps track of total score which is
// incremented according to respective disk type hit as
// described above

// if missed_disks == 3, game ends

int counter_red = 0; //!< Counter for red discs
int counter_yellow = 0; //!< Counter for yellow discs
int counter_blue = 0; //!< Counter for blue discs
int total_score = 0; //!< Total score counter
int missed_disks = 0; //!< Missed discs counter

QTimer *timer_left = new QTimer(); //!< Timer for spawning left discs on easy mode
QTimer *timer_mid = new QTimer(); //!< Timer for spawning middle discs on easy mode
QTimer *timer_right = new QTimer(); //!< Timer for spawning right discs on easy mode

QTimer *timer_left_medium = new QTimer(); //!< Timer for spawning left discs on medium mode
QTimer *timer_mid_medium = new QTimer(); //!< Timer for spawning middle discs on medium mode
QTimer *timer_right_medium = new QTimer(); //!< Timer for spawning right dics on medium mode

QTimer *timer_left_hard = new QTimer(); //!< Timer for spawning left discs on hard mode
QTimer *timer_mid_hard = new QTimer(); //!< Timer for spawning middle discs on hard mode
QTimer *timer_right_hard = new QTimer(); //!< Timer for spawning right discs on hard mode



game2::game2(QGraphicsScene *parent) : QGraphicsScene(parent)
{


  //  playlist = new QMediaPlaylist();
    music = new QMediaPlayer(); //!< For game music

    music->setMedia(QUrl("qrc:/game2/music.mp3"));
   // music->setPlaylist(playlist);
    music->play();
    music->setVolume(50);
    view = new QGraphicsView(this);
    view->setScene(this);
    view->show();



    view->setFixedSize(579, 838);
    view->setBackgroundBrush((QImage(":/game2/background.jpeg")).scaled(579,838));
    view->setHorizontalScrollBarPolicy((Qt::ScrollBarAlwaysOff));
    view->setVerticalScrollBarPolicy((Qt::ScrollBarAlwaysOff));
    this->setSceneRect(0, 0, 579, 838);

    view->adjustSize();
    view->move(QApplication::desktop()->screen()->rect().center() - view->rect().center());
    view->setWindowTitle("Shooting Discs");

    counter_label = new QLabel("0");
    this->addWidget(counter_label);
    QFont font;
    font.setPointSize(30);

    counter_label->setFont(font);
    counter_label->QWidget::setAttribute(Qt::WA_TranslucentBackground);
    counter_label->setFixedHeight(100);
    counter_label->setFixedWidth(100);
    QGraphicsProxyWidget *proxy = new QGraphicsProxyWidget;
    proxy = this->addWidget(counter_label);
    proxy->setPos(100,100);

    background = new QGridLayout();
    leftButton = new leftbutton();
    midButton = new midbutton();
    rightButton = new rightbutton();

    addItem(leftButton);
    leftButton->setFlag(leftbutton::ItemIsFocusable);
    leftButton->setFocus();
    leftButton->setPos(63, 725);

    addItem(midButton);
    midButton->setFlag(leftbutton::ItemIsFocusable);
    //midButton->setFocus();
    midButton->setPos(263,725);

    addItem(rightButton);
    rightButton->setFlag(leftbutton::ItemIsFocusable);
    //rightButton->setFocus();
    rightButton->setPos(463, 725);


    // since red(left) is worth least pts it's most common
    // yellow(mid) is less common
    // blue is least common

    timer_left->setInterval(4000);
    timer_mid->setInterval(6000);
    timer_right->setInterval(7000);

    timer_left_medium->setInterval(2000);
    timer_mid_medium->setInterval(2500);
    timer_right_medium->setInterval(3000);

    timer_left_hard->setInterval(500);
    timer_mid_hard->setInterval(1000);
    timer_right_hard->setInterval(1100);

    QTimer *check_timer = new QTimer();
    check_timer->setInterval(100);

    QObject::connect(check_timer,SIGNAL(timeout()),this,SLOT(checkMisses()));
    check_timer->start();

    if (ans == "Easy")
    {
        QObject::connect(timer_left,SIGNAL(timeout()),this,SLOT(create_left()));
        QObject::connect(timer_mid,SIGNAL(timeout()),this,SLOT(create_mid()));
        QObject::connect(timer_right,SIGNAL(timeout()),this,SLOT(create_right()));
        timer_left->start();
        timer_mid->start();
        timer_right->start();
    }

    else if (ans == "Medium")
    {

        //qWarning() << "PICKED MEDIUM";
        QObject::connect(timer_left,SIGNAL(timeout()),this,SLOT(create_left()));
        QObject::connect(timer_left_medium,SIGNAL(timeout()),this,SLOT(create_left()));

        QObject::connect(timer_mid,SIGNAL(timeout()),this,SLOT(create_mid()));
        QObject::connect(timer_mid_medium,SIGNAL(timeout()),this,SLOT(create_mid()));

        QObject::connect(timer_right,SIGNAL(timeout()),this,SLOT(create_right()));
        QObject::connect(timer_right_medium,SIGNAL(timeout()),this,SLOT(create_right()));

        timer_left->start();
        timer_mid->start();
        timer_right->start();

        timer_left_medium->start();
        timer_mid_medium->start();
        timer_right_medium->start();
    }

    else if (ans == "Hard")
    {
        ////qWarning() << "PICKED MEDIUM";
        QObject::connect(timer_left,SIGNAL(timeout()),this,SLOT(create_left()));
        QObject::connect(timer_left_hard,SIGNAL(timeout()),this,SLOT(create_left()));

        QObject::connect(timer_mid,SIGNAL(timeout()),this,SLOT(create_mid()));
        QObject::connect(timer_mid_hard,SIGNAL(timeout()),this,SLOT(create_mid()));

        QObject::connect(timer_right,SIGNAL(timeout()),this,SLOT(create_right()));
        QObject::connect(timer_right_hard,SIGNAL(timeout()),this,SLOT(create_right()));

        timer_left->start();
        timer_mid->start();
        timer_right->start();

        timer_left_hard->start();
        timer_mid_hard->start();
        timer_right_hard->start();
    }

}

void game2::create_left()
{
    // if total_score == 30, double speed
    if (total_score >= 30)
    {
        timer_left->setInterval(2000);
    }

    // if total_score == 60, 4x speed
    if (total_score >= 60)
    {
        timer_left->setInterval(1000);
    }

    // if total_score == 120, 16x speed ??
    // 16 seems too much
    // 8 instead??
    if (total_score >= 120)
    {
        timer_left->setInterval(500);
    }

    left_disks *r = new left_disks();
    this->addItem(r);



}

void game2::create_mid()
{
    // if total_score == 30, double speed
    if (total_score >= 30)
    {
        timer_mid->setInterval(3000);
    }

    // if total_score == 60, 4x speed
    if (total_score >= 60)
    {
        timer_mid->setInterval(1500);
    }

    // if total_score == 120, 16x speed ??
    // 16 seems too much
    // 8 instead?
    if (total_score >= 120)
    {
        timer_mid->setInterval(750);
    }
    mid_disks *r = new mid_disks();
    this->addItem(r);
}


void game2::create_right()
{
    // if total_score == 30, double speed
    if (total_score >= 30)
    {
        timer_right->setInterval(3500);

    }

    // if total_score == 60, 4x speed
    if (total_score >= 60)
    {
        timer_right->setInterval(1750);
    }

    // if total_score == 120, 16x speed ???
    // 16 seems too much
    // 8 instead ??
    if (total_score >= 120)
    {
        timer_right->setInterval(875);
    }
    right_disks *r = new right_disks();
    this->addItem(r);

}


void game2::keyPressEvent(QKeyEvent *event)
{
    if( event->key() == Qt::Key_Left )
    {
        leftButton->setFocus();
        if(leftButton->checkColl())
        {
            total_score += 3;
            counter_red += 1;
            QString str_counter = QString::fromStdString(std::to_string(total_score));
            counter_label->setText(str_counter);


        }

        else
        {
            missed_disks += 1;
            //qWarning() << missed_disks;
            /*if (missed_disks == 3 && total_score < 150)
            {
                ////qWarning() << "IM HERE";
                //scene()->clear();

                view->close();
                music->stop();


                lose_screen *lose = new lose_screen();
                lose->show();
            }

            else if (missed_disks == 3 && total_score >= 150)
            {

                music->stop();

                view->close();
                victory_screen *win = new victory_screen();
                win->show();
            }*/

        }


    }

    else if (event->key() == Qt::Key_Down)
    {
        midButton->setFocus();
        if(midButton->checkColl())
        {
            total_score += 5;
            counter_yellow += 1;
            QString str_counter = QString::fromStdString(std::to_string(total_score));
            counter_label->setText(str_counter);
         }

        else
        {
            missed_disks += 1;
            //qWarning() << missed_disks;
            /*if (missed_disks == 3 && total_score < 150)
            {
                ////qWarning() << "IM HERE";
                music->stop();

                delete this;
                view->close();
                lose_screen *lose = new lose_screen();
                lose->show();
            }

            else if (missed_disks == 3 && total_score >= 150)
            {

                music->stop();

                delete this;
                view->close();
                victory_screen *win = new victory_screen();
                win->show();
            }*/

        }

    }

    else if (event->key() == Qt::Key_Right)
    {
        rightButton->setFocus();
        if(rightButton->checkColl())
        {
            total_score += 7;
            counter_blue += 1;
            QString str_counter = QString::fromStdString(std::to_string(total_score));
            counter_label->setText(str_counter);
        }

        else
        {

            missed_disks += 1;
            //qWarning() << missed_disks;
            /*if (missed_disks == 3 && total_score < 150)
            {
                ////qWarning() << "IM HERE";
                music->stop();

                delete this;
                view->close();
                lose_screen *lose = new lose_screen();
                lose->show();
            }

            else if (missed_disks == 3 && total_score >= 150)
            {
                music->stop();

                delete this;
                view->close();
                victory_screen *win = new victory_screen();
                win->show();
            }*/

        }
    }
}

void game2::checkMisses()
{
    if (missed_disks == 3 && total_score < 150)
    {
        music->stop();

        view->close();
        delete this;
        lose_screen *lose = new lose_screen();
        lose->adjustSize();
        lose->move(QApplication::desktop()->screen()->rect().center() - lose->rect().center());
        lose->setWindowTitle("Lose Screen");
        lose->show();

        // reset
        missed_disks = 0;
        total_score = 0;
    }

    else if (missed_disks == 3 && total_score >= 150)
    {
        music->stop();

        view->close();
        delete this;
        victory_screen *win = new victory_screen();
        win->adjustSize();
        win->move(QApplication::desktop()->screen()->rect().center() - win->rect().center());
        win->setWindowTitle("Victory Screen");
        win->show();

        // reset
        missed_disks = 0;
        total_score = 0;
    }
}
