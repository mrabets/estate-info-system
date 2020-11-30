#include "Estate.h"

Estate::Estate(string address, string owner, float price)
{
	this->address = address;
	this->owner = owner;
	this->price = price;
}

Estate::~Estate()
{
}

string Estate::getAddress()
{
	return address;
}

string Estate::getOwner()
{
	return owner;
}

float Estate::getPrice()
{
	return price;
}

void Estate::setAddress(string address)
{
	this->address = address;
}

void Estate::setOwner(string owner)
{
	this->owner = owner;
}

void Estate::setPrice(float price)
{
	this->price = price;
}
