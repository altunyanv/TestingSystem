/********************************************************************************
** Form generated from reading UI file 'newproblem.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWPROBLEM_H
#define UI_NEWPROBLEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NewProblem
{
public:
    QLabel *label_2;
    QPlainTextEdit *problem_output;
    QPlainTextEdit *sample_input;
    QLabel *label;
    QPlainTextEdit *sample_output;
    QPlainTextEdit *problem_title;
    QPlainTextEdit *problem_statement;
    QLabel *label_4;
    QPlainTextEdit *problem_input;
    QLabel *label_3;
    QLabel *label_5;
    QPlainTextEdit *test_input;
    QPlainTextEdit *test_output;
    QPushButton *pushButton;
    QLabel *label_6;
    QLabel *label_7;
    QTableView *tableView;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;

    void setupUi(QWidget *NewProblem)
    {
        if (NewProblem->objectName().isEmpty())
            NewProblem->setObjectName(QStringLiteral("NewProblem"));
        NewProblem->resize(810, 580);
        label_2 = new QLabel(NewProblem);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(50, 180, 141, 21));
        QFont font;
        font.setPointSize(11);
        font.setBold(true);
        font.setItalic(true);
        font.setWeight(75);
        label_2->setFont(font);
        problem_output = new QPlainTextEdit(NewProblem);
        problem_output->setObjectName(QStringLiteral("problem_output"));
        problem_output->setEnabled(true);
        problem_output->setGeometry(QRect(30, 300, 740, 61));
        QFont font1;
        font1.setPointSize(11);
        problem_output->setFont(font1);
        problem_output->setFrameShape(QFrame::Box);
        problem_output->setFrameShadow(QFrame::Sunken);
        problem_output->setTabStopWidth(40);
        problem_output->setBackgroundVisible(false);
        sample_input = new QPlainTextEdit(NewProblem);
        sample_input->setObjectName(QStringLiteral("sample_input"));
        sample_input->setEnabled(true);
        sample_input->setGeometry(QRect(30, 390, 370, 41));
        QFont font2;
        font2.setFamily(QStringLiteral("Consolas"));
        font2.setPointSize(11);
        sample_input->setFont(font2);
        sample_input->setFrameShape(QFrame::Box);
        sample_input->setFrameShadow(QFrame::Sunken);
        sample_input->setTabStopWidth(40);
        sample_input->setBackgroundVisible(false);
        label = new QLabel(NewProblem);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(50, 70, 141, 21));
        label->setFont(font);
        sample_output = new QPlainTextEdit(NewProblem);
        sample_output->setObjectName(QStringLiteral("sample_output"));
        sample_output->setEnabled(true);
        sample_output->setGeometry(QRect(400, 390, 370, 41));
        sample_output->setFont(font2);
        sample_output->setFrameShape(QFrame::Box);
        sample_output->setFrameShadow(QFrame::Sunken);
        sample_output->setTabStopWidth(40);
        sample_output->setBackgroundVisible(false);
        problem_title = new QPlainTextEdit(NewProblem);
        problem_title->setObjectName(QStringLiteral("problem_title"));
        problem_title->setEnabled(true);
        problem_title->setGeometry(QRect(30, 19, 740, 51));
        QFont font3;
        font3.setPointSize(20);
        problem_title->setFont(font3);
        problem_title->setFrameShape(QFrame::Box);
        problem_title->setFrameShadow(QFrame::Sunken);
        problem_title->setTabStopWidth(40);
        problem_title->setBackgroundVisible(false);
        problem_statement = new QPlainTextEdit(NewProblem);
        problem_statement->setObjectName(QStringLiteral("problem_statement"));
        problem_statement->setEnabled(true);
        problem_statement->setGeometry(QRect(30, 100, 740, 81));
        problem_statement->setFont(font1);
        problem_statement->setFrameShape(QFrame::Box);
        problem_statement->setFrameShadow(QFrame::Sunken);
        problem_statement->setTabStopWidth(40);
        problem_statement->setBackgroundVisible(false);
        label_4 = new QLabel(NewProblem);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(50, 360, 161, 21));
        label_4->setFont(font);
        problem_input = new QPlainTextEdit(NewProblem);
        problem_input->setObjectName(QStringLiteral("problem_input"));
        problem_input->setEnabled(true);
        problem_input->setGeometry(QRect(30, 210, 740, 61));
        problem_input->setFont(font1);
        problem_input->setFrameShape(QFrame::Box);
        problem_input->setFrameShadow(QFrame::Sunken);
        problem_input->setTabStopWidth(40);
        problem_input->setBackgroundVisible(false);
        label_3 = new QLabel(NewProblem);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(50, 270, 141, 21));
        label_3->setFont(font);
        label_5 = new QLabel(NewProblem);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(50, 430, 161, 21));
        label_5->setFont(font);
        test_input = new QPlainTextEdit(NewProblem);
        test_input->setObjectName(QStringLiteral("test_input"));
        test_input->setEnabled(true);
        test_input->setGeometry(QRect(100, 460, 221, 41));
        test_input->setFont(font2);
        test_input->setFrameShape(QFrame::Box);
        test_input->setFrameShadow(QFrame::Sunken);
        test_input->setTabStopWidth(40);
        test_input->setBackgroundVisible(false);
        test_output = new QPlainTextEdit(NewProblem);
        test_output->setObjectName(QStringLiteral("test_output"));
        test_output->setEnabled(true);
        test_output->setGeometry(QRect(100, 500, 221, 41));
        test_output->setFont(font2);
        test_output->setFrameShape(QFrame::Box);
        test_output->setFrameShadow(QFrame::Sunken);
        test_output->setTabStopWidth(40);
        test_output->setBackgroundVisible(false);
        pushButton = new QPushButton(NewProblem);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(320, 490, 75, 23));
        label_6 = new QLabel(NewProblem);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(40, 470, 61, 21));
        label_6->setFont(font);
        label_7 = new QLabel(NewProblem);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(40, 510, 61, 21));
        label_7->setFont(font);
        tableView = new QTableView(NewProblem);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(400, 460, 371, 81));
        pushButton_2 = new QPushButton(NewProblem);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(590, 544, 91, 31));
        QFont font4;
        font4.setPointSize(10);
        pushButton_2->setFont(font4);
        pushButton_3 = new QPushButton(NewProblem);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(681, 544, 91, 31));
        pushButton_3->setFont(font4);

        retranslateUi(NewProblem);

        QMetaObject::connectSlotsByName(NewProblem);
    } // setupUi

    void retranslateUi(QWidget *NewProblem)
    {
        NewProblem->setWindowTitle(QApplication::translate("NewProblem", "Form", nullptr));
        label_2->setText(QApplication::translate("NewProblem", "\325\204\325\270\326\202\325\277\326\204", nullptr));
        label->setText(QApplication::translate("NewProblem", "\325\206\325\257\325\241\326\200\325\241\325\243\326\200\325\270\326\202\325\251\325\265\325\270\326\202\325\266", nullptr));
        label_4->setText(QApplication::translate("NewProblem", "\324\271\325\245\325\275\325\277\325\241\325\265\325\253\325\266 \326\205\326\200\325\253\325\266\325\241\325\257", nullptr));
        label_3->setText(QApplication::translate("NewProblem", "\324\265\325\254\326\204", nullptr));
        label_5->setText(QApplication::translate("NewProblem", "\324\261\325\276\325\245\325\254\325\241\326\201\325\266\325\245\325\254 \325\251\325\245\325\275\325\277", nullptr));
        pushButton->setText(QApplication::translate("NewProblem", "\324\261\325\276\325\245\325\254\325\241\326\201\325\266\325\245\325\254>", nullptr));
        label_6->setText(QApplication::translate("NewProblem", "\325\204\325\270\326\202\325\277\326\204", nullptr));
        label_7->setText(QApplication::translate("NewProblem", "\324\265\325\254\326\204", nullptr));
        pushButton_2->setText(QApplication::translate("NewProblem", "\325\212\325\241\325\277\326\200\325\241\325\275\325\277", nullptr));
        pushButton_3->setText(QApplication::translate("NewProblem", "\324\264\325\270\326\202\326\200\325\275 \325\243\325\241\325\254", nullptr));
    } // retranslateUi

};

namespace Ui {
    class NewProblem: public Ui_NewProblem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWPROBLEM_H
