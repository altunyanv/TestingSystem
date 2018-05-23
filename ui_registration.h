/********************************************************************************
** Form generated from reading UI file 'registration.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTRATION_H
#define UI_REGISTRATION_H

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

class Ui_Registration
{
public:
    QPushButton *register_button;
    QLineEdit *name_edit;
    QLineEdit *surname_edit;
    QLineEdit *login_edit;
    QLineEdit *password_edit;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *password_edit_2;
    QLabel *label_5;
    EyeLabel *confirm_password_show;
    EyeLabel *password_show;
    QLabel *login_warning;
    QPushButton *login_button;
    QLabel *password_warning;

    void setupUi(QWidget *Registration)
    {
        if (Registration->objectName().isEmpty())
            Registration->setObjectName(QStringLiteral("Registration"));
        Registration->resize(810, 580);
        register_button = new QPushButton(Registration);
        register_button->setObjectName(QStringLiteral("register_button"));
        register_button->setGeometry(QRect(535, 410, 85, 30));
        QFont font;
        font.setPointSize(10);
        register_button->setFont(font);
        name_edit = new QLineEdit(Registration);
        name_edit->setObjectName(QStringLiteral("name_edit"));
        name_edit->setGeometry(QRect(340, 120, 201, 25));
        name_edit->setFont(font);
        name_edit->setMaxLength(20);
        surname_edit = new QLineEdit(Registration);
        surname_edit->setObjectName(QStringLiteral("surname_edit"));
        surname_edit->setGeometry(QRect(340, 160, 201, 25));
        surname_edit->setFont(font);
        surname_edit->setMaxLength(20);
        login_edit = new QLineEdit(Registration);
        login_edit->setObjectName(QStringLiteral("login_edit"));
        login_edit->setGeometry(QRect(340, 200, 201, 25));
        login_edit->setFont(font);
        login_edit->setMaxLength(20);
        password_edit = new QLineEdit(Registration);
        password_edit->setObjectName(QStringLiteral("password_edit"));
        password_edit->setGeometry(QRect(340, 240, 201, 25));
        password_edit->setFont(font);
        password_edit->setMaxLength(16);
        label = new QLabel(Registration);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(140, 120, 161, 25));
        QFont font1;
        font1.setPointSize(11);
        label->setFont(font1);
        label_2 = new QLabel(Registration);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(140, 160, 161, 25));
        label_2->setFont(font1);
        label_3 = new QLabel(Registration);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(140, 200, 161, 25));
        label_3->setFont(font1);
        label_4 = new QLabel(Registration);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(140, 240, 161, 25));
        label_4->setFont(font1);
        password_edit_2 = new QLineEdit(Registration);
        password_edit_2->setObjectName(QStringLiteral("password_edit_2"));
        password_edit_2->setGeometry(QRect(340, 280, 201, 25));
        password_edit_2->setFont(font);
        password_edit_2->setMaxLength(16);
        label_5 = new QLabel(Registration);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(140, 280, 191, 25));
        label_5->setFont(font1);
        confirm_password_show = new EyeLabel(Registration);
        confirm_password_show->setObjectName(QStringLiteral("confirm_password_show"));
        confirm_password_show->setGeometry(QRect(515, 280, 25, 25));
        password_show = new EyeLabel(Registration);
        password_show->setObjectName(QStringLiteral("password_show"));
        password_show->setGeometry(QRect(515, 240, 25, 25));
        password_show->setMargin(0);
        password_show->setIndent(0);
        login_warning = new QLabel(Registration);
        login_warning->setObjectName(QStringLiteral("login_warning"));
        login_warning->setGeometry(QRect(550, 210, 171, 16));
        QFont font2;
        font2.setPointSize(7);
        login_warning->setFont(font2);
        login_warning->setStyleSheet(QStringLiteral("color: rgb(255, 0, 0);"));
        login_button = new QPushButton(Registration);
        login_button->setObjectName(QStringLiteral("login_button"));
        login_button->setGeometry(QRect(170, 410, 85, 30));
        login_button->setFont(font);
        login_button->setAutoDefault(false);
        login_button->setFlat(false);
        password_warning = new QLabel(Registration);
        password_warning->setObjectName(QStringLiteral("password_warning"));
        password_warning->setGeometry(QRect(550, 290, 171, 16));
        password_warning->setFont(font2);
        password_warning->setStyleSheet(QStringLiteral("color: rgb(255, 0, 0);"));

        retranslateUi(Registration);

        login_button->setDefault(false);


        QMetaObject::connectSlotsByName(Registration);
    } // setupUi

    void retranslateUi(QWidget *Registration)
    {
        Registration->setWindowTitle(QApplication::translate("Registration", "Form", nullptr));
        register_button->setText(QApplication::translate("Registration", "\324\263\326\200\325\241\325\266\326\201\325\276\325\245\325\254", nullptr));
        label->setText(QApplication::translate("Registration", "\324\261\325\266\325\270\326\202\325\266", nullptr));
        label_2->setText(QApplication::translate("Registration", "\324\261\325\246\325\243\325\241\325\266\325\270\326\202\325\266", nullptr));
        label_3->setText(QApplication::translate("Registration", "\325\204\325\270\326\202\325\277\326\204\325\241\325\266\325\270\326\202\325\266", nullptr));
        label_4->setText(QApplication::translate("Registration", "\324\263\325\241\325\262\325\277\325\266\325\241\325\242\325\241\325\274", nullptr));
        label_5->setText(QApplication::translate("Registration", "\325\200\325\241\325\275\325\277\325\241\325\277\325\245\325\254 \325\243\325\241\325\262\325\277\325\266\325\241\325\242\325\241\325\274\325\250", nullptr));
        confirm_password_show->setText(QString());
        password_show->setText(QString());
        login_warning->setText(QString());
        login_button->setText(QApplication::translate("Registration", "\325\204\325\270\326\202\325\277\326\204", nullptr));
        password_warning->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Registration: public Ui_Registration {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTRATION_H
