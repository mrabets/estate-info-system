#pragma once
#include "House.h"
class Cottage :public House
{
public:
	string getNameOfVillage();
	void setNameOfVillage(string nameOfVillage);

private:
	string nameOfVillage;
};

