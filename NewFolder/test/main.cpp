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


using namespace std;


/*
 *
 */
int
main (int argc, char** argv)
{
  string p_issn = "ISSN 1467-8640";

  bool isValid = false;
  if (p_issn.substr (0, 5).compare ("ISSN ") && p_issn.length () == 14 && p_issn.substr (9, 1).compare ("-"))
    {
      if (isdigit (p_issn.substr (5, 4)) && isdigit p_issn.substr (10, 4))
        {
          string chiffre = "";
          chiffre.append (p_issn.substr (5, 4).append (p_issn.substr (10, 4)));
          int somme = 0;

          for (int i = 0; i < chiffre.length () - 1; i++)
            {
              somme += atoi (chiffre.substr (i, 1).c_str ()) * 8 - i;
            }
          isValid = atoi (chiffre[7].c_str ()) == somme % 11;
        }
    }

  cout << isValid << endl;


  return 0;
}

