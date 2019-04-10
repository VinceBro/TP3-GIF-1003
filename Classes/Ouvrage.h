/**
 * \file Ouvrage.h
 * \brief Classe Ouvrage dérivée de Reference
 * \author Vincent Breault
 * \date
 */
#include "Reference.h"
#ifndef OUVRAGE_H_
#define OUVRAGE_H_

namespace biblio{
/**
 * \class Ouvrage
 * \brief Classe dérivée de la classe Reference
 */
class Ouvrage: public biblio::Reference{

public:
	Ouvrage(const std::string auteurs, const std::string titre, const std::string identifiant
			, const int annee, const std::string ville, const std::string editeur);
	/**
	 * \brief Accesseur editeur
	 * @return editeur
	 */
	std::string reqEditeur() const {return m_editeur;};
	/**
	 * \brief Accesseur ville
	 * @return ville
	 */
	std::string reqVille() const {return m_ville;};
    virtual std::string reqReferenceFormate() const;
    /**
     * \brief Effectue une copie de l'objet courant
     * @return Objet Ouvrage
     */
    virtual Reference* clone() const {return new Ouvrage(*this);};

private:
	std::string m_editeur, m_ville;
	void verifieInvariant() const;
};

}

#endif /* OUVRAGE_H_ */
