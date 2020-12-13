#include "SecondaryHousing.h"

SecondaryHousing::SecondaryHousing() : Apartment()
{
    this->typeOfRepair = "";
}

SecondaryHousing::SecondaryHousing(string city, string owner, float price, float livingSpace, int yearBuilt, int roomsAmount, int floor, string typeOfRepair)
    : Apartment(roomsAmount, floor, livingSpace, yearBuilt, city, owner, price)
{
    this->typeOfRepair = typeOfRepair;
}

void SecondaryHousing::enterData()
{
	Apartment::enterData();

	while (true)
	{
		cin.clear();

		cout << "Введите тип ремонта (напр. Евроремонт): ";
		cin >> typeOfRepair;

		bool isIncorrectSymbol = false;
		for (int i = 0; i < typeOfRepair.length(); i++)
		{
			if (typeOfRepair[i] >= '0' && typeOfRepair[i] <= '9')
			{
				isIncorrectSymbol = true;
				break;
			}
		}

		if (!isIncorrectSymbol)
		{
			break;
		}

		system("CLS");
		cout << "Некорректное значение. Повторите ввод: " << endl;
	}
}

string SecondaryHousing::getTypeOfRepair()
{
    return typeOfRepair;
}

void SecondaryHousing::setTypeOfRepair(string typeOfRepair)
{
    this->typeOfRepair = typeOfRepair;
}

ostream& operator<<(ostream& out, SecondaryHousing& obj)
{
    return out << dynamic_cast<Apartment&>(obj) << setw(18) << obj.typeOfRepair << "\n";
}

istream& operator>>(istream& in, SecondaryHousing& obj)
{
    return in >> dynamic_cast<Apartment&>(obj) >> obj.typeOfRepair;
}
