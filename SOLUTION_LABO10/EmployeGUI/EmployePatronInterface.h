/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   EmployePatronInterface.h
 * Author: etudiant
 *
 * Created on 18 novembre 2021, 12:44
 */

#ifndef _EMPLOYEPATRONINTERFACE_H
#define _EMPLOYEPATRONINTERFACE_H

#include "ui_EmployePatronInterface.h"
#include "Date.h"

class EmployePatronInterface : public QDialog
{
  Q_OBJECT
public:
  EmployePatronInterface ();
  virtual ~EmployePatronInterface ();

  QString reqNom ()const;
  QString reqPrenom ()const;
  util::Date reqDateNaissance ()const;
  int reqCodeDepartement ()const;
  double reqSalaireHebdo ()const;

private slots:
  void valideEnregistrement ();

private:
  Ui::EmployePatronInterface widget;
  util::Date m_dateNaissance;
};

#endif /* _EMPLOYEPATRONINTERFACE_H */
