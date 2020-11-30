#include "Apartment.h"



Apartment::Apartment(int roomsAmount, int floor, float livingSpace, int yearBuilt, string address, string owner, float price)
    : Building(livingSpace, yearBuilt, address, owner, price)
{
    this->roomsAmount = roomsAmount;
    this->floor = floor;
}

int Apartment::getRoomsAmount()
{
    return this->roomsAmount;
}

int Apartment::getFloor()
{
    return this->floor;
}

void Apartment::setRoomsAmount(int roomsAmount)
{
    this->roomsAmount = roomsAmount;
}

void Apartment::setFloor(int floor)
{
    this->floor = floor;
}
