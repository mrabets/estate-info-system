#include "NewBuilding.h"

NewBuilding::NewBuilding() : Apartment()
{
    this->warranty = 0;
}

NewBuilding::NewBuilding(int warranty, int roomsAmount, int floor, float livingSpace, int yearBuilt, string city, string owner, float price)
    : Apartment(roomsAmount, floor, livingSpace, yearBuilt, city, owner, price)
{
    this->warranty = warranty;
}

void NewBuilding::enterData()
{
	Apartment::enterData();

	while (true)
	{
		cin.clear();

		cout << "Введите гарантия (лет): ";
		cin >> warranty;

		if (warranty >= 0 && warranty <= 20)
		{
			break;
		}

		system("CLS");
		cout << "Некорректное значение. Повторите ввод: " << endl;
	}
}

int NewBuilding::getWarranty()
{
    return warranty;
}

void NewBuilding::setWarranty(int warranty)
{
    this->warranty = warranty;
}

ostream& operator<<(ostream& out, NewBuilding& obj)
{
    return out << dynamic_cast<Apartment&>(obj) << setw(12) << obj.warranty << "\n";
}

istream& operator>>(istream& in, NewBuilding& obj)
{
    return in >> dynamic_cast<Apartment&>(obj) >> obj.warranty;
}
