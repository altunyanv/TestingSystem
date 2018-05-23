/********************************************************************************
** Form generated from reading UI file 'problem.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROBLEM_H
#define UI_PROBLEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Problem
{
public:
    QPlainTextEdit *problem_statement;
    QPlainTextEdit *problem_title;
    QPlainTextEdit *problem_input;
    QPlainTextEdit *problem_output;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QPlainTextEdit *sample_input;
    QPlainTextEdit *sample_output;
    QPushButton *solve_problem;
    QPushButton *problem_set;

    void setupUi(QWidget *Problem)
    {
        if (Problem->objectName().isEmpty())
            Problem->setObjectName(QStringLiteral("Problem"));
        Problem->resize(810, 580);
        problem_statement = new QPlainTextEdit(Problem);
        problem_statement->setObjectName(QStringLiteral("problem_statement"));
        problem_statement->setEnabled(false);
        problem_statement->setGeometry(QRect(30, 100, 740, 101));
        QFont font;
        font.setPointSize(11);
        problem_statement->setFont(font);
        problem_statement->setFrameShape(QFrame::NoFrame);
        problem_statement->setFrameShadow(QFrame::Sunken);
        problem_statement->setTabStopWidth(40);
        problem_statement->setBackgroundVisible(false);
        problem_title = new QPlainTextEdit(Problem);
        problem_title->setObjectName(QStringLiteral("problem_title"));
        problem_title->setEnabled(false);
        problem_title->setGeometry(QRect(30, 19, 740, 51));
        QFont font1;
        font1.setPointSize(20);
        problem_title->setFont(font1);
        problem_title->setFrameShape(QFrame::NoFrame);
        problem_title->setFrameShadow(QFrame::Sunken);
        problem_title->setTabStopWidth(40);
        problem_title->setBackgroundVisible(false);
        problem_input = new QPlainTextEdit(Problem);
        problem_input->setObjectName(QStringLiteral("problem_input"));
        problem_input->setEnabled(false);
        problem_input->setGeometry(QRect(30, 240, 740, 61));
        problem_input->setFont(font);
        problem_input->setFrameShape(QFrame::NoFrame);
        problem_input->setFrameShadow(QFrame::Sunken);
        problem_input->setTabStopWidth(40);
        problem_input->setBackgroundVisible(false);
        problem_output = new QPlainTextEdit(Problem);
        problem_output->setObjectName(QStringLiteral("problem_output"));
        problem_output->setEnabled(false);
        problem_output->setGeometry(QRect(30, 340, 740, 61));
        problem_output->setFont(font);
        problem_output->setFrameShape(QFrame::NoFrame);
        problem_output->setFrameShadow(QFrame::Sunken);
        problem_output->setTabStopWidth(40);
        problem_output->setBackgroundVisible(false);
        label = new QLabel(Problem);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(50, 70, 141, 21));
        QFont font2;
        font2.setPointSize(11);
        font2.setBold(true);
        font2.setItalic(true);
        font2.setWeight(75);
        label->setFont(font2);
        label_2 = new QLabel(Problem);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(50, 210, 141, 21));
        label_2->setFont(font2);
        label_3 = new QLabel(Problem);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(50, 310, 141, 21));
        label_3->setFont(font2);
        label_4 = new QLabel(Problem);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(50, 400, 141, 21));
        label_4->setFont(font2);
        sample_input = new QPlainTextEdit(Problem);
        sample_input->setObjectName(QStringLiteral("sample_input"));
        sample_input->setEnabled(false);
        sample_input->setGeometry(QRect(30, 430, 370, 81));
        QFont font3;
        font3.setFamily(QStringLiteral("Consolas"));
        font3.setPointSize(11);
        sample_input->setFont(font3);
        sample_input->setFrameShape(QFrame::Box);
        sample_input->setFrameShadow(QFrame::Sunken);
        sample_input->setTabStopWidth(40);
        sample_input->setBackgroundVisible(false);
        sample_output = new QPlainTextEdit(Problem);
        sample_output->setObjectName(QStringLiteral("sample_output"));
        sample_output->setEnabled(false);
        sample_output->setGeometry(QRect(400, 430, 370, 81));
        sample_output->setFont(font3);
        sample_output->setFrameShape(QFrame::Box);
        sample_output->setFrameShadow(QFrame::Sunken);
        sample_output->setTabStopWidth(40);
        sample_output->setBackgroundVisible(false);
        solve_problem = new QPushButton(Problem);
        solve_problem->setObjectName(QStringLiteral("solve_problem"));
        solve_problem->setGeometry(QRect(680, 530, 85, 30));
        QFont font4;
        font4.setPointSize(10);
        solve_problem->setFont(font4);
        problem_set = new QPushButton(Problem);
        problem_set->setObjectName(QStringLiteral("problem_set"));
        problem_set->setGeometry(QRect(30, 530, 131, 30));
        problem_set->setFont(font4);

        retranslateUi(Problem);

        QMetaObject::connectSlotsByName(Problem);
    } // setupUi

    void retranslateUi(QWidget *Problem)
    {
        Problem->setWindowTitle(QApplication::translate("Problem", "Form", nullptr));
        label->setText(QApplication::translate("Problem", "\325\206\325\257\325\241\326\200\325\241\325\243\326\200\325\270\326\202\325\251\325\265\325\270\326\202\325\266", nullptr));
        label_2->setText(QApplication::translate("Problem", "\325\204\325\270\326\202\325\277\326\204", nullptr));
        label_3->setText(QApplication::translate("Problem", "\324\265\325\254\326\204", nullptr));
        label_4->setText(QApplication::translate("Problem", "\325\225\326\200\325\253\325\266\325\241\325\257", nullptr));
        solve_problem->setText(QApplication::translate("Problem", "\324\274\325\270\326\202\325\256\325\245\325\254", nullptr));
        problem_set->setText(QApplication::translate("Problem", "\324\262\325\270\325\254\325\270\326\200 \325\255\325\266\325\244\325\253\326\200\325\266\325\245\326\200\325\250", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Problem: public Ui_Problem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROBLEM_H
