/**
*\file victory_screen.cpp
*\brief victory screen
*
* implementation of victory screen class
*/
#include "victory_screen.h"
#include "battleship.h"
victory_screen::victory_screen(QWidget *parent) : QWidget(parent)
{
    grid = new QGridLayout();
    victory = new QLabel("Congratulations! You win!");
    return_to_login = new QPushButton("Back to Login Page");

    grid->addWidget(victory,0,0);
    grid->addWidget(return_to_login,0,1);
    this->setFixedSize(400,400);
    this->adjustSize();
    this->move(QApplication::desktop()->screen()->rect().center() - this->rect().center());
    this->setWindowTitle("Victory Screen");


    setLayout(grid);

    QObject::connect(return_to_login,SIGNAL(clicked()),this,SLOT(back_to_login()));


}

void victory_screen::back_to_login()
{
   loginPanel* login = new loginPanel();
   this->close();
   login->show();
}


