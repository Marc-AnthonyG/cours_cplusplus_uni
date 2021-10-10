/**
 * \file Temps_test.cpp
 * \brief Utilisation de notre classe Temps pour créer des objets
 * 			et tester les méthodes de la classe
 * \author THE
 * \date
 */

#include <iostream>
#include <array>
#include "Temps.h"
#include <fstream>

using namespace std;
const int TAILLETABLEAU = 5;


int
main ()
{
  cout << Temps::reqNbInstances () << endl;
  Temps t0; // temps courant
  cout << t0 << endl; //affichage du temps courant


  Temps testTic (23, 58, 58);
  do
    {
      testTic.tic ();
      cout << testTic << endl;
    }
  while (testTic.reqHeure () != 0);

  cout << Temps::reqNbInstances () << endl;


  Temps t;  // creation d'un objet Temps t par defaut (Temps courant)
  t.asgHeure (17);  //assignation de l'heure de l'objet Temps t
  t.asgMinute (34);
  t.asgSeconde (25);

  // affichage de l'objet Temps t creer
  cout << "Resultat d'un ajustement avec des valeurs valides:" << endl
          << "  Heure: " << t.reqHeure () << "  Minute: " << t.reqMinute ()
          << "  Seconde: " << t.reqSeconde ();

  t.asgHeure (234); // heure non valide, ajustee a 0.
  t.asgMinute (43);
  t.asgSeconde (6373); // seconde non valide, ajustee a 0.

  cout << "\n\nResultat avec des valeurs non valables pour"
          << " heure et seconde:\n  Heure: " << t.reqHeure () << "  Minute: "
          << t.reqMinute () << "  Seconde: " << t.reqSeconde () << endl;

  cout << endl << "constructeur avec parametres invalides" << endl;

  Temps t1 (23, 58, 58); //creation d'un objet Temps t1 avec parametre
  cout << "\t" << t1.reqTempsFormate () << " pour 23h 58mn 58s" << endl;

  //tableau d'objets Temps
  array<Temps, TAILLETABLEAU> tableauTemps;
  tableauTemps[1].asgTemps (2, 3, 4);
  tableauTemps[3].asgHeure (0);

  cout << endl << "tableau d'objets Temps" << endl;
  for (int i = 0; i < TAILLETABLEAU; i++)
    {
      cout << tableauTemps[i].reqTempsFormate () << endl;
    }

  cout << endl << "Ecriture dans le fichier" << endl;

  std::ofstream ofs ("test.txt", std::ofstream::out);
  if (ofs)
    {
      for (int i = 0; i < TAILLETABLEAU; i++)
        {
          ofs << tableauTemps[i] << endl;
        }
    }
  ofs.close ();
  cout << Temps::reqNbInstances () << endl;

  return 0;
}
