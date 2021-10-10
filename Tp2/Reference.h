/**
 * \file Reference.h
 * \brief Prototype de la classe Reference
 * \author Marc-Anthony Girard
 * \date 29 septembere 2021
 */

#ifndef REFERENCE_H
#define REFERENCE_H

#include <string>

/**
 * \class Reference
 * \brief Classe Reference permettant de modéliser des références de livre composé d'un auteur, d'un titre, d'une année ainsi que d'un indentifiant ISBN ou ISSN.
 */
class Reference
{
public:
  Reference (std::string p_auteur, std::string p_titre, int p_annee, std::string p_identifiant);

  const std::string& reqAuteur () const;
  const std::string& reqTitre () const;
  int reqAnnee () const;
  const std::string& reqIdentifiant () const;
  void asgAnnee (int p_annee);
  std::string& reqReferenceFormate () const;
  bool operator== (const Reference& p_Reference);

private:
  std::string m_auteurs;
  std::string m_titre;
  int m_annee;
  std::string m_identifiant;
};

#endif /* REFERENCE_H */
