/********************************************************************************
** Form generated from reading UI file 'editor.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITOR_H
#define UI_EDITOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include "editor.h"

QT_BEGIN_NAMESPACE

class Ui_Editor
{
public:
    PublicPlainTextEdit *plainTextEdit_2;
    PublicPlainTextEdit *plainTextEdit;
    QPushButton *submit_solution;
    QPushButton *back_to_problem;

    void setupUi(QWidget *Editor)
    {
        if (Editor->objectName().isEmpty())
            Editor->setObjectName(QStringLiteral("Editor"));
        Editor->resize(810, 580);
        plainTextEdit_2 = new PublicPlainTextEdit(Editor);
        plainTextEdit_2->setObjectName(QStringLiteral("plainTextEdit_2"));
        plainTextEdit_2->setGeometry(QRect(30, 10, 771, 511));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(plainTextEdit_2->sizePolicy().hasHeightForWidth());
        plainTextEdit_2->setSizePolicy(sizePolicy);
        plainTextEdit_2->setMinimumSize(QSize(771, 501));
        QFont font;
        font.setFamily(QStringLiteral("Consolas"));
        font.setPointSize(11);
        plainTextEdit_2->setFont(font);
        plainTextEdit_2->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        plainTextEdit_2->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        plainTextEdit_2->setLineWrapMode(QPlainTextEdit::NoWrap);
        plainTextEdit_2->setTabStopWidth(40);
        plainTextEdit = new PublicPlainTextEdit(Editor);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));
        plainTextEdit->setEnabled(false);
        plainTextEdit->setGeometry(QRect(10, 10, 20, 511));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(plainTextEdit->sizePolicy().hasHeightForWidth());
        plainTextEdit->setSizePolicy(sizePolicy1);
        plainTextEdit->setMinimumSize(QSize(20, 501));
        plainTextEdit->setSizeIncrement(QSize(10, 0));
        plainTextEdit->setBaseSize(QSize(20, 271));
        plainTextEdit->setFont(font);
        plainTextEdit->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        plainTextEdit->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        plainTextEdit->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContentsOnFirstShow);
        plainTextEdit->setLineWrapMode(QPlainTextEdit::NoWrap);
        plainTextEdit->setCursorWidth(1);
        submit_solution = new QPushButton(Editor);
        submit_solution->setObjectName(QStringLiteral("submit_solution"));
        submit_solution->setGeometry(QRect(670, 530, 131, 30));
        QFont font1;
        font1.setPointSize(10);
        submit_solution->setFont(font1);
        back_to_problem = new QPushButton(Editor);
        back_to_problem->setObjectName(QStringLiteral("back_to_problem"));
        back_to_problem->setGeometry(QRect(10, 530, 141, 30));
        back_to_problem->setFont(font1);

        retranslateUi(Editor);

        QMetaObject::connectSlotsByName(Editor);
    } // setupUi

    void retranslateUi(QWidget *Editor)
    {
        Editor->setWindowTitle(QApplication::translate("Editor", "Form", nullptr));
        submit_solution->setText(QApplication::translate("Editor", "\325\210\326\202\325\262\325\241\326\200\325\257\325\245\325\254 \325\254\325\270\326\202\325\256\325\270\326\202\325\264\325\250", nullptr));
        back_to_problem->setText(QApplication::translate("Editor", "\325\216\325\245\326\200\325\241\325\244\325\241\326\200\325\261 \325\255\325\266\325\244\326\200\325\253\325\266", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Editor: public Ui_Editor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITOR_H
