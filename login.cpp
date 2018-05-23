#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    connect(ui->password_show, SIGNAL(onShow(bool)), this, SLOT(show_password(bool)));
    ui->password_edit->setEchoMode(QLineEdit::Password);
}

Login::~Login()
{
    delete ui;
}

bool Login::checkIfAdmin(const QString &login, const QString &password) {
    QFile * xmlFile = new QFile(":/data/appconfig.xml");
    if (!xmlFile->open(QIODevice::ReadOnly)) {
        qDebug("Ստոպ բեյբի էս ինչ ես անում!");
    }

    bool ll = false, pp = false;

    QXmlStreamReader * rdr = new QXmlStreamReader(xmlFile);
    while(rdr->name().toString() != QString("Configuration") || !rdr->isEndElement()) {
        QString tmp = rdr->name().toString();
        if (tmp == QString("Login"))
            if (rdr->readElementText() == login)
                ll = true;

        if (tmp == QString("Password"))
            if (rdr->readElementText() == password)
                pp = true;

        rdr->readNextStartElement();
    }
    xmlFile->close();
    return ll && pp;
}

void Login::show_password(bool b) {
    ui->password_edit->setEchoMode(b ? QLineEdit::Password : QLineEdit::Normal);
}

void Login::on_log_in_button_clicked()
{
    int id = -1;
    OPEN_CONN
    try {
        QSqlQuery sq;
        QString password = ui->password_edit->text(), login = ui->login_edit->text();
        QByteArray hsh = QCryptographicHash::hash(QByteArray::fromStdString(password.toStdString()), QCryptographicHash::Sha256);
        password = QString::fromStdString(hsh.toStdString());

        sq.exec(QString("SELECT UserID FROM Users WHERE Login = '%1' AND Password = '%2'")
                .arg(login)
                .arg(password));

        if (sq.next())
            id = sq.value(0).toInt();
    }
    catch(std::exception) {
        qDebug("Ստոպ բեյբի էս ինչ ես անում!");
    }
    CLOSE_CONN

    if (id != -1) {
        emit clickLogin(id);
    }
    else if (checkIfAdmin(ui->login_edit->text(), ui->password_edit->text())) {
        emit clickLogin(0);
    }
    else {
        QMessageBox::warning(this, "Սխալ․․․", "Սխալ մուտքանուն կամ գաղտնաբառ", QMessageBox::Ok);
    }
}

void Login::on_register_button_clicked()
{
    this->hide();
    emit clickRegister();
}
