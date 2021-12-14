/*
 * Cercle.h
 *
 *  Created on: 2015-12-03
 *      Author: etudiant
 */

#ifndef CERCLE_H_
#define CERCLE_H_

#include "FormeDeuxDimensions.h"

namespace laboFormes
{

class Cercle: public FormeDeuxDimensions
{
public:
	Cercle(double p_rayon = 0, double p_xCentre = 0, double p_yCentre = 0);

	virtual std::string reqFormeFormate() const;
	virtual double aire() const;
	double reqRayon() const;

private:
	void verifieInvariant() const;
	double m_rayon;
};

} /* namespace laboFormes */

#endif /* CERCLE_H_ */
