/*
 * Ouvrage.cpp
 *
 *  Created on: Apr. 6, 2019
 *      Author: root
 */
#include "Ouvrage.h"
using namespace std;
using namespace biblio;
Ouvrage::Ouvrage(const string auteurs, const std::string titre,
		const std::string identifiant, const int annee, const std::string editeur,
		const std::string ville) : biblio::Reference(auteurs, titre, identifiant, annee)
{
	if (util::validerFormatNom(editeur) && util::validerFormatNom(ville))
	{
	m_editeur = editeur;
	m_ville = ville;
	} else cout << "Erreur du constructeur de Ouvrage mon excellent ami" << endl;
}
std::string Ouvrage::reqReferenceFormate() const{
	ostringstream os;
	os << m_auteurs << ". " << m_titre << ". "<<
			m_ville << " : " << m_editeur <<", " <<
			m_annee << ". " << m_identifiant;
	return os.str();
}
