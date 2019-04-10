/*
 * JournalTesteur.cpp
 *
 *  Created on: Apr. 10, 2019
 *      Author: root
 */

#include "Journal.h"
#include "ContratException.h"
#include <gtest/gtest.h>

using namespace std;
using namespace biblio;

class UnJourn: public ::testing::Test
{
public:
	UnJourn():
		journ1(	"Hart",
				"A survey of source code management tools for programming courses",
				"ISSN 1937-4771",
				2009,
				"Journal of Computing Sciences in Colleges",
				107,
				273,
				6)
		{};
	Journal journ1;
};

TEST(Journal, ConstructeurNormal)
{
	Journal Testeur(	"Hart",
			"A survey of source code management tools for programming courses",
			"ISSN 1937-4771",
			2009,
			"Journal of Computing Sciences in Colleges",
			107,
			273,
			6);
	EXPECT_EQ("Hart", Testeur.reqAuteurs())
	;
	EXPECT_EQ("A survey of source code management tools for programming courses", Testeur.reqTitre())
	;
	EXPECT_EQ("Journal of Computing Sciences in Colleges", Testeur.reqNom())
	;
	ASSERT_EQ(107, Testeur.reqVolume())
	;
	ASSERT_EQ(273, Testeur.reqNumero())
	;
	ASSERT_EQ(6, Testeur.reqPage())
	;
	ASSERT_EQ(2009, Testeur.reqAnnee())
	;
	EXPECT_EQ("ISSN 1937-4771", Testeur.reqIdentifiant());
	;
}

TEST(Journal, ConstructeurNomInvalide)
{
	ASSERT_THROW(Journal Testeur("Hart",
			"A survey of source code management tools for programming courses",
			"ISSN 1937-4771",
			2009,
			"",
			107,
			273,
			6), PreconditionException);

}

TEST(Journal, ConstructeurVolumeInvalide)
{
	ASSERT_THROW(Journal Testeur("Hart",
			"A survey of source code management tools for programming courses",
			"ISSN 1937-4771",
			2009,
			"Journal of Computing Sciences in Colleges",
			-467,
			273,
			6), PreconditionException);
}

TEST(Journal, ConstructeurNumeroInvalide)
{
	ASSERT_THROW(Journal Testeur(	"Hart",
			"A survey of source code management tools for programming courses",
			"ISSN 1937-4771",
			2009,
			"Journal of Computing Sciences in Colleges",
			107,
			-321,
			6), PreconditionException);
}

TEST(Journal, ConstructeurPageInvalide)
{
	ASSERT_THROW(Journal Testeur(	"Hart",
			"A survey of source code management tools for programming courses",
			"ISSN 1937-4771",
			2009,
			"Journal of Computing Sciences in Colleges",
			107,
			273,
			0), PreconditionException);

	ASSERT_THROW(Journal Testeur("Hart",
				"A survey of source code management tools for programming courses",
				"ISSN 1937-4771",
				2009,
				"Journal of Computing Sciences in Colleges",
				107,
				273,
				-1), PreconditionException);
}

TEST_F(UnJourn, reqNom)
{
	EXPECT_EQ("Journal of Computing Sciences in Colleges", journ1.reqNom());
}

TEST_F(UnJourn, reqVolume)
{
	EXPECT_EQ(107, journ1.reqVolume());
}

TEST_F(UnJourn, reqNumero)
{
	EXPECT_EQ(273, journ1.reqNumero());
}

TEST_F(UnJourn, reqPage)
{
	EXPECT_EQ(6, journ1.reqPage());
}


TEST_F(UnJourn, reqReferenceFormate)
{
	EXPECT_EQ("Hart. A survey of source code management tools for programming courses. Journal of Computing Sciences in Colleges, vol. 107, no. 273, pp. 6, 2009. ISSN 1937-4771.",
				journ1.reqReferenceFormate())<< journ1.reqReferenceFormate();
}

TEST_F(UnJourn, Clone)
{
	Reference* clone = journ1.clone();
	ASSERT_EQ(journ1.reqReferenceFormate(), clone->reqReferenceFormate())
	;
}

