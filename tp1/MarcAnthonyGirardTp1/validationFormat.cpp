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
checkLastDigit (int somme, string lastDigit)
{
  bool isValid = true;
  char * nbrValidation = new char[1];
  strcpy (nbrValidation, lastDigit.c_str ());
  if (isStringDigit (lastDigit))
    {
      isValid = atoi (nbrValidation) == 11 - somme % 11;
    }
  else
    {
      isValid = (*nbrValidation == 'X') && (somme % 11 == 1);
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
          isValid = checkLastDigit (somme, p_issn.substr (13, 1));
        }
    }
  return isValid;
}


bool
validerCodeIsbn (const std::string& p_isbn)
{
  bool isValid = false;

  if (p_isbn.substr (0, 5).compare ("ISBN ") == 0
      && (p_isbn.substr (5, 4).compare ("978-") == 0 || p_isbn.substr (5, 4).compare ("979-") == 0)
      && p_isbn.length () == 22)
    {
      string check = p_isbn.substr (9, string::npos);
      bool nombreValide = true;
      int sommeCheck = 0;
      int numeroNombre = 0;

      for (int i = 0; i < check.length () && nombreValide; i++, numeroNombre++)
        {
          if (i == check.length () - 2)
            {
              nombreValide = check[i] == '-';
            }
          else if (i == check.length () - 1)
            {
              isValid = checkLastDigit (sommeCheck, check.substr (i, 1));
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
                  sommeCheck += atoi (temp) * (10 - numeroNombre);
                }
              else
                {
                  nombreValide = false;
                }
            }
        }
    }
  return isValid;
}