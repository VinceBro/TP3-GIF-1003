#include <iostream>
#include "Reference.h"

using namespace std;
using namespace biblio;

int main(){
	return 0;
}

//constructeur
Reference::Reference(const string auteurs, const string titre, const string identifiant, int annee){

        m_auteurs = auteurs;
        m_titre = titre;
        m_identifiant = identifiant;
        m_annee = annee;


}
//affiche le ou les auteurs dans la console
void Reference::affich_auteur() const{
    cout << "Auteur(s): " << m_auteurs << endl;
    }
// affiche le titre dans la console
void Reference::affich_titre() const{
    cout << "Titre: " << m_titre << endl;
}
//affiche l'indentifiant dans la console
void Reference::affich_identifiant() const{
    cout << "Identifiant: " << m_identifiant << endl;
}
//affiche l'année dans la console
void Reference::affich_annee() const{
    cout << "Année de publication: " << m_annee << endl;
}
//change l'auteur si le nom d'auteur est valide
void Reference::modif_auteurs(string nouv_auteurs){

    if (util::validerFormatNom(nouv_auteurs)) m_auteurs = nouv_auteurs;

}
//retourne les variables de la classe formatés
string Reference::reqReferenceFormate() const{
    ostringstream os;
    os << m_auteurs << ", " << m_titre << ", "<< m_annee << ", " << m_identifiant;
    return os.str();
}
//determine si deux objets reference sont égaux
bool Reference::operator==(Reference *c_ref){
   return((c_ref-> m_auteurs == m_auteurs) && (c_ref-> m_titre == m_titre) && (c_ref-> m_identifiant == m_identifiant) &&(c_ref->m_annee == m_annee));
   }


