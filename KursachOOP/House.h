#pragma once
#include "Building.h"
#include "Ground.h"

class House : public Building
{
public:
	int getFloorsAmount();
	void setFloorsAmount(int floorsAmount);

protected:
	int floorsAmount;
};

