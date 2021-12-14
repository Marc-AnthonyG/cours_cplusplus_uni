#ifndef _EMPLOYEINTERFACE_H
#define _EMPLOYEINTERFACE_H

#include "ui_EmployeInterface.h"
#include "Employe.h"
#include <vector>
#include <string>

class EmployeInterface : public QMainWindow
{
  Q_OBJECT
public:
  EmployeInterface ();

  virtual ~EmployeInterface ();

  void ajouteEmployeCommission (const std::string& p_nom, const std::string& p_prenom,
                                const util::Date& p_dateNaissance, int p_codeDepartement,
                                double p_salaire, double p_commission, int p_quantite);
  void ajouteEmployeHoraire (const std::string& p_nom, const std::string& p_prenom,
                             const util::Date& p_dateNaissance, int p_codeDepartement,
                             double p_tauxHoraire, double p_heures);
  void ajouteEmployePatron (const std::string& p_nom, const std::string& p_prenom,
                            const util::Date& p_dateNaissance, int p_codeDepartement,
                            double p_salaireHebdo);
  std::string reqListeFormate ()const;

private slots:
  void dialogCommis ();
  void dialogHoraire ();
  void dialogPatron ();


private:
  Ui::EmployeInterface widget;
  std::vector<labo10::Employe*> m_vEmploye;

};

#endif /* _EMPLOYEINTERFACE_H */
