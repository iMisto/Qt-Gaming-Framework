/**
*\file historypanel.h
*\brief user game history
*
*
*/
#ifndef HISTORYPANEL_H
#define HISTORYPANEL_H

#include <QObject>
#include <QWidget>
#include <QtWidgets>
#include <QJsonObject>
class historypanel : public QWidget
{
    Q_OBJECT
public:
    explicit historypanel(QWidget *parent = nullptr);
    void getHistory(QString);

signals:
private:
    QString his_user;//!<name of user we are checking the history for
    QString wins;//!<user's num of wins
    QString losses;//!<user's num of losses
    QLabel* win_label;//!< for displaying win count
    QLabel* loss_label;//!<for displaying loss count

    QGridLayout *history_panel; //!<layout

public slots:
/*!\brief function to go back to previous panel
*/
    void back();
};

#endif // HISTORYPANEL_H
