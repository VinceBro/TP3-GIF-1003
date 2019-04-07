/*
 * Journal.cpp
 *
 *  Created on: Apr. 7, 2019
 *      Author: root
 */
#include "Journal.h"
using namespace std;
using namespace biblio;
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

std::string Journal::reqReferenceFormate() const{
	ostringstream os;
	os << m_auteurs << ". " << m_titre << ". "<< m_nom << ", vol. " <<
			m_volume << ", no. " << m_numero << ", pp. " << m_page <<
			", " << m_annee << ". " << m_identifiant;
	return os.str();
}

