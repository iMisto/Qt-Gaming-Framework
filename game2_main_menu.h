/**
*\file game2_main_menu.h
*\brief game2 main meenu class
*
* class responsible for the shooting discs game
*/
#ifndef GAME2_MAIN_MENU_H
#define GAME2_MAIN_MENU_H

#include <QObject>
#include <QWidget>
#include <QtWidgets>
class game2_main_menu : public QWidget
{
    Q_OBJECT
public:
    explicit game2_main_menu(QWidget *parent = nullptr);

signals:
public:

    QGridLayout* main_menu; //!< Grid for the main menu
    QPushButton* start; //!< Start button
    /*! \brief Function that retreives username
     *
    */
    void getUser(QString username);
    QString menu_username;

private slots:
    /*! \brief Function that launches the shooting discs game
     *
    */
    void to_new_window();

};

#endif // GAME2_MAIN_MENU_H
