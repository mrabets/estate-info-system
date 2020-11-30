#include "NewBuilding.h"
#include <iostream>
using namespace std;


int main()
{
	setlocale(LC_ALL, "Russian");
	
	NewBuilding nb(4, 5, 3, 4444, 1999, "Minsk", "Karim M", 2333.33);

	cout << nb;

	return 0;
}