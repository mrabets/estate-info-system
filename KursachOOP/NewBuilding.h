#pragma once
#include "Apartment.h"
class NewBuilding : public Apartment
{
public:
	NewBuilding(int warranty, int roomsAmount, int floor, float livingSpace, int yearBuilt, string address, string owner, float price);

	int getWarranty();
	void setWarranty(int warranty);

	friend ostream& operator << (ostream& out, const NewBuilding& obj);

private:
	int warranty;
};

