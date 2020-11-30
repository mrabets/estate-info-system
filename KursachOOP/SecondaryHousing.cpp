#include "SecondaryHousing.h"

SecondaryHousing::SecondaryHousing(string address, string owner, float price, float livingSpace, int yearBuilt, int roomsAmount, int floor, string typeOfRepair)
    :Apartment()
{
    
}

string SecondaryHousing::getTypeOfRepair()
{
    return typeOfRepair;
}

void SecondaryHousing::setTypeOfRepair(string typeOfRepair)
{
    this->typeOfRepair = typeOfRepair;
}
