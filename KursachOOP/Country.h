#pragma once
#include "House.h"
class Country : public House
{
public:
	Country();
	Country(int distanceFromCity, int floorsAmount, float livingSpace, int yearBuilt, string city, string owner, float price);

	void enterData() override;

	int getDistanceFromCity();
	void setDistanceFromCity(int distanceFromCity);

	friend ostream& operator << (ostream& out, Country& obj);
	friend istream& operator >> (istream& in, Country& obj);

private:
	int distanceFromCity;
};

