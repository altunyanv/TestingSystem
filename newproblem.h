#ifndef NEWPROBLEM_H
#define NEWPROBLEM_H

#include <QWidget>
#include <QMap>
#include <QVariant>
#include "dbconnection.h"

namespace Ui {
class NewProblem;
}

class NewProblem : public QWidget
{
    Q_OBJECT

public:
    explicit NewProblem(QWidget *parent = 0);
    ~NewProblem();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();

private:
    Ui::NewProblem *ui;
    int addProblem();
    void reset_fields();

signals:
    void logOut();
};

#endif // NEWPROBLEM_H
