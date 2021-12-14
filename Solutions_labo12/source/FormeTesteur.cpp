/**
 * \file FormeTesteur.cpp
 * \brief pour le test unitaire de la classe abstraite Forme
 * \author the
 * \version 0.1
 * \date 2018-12-03
 */

#include<gtest/gtest.h>
#include <string>
#include "Forme.h"

using namespace laboFormes;

/**
 * \class FormeDeTest
 * \brief Création d'une classe concrète qui hérite de Forme pour les tests unitaires.
 */
class FormeDeTest: public Forme
{
public:
	FormeDeTest(double p_xCentre, double p_yCentre) :
			Forme(p_xCentre, p_yCentre)
	{
	}
	// méthode virtuelle pure dans la classe de base, doit être implémentée.
	// Appelle cette méthode pour pouvoir la tester.
	virtual std::string reqFormeFormate() const
	{
		return Forme::reqFormeFormate();
	}
};

/**
 * \brief Test du constructeur avec paramètres
 *        cas valide
 *        ConstructeurParametreValides: création d'une activité et vérification de l'assignation de tous les attributs.
 */
TEST(ConstructeurForme,ConstructeurParametreValides)
{
	FormeDeTest t_forme(1.2, 2.3);
	EXPECT_EQ(1.2, t_forme.reqXCentre());
	EXPECT_EQ(2.3, t_forme.reqYCentre());
}

/**
 * \class UneForme
 * \brief Création d'une fixture pour la création d'un objet FormeDeTest utilisé dans les tests unitaires.
 */
class UneForme: public ::testing::Test
{
public:
	UneForme() :
			t_forme(1.2, 2.3)
	{

	}
	;
	FormeDeTest t_forme;
};
/**
 * \brief Test de l'accesseur de x
 *
 * cas valide : <br> test du retour
 */
TEST_F(UneForme, accesseurX)
{
	ASSERT_EQ(1.2, t_forme.reqXCentre());
}

/**
 * \brief Test de l'Accesseur de y
 *
 * cas valide : <br> test du retour
 */
TEST_F(UneForme, accesseurY)
{
	ASSERT_EQ(2.3, t_forme.reqYCentre());
}
/**
 * \brief Test de reqFormeFormate
 *
 * cas valide : <br> test du retour
 */
TEST_F(UneForme, reqFormate)
{
	std::string sortie ("Centre en (1.2,2.3)");
	ASSERT_EQ(sortie, t_forme.reqFormeFormate());
}
