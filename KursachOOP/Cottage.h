#pragma once
#include "House.h"
class Cottage :public House
{
public:
	Cottage(string nameOfVillage, int floorsAmount, float livingSpace, int yearBuilt, string address, string owner, float price);

	string getNameOfVillage();
	void setNameOfVillage(string nameOfVillage);

private:
	string nameOfVillage;
};

