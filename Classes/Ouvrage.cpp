/**
 * \file Ouvrage.cpp
 * \brief Implémentation de la classe Ouvrage dérivée de Reference
 * \author Vincent Breault
 * \date
 */
#include "Ouvrage.h"
using namespace std;
using namespace biblio;
/**
 * \brief Constructeur avec paramètre, Construction d'un objet Ouvrage à partir des valeurs passées en paramètre
 * @param auteurs
 * @param titre
 * @param identifiant
 * @param annee
 * @param editeur
 * @param ville
 */
Ouvrage::Ouvrage(const string auteurs, const std::string titre,
		const std::string identifiant, const int annee, const std::string ville,
		const std::string editeur) : biblio::Reference(auteurs, titre, identifiant, annee)
{
	PRECONDITION(util::validerFormatNom(ville));
	PRECONDITION(util::validerFormatNom(editeur));
	if (util::validerFormatNom(editeur) && util::validerFormatNom(ville))
	{
	m_editeur = editeur;
	m_ville = ville;
	} else cout << "Erreur du constructeur de Ouvrage mon excellent ami" << endl;
	POSTCONDITION(m_ville == ville);
	POSTCONDITION(m_editeur == editeur);

	INVARIANTS();
}

/**
 * \brief Génère un objet string formaté
 * @return Ouvrage formaté
 */
std::string Ouvrage::reqReferenceFormate() const{
	ostringstream os;
	os << m_auteurs << ". " << m_titre << ". "<<
			m_ville << " : " << m_editeur <<", " <<
			m_annee << ". " << m_identifiant << ".";
	return os.str();
}
void Ouvrage::verifieInvariant() const
{
	INVARIANT(util::validerFormatNom(m_ville));
	INVARIANT(util::validerFormatNom(m_editeur));
}
