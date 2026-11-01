#pragma once
#include<iostream>
#include "Date.h"
using namespace std;
class Livre {
private:
	const int id;
	string titre;
	string auteur;
	Date parution;
	float* notes;
	int nbNotes;
	static int compteurId;
	static int nbIstances;
public:
	int getid() const { return this->id; }
	string getnom() const { return this->titre; }
	Livre(string,string,Date);
	Livre(const Livre& L);
	void ajouterNote(int);
	float moyenneLivre() const;
	void afficher()const;
	Livre operator=(const Livre& L);
	~Livre();
};