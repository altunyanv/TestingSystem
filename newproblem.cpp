#include "newproblem.h"
#include "ui_newproblem.h"

NewProblem::NewProblem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NewProblem)
{
    ui->setupUi(this);
    OPEN_CONN
    try {
        QSqlQuery sq;
        if (DBConnection::DB.tables().contains("tmp_tests")) {
            sq.exec("drop table tmp_tests;");
        }
        sq.exec("create table tmp_tests(ID INTEGER PRIMARY KEY, Input TEXT, Output TEXT);");
        QSqlQueryModel * sqm = new QSqlQueryModel(ui->tableView);
        sqm->setQuery("select * from tmp_tests;");
        ui->tableView->setModel(sqm);
    }
    catch(std::exception) {
        qDebug("Ստոպ բեյբի էս ինչ ես անում!");
    }
    CLOSE_CONN
}

NewProblem::~NewProblem()
{
    delete ui;
}

void NewProblem::on_pushButton_clicked()
{
    try {
        OPEN_CONN
        QSqlQuery sq;
        sq.exec(QString("insert into tmp_tests(Input, Output) \ values('%1', '%2')")
                .arg(ui->test_input->toPlainText())
                .arg(ui->test_output->toPlainText()));
        QSqlQueryModel * sqm = new QSqlQueryModel(ui->tableView);
        sqm->setQuery("select * from tmp_tests;");
        ui->tableView->setModel(sqm);
        ui->tableView->resizeRowsToContents();
        ui->test_input->clear();
        ui->test_output->clear();
    }
    catch(std::exception) {
        qDebug("Ստոպ բեյբի էս ինչ ես անում!");
    }
    CLOSE_CONN
}

void NewProblem::on_pushButton_2_clicked()
{
    try {
        OPEN_CONN
        QSqlQuery sq;
        QMap<QString, QString> test_data;
        sq.exec("select * from tmp_tests;");
        while(sq.next()) {
            test_data.insert(sq.value("Input").toString(), sq.value("Output").toString());
        }
        int problem_id = addProblem();
        if (problem_id != -1) {
            OPEN_CONN
            foreach (QString key, test_data.keys()) {
                sq.exec(QString("INSERT INTO Testcases(ProblemID, StdIn, StdOut) \ VALUES(%1, '%2', '%3')")
                        .arg(problem_id)
                        .arg(key)
                        .arg(test_data.value(key)));
            }
            CLOSE_CONN
        }
        reset_fields();
    }
    catch(std::exception) {
        qDebug("Ստոպ բեյբի էս ինչ ես անում!");
    }
    CLOSE_CONN
}

int NewProblem::addProblem() {
    int problem_id = -1;
    try {
        OPEN_CONN
        QSqlQuery sq;
        sq.exec(QString("INSERT INTO Problems(Name, Description, InputFormat, OutputFormat, SampleIn, SampleOut) \ VALUES('%1', '%2', '%3', '%4', '%5', '%6');")
                .arg(ui->problem_title->toPlainText())
                .arg(ui->problem_statement->toPlainText())
                .arg(ui->problem_input->toPlainText())
                .arg(ui->problem_output->toPlainText())
                .arg(ui->sample_input->toPlainText())
                .arg(ui->sample_output->toPlainText()));
        sq.exec("SELECT MAX(ProblemID) FROM Problems;");
        if (sq.next()) {
            problem_id = sq.value(0).toInt();
        }
    }
    catch(std::exception) {
        qDebug("Ստոպ բեյբի էս ինչ ես անում!");
    }
    CLOSE_CONN
            return problem_id;
}

void NewProblem::reset_fields()
{
    ui->problem_input->clear();
    ui->problem_output->clear();
    ui->problem_statement->clear();
    ui->problem_title->clear();
    ui->sample_input->clear();
    ui->sample_output->clear();
    OPEN_CONN
    QSqlQuery sq;
    sq.exec("delete from tmp_tests;");
    QSqlQueryModel * sqm = new QSqlQueryModel(ui->tableView);
    sqm->setQuery("select * from tmp_tests;");
    ui->tableView->setModel(sqm);
    CLOSE_CONN
}

void NewProblem::on_pushButton_3_clicked()
{
    emit logOut();
}
