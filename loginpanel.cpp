/**
*\file loginpanel.cpp
*\brief implementation of login menu
*
*
*/
#include "loginpanel.h"
#include "mainpanel.h"
#include "welcome_screen.h"
#include "signup_form.h"
#include <iostream>
using namespace std;



loginPanel::loginPanel(QWidget *parent) : QWidget(parent)
{
    username_label = new QLabel("Username");
    password_label = new QLabel("Password");
    username_text = new QLineEdit();
    password_text = new QLineEdit();
    password_text->setEchoMode(QLineEdit::Password);
    login_panel = new QGridLayout();
    back_from_login = new QPushButton("Back to main page");
    login = new QPushButton("Login");

    login_panel->addWidget(username_label,1,1);
    login_panel->addWidget(username_text,1,2);
    login_panel->addWidget(password_label,2,1);
    login_panel->addWidget(password_text,2,2);
    login_panel->addWidget(login,3,0,1,3);
    login_panel->addWidget(back_from_login,4,0,1,3);

    this->adjustSize();
    this->move(QApplication::desktop()->screen()->rect().center() - this->rect().center());
    this->setWindowTitle("Login Page");

    setLayout(login_panel);
    this->setFixedSize(250,250);

    QObject::connect(back_from_login,SIGNAL(clicked()),this,SLOT(backfrom_login()));
    QObject::connect(login,SIGNAL(clicked()),this,SLOT(to_welcome_screen()));
}


void loginPanel::backfrom_login()
{
    this->close();
    mainpanel *mainpanel_from_login = new mainpanel();
    mainpanel_from_login->show();
}

void loginPanel::getPassword(QString User)
{
    QString pass = password_text->text();
    QString user = User;
    //qWarning()<<user;
    QFile file("/home/eece435l/435-project-group7/database.json");
    file.open(QIODevice::ReadOnly|QIODevice::Text);
    QJsonDocument content = QJsonDocument::fromJson( file.readAll() );
    QJsonArray list = content.array();
    QJsonObject dictionaries;
    for(int i=0;i<list.size();i++)
    {
        dictionaries = list[i].toObject();

        //bool empty = dictionaries.value(user).toObject().empty();

        if(dictionaries.value(user).toObject().empty()!=true)
        {
            bool pass_match = false;

            QJsonObject single = dictionaries.value(user).toObject();
            QString password = single.value("Password").toString();
            pass_match = (password == pass);

            if (pass_match == true)
            {
                this->close();
                welcome_screen *welcome = new welcome_screen();
                welcome->show();
                //welcome->setFixedSize(800,800);
                welcome->getInfo(user);
            }

            else
            {
                QMessageBox *invalid_password = new QMessageBox();
                invalid_password->critical(0,"Error","The entered password doesn't match the username!");
                invalid_password->setFixedSize(500,200);
            }


        }

    }
}

void loginPanel::to_welcome_screen()
{
    QString user = username_text->text();
    bool notexists = signup_form::isUnique(user);
    if(!notexists){

            getPassword(user);
    }

    else
    {
     QMessageBox *user_error = new QMessageBox();
     user_error->critical(0,"Error","Please enter a valid username");
     user_error->setFixedSize(500,200);
    }

}

