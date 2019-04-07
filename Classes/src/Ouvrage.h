/*
 * Ouvrage.h
 *
 *  Created on: Apr. 3, 2019
 *      Author: root
 */
#include "Reference.h"
#ifndef OUVRAGE_H_
#define OUVRAGE_H_
/*
 * \class Ouvrage
 * \brief Hérite de la classe Référence
 */
namespace biblio{
class Ouvrage: public biblio::Reference{

public:
	Ouvrage(const std::string, const std::string, const std::string, const int, const std::string, const std::string );
	void affich_editeur() const{ std::cout << "Éditeur: " << m_editeur << std::endl;};
	void affich_ville() const{std::cout << "Ville: " << m_ville << std::endl;};
    virtual std::string reqReferenceFormate() const;
    virtual Reference* clone() const {return new Ouvrage(*this);};

private:
	std::string m_editeur, m_ville;

};

}

#endif /* OUVRAGE_H_ */
