#pragma once
#include "House.h"
class Country : public House
{
public:
	int getDistanceFromCity();
	void setDistanceFromCity(int distanceFromCity);

private:
	int distanceFromCity;
};

