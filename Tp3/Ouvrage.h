/**
 * \file Ouvrage.h
 * \brief Declaration de la classe Ouvrage
 * \author Marc-Anthony Girard
 * \date 14 novembre 2021, 10:47
 */

/**
 * \class Ouvrage
 * \brief Classe Ouvrage permettant de modéliser des références d'ouvrage. Cette classe decoule de la classe reference et implante ses propres attribut soit le nom de l'editeur et de la ville d'edition.
 *
 * Note contract!!!
 * Le  nom  de  l'éditeur ainsi que la ville de publication de l’ouvrage  doit être valide suivant selon la méthode validerFormatNom de la bibliothèque validationFormat.h
 *
 * L'identifiant doit etre un code ISBN.
 */

#ifndef OUVRAGE_H
#define OUVRAGE_H
#include <string>
#include "Reference.h"
namespace biblio
{

  class Ouvrage : public Reference
  {
  public:

    Ouvrage (const std::string& p_auteurs, const std::string& p_titre, int p_annee, const std::string& p_identifiant, const std::string& p_editeur, const std::string& p_ville);
    virtual const std::string reqReferenceFormate () const;
    virtual Reference* clone () const;
    const std::string& reqEditeur () const;
    const std::string& reqVille () const;


  private:
    std::string m_editeur; //valider nom comfirme sa validite
    std::string m_ville; //validernom =s valide
    //identifiant de reference doit etre isbn
    virtual void verifieInvariant () const;
  };
}
#endif /* OUVRAGE_H */

