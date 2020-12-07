#pragma once
#include <string>
#include <iomanip>
#include <iostream>
using namespace std;

class Estate
{
public:
	Estate();
	Estate(string address, string owner, float price);
	virtual ~Estate() = default;

	string getCity();
	string getOwner();
	float getPrice();

	void setCity(string city);
	void setOwner(string owner);
	void setPrice(float price);

	friend ostream& operator << (ostream& out, Estate& obj);
	friend istream& operator >> (istream& in, Estate& obj);


private:
	string city;
	string owner;
	float price;
};

