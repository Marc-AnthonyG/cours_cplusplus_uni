/**
 * \file puissance.cpp
 * \author FRM
 * \brief Programme d�mo calcul de x � la puissance y en langage C++
 */
#include <iostream>
using namespace std;


int
main (void)
{

  cout << "Ce programme calcule x a la puissance y." << endl;

  cout << "Veuillez entrer la valeur enti�re de x (different de 0): " << endl;
  int x;
  cin >> x;
  /*A: x est diff�rent de 0*/

  cout << "\nVeuillez entre la valeur de y strictement positif: " << endl;
  int y;
  cin >> y;
  /*A: y > 0 */

  int puissance;
  puissance = x;
  int i = 0;
  while (i < y - 1)
    {
      puissance = puissance * x;
      i++;
    }

  cout << "x a la puissance y = " << puissance << endl;
  return 0;
}


