/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   EmployePatronInterface.cpp
 * Author: etudiant
 *
 * Created on 18 novembre 2021, 12:44
 */

#include "EmployePatronInterface.h"
#include <QMessageBox>


EmployePatronInterface::EmployePatronInterface ()
{
  widget.setupUi (this);
}


EmployePatronInterface::~EmployePatronInterface () { }


QString
EmployePatronInterface::reqNom ()const
{
  return widget.nom->text ();
}


QString
EmployePatronInterface::reqPrenom ()const
{
  return widget.prenom->text ();
}


util::Date
EmployePatronInterface::reqDateNaissance ()const
{
  return m_dateNaissance;
}


int
EmployePatronInterface::reqCodeDepartement ()const
{
  return widget.code->value ();
}


double
EmployePatronInterface::reqSalaireHebdo ()const
{
  return widget.salaire->value ();
}


void
EmployePatronInterface::valideEnregistrement ()
{
  if (reqNom ().isEmpty ())
    {
      QString message ("Le nom ne doit pas etre vide.");
      QMessageBox::information (this, "ERREUR", message);
      return;
    }


  if (reqPrenom ().isEmpty ())
    {
      QString message ("Le prenom ne doit pas etre vide.");
      QMessageBox::information (this, "ERREUR", message);
      return;
    }
  if (reqSalaireHebdo () <= 0)
    {
      QString message ("Le salaire doit etre positif.");
      QMessageBox::information (this, "ERREUR", message);
      return;
    }
  if (reqCodeDepartement () <= 0)
    {
      QString message ("Le code de departement doit etre positif.");
      QMessageBox::information (this, "ERREUR", message);
      return;
    }
  QDate  dateCourant = QDate::currentDate ();
  if (widget.dateNaissance->selectedDate () >= dateCourant)
    {
      QString message ("la date doit etre correct.");
      QMessageBox::information (this, "ERREUR", message);
      return;
    }
  else
    {
      int jour = widget.dateNaissance->selectedDate ().day ();
      int mois = widget.dateNaissance->selectedDate ().month ();
      int annee = widget.dateNaissance->selectedDate ().year ();
      m_dateNaissance.asgDate (jour, mois, annee);
    }
  accept ();

}