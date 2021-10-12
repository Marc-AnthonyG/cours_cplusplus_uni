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


int
saisirAnnee ()
{
  bool valeurCorrecte = false;
  int m_anneeDePublicaiton;

  while (!valeurCorrecte)
    {
      cout << "Saisissez l'année de publication (Strictement plus grande que 0)" << endl;
      cin >> m_anneeDePublicaiton;
      if (m_anneeDePublicaiton > 0)
        {
          valeurCorrecte = true;
        }
    }
  return m_anneeDePublicaiton;
}


/*
 *Les fonctions de validation ont été développées au TP1 dans le module validationFormat. Il s’agit ici
de les utiliser pour vérifier les données avant de les transmettre aux méthodes. Insérez ces fonctions dans
le  namespace  util.  Les  modifications  apportées  au  code  initial  du  TP1,  peuvent  être  qualifiées  de
maintenance.
 *
 * Aussi,  comme  indiqué  dans  ces  normes,  vous  devez  définir  un  espace  de  nom  (namespace).  Il  devra
porter le nom suivant : biblio (en minuscules).
 */
int
main ()
{
  bool valeurCorrecte = false;
  string nomAuteur;
  while (!valeurCorrecte)
    {
      cout << "Saisissez le nom de l'auteur ou si il y en a plusieurs le premier" << endl;
      getline (std::cin, nomAuteur);
      if (validerFormatNom (nomAuteur))
        {
          valeurCorrecte = true;
        }
    }
  cout << endl << endl;


  valeurCorrecte = false;
  string titre;
  while (!valeurCorrecte)
    {
      cout << "Saisissez le titre de la publication. Le titre ne peut pas etre vide" << endl;
      getline (std::cin, titre);
      if (!titre.empty ())
        {
          valeurCorrecte = true;
        }
    }

  cout << endl << endl;


  valeurCorrecte = false;
  string code;
  while (!valeurCorrecte)
    {
      cout << "Saisissez le code ISBN ou ISSN" << endl;
      getline (std::cin, code);
      if (validerCodeIssn (code) || validerCodeIsbn (code))
        {
          valeurCorrecte = true;
        }
    }

  cout << endl << endl;


  int annee = saisirAnnee ();
  cout << endl << endl;

  Reference ref = Reference (nomAuteur, titre, annee, code);
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

