/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   EmployeHoraireInterface.h
 * Author: etudiant
 *
 * Created on 17 novembre 2021, 13:08
 */

#ifndef _EMPLOYEHORAIREINTERFACE_H
#define _EMPLOYEHORAIREINTERFACE_H

#include "ui_EmployeHoraireInterface.h"
#include "Date.h"

class EmployeHoraireInterface : public QDialog
{
  Q_OBJECT
public:
  EmployeHoraireInterface ();
  virtual ~EmployeHoraireInterface ();

  QString reqNom ()const;
  QString reqPrenom ()const;
  util::Date reqDateNaissance ()const;
  int reqCodeDepartement ()const;
  double reqTauxHoraire ()const;
  double reqHeure ()const;


private slots:
  void valideEnregistrement ();




private:
  Ui::EmployeHoraireInterface widget;
  util::Date m_dateNaissance;
};

#endif /* _EMPLOYEHORAIREINTERFACE_H */
