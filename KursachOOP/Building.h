#pragma once
#include "Estate.h"
class Building : public Estate
{
public:
	Building();
	Building(float livingSpace, int yearBuilt, string address, string owner, float price);
	virtual ~Building() = default;

	float getLivingSpace();
	int getYearBuilt();

	void setLivingSpace(float livingSpace);
	void setYearBuilt(int yearBuilt);

	friend ostream& operator << (ostream& out, Building& obj);
	friend istream& operator >> (istream& in, Building& obj);

private:
	float livingSpace;
	int yearBuilt;
};

