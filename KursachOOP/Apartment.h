#pragma once
#include "Building.h"

class Apartment : public Building
{
public:
	Apartment();
	Apartment(int roomsAmount, int floor, float livingSpace, int yearBuilt, string address, string owner, float price);
	virtual ~Apartment() = default;

	void enterData() override;

	int getRoomsAmount();
	int getFloor();

	void setRoomsAmount(int roomsAmount);
	void setFloor(int floor);

	friend ostream& operator << (ostream& out, Apartment& obj);
	friend istream& operator >> (istream& in, Apartment& obj);

private:
	int roomsAmount;
	int floor;
};

