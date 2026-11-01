#pragma once
#include<iostream>
class Date
{
private:
	int jours;
	int mois;
	int annee;
public:
	Date();
	Date(int, int, int);
	bool estBissextile(int);
	void afficher()const;
	bool estValide(int,int,int);
	bool operator==(const Date& D) const;
	bool operator<(const Date& D) const;
};

