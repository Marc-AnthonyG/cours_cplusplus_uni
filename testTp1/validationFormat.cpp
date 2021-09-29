/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   validationFormat.cpp
 * Author: etudiant
 *
 * Created on 20 septembre 2021, 20:52
 */

#include <cstring>
#include <array>
#include "validationFormat.h"


using namespace std;


bool
validerFormatNom (const string& p_nom)
{
  bool isValid = true;

  for (int i = 0; i < p_nom.length () && isValid; i++)
    {
      if (!isalpha (p_nom[i]))
        {
          if (p_nom[i] == '-' || p_nom[i] == ' ')
            {
              if (i + 1 != p_nom.length ())
                {
                  isValid = !(p_nom[i + 1] == '-' || p_nom[i + 1] == ' ');
                }
            }
          else
            {
              isValid = false;
            }
        }
    }
  return isValid;
}


bool
isStringDigit (const string& aValider)
{
  bool isValid = true;
  for (int i = 0; i < aValider.length () && isValid; i++)
    {
      if (!isdigit (aValider[i]))
        {
          isValid = false;
        }
    }
  return isValid;
}


bool
isEditorValid (const string& aValider)
{
  bool isValid = false;
  char * firstChar = new char[1];
  strcpy (firstChar, aValider.substr (0, 1).c_str ());
  char * secondChar = new char[1];
  strcpy (secondChar, aValider.substr (1, 1).c_str ());

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


bool
isDomaineValid (const string & aValider)
{
  bool isValid = false;
  int longeur = aValider.length ();
  char * firstChar = new char[1];
  strcpy (firstChar, aValider.substr (0, 1).c_str ());

  char * secondChar = new char[1];
  char * thirdChar = new char[1];
  if (longeur >= 2)
    {
      strcpy (secondChar, aValider.substr (1, 1).c_str ());
    }
  if (longeur >= 4)
    {
      strcpy (thirdChar, aValider.substr (1, 1).c_str ());
    }
  switch (longeur)
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


bool
validerCodeIssn (const string & p_issn)
{
  bool isValid = false;

  if (p_issn.substr (0, 5).compare ("ISSN ") == 0 && p_issn.length () == 14 && p_issn[9] == '-')
    {
      string chiffre = "";
      chiffre.append (p_issn.substr (5, 4).append (p_issn.substr (10, 3)));
      if (isStringDigit (chiffre))
        {
          int somme = 0;
          for (int i = 0; i < chiffre.length (); i++)
            {
              char * temp = new char[1];
              strcpy (temp, chiffre.substr (i, 1).c_str ());
              somme += atoi (temp) * (8 - i);
            }
          char * nbrValidation = new char[1];
          strcpy (nbrValidation, p_issn.substr (13, 1).c_str ());
          if (isStringDigit (p_issn.substr (13, 1)))
            {
              isValid = atoi (nbrValidation) == 11 - somme % 11;
            }
          else
            {
              isValid = (*nbrValidation == 'X') && (somme % 11 == 1);
            }
        }
    }
  return isValid;
}


bool
validerCodeIsbn (const std::string & p_isbn)
{
  bool isValid = false;

  if (p_isbn.substr (0, 5).compare ("ISBN ") == 0
      && (p_isbn.substr (5, 4).compare ("978-") == 0 || p_isbn.substr (5, 4).compare ("979-") == 0)
      && p_isbn.length () == 22)
    {
      string domaine = p_isbn.substr (9, p_isbn.substr (9, string::npos).find ("-"));
      if (isDomaineValid (domaine))
        {
          string editor = p_isbn.substr (10 + domaine.length (), p_isbn.substr (10 + domaine.length (), string::npos).find ("-"));
          if (isEditorValid (editor))
            {
              string check = p_isbn.substr (5, string::npos);
              bool nombreValide = true;
              int sommeCheck = 0;
              bool estMulTrois = false;

              for (int i = 0; i < check.length () && nombreValide; i++)
                {
                  if (i == check.length () - 2)
                    {
                      nombreValide = check[i] == '-';
                    }
                  else if (i == check.length () - 1)
                    {
                      char * nbrValidation = new char[1];
                      strcpy (nbrValidation, check.substr (i, 1).c_str ());
                      isValid = atoi (nbrValidation) == (10 - sommeCheck % 10) % 10;
                    }
                  else
                    {
                      if (check[i] == '-')
                        {
                          nombreValide = !(check[i + 1] == '-');
                        }
                      else if (isStringDigit (check.substr (i, 1)))
                        {
                          char * temp = new char[1];
                          strcpy (temp, check.substr (i, 1).c_str ());
                          if (estMulTrois)
                            {
                              sommeCheck += (atoi (temp)*3);
                            }
                          else
                            {
                              sommeCheck += atoi (temp);
                            }
                          estMulTrois = !estMulTrois;
                        }
                      else
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