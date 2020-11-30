#pragma once
#include <string>
#include "Client.h"
using namespace std;

class Estate
{
public:
	Estate(string address, string owner, float price);
	virtual ~Estate() = default;

	string getAddress();
	string getOwner();
	float getPrice();

	void setAddress(string address);
	void setOwner(string owner);
	void setPrice(float price);

protected:
	string address;
	string owner;
	float price;
};

