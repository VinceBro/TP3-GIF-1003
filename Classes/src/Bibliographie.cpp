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
Bibliographie::Bibliographie(const Reference& p_nouvelleReference){
	m_vReferences.push_back(p_nouvelleReference.clone());
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
bool Bibliographie::referenceEstDejaPresente(const std::string& p_identifiant) const{
	bool valide = false;
	for (unsigned int i = 0; i < m_vReferences.size(); i++){
		if (m_vReferences[i]->reqIdentifiant() == p_identifiant) valide = true;
	}
	return valide;
}
