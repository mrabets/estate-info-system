#pragma once
#include "Apartment.h"
class SecondaryHousing : public Apartment
{
public:
	SecondaryHousing();
	SecondaryHousing(string city, string owner, float price, float livingSpace, int yearBuilt, int roomsAmount, int floor, string typeOfRepair);

	string getTypeOfRepair();
	void setTypeOfRepair(string typeOfRepair);

	friend ostream& operator << (ostream& out, SecondaryHousing& obj);
	friend istream& operator >> (istream& in, SecondaryHousing& obj);

private:
	string typeOfRepair;
};

