/**
 * \file validationFormat.cpp
 * \brief Implementation de la bibliothèque validationFormat
 * \author Marc-Anthony Girard
 * \date 29 septembre 2021
 */

#include <cstring>
#include <array>
#include "validationFormat.h"


using namespace util;


/**
 * \brief Méthode qui vérifie si tout les termes d'une string sont des nombres
 * \param[in] aValider La string à valider.
 * \return True si la string ne contient que des entiers (0 à 9).
 */
bool
isStringDigit (const std::string& aValider)
{
  bool isValid = true;
  for (int i = 0; i < aValider.length () && isValid; i++) // On rajoute isValid pour sortir dès que caractères n'est pas un nombre
    {
      if (!isdigit (aValider[i]))
        {
          isValid = false;
        }
    }
  return isValid;
}


/**
 * \brief Méthode qui vérifie si une string correspond à un numéro d'éditeur valide.
 * \param[in] aValider La string à valider.
 * \return True si le numéro d'éditeur est valide.
 */
bool
isEditorValid (const std::string& aValider)
{
  bool isValid = false;
  char * firstChar = new char[1];
  std::strcpy (firstChar, aValider.substr (0, 1).c_str ());
  char * secondChar = new char[1];
  std::strcpy (secondChar, aValider.substr (1, 1).c_str ());

  //création de char pour la fonction atoi
  switch (aValider.length ())
    {
      case 1:
        isValid = true;
        break;
      case 2:
        isValid = atoi (firstChar) < 2;
        break;
      case 3:
        isValid = atoi (firstChar) >= 2  && atoi (firstChar) < 7;
        break;
      case 4:
        isValid = atoi (firstChar) == 7  || (atoi (firstChar) == 8 && atoi (secondChar) < 5);
        break;
      case 5:
        isValid = atoi (firstChar) == 8  &&  atoi (secondChar) >= 5;
        break;
      case 6:
        isValid = atoi (firstChar) == 9  &&  atoi (secondChar) < 5;
        break;
      case 7:
        isValid = atoi (firstChar) == 9  &&  atoi (secondChar) >= 5;
        break;
    }
  return isValid;
}


/**
 * \brief Méthode qui vérifie si une string correspond à un numéro de domaine valeur valide.
 * \param[in] aValider La string à valider.
 * \return True si le numéro de domaine est valide.
 */
bool
isDomaineValid (const std::string & aValider)
{
  bool isValid = false;
  //création de char pour la fonction atoi
  char * firstChar = new char[1];
  strcpy (firstChar, aValider.substr (0, 1).c_str ());
  char * secondChar = new char[1];
  strcpy (secondChar, aValider.substr (1, 1).c_str ());
  char * thirdChar = new char[1];
  strcpy (thirdChar, aValider.substr (1, 1).c_str ());
  switch (aValider.length ())
    {
      case 1:
        isValid = atoi (firstChar) <= 5 || atoi (firstChar) == 7;
        break;
      case 2:
        isValid = atoi (firstChar) >= 8  && atoi (secondChar) < 5;
        break;
      case 3:
        isValid = (atoi (firstChar) == 6  && atoi (secondChar) < 5) ||
                (atoi (firstChar) == 9  && atoi (secondChar) < 9 && atoi (secondChar) >= 5);
        break;
      case 4:
        isValid = atoi (firstChar) == 9 && atoi (secondChar) == 9 && atoi (thirdChar) <= 8;
        break;
      case 5:
        isValid = atoi (firstChar) == 9 && atoi (secondChar) == 9 && atoi (thirdChar) == 9;
        break;
    }
  return isValid;
}


/**
 * \brief Méthode qui vérifie si une string correspond à un nom valide.
 *
 * Un nom valide est constituer que de lettre et n'est pas constituer de deux espaces ou tirets de suite.
 * ValiderFormatNon fonctionne de manière très simple. Il assume que le nom est valide,
 puis il passe à travers tout les caractères. En fesant cela, il y a trois possibilité.
 * (1) Le caractères est une lettre. Si c'est vrai, on ne teste rien d'autre et on passe au suivant.
 * (2) Le caractères est un espace ou un tiret. Dans ce cas, le code vérifie que le caractère suivant est  un autre espace ou un tiret. Si ce n'est pas le cas on passe au caractère suivant sinon on considère le nom invalide.
 * (3) Ce n'est pas un caractère valide donc on sort de l'ittération
 * \param[in] p_nom La string à valider.
 * \return True si le nom est valide.
 */
bool
util::validerFormatNom (const std::string& p_nom)
{
  bool isValid = true;

  for (int i = 0; i < p_nom.length () && isValid; i++) //on rajoute isValid pour sortir de la boucle dès que le nom est invalide
    {
      if (!isalpha (p_nom[i])) //(1)
        {
          if (p_nom[i] == '-' || p_nom[i] == ' ') //(2)
            {
              if (i + 1 != p_nom.length ())
                {
                  isValid = !(p_nom[i + 1] == '-' || p_nom[i + 1] == ' ');
                }
            }
          else //(3)
            {
              isValid = false;
            }
        }
    }
  return isValid;
}


/**
 * \brief Méthode qui vérifie si une string correspond à un numéro ISSN valide.
 *
 * validerCodeIssn Vérifie dans l'ordre
 * (1) Que ISSN est là, que le tiret est à la bonne place et que la chaine à la bonne longeur
 * (2) qu'il n'y a pas de lettre dans la chaine de chiffre
 * \param[in] p_issn La string à valider.
 * \return True si le code ISSN est valide.
 */
bool
util::validerCodeIssn (const std::string & p_issn)
{
  bool isValid = false;

  if (p_issn.substr (0, 5).compare ("ISSN ") == 0 && p_issn.length () == 14 && p_issn[9] == '-') //(1)
    {
      std::string chiffre = "";
      chiffre.append (p_issn.substr (5, 4).append (p_issn.substr (10, 3)));

      if (isStringDigit (chiffre))//(2)
        {
          int somme = 0;
          for (int i = 0; i < chiffre.length (); i++) //La boucle permet de calculé la somme qui nous donnera 11 - somme%11 = clé de contrôle
            {
              somme += atoi (chiffre.substr (i, 1).c_str ()) * (8 - i);
            }

          //la suite permet de vérifier si la clé de contrôle est bonne
          if (isStringDigit (p_issn.substr (13, 1)))
            {
              isValid = atoi (p_issn.substr (13, 1).c_str ()) == 11 - somme % 11;
            }
          else
            {
              isValid = (*p_issn.substr (13, 1).c_str () == 'X') && (somme % 11 == 1);
            }
        }
    }
  return isValid;
}


/**
 * \brief Méthode qui vérifie si une string correspond à un numéro ISBN valide.
 *
 * validerCodeIsbn Vérifie dans l'ordre
 * (1) Que ISBN est là, que le préfixe est 978 ou 979 et que la chaine à la bonne longeur
 * (2) Que l'identifiant de domaine est valide
 * (3) Que l'identifiant d'éditeur est valide
 * \param[in] p_isbn La string à valider.
 * \return True si le code ISBN est valide.
 */
bool
util::validerCodeIsbn (const std::string & p_isbn)
{
  bool isValid = false;

  if (p_isbn.substr (0, 5).compare ("ISBN ") == 0
      && (p_isbn.substr (5, 4).compare ("978-") == 0 || p_isbn.substr (5, 4).compare ("979-") == 0)
      && p_isbn.length () == 22) //(1)
    {
      std::string domaine = p_isbn.substr (9, p_isbn.substr (9, std::string::npos).find ("-"));
      if (isDomaineValid (domaine)) // (2)
        {
          if (isEditorValid (p_isbn.substr (10 + domaine.length (), p_isbn.substr (10 + domaine.length (), std::string::npos).find ("-")))) // (3)
            {
              std::string check = p_isbn.substr (5, std::string::npos);
              bool nombreValide = true;
              int sommeCheck = 0;
              bool estMulTrois = false;

              //l'intérieur du for permet de vérifier qu'il n'y a pas deux tiret de suite (1), qu'il n'y a pas de lettre (2) et cela permet aussi de calculer la sommes des nombres avec leur pondération(3) aisni que d'évaluer la clé de controle (4). Finalement cela permet aussi de vérifier que la clé de controle est séparer d'un tiret du reste de la string (5)
              for (int i = 0; i < check.length () && nombreValide; i++)
                {
                  if (i == check.length () - 2)//(5)
                    {
                      nombreValide = check[i] == '-';
                    }
                  else if (i == check.length () - 1)//(4)
                    {
                      isValid = atoi (check.substr (i, 1).c_str ()) == (10 - sommeCheck % 10) % 10;
                    }
                  else
                    {
                      if (check[i] == '-')//(1)
                        {
                          nombreValide = !(check[i + 1] == '-');
                        }
                      else if (isStringDigit (check.substr (i, 1)))//(3)
                        {
                          if (estMulTrois)
                            {
                              sommeCheck += (atoi (check.substr (i, 1).c_str ()) * 3);
                            }
                          else
                            {
                              sommeCheck += atoi (check.substr (i, 1).c_str ());
                            }
                          estMulTrois = !estMulTrois;
                        }
                      else //(2)
                        {
                          nombreValide = false;
                        }
                    }
                }
            }
        }
    }
  return isValid;
}
