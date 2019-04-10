/**
 * \file Journal.cpp
 * \brief Implémentation de la classe Journal dérivée de Reference
 * \author Vincent Breault
 * \date
 */
#include "Journal.h"
using namespace std;
using namespace biblio;
/**
 * \brief Constructeur avec paramètre, Construction d'un objet Journal à partir des valeurs passées en paramètre
 * @param auteurs
 * @param titre
 * @param identifiant
 * @param annee
 * @param nom
 * @param volume
 * @param numero
 * @param page
 */
Journal::Journal(const string auteurs, const string titre,
		const string identifiant, const int annee, const string nom,
		const int volume, const int numero, const int page) :
				biblio::Reference(auteurs, titre, identifiant, annee)
{
	PRECONDITION(!(nom.empty()));
	PRECONDITION(volume >= 0);
	PRECONDITION(numero >= 0);
	PRECONDITION(page > 0);
	if (util::validerFormatNom(nom) && volume >= 0 && numero >=0 && page >= 0)
	{
	m_nom= nom;
	m_volume= volume;
	m_numero= numero;
	m_page= page;
	}
	POSTCONDITION(m_nom == nom);
	POSTCONDITION(m_volume ==volume);
	POSTCONDITION(m_numero == numero);
	POSTCONDITION(m_page == page);

	INVARIANTS();

}
/**
 * \brief Génère un objet string formaté
 * @return Journal formaté
 */
std::string Journal::reqReferenceFormate() const{
	ostringstream os;
	os << m_auteurs << ". " << m_titre << ". "<< m_nom << ", vol. " <<
			m_volume << ", no. " << m_numero << ", pp. " << m_page <<
			", " << m_annee << ". " << m_identifiant << ".";
	return os.str();
}
void Journal::verifieInvariant() const
{
	INVARIANT(!(m_nom.empty()));
	INVARIANT(m_volume >= 0);
	INVARIANT(m_numero >= 0);
	INVARIANT(m_page > 0);
}

