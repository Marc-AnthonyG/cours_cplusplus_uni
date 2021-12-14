/********************************************************************************
** Form generated from reading UI file 'EmployeHoraireInterface.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EMPLOYEHORAIREINTERFACE_H
#define UI_EMPLOYEHORAIREINTERFACE_H

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

class Ui_EmployeHoraireInterface
{
public:
    QPushButton *ok;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLineEdit *nom;
    QLineEdit *prenom;
    QCalendarWidget *dateNaissance;
    QSpinBox *code;
    QDoubleSpinBox *taux;
    QDoubleSpinBox *heure;

    void setupUi(QDialog *EmployeHoraireInterface)
    {
        if (EmployeHoraireInterface->objectName().isEmpty())
            EmployeHoraireInterface->setObjectName(QString::fromUtf8("EmployeHoraireInterface"));
        EmployeHoraireInterface->resize(790, 607);
        ok = new QPushButton(EmployeHoraireInterface);
        ok->setObjectName(QString::fromUtf8("ok"));
        ok->setGeometry(QRect(320, 570, 90, 28));
        label = new QLabel(EmployeHoraireInterface);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 20, 58, 16));
        label_2 = new QLabel(EmployeHoraireInterface);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(30, 70, 58, 16));
        label_3 = new QLabel(EmployeHoraireInterface);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(30, 220, 121, 16));
        label_4 = new QLabel(EmployeHoraireInterface);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(30, 400, 131, 16));
        label_5 = new QLabel(EmployeHoraireInterface);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(30, 460, 111, 16));
        label_6 = new QLabel(EmployeHoraireInterface);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(30, 520, 121, 16));
        nom = new QLineEdit(EmployeHoraireInterface);
        nom->setObjectName(QString::fromUtf8("nom"));
        nom->setGeometry(QRect(220, 10, 431, 28));
        prenom = new QLineEdit(EmployeHoraireInterface);
        prenom->setObjectName(QString::fromUtf8("prenom"));
        prenom->setGeometry(QRect(220, 60, 431, 28));
        dateNaissance = new QCalendarWidget(EmployeHoraireInterface);
        dateNaissance->setObjectName(QString::fromUtf8("dateNaissance"));
        dateNaissance->setGeometry(QRect(220, 120, 432, 194));
        code = new QSpinBox(EmployeHoraireInterface);
        code->setObjectName(QString::fromUtf8("code"));
        code->setGeometry(QRect(220, 390, 81, 26));
        taux = new QDoubleSpinBox(EmployeHoraireInterface);
        taux->setObjectName(QString::fromUtf8("taux"));
        taux->setGeometry(QRect(220, 450, 81, 26));
        heure = new QDoubleSpinBox(EmployeHoraireInterface);
        heure->setObjectName(QString::fromUtf8("heure"));
        heure->setGeometry(QRect(220, 510, 81, 26));

        retranslateUi(EmployeHoraireInterface);
        QObject::connect(ok, SIGNAL(clicked()), EmployeHoraireInterface, SLOT(valideEnregistrement()));

        QMetaObject::connectSlotsByName(EmployeHoraireInterface);
    } // setupUi

    void retranslateUi(QDialog *EmployeHoraireInterface)
    {
        EmployeHoraireInterface->setWindowTitle(QApplication::translate("EmployeHoraireInterface", "EmployeHoraireInterface", nullptr));
        ok->setText(QApplication::translate("EmployeHoraireInterface", "OK", nullptr));
        label->setText(QApplication::translate("EmployeHoraireInterface", "Nom :", nullptr));
        label_2->setText(QApplication::translate("EmployeHoraireInterface", "Prenom :", nullptr));
        label_3->setText(QApplication::translate("EmployeHoraireInterface", "Date de naissance :", nullptr));
        label_4->setText(QApplication::translate("EmployeHoraireInterface", "Code departement :", nullptr));
        label_5->setText(QApplication::translate("EmployeHoraireInterface", "Taux horaire :", nullptr));
        label_6->setText(QApplication::translate("EmployeHoraireInterface", "Nombre d'heure :", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EmployeHoraireInterface: public Ui_EmployeHoraireInterface {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EMPLOYEHORAIREINTERFACE_H
