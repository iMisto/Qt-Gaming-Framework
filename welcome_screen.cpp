/**
*\file welcome_screen.cpp
*\brief screen that shows when user logins in
*
*
*/
#include "welcome_screen.h"
#include "mainpanel.h"
#include "loginpanel.h"
#include "QDate"
#include "historypanel.h"
#include "battleship_main_menu.h"
#include "game2.h"
#include "game2_main_menu.h"

welcome_screen::welcome_screen(QWidget *parent) : QWidget(parent)
{

    game_1 = new QPushButton("Battleship");
    game_2 = new QPushButton("Shooting discs");
    back_to_main_page = new QPushButton("Back to main page");
    history = new QPushButton("View Game History");
    welcome_panel = new QGridLayout();
    welcome_panel->addWidget(game_1, 4,0,1,2);
    welcome_panel->addWidget(game_2, 4,2,1,2);
    welcome_panel->addWidget(back_to_main_page,5,2,1,2);
    welcome_panel->addWidget(history,5,0,1,2);



    setLayout(welcome_panel);
    this->setFixedSize(600,600);

    this->adjustSize();
    this->move(QApplication::desktop()->screen()->rect().center() - this->rect().center());
    this->setWindowTitle("Welcome Page");
    QObject::connect(back_to_main_page,SIGNAL(clicked()),this,SLOT(back_to_main()));
    QObject::connect(history,SIGNAL(clicked()),this,SLOT(to_history_panel()));
    QObject::connect(game_1,SIGNAL(clicked()),this,SLOT(to_game_1()));
    QObject::connect(game_2,SIGNAL(clicked()),this,SLOT(to_game_2()));
}

void welcome_screen::to_game_1()
{
    this->close();
    Battleship_Main_Menu* new_panel = new Battleship_Main_Menu();
    new_panel->getUser(this->user);
    new_panel->show();
    this->setFixedSize(630,498);

}

void welcome_screen::to_game_2()
{
   this->close();
    game2_main_menu *game2 = new game2_main_menu();
    game2->show();
    game2->getUser(this->user);


}

void welcome_screen::to_history_panel()
{
    this->close();
    historypanel *new_panel = new historypanel();
    new_panel->getHistory(this->user);
    new_panel->show();
    new_panel->setFixedSize(400,400);
}
void welcome_screen::back_to_main()
{
    this->close();
    mainpanel *back_from_welcome = new mainpanel();
    back_from_welcome->show();

}

void welcome_screen::getInfo(QString User)
{

    this->user = User;
    QString user = User;
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

            QJsonObject single = dictionaries.value(user).toObject();
            QString dob = single.value("DOB").toString();
            QString FirstName = single.value("FirstName").toString();
            QString LastName = single.value("LastName").toString();
            QString gender = single.value("Gender").toString();
            QString password = single.value("Password").toString();
            QString PhoneNumber = single.value("PhoneNumber").toString();
            QString Username = single.value("Username").toString();
            welcome_name = new QLabel("Hello "+FirstName+" "+LastName);
            welcome_date = new QLabel("Password:" + password);



            QLabel *flag_pic_display = new QLabel();
            QImage flag_image;

            if (PhoneNumber.contains("+961"))
            {

                //QString flag_path = "/home/eece435l/435-project-group7/Lebanon.jpg";
                flag_image.load(":/flags/Lebanon.png");
                //qDebug() << "FIle exists: " << QFileInfo("/home/eece435l/435-project-group7/UAE.png").exists() << QFileInfo("/home/eece435l/435-project-group7/UAE.png").absolutePath();
                welcome_panel->addWidget(flag_pic_display,0,2);
                flag_pic_display->setPixmap(QPixmap::fromImage(flag_image).scaled(50,50));

            }

            else if (PhoneNumber.contains("+962"))
            {
                flag_image.load(":/flags/Jordan.png");
                welcome_panel->addWidget(flag_pic_display,0,2);
                flag_pic_display->setPixmap(QPixmap::fromImage(flag_image).scaled(50,50));
            }

            else if (PhoneNumber.contains("+966"))
            {
                flag_image.load(":/flags/saudi.png");
                welcome_panel->addWidget(flag_pic_display,0,2);
                flag_pic_display->setPixmap(QPixmap::fromImage(flag_image).scaled(50,50));
            }

            else if (PhoneNumber.contains("+971"))
            {
                flag_image.load(":/flags/UAE.png");
                welcome_panel->addWidget(flag_pic_display,0,2);
                flag_pic_display->setPixmap(QPixmap::fromImage(flag_image).scaled(50,50));
            }

            else if (PhoneNumber.contains("+972"))
            {
                flag_image.load(":/flags/Qatar.png");
                welcome_panel->addWidget(flag_pic_display,0,2);
                flag_pic_display->setPixmap(QPixmap::fromImage(flag_image).scaled(50,50));
            }




            welcome_panel->addWidget(welcome_name,0,0);

            QLabel *welcome_profile_pic_display = new QLabel();
            QImage image;
            QString image_path = single.value("Image").toString();
            //qWarning() << image_path;
            image.load(image_path);

            welcome_panel->addWidget(welcome_profile_pic_display,0,3);
            welcome_profile_pic_display->setPixmap(QPixmap::fromImage(image).scaled(100,100));

            QString s = QDate::currentDate().toString();
            QLabel *current_date = new QLabel(s);
            welcome_panel->addWidget(current_date,0,1);



        }


    }
}
