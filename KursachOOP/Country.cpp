#include "Country.h"

Country::Country() : House()
{
    this->distanceFromCity = 0;
}

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
    return out << dynamic_cast<House&>(obj) << setw(25) << obj.distanceFromCity << endl;
}

istream& operator>>(istream& in, Country& obj)
{
    in >> dynamic_cast<House&>(obj);

    cout << "Расстояние от города: ";
    in >> obj.distanceFromCity;

    return in;
}
