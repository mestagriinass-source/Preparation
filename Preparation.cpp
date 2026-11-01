#include <iostream>
#include "Date.h"
#include "Livre.h"
#include "Bibliotheque.h"
using namespace std;
int main() {
	Date d1(29, 2, 2020);
	Livre livre1("Titre1", "Auteur1", d1);
	Bibliotheque bib1("Bibliotheque1", 10);
	Livre livre2("Titre2", "Auteur2", d1);
	d1.afficher();
	livre1.afficher();
	bib1.afficher();
	bib1.ajouterLivre(&livre1);
	bib1.ajouterLivre(&livre2);
	bib1.recherche(livre1.getid());
	bib1.recherche(livre2.getid());

		return 0;
}