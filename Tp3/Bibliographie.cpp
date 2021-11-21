/**
 * \file Bibliographie.cpp
 * \brief Implementation de la classe Bibliographie
 * \author Marc-Anthony Girard
 * \date 14 novembre 2021
 */

#include "Reference.h"
#include "Bibliographie.h"
#include "ContratException.h"
#include "validationFormat.h"
#include <vector>
#include <string>
#include <iostream>
#include <sstream>

using namespace biblio;


/**
 * \brief Constructeur avec paramètres.
 *
 * Le paramètre est le nom de la bibliographie.
 * \param[in] p_nom. Le nom de la bibliographie. Il ne doit pas etre.
 */
Bibliographie::Bibliographie (std::string p_nom) : m_nom (p_nom)
{
  PRECONDITION (!p_nom.empty ());
  m_vReferences = {};
  POSTCONDITION (m_nom == p_nom);
  POSTCONDITION (m_vReferences.empty ());

  INVARIANTS ();
}


const std::string&
Bibliographie::reqNom () const
{
  return m_nom;
}


bool
Bibliographie::referenceEstDejaPresente (const std::string& p_identifiant) const
{
  bool isThere = false;
  for (int i = 0; i < m_vReferences.size () && !isThere; i++)
    {
      Reference* temp = m_vReferences[i];
      isThere = p_identifiant == temp->reqIdentifiant ();
    }
  return isThere;
}


void
Bibliographie::ajouterReference (const Reference& p_nouvelleReference)
{
  m_vReferences.push_back (p_nouvelleReference.clone ());
  POSTCONDITION (p_nouvelleReference.reqReferenceFormate () == m_vReferences[m_vReferences.size () - 1]->reqReferenceFormate ());
  INVARIANTS ();
}


const std::string
Bibliographie::reqBibliographieFormate () const
{
  std::ostringstream oss;
  oss << m_nom << "\n===============================";
  for (int i = 0; i < m_vReferences.size (); i++)
    {
      oss << "[" << i << "] " << m_vReferences[i]->reqReferenceFormate ();
    }
  return oss.str ();
}


Bibliographie::~Bibliographie ()
{
  for (int i = 0; i < m_vReferences.size (); i++)
    {
      delete m_vReferences[i];
    }
  POSTCONDITION (m_vReferences.empty ());
  INVARIANTS ();
}


void
Bibliographie::verifieInvariant () const
{
  INVARIANT (m_nom.empty ());
}


bool Bibliographie::operator= (const Bibliographie & p_bibliographie) const
{
  return reqBibliographieFormate () == p_bibliographie.reqBibliographieFormate ();
}


const std::vector<Reference*>
Bibliographie::reqVReferences () const
{
  return m_vReferences;
}

/*
Bibliographie::Bibliographie (const Bibliographie& p_bibliographie)
{
  Bibliographie* temp = new Bibliographie (p_bibliographie.reqNom ());
  for (int i = 0; i < *p_bibliographie.reqVReferences ().size (); i++)
    {
 *temp->ajouterReference (*p_bibliographie.reqVReferences ()[i]);
    }
}*/
