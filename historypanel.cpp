/**
*\file historypanel.cpp
*\brief user game history implementation
*
*
*/
#include "historypanel.h"
#include "welcome_screen.h"
historypanel::historypanel(QWidget *parent) : QWidget(parent)
{

    history_panel = new QGridLayout();
    QPushButton* back_to_welcome = new QPushButton("Back to Welcome");
    history_panel->addWidget(back_to_welcome,2,0);
    this->adjustSize();
    this->move(QApplication::desktop()->screen()->rect().center() - this->rect().center());
    this->setWindowTitle("History Page");

    setLayout(history_panel);

    QObject::connect(back_to_welcome,SIGNAL(clicked()),this,SLOT(back()));

}

void historypanel::getHistory(QString player)
{
    this->his_user = player;
    QString user = player;
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



            int wins = single.value("G1-Wins").toInt();
            int losses = single.value("G1-Losses").toInt();
            qWarning()<<wins;

            QString concwin = "Wins: " + QString::number(wins);
            QString conclos = "Losses: " + QString::number(losses);
            win_label = new QLabel(concwin);
            loss_label = new QLabel(conclos);
            history_panel->addWidget(win_label,0,0);
            history_panel->addWidget(loss_label,1,0);






      }

    }


}

void historypanel::back()
{
    this->close();
    welcome_screen* welcome = new welcome_screen();
    QString u = this->his_user;
    welcome->getInfo(u);
    welcome->show();

}
