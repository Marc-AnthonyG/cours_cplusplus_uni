/*
 * Sphere.cpp
 *
 *  Created on: 2018-12-03
 *      Author: THE
 */
#include <sstream>

#include "Sphere.h"
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
Sphere::Sphere(double p_rayon, double p_xCentre, double p_yCentre) :
		FormeTroisDimensions(p_xCentre, p_yCentre), m_rayon(p_rayon)
{
	PRECONDITION(p_rayon > 0);
	POSTCONDITION(m_rayon == p_rayon);
	INVARIANTS();
}
/**
 * \brief Pour retourner les informations sur un objet formatées dans une chaine de caractères.
 * \return un objet string contenant les informations sur l'objet forme courant.
 */
string laboFormes::Sphere::reqFormeFormate() const
{
	ostringstream os;
	os << "Sphere de rayon : " << m_rayon << " " << Forme::reqFormeFormate()
			<< endl << "d'aire : " << aire() << " et de volume : " << volume();
	return os.str();
}
/**
 * \brief retourne l'aire de la sphère courante
 * \return l'aire de la sphère
 */
double laboFormes::Sphere::aire() const
{
	return 4 * 3.14159 * m_rayon * m_rayon;
}
/**
 * \brief retourne le volume de la sphère courante
 * \return le volume de la sphère
 */
double laboFormes::Sphere::volume() const
{
	return 4.0 / 3.0 * 3.14159 * m_rayon * m_rayon * m_rayon;
}

/**
 * \brief accesseur du rayon de la sphère
 */
double Sphere::reqRayon() const
{
	return m_rayon;
}

/**
 * \brief Méthode qui s'assure que l'objet Forme sont dans un état valide en tout temps
 */
void laboFormes::Sphere::verifieInvariant() const
{
	INVARIANT(m_rayon > 0);
}
} /* namespace laboFormes */
