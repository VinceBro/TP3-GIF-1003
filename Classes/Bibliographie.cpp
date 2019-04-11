/**
 * \file Bibliographie.cpp
 * \brief Implémentation de la classe Bibliographie pour gérer les références
 * \author Vincent Breault
 * \date
 */
#include "Bibliographie.h"
using namespace std;
using namespace biblio;
/**
 * \brief TODO Y FAUT SASSURER QUE LE CONSTRUCTEUR EST BON
 * @param p_nouvelleReference
 */
Bibliographie::Bibliographie(const string nombiblio){
	PRECONDITION(!(nombiblio.empty()));

	m_nBibliographie = nombiblio;

	POSTCONDITION(m_nBibliographie == nombiblio);

	INVARIANTS();
}
/**
 * \brief Génère un objet string les éléments de toutes les références enregistrées dans Bibliographie
 * @return Les références formatées
 */
string Bibliographie::reqBibliographieFormate() const{
	ostringstream os;
	os << "Bibliographie\n" << "===============================\n" << endl;
	for (unsigned int i = 0; i < m_vReferences.size(); i++){
		os << "[" << i << "]" <<  m_vReferences[i]->reqReferenceFormate()<< "\n";
	}
	return os.str();
}
/**
 * \brief Vérifie si l'identifiant en entrée correspond à une Référence déja Présente dans Bibliographie
 * @param p_identifiant
 * @return booléen
 */

Bibliographie::~Bibliographie(){
	for (unsigned int i = m_vReferences.size(); i<=0; i--){
		delete m_vReferences[i];
	}
}
bool Bibliographie::referenceEstDejaPresente(const std::string& p_identifiant) const{
	bool valide = false;
	for (unsigned int i = 0; i < m_vReferences.size(); i++){
		if (m_vReferences[i]->reqIdentifiant() == p_identifiant) valide = true;
	}
	return valide;
}
const std::string& Bibliographie::reqNomBibliographie() const
{
	return m_nBibliographie;
}
std::vector<Reference*> Bibliographie::reqReferences() const
{return m_vReferences;};
void Bibliographie::verifieInvariant() const{
	INVARIANT(!(m_nBibliographie.empty()));
}







