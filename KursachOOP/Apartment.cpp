#include "Apartment.h"



Apartment::Apartment() : Building()
{
    this->roomsAmount = 0;
    this->floor = 0;
}

Apartment::Apartment(int roomsAmount, int floor, float livingSpace, int yearBuilt, string city, string owner, float price)
    : Building(livingSpace, yearBuilt, city, owner, price)
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

ostream& operator<<(ostream& out, Apartment& obj)
{
    return out << dynamic_cast<Building&>(obj) << setw(10) << obj.floor << setw(20) << obj.roomsAmount;
}

istream& operator>>(istream& in, Apartment& obj)
{
    return in >> dynamic_cast<Building&>(obj) >> obj.floor >> obj.roomsAmount;
}