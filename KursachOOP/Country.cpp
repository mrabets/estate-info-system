#include "Country.h"

Country::Country(int distanceFromCity, int floorsAmount, float livingSpace, int yearBuilt, string address, string owner, float price)
    : House(floorsAmount, livingSpace, yearBuilt, address, owner, price)
{
    this->distanceFromCity = distanceFromCity;
}

int Country::getDistanceFromCity()
{
    return distanceFromCity;
}

void Country::setDistanceFromCity(int distanceFromCity)
{
    this->distanceFromCity = distanceFromCity;
}
