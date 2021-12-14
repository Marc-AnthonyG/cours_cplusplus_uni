/*
 * FormeDeuxDimensions.cpp
 *
 *  Created on: 2018-12-03
 *      Author: THE
 */

#include "FormeDeuxDimensions.h"
#include "ContratException.h"

namespace laboFormes
{
/**
 * \brief constructeur
 * \param[in] p_xCentre la coordonnée cartésienne en x du centre de la forme
 * \param[in] p_yCentre la coordonnée cartésienne en y du centre de la forme
 */
FormeDeuxDimensions::FormeDeuxDimensions(double p_xCentre, double p_yCentre) :
		Forme(p_xCentre, p_yCentre)
{	INVARIANTS();

}
/**
 * \brief Méthode qui s'assure que l'objet est dans un état valide en tout temps
 * implémenté même vide pour les futurs développements
 */
void laboFormes::FormeDeuxDimensions::verifieInvariant() const
{
}
} /* namespace laboFormes */


