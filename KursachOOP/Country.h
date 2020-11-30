#pragma once
#include "House.h"
class Country : public House
{
public:
	Country(int distanceFromCity, int floorsAmount, float livingSpace, int yearBuilt, string address, string owner, float price);

	int getDistanceFromCity();
	void setDistanceFromCity(int distanceFromCity);

private:
	int distanceFromCity;
};

