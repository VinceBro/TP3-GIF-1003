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
	if (util::validerFormatNom(nom) && volume >= 0 && numero >=0 && page >= 0)
	{
	m_nom= nom;
	m_volume= volume;
	m_numero= numero;
	m_page= page;
	}
}
/**
 * \brief Génère un objet string formaté
 * @return Journal formaté
 */
std::string Journal::reqReferenceFormate() const{
	ostringstream os;
	os << m_auteurs << ". " << m_titre << ". "<< m_nom << ", vol. " <<
			m_volume << ", no. " << m_numero << ", pp. " << m_page <<
			", " << m_annee << ". " << m_identifiant;
	return os.str();
}

