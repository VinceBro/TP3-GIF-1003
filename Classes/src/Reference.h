#ifndef REFERENCE_H
#define REFERENCE_H
#include <string>
#include <sstream>
//fonctions utilitaires
namespace util{

bool validerFormatNom(const std::string& p_nom);
bool validerCodeIssn (const std::string& p_issn);
bool validerCodeIsbn (const std::string& p_isbn);

}
//de biblio: classe reference: stocke et gère une reference
namespace biblio{
class Reference
{

public:
    Reference(const std::string, const std::string, const std::string, int);
    void affich_auteur() const;
    void affich_titre() const;
    void affich_identifiant() const;
    void affich_annee() const;
    void modif_auteurs(std::string);
    std::string reqReferenceFormate() const;
    bool operator==(Reference *c_ref);
private:
    std::string m_auteurs, m_titre, m_identifiant;
    int m_annee;
};
}

#endif // REFERENCE_H