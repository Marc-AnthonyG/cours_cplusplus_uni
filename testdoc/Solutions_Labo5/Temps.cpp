/**
 * \file Temps.cpp
 * \brief Implementation de la classe temps
 * \author THE
 * \date
 */

#include "Temps.h"
#include <time.h>
#include <sstream>
#include<iostream>


/**
 * \brief Constructeur par defaut qui represente l'heure actuelle
 * \return Un objet temps
 */
Temps::Temps ()
{
  //  std::cout << "temp()";//pour voir que le constructeur par défaut est appelé
  m_seconde = time (NULL); // nombre de secondes depuis 1970
  m_minute = (m_seconde % 3600) / 60; // nombre de minutes dans la dernière heure
  m_heure = (m_seconde / 3600) % 24; // nombre d'heures aujourd'hui, IMPORTANT: l’heure ici est en GMT
  /*
   * Pour mettre l’heure en GMT-4 ou GMT-5, il faut tenir compte
   * *** pour GMT-4 de l’intervalle [1..3] parce que si en GMT il est 3 et que vous faites uniquement -4 pour
   *     avoir l’heure GMT-4 vous vous retrouverez avec une heure négative;
   *     pareille pour GMT-5, c’est l’intervalle [1..4]
   * */
  /* Mettre m_heure en GMT-4*/
  switch (m_heure)
    {
      case 1:
        m_heure = 21;
        break;
      case 2:
        m_heure = 22;
        break;
      case 3:
        m_heure = 23;
        break;
      default:
        m_heure = m_heure - 4;
        break;
    }
  /* Mettre m_heure en GMT-5
   switch (m_heure)
   {
   case 1:
   m_heure = 20;
   break;
   case 2:
   m_heure = 21;
   break;
   case 3:
   m_heure = 22;
   break;
   case 4:
   m_heure = 23;
   break;
   default:
   m_heure = m_heure - 5;
   break;
   }*/
  m_seconde = m_seconde % 60; // nombre de secondes dans la dernière minute
}


/**
 * \brief Constructeur avec parametres
 * \param[in] p_heure Le nombre d'heure
 * \param[in] p_minute Le nombre de minutes
 * \param[in] p_seconde Le nombre de secondes
 * \return Un objet temps
 */
Temps::Temps (int p_heure, int p_minute, int p_seconde) :
m_heure (p_heure), m_minute (p_minute), m_seconde (p_seconde) { }


/**
 * \brief Accesseur pour heure
 * \return m_heure L'heure de l'objet
 */
int Temps::reqHeure () const
{
  return m_heure;
}


/**
 * \brief Accesseur pour minute
 * \return m_minute Les minutes de l'objet
 */
int Temps::reqMinute () const
{
  return m_minute;
}


/**
 * \brief Accesseur pour les secondes
 * \return m_seconde Les seconde de l'objet
 */
int Temps::reqSeconde () const
{
  return m_seconde;
}


/**
 * \brief Mutateur pour heure, modifie l'heure
 * \param[in] p_heure nouvelle heure
 */
void Temps::asgHeure (int p_heure)
{
  m_heure = (p_heure >= 0 && p_heure < 24) ? p_heure : 0;
}


/**
 * \brief Mutateur pour minute, modifie les minutes
 * \param[in] p_minute nouveau nombre de minutes
 */
void Temps::asgMinute (int p_minute)
{
  m_minute = (p_minute >= 0 && p_minute < 60) ? p_minute : 0;
}


/**
 * \brief Mutateur pour seconde, modifie les secondes
 * \param[in] p_seconde nouveau nombre de secondes
 */
void Temps::asgSeconde (int p_seconde)
{
  m_seconde = (p_seconde >= 0 && p_seconde < 60) ? p_seconde : 0;
}


/**
 * \brief Retourne une chaine de caractere qui contient l'information de l'objet temps
 * \return un string qui contient l'information
 */
std::string Temps::reqTempsFormate () const
{
  std::ostringstream os;
  os << ((m_heure == 0 || m_heure == 12) ? 12 : m_heure % 12) << ":"
          << (m_minute < 10 ? "0" : "") << m_minute << ":"
          << (m_seconde < 10 ? "0" : "") << m_seconde
          << (m_heure < 12 ? " AM" : " PM");
  return os.str ();
}


/**
 * \brief Mutateur pour la classe Temps, modifie les heures, les minutes et les secondes
 * \param[in] p_heure nouvelle heure
 * \param[in] p_minute nouveau nombre de minutes
 * \param[in] p_seconde nouveau nombre de secondes
 */
void Temps::asgTemps (int p_heure, int p_minute, int p_seconde)
{
  asgHeure (p_heure);
  asgMinute (p_minute);
  asgSeconde (p_seconde);
}
