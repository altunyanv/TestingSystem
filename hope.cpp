#include "hope.h"
#include "ui_hope.h"

Hope::Hope(QWidget *parent) :
    QStackedWidget(parent),
    ui(new Ui::Hope)
{
    ui->setupUi(this);
    this->setStyleSheet("QStackedWidget {background-color: white}");
    prob = new Problem(parent);
    ed = new Editor(parent);
    ps = new ProblemSet(parent);
    lg = new Login(parent);
    rg = new Registration(parent);
    np = new NewProblem(parent);

    this->addWidget(lg);
    connect(ed, SIGNAL(goToProblem(int)), this, SLOT(openProblem(int)));
    connect(prob, SIGNAL(goToSolve(int)), this, SLOT(openEditor(int)));
    connect(ps, SIGNAL(openProblem(int)), this, SLOT(openProblem(int)));
    connect(prob, SIGNAL(goToProblems()), this, SLOT(openProblemSet()));

    connect(lg, SIGNAL(clickRegister()), this, SLOT(openRegistration()));
    connect(rg, SIGNAL(clickLogin()), this, SLOT(openLogin()));
    connect(lg, SIGNAL(clickLogin(int)), this, SLOT(onLogin(int)));
    connect(np, SIGNAL(logOut()), this, SLOT(onLogout()));
    connect(ps, SIGNAL(logOut()), this, SLOT(onLogout()));
}

Hope::~Hope()
{
    delete ui;
}

void Hope::openEditor(int probId)
{
    ed->prepare(probId, currentUserID);
    this->removeWidget((QWidget *)(QObject::sender()));
    this->addWidget(ed);
}

void Hope::openProblem(int probId)
{
    prob->setProblemID(probId);
    this->removeWidget((QWidget *)(QObject::sender()));
    this->addWidget(prob);
}

void Hope::openProblemSet()
{
    this->removeWidget((QWidget *)(QObject::sender()));
    ps->setUser();
    this->addWidget(ps);
}

void Hope::openLogin()
{
    this->removeWidget((QWidget *)(QObject::sender()));
    this->addWidget(lg);
}

void Hope::openRegistration()
{
    this->removeWidget((QWidget *)(QObject::sender()));
    this->addWidget(rg);
}

void Hope::onLogin(int userId)
{
    this->removeWidget((QWidget *)(QObject::sender()));
    if (userId) {
        ps->setUser(userId);
        currentUserID = userId;
        this->addWidget(ps);
    }
    else
        this->addWidget(np);
}

void Hope::onLogout()
{
    this->removeWidget((QWidget *)(QObject::sender()));
    this->addWidget(lg);
}


