#ifndef PROBLEM_H
#define PROBLEM_H

#include <QWidget>
#include "dbconnection.h"

namespace Ui {
class Problem;
}

class Problem : public QWidget
{
    Q_OBJECT

public:
    explicit Problem(QWidget *parent = 0);
    ~Problem();
    void setProblemID(int problemID);

signals:
    void goToSolve(int);
    void goToProblems();

private slots:
    void on_solve_problem_clicked();

    void on_problem_set_clicked();

private:
    Ui::Problem *ui;
    int problemId;
};

#endif // PROBLEM_H
