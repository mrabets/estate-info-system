#pragma once
#include "Estate.h"
class Building : public Estate
{
public:
	Building(float livingSpace, int yearBuilt, string address, string owner, float price);
	virtual ~Building() = default;

	float getLivingSpace();
	int getYearBuilt();

	void setLivingSpace(float livingSpace);
	void setYeatBuilt(int yearBuilt);

protected:
	float livingSpace;
	int yearBuilt;
};

