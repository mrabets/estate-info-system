#include "Building.h"

Building::Building() : Estate()
{
    this->livingSpace = 0.0f;
    this->yearBuilt = 0;
}

Building::Building(float livingSpace, int yearBuilt, string city, string owner, float price) : Estate(city, owner, price)
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
    return out << dynamic_cast<Estate&>(obj) << setw(18) << obj.livingSpace << setw(18) << obj.yearBuilt;
}

istream& operator>>(istream& in, Building& obj)
{
    return in >> dynamic_cast<Estate&>(obj) >> obj.livingSpace >> obj.yearBuilt;
}
