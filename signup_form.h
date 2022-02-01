
/**
*\file signup_form.h
*\brief for registering new users
*
*
*/
#ifndef SIGNUP_FORM_H
#define SIGNUP_FORM_H

#include <QObject>
#include <QWidget>
#include <QtWidgets>
#include <QDateEdit>
#include <QFileDialog>

class signup_form : public QWidget
{
    Q_OBJECT
public:
    explicit signup_form(QWidget *parent = nullptr);

signals:

private:


    QJsonObject j_content; //!< for storing user data
    QLabel *username; //!<username label
    QLineEdit *username_txt;//!<username editable text box

    QLabel *password; //!<pass label
    QLineEdit *password_txt;//!<pass textbox

    QLabel *firstName;//!<firstname label
    QLineEdit *firstName_txt;//!<firstname text box

    QLabel *lastName;//!<lastname label
    QLineEdit *lastName_txt;//!<lastname textbox

    QLabel *date_of_birth;//!<dob label
    QDateEdit *date_of_birth_txt;//!<dob text box

    QLabel *gender;//!<gender label
    QRadioButton *gender_Choice1;//!<radio button for male
    QRadioButton *gender_Choice2;//!<radio button for female
    QGroupBox *gender_Group;//!<box to group both choices
    QVBoxLayout *gridRadio;//!<small grid for radio buttons

    QLabel *phone_num;//!<phone num label
    QLineEdit *phone_num_txt;//!<phone num text box

    QPushButton *signup_button;//!<signup button
    QPushButton *signup_back_button;//!<takes you back to main panel
    QGridLayout *grid;//!<grid to store widgets
    QVBoxLayout *box;//!<secondary box to store widgets

    // profile picture to be done ??

    // To test the functions that check the password and phone number format
    QTextEdit *text;//!<feedback text

    QPushButton *choose_image_button;//!<button to choose image
    QLabel *display_image;//!<label that displays selected image

    void insertUser(QString in_user,QString in_password,QString in_firstname,QString in_lastname,QString in_gender,QString in_phonenumber,QString in_dob);

public slots:

    // check that password and phone number meet the requirements
/*! \brief Function that checks if pass and phone number meet requirements
*
*
*/
void check_pass_num_empty();
/*! \brief Function that takes user back to main panel
*
*
*/
void back_from_signup();
/*! \brief Function that displays image selection
*
*
*/

void select_display_image();
/*! \brief Function that checks if username is unique
*
*
*/
static bool isUnique(QString curr_name);

};

#endif // SIGNUP_FORM_H

