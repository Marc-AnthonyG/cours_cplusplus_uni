/**
 * \file Journal.h
 * \brief Definition de la classe Journal
 * \author Marc-Anthony Girard
 * \date 14 novembre 2021, 10:35
 */

/**
 * \class Journal
 * \brief Classe Journal permettant de modéliser des références de journaux. Cette classe decoule de la classe reference et implante ses propres attribut soit le nom de l'editeur et de la ville d'edition.
 *
 * Note contract!!!
 * Le  nom  du journal ne devrait pas etre vide. Le numero de volume, le numero d'article et le nombre de page devrait etre superieur a 0.
 *
 * L'identifiant doit etre un code ISSN.
 *
 */

#ifndef JOURNAL_H
#define JOURNAL_H
#include <string>
#include "Reference.h"

namespace biblio
{

  class Journal : public Reference
  {
  public:
    Journal (const std::string& p_auteurs, const std::string& p_titre, int p_annee, const std::string& p_identifiant, const std::string& p_nom, int p_volume, int p_numero, int p_page);
    virtual const std::string reqReferenceFormate () const;
    virtual Reference* clone () const;
    const std::string& reqNom () const;
    int reqVolume () const;
    int reqNumero () const;
    int reqPage () const;


  private:
    std::string m_nom; // pas vide
    int m_volume;
    int m_numero;
    int m_page;
    void verifieInvariant () const;
  };
}
#endif /* JOURNAL_H */
