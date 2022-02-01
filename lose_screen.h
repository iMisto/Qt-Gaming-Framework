/**
*\file lose_screen.h
*\brief lose_screen class
*
* class responsible for the losing screen at the end of either games
*/
#ifndef LOSE_SCREEN_H
#define LOSE_SCREEN_H

#include <QObject>
#include <QWidget>
#include <QtWidgets>

class lose_screen : public QWidget
{
    Q_OBJECT
public:
    explicit lose_screen(QWidget *parent = nullptr);
    QGridLayout* grid;
    QLabel* lose;
    QPushButton* return_to_login;


private slots:
    /*! \brief Function that takes the user back to login screen

    */
    void back_to_login();


signals:

};

#endif // LOSE_SCREEN_H
