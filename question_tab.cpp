#include "question_tab.h"
#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include <string>
#include <iostream>
#include <QList>
#include "battleship.h"

//int i = 0;
//static QList<int> rand_nums = QList<int>();


question_tab::question_tab(QWidget *parent) : QWidget(parent)
{
    // store rand_nums in a list so that questions aren't repeated

    /*rand_nums.append(0);

    grid = new QGridLayout();
    srand(time(0));

    while (rand_nums.contains(i))
    {
        i = rand()%16 + 1;
    }

    rand_nums.append(i);

    qWarning() << i << endl;
    QFile file("/home/eece435l/435-project-group7/questions_answers.json");
    file.open(QIODevice::ReadOnly|QIODevice::Text);
    QJsonDocument content = QJsonDocument::fromJson( file.readAll() );

    QString rand_question = "Quest_" + QString::number(i);
    qWarning() << rand_question << endl;

    QJsonValue quest = content.object().value(rand_question);
    QString quest_txt = quest.toString();
    QString ans1 = content.object().value("Ans_" + QString::number(i) + "1").toString();
    QString ans2 = content.object().value("Ans_" + QString::number(i) + "2").toString();
    QString ans3 = content.object().value("Ans_" + QString::number(i) + "3").toString();

    question = new QLabel(quest_txt);

    qWarning() << quest_txt << " " << ans1 << " " << ans2 << " " << ans3;


    grid->addWidget(question,0,0);


    answer_1 = new QRadioButton(ans1);
    answer_2 = new QRadioButton(ans2);
    answer_3 = new QRadioButton(ans3);
    answer_group = new QGroupBox();
    answer_radio = new QVBoxLayout();
    submit = new QPushButton("Submit");

    answer_radio->addWidget(answer_1,0,0);
    answer_radio->addWidget(answer_2,1,0);
    answer_radio->addWidget(answer_3,2,0);
    answer_group->setLayout(answer_radio);
    grid->addWidget(answer_group,1,0);
    grid->addWidget(submit, 2,0);
    setLayout(grid);



    this->setFixedSize(500,500);

    QObject::connect(submit,SIGNAL(clicked()),this,SLOT(submitAnswer()));*/

}

/*void question_tab::submitAnswer()
{
    QFile file2("/home/eece435l/435-project-group7/correct_answers.json");
    file2.open(QIODevice::ReadOnly|QIODevice::Text);
    QJsonDocument content_correct = QJsonDocument::fromJson( file2.readAll() );

    QString correct = content_correct.object().value("C" + QString::number(i)).toString();

    qWarning() << "Correct is : " << correct << endl;

    if (answer_1->isChecked() && answer_1->text() == correct)
    {

        this->close();
    }

    else if (answer_2->isChecked() && answer_2->text() == correct)
    {
        this->close();
    }

    else if (answer_3->isChecked() && answer_3->text() == correct)
    {
        this->close();
    }
}*/
