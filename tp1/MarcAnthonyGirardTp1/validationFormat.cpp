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

#include "validationFormat.h"
#include <string>


using namespace std;


bool
validerFormatNom (const string& p_nom)
{
  bool isValid = true;

  for (int i = 0; i < p_nom.length () && isValid; i++)
    {
      if (!isalpha)
        {
          if (p_nom[i] == '-' || p_nom[i] == ' ')
            {
              if (i + 1 != p_nom.length ())
                isValid = !(p_nom[i + 1] == '-' || p_nom[i + 1] == ' ');
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
validerCodeIssn (const string& p_issn)
{

  return true;
}