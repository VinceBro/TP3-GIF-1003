#ifndef REFERENCE_H
#define REFERENCE_H
#include "util.h"
#include <string>
#include <sstream>
namespace biblio{
/*
 * \class Reference
 * \brief Classe de base
 */
class Reference
{

public:
    Reference(const std::string, const std::string, const std::string, int);
    void affich_auteur() const;
    void affich_titre() const;
    void affich_identifiant() const;
    void affich_annee() const;
    void modif_auteurs(std::string);
    virtual std::string reqReferenceFormate() const = 0;
    bool operator==(Reference *c_ref);
    virtual ~Reference(){};
protected:
    std::string m_auteurs, m_titre, m_identifiant;
    int m_annee;
};
}

#endif // REFERENCE_H
