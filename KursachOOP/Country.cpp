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

ostream& operator<<(ostream& out, Country& obj)
{
    return out << dynamic_cast<House&>(obj) << setw(10) << obj.distanceFromCity;
}

istream& operator>>(istream& in, Country& obj)
{
    in >> dynamic_cast<House&>(obj);

    cout << "Distance from city: ";
    in >> obj.distanceFromCity;

    return in;
}
