/**
 * \file Reference.h
 * \brief Prototype de la classe Reference
 * \author Marc-Anthony Girard
 * \date 29 septembere 2021
 */

#ifndef REFERENCE_H
#define REFERENCE_H

#include <string>
#include "validationFormat.h"

/**
 * \class Reference
 * \brief Classe Reference permettant de modéliser des références de livre composé d'un auteur, d'un titre, d'une année ainsi que d'un indentifiant ISBN ou ISSN.
 *
 *  * Note contract!!!
 * Le nom et prenom de l'auteur ou du premier auteur de la publication doit être non vide, doit être composé que de lettres, mais les espaces et les tirets ‘-‘ sont permis s’ils ne sont pas doublés; deux (ou plus) espaces ou ‘-‘ consécutifs; un tiret ne pouvant pas être suivi d’un espace et inversement.
 * Le titre de la publication doit être non vide et peut comporter des espaces.
 * L'annee de publication pourra être changer et elle doit être strictement plus grande que 0
 * L'identifiant ISBN ou ISSN de la publication doivent être valide suivant selon les méthodes validerCodeIsbn ou validerCodeIssn de la bibliothèque util::validationFormat.h
 */
namespace biblio
{

  class Reference
  {
  public:
    Reference (const std::string& p_auteurs, const std::string& p_titre, int p_annee, const std::string& p_identifiant);
    const std::string& reqAuteur () const;
    const std::string& reqTitre () const;
    int reqAnnee () const;
    const std::string& reqIdentifiant () const;
    void asgAnnee (int p_annee);
    virtual const std::string reqReferenceFormate () const = 0;
    bool operator== (const Reference& p_Reference) const;
    virtual Reference* clone () const = 0;

    virtual
    ~Reference () { };

  private:
    std::string m_auteurs;
    std::string m_titre;
    int m_annee;
    std::string m_identifiant;
    virtual void verifieInvariant () const;
  };
}
#endif /* REFERENCE_H */
