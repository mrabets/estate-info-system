#include "NewBuilding.h"

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

ostream& operator<<(ostream& out, const NewBuilding& obj)
{
    return out << obj.address << " " << obj.owner << " " << obj.price << " " << obj.floor << " " <<
        obj.livingSpace << " " << obj.yearBuilt << " " << obj.warranty << " " << obj.roomsAmount << endl;
}
