#include "Estate.h"

Estate::Estate()
{
	this->city = "None";
	this->owner = "None";
	this->price = 0;
}

Estate::Estate(string city, string owner, float price)
{
	this->city = city;
	this->owner = owner;
	this->price = price;
}

void Estate::enterData()
{
}

string Estate::getCity()
{
	return city;
}

string Estate::getOwner()
{
	return owner;
}

float Estate::getPrice()
{
	return price;
}

void Estate::setCity(string address)
{
	this->city = address;
}

void Estate::setOwner(string owner)
{
	this->owner = owner;
}

void Estate::setPrice(float price)
{
	this->price = price;
}

ostream& operator<<(ostream& out, Estate& obj)
{
	return out << setw(20) << obj.city << setw(20) << obj.owner << setw(10) << obj.price;
}

istream& operator>>(istream& in, Estate& obj)
{
	return in >> obj.city >> obj.owner >> obj.price;
}
