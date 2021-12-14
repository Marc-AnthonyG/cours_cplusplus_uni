/**
 * \file Forme.h
 * \brief
 * \author the
 * \version 0.1
 * \date 2015-12-03
 */

#ifndef FORME_H_
#define FORME_H_
#include <string>
/**
 * \namespace laboFormes
 *
 * espace de nommage regroupant les definitions
 * pour les classes de formes
 */
namespace laboFormes
{
/**
 * \class Forme
 * \brief Classe abstraite permettant de modéliser les objets Forme.
 */

class Forme
{
public:
	Forme(double p_xCentre = 0, double p_yCentre = 0);
	virtual ~Forme()
	{
	}
	;
	double reqXCentre() const;
	double reqYCentre() const;

	virtual std::string reqFormeFormate() const=0;

private:
	void verifieInvariant() const;
	double m_xCentre;
	double m_yCentre;
};

} /* namespace laboFormes */

#endif /* FORME_H_ */
