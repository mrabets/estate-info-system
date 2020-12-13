#include "Ground.h"

Ground::Ground() : Estate()
{
    this->landSquare = 0.0f;
}

Ground::Ground(float landSquare, string city, string owner, float price)
    : Estate(city, owner, price)
{
    this->landSquare = landSquare;
}

void Ground::enterData()
{
	Estate::enterData();

	while (true)
	{
		cin.clear();

		cout << "Введите площадь земельного участка (в квадратных метрах): ";
		cin >> landSquare;

		if (landSquare >= 0.1 && landSquare <= 200.0)
		{
			break;
		}

		system("CLS");
		cout << "Некорректное значение. Повторите ввод: " << endl;
	}
}

float Ground::getLandSquare()
{
    return landSquare;
}

void Ground::setLandSquare(float landSquare)
{
    this->landSquare = landSquare;
}

ostream& operator<<(ostream& out, Ground& obj)
{
    return out << dynamic_cast<Estate&>(obj) << setw(20) << obj.landSquare << "\n";
}

istream& operator>>(istream& in, Ground& obj)
{
    return in >> dynamic_cast<Estate&>(obj) >> obj.landSquare;
}
