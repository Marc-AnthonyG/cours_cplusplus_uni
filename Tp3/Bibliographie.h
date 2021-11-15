/**
 * \file Bibliographie.h
 * \brief Declaration de la classe Bibliographie
 * \author Marc-Anthony Girard
 * \date 14 novembre 2021
 */


#ifndef BIBLIOGRAPHIE_H
#define BIBLIOGRAPHIE_H

#include "Reference.h"
#include <vector>
#include <string>

namespace biblio
{

  class Bibliographie
  {
  public:
    Bibliographie (std::string p_nom);
    void ajouterReference (const Reference& p_nouvelleReference);
    const std::string reqBibliographieFormate () const;
    ~Bibliographie ();
    bool operator= (const Bibliographie& p_bibliographie) const;

  private:
    std::string m_nom;
    std::vector<Reference*> m_vReferences;
    bool referenceEstDejaPresente (const std::string& p_identifiant) const;
    void verifieInvariant () const;

  };
}
#endif /* BIBLIOGRAPHIE_H */

