/**
 * \file FormeTroisDimensions.h
 * \brief interface classe trois dimensions
 * \author the
 * \version 0.1
 * \date 2015-12-03
 */
#ifndef FORMETROISDIMENSIONS_H_
#define FORMETROISDIMENSIONS_H_

#include "Forme.h"

namespace laboFormes
{

class FormeTroisDimensions: public Forme
{
public:
	FormeTroisDimensions(double p_xCentre, double p_yCentre);
	virtual double aire() const = 0;
	virtual double volume() const = 0;
private:
	void verifieInvariant() const;
};

} /* namespace laboFormes */

#endif /* FORMETROISDIMENSIONS_H_ */
