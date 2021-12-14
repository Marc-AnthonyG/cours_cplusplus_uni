/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   EmployeHoraireInterface.cpp
 * Author: etudiant
 *
 * Created on 17 novembre 2021, 13:08
 */

#include "EmployeHoraireInterface.h"
#include "QMessageBox"


EmployeHoraireInterface::EmployeHoraireInterface ()
{
  widget.setupUi (this);
}


EmployeHoraireInterface::~EmployeHoraireInterface () { }


QString
EmployeHoraireInterface::reqNom ()const
{
  return widget.nom->text ();
}


QString
EmployeHoraireInterface::reqPrenom ()const
{
  return widget.prenom->text ();
}


util::Date
EmployeHoraireInterface::reqDateNaissance ()const
{
  return m_dateNaissance;
}


int
EmployeHoraireInterface::reqCodeDepartement ()const
{
  return widget.code->value ();
}


double
EmployeHoraireInterface::reqTauxHoraire ()const
{
  return widget.taux->value ();
}


double
EmployeHoraireInterface::reqHeure ()const
{
  return widget.heure->value ();
}


void
EmployeHoraireInterface::valideEnregistrement ()
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
  if (reqTauxHoraire () <= 0)
    {
      QString message ("Le taux horaire doit etre positif.");
      QMessageBox::information (this, "ERREUR", message);
      return;
    }
  if (reqHeure () <= 0 || reqHeure () >= 168 )
    {
      QString message ("L'heure doit etre entre 0 et 168.");
      QMessageBox::information (this, "ERREUR", message);
      return;
    }
  accept ();

}