/**
*\file battleship_main_menu.cpp
*\brief battleship main menu
*
* implementation of battleship main menu class
*/
#include "battleship_main_menu.h"
#include "battleship.h"
#include <iostream>
using namespace std;
Battleship_Main_Menu::Battleship_Main_Menu(QWidget *parent) : QWidget(parent)
{

    main_menu = new QGridLayout();
    start = new QPushButton("Start");

    QPixmap backgrnd(":/Assets/Main_Menu.png");
    backgrnd = backgrnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, backgrnd);
    setPalette(palette);

    main_menu->addWidget(start,0,0,1,1,Qt::AlignBottom);


    setLayout(main_menu);
    this->setFixedSize(630,498);

    this->adjustSize();
    this->move(QApplication::desktop()->screen()->rect().center() - this->rect().center());
    this->setWindowTitle("Battleship Main Menu");

    QObject::connect(start,SIGNAL(clicked()),this,SLOT(to_new_window()));
}

void Battleship_Main_Menu::to_new_window()
{
    this->close();
    battleship *game_panel = new battleship();
    qWarning()<<this->menu_username;
    game_panel->getUser(this->menu_username);
    game_panel->show();
}

void Battleship_Main_Menu::to_new_window_key_click(QKeyEvent* event)
{
    int keycode = event->key();
    if (keycode == Qt::Key_F1)
    {
        cout << "HEY\n";
        this->close();
        //mainpanel *mainpanel_from_login = new mainpanel();
        //mainpanel_from_login->show();
    }
}
void Battleship_Main_Menu::getUser(QString username)
{

    this->menu_username = username;

}
