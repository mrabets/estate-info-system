#pragma once
#include "Building.h"
#include "Ground.h"

class House : public Building
{
public:
	House();
	House(int floorsAmount, float livingSpace, int yearBuilt, string address, string owner, float price);
	virtual ~House() = default;

	void enterData() override;

	int getFloorsAmount();
	void setFloorsAmount(int floorsAmount);

	friend ostream& operator << (ostream& out, House& obj);
	friend istream& operator >> (istream& in, House& obj);

private:
	int floorsAmount;
};

