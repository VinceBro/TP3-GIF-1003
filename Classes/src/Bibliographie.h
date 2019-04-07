/*
 * Bibliographie.h
 *
 *  Created on: Apr. 7, 2019
 *      Author: root
 */

#ifndef BIBLIOGRAPHIE_H_
#define BIBLIOGRAPHIE_H_
#include "Reference.h"
#include "Ouvrage.h"
#include "Journal.h"
#include <vector>

namespace biblio{
class Bibliographie
{
public:
	Bibliographie(const Reference& p_nouvelleReference);
	void ajouterReference (const Reference& p_nouvelleReference)
	{
		m_vReferences.push_back(p_nouvelleReference.clone());
	};
	std::string reqBibliographieFormate() const;
	~Bibliographie();

private:
	std::vector<biblio::Reference*> m_vReferences;

	//Permet de vérifier si la bibliographie a déjà une référence
	bool referenceEstDejaPresente(const std::string& p_identifiant) const;

};

}

#endif /* BIBLIOGRAPHIE_H_ */
