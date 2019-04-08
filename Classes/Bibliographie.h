/**
 * \file Bibliographie.h
 * \brief Classe pour gérer les références Bibliographie
 * \author Vincent Breault
 * \date
 */
#ifndef BIBLIOGRAPHIE_H_
#define BIBLIOGRAPHIE_H_
#include "Reference.h"
#include "Ouvrage.h"
#include "Journal.h"
#include <vector>

namespace biblio{
/**
 * \class Bibliographie
 * \brief Gère les références
 */
class Bibliographie
{
public:
	Bibliographie(const Reference& p_nouvelleReference);
	/**
	 * \brief Ajoute une référence dans m_vReferences
	 * @param p_nouvelleReference (La référence à ajouter)
	 */
	void ajouterReference (const Reference& p_nouvelleReference)
	{
		m_vReferences.push_back(p_nouvelleReference.clone());
	};
	std::string reqBibliographieFormate() const;
	~Bibliographie();
	//Classe de forme Coplien, opérateur d'assignation et constructeur de copie pas sur
	//Vraiment pas sur de celle là
	//Bibliographie* clone() const {return new Ouvrage(*this);};
private:
	std::vector<biblio::Reference*> m_vReferences;

	//Permet de vérifier si la bibliographie a déjà une référence
	bool referenceEstDejaPresente(const std::string& p_identifiant) const;

};

}

#endif /* BIBLIOGRAPHIE_H_ */
