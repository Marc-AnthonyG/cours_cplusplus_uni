/**
 * \file principalUtilisationDate.cpp
 * \brief Programme simple pour l'utilisation de la classe Date
 * \author Administrateur
 * \date 04 10 2012
 * \version 2.0
 */
#include "Date.h"
#include "ContratException.h"
#include <iostream>

using namespace std;
using namespace util;

int main()
{
	try
	{
		Date uneDate;

		cout << "On recupere la date courante" << endl;

		cout << uneDate.reqJour() << ":" << uneDate.reqMois() << ":"
				<< uneDate.reqAnnee() << endl;

		cout << "Date formatee" << endl;

		cout << uneDate.reqDateFormatee() << endl;

		Date dateDeux(1, 2, 2000);

		cout << uneDate - dateDeux << endl;
		Date d1(15,4,2000);
		Date d2(16,4,2010);

		cout << "Mes dates: "<< d1-d2 << endl;

		uneDate.asgDate(dateDeux.reqJour(), dateDeux.reqMois(),
				dateDeux.reqAnnee());
		cout << uneDate << endl;
		cout << uneDate.reqDateFormatee() << endl;
		uneDate.ajouteNbJour(-3);
		cout << uneDate.reqDateFormatee() << endl;
	} catch (ContratException& e)
	{
		cout << e.reqTexteException() << endl;
	}
	return 0;
}
