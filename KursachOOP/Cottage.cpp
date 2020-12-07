#include "Cottage.h"

Cottage::Cottage() : House()
{
    this->nameOfVillage = "";
}

Cottage::Cottage(string nameOfVillage, int floorsAmount, float livingSpace, int yearBuilt, string city, string owner, float price)
    : House(floorsAmount, livingSpace, yearBuilt, city, owner, price)
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
    return out << dynamic_cast<House&>(obj) << setw(15) << obj.nameOfVillage << "\n";
}

istream& operator>>(istream& in, Cottage& obj)
{
    return in >> dynamic_cast<House&>(obj) >> obj.nameOfVillage;  
}
