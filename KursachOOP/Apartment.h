#pragma once
#include "Building.h"

class Apartment : public Building
{
public:
	Apartment(int roomsAmount, int floor, float livingSpace, int yearBuilt, string address, string owner, float price);
	virtual ~Apartment() = 0;

	int getRoomsAmount();
	int getFloor();

	void setRoomsAmount(int roomsAmount);
	void setFloor(int floor);

protected:
	int roomsAmount;
	int floor;
};

