/**
 * \file Ouvrage.cpp
 * \brief Implementation de la classe Ouvrage
 * \author Marc-Anthony Girard
 * \date 14 novembre 2021, 11:10
 */

#include "Ouvrage.h"
#include "Reference.h"
#include <string>
#include <iostream>
#include <sstream>

using namespace biblio;


/**
 * \brief Constructeur avec paramètres.
 *
 * Les paramètres sont l'auteur, le titre, l'année l'identifiant ISBN, l'editeur et la ville.
 * \param[in] p_auteurs Nom et prenom de l'auteur ou du premier auteur de la publication. Il doit être non vide, doit être composé que de lettres, mais les espaces et les tirets ‘-‘ sont permis s’ils ne sont pas doublés; deux (ou plus) espaces ou ‘-‘ consécutifs; un tiret ne pouvant pas être suivi d’un espace et inversement.
 * \param[in] p_titre Titre de la publication. Le titre doit être non vide et peut comporter des espaces.
 * \param[in] p_annee Année de publication. Pourra être changer. Elle doit être strictement plus grande que 0
 * \param[in] p_identifiant Identifiant ISBN ou ISSN de la publication. Les codes doivent être valide suivant selon les méthodes validerCodeIsbn ou validerCodeIssn de la bibliothèque validationFormat.h
 *
 * \param[in] p_editeur. Editeur de la publication. le  nom  de  l'éditeur  de l’ouvrage  doit être valide suivant selon la méthode validerFormatNom de la bibliothèque validationFormat.h
 *
 *  \param[in] p_ville. Ville de la publication. La ville de publication de l’ouvrage  doit être valide suivant selon la méthode validerFormatNom de la bibliothèque validationFormat.h
 */
Ouvrage::Ouvrage (const std::string& p_auteurs, const std::string& p_titre, int p_annee, const std::string& p_identifiant, const std::string& p_editeur, const std::string& p_ville) : Reference (p_auteurs, p_titre, p_annee, p_identifiant), m_editeur (p_editeur), m_ville (p_ville) { }


/**
 * \brief Méthode permettant d'avoir accès a la ville de la publication.
 * \return La référence de la string non modifiable contenant la ville de publicaiton.
 */
const std::string&
Ouvrage::reqVille () const
{
  return m_ville;
}


/**
 * \brief Méthode permettant d'avoir accès a l'editeur de la publication.
 * \return La référence de la string non modifiable contenant l'editeur de la publication.
 */
const std::string&
Ouvrage::reqEditeur () const
{
  return m_editeur;
}


/**
 * \brief Méthode permettant d'obtenir une chaine de caracteres qui contient l'information de l'objet Ouvrage.
 * \return Une chaine de caracteres avec l'information de l'Ouvrage.
 */
const std::string
Ouvrage::reqReferenceFormate () const
{
  std::ostringstream oss;
  std::string sep = ". ";
  oss << reqAuteur () << sep << reqTitre () << sep << m_ville << " : " << m_editeur << ", " << reqAnnee () << sep << reqIdentifiant () << sep;
  return oss.str ();
}


/**
 * \brief Méthode permettant de creer des clones de l'Ouvrage courant.
 * \return Un pointeur d'une copie de l'Ouvrage dans l'espace memoire du monceau.
 */
Reference*
Ouvrage::clone () const
{
  return new Ouvrage (*this);
}