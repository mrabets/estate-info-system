#include "Ground.h"

Ground::Ground(float landSquare, string address, string owner, float price)
    : Estate(address, owner, price)
{
    this->landSquare = landSquare;
}

float Ground::getLandSquare()
{
    return landSquare;
}

void Ground::setLandSquare(float landSquare)
{
    this->landSquare = landSquare;
}
