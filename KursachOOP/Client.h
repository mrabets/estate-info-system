#pragma once
#include <iostream>
#include <string>
#include "Estate.h"
using namespace std;

class Client
{
public:
	Client();
	Client(const Client& object);
	Client(string fullName, int age, string passport);
	~Client();

	//void setPrice(Estate& estate, float price);
	//void setAddress(Estate& estate, string address);
	//void setPrice(Estate& estate, float price);

	string getFullName();
	int getAge();
	string getPassport();

private:
	  string fullName;
	  int age;
	  string passport;	  
};



