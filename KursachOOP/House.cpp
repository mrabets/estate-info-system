#include "House.h"

House::House() : Building()
{
    this->floorsAmount = 0;
}

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

ostream& operator<<(ostream& out, House& obj)
{
    return out << dynamic_cast<Building&>(obj) << setw(10) << obj.floorsAmount;
}

istream& operator>>(istream& in, House& obj)
{
    in >> dynamic_cast<Building&>(obj);

    cout << "Floors amount: ";
    in >> obj.floorsAmount;

    return in;
}
