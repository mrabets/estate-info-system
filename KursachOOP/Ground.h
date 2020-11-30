#pragma once
#include "Estate.h"

class Ground : public Estate
{
public:
	Ground(float landSquare, string address, string owner, float price);

	float getLandSquare();
	void setLandSquare(float landSquare);

private:
	float landSquare;
};

