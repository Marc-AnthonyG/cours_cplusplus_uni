/********************************************************************************
** Form generated from reading UI file 'EmployePatronInterface.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EMPLOYEPATRONINTERFACE_H
#define UI_EMPLOYEPATRONINTERFACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_EmployePatronInterface
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QCalendarWidget *dateNaissance;
    QLineEdit *nom;
    QLineEdit *prenom;
    QSpinBox *code;
    QDoubleSpinBox *salaire;
    QPushButton *ok;

    void setupUi(QDialog *EmployePatronInterface)
    {
        if (EmployePatronInterface->objectName().isEmpty())
            EmployePatronInterface->setObjectName(QString::fromUtf8("EmployePatronInterface"));
        EmployePatronInterface->resize(779, 610);
        label = new QLabel(EmployePatronInterface);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 20, 58, 16));
        label_2 = new QLabel(EmployePatronInterface);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 80, 58, 16));
        label_3 = new QLabel(EmployePatronInterface);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 220, 131, 16));
        label_4 = new QLabel(EmployePatronInterface);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 390, 121, 16));
        label_5 = new QLabel(EmployePatronInterface);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(20, 480, 141, 16));
        dateNaissance = new QCalendarWidget(EmployePatronInterface);
        dateNaissance->setObjectName(QString::fromUtf8("dateNaissance"));
        dateNaissance->setGeometry(QRect(230, 120, 432, 194));
        nom = new QLineEdit(EmployePatronInterface);
        nom->setObjectName(QString::fromUtf8("nom"));
        nom->setGeometry(QRect(230, 20, 351, 28));
        prenom = new QLineEdit(EmployePatronInterface);
        prenom->setObjectName(QString::fromUtf8("prenom"));
        prenom->setGeometry(QRect(230, 70, 351, 28));
        code = new QSpinBox(EmployePatronInterface);
        code->setObjectName(QString::fromUtf8("code"));
        code->setGeometry(QRect(230, 380, 81, 26));
        salaire = new QDoubleSpinBox(EmployePatronInterface);
        salaire->setObjectName(QString::fromUtf8("salaire"));
        salaire->setGeometry(QRect(230, 470, 81, 26));
        ok = new QPushButton(EmployePatronInterface);
        ok->setObjectName(QString::fromUtf8("ok"));
        ok->setGeometry(QRect(290, 570, 90, 28));

        retranslateUi(EmployePatronInterface);
        QObject::connect(ok, SIGNAL(clicked()), EmployePatronInterface, SLOT(valideEnregistrement()));

        QMetaObject::connectSlotsByName(EmployePatronInterface);
    } // setupUi

    void retranslateUi(QDialog *EmployePatronInterface)
    {
        EmployePatronInterface->setWindowTitle(QApplication::translate("EmployePatronInterface", "EmployePatronInterface", nullptr));
        label->setText(QApplication::translate("EmployePatronInterface", "Nom :", nullptr));
        label_2->setText(QApplication::translate("EmployePatronInterface", "Prenom :", nullptr));
        label_3->setText(QApplication::translate("EmployePatronInterface", "Date de naissance :", nullptr));
        label_4->setText(QApplication::translate("EmployePatronInterface", "Code departement :", nullptr));
        label_5->setText(QApplication::translate("EmployePatronInterface", "Salaire hebdomadaire :", nullptr));
        ok->setText(QApplication::translate("EmployePatronInterface", "OK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EmployePatronInterface: public Ui_EmployePatronInterface {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EMPLOYEPATRONINTERFACE_H
