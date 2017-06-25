/********************************************************************************
** Form generated from reading UI file 'helloinvs.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HELLOINVS_H
#define UI_HELLOINVS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_helloinvsClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *helloinvsClass)
    {
        if (helloinvsClass->objectName().isEmpty())
            helloinvsClass->setObjectName(QStringLiteral("helloinvsClass"));
        helloinvsClass->resize(600, 400);
        menuBar = new QMenuBar(helloinvsClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        helloinvsClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(helloinvsClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        helloinvsClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(helloinvsClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        helloinvsClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(helloinvsClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        helloinvsClass->setStatusBar(statusBar);

        retranslateUi(helloinvsClass);

        QMetaObject::connectSlotsByName(helloinvsClass);
    } // setupUi

    void retranslateUi(QMainWindow *helloinvsClass)
    {
        helloinvsClass->setWindowTitle(QApplication::translate("helloinvsClass", "helloinvs", 0));
    } // retranslateUi

};

namespace Ui {
    class helloinvsClass: public Ui_helloinvsClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HELLOINVS_H
