/********************************************************************************
** Form generated from reading UI file 'hope.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HOPE_H
#define UI_HOPE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QStackedWidget>

QT_BEGIN_NAMESPACE

class Ui_Hope
{
public:

    void setupUi(QStackedWidget *Hope)
    {
        if (Hope->objectName().isEmpty())
            Hope->setObjectName(QStringLiteral("Hope"));
        Hope->resize(810, 580);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Hope->sizePolicy().hasHeightForWidth());
        Hope->setSizePolicy(sizePolicy);
        Hope->setMinimumSize(QSize(810, 580));
        Hope->setMaximumSize(QSize(810, 580));

        retranslateUi(Hope);

        Hope->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(Hope);
    } // setupUi

    void retranslateUi(QStackedWidget *Hope)
    {
        Hope->setWindowTitle(QApplication::translate("Hope", "\324\271\325\245\325\275\325\277\325\241\325\276\325\270\326\200\325\264\325\241\325\266 \325\200\325\241\325\264\325\241\325\257\325\241\326\200\325\243 ver 1.0", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Hope: public Ui_Hope {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HOPE_H
