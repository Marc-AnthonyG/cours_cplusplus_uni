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
  string test = "abc--asdas";

  bool isValid = true;
  int nbrSpeciauSuite = 0;

  for (int i = 0; i < test.length () && isValid; i++)
    {
      if (!(isalpha (test[i]) || test[i] == '-' || test[i] == ' '))
        {
          isValid = false;
        }
      else
        {
          if (test[i] == '-' || test[i] == ' ')
            {
              isValid = ++nbrSpeciauSuite != 2;
            }
          else
            nbrSpeciauSuite = 0;
        }
    }
  cout << isValid << endl;


  return 0;
}

