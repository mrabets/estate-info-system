#pragma once

#include "Apartment.h"
class NewBuilding : public Apartment
{
public:
	NewBuilding();
	NewBuilding(int warranty, int roomsAmount, int floor, float livingSpace, int yearBuilt, string city, string owner, float price);

	int getWarranty();
	void setWarranty(int warranty);

	friend ostream& operator << (ostream& out, NewBuilding& obj);
	friend istream& operator >> (istream& in, NewBuilding& obj);

private:
	int warranty;
};

