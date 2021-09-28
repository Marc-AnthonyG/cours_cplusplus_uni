/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   main.cpp
 * Author: etudiant
 *
 * Created on 20 septembre 2021, 21:04
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include <cstring>


using namespace std;
bool isStringDigit (const string& aValider);


/*
 *
 */
int
main (int argc, char** argv)
{
  const string p_issn = "ISSN 1467-8640";
  bool isValid = false;

  if (p_issn.substr (0, 5).compare ("ISSN ") == 0 && p_issn.length () == 14 && p_issn.substr (9, 1).compare ("-") == 0)
    {
      string chiffre = "";
      chiffre.append (p_issn.substr (5, 4).append (p_issn.substr (10, 4)));
      if (isStringDigit (chiffre))
        {
          int somme = 0;
          for (int i = 0; i < chiffre.length (); i++)
            {
              char * temp = new char[1];
              strcpy (temp, chiffre.substr (i, 1).c_str ());
              if (i != 7)
                {
                  somme += atoi (temp) * (8 - i);
                }
              else
                {
                  isValid = atoi (temp) == somme % 11;
                }
            }
        }
    }
  cout << isValid << endl;

  return 0;
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
