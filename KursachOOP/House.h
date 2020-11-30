#pragma once
#include "Building.h"
#include "Ground.h"

class House : public Building
{
public:
	House(int floorsAmount, float livingSpace, int yearBuilt, string address, string owner, float price);
	virtual ~House() = default;

	int getFloorsAmount();
	void setFloorsAmount(int floorsAmount);

protected:
	int floorsAmount;
};

