/**
 * \file Bibliographie.h
 * \brief Declaration de la classe Bibliographie
 * \author Marc-Anthony Girard
 * \date 14 novembre 2021
 */

/**
 * \class Bibliographie
 * \brief Classe Bibliographie permettant de modéliser une liste de reference. Celle-ci possede aussi un nom.
 *
 * Note contract!!!
 * Le nom ne doit pas etre vide.
 */s
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

    const std::string& reqNom () const;
    const std::vector<Reference*> reqVReferences () const;

    ~Bibliographie ();

    bool operator= (const Bibliographie& p_bibliographie) const;

    Bibliographie (const Bibliographie& p_bibliographie);

  private:
    std::string m_nom;

    std::vector<Reference*> m_vReferences;

    bool referenceEstDejaPresente (const std::string& p_identifiant) const;

    void verifieInvariant () const;

  };
}
#endif /* BIBLIOGRAPHIE_H */

