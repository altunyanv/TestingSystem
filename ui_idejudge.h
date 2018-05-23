/********************************************************************************
** Form generated from reading UI file 'idejudge.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IDEJUDGE_H
#define UI_IDEJUDGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_IDEJudge
{
public:
    QWidget *centralWidget;

    void setupUi(QMainWindow *IDEJudge)
    {
        if (IDEJudge->objectName().isEmpty())
            IDEJudge->setObjectName(QStringLiteral("IDEJudge"));
        IDEJudge->resize(810, 600);
        centralWidget = new QWidget(IDEJudge);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        IDEJudge->setCentralWidget(centralWidget);

        retranslateUi(IDEJudge);

        QMetaObject::connectSlotsByName(IDEJudge);
    } // setupUi

    void retranslateUi(QMainWindow *IDEJudge)
    {
        IDEJudge->setWindowTitle(QApplication::translate("IDEJudge", "IDEJudge", nullptr));
    } // retranslateUi

};

namespace Ui {
    class IDEJudge: public Ui_IDEJudge {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IDEJUDGE_H
