/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   EmployeInterface.cpp
 * Author: etudiant
 *
 * Created on 15 novembre 2021, 21:03
 */

#include "EmployeInterface.h"
#include "EmployeCommisInterface.h"
#include "EmployeHoraireInterface.h"
#include "EmployePatronInterface.h"
#include "EmployeCommission.h"
#include "EmployeHoraire.h"
#include "Patron.h"
#include <sstream>



using namespace labo10;
using namespace std;


EmployeInterface::EmployeInterface ()
{
  widget.setupUi (this);
}


EmployeInterface::~EmployeInterface ()
{
  for (size_t i = 0; i < m_vEmploye.size (); i++)
    {
      delete m_vEmploye[i];
    }

}


void
EmployeInterface::ajouteEmployeCommission (const std::string& p_nom, const std::string& p_prenom,
                                           const util::Date& p_dateNaissance, int p_codeDepartement,
                                           double p_salaire, double p_commission, int p_quantite)
{
  EmployeCommission employeCom (p_nom, p_prenom, p_dateNaissance, p_codeDepartement,
                                p_salaire, p_commission, p_quantite);


  m_vEmploye.push_back (new EmployeCommission (employeCom)); // ajout de l'employé dans le vector


}


void
EmployeInterface::ajouteEmployeHoraire (const std::string& p_nom, const std::string& p_prenom,
                                        const util::Date& p_dateNaissance, int p_codeDepartement,
                                        double p_tauxHoraire, double p_heures)
{
  EmployeHoraire employeHoraire (p_nom, p_prenom, p_dateNaissance, p_codeDepartement,
                                 p_tauxHoraire, p_heures);


  m_vEmploye.push_back (new EmployeHoraire (employeHoraire)); // ajout de l'employé dans le vector


}


void
EmployeInterface::ajouteEmployePatron (const std::string& p_nom, const std::string& p_prenom,
                                       const util::Date& p_dateNaissance, int p_codeDepartement,
                                       double p_salaireHebdo)
{
  Patron employePatron (p_nom, p_prenom, p_dateNaissance, p_codeDepartement,
                        p_salaireHebdo);


  m_vEmploye.push_back (new Patron (employePatron)); // ajout de l'employé dans le vector


}


std::string
EmployeInterface::reqListeFormate ()const
{
  ostringstream os;
  os << "Liste des employes : " << endl;
  os << "------------------------------------------------------------------" << endl;
  for (size_t i = 0; i < m_vEmploye.size (); i++)
    {
      os << m_vEmploye[i]->reqEmployeFormate ();
      os << "------------------------------------------------------------------" << endl;
    }
  return os.str ();
}


void
EmployeInterface::dialogCommis ()
{
  EmployeCommisInterface Commis;
  if (Commis.exec ())
    {
      ajouteEmployeCommission (Commis.reqNom ().toStdString (),
                               Commis.reqPrenom ().toStdString (),
                               Commis.reqDateNaissance (),
                               Commis.reqCodeDepartement (),
                               Commis.reqSalaire (),
                               Commis.reqCommission (),
                               Commis.reqQuantite ());
      widget.affichage->setText (reqListeFormate ().c_str ());
    }
}


void
EmployeInterface::dialogHoraire ()
{
  EmployeHoraireInterface Horaire;
  if (Horaire.exec ())
    {
      ajouteEmployeHoraire    (Horaire.reqNom ().toStdString (),
                               Horaire.reqPrenom ().toStdString (),
                               Horaire.reqDateNaissance (),
                               Horaire.reqCodeDepartement (),
                               Horaire.reqTauxHoraire (),
                               Horaire.reqHeure ());
      widget.affichage->setText (reqListeFormate ().c_str ());
    }
}


void
EmployeInterface::dialogPatron ()
{
  EmployePatronInterface Patron;
  if (Patron.exec ())
    {
      ajouteEmployePatron     (Patron.reqNom ().toStdString (),
                               Patron.reqPrenom ().toStdString (),
                               Patron.reqDateNaissance (),
                               Patron.reqCodeDepartement (),
                               Patron.reqSalaireHebdo ());
      widget.affichage->setText (reqListeFormate ().c_str ());
    }
}