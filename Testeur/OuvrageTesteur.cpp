/**
 * \file OuvrageTesteur.cpp
 * \brief Fonctions qui testent la classe Ouvrage (avec google test)
 * \author Vincent Breault
 * \date
 */
#include "Ouvrage.h"
#include "ContratException.h"
#include <gtest/gtest.h>

using namespace std;
using namespace biblio;

class UnOuvr: public ::testing::Test
{
public:
	UnOuvr():
		Ouvr1(	"Homayoon Beigi",
					"Fundamentals of Speaker Recognition",
					"ISBN 978-0-387-77591-3",
					2008,
					"New York",
					"Springer")
		{};
	Ouvrage Ouvr1;
};

TEST(Ouvrage, ConstructeurNormal)
{
	Ouvrage Testeur("Homayoon Beigi",
			"Fundamentals of Speaker Recognition",
			"ISBN 978-0-387-77591-3",
			2008,
			"New York",
			"Springer");

	ASSERT_EQ("Homayoon Beigi", Testeur.reqAuteurs())
	;
	ASSERT_EQ("Fundamentals of Speaker Recognition", Testeur.reqTitre())
	;
	ASSERT_EQ("New York", Testeur.reqVille())
	;
	ASSERT_EQ("Springer", Testeur.reqEditeur())
	;
	ASSERT_EQ(2008, Testeur.reqAnnee())
	;
	ASSERT_EQ("ISBN 978-0-387-77591-3", Testeur.reqIdentifiant());
}

TEST(Ouvrage, ConstructeurVilleInvalide)
{

	ASSERT_THROW(Ouvrage ouvrageTest("Homayoon Beigi", "Fundamentals of Speaker Recognition",  "ISBN 978-0-387-77591-3", 2008, "New&&York", "Springer"),
			PreconditionException);
	ASSERT_THROW(Ouvrage ouvrageTest("Homayoon Beigi", "Fundamentals of Speaker Recognition", "ISBN 978-0-387-77591-3",2008, "", "Springer"),
				PreconditionException);
	ASSERT_THROW(Ouvrage ouvrageTest("Homayoon Beigi", "Fundamentals of Speaker Recognition",  "ISBN 978-0-387-77591-3",2008, "4 New York 2", "Springer"),
PreconditionException);
}

TEST(Ouvrage, ConstructeurEditeurInvalide)
{
	ASSERT_THROW(Ouvrage ouvrageTest("Homayoon Beigi", "Fundamentals of Speaker Recognition", "ISBN 978-0-387-77591-3",2008, "New York", ""),
				PreconditionException);
	ASSERT_THROW(Ouvrage ouvrageTest("Homayoon Beigi", "Fundamentals of Speaker Recognition",  "ISBN 978-0-387-77591-3",2008, "New York", "%"),
				PreconditionException);
	ASSERT_THROW(Ouvrage ouvrageTest("Homayoon Beigi", "Fundamentals of Speaker Recognition",  "ISBN 978-0-387-77591-3",2008, "New York", "3 Springer 2"),
				PreconditionException);
	ASSERT_THROW(Ouvrage ouvrageTest("Homayoon Beigi", "Fundamentals of Speaker Recognition",  "ISBN 978-0-387-77591-3",2008, "New York", "Spr&&%inger"),
				PreconditionException);
}

TEST(Ouvrage, ConstructeurIdentifiantInvalide)
{
	ASSERT_THROW(Ouvrage ouvrageTest("Homayoon Beigi", "Fundamentals of Speaker Recognition", "ISBN sss 978-0-387-77591-3",2008, "New York", "Springer"),
					PreconditionException);
	ASSERT_THROW(Ouvrage ouvrageTest("Homayoon Beigi", "Fundamentals of Speaker Recognition", "",2008, "New York", "Springer"),
					PreconditionException);
	ASSERT_THROW(Ouvrage ouvrageTest("Homayoon Beigi", "Fundamentals of Speaker Recognition", "ISBN sss 978888-0-387-77591-3",2008, "New York", "Springer"),
					PreconditionException);

}

TEST_F(UnOuvr, reqEditeur)
{
	ASSERT_EQ("Springer", Ouvr1.reqEditeur());
}

TEST_F(UnOuvr, reqVille)
{
	ASSERT_EQ("New York", Ouvr1.reqVille());
}

TEST_F(UnOuvr, reqReferenceFormate)
{
	EXPECT_EQ("Homayoon Beigi. Fundamentals of Speaker Recognition. New York : Springer, 2008. ISBN 978-0-387-77591-3.",
			Ouvr1.reqReferenceFormate());
}

TEST_F(UnOuvr, Clone)
{
	Reference* clone = Ouvr1.clone();
	ASSERT_EQ(Ouvr1.reqReferenceFormate(), clone->reqReferenceFormate())
	;
}
