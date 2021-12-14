/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   EmployeCommisInterface.h
 * Author: etudiant
 *
 * Created on 15 novembre 2021, 21:22
 */

#ifndef _EMPLOYECOMMISINTERFACE_H
#define _EMPLOYECOMMISINTERFACE_H

#include "ui_EmployeCommisInterface.h"
#include "Date.h"

class EmployeCommisInterface : public QDialog
{
  Q_OBJECT
public:
  EmployeCommisInterface ();
  virtual ~EmployeCommisInterface ();

  QString reqNom ()const;
  QString reqPrenom ()const;
  util::Date reqDateNaissance ()const;
  int reqCodeDepartement ()const;
  double reqSalaire ()const;
  double reqCommission ()const;
  int reqQuantite ()const;

private slots:
  void valideEnregistrement ();



private:
  Ui::EmployeCommisInterface widget;
  util::Date m_dateNaissance;
};

#endif /* _EMPLOYECOMMISINTERFACE_H */
