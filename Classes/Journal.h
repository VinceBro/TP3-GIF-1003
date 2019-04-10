/**
 * \file Journal.h
 * \brief Classe Journal dérivée de Reference
 * \author Vincent Breault
 * \date
 */
#include "Reference.h"
#ifndef JOURNAL_H_
#define JOURNAL_H_


namespace biblio{
/**
 * \class Journal
 * \brief Classe dérivée de la classe Reference
 */
class Journal: public biblio::Reference{

public:
	Journal(const std::string auteurs, const std::string titre,
			const std::string identifiant, const int annee, const std::string nom,
			const int volume, const int numero, const int page);
	/**
	 * \brief Accesseur nom
	 * @return nom
	 */
	std::string reqNom() const {return m_nom;};
	/**
	 * \brief Accesseur volume
	 * @return volume
	 */
	int reqVolume() const {return m_volume;};
	/**
	 * \brief Accesseur numero
	 * @return numero
	 */
	int reqNumero() const {return m_numero;};
	/**
	 * \brief Accesseur page
	 * @return page
	 */
	int reqPage() const {return m_page;};

	/**
	 * \brief Effectue une copie de l'objet courant
	 * @return Objet Journal
	 */
    virtual Reference* clone() const {return new Journal(*this);};
    virtual std::string reqReferenceFormate() const;

private:
	std::string m_nom;
	int m_volume, m_numero, m_page;
	void verifieInvariant() const;
};

}


#endif /* JOURNAL_H_ */
