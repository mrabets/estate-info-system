#include "NewBuilding.h"
#include <iostream>
using namespace std;


int main()
{
	setlocale(LC_ALL, "Russian");
	
	const int SIZE = 3;

	NewBuilding newBuildings[SIZE] =
	{
		NewBuilding(1, 4, 5, 22.33f, 1999, "Minsk", "Karim Marabet", 62.1f),
		NewBuilding(3, 2, 3, 65.21f, 2100, "Moscow", "Olga Boreyko", 42.5f),
		NewBuilding(1, 4, 5, 22.33f, 1999, "Minsk", "Alex Dmitriev", 33.2f),
	};

	for (int i = 0; i < SIZE; i++)
	{
		cout << newBuildings[i];
	}

	return 0;
}