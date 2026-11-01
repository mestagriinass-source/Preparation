#include "Livre.h"
#include "Date.h"
int Livre::compteurId = 0;
int Livre::nbIstances = 0;
Livre::Livre(string titre, string auteur, Date parution):id(++compteurId),parution(parution)
{
	this->titre = titre;
	this->auteur = auteur;
	this->nbNotes = 0;
	notes = new float[nbNotes];
	nbIstances++;
}

Livre::Livre(const Livre& L):id(L.id)
{
	int i;
	this->titre = L.titre;
	this->auteur = L.auteur;
	this->parution = L.parution;
	this->nbNotes = L.nbNotes;
	this->notes = new float[this->nbNotes];
	for (i = 0;i < L.nbNotes;i++) {
		this->notes[i] = L.notes[i];
	}
	nbIstances++;
}

void Livre::ajouterNote(int n)
{
	if (n >= 0 && n <= 20) {
		float* tab = new float[nbNotes + 1];
		for (int i = 0;i < nbNotes;i++) {
			tab[i] = notes[i];
		}
		tab[nbNotes] = n;
		delete[]notes;
		notes = tab;
		nbNotes++;

	}
}

float Livre::moyenneLivre() const
{
	float somme = 0.0;int  i;
	for (i = 0;i < nbNotes;i++) {
		somme += notes[i];
	}
	return somme/ nbNotes;
}

void Livre::afficher() const
{
	cout << "le id du livre est:" << this->id << endl;
	cout << "auteur du livre est:" << this->auteur << endl;
	cout << "le titre de livre est:" << this->titre << endl;
	cout << "le nombre de clients est:" << this->compteurId << endl;
	cout << "la date est:" << endl;
	parution.afficher();
}

Livre Livre::operator=(const Livre& L)
{
	int i;
	this->titre = L.titre;
	this->auteur = L.auteur;
	this->parution = L.parution;
	this->nbNotes = L.nbNotes;
	this->notes = new float[this->nbNotes];
	for (i = 0;i < L.nbNotes;i++) {
		this->notes[i] = L.notes[i];
	}
	return *this;
}

Livre::~Livre(){
	delete[]this->notes;
	--nbIstances;
}



