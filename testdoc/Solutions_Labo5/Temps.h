/**
 * \file Temps.h
 * \brief Prototype de la classe Temps
 * \author THE
 * \date
 */

#ifndef TEMPS_H_
#define TEMPS_H_

#include <string>

/**
 * \class Temps
 * \brief Classe Temps permettant de modéliser les objets temps
 */
class Temps
{
public:
  Temps ();
  Temps (int p_heure, int p_minute, int p_seconde);

  int reqHeure () const;
  int reqMinute () const;
  int reqSeconde () const;

  std::string reqTempsFormate () const;

  void asgHeure (int p_heure);
  void asgMinute (int p_minute);
  void asgSeconde (int p_seconde);
  void asgTemps (int p_heure, int p_minute, int p_seconde);

private:
  int m_heure;
  int m_minute;
  int m_seconde;
};

#endif /* TEMPS_H_ */
