/**
*\file lose_screen.cpp
*\brief lose screen
* implementation of lose screen class
*/
#include "lose_screen.h"
#include "loginpanel.h"
#include "battleship.h"
lose_screen::lose_screen(QWidget *parent) : QWidget(parent)
{
    grid = new QGridLayout();
    lose = new QLabel("You lost :(");
    return_to_login = new QPushButton("Back to Login Page");

    grid->addWidget(lose,0,0);
    grid->addWidget(return_to_login,0,1);
    this->setFixedSize(400,400);
    this->adjustSize();
    this->move(QApplication::desktop()->screen()->rect().center() - this->rect().center());
    this->setWindowTitle("Losing Screen");

    setLayout(grid);

    QObject::connect(return_to_login,SIGNAL(clicked()),this,SLOT(back_to_login()));


}




void lose_screen::back_to_login()
{
loginPanel* login = new loginPanel();
this->close();
login->show();
}




