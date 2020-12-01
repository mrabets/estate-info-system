#include "SecondaryHousing.h"

SecondaryHousing::SecondaryHousing() : Apartment()
{
    this->typeOfRepair = "";
}

SecondaryHousing::SecondaryHousing(string address, string owner, float price, float livingSpace, int yearBuilt, int roomsAmount, int floor, string typeOfRepair)
    : Apartment(roomsAmount, floor, livingSpace, yearBuilt, address, owner, price)
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
    return out << dynamic_cast<Apartment&>(obj) << setw(18) << obj.typeOfRepair << endl;
}

istream& operator>>(istream& in, SecondaryHousing& obj)
{
    in >> dynamic_cast<Apartment&>(obj);

    cout << "Тип ремонта: ";
    in >> obj.typeOfRepair;
    rewind stdin;

    return in;
}
