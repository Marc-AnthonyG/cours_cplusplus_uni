/**
 * \file Forme.cpp
 * \brief  implémentation des méthode de la classe Forme
 * \author the
 * \version 0.1
 * \date 2018-12-03
 */
#include <sstream>
#include "Forme.h"
#include "ContratException.h"

using namespace std;

namespace laboFormes
{

/**
 * \brief constructeur
 * \param[in] p_xCentre la coordonnée cartésienne en x du centre de la forme
 * \param[in] p_yCentre la coordonnée cartésienne en y du centre de la forme
 * \post l'objet est construit
 */
Forme::Forme(double p_xCentre, double p_yCentre) :
		m_xCentre(p_xCentre), m_yCentre(p_yCentre)
{
	POSTCONDITION(m_xCentre == p_xCentre);
	POSTCONDITION(m_yCentre == p_yCentre);
	INVARIANTS();
}

/**
 * \brief accesseur pour le centre de la forme
 * \return le centre en x
 */
double Forme::reqXCentre() const
{
	return m_xCentre;
}
/**
 * \brief accesseur pour le centre de la forme
 * \return le centre en y
 */
double Forme::reqYCentre() const
{
	return m_yCentre;
}

/**
 * \brief Pour retourner les informations sur un objet forme formatées dans une chaine de caractères.
 * \return un objet string contenant les informations sur l'objet forme courant.
 */
string Forme::reqFormeFormate() const
{
	ostringstream os;
	os << "Centre en (" << m_xCentre << "," << m_yCentre << ")";
	return os.str();
}

/**
 * \brief Méthode qui s'assure que l'objet Forme sont dans un état valide en tout temps
 * implémenté même vide pour les futurs développements
 */
void Forme::verifieInvariant() const
{
}

} /* namespace laboFormes */
