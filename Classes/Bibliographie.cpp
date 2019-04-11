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
Bibliographie::Bibliographie(const string& nombiblio) : m_nBibliographie(nombiblio){
	PRECONDITION(!(nombiblio.empty()));

	POSTCONDITION(m_nBibliographie == nombiblio);
}
/**
 * \brief Génère un objet string les éléments de toutes les références enregistrées dans Bibliographie
 * @return Les références formatéses
 */
string Bibliographie::reqBibliographieFormate() const{
	ostringstream os;
	os << m_nBibliographie <<"\n" << "===============================" << endl;
	for (unsigned int i = 0; i < m_vReferences.size(); i++){
		os << "[" << i + 1 << "]" << " " <<   m_vReferences[i]->reqReferenceFormate()<< "\n";
	}
	return os.str();
}
/**
 * \brief Vérifie si l'identifiant en entrée correspond à une Référence déja Présente dans Bibliographie
 * @param p_identifiant
 * @return booléen
 *
 */
Bibliographie::~Bibliographie()
{
	for (vector<Reference*>::iterator i = m_vReferences.begin(); i != m_vReferences.end(); ++i)
	{
 		delete *i;
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
void Bibliographie::ajouterReference (const Reference& p_nouvelleReference)
	{

		if (!(referenceEstDejaPresente(p_nouvelleReference.reqIdentifiant()))) {
			m_vReferences.push_back(p_nouvelleReference.clone());
		}
	};







