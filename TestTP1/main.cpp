/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   main.cpp
 * Author: etudiant
 *
 * Created on 29 septembre 2021, 13:06
 */

#include <string>
#include "validationFormat.h"
#include <iostream>

using namespace std;


/*
 *
 */
int
main (int argc, char** argv)
{
  cout << validerCodeIsbn ("ISBN 978-2-212-67895-6") << endl;
  cout << validerCodeIsbn ("ISBN 978-99937-1-056-1") << endl;
  return 0;
}
