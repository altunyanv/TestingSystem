#include "editor.h"
#include "ui_editor.h"

Editor::Editor(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Editor)
{
    ui->setupUi(this);
    ui->plainTextEdit->document()->setDocumentMargin(0);
    ui->plainTextEdit_2->document()->setDocumentMargin(0);
    hgh = new Highlighter(ui->plainTextEdit_2->document());
    hgh->setRulesFromXML(":/data/python.xml");
}

Editor::~Editor()
{
    delete ui;
}

void Editor::prepare(int problemID, int userID) {
    problemId = problemID;
    userId = userID;
    ui->plainTextEdit_2->clear();
}

void Editor::update_width(int highest) {
    int len = 0;
    while(highest) {
        highest /= 10;
        len++;
    }

    ui->plainTextEdit->setMinimumSize(QSize(17 + 8 * len, 511));
    QSize sz = ui->plainTextEdit->sizeHint();
    ui->plainTextEdit->setGeometry(10, 10, 17 + 8 * len, sz.height());

    ui->plainTextEdit_2->setMinimumSize(QSize(791 - 17 - 8 * len, 511));
    sz = ui->plainTextEdit_2->sizeHint();
    ui->plainTextEdit_2->setGeometry(27 + 8 * len, 10, sz.width(), sz.height());
}

void Editor::on_plainTextEdit_2_updateRequest(const QRect &rect, int dy)
{
    int highest = 1;
    ui->plainTextEdit->clear();
    QTextBlock current = ui->plainTextEdit_2->firstVisible();
    while(current.isValid() && ui->plainTextEdit_2->firstVisible().blockNumber() + 28 > highest) {
        ui->plainTextEdit->appendPlainText(QString(" %1 ").arg(current.blockNumber() + 1));
        highest = current.blockNumber() + 1;
        current = current.next();
    }
    update_width(highest);
}

void Editor::on_back_to_problem_clicked()
{
    emit goToProblem(problemId);
}

void Editor::on_submit_solution_clicked()
{
    int submissionID;
    try {
        OPEN_CONN
        QSqlQuery sq;
        sq.prepare("INSERT INTO History(UserID, ProblemID, UnixTime, SourceCode) \ VALUES((:UID), (:PID), (:UT), (:SRC))");
        sq.bindValue(":UID", userId);
        sq.bindValue(":PID", problemId);
        sq.bindValue(":UT", (QDateTime::currentDateTime()).toTime_t());
        sq.bindValue(":SRC", ui->plainTextEdit_2->toPlainText());
        sq.exec();

        sq.exec("SELECT MAX(SubmissionID) \ FROM History"); sq.next();
        submissionID = sq.value(0).toInt();
    }
    catch(std::exception) {
        qDebug("Ստոպ բեյբի էս ինչ ես անում!");
    }
    CLOSE_CONN

    Python::set_source(ui->plainTextEdit_2->toPlainText());
    bool compilation = Python::compile();
    int status = -1;
    if (compilation) {
        try {
            OPEN_CONN
            Python::create_source();
            QSqlQuery sq;
            sq.exec(QString("SELECT * \ FROM Testcases \ WHERE ProblemID = %1").arg(problemId));

            bool passed = true;
            while(sq.next()) {
                if (!Python::run_on_test(sq.value("StdIn").toString(), sq.value("StdOut").toString())) {
                    passed = false;
                    break;
                }
            }
            Python::remove_source();

            if (passed) {
                QMessageBox::information(this, "Հաջողություն․․․", "Ձեր լուծումը թեստավորված է։ Բոլոր արդյունքները ճիշտ էին։", QMessageBox::Ok);
                status = 1;
            }
            else {
                QMessageBox::information(this, "Մոտ էր․․․", "Ձեր լուծումը թեստավորված է։ Ոչ բոլոր արդյունքներն էին ճիշտ։", QMessageBox::Ok);
                status = 0;
            }
        }
        catch(std::exception) {
            qDebug("Ստոպ բեյբի էս ինչ ես անում!");
        }
        CLOSE_CONN
    }
    else {
        QMessageBox::information(this, "Կոմպիլյացիա․․․", "Կոդում կան սխալներ, ուղղեք խնդրում եմ․", QMessageBox::Ok);
        status = -1;
    }

    try {
        OPEN_CONN
        QSqlQuery sq;
        sq.exec(QString("UPDATE History \ SET Status = %1 \ WHERE SubmissionID = %2").arg(status).arg(submissionID));
    }
    catch(std::exception) {
        qDebug("Ստոպ բեյբի էս ինչ ես անում!");
    }
    CLOSE_CONN
}
