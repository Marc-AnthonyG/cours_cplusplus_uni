/**
 * \file FormeTroisDimensions.cpp
 * \brief  implémentation de la classe abstraite forme en trois dimension
 * \author the
 * \version 0.1
 * \date 2018-12-03
 */
#include "FormeTroisDimensions.h"
#include "ContratException.h"

namespace laboFormes
{
/**
 * \brief constructeur
 * \param[in] p_xCentre la coordonnée cartésienne en x du centre de la forme
 * \param[in] p_yCentre la coordonnée cartésienne en y du centre de la forme
 */
FormeTroisDimensions::FormeTroisDimensions(double p_xCentre, double p_yCentre) :
		Forme(p_xCentre, p_yCentre)
{
	INVARIANTS();
}
/**
 * \brief Méthode qui s'assure que l'objet est dans un état valide en tout temps
 * implémenté même vide pour les futurs développements
 */
void laboFormes::FormeTroisDimensions::verifieInvariant() const
{
}
} /* namespace laboFormes */

