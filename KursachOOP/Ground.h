#pragma once
#include "Estate.h"

class Ground : public Estate
{
public:
	float getLandSquare();
	void setLandSquare(float landSquare);

private:
	float landSquare;
};

