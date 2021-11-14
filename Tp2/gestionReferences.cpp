/**
 * \file gestionReferences.cpp
 * \brief Programme test pour la classe référence et validationFormat
 * \author Marc-Anthony Girard
 * \date 11 octobre 2021
 */

#include <string>
#include "validationFormat.h"
#include "Reference.h"
#include <iostream>


using namespace std;


//ISBN 978-2-7605-5379-8


int
saisirAnnee ()
{
  bool valeurCorrecte = false;
  int m_anneeDePublicaiton;

  do
    {
      cout << "Saisissez l'année de publication (Strictement plus grande que 0)" << endl;
      cin >> m_anneeDePublicaiton;
      if (m_anneeDePublicaiton > 0)
        {
          valeurCorrecte = true;
        }
    }
  while (!valeurCorrecte);
  return m_anneeDePublicaiton;
}


int
main ()
{
  bool valeurCorrecte = false;
  string nomAuteur;
  do
    {
      cout << "Saisissez le nom de l'auteur ou si il y en a plusieurs le premier" << endl;
      getline (std::cin, nomAuteur);
      if (util::validerFormatNom (nomAuteur))
        {
          valeurCorrecte = true;
        }
    }
  while (!valeurCorrecte);
  cout << endl << endl;


  valeurCorrecte = false;
  string titre;
  do
    {
      cout << "Saisissez le titre de la publication. Le titre ne peut pas etre vide" << endl;
      getline (std::cin, titre);
      if (!titre.empty ())
        {
          valeurCorrecte = true;
        }
    }
  while (!valeurCorrecte);

  cout << endl << endl;


  valeurCorrecte = false;
  string code;
  do
    {
      cout << "Saisissez le code ISBN ou ISSN" << endl;
      getline (std::cin, code);
      if (util::validerCodeIssn (code) || util::validerCodeIsbn (code))
        {
          valeurCorrecte = true;
        }
    }
  while (!valeurCorrecte);

  cout << endl << endl;


  int annee = saisirAnnee ();
  cout << endl << endl;

  biblio::Reference ref (nomAuteur, titre, annee, code);
  cout <<  "Voici la référence formaté: \n" << ref.reqReferenceFormate () << endl;

  cout << endl << endl;
  string modifierAnnee;
  cout << "Voulez-vous modifier l'année de publication? \"oui\" ou \"non\"" << endl;
  cin >> modifierAnnee;

  cout << endl << endl;
  if (modifierAnnee.compare ("oui") == 0)
    {
      ref.asgAnnee (saisirAnnee ());
      cout << ref.reqReferenceFormate () << endl;
    }
  cout << endl << endl;
  cout << "Fin du programme!" << endl;

  return 0;
}

