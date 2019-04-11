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
	Bibliographie(const std::string& nombiblio);
	~Bibliographie();
	/**
	 * \brief Ajoute une référence dans m_vReferences
	 * @param p_nouvelleReference (La référence à ajouter)
	 */
	const std::string& reqNomBibliographie() const;
	std::vector<Reference*> reqReferences() const;
	void ajouterReference (const Reference& p_nouvelleReference);
	std::string reqBibliographieFormate() const;
private:
	std::vector<biblio::Reference*> m_vReferences;
	std::string m_nBibliographie;
	Bibliographie(const biblio::Bibliographie&);
	const Bibliographie& operator=(const Bibliographie& bibliographie);
	bool referenceEstDejaPresente(const std::string& p_identifiant) const;

};

}

#endif /* BIBLIOGRAPHIE_H_ */
