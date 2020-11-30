#pragma once
#include "Estate.h"

class Ground : public Estate
{
public:
	Ground();
	Ground(float landSquare, string address, string owner, float price);

	float getLandSquare();
	void setLandSquare(float landSquare);

	friend ostream& operator << (ostream& out, Ground& obj);
	friend istream& operator >> (istream& in, Ground& obj);

private:
	float landSquare;
};

