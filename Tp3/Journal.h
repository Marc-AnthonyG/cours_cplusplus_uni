/**
 * \file Journal.h
 * \brief Definition de la classe Journal
 * \author Marc-Anthony Girard
 * \date 14 novembre 2021, 10:35
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
    //CODE ISSN

  };
}
#endif /* JOURNAL_H */
