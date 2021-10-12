/**
 * \file Reference.cpp
 * \brief Implementation de la classe Reference
 * \author Marc-Anthony Girard
 * \date 29 septembre 2021
 */

#include "Reference.h"
#include <string>
#include<iostream>
#include <sstream>

using namespace biblio;


/**
 * \brief Constructeur avec paramètres.
 *
 * Les paramètres sont l'auteur, le titre, l'année ainsi qu'un identifiant ISBN ou ISSN.
 * \param[in] p_auteur Nom et prenom de l'auteur ou du premier auteur de la publication. Il doit être non vide, doit être composé que de lettres, mais les espaces et les tirets ‘-‘ sont permis s’ils ne sont pas doublés; deux (ou plus) espaces ou ‘-‘ consécutifs; un tiret ne pouvant pas être suivi d’un espace et inversement.
 * \param[in] p_titre Titre de la publication. Le titre doit être non vide et peut comporter des espaces.
 * \param[in] p_annee Année de publication. Pourra être changer. Elle doit être strictement plus grande que 0
 * \param[in] p_identifiant Identifiant ISBN ou ISSN de la publication. Les codes doivent être valide suivant selon la méthode validerCodeIsbn ou validerCodeIssn de la bibliothèque validationFormat.h
 */
Reference::Reference (const std::string& p_auteur, const std::string& p_titre, int p_annee, const std::string& p_identifiant) : m_auteurs (p_auteur), m_titre (p_titre), m_annee (p_annee), m_identifiant (p_identifiant) { }


/**
 * \brief Méthode permettant d'avoir accès au nom de l'auteur de la publication.
 * \return La référence de la string non modifiable contenant le nom de l'auteur.
 */
const std::string&
Reference::reqAuteur () const
{
  return m_auteurs;
}


/**
 * \brief Méthode permettant d'avoir accès au nom titre de la publication.
 * \return La référence de la string non modifiable contenant le titre de la publication.
 */
const std::string&
Reference::reqTitre () const
{
  return m_titre;
}


/**
 * \brief Méthode permettant d'avoir accès à l'année de publication.
 * \return Un entier contenant l'année de la référence.
 */
int
Reference::reqAnnee () const
{
  return m_annee;
}


/**
 * \brief Méthode permettant d'avoir accès à l'identification de la publication.
 * \return La référence de la string non modifiable contenant l'identification de la publication.
 */
const std::string&
Reference::reqIdentifiant () const
{
  return m_identifiant;
}


/**
 * \brief Méthode permettant de changer l'année de la publication.
 * \param[in] p_annee Nouvel année de publication de la publication.
 */
void
Reference::asgAnnee (int p_annee)
{
  if (p_annee > 0) m_annee = p_annee;
}


/**
 * \brief Méthode permettant d'optenir une chaine de caractères qui contient l'information de l'objet Référence.
 * \return Une chaine de caractères avec l'information de la référence.
 */
const std::string
Reference::reqReferenceFormate () const
{
  std::ostringstream oss;
  std::string separateur = ", ";
  oss << m_auteurs << separateur << m_titre << separateur << m_annee << separateur << m_identifiant << "." << std::endl;
  return oss.str ();
}


/**
 * \brief Surcharge de l'opérateur égale (==) afin de déterminer si deux références sont égale.
 * \param[in] p_Reference La référence qui sera comparé à l'objet courant.
 * \return Un booléan d'état Vrai si les deux références sont en tous points pareils. (même auteur, année, identifiant et titre)
 */
bool Reference::operator== (const Reference& p_Reference)
{
  return this->reqReferenceFormate ().compare (p_Reference.reqReferenceFormate ());
}