#pragma once
#include <string>
#include "Client.h"
using namespace std;

class Estate
{
public:
	Estate(string address, string owner, float price);
	virtual ~Estate() = 0;
	//virtual void rent(Client renter) = 0;
	//virtual void sale(Client newOwner) = 0;

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

