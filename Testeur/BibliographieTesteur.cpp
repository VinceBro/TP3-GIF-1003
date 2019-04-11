/*
 * BibliographieTesteur.cpp
 *
 *  Created on: Apr. 10, 2019
 *      Author: root
 */
#include "Bibliographie.h"
#include "ContratException.h"
#include <gtest/gtest.h>

using namespace std;
using namespace biblio;

class UneBiblio : public ::testing::Test
{
public:
	UneBiblio() : biblio1("biblio") {};
	Bibliographie biblio1;
};

TEST(Bibliographie, ConstructeurNormal)
{
	Bibliographie Testeur("Sauceur");
	EXPECT_EQ("Sauceur", Testeur.reqNomBibliographie());

}

TEST(Bibliographie, ConstructeurAvecNomInvalide)
{
	ASSERT_THROW(Bibliographie Testeur(""), PreconditionException);
}

TEST(Bibliographie, ajouterReference)
{
	Bibliographie bibliographieTest("Biblio");
	Ouvrage t_ouvrage(	"Homayoon Beigi",
						"Fundamentals of Speaker Recognition",
						"New York",
						"Springer",
						2011,
						"ISBN 978-0-387-77591-3");
	EXPECT_TRUE((bibliographieTest.reqVecteur()).empty())
	;
	bibliographieTest.ajouterReference(t_ouvrage);
	EXPECT_FALSE((bibliographieTest.reqVecteur()).empty())
	;
	ASSERT_EQ(t_ouvrage.reqReferenceFormate(), (bibliographieTest.reqVecteur())[0]->reqReferenceFormate())
	;

	Journal journalTest(	"Hart",
							"A survey of source code management tools for programming courses",
							"Journal of Computing Sciences in Colleges",
							24,
							6,
							113,
							2009,
							"ISSN 1937-4771");
	bibliographieTest.ajouterReference(journalTest);
	ASSERT_EQ(journalTest.reqReferenceFormate(), (bibliographieTest.reqVecteur())[1]->reqReferenceFormate())
	;
}
