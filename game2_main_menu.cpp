/**
*\file game2_main_menu.cpp
*\brief game2 main menu
*
* implementation of game2 main menu class
*/
#include "game2_main_menu.h"
#include "game2.h"
#include "extern_vars.h"
QString ans = "";

game2_main_menu::game2_main_menu(QWidget *parent) : QWidget(parent)
{

    main_menu = new QGridLayout();
    start = new QPushButton("Start");

    QPixmap backgrnd(":/game2/background.jpeg");
    backgrnd = backgrnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, backgrnd);
    setPalette(palette);

    main_menu->addWidget(start,0,0,1,1,Qt::AlignBottom);


    setLayout(main_menu);
    this->setFixedSize(640,480);

    this->adjustSize();
    this->move(QApplication::desktop()->screen()->rect().center() - this->rect().center());
    this->setWindowTitle("Shooting Discs Main Menu");

    QObject::connect(start,SIGNAL(clicked()),this,SLOT(to_new_window()));
}

void game2_main_menu::to_new_window()
{
    QInputDialog* choice = new QInputDialog();
    QString picked_choice;
    QStringList items;
    bool ok = false;
    QString difficulty_1 = "Easy";
    QString difficulty_2 = "Medium";
    QString difficulty_3 = "Hard";
    items << difficulty_1 << difficulty_2 << difficulty_3;
    // dl->getItem returns a string ans which is the selected answer
    ans = choice->getItem(this, "Answer the following question", "Please choose the difficulty of the game", items, 0, false, &ok);

    this->close();
    game2 *scene = new game2();


}

void game2_main_menu::getUser(QString username)
{

    this->menu_username = username;

}
