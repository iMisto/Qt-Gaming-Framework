/**
*\file loginpanel.h
*\brief loginpanel header class
*
* for users to log in
*/
#ifndef LOGINPANEL_H
#define LOGINPANEL_H

#include <QObject>
#include <QWidget>
#include <QtWidgets>
#include <QJsonObject>
#include "welcome_screen.h"
class loginPanel : public QWidget
{
    Q_OBJECT
public:
    explicit loginPanel(QWidget *parent = nullptr);

signals:
private:
    QGridLayout *login_panel; //!<main layout
    QLabel *username_label;//!<label for username
    QLabel *password_label;//!<label for pass
    QLineEdit *username_text;//!<text for username
    QLineEdit *password_text;//!<text for pass
    QPushButton *back_from_login;//!<button to go back
    QPushButton *login;//!<button to submit login


private slots:

/*! \brief Function that goes back to previous panel
*/
void backfrom_login();
/*! \brief Function that goes to welcome screen
*/
void to_welcome_screen();
/*! \brief Function that fetches password of user
* \param Username
*/
void getPassword(QString User);

};

#endif // LOGINPANEL_H
