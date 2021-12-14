/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   EmployeCommisInterface.cpp
 * Author: etudiant
 *
 * Created on 15 novembre 2021, 21:22
 */

#include "EmployeCommisInterface.h"
#include "QMessageBox"


EmployeCommisInterface::EmployeCommisInterface ()
{
  widget.setupUi (this);
}


EmployeCommisInterface::~EmployeCommisInterface () { }


QString
EmployeCommisInterface::reqNom ()const
{
  return widget.nom->text ();
}


QString
EmployeCommisInterface::reqPrenom ()const
{
  return widget.prenom->text ();
}


util::Date
EmployeCommisInterface::reqDateNaissance ()const
{
  return m_dateNaissance;
}


int
EmployeCommisInterface::reqCodeDepartement ()const
{
  return widget.code->value ();
}


double
EmployeCommisInterface::reqSalaire ()const
{
  return widget.salaire->value ();
}


double
EmployeCommisInterface::reqCommission ()const
{
  return widget.commission->value ();
}


int
EmployeCommisInterface::reqQuantite ()const
{
  return widget.quantite->value ();
}


void
EmployeCommisInterface::valideEnregistrement ()
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
  if (reqSalaire () <= 0)
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
  if (reqCodeDepartement () <= 0)
    {
      QString message ("Le code de departement doit etre positif.");
      QMessageBox::information (this, "ERREUR", message);
      return;
    }
  accept ();

}