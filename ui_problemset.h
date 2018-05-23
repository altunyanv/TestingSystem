/********************************************************************************
** Form generated from reading UI file 'problemset.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROBLEMSET_H
#define UI_PROBLEMSET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ProblemSet
{
public:
    QLabel *label;
    QLabel *label_2;
    QTableView *submission_history;
    QLabel *label_3;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QPushButton *pushButton_3;

    void setupUi(QWidget *ProblemSet)
    {
        if (ProblemSet->objectName().isEmpty())
            ProblemSet->setObjectName(QStringLiteral("ProblemSet"));
        ProblemSet->resize(810, 580);
        label = new QLabel(ProblemSet);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 20, 61, 31));
        QFont font;
        font.setPointSize(12);
        label->setFont(font);
        label_2 = new QLabel(ProblemSet);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(70, 20, 151, 31));
        label_2->setFont(font);
        submission_history = new QTableView(ProblemSet);
        submission_history->setObjectName(QStringLiteral("submission_history"));
        submission_history->setGeometry(QRect(270, 50, 511, 471));
        label_3 = new QLabel(ProblemSet);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(270, 20, 241, 31));
        label_3->setFont(font);
        scrollArea = new QScrollArea(ProblemSet);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setGeometry(QRect(20, 50, 230, 470));
        scrollArea->setFrameShape(QFrame::NoFrame);
        scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 230, 470));
        scrollArea->setWidget(scrollAreaWidgetContents);
        pushButton_3 = new QPushButton(ProblemSet);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(690, 530, 91, 31));
        QFont font1;
        font1.setPointSize(10);
        pushButton_3->setFont(font1);

        retranslateUi(ProblemSet);

        QMetaObject::connectSlotsByName(ProblemSet);
    } // setupUi

    void retranslateUi(QWidget *ProblemSet)
    {
        ProblemSet->setWindowTitle(QApplication::translate("ProblemSet", "Form", nullptr));
        label->setText(QApplication::translate("ProblemSet", "   ID", nullptr));
        label_2->setText(QApplication::translate("ProblemSet", "\324\275\325\266\325\244\326\200\325\253 \325\241\325\266\325\270\326\202\325\266\325\250", nullptr));
        label_3->setText(QApplication::translate("ProblemSet", "   \324\274\325\270\326\202\325\256\325\270\326\202\325\264\325\266\325\245\326\200\325\253 \325\272\325\241\325\277\325\264\325\270\326\202\325\251\325\265\325\270\326\202\325\266\325\250", nullptr));
        pushButton_3->setText(QApplication::translate("ProblemSet", "\324\264\325\270\326\202\326\200\325\275 \325\243\325\241\325\254", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ProblemSet: public Ui_ProblemSet {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROBLEMSET_H
