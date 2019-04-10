/**
 * \file Reference.cpp
 * \brief Implémentation de la classe de base abstraite Reference
 * \author Vincent Breault
 * \date
 */

#include "Reference.h"

using namespace std;
using namespace biblio;
/**
 * \brief TODO J'ai aucune idée quoi documenter pour main
 * @return
 */
/**
 * \brief Constructeur avec paramètre, Construction d'un objet Reference à partir des valeurs passées en paramètre
 * @param[in] auteurs correspond au nom du ou des auteurs (string)
 * @param[in] titre correspond au titre (string)
 * @param[in] identifiant correspond au ISBN ou au ISSN (string)
 * @param[in] annee correspond à l'année (int)
 */
Reference::Reference(const string auteurs, const string titre, const string identifiant, int annee){
	PRECONDITION(util::validerFormatNom(auteurs));
	PRECONDITION(!(titre.empty()));
	PRECONDITION(annee >= 0);
	PRECONDITION(util::validerCodeIsbn(identifiant) || util::validerCodeIssn(identifiant));


	if (util::validerFormatNom(auteurs) && (!(titre.empty()) &&
		(util::validerCodeIsbn(identifiant) || util::validerCodeIssn(identifiant)) &&
		(annee >= 0)))
	{
	m_auteurs = auteurs;
	m_titre = titre;
	m_identifiant = identifiant;
	m_annee = annee;
	}
	else cout << "Erreur du constructeur de Reference mon excellent ami" << endl;

	POSTCONDITION(m_auteurs == auteurs);
	POSTCONDITION(m_titre == titre);
	POSTCONDITION(m_annee == annee);
	POSTCONDITION(m_identifiant == identifiant);

	INVARIANTS();

}

/**
 * \brief Modifie l'auteur si le format est valide
 * @param auteurs
 */
void Reference::modif_auteurs(const string auteurs){
	PRECONDITION(util::validerFormatNom(auteurs));

    if (util::validerFormatNom(auteurs)) m_auteurs = auteurs;

    POSTCONDITION(m_auteurs == auteurs);

    INVARIANTS();
}

/**
 * \brief détermine si deux objets Reference sont égaux en comparant les attributs
 * @param c_ref pointeur d'un objet Reference
 * @return booléen
 */
bool Reference::operator==(Reference *c_ref){
   return((c_ref-> m_auteurs == m_auteurs) && (c_ref-> m_titre == m_titre) && (c_ref-> m_identifiant == m_identifiant) &&(c_ref->m_annee == m_annee));
   }
void Reference::verifieInvariant() const
{
	INVARIANT(util::validerFormatNom(m_auteurs));
	INVARIANT(!(m_titre.empty()));
	INVARIANT(m_annee >= 0);
}

