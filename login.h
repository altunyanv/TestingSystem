#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QMessageBox>
#include "registration.h"

namespace Ui {
class Login;
}

class Login : public QWidget
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = 0);
    ~Login();

private:
    Ui::Login *ui;
    bool checkIfAdmin(const QString&, const QString&);

private slots:
    void show_password(bool);
    void on_log_in_button_clicked();

    void on_register_button_clicked();

signals:
    void clickLogin(int);
    void clickRegister();
};

#endif // LOGIN_H
