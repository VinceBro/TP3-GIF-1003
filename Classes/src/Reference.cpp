/**
 * \file Reference.cpp
 * \brief Implémentation de la classe de base abstraite Reference
 * \author Vincent Breault
 * \date
 */

#include "Reference.h"

using namespace std;
using namespace biblio;
/**
 * \brief TODO J'ai aucune idée quoi documenter pour main
 * @return
 */
int main(){
	return 0;
}
/**
 * \brief Constructeur avec paramètre, Construction d'un objet Reference à partir des valeurs passées en paramètre
 * @param[in] auteurs correspond au nom du ou des auteurs (string)
 * @param[in] titre correspond au titre (string)
 * @param[in] identifiant correspond au ISBN ou au ISSN (string)
 * @param[in] annee correspond à l'année (int)
 */
Reference::Reference(const string auteurs, const string titre, const string identifiant, int annee){
	if (util::validerFormatNom(auteurs) && (titre.length() > 0) &&
		(util::validerCodeIsbn(identifiant) || util::validerCodeIssn(identifiant)) &&
		(annee > 0))
	{
	m_auteurs = auteurs;
	m_titre = titre;
	m_identifiant = identifiant;
	m_annee = annee;
	}
	else cout << "Erreur du constructeur de Reference mon excellent ami" << endl;

}

/**
 * \brief Modifie l'auteur si le format est valide
 * @param nouv_auteurs
 */
void Reference::modif_auteurs(const string nouv_auteurs){

    if (util::validerFormatNom(nouv_auteurs)) m_auteurs = nouv_auteurs;

}

/**
 * \brief détermine si deux objets Reference sont égaux en comparant les attributs
 * @param c_ref pointeur d'un objet Reference
 * @return booléen
 */
bool Reference::operator==(Reference *c_ref){
   return((c_ref-> m_auteurs == m_auteurs) && (c_ref-> m_titre == m_titre) && (c_ref-> m_identifiant == m_identifiant) &&(c_ref->m_annee == m_annee));
   }


