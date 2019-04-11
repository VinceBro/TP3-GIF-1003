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

	while (valide == false){
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
			(annee >= 0) && util::validerFormatNom(editeur) && util::validerFormatNom(ville)){
			valide = true;
		}
		else cout << "Veuillez réessayer en entrant des données valides" << endl;
	}
	return Ouvrage(auteur, titre, identifiant, annee, ville, editeur);
}

Journal CreerUnJournal()
{
	string auteur;
	string titre;
	int annee;
	string nom;
	int volume;
	int numero;
	int page;
	string identifiant;
	bool valide = false;

	while (valide == false){
		cout << "Entrez le nom du/des auteurs" << endl;
		getline(cin, auteur);

		cout << "Entrez le titre de l'ouvrage" << endl;
		getline(cin, titre);

		cout << "Entrez le nom du journal" << endl;
		getline(cin, nom);

		cout << "Entrez l'année d'édition" << endl;
		cin >> annee;
		cin.ignore();

		cout << "Entrez le volume du journal" << endl;
		cin >> volume;
		cin.ignore();

		cout << "Entrez le numero du journal" << endl;
		cin >> numero;
		cin.ignore();

		cout << "Entrez la page du journal" << endl;
		cin >> page;
		cin.ignore();

		cout << "Entrez l'identifiant" << endl;
		getline(cin, identifiant);

		if (util::validerFormatNom(auteur) && (!(titre.empty())) &&
			(util::validerCodeIsbn(identifiant) || util::validerCodeIssn(identifiant)) &&
			(annee >= 0) && volume >= 0 && numero >= 0 && page > 0){
			valide = true;
		}
		else cout << "Veuillez réessayer en entrant des données valides" << endl;
	}
	return Journal(auteur, titre, identifiant, annee, nom, volume, numero, page);
}


int main() {
	string nombiblio;
	cout << "Entrez un nom pour votre bibliographie" << endl;
	getline(cin, nombiblio);
	Bibliographie biblio(nombiblio);

	cout << "Création du premier ouvrage" << endl;
	biblio.ajouterReference(CreerUnOuvrage());
	cout << "Jusqu'a présent: \n" << biblio.reqBibliographieFormate() << endl;

	cout << "Création du deuxième ouvrage" << endl;
	biblio.ajouterReference(CreerUnOuvrage());
	cout << "Jusqu'a présent: \n" << biblio.reqBibliographieFormate() << endl;

	cout << "Création du premier journal" << endl;
	biblio.ajouterReference(CreerUnJournal());
	cout << "Jusqu'a présent: \n" << biblio.reqBibliographieFormate() << endl;

	cout << "Création du deuxième journal" << endl;
	biblio.ajouterReference(CreerUnJournal());
	cout << "Jusqu'a présent: \n" << biblio.reqBibliographieFormate() << endl;

	cout << "Fin du programme" << endl;

	return 0;
}
