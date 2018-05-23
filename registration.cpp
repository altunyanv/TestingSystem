#include "registration.h"
#include "ui_registration.h"

Registration::Registration(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Registration)
{
    ui->setupUi(this);
    connect(ui->register_button, SIGNAL(clicked(bool)), this, SLOT(reset_fields()));
    connect(ui->login_button, SIGNAL(clicked(bool)), this, SLOT(reset_fields()));
    connect(ui->password_show, SIGNAL(onShow(bool)), this, SLOT(show_password(bool)));
    connect(ui->confirm_password_show, SIGNAL(onShow(bool)), this, SLOT(show_confirmed_password(bool)));
    ui->password_edit_2->setEchoMode(QLineEdit::Password);
    ui->password_edit->setEchoMode(QLineEdit::Password);
}

Registration::~Registration()
{
    delete ui;
}

void Registration::reset_fields() {
    ui->name_edit->setText("");
    ui->surname_edit->setText("");
    ui->login_edit->setText("");    ui->login_warning->setText("");
    ui->password_edit->setText("");
    ui->password_edit_2->setText("");
}

void Registration::on_login_edit_textChanged(const QString &login)
{
    if (login.length() < 8)     ui->login_warning->setText(QString("Մուտքանունը շատ կարճ է"));
    else {
        ui->login_warning->setText(QString(""));
        if (!isLoginUnique(login))  ui->login_warning->setText(QString("Մուտքանունը միակը չէ"));
        else                        ui->login_warning->setText(QString(""));
    }
}

void Registration::show_confirmed_password(bool b) {
    ui->password_edit_2->setEchoMode(b ? QLineEdit::Password : QLineEdit::Normal);
}

void Registration::show_password(bool b) {
    ui->password_edit->setEchoMode(b ? QLineEdit::Password : QLineEdit::Normal);
}

bool Registration::isLoginUnique(const QString &login) {
    bool result = false;
    try {
        OPEN_CONN
        QSqlQuery sq;
        sq.exec(QString("SELECT Login FROM Users WHERE Login = '%1'").arg(login));
        result = !sq.next();
    }
    catch(std::exception ex){
        //qDebug(ex.what());
        qDebug("Ստոպ բեյբի էս ինչ ես անում!");
    }
    CLOSE_CONN
    return result;
}

void Registration::on_password_edit_2_textChanged(const QString &arg1)
{
    if (ui->password_edit->text().length() != 0 &&
        ui->password_edit_2->text().length() != 0 &&
        ui->password_edit->text() != ui->password_edit_2->text())
        ui->password_warning->setText("Գաղտնաբառերը չեն համընկնում");
    else
        ui->password_warning->setText("");
}

void Registration::on_password_edit_textChanged(const QString &arg1)
{
    if (ui->password_edit->text().length() != 0 &&
        ui->password_edit_2->text().length() != 0 &&
        ui->password_edit->text() != ui->password_edit_2->text())
        ui->password_warning->setText("Գաղտնաբառերը չեն համընկնում");
    else
        ui->password_warning->setText("");
}

void Registration::on_register_button_clicked()
{
    if (ui->name_edit->text().length() == 0 ||
            ui->surname_edit->text().length() == 0 ||
            ui->login_edit->text().length() == 0 ||
            ui->password_edit->text().length() == 0 ||
            ui->password_edit_2->text().length() == 0)
        QMessageBox::warning(this, "Ուշադրություն․․․", "Բոլոր դաշտերը պետք է լրացված լինեն", QMessageBox::Ok);
    else if (ui->login_warning->text().length() != 0 ||
             ui->password_warning->text().length() != 0)
        QMessageBox::warning(this, "Ուշադրություն․․․", "Ուշադրություն դարձրեք կարմիր գույնով նշված սխալներին", QMessageBox::Ok);
    else {
        try {
            OPEN_CONN
            int id;
            QString name = ui->name_edit->text(),
                    surname = ui->surname_edit->text(),
                    login = ui->login_edit->text(),
                    password = ui->password_edit->text();

            QByteArray hsh = QCryptographicHash::hash(QByteArray::fromStdString(password.toStdString()), QCryptographicHash::Sha256);
            password = QString::fromStdString(hsh.toStdString());


            QSqlQuery sq;
            srand(time(0));
            while(id = (10000 + rand())) {
                sq.exec(QString("SELECT UserID FROM Users WHERE ID = %1").arg(id));
                if (!sq.next()) break;
            }

            sq.prepare("INSERT INTO Users \
                            VALUES((:UserID), (:Name), (:Surname), (:Login), (:Password))");
            sq.bindValue(":UserID", id);
            sq.bindValue(":Name", name);
            sq.bindValue(":Surname", surname);
            sq.bindValue(":Login", login);
            sq.bindValue(":Password", password);

            sq.exec();
            QMessageBox::warning(this, "Ուշադրություն․․․", "Շնորհավորում եմ դուք հաջողությամբ գրանցվեցիք մեր համակարգում", QMessageBox::Ok);
        }
        catch(std::exception ex) {
            qDebug("Ստոպ բեյբի էս ինչ ես անում!");
        }
        CLOSE_CONN
    }
}

void Registration::on_login_button_clicked()
{
    emit clickLogin();
}
