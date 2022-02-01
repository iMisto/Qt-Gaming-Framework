/**
*\file mainpanel.h
*\brief mainpanel header class
*
* first interface
*/
#ifndef MAINPANEL_H
#define MAINPANEL_H

#include <QObject>
#include <QWidget>
#include <QtWidgets>
class mainpanel : public QWidget
{
    Q_OBJECT
public:
    explicit mainpanel(QWidget *parent = nullptr);


signals:
private:
    QGridLayout *panel; //!<main panel
    QPushButton *signup; //!<button for signup
    QPushButton *signin;//!<button for sign in
    QPushButton *playguest;//!<button to play as guest
private slots:
/*! \brief Function that opens login panel
*
*
*/
void openLoginPanel();
/*! \brief Function that opens signup panel
*
*
*/
void openSignupPanel();
/*! \brief Function that opens guest panel
*
*
*/
void playAsGuest();

};

#endif // MAINPANEL_H
