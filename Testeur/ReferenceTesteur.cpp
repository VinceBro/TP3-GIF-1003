/*
 * ReferenceTesteur.cpp
 *
 *  Created on: Apr. 7, 2019
 *      Author: root
 */
#include "Reference.h"
#include <gtest/gtest.h>

using namespace std;
using namespace biblio;


class TestReference : public Reference
{
public:
	TestReference(const string auteurs, const string titre, const string identifiant, const int annee):
		Reference(auteurs, titre, identifiant, annee) {};
	virtual Reference* clone() const
		{
			return new TestReference(*this);
		};
		virtual std::string reqReferenceFormate() const
		{
			return "que la sauce soit avec toi";
	};
};

class UneRef : public ::testing::Test
{
	UneRef(): ref_1("Homayoon Beigi", "Fundamentals of Speaker Recognition", "ISBN 978-3-16-148410-0", 2008)
		{};
	TestReference ref_1;
};

TEST(Reference, ConstructeurNormal)
{
	TestReference Testeur ("Mon grand ami",
			"Fundamentals of Speaker Recognition",
			"ISBN 978-0-387-77591-3",
			2008);
	ASSERT_EQ("Mon grand ami", Testeur.reqAuteurs());

	ASSERT_EQ("Fundamentals of Speaker Recognition", Testeur.reqTitre());

	ASSERT_EQ("ISBN 978-0-387-77591-3", Testeur.reqIdentifiant());

	ASSERT_EQ(2008, Testeur.reqAnnee());

}

TEST(Reference, ConstructeurAuteurVide)
{
	ASSERT_THROW(TestReference Testeur("","Fundamentals of Speaker Recognition",
			"ISBN 978-0-387-77591-3", 2008), PreconditionException) << "Stop la sauce mon enorme ami";
}

TEST(Reference, ConstructeurAuteurInvalide)
{
	ASSERT_THROW(TestReference Testeur("Ce-Nom%est&invalide","Fundamentals of Speaker Recognition",
			"ISBN 978-0-387-77591-3", 2008), PreconditionException);
	ASSERT_THROW(TestReference Testeur("33lol33","Fundamentals of Speaker Recognition",
				"ISBN 978-0-387-77591-3", 2008), PreconditionException);
	ASSERT_THROW(TestReference Testeur("  Vincebro","Fundamentals of Speaker Recognition",
				"ISBN 978-0-387-77591-3", 2008), PreconditionException);
	ASSERT_THROW(TestReference Testeur("3 invalide 2","Fundamentals of Speaker Recognition",
				"ISBN 978-0-387-77591-3", 2008), PreconditionException);
}
TEST(Reference, ConstructeurAnneeInvalide)
{
	ASSERT_THROW(TestReference Testeur("Mon grand ami",
			"Fundamentals of Speaker Recognition",
			"ISBN 978-0-387-77591-3",
			-672), PreconditionException);
}

TEST(Reference, ConstructeurIdentifiantInvalide)
{
	ASSERT_THROW(TestReference Testeur("Mon grand ami",
				"Fundamentals of Speaker Recognition",
				"ISBN 9780387775913",
				2008), PreconditionException) << "Toute collé";
	ASSERT_THROW(TestReference Testeur("Mon grand ami",
				"Fundamentals of Speaker Recognition",
				"ISBN 972-0-387-77591-3",
				2008), PreconditionException) << "Changé un chiffre";
	ASSERT_THROW(TestReference Testeur("Mon grand ami",
				"Fundamentals of Speaker Recognition",
				"ISSBN 978-0-387-77591-3",
				2008), PreconditionException) << "ISSBN";
	ASSERT_THROW(TestReference Testeur("Mon grand ami",
				"Fundamentals of Speaker Recognition",
				"ISSN 978-0-387-77591-3",
				2008), PreconditionException) << "ISSN pas rapport";
	ASSERT_THROW(TestReference Testeur("Mon grand ami",
				"Fundamentals of Speaker Recognition",
				"ISBN 978-0-387-591-3",
				2008), PreconditionException) << "Enlevé des chiffres";
	ASSERT_NO_THROW(TestReference Testeur("Mon grand ami",
					"Fundamentals of Speaker Recognition",
					"ISSN 0032-1478",
					2008)) << "Cas ISSN qui est supposé marcher";
}
