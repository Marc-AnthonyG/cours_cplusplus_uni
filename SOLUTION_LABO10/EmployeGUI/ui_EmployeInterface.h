/********************************************************************************
** Form generated from reading UI file 'EmployeInterface.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EMPLOYEINTERFACE_H
#define UI_EMPLOYEINTERFACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EmployeInterface
{
public:
    QAction *actionQuitter;
    QAction *actionCommission;
    QAction *actionHoraire;
    QAction *actionPatron;
    QWidget *centralwidget;
    QTextEdit *affichage;
    QMenuBar *menubar;
    QMenu *menuMenu;
    QMenu *menuAjouter_Employe;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *EmployeInterface)
    {
        if (EmployeInterface->objectName().isEmpty())
            EmployeInterface->setObjectName(QString::fromUtf8("EmployeInterface"));
        EmployeInterface->resize(800, 600);
        actionQuitter = new QAction(EmployeInterface);
        actionQuitter->setObjectName(QString::fromUtf8("actionQuitter"));
        actionCommission = new QAction(EmployeInterface);
        actionCommission->setObjectName(QString::fromUtf8("actionCommission"));
        actionHoraire = new QAction(EmployeInterface);
        actionHoraire->setObjectName(QString::fromUtf8("actionHoraire"));
        actionPatron = new QAction(EmployeInterface);
        actionPatron->setObjectName(QString::fromUtf8("actionPatron"));
        centralwidget = new QWidget(EmployeInterface);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        affichage = new QTextEdit(centralwidget);
        affichage->setObjectName(QString::fromUtf8("affichage"));
        affichage->setGeometry(QRect(3, 4, 781, 561));
        EmployeInterface->setCentralWidget(centralwidget);
        menubar = new QMenuBar(EmployeInterface);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        menuMenu = new QMenu(menubar);
        menuMenu->setObjectName(QString::fromUtf8("menuMenu"));
        menuAjouter_Employe = new QMenu(menuMenu);
        menuAjouter_Employe->setObjectName(QString::fromUtf8("menuAjouter_Employe"));
        EmployeInterface->setMenuBar(menubar);
        statusbar = new QStatusBar(EmployeInterface);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        EmployeInterface->setStatusBar(statusbar);

        menubar->addAction(menuMenu->menuAction());
        menuMenu->addAction(menuAjouter_Employe->menuAction());
        menuMenu->addAction(actionQuitter);
        menuAjouter_Employe->addAction(actionCommission);
        menuAjouter_Employe->addAction(actionHoraire);
        menuAjouter_Employe->addAction(actionPatron);

        retranslateUi(EmployeInterface);
        QObject::connect(actionQuitter, SIGNAL(triggered()), EmployeInterface, SLOT(close()));
        QObject::connect(actionCommission, SIGNAL(triggered()), EmployeInterface, SLOT(dialogCommis()));
        QObject::connect(actionHoraire, SIGNAL(triggered()), EmployeInterface, SLOT(dialogHoraire()));
        QObject::connect(actionPatron, SIGNAL(triggered()), EmployeInterface, SLOT(dialogPatron()));

        QMetaObject::connectSlotsByName(EmployeInterface);
    } // setupUi

    void retranslateUi(QMainWindow *EmployeInterface)
    {
        EmployeInterface->setWindowTitle(QApplication::translate("EmployeInterface", "EmployeInterface", nullptr));
        actionQuitter->setText(QApplication::translate("EmployeInterface", "Quitter", nullptr));
        actionCommission->setText(QApplication::translate("EmployeInterface", "Commission", nullptr));
        actionHoraire->setText(QApplication::translate("EmployeInterface", "Horaire", nullptr));
        actionPatron->setText(QApplication::translate("EmployeInterface", "Patron", nullptr));
        menuMenu->setTitle(QApplication::translate("EmployeInterface", "Menu", nullptr));
        menuAjouter_Employe->setTitle(QApplication::translate("EmployeInterface", "Ajouter Employe", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EmployeInterface: public Ui_EmployeInterface {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EMPLOYEINTERFACE_H
