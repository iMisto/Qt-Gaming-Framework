/**
*\file mainpanel.cpp
*\brief mainpanel
*
* interface for welcoming users
*/
#include "mainpanel.h"
#include "loginpanel.h"
#include "signup_form.h"
mainpanel::mainpanel(QWidget *parent) : QWidget(parent)
{

    signup = new QPushButton("Sign Up");
    signin = new QPushButton("Sign in");
    playguest = new QPushButton("Play as Guest");
    panel = new QGridLayout();
    panel->addWidget(signin,0,0);
    panel->addWidget(playguest,0,2);
    panel->addWidget(signup,1,1);
    panel->setColumnMinimumWidth(0,5);
    this->adjustSize();
    this->move(QApplication::desktop()->screen()->rect().center() - this->rect().center());
    this->setWindowTitle("Main Page");
    setLayout(panel);

    QObject::connect(signin,SIGNAL(clicked()),this,SLOT(openLoginPanel()));
    QObject::connect(signup,SIGNAL(clicked()),this,SLOT(openSignupPanel()));
    QObject::connect(playguest,SIGNAL(clicked()),this,SLOT(playAsGuest()));
}

void mainpanel::openLoginPanel()
{
    this->close();
    loginPanel *loginpanel = new loginPanel();
    loginpanel->show();


}

void mainpanel::openSignupPanel()
{
    this->close();
    signup_form *signupPanel = new signup_form();
    signupPanel->show();


}

void mainpanel::playAsGuest()
{
    this->close();
    welcome_screen* welcome = new welcome_screen();
    welcome->show();
}
