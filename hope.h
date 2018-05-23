#ifndef HOPE_H
#define HOPE_H

#include <QStackedWidget>
#include <QtSql>
#include <QXmlStreamReader>
#include <QIODevice>
#include <QFile>
#include <QWidget>
#include <QByteArray>
#include <QCryptographicHash>
#include <QString>
#include <ctime>
#include "registration.h"
#include "login.h"
#include "dbconnection.h"
#include "problem.h"
#include "editor.h"
#include "problemset.h"
#include "newproblem.h"

namespace Ui {
class Hope;
}

class Hope : public QStackedWidget
{
    Q_OBJECT

public:
    explicit Hope(QWidget *parent = 0);
    ~Hope();

private:
    Ui::Hope *ui;
    Registration * rg;
    Login * lg;
    Problem * prob;
    Editor * ed;
    ProblemSet * ps;
    NewProblem * np;
    int currentUserID;

private slots:
    void openEditor(int);
    void openProblem(int);
    void openProblemSet();
    void openLogin();
    void openRegistration();
    void onLogin(int);
    void onLogout();

signals:
    void goBack();
};

#endif // HOPE_H
