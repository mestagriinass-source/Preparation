#pragma once
#include<iostream>
#include "Livre.h"
using namespace std;
class Bibliotheque {
private:
	string nom;
	Livre** livres;
	static int nbLivres;
	int capacite;
	static int nbBiblotheques;
	int id;
public:
	Bibliotheque(string, int);
	Bibliotheque(const Bibliotheque& B);
	Bibliotheque operator=(const Bibliotheque& B);
	Livre& ajouterLivre(Livre*);
	Bibliotheque operator+=(const Bibliotheque& B);
	int getid() const { return this->id; }
	string getnom() const { return this->nom; }
	bool recherche(int);
	bool recherche(string);
	void afficher()const;
	~Bibliotheque();
};
