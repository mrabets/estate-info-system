#include "NewBuilding.h"

NewBuilding::NewBuilding() : Apartment()
{
    this->warranty = 0;
}

NewBuilding::NewBuilding(int warranty, int roomsAmount, int floor, float livingSpace, int yearBuilt, string address, string owner, float price)
    : Apartment(roomsAmount, floor, livingSpace, yearBuilt, address, owner, price)
{
    this->warranty = warranty;
}

int NewBuilding::getWarranty()
{
    return warranty;
}

void NewBuilding::setWarranty(int warranty)
{
    this->warranty = warranty;
}

ostream& operator<<(ostream& out, NewBuilding& obj)
{
    return out << dynamic_cast<Apartment&>(obj) << setw(10) << obj.warranty;
}

istream& operator>>(istream& in, NewBuilding& obj)
{
    in >> dynamic_cast<Apartment&>(obj);

    cout << "Warranty: ";
    in >> obj.warranty;

    return in;
}
