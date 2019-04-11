//============================================================================
// Name        : Utilisation.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "Bibliographie.h"
#include "Util.h"
using namespace std;
using namespace biblio;

Ouvrage CreerUnOuvrage()
{
	string auteur;
	string titre;
	string ville;
	string editeur;
	int annee;
	string identifiant;
	bool valide = false;

	while (valide = false){
		cout << "Entrez le nom du/des auteurs" << endl;
		getline(cin, auteur);

		cout << "Entrez le titre de l'ouvrage" << endl;
		getline(cin, titre);

		cout << "Entrez la ville d'édition" << endl;
		getline(cin, ville);

		cout << "Entrez le nom de l'éditeur" << endl;
		getline(cin, editeur);

		cout << "Entrez l'année d'édition" << endl;
		cin >> annee;
		cin.ignore();

		cout << "Entrez l'identifiant" << endl;
		getline(cin, identifiant);

		if (util::validerFormatNom(auteur) && (!(titre.empty())) &&
			(util::validerCodeIsbn(identifiant) || util::validerCodeIssn(identifiant)) &&
			(annee >= 0) && util::validerFormatNom(editeur) && util::validerFormatNom(ville)) valide = true;
		else cout << "Veuillez réessayer en entrant des données valides" << endl;
	}
	return Ouvrage(auteur, titre, identifiant, annee, ville, editeur);
}



int main() {
	return 0;
}
