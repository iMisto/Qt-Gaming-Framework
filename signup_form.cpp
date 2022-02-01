
/**
*\file signup_form.cpp
*\brief signup_form
*
* interface for registering new users
*/
#include "signup_form.h"
#include "mainpanel.h"
#include <iostream>
using namespace std;

static QString filename; //!<save name of file

signup_form::signup_form(QWidget *parent) : QWidget(parent)
{

    signup_back_button = new QPushButton("Back to main page");
    username = new QLabel("Username");
    username_txt = new QLineEdit();

    password = new QLabel("Password");
    password_txt = new QLineEdit();

    firstName = new QLabel("First Name");
    firstName_txt = new QLineEdit();

    lastName = new QLabel("Last Name");
    lastName_txt = new QLineEdit();

    date_of_birth = new QLabel("Date of Birth");
    date_of_birth_txt = new QDateEdit();

    gender = new QLabel("Gender");
    gender_Choice1 = new QRadioButton("Male");
    gender_Choice2 = new QRadioButton("Female");
    gender_Group = new QGroupBox();
    gridRadio = new QVBoxLayout();

    phone_num = new QLabel("Phone Number");
    phone_num_txt = new QLineEdit();

    signup_button = new QPushButton("Sign up");

    grid = new QGridLayout();
    box = new QVBoxLayout();

    text = new QTextEdit();

    choose_image_button = new QPushButton("Choose an image");
    display_image = new QLabel();




    grid->addWidget(username,0,0);
    grid->addWidget(username_txt,0,1);

    grid->addWidget(password,1,0);
    grid->addWidget(password_txt,1,1);

    grid->addWidget(firstName,2,0);
    grid->addWidget(firstName_txt,2,1);

    grid->addWidget(lastName,3,0);
    grid->addWidget(lastName_txt,3,1);

    grid->addWidget(date_of_birth,4,0);
    grid->addWidget(date_of_birth_txt,4,1);

    gridRadio->addWidget(gender_Choice1);
    gridRadio->addWidget(gender_Choice2);
    gender_Group->setLayout(gridRadio);
    grid->addWidget(gender,5,0);
    grid->addWidget(gender_Group,5,1);

    grid->addWidget(phone_num,6,0);
    grid->addWidget(phone_num_txt,6,1);

    grid->addWidget(choose_image_button,7,0,1,2);


    box->addLayout(grid);
    box->addWidget(signup_button);
    box->addWidget(text);
    box -> addWidget(signup_back_button);

    this->setFixedSize(750,750);

    this->adjustSize();
    this->move(QApplication::desktop()->screen()->rect().center() - this->rect().center());
    this->setWindowTitle("Signup Page");
    setLayout(box);

    QObject::connect(signup_button,SIGNAL(clicked()),this,SLOT(check_pass_num_empty()));
    QObject::connect(signup_back_button,SIGNAL(clicked()),this,SLOT(back_from_signup()));
    QObject::connect(choose_image_button,SIGNAL(clicked()),this,SLOT(select_display_image()));


}

// function needs to check that the password is at least 8 characters
// and if it contains at least one number in addition to upper and lower
// case letters

void signup_form::back_from_signup()
{
    this->close();
    mainpanel *main_panel_back = new mainpanel();
    main_panel_back->show();
}

void signup_form::check_pass_num_empty()
{

    QString pass = password_txt->text();
    QString phone_num = phone_num_txt->text();
    // Regular Expression to check password requirements
    // ?=.*[a-z] checks if at least one lower case character is present
    // ?=.*[A-Z] checks if at least one upper case character is present
    // ?=.*\\d checks if at least one numerical value is present
    // . represents any character excluding line break
    // + represents one or more

    const QRegExp pattern("^(?=.*[a-z])(?=.*[A-Z])(?=.*\\d).+$");
    bool isCorrect = true;
    if(phone_num[0] != '+' || phone_num[4] != '-')
    {
        text->setText("Phone number should be in proper format: +XXX-XXXXXXXX");
        isCorrect = false;
    }

    if (pass.length() <8 || pattern.indexIn(pass))
    {
        text->setText("Your password should be at least 8 characters long, and must contain at least one number, one uppercase letter, and one lowercase letter!");
        isCorrect = false;
    }


    QString in_user = username_txt->text();
    QString in_password = password_txt->text();
    QString in_firstname = firstName_txt->text();
    QString in_lastname = lastName_txt->text();
    QString in_gender;
    if(gender_Choice1->isChecked())
    {
        in_gender = "Male";
    }
    else
    {
        in_gender = "Female";
    }
    QString in_phonenumber = phone_num_txt->text();
    QString in_dob = date_of_birth_txt->text();

    if (in_user.isEmpty() || in_password.isEmpty() || in_firstname.isEmpty() || in_lastname.isEmpty() || in_gender.isEmpty() || filename.isEmpty() || in_phonenumber.isEmpty() || in_dob.isEmpty())
    {
        text->setText("Please fill all required information");
        isCorrect = false;
    }

    if(isUnique(in_user)!=true)
        {
            text->setText("Username not unique!");
            isCorrect=false;

        }

    if(isCorrect)
    {

        insertUser(in_user,in_password,in_firstname,in_lastname,in_gender,in_phonenumber,in_dob);
        text->setText("Username created successfully");
    }



}


void signup_form::select_display_image()
{

    filename = QFileDialog::getOpenFileName(this,tr("Choose"),"",tr("Images (*.png *.jpg *.jpeg *.bmp)"));
    if (QString::compare(filename,QString()) != 0)
    {
        QImage image;
        bool isValid = image.load(filename);

        if (isValid)
        {
            grid->addWidget(display_image, 8,0,4,2);
            display_image->setPixmap(QPixmap::fromImage(image).scaled(300,300));

        }
    }
}

void signup_form::insertUser(QString in_user,QString in_password,QString in_firstname,QString in_lastname,QString in_gender,QString in_phonenumber,QString in_dob)
{

    QFile file("/home/eece435l/435-project-group7/database.json");
    file.open(QIODevice::ReadOnly|QIODevice::Text);
    QJsonDocument docAll = QJsonDocument::fromJson( file.readAll() );
    file.close();
    file.open(QIODevice::WriteOnly|QIODevice::Text);

    QJsonObject user;
    user["Username"] = in_user;
    user["Password"] = in_password;
    user["FirstName"] = in_firstname;
    user["LastName"] = in_lastname;
    user["Gender"] = in_gender;
    user["PhoneNumber"] = in_phonenumber;
    user["DOB"] = in_dob;
    user["G1-Wins"] = 0;
    user["G1-Losses"] = 0;
    user["Image"] = filename;

    QJsonObject obj;

    obj[in_user] = user;
    //QJsonDocument doc(obj);

    QJsonArray arrLog = docAll.array();
    arrLog.push_back(obj);
    QJsonDocument newdoc( arrLog );

    file.write(newdoc.toJson());
    file.close();


}

bool signup_form::isUnique(QString curr_name)
{


    QFile file("/home/eece435l/435-project-group7/database.json");
    file.open(QIODevice::ReadOnly|QIODevice::Text);
    QJsonDocument content = QJsonDocument::fromJson( file.readAll() );
    QJsonArray list = content.array();
    QJsonObject item;
    bool contains;
    for(int i=0;i<list.size();i++)
    {
        item = list[i].toObject();
        contains = item.contains(curr_name);
        if(contains)
        {
            return false;
        }
    }

    return true;


}

