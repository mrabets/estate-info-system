#include "House.h"

House::House(int floorsAmount, float livingSpace, int yearBuilt, string address, string owner, float price)
    : Building(livingSpace, yearBuilt, address, owner, price)
{
    this->floorsAmount = floorsAmount;
}

int House::getFloorsAmount()
{
    return floorsAmount;
}

void House::setFloorsAmount(int floorsAmount)
{
    this->floorsAmount = floorsAmount;
}
