#include "Bibliotheque.h"
#include"Livre.h"
int Bibliotheque::nbBiblotheques = 0;
int Bibliotheque::nbLivres = 0;
Bibliotheque::Bibliotheque(string nom, int capacite)
{
	int i;
	this->nom = nom;
	this->capacite = capacite;
	livres = new Livre * [capacite];
	for (i = 0;i < this->capacite;i++) {
		livres[i] = nullptr;
	}
	this->id=++nbBiblotheques;
}

Bibliotheque::Bibliotheque(const Bibliotheque& B)
{
	this->nom = B.nom;
	this->capacite = B.capacite;
	livres = new Livre* [this->capacite];
	for (int i = 0; i < this->nbLivres; i++) {
		this->livres[i] = new Livre(*B.livres[i]);
	}
	this->id=++nbBiblotheques;
}

Bibliotheque Bibliotheque::operator=(const Bibliotheque& B)
{
	this->nom = B.nom;
	this->capacite = B.capacite;
	livres = new Livre * [this->capacite];
	for (int i = 0; i < this->nbLivres; i++) {
		this->livres[i] = new Livre(*B.livres[i]);
	}
	return *this;
}

Livre& Bibliotheque::ajouterLivre(Livre *nom)
{
	if(nbLivres>=capacite){
		cout << "la bibliotheque est pleine" << endl;
		return *nom;
	}
	else {
		livres[nbLivres] = nom;
		++nbLivres;
		return *nom;
	}
}

bool Bibliotheque::recherche(int id)
{
	if(nbLivres==0){
		cout << "la bibliotheque est vide" << endl;
		return false;
	}
	for (int i = 0; i < nbLivres; i++) {
		if (livres[i]->getid() == id) {
			cout << "le livre demande existe" << endl;
			return true;
		}
	}
	cout << "le livre demande n'existe pas" << endl;
	return false;
}

bool Bibliotheque::recherche(string titre)
{
	if (nbLivres == 0) {
		cout << "la bibliotheque est vide" << endl;
		return false;
	}
	for (int i = 0; i < nbLivres; i++) {
		if (livres[i]->getnom() == titre) {
			std::cout << "Livre demander existe";
		}
	}
	cout << "le livre demande n'existe pas" << endl;
	return false;
	}

void Bibliotheque::afficher() const
{
	cout << "le id est:" << this->id << endl;
	cout << "le nom est:" << this->nom << endl;
	cout << "le nbr est:" << this->nbLivres << endl;
	cout << "le nombre de bibliotheque est:" << this->nbBiblotheques << endl;
	for (int i = 0; i < this->nbLivres; i++) {
		livres[i]->afficher();
	}
}

Bibliotheque::~Bibliotheque()
{
		delete[]this->livres;
	--nbLivres;
	--nbBiblotheques;
}



