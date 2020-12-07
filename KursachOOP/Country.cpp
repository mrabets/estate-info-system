#include "Country.h"

Country::Country() : House()
{
    this->distanceFromCity = 0;
}

Country::Country(int distanceFromCity, int floorsAmount, float livingSpace, int yearBuilt, string city, string owner, float price)
    : House(floorsAmount, livingSpace, yearBuilt, city, owner, price)
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

ostream& operator<<(ostream& out, Country& obj)
{
    return out << dynamic_cast<House&>(obj) << setw(25) << obj.distanceFromCity << "\n";
}

istream& operator>>(istream& in, Country& obj)
{
    return in >> dynamic_cast<House&>(obj) >> obj.distanceFromCity;
}
