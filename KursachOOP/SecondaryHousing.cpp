#include "SecondaryHousing.h"

SecondaryHousing::SecondaryHousing() : Apartment()
{
    this->typeOfRepair = "";
}

SecondaryHousing::SecondaryHousing(string city, string owner, float price, float livingSpace, int yearBuilt, int roomsAmount, int floor, string typeOfRepair)
    : Apartment(roomsAmount, floor, livingSpace, yearBuilt, city, owner, price)
{
    this->typeOfRepair = typeOfRepair;
}

string SecondaryHousing::getTypeOfRepair()
{
    return typeOfRepair;
}

void SecondaryHousing::setTypeOfRepair(string typeOfRepair)
{
    this->typeOfRepair = typeOfRepair;
}

ostream& operator<<(ostream& out, SecondaryHousing& obj)
{
    return out << dynamic_cast<Apartment&>(obj) << setw(18) << obj.typeOfRepair << "\n";
}

istream& operator>>(istream& in, SecondaryHousing& obj)
{
    return in >> dynamic_cast<Apartment&>(obj) >> obj.typeOfRepair;
}
