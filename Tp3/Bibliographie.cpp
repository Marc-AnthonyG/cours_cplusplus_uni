/**
 * \file Bibliographie.cpp
 * \brief Implementation de la classe Bibliographie
 * \author Marc-Anthony Girard
 * \date 14 novembre 2021
 */

#include "Reference.h"
#include "Bibliographie.h"
#include <vector>
#include <string>
#include <iostream>
#include <sstream>

using namespace biblio;


Bibliographie::Bibliographie (std::string p_nom) : m_nom (p_nom) { }


bool
Bibliographie::referenceEstDejaPresente (const std::string& p_identifiant) const
{
  bool isThere = false;
  for (int i = 0; i < m_vReferences && !isThere; i++)
    {
      Reference* temp = m_vReferences[i];
      isThere = p_identifiant == &temp.reqIdentifiant ();
    }
  return isThere;
}


void
Bibliographie::ajouterReference (const Reference& p_nouvelleReference)
{
  m_vReferences.push_back (p_nouvelleReference.clone ());
}


const std::string
Bibliographie::reqBibliographieFormate () const
{
  std::ostringstream oss;
  oss << "Bibliographie\n===============================";
  for (int i = 0; i < m_vReferences; i++)
    {
      oss << "[" << i << "] " m_vReferences[i]->reqReferenceFormate ();
    }
  return oss.str ();
}


Bibliographie::~Bibliographie ()
{
  for (int i = 0; i < m_vReferences; i++)
    {
      delete m_vReferences;
    }
}


bool Bibliographie::operator= (const Bibliographie & p_bibliographie) const
{
  return true;
}
