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
bool checkLastDigit (int somme, string lastDigit);


/*
 *
 */
int
main (int argc, char** argv)
{
  const string p_isbn = "ISBN 978-2-1234-5680-2";
  bool isValid = false;

  if (p_isbn.substr (0, 5).compare ("ISBN ") == 0
      && (p_isbn.substr (5, 4).compare ("978-") == 0 || p_isbn.substr (5, 4).compare ("979-") == 0)
      && p_isbn.length () == 22)
    {
      string check = p_isbn.substr (9, string::npos);
      bool nombreValide = true;
      int sommeCheck = 0;
      int numeroNombre = 0;

      for (int i = 0; i < check.length () && nombreValide; i++)
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
                  numeroNombre++;
                }
              else
                {
                  nombreValide = false;
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