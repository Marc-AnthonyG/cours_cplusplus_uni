
/**
 * \file Journal.cpp
 * \brief Implementation de la classe Journal
 * \author Marc-Anthony Girard
 * \date 14 novembre 2021, 11:30
 */

#include "Journal.h"
#include "Reference.h"
#include "ContratException.h"
#include "validationFormat.h"
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
 * \param[in] p_identifiant Identifiant ISSN de la publication. Le code doit être valide suivant la méthode validerCodeIssn de la bibliothèque validationFormat.h
 * \param[in] p_nom Nom du journal. Le nom doit être non vide et peut comporter des espaces et des chiffres.
 * \param[in] p_volume Numero du volume.
 * \param[in] p_numero Numero de quelque chose.
 * \param[in] p_page Page du volume ou debute la reference.
 */
Journal::Journal (const std::string& p_auteurs, const std::string& p_titre, int p_annee, const std::string& p_identifiant, const std::string& p_nom, int p_volume, int p_numero, int p_page) : Reference (p_auteurs, p_titre, p_annee, p_identifiant), m_nom (p_nom), m_volume (p_volume), m_numero (p_numero), m_page (p_page)
{
  PRECONDITION (util::validerCodeIssn (p_identifiant));
  PRECONDITION (!p_nom.empty ());
  PRECONDITION (p_volume > 0);
  PRECONDITION (p_numero > 0);
  PRECONDITION (p_page > 0);

  POSTCONDITION (m_nom == p_nom);
  POSTCONDITION (m_volume == p_volume);
  POSTCONDITION (m_numero == p_numero);
  POSTCONDITION (m_page == p_page);


  INVARIANTS ();
}


/**
 * \brief Méthode permettant d'avoir accès au nom du journal
 * \return La référence de la string non modifiable contenant le nom du journal.
 */
const std::string&
Journal::reqNom () const
{
  return m_nom;
}


/**
 * \brief Méthode permettant d'avoir accès au numero du volume.
 * \return Le numero du volume.
 */
int
Journal::reqVolume () const
{
  return m_volume;
}


/**
 * \brief Méthode permettant d'avoir accès au numero de publication.
 * \return Le numero de publication.
 */
int
Journal::reqNumero () const
{
  return m_numero;
}


/**
 * \brief Méthode permettant d'avoir accès a la page ou commence la reference.
 * \return La page ou commence la reference.
 */
int
Journal::reqPage () const
{
  return m_page;
}


/**
 * \brief Méthode permettant d'obtenir une chaine de caracteres qui contient l'information de l'objet Journal.
 * \return Une chaine de caracteres avec l'information du Journal.
 */
const std::string
Journal::reqReferenceFormate () const
{
  std::ostringstream oss;
  std::string sep = ". ";
  oss << reqAuteur () << sep << reqTitre () << sep << m_nom << ", vol" << sep << m_volume << ", no" << sep << m_numero << ", pp" << sep << m_page << ", " << reqAnnee () << sep << reqIdentifiant () << sep;
  return oss.str ();
}


/**
 * \brief Méthode permettant de creer des clones du Journal courant.
 * \return Un pointeur d'une copie du Journal dans l'espace memoire du monceau.
 */
Reference*
Journal::clone () const
{
  return new Journal (*this);
}


/**
 * \brief Méthode permettant de verifier les invariants de la classe Ouvrage
 */
void
Journal::verifieInvariant () const
{
  INVARIANT (util::validerFormatNom (Reference::reqAuteur ()));
  INVARIANT (util::validerCodeIssn (Reference::reqIdentifiant ()));
  INVARIANT (!Reference::reqTitre ().empty ());
  INVARIANT (Reference::reqAnnee () > 0);
  INVARIANT (!m_nom.empty ());
  INVARIANT (m_volume > 0);
  INVARIANT (m_numero > 0);
  INVARIANT (m_page > 0);
}