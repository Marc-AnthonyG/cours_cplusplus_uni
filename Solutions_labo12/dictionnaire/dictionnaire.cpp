/**
 * \file dictionnaire.cpp
 * \brief Implantation d'un mini-dictionnaire anglais-français
 * \author etudiant
 * \version 0.1
 * \date 2015-04-16
 */

#include <iostream>
#include <string>
#include<map>

using namespace std;

int main()
{

    multimap<string,string> dictionnaire;    	// Notre dictionnaire
    dictionnaire.insert(pair<string,string>("blue","bleu"));
    dictionnaire.insert(pair<string,string>("yes","oui"));
    dictionnaire.insert(pair<string,string>("pants","pantalon"));
    dictionnaire.insert(pair<string,string>("snow","neige"));
    dictionnaire.insert(pair<string,string>("pencil","crayon"));
    dictionnaire.insert(pair<string,string>("funny","drôle"));
    dictionnaire.insert(pair<string,string>("funny","amusant"));

    cout << "Entrez un mot anglais : ";
    char buffer[256];
    cin.getline(buffer,255);
    string motAnglais = buffer;           	           // Mots anglais

    multimap<string,string>::iterator iter;            // Pour parcourir le dictionnaire
    iter = dictionnaire.find(motAnglais);              // trouver la traduction en français du mot anglais
    if (iter != dictionnaire.end())
    {
    	cout << motAnglais << " se traduit par" << endl;
    	while(iter != dictionnaire.end())
    	{
    		if (iter->first == motAnglais)
    			cout << iter->second << endl;
    		iter++;
    	}
    }
    else
    {
    	cout << "Le mot \"" << motAnglais  << "\" n'est pas dans le dictionnaire." << endl;
    }

	return 0;
}



