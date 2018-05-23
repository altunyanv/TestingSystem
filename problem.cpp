#include "problem.h"
#include "ui_problem.h"

Problem::Problem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Problem)
{
    problemId = 0;
    ui->setupUi(this);
    //this->setStyleSheet("QWidget {background-color: white}");
    ui->problem_statement->viewport()->setAutoFillBackground(false);
    ui->problem_statement->setStyleSheet(":disabled {background-color: white transparent; color: black}");
    ui->problem_input->viewport()->setAutoFillBackground(false);
    ui->problem_input->setStyleSheet(":disabled {background-color: white transparent; color: black}");
    ui->problem_output->viewport()->setAutoFillBackground(false);
    ui->problem_output->setStyleSheet(":disabled {background-color: white transparent; color: black}");
    ui->problem_title->viewport()->setAutoFillBackground(false);
    ui->problem_title->setStyleSheet(":disabled {background-color: white transparent; color: black; text-align: center}");
    ui->sample_input->viewport()->setAutoFillBackground(false);
    ui->sample_input->setStyleSheet(":disabled {background-color: white transparent; color: black; text-align: center}");
    ui->sample_output->viewport()->setAutoFillBackground(false);
    ui->sample_output->setStyleSheet(":disabled {background-color: white transparent; color: black; text-align: center}");
}

Problem::~Problem()
{
    delete ui;
}

void Problem::setProblemID(int problemID) {
    if (problemID == problemId) return;

    problemId = problemID;
    try {
        OPEN_CONN
        QSqlQuery sq;
        sq.exec(QString("SELECT * \ FROM Problems \ WHERE ProblemID = %1").arg(problemId));

        sq.next();
        ui->problem_title->clear();     ui->problem_title->appendPlainText(sq.value("Name").toString());
        ui->problem_statement->clear(); ui->problem_statement->appendPlainText(sq.value("Description").toString());
        ui->problem_input->clear();     ui->problem_input->appendPlainText(sq.value("InputFormat").toString());
        ui->problem_output->clear();    ui->problem_output->appendPlainText(sq.value("OutputFormat").toString());
        ui->sample_input->clear();      ui->sample_input->appendPlainText(sq.value("SampleIn").toString());
        ui->sample_output->clear();     ui->sample_output->appendPlainText(sq.value("SampleOut").toString());
    }
    catch(std::exception) {
        qDebug("Ստոպ բեյբի էս ինչ ես անում!");
    }
    CLOSE_CONN
}

void Problem::on_solve_problem_clicked()
{
    emit goToSolve(problemId);
}

void Problem::on_problem_set_clicked()
{
    emit goToProblems();
}
