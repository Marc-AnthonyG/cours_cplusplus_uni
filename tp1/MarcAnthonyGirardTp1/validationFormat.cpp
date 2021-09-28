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
      if (!isalpha (p_nom[i]) {
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
isStringDigit (const string & aValider)
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
validerCodeIssn (const string & p_issn)
{
          bool isValid = false;
          if (p_issn.substr (0, 5).compare ("ISSN ") && p_issn.length () == 14 && p_issn[9].compare ("-"))
    {
          if (isdigit (p_issn.substr (5, 4)) && isdigit p_issn.substr (10, 4))
        {
          string chiffre = "";
          chiffre.append (p_issn.substr (5, 4).append (p_issn.substr (10, 4)));
          int somme = 0;

          for (int i = 0; i < chiffre.length () - 1; i++)
            {
          somme += atoi (chiffre[i].c_str ()) * 8 - i;
            }
          isValid = atoi (chiffre[7].c_str ()) == somme % 11;
        }
    }
          return isValid;
}