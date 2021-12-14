/********************************************************************************
** Form generated from reading UI file 'EmployeCommisInterface.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EMPLOYECOMMISINTERFACE_H
#define UI_EMPLOYECOMMISINTERFACE_H

#include <QtCore/QDate>
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

class Ui_EmployeCommisInterface
{
public:
    QPushButton *ok;
    QLabel *label;
    QLineEdit *nom;
    QLabel *label_2;
    QLineEdit *prenom;
    QLabel *label_3;
    QCalendarWidget *dateNaissance;
    QLabel *label_4;
    QSpinBox *code;
    QLabel *label_5;
    QDoubleSpinBox *salaire;
    QLabel *label_6;
    QLabel *label_7;
    QDoubleSpinBox *commission;
    QSpinBox *quantite;

    void setupUi(QDialog *EmployeCommisInterface)
    {
        if (EmployeCommisInterface->objectName().isEmpty())
            EmployeCommisInterface->setObjectName(QString::fromUtf8("EmployeCommisInterface"));
        EmployeCommisInterface->resize(764, 596);
        ok = new QPushButton(EmployeCommisInterface);
        ok->setObjectName(QString::fromUtf8("ok"));
        ok->setGeometry(QRect(310, 550, 90, 28));
        label = new QLabel(EmployeCommisInterface);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 30, 58, 16));
        nom = new QLineEdit(EmployeCommisInterface);
        nom->setObjectName(QString::fromUtf8("nom"));
        nom->setGeometry(QRect(190, 20, 461, 28));
        label_2 = new QLabel(EmployeCommisInterface);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 80, 58, 16));
        prenom = new QLineEdit(EmployeCommisInterface);
        prenom->setObjectName(QString::fromUtf8("prenom"));
        prenom->setGeometry(QRect(190, 70, 461, 28));
        label_3 = new QLabel(EmployeCommisInterface);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 210, 121, 16));
        dateNaissance = new QCalendarWidget(EmployeCommisInterface);
        dateNaissance->setObjectName(QString::fromUtf8("dateNaissance"));
        dateNaissance->setGeometry(QRect(190, 120, 432, 194));
        dateNaissance->setMinimumDate(QDate(1970, 1, 1));
        dateNaissance->setMaximumDate(QDate(2030, 12, 31));
        label_4 = new QLabel(EmployeCommisInterface);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 370, 141, 16));
        code = new QSpinBox(EmployeCommisInterface);
        code->setObjectName(QString::fromUtf8("code"));
        code->setGeometry(QRect(200, 370, 61, 26));
        label_5 = new QLabel(EmployeCommisInterface);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(20, 420, 58, 16));
        salaire = new QDoubleSpinBox(EmployeCommisInterface);
        salaire->setObjectName(QString::fromUtf8("salaire"));
        salaire->setGeometry(QRect(200, 410, 64, 26));
        label_6 = new QLabel(EmployeCommisInterface);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(20, 460, 91, 16));
        label_7 = new QLabel(EmployeCommisInterface);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(20, 500, 58, 16));
        commission = new QDoubleSpinBox(EmployeCommisInterface);
        commission->setObjectName(QString::fromUtf8("commission"));
        commission->setGeometry(QRect(200, 460, 64, 26));
        quantite = new QSpinBox(EmployeCommisInterface);
        quantite->setObjectName(QString::fromUtf8("quantite"));
        quantite->setGeometry(QRect(200, 500, 61, 26));

        retranslateUi(EmployeCommisInterface);
        QObject::connect(ok, SIGNAL(clicked()), EmployeCommisInterface, SLOT(valideEnregistrement()));

        QMetaObject::connectSlotsByName(EmployeCommisInterface);
    } // setupUi

    void retranslateUi(QDialog *EmployeCommisInterface)
    {
        EmployeCommisInterface->setWindowTitle(QApplication::translate("EmployeCommisInterface", "EmployeCommisInterface", nullptr));
        ok->setText(QApplication::translate("EmployeCommisInterface", "OK", nullptr));
        label->setText(QApplication::translate("EmployeCommisInterface", "Nom :", nullptr));
        label_2->setText(QApplication::translate("EmployeCommisInterface", "Prenom :", nullptr));
        label_3->setText(QApplication::translate("EmployeCommisInterface", "Date de naissance :", nullptr));
        label_4->setText(QApplication::translate("EmployeCommisInterface", "Code de departement :", nullptr));
        label_5->setText(QApplication::translate("EmployeCommisInterface", "Salaire :", nullptr));
        label_6->setText(QApplication::translate("EmployeCommisInterface", "Commission :", nullptr));
        label_7->setText(QApplication::translate("EmployeCommisInterface", "Quantite :", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EmployeCommisInterface: public Ui_EmployeCommisInterface {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EMPLOYECOMMISINTERFACE_H
