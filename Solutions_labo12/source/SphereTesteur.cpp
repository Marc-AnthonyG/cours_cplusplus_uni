/**
 * \file SphereTesteur.cpp
 * \brief
 * \author etudiant
 * \version 0.1
 * \date 2018-12-03
 */
#include <iostream>
#include<gtest/gtest.h>
#include <string>
#include "Sphere.h"
#include "ContratException.h"

using namespace laboFormes;

/**
 * \brief Test du constructeur avec paramètres
 *        cas valide
 *        ConstructeurParametreValides: création d'une activité et vérification de l'assignation de tous les attributs.
 *        cas invalide : rayon négatif
 */
TEST(ConstructeurSphere,ConstructeurParametreValides)
{
	Sphere t_sphere(5, 1.2, 2.3);
	EXPECT_EQ(1.2, t_sphere.reqXCentre());
	EXPECT_EQ(2.3, t_sphere.reqYCentre());
	EXPECT_EQ(5, t_sphere.reqRayon());
}
//cas invalide : rayon négatif
TEST(ConstructeurSphere,ConstructeurParametreInvalides)
{
	ASSERT_THROW(Sphere(-5, 1.2, 2.3), PreconditionException);
}
/**
 * \class UneSphere
 * \brief Création d'une fixture pour la création d'un objet Sphere utilisé dans les tests unitaires.
 */
class UneSphere: public ::testing::Test
{
public:
	UneSphere() :
			t_sphere(5, 1.2, 2.3)
	{

	}
	;
	Sphere t_sphere;
};
/**
 * \brief Test de aire
 */
TEST_F(UneSphere,aire)
{
	ASSERT_EQ(4 * 3.14159 * 5 * 5, t_sphere.aire());
}
/**
 * \brief Test de volume
 */
TEST_F(UneSphere,volume)
{
	ASSERT_EQ(4.0 / 3.0 *3.14159 * 5 * 5 * 5, t_sphere.volume());
}
/**
 * \brief Test de l'accesseur du rayon
 */
TEST_F(UneSphere,accesseurRayon)
{
	ASSERT_EQ(5, t_sphere.reqRayon());
}

/**
 * \brief Test de reqFormeFormate
 *
 * cas valide : <br> test du retour
 */
TEST_F(UneSphere, reqFormate)
{
	std::string sortie(
			"Sphere de rayon : 5 Centre en (1.2,2.3)\nd'aire : 314.159 et de volume : 523.598");
	ASSERT_EQ(sortie, t_sphere.reqFormeFormate());
}
