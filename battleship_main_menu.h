/**
*\file battleship_main_menu.h
*\brief battleship main menu class
*
* class responsible for setting up the main menu of the battleship game
*/

#ifndef BATTLESHIP_MAIN_MENU_H
#define BATTLESHIP_MAIN_MENU_H

#include <QObject>
#include <QWidget>
#include <QtWidgets>
#include <QPixmap>
#include <QKeyEvent>

class Battleship_Main_Menu : public QWidget
{
    Q_OBJECT
public:
    explicit Battleship_Main_Menu(QWidget *parent = nullptr);
    /*! \brief Function that takes the user to the battleship game when they click F1 key
     */
    void to_new_window_key_click(QKeyEvent* event);

    /*! \brief Function that retreives the name of the user
     * \param username
    */

    void getUser(QString username);
    QString menu_username;


signals:
private:

    QGridLayout* main_menu;
    QPushButton* start;

private slots:
    /*! \brief Function that takes the user to battleship game when they click start
        */
    void to_new_window();



};

#endif // BATTLESHIP_MAIN_MENU_H
