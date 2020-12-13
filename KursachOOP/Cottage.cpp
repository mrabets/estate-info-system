#include "Cottage.h"

Cottage::Cottage() : House()
{
    this->nameOfVillage = "";
}

Cottage::Cottage(string nameOfVillage, int floorsAmount, float livingSpace, int yearBuilt, string city, string owner, float price)
    : House(floorsAmount, livingSpace, yearBuilt, city, owner, price)
{
    this->nameOfVillage = nameOfVillage;
}

void Cottage::enterData()
{
	House::enterData();

	while (true)
	{
		cin.clear();

		cout << "Введите название посёлка: ";
		cin >> nameOfVillage;

		bool isIncorrectSymbol = false;
		for (int i = 0; i < nameOfVillage.length(); i++)
		{
			if (!(nameOfVillage[i] >= 'А' && nameOfVillage[i] <= 'я'))
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

string Cottage::getNameOfVillage()
{
    return nameOfVillage;
}

void Cottage::setNameOfVillage(string nameOfVillage)
{
    this->nameOfVillage = nameOfVillage;
}

ostream& operator<<(ostream& out, Cottage& obj)
{
    return out << dynamic_cast<House&>(obj) << setw(15) << obj.nameOfVillage << "\n";
}

istream& operator>>(istream& in, Cottage& obj)
{
    return in >> dynamic_cast<House&>(obj) >> obj.nameOfVillage;  
}
