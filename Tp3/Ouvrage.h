/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 * \file Ouvrage.h
 * \brief Declaration de la classe Ouvrage
 * \author Marc-Anthony Girard
 * \date 14 novembre 2021, 10:47
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
  };
}
#endif /* OUVRAGE_H */

