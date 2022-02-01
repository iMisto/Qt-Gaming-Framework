#include <QApplication>
#include "mainpanel.h"
#include "game2.h"
#include <QDesktopWidget>
int main(int argc, char **argv)
{
QApplication app (argc, argv);
mainpanel *m1 = new mainpanel();

m1->adjustSize();
//m1->setWindowTitle("Main Page");
//m1->move(QApplication::desktop()->screen()->rect().center() - m1->rect().center());
m1->show();
return app.exec();

}
