/**
*\file battleship.h
*\brief battleship class
*
* class responsible for the battleship game
*/

#ifndef BATTLESHIP_H
#define BATTLESHIP_H

#include <QObject>
#include <QWidget>
#include <QtWidgets>
#include <stdlib.h>     /* srand, rand */
#include <time.h>
#include "question_tab.h"
class battleship : public QWidget
{
    Q_OBJECT
public:
    explicit battleship(QWidget *parent = nullptr);

signals:
public:

    QTime* timer; //!< timer for game duration
    QTimer* timerDecrement; //!< for decrementing timer
    QLabel* decrement;

    QString game_username;
    QGridLayout *screen;
    QGridLayout *goodpractices; //!< Grid for the player's side
    QGridLayout *badpractices;  //!< Grid for the enemy's side
    QPushButton *bad00; //!< badxy: PushButton for enemy's side
    QPushButton *bad01;
    QPushButton *bad02;
    QPushButton *bad03;
    QPushButton *bad10;
    QPushButton *bad11;
    QPushButton *bad12;
    QPushButton *bad13;
    QPushButton *bad20;
    QPushButton *bad21;
    QPushButton *bad22;
    QPushButton *bad23;
    QPushButton *bad30;
    QPushButton *bad31;
    QPushButton *bad32;
    QPushButton *bad33;

    QPushButton *gd00; //!< gdxy PushButton for player's side
    QPushButton *gd01;
    QPushButton *gd02;
    QPushButton *gd03;
    QPushButton *gd10;
    QPushButton *gd11;
    QPushButton *gd12;
    QPushButton *gd13;
    QPushButton *gd20;
    QPushButton *gd21;
    QPushButton *gd22;
    QPushButton *gd23;
    QPushButton *gd30;
    QPushButton *gd31;
    QPushButton *gd32;
    QPushButton *gd33;

    // For the question tab
    QGridLayout* grid; //!< Main grid
    QLabel* question;
    /*
    QRadioButton* answer_1;
    QRadioButton* answer_2;
    QRadioButton* answer_3;
    QGroupBox* answer_group;
    QVBoxLayout* answer_radio;

    QPushButton* submit;

    question_tab* new_tab;
    */

    /*! \brief Function that checks if a pushbutton has been clicked
     *
     * This function disables a push button after it's been clicked once
    */
    void checkCounters();

    /*! \brief Function that gets the username
     *
    */
    void getUser(QString);

    /*! \brief Function that saves the user's score
     * \param player: username of player
     * \param correct: number of correct answers
     * \param incorrect: number of incorrect answers
     *
     * This function checks the json file to find the user
     *
     * It then increments the wins/losses member for the user
    */
    void saveScore(QString player,int correct ,int incorrect );

public slots:
    /*! \brief Function that opens a question tab when a player clicks on a button
     *\return bool to be indicate whether the question tab was opened or not
     *
     * This function randomly picks a question along with its respective answers
     *
     * It displays the question along with the answers using a QInputDialogue
    */
    bool open_question_tab();

    /*! \brief Function that checks if a ship is under a pushbutton
     *
     * This function checks if a ship image is under a pushbutton
     *
     * If there is a ship image, it'll display an explosion (hit) if the player answers correctly
     *
     * If the player answers incorrectly, the ship image is shown and a random ship on the player's side is hit
     *
    */
    void showShip00();
    void showShip01();
    void showShip02();
    void showShip03();
    void showShip10();
    void showShip11();
    void showShip12();
    void showShip13();
    void showShip20();
    void showShip21();
    void showShip22();
    void showShip23();
    void showShip30();
    void showShip31();
    void showShip32();
    void showShip33();

    /*! \brief Function for updating the timer
     *
     * This function updates the 10 minute timer and displays it on screen
    */
    void updateTimer();

};

#endif // BATTLESHIP_H
