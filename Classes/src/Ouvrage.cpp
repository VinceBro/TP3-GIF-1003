/*
 * Ouvrage.cpp
 *
 *  Created on: Apr. 6, 2019
 *      Author: root
 */
#include "Ouvrage.h"
using namespace std;
Ouvrage::Ouvrage(const string auteurs, const std::string titre, const std::string identifiant, const int annee, const std::string editeur, const std::string ville) : biblio::Reference(auteurs, titre, identifiant, annee)
{
	m_editeur = editeur;
	m_ville = ville;
}
std::string Ouvrage::reqReferenceFormate() const{
	ostringstream os;
	os << m_auteurs << ". " << m_titre << ". "<<
			m_ville << " : " << m_editeur <<", " <<
			m_annee << ". " << m_identifiant;
	return os.str();
}