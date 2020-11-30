#include "Cottage.h"

Cottage::Cottage() : House()
{
    this->nameOfVillage = "";
}

Cottage::Cottage(string nameOfVillage, int floorsAmount, float livingSpace, int yearBuilt, string address, string owner, float price)
    : House(floorsAmount, livingSpace, yearBuilt, address, owner, price)
{
    this->nameOfVillage = nameOfVillage;
}

string Cottage::getNameOfVillage()
{
    return nameOfVillage;
}

void Cottage::setNameOfVillage(string nameOfVillage)
{
    this->nameOfVillage = nameOfVillage;
}

ostream& operator<<(ostream& out, Cottage& obj)
{
    return out << dynamic_cast<House&>(obj) << setw(10) << obj.nameOfVillage;
}

istream& operator>>(istream& in, Cottage& obj)
{
    in >> dynamic_cast<House&>(obj);

    cout << "Name of village: ";
    in >> obj.nameOfVillage;
    rewind stdin;

    return in;
}
