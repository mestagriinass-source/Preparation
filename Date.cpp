#include "Date.h"
#include "Livre.h"
Date::Date()
{
}
Date::Date(int j, int m, int a)
{
	if (estValide(j, m, a)) {
		this->jours = j;
		this->mois = m;
		this->annee = a;
	}
	else {
		cout << "erreur detectee" << endl;
		this->jours = 1;
		this->mois = 1;
		this->annee = 2000;
	}
}

bool Date::estBissextile(int annee)
{
	if ((annee % 4 == 0 && annee %100 !=0)|| (annee % 400 == 0)) {
		return 1;
	}
	return 0;
}
void Date::afficher() const
{
	cout << "jour est:" << this->jours << endl;
	cout << "mois est:" << this->mois << endl;
	cout << "annee est:" << this->annee << endl;
}

bool Date::estValide(int j ,int m , int a)
{
	if (j<1||j>31||m<1||m>12||a<1||a>2026) {
		return false;
	}
	int mois[12] = { 31,28,31,30,31,30,31,31,30,31,30,31};
	if (estBissextile(a)) {
		cout << "c'est une annee bissextile"<< endl;
		mois[1] = 29;
	}
	return j<=mois[m-1];
}

bool Date::operator==(const Date& D) const
{
	if (this->jours == D.jours && this->mois == D.mois && this->annee == D.annee) {
		return true;
	}
	else {
		return  false;
	}

}

bool Date::operator<(const Date& D) const
{
	if (this->annee != D.annee)
		return this->annee < D.annee;

	if (this->mois != D.mois)
		return this->mois < D.mois;

	return this->jours < D.jours;
}