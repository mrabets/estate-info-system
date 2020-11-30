#pragma once
#include <string>
#include <iomanip>
#include "Client.h"
using namespace std;

class Estate
{
public:
	Estate();
	Estate(string address, string owner, float price);
	virtual ~Estate() = default;

	string getAddress();
	string getOwner();
	float getPrice();

	void setAddress(string address);
	void setOwner(string owner);
	void setPrice(float price);

	friend ostream& operator << (ostream& out, Estate& obj);
	friend istream& operator >> (istream& in, Estate& obj);


private:
	string address;
	string owner;
	float price;
};

