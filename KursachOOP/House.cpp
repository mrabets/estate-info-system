#include "House.h"

House::House() : Building()
{
    this->floorsAmount = 0;
}

House::House(int floorsAmount, float livingSpace, int yearBuilt, string address, string owner, float price)
    : Building(livingSpace, yearBuilt, address, owner, price)
{
    this->floorsAmount = floorsAmount;
}

void House::enterData()
{
	Building::enterData();

	while (true)
	{
		cin.clear();

		cout << "Введите количество этажей: ";
		cin >> floorsAmount;

		if (floorsAmount >= 1 && floorsAmount <= 50)
		{
			break;
		}

		system("CLS");
		cout << "Некорректное значение. Повторите ввод: " << endl;
	}
}

int House::getFloorsAmount()
{
    return floorsAmount;
}

void House::setFloorsAmount(int floorsAmount)
{
    this->floorsAmount = floorsAmount;
}

ostream& operator<<(ostream& out, House& obj)
{
    return out << dynamic_cast<Building&>(obj) << setw(20) << obj.floorsAmount;
}

istream& operator>>(istream& in, House& obj)
{
    return in >> dynamic_cast<Building&>(obj) >> obj.floorsAmount;
}
