#include "Cottage.h"

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
