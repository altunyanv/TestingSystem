#ifndef REGISTRATION_H
#define REGISTRATION_H

#include <QWidget>
#include <QPixmap>
#include <QLabel>
#include <QMessageBox>
#include "dbconnection.h"

namespace Ui {
class Registration;
}

class Registration : public QWidget
{
    Q_OBJECT
public:
    explicit Registration(QWidget *parent = 0);
    ~Registration();

private slots:
    void on_login_edit_textChanged(const QString &arg1);
    void reset_fields();
    void show_password(bool);
    void show_confirmed_password(bool);
    void on_password_edit_2_textChanged(const QString &arg1);
    void on_password_edit_textChanged(const QString &arg1);
    void on_register_button_clicked();

    void on_login_button_clicked();

signals:
    void onRegistration(QString, QString, QString, QString);
    void showAllUsers();
    void clickLogin();

private:
    Ui::Registration *ui;
    bool isLoginUnique(const QString&);
};

//------------------------------------------------------------------------------------------
//------------------------------Password show/hide icon-------------------------------------
//------------------------------------------------------------------------------------------

class EyeLabel : public QLabel {
    Q_OBJECT
public:
    EyeLabel(QWidget *parent = 0) : QLabel(parent) {
        setPixmap(QPixmap(":/images/eye_closed.png").scaled(25, 25));
    }

    void mousePressEvent(QMouseEvent *ev) {
        emit onShow(false);
        setPixmap(QPixmap(":/images/eye_opened.png").scaled(25, 25));
    }

    void mouseReleaseEvent(QMouseEvent *ev) {
        emit onShow(true);
        setPixmap(QPixmap(":/images/eye_closed.png").scaled(25, 25));
    }

signals:
    void onShow(bool);
};

#endif // REGISTRATION_H
