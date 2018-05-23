#include "dbconnection.h"
#include "login.h"
#include "hope.h"
#include <QApplication>
#include <QFile>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SETUP_CONN

    Hope huys;
    huys.show();

    return a.exec();
}
