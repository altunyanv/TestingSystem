#include "problemset.h"
#include "ui_problemset.h"

ProblemSet::ProblemSet(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ProblemSet)
{
    ui->setupUi(this);
    ui->scrollAreaWidgetContents->setStyleSheet("QWidget {background-color: white}");
}

ProblemSet::~ProblemSet()
{
    delete ui;
}

void ProblemSet::setUser(int id)
{
    if (id != -1) {
        userId = id;
        loadProblemSet();
    }
    updateContent();
}

void ProblemSet::loadProblemSet() {
    IndexLabel * problemId, * problemName;
    int row = 0;
    try {
        OPEN_CONN
        QSqlQuery sq;
        sq.exec("SELECT ProblemID, Name \ FROM Problems");
        while(sq.next()) {
            problemId = new IndexLabel(sq.value(0).toString(), ui->scrollAreaWidgetContents);     problemId->setGeometry(0, row * 30, 40, 30);       problemId->setFont(QFont("Consolas", 12, -1, true));
            problemName = new IndexLabel(sq.value(1).toString(), ui->scrollAreaWidgetContents);   problemName->setGeometry(40, row * 30, 170, 30);    problemName->setFont(QFont("Consolas", 12));
            connect(problemId, SIGNAL(clicked(int)), this, SLOT(onProblemIdClick(int)));
            row++;
        }

        ui->scrollArea->setGeometry(QRect(20, 80, 230, row * 31 < 470 ? row * 31 : 470));

    }
    catch(std::exception) {
        qDebug("Ստոպ բեյբի էս ինչ ես անում!");
    }
    CLOSE_CONN
}

void ProblemSet::updateContent()
{
    try {
        OPEN_CONN
        QSqlQueryModel * sqm = new QSqlQueryModel(ui->submission_history);

        sqm->setQuery(QString("SELECT SubmissionID, UserID, ProblemID, UnixTime AS DateTime, Status \ FROM History \ WHERE UserID = %1 \ ORDER BY UnixTime").arg(userId));
        ui->submission_history->setModel(sqm);
        ui->submission_history->setItemDelegateForColumn(3, new DateTimeDelegate(ui->submission_history));
        ui->submission_history->setItemDelegateForColumn(4, new StatusDelegate(ui->submission_history));
        ui->submission_history->resizeColumnsToContents();
    }
    catch(std::exception) {
        qDebug("Ստոպ բեյբի էս ինչ ես անում!");
    }
    CLOSE_CONN
}

void ProblemSet::onProblemIdClick(int problemId)
{
    emit openProblem(problemId);
}

void ProblemSet::on_pushButton_3_clicked()
{
    emit logOut();
}
