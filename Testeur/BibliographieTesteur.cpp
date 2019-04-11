/**
 * \file BibliographieTesteur.cpp
 * \brief Fonctions qui testent la classe Bibliographie (avec google test)
 * \author Vincent Breault
 * \date
 */
#include "Bibliographie.h"
#include "ContratException.h"
#include <gtest/gtest.h>

using namespace std;
using namespace biblio;

/**
 * \brief Test du Constructeur de Bibliographie
 * 				cas invalide : le constructeur est donné un nom vide
 */
TEST(Bibliographie, ConstructeurNormal)
{
	Bibliographie Testeur("sauceur");
	ASSERT_EQ("sauceur", Testeur.reqNomBibliographie());
}

TEST(Bibliographie, ConstructeurAvecNomInvalide)
{
	ASSERT_THROW(Bibliographie Testeur(""), PreconditionException);
}

/**
 * \brief Test de l'ajout d'une Reference avec la fonction ajouterReference
 * 					cas invalide : Le vecteur de references est toujours vide après l'ajout de la reference
 * 					et les References formatés ne sont pas égales
 */
TEST(Bibliographie, ajouteruneReference)
{
	Bibliographie Testeur("Sauceur");
	Ouvrage OuvrageTesteur(	"Homayoon Beigi",
						"Fundamentals of Speaker Recognition",
						"ISBN 978-0-387-77591-3",
						2011,
						"New York",
						"Springer");
	EXPECT_TRUE((Testeur.reqReferences()).empty());

	Testeur.ajouterReference(OuvrageTesteur);
	EXPECT_FALSE((Testeur.reqReferences()).empty());

	ASSERT_EQ(OuvrageTesteur.reqReferenceFormate(), (Testeur.reqReferences())[0]->reqReferenceFormate());


}

TEST(Bibliographie, ajouterdeuxReferences)
{
	Bibliographie Testeur("Sauceur");
	Ouvrage OuvrageTesteur(	"Homayoon Beigi",
						"Fundamentals of Speaker Recognition",
						"ISBN 978-0-387-77591-3",
						2011,
						"New York",
						"Springer");
	EXPECT_TRUE((Testeur.reqReferences()).empty());

	Testeur.ajouterReference(OuvrageTesteur);
	EXPECT_FALSE((Testeur.reqReferences()).empty());

	ASSERT_EQ(OuvrageTesteur.reqReferenceFormate(), (Testeur.reqReferences())[0]->reqReferenceFormate());
	Journal JournalTesteur(	"Hart",
								"A survey of source code management tools for programming courses",
								"ISSN 1937-4771",
								2009,
								"Journal of Computing Sciences in Colleges",
								24,
								6,
								113);
		Testeur.ajouterReference(JournalTesteur);
		ASSERT_EQ(JournalTesteur.reqReferenceFormate(), (Testeur.reqReferences())[1]->reqReferenceFormate())
		;


}
/**
 * \brief Test ajout Reference Existante
 * 			cas invalide : la longueur du vecteur de references est plus grand que 1
 */
TEST(Bibliographie, ajouterReferenceExistante)
{
	Bibliographie Testeur("Sauceur");
		Ouvrage OuvrageTesteur(	"Homayoon Beigi",
							"Fundamentals of Speaker Recognition",
							"ISBN 978-0-387-77591-3",
							2011,
							"New York",
							"Springer");
		EXPECT_TRUE((Testeur.reqReferences()).empty());

		Testeur.ajouterReference(OuvrageTesteur);
		EXPECT_FALSE((Testeur.reqReferences()).empty());
		Testeur.ajouterReference(OuvrageTesteur);
		EXPECT_EQ(1, Testeur.reqReferences().size());

}


/**
 * \brief Test de Bibliographie formate (s'il est adéquat)
 */
TEST(Bibliographie, reqReferenceFormate){
	ostringstream os;
	Bibliographie Testeur("Sauceur");
	Ouvrage OuvrageTesteur(	"Homayoon Beigi",
								"Fundamentals of Speaker Recognition",
								"ISBN 978-0-387-77591-3",
								2011,
								"New York",
								"Springer");
	Testeur.ajouterReference(OuvrageTesteur);
	os << "Sauceur" << endl;
		os << "===============================" << endl;
		os << "[" << 1 << "]" << " " << OuvrageTesteur.reqReferenceFormate() << endl;
		ASSERT_EQ(os.str(), Testeur.reqBibliographieFormate()) << Testeur.reqBibliographieFormate();
	;
}































