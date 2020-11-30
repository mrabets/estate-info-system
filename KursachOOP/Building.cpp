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

void Building::setYeatBuilt(int yearBuilt)
{
    this->yearBuilt = yearBuilt;
}
