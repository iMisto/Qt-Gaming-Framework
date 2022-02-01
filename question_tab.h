#ifndef QUESTION_TAB_H
#define QUESTION_TAB_H

#include <QObject>
#include <QWidget>
#include <QtWidgets>

class question_tab : public QWidget
{
    Q_OBJECT
public:
    explicit question_tab(QWidget *parent = nullptr);


signals:
private:
   //QGridLayout* grid;
    //QLabel* question;

    //QRadioButton* answer_1;
    //QRadioButton* answer_2;
    //QRadioButton* answer_3;
    //QGroupBox* answer_group;
    //QVBoxLayout* answer_radio;

    //QPushButton* submit;

//public slots:

    //void submitAnswer();
};

#endif // QUESTION_TAB_H
