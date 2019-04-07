/*
 * Journal.h
 *
 *  Created on: Apr. 7, 2019
 *      Author: root
 */
#include "Reference.h"
#ifndef JOURNAL_H_
#define JOURNAL_H_

namespace biblio{
class Journal: public biblio::Reference{

public:
	Journal(const std::string auteurs, const std::string titre,
			const std::string identifiant, const int annee, const std::string nom,
			const int volume, const int numero, const int page);
	void affich_nom() const {std::cout << "Nom: " << m_nom << std::endl;}
	void affich_volume() const {std::cout << "Volume: " << m_volume << std::endl;}
	void affich_numero() const {std::cout << "Numéro: " << m_numero << std::endl;}
	void affich_page() const {std::cout << "Page: " << m_page << std::endl;}

    virtual Reference* clone() const {return new Journal(*this);};
    virtual std::string reqReferenceFormate() const;

private:
	std::string m_nom;
	int m_volume, m_numero, m_page;
};

}


#endif /* JOURNAL_H_ */
