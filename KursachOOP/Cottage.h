#pragma once
#include "House.h"
class Cottage :public House
{
public:
	Cottage();
	Cottage(string nameOfVillage, int floorsAmount, float livingSpace, int yearBuilt, string city, string owner, float price);

	void enterData() override;

	string getNameOfVillage();
	void setNameOfVillage(string nameOfVillage);

	friend ostream& operator << (ostream& out, Cottage& obj);
	friend istream& operator >> (istream& in, Cottage& obj);

private:
	string nameOfVillage;
};

