/**
 * \file Reference.h
 * \brief Classe de base abstraite Reference
 * \author Vincent Breault
 * \date
 */
#ifndef REFERENCE_H
#define REFERENCE_H
#include "Util.h"
#include "ContratException.h"
#include <iostream>
#include <string>
#include <sstream>
namespace biblio{
/**
 * \class Reference
 * \brief Classe de base abstraite, les classes Ouvrage et Journal hérite de cette classe
 */
class Reference
{

public:
    Reference(const std::string auteurs, const std::string titre, const std::string identifiant, int annee);
    /**
     * \brief Accesseur auteur
     * @return auteur
     */
    std::string reqAuteurs() const {return m_auteurs;};
    /**
	 * \brief Accesseur titre
	 * @return titre
	 */
    std::string reqTitre() const {return m_titre;};
    /**
	 * \brief Accesseur identifiant
	 * @return identifiant
	 */
    std::string reqIdentifiant() const {return m_identifiant;};
    /**
	 * \brief Accesseur annee
	 * @return annee
	 */
    int reqAnnee() const { return m_annee;};
    void modif_auteurs(const std::string nouv_auteurs);
    bool operator==(Reference *c_ref);
    virtual std::string reqReferenceFormate() const = 0;
    virtual Reference* clone() const = 0;
    virtual ~Reference(){};
protected:
    std::string m_auteurs, m_titre, m_identifiant;
    int m_annee;
private:
    void verifieInvariant() const;
};
}

#endif // REFERENCE_H
