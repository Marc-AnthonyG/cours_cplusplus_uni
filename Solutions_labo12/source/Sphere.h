/*
 * Sphere.h
 *
 *  Created on: 2018-12-03
 *      Author: THE
 */

#ifndef SPHERE_H_
#define SPHERE_H_

#include "FormeTroisDimensions.h"

namespace laboFormes
{

class Sphere: public FormeTroisDimensions
{
public:
	Sphere(double p_rayon = 0, double p_xCentre = 0, double p_yCentre = 0);
	virtual std::string reqFormeFormate() const;
	virtual double aire() const;
	virtual double volume() const;
	double reqRayon() const;

private:
	void verifieInvariant() const;
	double m_rayon;
};

} /* namespace laboFormes */

#endif /* SPHERE_H_ */
