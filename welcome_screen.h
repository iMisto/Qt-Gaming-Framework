/**
*\file welcome_screen.h
*\brief header file for welcome_screen.cpp
*
*
*/
#ifndef WELCOME_SCREEN_H
#define WELCOME_SCREEN_H

#include <QObject>
#include <QWidget>
#include <QtWidgets>
#include "game2.h"


class welcome_screen : public QWidget
{
    Q_OBJECT

public:

    explicit welcome_screen(QWidget *parent = nullptr);
    QString user;
    void getInfo(QString User);


signals:
public:
    QGridLayout *welcome_panel; //!<main layout
    QPushButton *game_1;//!<button to take user to game1
    QPushButton *game_2;//!<button to take user to game2
    QPushButton *back_to_main_page;//!<back button
    QPushButton *history;//!<history button
    QLabel *welcome_name;//!<display username
    QLabel *welcome_date;//!<display today's date


public slots:
/*!\brief function to go back to previous panel
*/
    void back_to_main();
    /*!\brief function to go to history panel
*/
    void to_history_panel();
    /*!\brief function to launch game1
*/
    void to_game_1();
    /*!\brief function to launch game2
*/
    void to_game_2();


};

#endif // WELCOME_SCREEN_H
