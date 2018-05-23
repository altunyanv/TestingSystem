/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include "registration.h"

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QLineEdit *login_edit;
    QLabel *label_3;
    QLineEdit *password_edit;
    QLabel *label_4;
    QPushButton *register_button;
    QPushButton *log_in_button;
    EyeLabel *password_show;

    void setupUi(QWidget *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName(QStringLiteral("Login"));
        Login->resize(810, 580);
        login_edit = new QLineEdit(Login);
        login_edit->setObjectName(QStringLiteral("login_edit"));
        login_edit->setGeometry(QRect(345, 200, 201, 25));
        QFont font;
        font.setPointSize(10);
        login_edit->setFont(font);
        login_edit->setMaxLength(20);
        label_3 = new QLabel(Login);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(240, 200, 101, 25));
        QFont font1;
        font1.setPointSize(11);
        label_3->setFont(font1);
        password_edit = new QLineEdit(Login);
        password_edit->setObjectName(QStringLiteral("password_edit"));
        password_edit->setGeometry(QRect(345, 240, 201, 25));
        password_edit->setFont(font);
        password_edit->setMaxLength(16);
        label_4 = new QLabel(Login);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(240, 240, 101, 25));
        label_4->setFont(font1);
        register_button = new QPushButton(Login);
        register_button->setObjectName(QStringLiteral("register_button"));
        register_button->setGeometry(QRect(240, 310, 85, 30));
        register_button->setFont(font);
        log_in_button = new QPushButton(Login);
        log_in_button->setObjectName(QStringLiteral("log_in_button"));
        log_in_button->setGeometry(QRect(463, 310, 85, 30));
        log_in_button->setFont(font);
        password_show = new EyeLabel(Login);
        password_show->setObjectName(QStringLiteral("password_show"));
        password_show->setGeometry(QRect(520, 240, 25, 25));
        password_show->setMargin(0);
        password_show->setIndent(0);

        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QWidget *Login)
    {
        Login->setWindowTitle(QApplication::translate("Login", "Form", nullptr));
        label_3->setText(QApplication::translate("Login", "\325\204\325\270\326\202\325\277\326\204\325\241\325\266\325\270\326\202\325\266", nullptr));
        label_4->setText(QApplication::translate("Login", "\324\263\325\241\325\262\325\277\325\266\325\241\325\242\325\241\325\274", nullptr));
        register_button->setText(QApplication::translate("Login", "\324\263\326\200\325\241\325\266\326\201\325\276\325\245\325\254", nullptr));
        log_in_button->setText(QApplication::translate("Login", "\325\204\325\270\326\202\325\277\326\204", nullptr));
        password_show->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
