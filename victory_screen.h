/**
*\file victory_screen.h
*\brief victory screen class
*
* class responsible for the victory screen at the end of either games
*/

#ifndef VICTORY_SCREEN_H
#define VICTORY_SCREEN_H

#include <QObject>
#include <QWidget>
#include <QtWidgets>
#include "loginpanel.h"
#include "welcome_screen.h"

class victory_screen : public QWidget
{
    Q_OBJECT
public:
    explicit victory_screen(QWidget *parent = nullptr);

signals:
private:
    QGridLayout* grid;
    QLabel* victory;
    QPushButton* return_to_login;


private slots:
    /*! \brief Function that takes the user back to login screen

    */
    void back_to_login();

};

#endif // VICTORY_SCREEN_H
