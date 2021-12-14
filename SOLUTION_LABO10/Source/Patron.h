/**
 * \file Patron.h
 * \brief Classe Patron, dérivée de la classe Employe.
 * \author etudiant
 * \version 0.1
 * \date
 */

#ifndef PATRON_H_
#define PATRON_H_

#include "Employe.h"

namespace labo10
{

  /**
   * \class Patron
   * \brief Classe dérivée de la classe Employe
   */
  class Patron : public Employe
  {
  public:
    Patron (const std::string& p_nom, const std::string& p_prenom, const util::Date& p_dateNaissance, int p_codeDepartement = 1,
            double p_salaireHebdo = 0.0);

    void asgSalaireHebdo (double p_salaireHebdo);
    double reqSalaireHebdo ()const;

    virtual double gains () const;
    virtual std::string reqEmployeFormate () const;

  private:
    double m_salaireHebdo;
    void verifieInvariant () const;

  };

} // namespace labo10

#endif /* PATRON_H_ */
