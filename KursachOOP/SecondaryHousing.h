#pragma once
#include "Apartment.h"
class SecondaryHousing : public Apartment
{
public:
	SecondaryHousing(string address, string owner, float price, float livingSpace, int yearBuilt, int roomsAmount, int floor, string typeOfRepair);

	string getTypeOfRepair();
	void setTypeOfRepair(string typeOfRepair);

private:
	string typeOfRepair;
};

