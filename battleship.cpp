/**
*\file battleship.cpp
*\brief battleship
*
* implementation of battleship class
*/

#include "battleship.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>
#include "question_tab.h"
#include <unordered_map>
#include <QtGlobal>
#include "victory_screen.h"
#include "lose_screen.h"

#define GET_VARIABLE_NAME(Variable) (#Variable)
using namespace std;

int seconds = 600;

//correct answers needed
int correct = 0;
//incorrect answers for loss
int incorrect = 0;

QString question_path;
QString correct_path;


// for random numbers
int i = 0;
static QList<int> rand_nums = QList<int>();

// random number for the player side
int j = -1;

QList<int> good_ships = QList<int>{10,12,13,30,31,32,33};
static QList<int> rand_nums_good = QList<int>();

// for explosion
QString path_explosion = ":/game1assets/pop.png";


int check = 1;
unordered_map<string,QString> urlmap;

unordered_map<string,QString> explodedmap;

battleship::battleship(QWidget *parent) : QWidget(parent)
{
    decrement = new QLabel();
    QInputDialog* choice = new QInputDialog();
      QString picked_choice;
      QStringList items;
      bool ok = false;
      QString set_1 = "Programming Concepts";
      QString set_2 = "Movies and TV";
      QString set_3 = "Music";
      items << set_1 << set_2 << set_3;
      // dl->getItem returns a string ans which is the selected answer
      QString ans = choice->getItem(this, "Answer the following question", "Please choose the genre of questions", items, 0, false, &ok);

      if (ans == set_1)
      {
         question_path = "/home/eece435l/435-project-group7/questions_answers_PC.json";
         correct_path = "/home/eece435l/435-project-group7/correct_answers_PC.json";
      }

      else if (ans == set_2)
      {
          question_path = "/home/eece435l/435-project-group7/questions_answers_MOVTV.json";
          correct_path = "/home/eece435l/435-project-group7/correct_answers_MOVTV.json";
      }

      else if (ans == set_3)
      {
          question_path = "/home/eece435l/435-project-group7/questions_answers_MUS.json";
          correct_path = "/home/eece435l/435-project-group7/correct_answers_MUS.json";
      }

      timer = new QTime(0,10,0);
      timerDecrement = new QTimer(this);
      timerDecrement->start(1000);

      connect(timerDecrement, SIGNAL(timeout()), this, SLOT(updateTimer()));



  screen = new QGridLayout();
  badpractices = new QGridLayout();
  goodpractices = new QGridLayout();
///"home/eece435l/435-project-group7/Lebanon.png"
  QPixmap bkgnd(":/game1assets/background.png");
      bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
      QPalette palette;
      palette.setBrush(QPalette::Background, bkgnd);
      setPalette(palette);
    bad00 = new QPushButton();
    bad01 = new QPushButton();
    bad02 = new QPushButton();
    bad03 = new QPushButton();
    bad10 = new QPushButton();
    bad11 = new QPushButton();
    bad12 = new QPushButton();
    bad13 = new QPushButton();
    bad20 = new QPushButton();
    bad21 = new QPushButton();
    bad22 = new QPushButton();
    bad23 = new QPushButton();
    bad30 = new QPushButton();
    bad31 = new QPushButton();
    bad32 = new QPushButton();
    bad33 = new QPushButton();




    bad00->setFixedSize(55,55);
    bad01->setFixedSize(55,55);
    bad02->setFixedSize(55,55);
    bad03->setFixedSize(55,55);
    bad10->setFixedSize(55,55);
    bad11->setFixedSize(55,55);
    bad12->setFixedSize(55,55);
    bad13->setFixedSize(55,55);
    bad20->setFixedSize(55,55);
    bad21->setFixedSize(55,55);
    bad22->setFixedSize(55,55);
    bad23->setFixedSize(55,55);
    bad30->setFixedSize(55,55);
    bad31->setFixedSize(55,55);
    bad32->setFixedSize(55,55);
    bad33->setFixedSize(55,55);


    gd00 = new QPushButton();
    gd01 = new QPushButton();
    gd02 = new QPushButton();
    gd03 = new QPushButton();
    gd10 = new QPushButton();
    gd11 = new QPushButton();
    gd12 = new QPushButton();
    gd13 = new QPushButton();
    gd20 = new QPushButton();
    gd21 = new QPushButton();
    gd22 = new QPushButton();
    gd23 = new QPushButton();
    gd30 = new QPushButton();
    gd31 = new QPushButton();
    gd32 = new QPushButton();
    gd33 = new QPushButton();



    gd00->setFixedSize(55,55);
    gd01->setFixedSize(55,55);
    gd02->setFixedSize(55,55);
    gd03->setFixedSize(55,55);
    gd10->setFixedSize(55,55);
    gd11->setFixedSize(55,55);
    gd12->setFixedSize(55,55);
    gd13->setFixedSize(55,55);
    gd20->setFixedSize(55,55);
    gd21->setFixedSize(55,55);
    gd22->setFixedSize(55,55);
    gd23->setFixedSize(55,55);
    gd30->setFixedSize(55,55);
    gd31->setFixedSize(55,55);
    gd32->setFixedSize(55,55);
    gd33->setFixedSize(55,55);


    badpractices->addWidget(bad00,0,0);
    badpractices->addWidget(bad01,0,1);
    badpractices->addWidget(bad02,0,2);
    badpractices->addWidget(bad03,0,3);
    badpractices->addWidget(bad10,1,0);
    badpractices->addWidget(bad11,1,1);
    badpractices->addWidget(bad12,1,2);
    badpractices->addWidget(bad13,1,3);
    badpractices->addWidget(bad20,2,0);
    badpractices->addWidget(bad21,2,1);
    badpractices->addWidget(bad22,2,2);
    badpractices->addWidget(bad23,2,3);
    badpractices->addWidget(bad30,3,0);
    badpractices->addWidget(bad31,3,1);
    badpractices->addWidget(bad32,3,2);
    badpractices->addWidget(bad33,3,3);

    goodpractices->addWidget(gd00,0,0);
    goodpractices->addWidget(gd01,0,1);
    goodpractices->addWidget(gd02,0,2);
    goodpractices->addWidget(gd03,0,3);
    goodpractices->addWidget(gd10,1,0);
    goodpractices->addWidget(gd11,1,1);
    goodpractices->addWidget(gd12,1,2);
    goodpractices->addWidget(gd13,1,3);
    goodpractices->addWidget(gd20,2,0);
    goodpractices->addWidget(gd21,2,1);
    goodpractices->addWidget(gd22,2,2);
    goodpractices->addWidget(gd23,2,3);
    goodpractices->addWidget(gd30,3,0);
    goodpractices->addWidget(gd31,3,1);
    goodpractices->addWidget(gd32,3,2);
    goodpractices->addWidget(gd33,3,3);


    // Setting ships on good practices side
    QString path_small_ship = ":/game1assets/smallboat.png";
    gd10->setIcon(QIcon(path_small_ship));
    gd10->setIconSize(QSize(55,55));

    QString path_med_ship_0 = ":/game1assets/Mid1.png";
    QString path_med_ship_1 = ":/game1assets/Mid2.png";

    gd12->setIcon(QIcon(path_med_ship_0));
    gd12->setIconSize(QSize(55,55));

    gd13->setIcon(QIcon(path_med_ship_1));
    gd13->setIconSize(QSize(55,55));

    QString path_big_ship_0 = ":/game1assets/Boat1.png";
    QString path_big_ship_1 = ":/game1assets/Boat2.png";
    QString path_big_ship_2 = ":/game1assets/Boat3.png";
    QString path_big_ship_3 = ":/game1assets/Boat4.png";

    gd30->setIcon(QIcon(path_big_ship_0));
    gd30->setIconSize(QSize(55,55));

    gd31->setIcon(QIcon(path_big_ship_1));
    gd31->setIconSize(QSize(55,55));

    gd32->setIcon(QIcon(path_big_ship_2));
    gd32->setIconSize(QSize(55,55));

    gd33->setIcon(QIcon(path_big_ship_3));
    gd33->setIconSize(QSize(55,55));


    //SHIP PLACEMENT GENERATION
    int placements [4] = {0,1,2,3};
    srand (time(NULL));
    // 4-length ship
    random_shuffle(placements,placements+4);


    string bigrow = to_string(placements[0]);
    string midrow = to_string(placements[1]);
    string smallrow = to_string(placements[2]);
    string smallcol = to_string((placements[2] + placements[0] ) %4 );
    int midcol = ( placements[1] + placements[3] ) %3;
    string extrarow = to_string(placements[3]);
    int extracol = ((placements[2] + placements[0]) %2); //0 or 1



    string varname = "bad";
    varname += bigrow; //var name now bad3 for example
    string big_piece1 = varname+"0"; //bad30
    string big_piece2 = varname+"1"; //bad31
    string big_piece3 = varname+"2"; //bad32
    string big_piece4 = varname+"3"; //bad33

    urlmap.insert(make_pair(big_piece1,":/game1assets/Boat1.png"));
    urlmap.insert(make_pair(big_piece2,":/game1assets/Boat2.png"));
    urlmap.insert(make_pair(big_piece3,":/game1assets/Boat3.png"));
    urlmap.insert(make_pair(big_piece4,":/game1assets/Boat4.png"));

    varname = "bad";
    varname += midrow;
    string mid_piece1 = varname+ to_string(midcol);
    midcol++;
    string mid_piece2 = varname+ to_string(midcol);
    urlmap.insert(make_pair(mid_piece1,":/game1assets/Mid1.png"));
    urlmap.insert(make_pair(mid_piece2,":/game1assets/Mid2.png"));
    varname = "bad";

    string small_piece = varname + smallrow + smallcol;

    urlmap.insert(make_pair(small_piece,":/game1assets/smallboat.png"));

    varname = "bad";
    string extra1 = varname+extrarow+to_string(extracol); //badij
    string extra2 = varname+extrarow+to_string(extracol+extracol+1); //badi'j'
    string extra3 = varname+extrarow+to_string( (extracol+extracol+2)%4);
    urlmap.insert(make_pair(extra1,":/game1assets/smallboat.png"));
    urlmap.insert(make_pair(extra2,":/game1assets/smallboat.png"));
    urlmap.insert(make_pair(extra3,":/game1assets/smallboat.png"));







    QObject::connect(bad00,SIGNAL(clicked()),this,SLOT(showShip00()));
    QObject::connect(bad01,SIGNAL(clicked()),this,SLOT(showShip01()));
    QObject::connect(bad02,SIGNAL(clicked()),this,SLOT(showShip02()));
    QObject::connect(bad03,SIGNAL(clicked()),this,SLOT(showShip03()));

     QObject::connect(bad20,SIGNAL(clicked()),this,SLOT(showShip20()));
     QObject::connect(bad21,SIGNAL(clicked()),this,SLOT(showShip21()));
     QObject::connect(bad22,SIGNAL(clicked()),this,SLOT(showShip22()));
     QObject::connect(bad23,SIGNAL(clicked()),this,SLOT(showShip23()));

     QObject::connect(bad30,SIGNAL(clicked()),this,SLOT(showShip30()));
     QObject::connect(bad31,SIGNAL(clicked()),this,SLOT(showShip31()));
     QObject::connect(bad32,SIGNAL(clicked()),this,SLOT(showShip32()));
     QObject::connect(bad33,SIGNAL(clicked()),this,SLOT(showShip33()));

     QObject::connect(bad10,SIGNAL(clicked()),this,SLOT(showShip10()));
     QObject::connect(bad11,SIGNAL(clicked()),this,SLOT(showShip11()));
     QObject::connect(bad12,SIGNAL(clicked()),this,SLOT(showShip12()));
     QObject::connect(bad13,SIGNAL(clicked()),this,SLOT(showShip13()));



    //Adding ship icons
    bad00->setStyleSheet("background-color : blue");
    bad01->setStyleSheet("background-color : blue");
    bad02->setStyleSheet("background-color : blue");
    bad03->setStyleSheet("background-color : blue");
    bad10->setStyleSheet("background-color : blue");
    bad11->setStyleSheet("background-color : blue");
    bad12->setStyleSheet("background-color : blue");
    bad13->setStyleSheet("background-color : blue");
    bad20->setStyleSheet("background-color : blue");
    bad21->setStyleSheet("background-color : blue");
    bad22->setStyleSheet("background-color : blue");
    bad23->setStyleSheet("background-color : blue");
    bad30->setStyleSheet("background-color : blue");
    bad31->setStyleSheet("background-color : blue");
    bad32->setStyleSheet("background-color : blue");
    bad33->setStyleSheet("background-color : blue");

     gd00->setStyleSheet("background-color : blue");
     gd01->setStyleSheet("background-color : blue");
     gd02->setStyleSheet("background-color : blue");
     gd03->setStyleSheet("background-color : blue");
     gd10->setStyleSheet("background-color : blue");
     gd11->setStyleSheet("background-color : blue");
     gd12->setStyleSheet("background-color : blue");
     gd13->setStyleSheet("background-color : blue");
     gd20->setStyleSheet("background-color : blue");
     gd21->setStyleSheet("background-color : blue");
     gd22->setStyleSheet("background-color : blue");
     gd23->setStyleSheet("background-color : blue");
     gd30->setStyleSheet("background-color : blue");
     gd31->setStyleSheet("background-color : blue");
     gd32->setStyleSheet("background-color : blue");
     gd33->setStyleSheet("background-color : blue");

    screen->addLayout(badpractices,1,7);
    screen->addWidget(decrement,1,4);
    screen->addLayout(goodpractices,1,1);
    this->setFixedSize(650,350);

    this->adjustSize();
    this->move(QApplication::desktop()->screen()->rect().center() - this->rect().center());
    this->setWindowTitle("Battleship");

    setLayout(screen);




}

void battleship::updateTimer(){
    *timer = timer->addSecs(-1);
    seconds--;
    decrement->setText("Time Remaining:\n    "+ timer->toString("m:ss"));
    QTime *end= new QTime(0,0,0);
    if (seconds == 0) {
        timerDecrement->stop();
        //qInfo()<<"hi";
        this->close();
        lose_screen* lost = new lose_screen();
        lost->show();
    }
}

bool battleship::open_question_tab()
{

    // for questions
    //new_tab = new question_tab();
    rand_nums.append(0);

    //grid = new QGridLayout();
    srand(time(0));

    while (rand_nums.contains(i))
    {
        i = rand()%16 + 1;
    }

    rand_nums.append(i);

    //qWarning() << i << endl;
    QFile file(question_path);
    file.open(QIODevice::ReadOnly|QIODevice::Text);
    QJsonDocument content = QJsonDocument::fromJson( file.readAll() );

    QString rand_question = "Quest_" + QString::number(i);
    //qWarning() << rand_question << endl;

    QJsonValue quest = content.object().value(rand_question);
    QString quest_txt = quest.toString();
    QString ans1 = content.object().value("Ans_" + QString::number(i) + "1").toString();
    QString ans2 = content.object().value("Ans_" + QString::number(i) + "2").toString();
    QString ans3 = content.object().value("Ans_" + QString::number(i) + "3").toString();

    // Dialogue Box for questions and answers
    QInputDialog* dl = new QInputDialog();
    dl->resize(500,500);
    QStringList items;
    bool ok = false;
    items << ans1 << ans2 << ans3;
    // dl->getItem returns a string ans which is the selected answer
    QString ans = dl->getItem(this, "Answer the following question", quest_txt, items, 0, false, &ok);

    QFile file2(correct_path);
    file2.open(QIODevice::ReadOnly|QIODevice::Text);
    QJsonDocument content_correct = QJsonDocument::fromJson( file2.readAll() );

    QString correct = content_correct.object().value("C" + QString::number(i)).toString();

   // qWarning() << ans << endl;

    // check if ans is correct
    if (ans == correct){
        return true;
    }

    return false;

}


// show ship functions
void battleship::showShip00()
{

    unordered_map<string,QString>::const_iterator got = urlmap.find("bad00");
    if (got != urlmap.end())
    {
        if (open_question_tab())
        {
            bad00->setIcon(QIcon(path_explosion));
            bad00->setIconSize(QSize(55,55));
            correct++;
            //trials--;

        }

        else{
            QString path = got->second;
            bad00->setIcon(QIcon(path));
            bad00->setIconSize(QSize(55,55));
            rand_nums_good.append(j);

            while (rand_nums_good.contains(j)){
                j = rand() % 6;
            }

            int ship_num = good_ships.at(j);

                if (ship_num == 10)
                {
                    gd10->setIcon(QIcon(path_explosion));
                    gd10->setIconSize(QSize(55,55));
                }

                else if (ship_num == 12)
                {
                    gd12->setIcon(QIcon(path_explosion));
                    gd12->setIconSize(QSize(55,55));
                }

                else if (ship_num == 13)
                {
                    gd13->setIcon(QIcon(path_explosion));
                    gd13->setIconSize(QSize(55,55));
                }

                else if (ship_num == 30)
                {
                    gd30->setIcon(QIcon(path_explosion));
                    gd30->setIconSize(QSize(55,55));
                }

                else if (ship_num == 31)
                {
                    gd31->setIcon(QIcon(path_explosion));
                    gd31->setIconSize(QSize(55,55));
                }

                else if (ship_num == 32)
                {
                    gd32->setIcon(QIcon(path_explosion));
                    gd32->setIconSize(QSize(55,55));
                }

                else if (ship_num == 33)
                {
                    gd33->setIcon(QIcon(path_explosion));
                    gd33->setIconSize(QSize(55,55));
                }

                incorrect++;

        }
        }
    else
    {
        bad00->setIcon(QIcon(":/game1assets/splash.png"));
        bad00->setIconSize(QSize(55,55));
    }

    checkCounters();
    bad00->blockSignals(true);
    }

void battleship::showShip01()
{

    unordered_map<string,QString>::const_iterator got = urlmap.find("bad01");
    if (got != urlmap.end())
    {

        if (open_question_tab())
        {
            bad01->setIcon(QIcon(path_explosion));
            bad01->setIconSize(QSize(55,55));
            correct++;

         }

        else
        {
            QString path = got->second;
            bad01->setIcon(QIcon(path));
            bad01->setIconSize(QSize(55,55));

            rand_nums_good.append(j);

            while (rand_nums_good.contains(j))
            {
                j = rand() % 6;
            }

            int ship_num = good_ships.at(j);

                if (ship_num == 10)
                {
                    gd10->setIcon(QIcon(path_explosion));
                    gd10->setIconSize(QSize(55,55));
                }

                else if (ship_num == 12)
                {
                    gd12->setIcon(QIcon(path_explosion));
                    gd12->setIconSize(QSize(55,55));
                }

                else if (ship_num == 13)
                {
                    gd13->setIcon(QIcon(path_explosion));
                    gd13->setIconSize(QSize(55,55));
                }

                else if (ship_num == 30)
                {
                    gd30->setIcon(QIcon(path_explosion));
                    gd30->setIconSize(QSize(55,55));
                }

                else if (ship_num == 31)
                {
                    gd31->setIcon(QIcon(path_explosion));
                    gd31->setIconSize(QSize(55,55));
                }

                else if (ship_num == 32)
                {
                    gd32->setIcon(QIcon(path_explosion));
                    gd32->setIconSize(QSize(55,55));
                }

                else if (ship_num == 33)
                {
                    gd33->setIcon(QIcon(path_explosion));
                    gd33->setIconSize(QSize(55,55));
                }

                incorrect++;
        }


    }

    else
    {
        bad01->setIcon(QIcon(":/game1assets/splash.png"));
        bad01->setIconSize(QSize(55,55));
    }

    checkCounters();
    bad01->blockSignals(true);

}
void battleship::showShip02()
{

    unordered_map<string,QString>::const_iterator got = urlmap.find("bad02");
    if (got != urlmap.end())
    {

        if (open_question_tab())
        {
            bad02->setIcon(QIcon(path_explosion));
            bad02->setIconSize(QSize(55,55));
            correct++;

         }

        else
        {
            QString path = got->second;
            bad02->setIcon(QIcon(path));
            bad02->setIconSize(QSize(55,55));

            rand_nums_good.append(j);

            while (rand_nums_good.contains(j)){
                j = rand() % 6;
            }

            int ship_num = good_ships.at(j);

                if (ship_num == 10)
                {
                    gd10->setIcon(QIcon(path_explosion));
                    gd10->setIconSize(QSize(55,55));
                }

                else if (ship_num == 12)
                {
                    gd12->setIcon(QIcon(path_explosion));
                    gd12->setIconSize(QSize(55,55));
                }

                else if (ship_num == 13)
                {
                    gd13->setIcon(QIcon(path_explosion));
                    gd13->setIconSize(QSize(55,55));
                }

                else if (ship_num == 30)
                {
                    gd30->setIcon(QIcon(path_explosion));
                    gd30->setIconSize(QSize(55,55));
                }

                else if (ship_num == 31)
                {
                    gd31->setIcon(QIcon(path_explosion));
                    gd31->setIconSize(QSize(55,55));
                }

                else if (ship_num == 32)
                {
                    gd32->setIcon(QIcon(path_explosion));
                    gd32->setIconSize(QSize(55,55));
                }

                else if (ship_num == 33)
                {
                    gd33->setIcon(QIcon(path_explosion));
                    gd33->setIconSize(QSize(55,55));
                }

            incorrect++;
         }


    }

    else
    {
        bad02->setIcon(QIcon(":/game1assets/splash.png"));
        bad02->setIconSize(QSize(55,55));
    }

    checkCounters();
    bad02->blockSignals(true);

}
void battleship::showShip03()
{

    unordered_map<string,QString>::const_iterator got = urlmap.find("bad03");
    if (got != urlmap.end())
    {

        if (open_question_tab())
        {
            bad03->setIcon(QIcon(path_explosion));
            bad03->setIconSize(QSize(55,55));
            correct++;

        }

        else
        {
            QString path = got->second;
            bad03->setIcon(QIcon(path));
            bad03->setIconSize(QSize(55,55));

            rand_nums_good.append(j);

            while (rand_nums_good.contains(j)){
                j = rand() % 6;
            }

            int ship_num = good_ships.at(j);

                if (ship_num == 10)
                {
                    gd10->setIcon(QIcon(path_explosion));
                    gd10->setIconSize(QSize(55,55));
                }

                else if (ship_num == 12)
                {
                    gd12->setIcon(QIcon(path_explosion));
                    gd12->setIconSize(QSize(55,55));
                }

                else if (ship_num == 13)
                {
                    gd13->setIcon(QIcon(path_explosion));
                    gd13->setIconSize(QSize(55,55));
                }

                else if (ship_num == 30)
                {
                    gd30->setIcon(QIcon(path_explosion));
                    gd30->setIconSize(QSize(55,55));
                }

                else if (ship_num == 31)
                {
                    gd31->setIcon(QIcon(path_explosion));
                    gd31->setIconSize(QSize(55,55));
                }

                else if (ship_num == 32)
                {
                    gd32->setIcon(QIcon(path_explosion));
                    gd32->setIconSize(QSize(55,55));
                }

                else if (ship_num == 33)
                {
                    gd33->setIcon(QIcon(path_explosion));
                    gd33->setIconSize(QSize(55,55));
                }

                incorrect++;
        }


       }

    else
    {
        bad03->setIcon(QIcon(":/game1assets/splash.png"));
        bad03->setIconSize(QSize(55,55));
    }

    checkCounters();
    bad03->blockSignals(true);
}
void battleship::showShip10()
{

    unordered_map<string,QString>::const_iterator got = urlmap.find("bad10");
    if (got != urlmap.end())
    {
        if (open_question_tab())
        {

            bad10->setIcon(QIcon(path_explosion));
            bad10->setIconSize(QSize(55,55));
            correct++;

     }

        else
        {
            QString path = got->second;
            bad10->setIcon(QIcon(path));
            bad10->setIconSize(QSize(55,55));

            rand_nums_good.append(j);

            while (rand_nums_good.contains(j)){
                j = rand() % 6;
            }

            int ship_num = good_ships.at(j);

                if (ship_num == 10)
                {
                    gd10->setIcon(QIcon(path_explosion));
                    gd10->setIconSize(QSize(55,55));
                }

                else if (ship_num == 12)
                {
                    gd12->setIcon(QIcon(path_explosion));
                    gd12->setIconSize(QSize(55,55));
                }

                else if (ship_num == 13)
                {
                    gd13->setIcon(QIcon(path_explosion));
                    gd13->setIconSize(QSize(55,55));
                }

                else if (ship_num == 30)
                {
                    gd30->setIcon(QIcon(path_explosion));
                    gd30->setIconSize(QSize(55,55));
                }

                else if (ship_num == 31)
                {
                    gd31->setIcon(QIcon(path_explosion));
                    gd31->setIconSize(QSize(55,55));
                }

                else if (ship_num == 32)
                {
                    gd32->setIcon(QIcon(path_explosion));
                    gd32->setIconSize(QSize(55,55));
                }

                else if (ship_num == 33)
                {
                    gd33->setIcon(QIcon(path_explosion));
                    gd33->setIconSize(QSize(55,55));
                }
                incorrect++;
        }

    }

    else
    {
        bad10->setIcon(QIcon(":/game1assets/splash.png"));
        bad10->setIconSize(QSize(55,55));
    }

    checkCounters();
    bad10->blockSignals(true);

}
void battleship::showShip11()
{

    unordered_map<string,QString>::const_iterator got = urlmap.find("bad11");
    if (got != urlmap.end())
    {
        if (open_question_tab())
        {
            bad11->setIcon(QIcon(path_explosion));
            bad11->setIconSize(QSize(55,55));
            correct++;

          }

        else{
            QString path = got->second;
            bad11->setIcon(QIcon(path));
            bad11->setIconSize(QSize(55,55));

            rand_nums_good.append(j);

            while (rand_nums_good.contains(j)){
                j = rand() % 6;
            }

            int ship_num = good_ships.at(j);

                if (ship_num == 10)
                {
                    gd10->setIcon(QIcon(path_explosion));
                    gd10->setIconSize(QSize(55,55));
                }

                else if (ship_num == 12)
                {
                    gd12->setIcon(QIcon(path_explosion));
                    gd12->setIconSize(QSize(55,55));
                }

                else if (ship_num == 13)
                {
                    gd13->setIcon(QIcon(path_explosion));
                    gd13->setIconSize(QSize(55,55));
                }

                else if (ship_num == 30)
                {
                    gd30->setIcon(QIcon(path_explosion));
                    gd30->setIconSize(QSize(55,55));
                }

                else if (ship_num == 31)
                {
                    gd31->setIcon(QIcon(path_explosion));
                    gd31->setIconSize(QSize(55,55));
                }

                else if (ship_num == 32)
                {
                    gd32->setIcon(QIcon(path_explosion));
                    gd32->setIconSize(QSize(55,55));
                }

                else if (ship_num == 33)
                {
                    gd33->setIcon(QIcon(path_explosion));
                    gd33->setIconSize(QSize(55,55));
                }
        }
        incorrect++;

    }


    else
    {
        bad11->setIcon(QIcon(":/game1assets/splash.png"));
        bad11->setIconSize(QSize(55,55));
    }
    checkCounters();
    bad11->blockSignals(true);

}
void battleship::showShip12()
{

    unordered_map<string,QString>::const_iterator got = urlmap.find("bad12");
    if (got != urlmap.end())
    {
        if (open_question_tab()){
            bad12->setIcon(QIcon(path_explosion));
            bad12->setIconSize(QSize(55,55));
            correct++;

    }

        else{
            QString path = got->second;
            bad12->setIcon(QIcon(path));
            bad12->setIconSize(QSize(55,55));

            rand_nums_good.append(j);

            while (rand_nums_good.contains(j)){
                j = rand() % 6;
            }

            int ship_num = good_ships.at(j);

                if (ship_num == 10)
                {
                    gd10->setIcon(QIcon(path_explosion));
                    gd10->setIconSize(QSize(55,55));
                }

                else if (ship_num == 12)
                {
                    gd12->setIcon(QIcon(path_explosion));
                    gd12->setIconSize(QSize(55,55));
                }

                else if (ship_num == 13)
                {
                    gd13->setIcon(QIcon(path_explosion));
                    gd13->setIconSize(QSize(55,55));
                }

                else if (ship_num == 30)
                {
                    gd30->setIcon(QIcon(path_explosion));
                    gd30->setIconSize(QSize(55,55));
                }

                else if (ship_num == 31)
                {
                    gd31->setIcon(QIcon(path_explosion));
                    gd31->setIconSize(QSize(55,55));
                }

                else if (ship_num == 32)
                {
                    gd32->setIcon(QIcon(path_explosion));
                    gd32->setIconSize(QSize(55,55));
                }

                else if (ship_num == 33)
                {
                    gd33->setIcon(QIcon(path_explosion));
                    gd33->setIconSize(QSize(55,55));
                }
                incorrect++;
        }

    }

    else
    {
        bad12->setIcon(QIcon(":/game1assets/splash.png"));
        bad12->setIconSize(QSize(55,55));
    }
    checkCounters();
    bad12->blockSignals(true);

}
void battleship::showShip13()
{

    unordered_map<string,QString>::const_iterator got = urlmap.find("bad13");
    if (got != urlmap.end())
    {
        if (open_question_tab()){
            bad13->setIcon(QIcon(path_explosion));
            bad13->setIconSize(QSize(55,55));
            correct++;

    }

        else{
            QString path = got->second;
            bad13->setIcon(QIcon(path));
            bad13->setIconSize(QSize(55,55));

            rand_nums_good.append(j);

            while (rand_nums_good.contains(j)){
                j = rand() % 6;
            }

            int ship_num = good_ships.at(j);

                if (ship_num == 10)
                {
                    gd10->setIcon(QIcon(path_explosion));
                    gd10->setIconSize(QSize(55,55));
                }

                else if (ship_num == 12)
                {
                    gd12->setIcon(QIcon(path_explosion));
                    gd12->setIconSize(QSize(55,55));
                }

                else if (ship_num == 13)
                {
                    gd13->setIcon(QIcon(path_explosion));
                    gd13->setIconSize(QSize(55,55));
                }

                else if (ship_num == 30)
                {
                    gd30->setIcon(QIcon(path_explosion));
                    gd30->setIconSize(QSize(55,55));
                }

                else if (ship_num == 31)
                {
                    gd31->setIcon(QIcon(path_explosion));
                    gd31->setIconSize(QSize(55,55));
                }

                else if (ship_num == 32)
                {
                    gd32->setIcon(QIcon(path_explosion));
                    gd32->setIconSize(QSize(55,55));
                }

                else if (ship_num == 33)
                {
                    gd33->setIcon(QIcon(path_explosion));
                    gd33->setIconSize(QSize(55,55));
                }
                incorrect++;
        }

    }

    else
    {
        bad13->setIcon(QIcon(":/game1assets/splash.png"));
        bad13->setIconSize(QSize(55,55));
    }

    checkCounters();
    bad13->blockSignals(true);

}
void battleship::showShip20()
{

    unordered_map<string,QString>::const_iterator got = urlmap.find("bad20");
    if (got != urlmap.end())
    {
        if (open_question_tab()){
            bad20->setIcon(QIcon(path_explosion));
            bad20->setIconSize(QSize(55,55));
            correct++;

    }

        else{
            QString path = got->second;
            bad20->setIcon(QIcon(path));
            bad20->setIconSize(QSize(55,55));

            rand_nums_good.append(j);

            while (rand_nums_good.contains(j)){
                j = rand() % 6;
            }

            int ship_num = good_ships.at(j);

                if (ship_num == 10)
                {
                    gd10->setIcon(QIcon(path_explosion));
                    gd10->setIconSize(QSize(55,55));
                }

                else if (ship_num == 12)
                {
                    gd12->setIcon(QIcon(path_explosion));
                    gd12->setIconSize(QSize(55,55));
                }

                else if (ship_num == 13)
                {
                    gd13->setIcon(QIcon(path_explosion));
                    gd13->setIconSize(QSize(55,55));
                }

                else if (ship_num == 30)
                {
                    gd30->setIcon(QIcon(path_explosion));
                    gd30->setIconSize(QSize(55,55));
                }

                else if (ship_num == 31)
                {
                    gd31->setIcon(QIcon(path_explosion));
                    gd31->setIconSize(QSize(55,55));
                }

                else if (ship_num == 32)
                {
                    gd32->setIcon(QIcon(path_explosion));
                    gd32->setIconSize(QSize(55,55));
                }

                else if (ship_num == 33)
                {
                    gd33->setIcon(QIcon(path_explosion));
                    gd33->setIconSize(QSize(55,55));
                }
                incorrect++;
        }

    }

    else
    {
        bad20->setIcon(QIcon(":/game1assets/splash.png"));
        bad20->setIconSize(QSize(55,55));
    }
    checkCounters();
    bad20->blockSignals(true);

}
void battleship::showShip21()
{

    unordered_map<string,QString>::const_iterator got = urlmap.find("bad21");
    if (got != urlmap.end())
    {
        if (open_question_tab()){
            bad21->setIcon(QIcon(path_explosion));
            bad21->setIconSize(QSize(55,55));
            correct++;

    }

        else{
            QString path = got->second;
            bad21->setIcon(QIcon(path));
            bad21->setIconSize(QSize(55,55));

            rand_nums_good.append(j);

            while (rand_nums_good.contains(j)){
                j = rand() % 6;
            }

            int ship_num = good_ships.at(j);

                if (ship_num == 10)
                {
                    gd10->setIcon(QIcon(path_explosion));
                    gd10->setIconSize(QSize(55,55));
                }

                else if (ship_num == 12)
                {
                    gd12->setIcon(QIcon(path_explosion));
                    gd12->setIconSize(QSize(55,55));
                }

                else if (ship_num == 13)
                {
                    gd13->setIcon(QIcon(path_explosion));
                    gd13->setIconSize(QSize(55,55));
                }

                else if (ship_num == 30)
                {
                    gd30->setIcon(QIcon(path_explosion));
                    gd30->setIconSize(QSize(55,55));
                }

                else if (ship_num == 31)
                {
                    gd31->setIcon(QIcon(path_explosion));
                    gd31->setIconSize(QSize(55,55));
                }

                else if (ship_num == 32)
                {
                    gd32->setIcon(QIcon(path_explosion));
                    gd32->setIconSize(QSize(55,55));
                }

                else if (ship_num == 33)
                {
                    gd33->setIcon(QIcon(path_explosion));
                    gd33->setIconSize(QSize(55,55));
                }
                incorrect++;
        }

    }

    else
    {
        bad21->setIcon(QIcon(":/game1assets/splash.png"));
        bad21->setIconSize(QSize(55,55));
    }
    checkCounters();
    bad21->blockSignals(true);

}
void battleship::showShip22()
{

    unordered_map<string,QString>::const_iterator got = urlmap.find("bad22");
    if (got != urlmap.end())
    {
        if (open_question_tab()){
            bad22->setIcon(QIcon(path_explosion));
            bad22->setIconSize(QSize(55,55));
            correct++;

    }

        else{
            QString path = got->second;
            bad22->setIcon(QIcon(path));
            bad22->setIconSize(QSize(55,55));

            rand_nums_good.append(j);

            while (rand_nums_good.contains(j)){
                j = rand() % 6;
            }

            int ship_num = good_ships.at(j);

                if (ship_num == 10)
                {
                    gd10->setIcon(QIcon(path_explosion));
                    gd10->setIconSize(QSize(55,55));
                }

                else if (ship_num == 12)
                {
                    gd12->setIcon(QIcon(path_explosion));
                    gd12->setIconSize(QSize(55,55));
                }

                else if (ship_num == 13)
                {
                    gd13->setIcon(QIcon(path_explosion));
                    gd13->setIconSize(QSize(55,55));
                }

                else if (ship_num == 30)
                {
                    gd30->setIcon(QIcon(path_explosion));
                    gd30->setIconSize(QSize(55,55));
                }

                else if (ship_num == 31)
                {
                    gd31->setIcon(QIcon(path_explosion));
                    gd31->setIconSize(QSize(55,55));
                }

                else if (ship_num == 32)
                {
                    gd32->setIcon(QIcon(path_explosion));
                    gd32->setIconSize(QSize(55,55));
                }

                else if (ship_num == 33)
                {
                    gd33->setIcon(QIcon(path_explosion));
                    gd33->setIconSize(QSize(55,55));
                }
                incorrect++;
        }

    }
    else
    {
        bad22->setIcon(QIcon(":/game1assets/splash.png"));
        bad22->setIconSize(QSize(55,55));
    }
    checkCounters();

    bad22->blockSignals(true);

}

void battleship::showShip23()
{

    unordered_map<string,QString>::const_iterator got = urlmap.find("bad23");
    if (got != urlmap.end())
    {
        if (open_question_tab()){
            bad23->setIcon(QIcon(path_explosion));
            bad23->setIconSize(QSize(55,55));
            correct++;

    }

        else{
            QString path = got->second;
            bad23->setIcon(QIcon(path));
            bad23->setIconSize(QSize(55,55));

            rand_nums_good.append(j);

            while (rand_nums_good.contains(j)){
                j = rand() % 6;
            }

            int ship_num = good_ships.at(j);

                if (ship_num == 10)
                {
                    gd10->setIcon(QIcon(path_explosion));
                    gd10->setIconSize(QSize(55,55));
                }

                else if (ship_num == 12)
                {
                    gd12->setIcon(QIcon(path_explosion));
                    gd12->setIconSize(QSize(55,55));
                }

                else if (ship_num == 13)
                {
                    gd13->setIcon(QIcon(path_explosion));
                    gd13->setIconSize(QSize(55,55));
                }

                else if (ship_num == 30)
                {
                    gd30->setIcon(QIcon(path_explosion));
                    gd30->setIconSize(QSize(55,55));
                }

                else if (ship_num == 31)
                {
                    gd31->setIcon(QIcon(path_explosion));
                    gd31->setIconSize(QSize(55,55));
                }

                else if (ship_num == 32)
                {
                    gd32->setIcon(QIcon(path_explosion));
                    gd32->setIconSize(QSize(55,55));
                }

                else if (ship_num == 33)
                {
                    gd33->setIcon(QIcon(path_explosion));
                    gd33->setIconSize(QSize(55,55));
                }
                incorrect++;
        }

    }

    else
    {
        bad23->setIcon(QIcon(":/game1assets/splash.png"));
        bad23->setIconSize(QSize(55,55));
    }
    checkCounters();
    bad23->blockSignals(true);

}

void battleship::showShip30()
{

    unordered_map<string,QString>::const_iterator got = urlmap.find("bad30");
    if (got != urlmap.end())
    {
        if (open_question_tab()){
            bad30->setIcon(QIcon(path_explosion));
            bad30->setIconSize(QSize(55,55));
            correct++;

    }

        else{
            QString path = got->second;
            bad30->setIcon(QIcon(path));
            bad30->setIconSize(QSize(55,55));

            rand_nums_good.append(j);

            while (rand_nums_good.contains(j)){
                j = rand() % 6;
            }

            int ship_num = good_ships.at(j);

                if (ship_num == 10)
                {
                    gd10->setIcon(QIcon(path_explosion));
                    gd10->setIconSize(QSize(55,55));
                }

                else if (ship_num == 12)
                {
                    gd12->setIcon(QIcon(path_explosion));
                    gd12->setIconSize(QSize(55,55));
                }

                else if (ship_num == 13)
                {
                    gd13->setIcon(QIcon(path_explosion));
                    gd13->setIconSize(QSize(55,55));
                }

                else if (ship_num == 30)
                {
                    gd30->setIcon(QIcon(path_explosion));
                    gd30->setIconSize(QSize(55,55));
                }

                else if (ship_num == 31)
                {
                    gd31->setIcon(QIcon(path_explosion));
                    gd31->setIconSize(QSize(55,55));
                }

                else if (ship_num == 32)
                {
                    gd32->setIcon(QIcon(path_explosion));
                    gd32->setIconSize(QSize(55,55));
                }

                else if (ship_num == 33)
                {
                    gd33->setIcon(QIcon(path_explosion));
                    gd33->setIconSize(QSize(55,55));
                }
                incorrect++;
        }

    }

    else
    {
        bad30->setIcon(QIcon(":/game1assets/splash.png"));
        bad30->setIconSize(QSize(55,55));
    }
    checkCounters();
    bad30->blockSignals(true);

}

void battleship::showShip31()
{

    unordered_map<string,QString>::const_iterator got = urlmap.find("bad31");
    if (got != urlmap.end())
    {
        if (open_question_tab()){
            bad31->setIcon(QIcon(path_explosion));
            bad31->setIconSize(QSize(55,55));
            correct++;

    }

        else{
            QString path = got->second;
            bad31->setIcon(QIcon(path));
            bad31->setIconSize(QSize(55,55));

            rand_nums_good.append(j);

            while (rand_nums_good.contains(j)){
                j = rand() % 6;
            }

            int ship_num = good_ships.at(j);

                if (ship_num == 10)
                {
                    gd10->setIcon(QIcon(path_explosion));
                    gd10->setIconSize(QSize(55,55));
                }

                else if (ship_num == 12)
                {
                    gd12->setIcon(QIcon(path_explosion));
                    gd12->setIconSize(QSize(55,55));
                }

                else if (ship_num == 13)
                {
                    gd13->setIcon(QIcon(path_explosion));
                    gd13->setIconSize(QSize(55,55));
                }

                else if (ship_num == 30)
                {
                    gd30->setIcon(QIcon(path_explosion));
                    gd30->setIconSize(QSize(55,55));
                }

                else if (ship_num == 31)
                {
                    gd31->setIcon(QIcon(path_explosion));
                    gd31->setIconSize(QSize(55,55));
                }

                else if (ship_num == 32)
                {
                    gd32->setIcon(QIcon(path_explosion));
                    gd32->setIconSize(QSize(55,55));
                }

                else if (ship_num == 33)
                {
                    gd33->setIcon(QIcon(path_explosion));
                    gd33->setIconSize(QSize(55,55));
                }
                incorrect++;
        }

    }

    else
    {
        bad31->setIcon(QIcon(":/game1assets/splash.png"));
        bad31->setIconSize(QSize(55,55));
    }
    checkCounters();
    bad31->blockSignals(true);

}

void battleship::showShip32()
{

    unordered_map<string,QString>::const_iterator got = urlmap.find("bad32");
    if (got != urlmap.end())
    {
        if (open_question_tab()){
            bad32->setIcon(QIcon(path_explosion));
            bad32->setIconSize(QSize(55,55));
            correct++;

    }

        else{
            QString path = got->second;
            bad32->setIcon(QIcon(path));
            bad32->setIconSize(QSize(55,55));

            rand_nums_good.append(j);

            while (rand_nums_good.contains(j)){
                j = rand() % 6;
            }

            int ship_num = good_ships.at(j);

                if (ship_num == 10)
                {
                    gd10->setIcon(QIcon(path_explosion));
                    gd10->setIconSize(QSize(55,55));
                }

                else if (ship_num == 12)
                {
                    gd12->setIcon(QIcon(path_explosion));
                    gd12->setIconSize(QSize(55,55));
                }

                else if (ship_num == 13)
                {
                    gd13->setIcon(QIcon(path_explosion));
                    gd13->setIconSize(QSize(55,55));
                }

                else if (ship_num == 30)
                {
                    gd30->setIcon(QIcon(path_explosion));
                    gd30->setIconSize(QSize(55,55));
                }

                else if (ship_num == 31)
                {
                    gd31->setIcon(QIcon(path_explosion));
                    gd31->setIconSize(QSize(55,55));
                }

                else if (ship_num == 32)
                {
                    gd32->setIcon(QIcon(path_explosion));
                    gd32->setIconSize(QSize(55,55));
                }

                else if (ship_num == 33)
                {
                    gd33->setIcon(QIcon(path_explosion));
                    gd33->setIconSize(QSize(55,55));
                }
                incorrect++;
        }

    }

    else
    {
        bad32->setIcon(QIcon(":/game1assets/splash.png"));
        bad32->setIconSize(QSize(55,55));
    }
    bad32->blockSignals(true);
    checkCounters();

}

void battleship::showShip33()
{

    unordered_map<string,QString>::const_iterator got = urlmap.find("bad33");
    if (got != urlmap.end())
    {
        if (open_question_tab())
        {
            bad33->setIcon(QIcon(path_explosion));
            bad33->setIconSize(QSize(55,55));

            correct++;
         }

        else{
            QString path = got->second;
            bad33->setIcon(QIcon(path));
            bad33->setIconSize(QSize(55,55));

            rand_nums_good.append(j);

            while (rand_nums_good.contains(j)){
                j = rand() % 6;
            }

            int ship_num = good_ships.at(j);

                if (ship_num == 10)
                {
                    gd10->setIcon(QIcon(path_explosion));
                    gd10->setIconSize(QSize(55,55));
                }

                else if (ship_num == 12)
                {
                    gd12->setIcon(QIcon(path_explosion));
                    gd12->setIconSize(QSize(55,55));
                }

                else if (ship_num == 13)
                {
                    gd13->setIcon(QIcon(path_explosion));
                    gd13->setIconSize(QSize(55,55));
                }

                else if (ship_num == 30)
                {
                    gd30->setIcon(QIcon(path_explosion));
                    gd30->setIconSize(QSize(55,55));
                }

                else if (ship_num == 31)
                {
                    gd31->setIcon(QIcon(path_explosion));
                    gd31->setIconSize(QSize(55,55));
                }

                else if (ship_num == 32)
                {
                    gd32->setIcon(QIcon(path_explosion));
                    gd32->setIconSize(QSize(55,55));
                }

                else if (ship_num == 33)
                {
                    gd33->setIcon(QIcon(path_explosion));
                    gd33->setIconSize(QSize(55,55));
                }
                incorrect++;
        }

    }

    else
    {
        bad33->setIcon(QIcon(":/game1assets/splash.png"));
        bad33->setIconSize(QSize(55,55));
    }

    checkCounters();
    bad33->blockSignals(true);

}

void battleship::checkCounters()
{

    if(correct==7)
    {

        saveScore(this->game_username,correct,incorrect);
        correct = 0;

        rand_nums.clear();
        rand_nums_good.clear();
        this->close();
        qWarning()<<"correct:"<<correct;
        victory_screen* victory = new victory_screen();
        victory->show();
        victory->setFixedSize(400,400);
        //show victory screen
        qWarning()<<"won";



    }
    if(incorrect==4)
    {
        saveScore(this->game_username,correct,incorrect);
        incorrect = 0;
        rand_nums.clear();
        rand_nums_good.clear();
        this->close();
        qWarning()<<"incorrect:"<<correct;
        lose_screen* lose = new lose_screen();
        lose->show();
        lose->setFixedSize(400,400);
        qWarning()<<"lost";

    }
}

void battleship::getUser(QString username)
{

    this->game_username = username;

}
void battleship::saveScore(QString player,int correct,int incorrect)
{
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
            QString firstname = single.value("FirstName").toString();
            QString lastname = single.value("LastName").toString();
            QString dob = single.value("DOB").toString();
            QString gender = single.value("Gender").toString();
            QString image = single.value("Image").toString();
            QString pass = single.value("Password").toString();
            QString num = single.value("PhoneNumber").toString();
            QString username = single.value("Username").toString();



            list.removeAt(i);





            if(correct==7)
            {


                wins++;

            }
            else if(incorrect==4)
            {

                losses++;


            }


            file.close();
            file.open(QIODevice::WriteOnly|QIODevice::Text);
            file.resize(0);


            QJsonObject user;
            user["Username"] = username;
            user["Password"] = pass;
            user["FirstName"] = firstname;
            user["LastName"] = lastname;
            user["Gender"] = gender;
            user["PhoneNumber"] = num;
            user["DOB"] = dob;
            user["G1-Wins"] = wins;
            user["G1-Losses"] = losses;
            user["Image"] = image;

            QJsonObject obj;

            obj[username] = user;
            //QJsonDocument doc(obj);


            list.push_back(obj);
            qWarning()<<list;
            QJsonDocument newdoc( list );

            file.write(newdoc.toJson());
            file.close();


           // qWarning()<<list[0];








        }
      }





}
