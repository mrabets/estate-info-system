#include "Building.h"

Building::Building(float livingSpace, int yearBuilt, string address, string owner, float price) : Estate(address, owner, price)
{
    this->livingSpace = livingSpace;
    this->yearBuilt = yearBuilt;
}

float Building::getLivingSpace()
{
    return this->livingSpace;
}

int Building::getYearBuilt()
{
    return this->yearBuilt;
}

void Building::setLivingSpace(float livingSpace)
{
    this->livingSpace = livingSpace;
}

void Building::setYearBuilt(int yearBuilt)
{
    this->yearBuilt = yearBuilt;
}

ostream& operator<<(ostream& out, Building& obj)
{
    return out << dynamic_cast<Estate&>(obj) << setw(10) << obj.livingSpace << setw(10) << obj.yearBuilt;
}

istream& operator>>(istream& in, Building& obj)
{
    in >> dynamic_cast<Estate&>(obj);

    cout << "Living Space: ";
    in >> obj.livingSpace;

    cout << "Year built: ";
    in >> obj.yearBuilt;

    return in;
}
