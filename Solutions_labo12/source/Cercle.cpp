/**
 * \file Cercle.cpp
 * \brief
 * \author THE
 * \version 0.1
 * \date 2018-12-03
 */
#include <sstream>
#include "Cercle.h"
#include "ContratException.h"
using namespace std;

namespace laboFormes
{
/**
 * \brief constructeur
 * \param[in] p_rayon
 * \pre >0
 * \param[in] p_xCentre coordonnées en x du centre
 * \param[in] p_yCentre coordonnées en y du centre
 * \post l'objet est construit et est valide
 */
Cercle::Cercle(double p_rayon, double p_xCentre, double p_yCentre) :
		FormeDeuxDimensions(p_xCentre, p_yCentre), m_rayon(p_rayon)
{
	PRECONDITION(p_rayon > 0);
	POSTCONDITION(m_rayon == p_rayon);
	INVARIANTS();
}
/**
 * \brief Pour retourner les informations sur un objet formatées dans une chaine de caractères.
 * \return un objet string contenant les informations sur l'objet forme courant.
 */
std::string Cercle::reqFormeFormate() const
{
	ostringstream os;
	os << "Cercle de rayon : " << m_rayon << " " << Forme::reqFormeFormate()
			<< endl << "d'aire : " << aire();
	return os.str();
}
/**
 * \brief retourne l'aide du cercle courant
 * \return l'aire du cercle
 */
double Cercle::aire() const
{
	return 3.14159 * m_rayon * m_rayon;
}
/**
 * \brief accesseur du rayon du cercle
 */
double laboFormes::Cercle::reqRayon() const
{
	return m_rayon;
}
/**
 * \brief Méthode qui s'assure que l'objet Cercle est dans un état valide en tout temps
 */
void Cercle::verifieInvariant() const
{
	INVARIANT(m_rayon > 0);
}

} /* namespace laboFormes */

