/*
 * FormeDeuxDimensions.h
 *
 *  Created on: 2015-12-03
 *      Author: etudiant
 */

#ifndef FORMEDEUXDIMENSIONS_H_
#define FORMEDEUXDIMENSIONS_H_

#include "Forme.h"

namespace laboFormes
{

class FormeDeuxDimensions: public Forme
{
public:
	FormeDeuxDimensions(double p_xCentre, double p_yCentre);
	virtual double aire() const = 0;
private:
	void verifieInvariant() const;
};

} /* namespace laboFormes */

#endif /* FORMEDEUXDIMENSIONS_H_ */
