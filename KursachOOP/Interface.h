#pragma once

#include "NewBuilding.h"
#include "SecondaryHousing.h"
#include "Cottage.h"
#include "Country.h"
#include "Ground.h"
#include "Ring.h"
#include "Estate.h"

template<class T>
class Interface
{
public:
	Interface() {};
	~Interface() {};

	void service();

	T enterData();

	void searchData();
};

template <class T>
void Interface<T>::service()
{
	Ring<T> object;

	while (true)
	{
		cout << "Выберите операцию:" << endl << endl
			<< "1. Добавить данные в начало таблицы" << endl
			<< "2. Добавить данные в конец таблицы" << endl
			<< "3. Добавить данные в таблицу по индексу" << endl << endl
			<< "4. Удалить данные в начале таблицы" << endl
			<< "5. Удалить данные в конце таблицы" << endl
			<< "6. Удалить данные в таблице по индексу" << endl
			<< "7. Удалить все данные" << endl << endl
			<< "8. Редактировать данные" << endl << endl
			<< "9. Вывести данные на экран" << endl << endl
			<< "10. Работа с базой данных" << endl << endl
			<< "0. Назад" << endl;

		int choiceMenu;
		cin >> choiceMenu;

		system("CLS");

		T value;
		int index;

		switch (choiceMenu)
		{
		case 1:
			object.addToBegin(enterData());
			break;

		case 2:
			object.addToEnd(enterData());
			break;

		case 3:
			cout << "Введите индекс: ";
			cin >> index;

			if (index < 0 || index > object.getSize())
			{
				cout << "Неверный индекс" << endl;
				break;
			}

			object.addByIndex(enterData(), index);
			break;

		case 4:
			object.deleteFirst();
			break;

		case 5:
			object.deleteLast();
			break;

		case 6:
			cout << "Введите индекс: ";
			cin >> index;

			if (index < 0 || index > object.getSize())
			{
				cout << "Неверный индекс" << endl;
				break;
			}

			object.deleteByIndex(index);
			break;

		case 7:
			object.clear();
			break;

		case 8:
			cout << "Введите индекс: ";
			cin >> index;

			if (index < 0 || index > object.getSize())
			{
				cout << "Неверный индекс" << endl;
				break;
			}

			object.changeData(index);

			break;

		case 9:
			object.display();
			break;

		case 10:
			object.saveDataToFile();
			break;

		case 0:
			return;
		}

		cout << endl;
	}
}

template<class T>
T Interface<T>::enterData()
{
	cout << "Введите данные: ";
	T data;
	cin >> data;
	return data;
}

template<>
NewBuilding Interface<NewBuilding>::enterData()
{
	string city;
	while (true)
	{
		cin.clear();

		cout << "Введите город (напр. Минск): ";
		cin >> city;

		bool isIncorrectSymbol = false;
		for (int i = 0; i < city.length(); i++)
		{
			if (!(city[i] >= 'А' && city[i] <= 'я'))
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

	string owner;
	while (true)
	{
		cin.clear();

		cout << "Введите владельца (напр. Новострой): ";
		cin >> owner;
		
		if (owner.length() >= 2 && owner.length() <= 12)
		{
			break;
		}

		system("CLS");
		cout << "Некорректное значение. Повторите ввод: " << endl;
	}
	
	float price;
	while (true)
	{
		cin.clear();

		cout << "Введите цену (в долларах): ";
		cin >> price;

		if (price >= 100.0 && price <= 10000000.0)
		{
			break;
		}

		system("CLS");
		cout << "Некорректное значение. Повторите ввод: " << endl;
	}

	float livingSpace;
	while (true)
	{
		cin.clear();

		cout << "Введите жилую площадь (в квадратных метрах): ";
		cin >> livingSpace;

		if (livingSpace >= 1.0 && livingSpace <= 200.0)
		{
			break;
		}

		system("CLS");
		cout << "Некорректное значение. Повторите ввод: " << endl;
	}
	
	int yearBuilt;
	while (true)
	{
		cin.clear();

		cout << "Введите год постройки: ";
		cin >> yearBuilt;

		if (yearBuilt >= 1600 && yearBuilt <= 2021)
		{
			break;
		}

		system("CLS");
		cout << "Некорректное значение. Повторите ввод: " << endl;
	}
	
	int floor;
	while (true)
	{
		cin.clear();

		cout << "Введите этаж: ";
		cin >> floor;

		if (floor >= 1 && floor <= 150)
		{
			break;
		}

		system("CLS");
		cout << "Некорректное значение. Повторите ввод: " << endl;
	}
	
	int roomsAmount;
	while (true)
	{
		cin.clear();

		cout << "Введите количество комнат: ";
		cin >> roomsAmount;

		if (roomsAmount >= 1 && roomsAmount <= 50)
		{
			break;
		}

		system("CLS");
		cout << "Некорректное значение. Повторите ввод: " << endl;
	}
	
	int waranty;
	while (true)
	{
		cin.clear();

		cout << "Введите гарантия (лет): ";
		cin >> waranty;

		if (waranty >= 0 && waranty <= 20)
		{
			break;
		}

		system("CLS");
		cout << "Некорректное значение. Повторите ввод: " << endl;
	}

	NewBuilding object(waranty, roomsAmount, floor, livingSpace, yearBuilt, city, owner, price);
	return object;
}

template<>
SecondaryHousing Interface<SecondaryHousing>::enterData()
{
	string city;
	while (true)
	{
		cin.clear();

		cout << "Введите город (напр. Минск): ";
		cin >> city;

		bool isIncorrectSymbol = false;
		for (int i = 0; i < city.length(); i++)
		{
			if (!(city[i] >= 'А' && city[i] <= 'я'))
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

	string owner;
	while (true)
	{
		cin.clear();

		cout << "Введите владельца (напр. Новострой): ";
		cin >> owner;

		if (owner.length() >= 2 && owner.length() <= 12)
		{
			break;
		}

		system("CLS");
		cout << "Некорректное значение. Повторите ввод: " << endl;
	}

	float price;
	while (true)
	{
		cin.clear();

		cout << "Введите цену (в долларах): ";
		cin >> price;

		if (price >= 100.0 && price <= 10000000.0)
		{
			break;
		}

		system("CLS");
		cout << "Некорректное значение. Повторите ввод: " << endl;
	}

	float livingSpace;
	while (true)
	{
		cin.clear();

		cout << "Введите жилую площадь (в квадратных метрах): ";
		cin >> livingSpace;

		if (livingSpace >= 1.0 && livingSpace <= 200.0)
		{
			break;
		}

		system("CLS");
		cout << "Некорректное значение. Повторите ввод: " << endl;
	}

	int yearBuilt;
	while (true)
	{
		cin.clear();

		cout << "Введите год постройки: ";
		cin >> yearBuilt;

		if (yearBuilt >= 1600 && yearBuilt <= 2021)
		{
			break;
		}

		system("CLS");
		cout << "Некорректное значение. Повторите ввод: " << endl;
	}

	int floor;
	while (true)
	{
		cin.clear();

		cout << "Введите этаж: ";
		cin >> floor;

		if (floor >= 1 && floor <= 150)
		{
			break;
		}

		system("CLS");
		cout << "Некорректное значение. Повторите ввод: " << endl;
	}

	int roomsAmount;
	while (true)
	{
		cin.clear();

		cout << "Введите количество комнат: ";
		cin >> roomsAmount;

		if (roomsAmount >= 1 && roomsAmount <= 50)
		{
			break;
		}

		system("CLS");
		cout << "Некорректное значение. Повторите ввод: " << endl;
	}

	string typeOfRepair;
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

	SecondaryHousing object(city, owner, price, livingSpace, yearBuilt, roomsAmount, floor, typeOfRepair);
	return object;
}

template<>
Cottage Interface<Cottage>::enterData()
{
	string city;
	while (true)
	{
		cin.clear();

		cout << "Введите город (напр. Минск): ";
		cin >> city;

		bool isIncorrectSymbol = false;
		for (int i = 0; i < city.length(); i++)
		{
			if (!(city[i] >= 'А' && city[i] <= 'я'))
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

	string owner;
	while (true)
	{
		cin.clear();

		cout << "Введите владельца (напр. Новострой): ";
		cin >> owner;

		if (owner.length() >= 2 && owner.length() <= 12)
		{
			break;
		}

		system("CLS");
		cout << "Некорректное значение. Повторите ввод: " << endl;
	}

	float price;
	while (true)
	{
		cin.clear();

		cout << "Введите цену (в долларах): ";
		cin >> price;

		if (price >= 100.0 && price <= 10000000.0)
		{
			break;
		}

		system("CLS");
		cout << "Некорректное значение. Повторите ввод: " << endl;
	}

	float livingSpace;
	while (true)
	{
		cin.clear();

		cout << "Введите жилую площадь (в квадратных метрах): ";
		cin >> livingSpace;

		if (livingSpace >= 1.0 && livingSpace <= 200.0)
		{
			break;
		}

		system("CLS");
		cout << "Некорректное значение. Повторите ввод: " << endl;
	}

	int yearBuilt;
	while (true)
	{
		cin.clear();

		cout << "Введите год постройки: ";
		cin >> yearBuilt;

		if (yearBuilt >= 1600 && yearBuilt <= 2021)
		{
			break;
		}

		system("CLS");
		cout << "Некорректное значение. Повторите ввод: " << endl;
	}

	int floorsAmount;
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
	
	string nameOfVillage;
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
	
	Cottage object(nameOfVillage, floorsAmount, livingSpace, yearBuilt, city, owner, price);
	return object;
}

template<>
Country Interface<Country>::enterData()
{
	string city;
	while (true)
	{
		cin.clear();

		cout << "Введите город (напр. Минск): ";
		cin >> city;

		bool isIncorrectSymbol = false;
		for (int i = 0; i < city.length(); i++)
		{
			if (!(city[i] >= 'А' && city[i] <= 'я'))
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

	string owner;
	while (true)
	{
		cin.clear();

		cout << "Введите владельца (напр. Новострой): ";
		cin >> owner;

		if (owner.length() >= 2 && owner.length() <= 12)
		{
			break;
		}

		system("CLS");
		cout << "Некорректное значение. Повторите ввод: " << endl;
	}

	float price;
	while (true)
	{
		cin.clear();

		cout << "Введите цену (в долларах): ";
		cin >> price;

		if (price >= 100.0 && price <= 10000000.0)
		{
			break;
		}

		system("CLS");
		cout << "Некорректное значение. Повторите ввод: " << endl;
	}

	float livingSpace;
	while (true)
	{
		cin.clear();

		cout << "Введите жилую площадь (в квадратных метрах): ";
		cin >> livingSpace;

		if (livingSpace >= 1.0 && livingSpace <= 200.0)
		{
			break;
		}

		system("CLS");
		cout << "Некорректное значение. Повторите ввод: " << endl;
	}

	int yearBuilt;
	while (true)
	{
		cin.clear();

		cout << "Введите год постройки: ";
		cin >> yearBuilt;

		if (yearBuilt >= 1600 && yearBuilt <= 2021)
		{
			break;
		}

		system("CLS");
		cout << "Некорректное значение. Повторите ввод: " << endl;
	}

	int floorsAmount;
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

	int distanceFromCity;
	while (true)
	{
		cin.clear();

		cout << "Введите название посёлка: ";
		cin >> distanceFromCity;

		if (distanceFromCity >= 1 && distanceFromCity <= 50)
		{
			break;
		}

		system("CLS");
		cout << "Некорректное значение. Повторите ввод: " << endl;
	}

	Country object(distanceFromCity, floorsAmount, livingSpace, yearBuilt, city, owner, price);
	return object;
}

template<>
Ground Interface<Ground>::enterData()
{
	string city;
	while (true)
	{
		cin.clear();

		cout << "Введите город (напр. Минск): ";
		cin >> city;

		bool isIncorrectSymbol = false;
		for (int i = 0; i < city.length(); i++)
		{
			if (!(city[i] >= 'А' && city[i] <= 'я'))
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

	string owner;
	while (true)
	{
		cin.clear();

		cout << "Введите владельца (напр. Новострой): ";
		cin >> owner;

		if (owner.length() >= 2 && owner.length() <= 12)
		{
			break;
		}

		system("CLS");
		cout << "Некорректное значение. Повторите ввод: " << endl;
	}

	float price;
	while (true)
	{
		cin.clear();

		cout << "Введите цену (в долларах): ";
		cin >> price;

		if (price >= 100.0 && price <= 10000000.0)
		{
			break;
		}

		system("CLS");
		cout << "Некорректное значение. Повторите ввод: " << endl;
	}

	float landSquare;
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

	Ground object(landSquare, city, owner, price);
	return object;
}

template<>
void Interface<NewBuilding>::searchData()
{
	fstream fs;

	while (true)
	{
		fs.open("NewBuilding.txt", fstream::in | fstream::app);

		if (!fs.is_open())
		{
			cout << "Ошибка открытия файла" << endl;
		}
		else
		{
			cout << "Искать по: " << endl << endl
				<< "1. Городу" << endl
				<< "2. Цене" << endl
				<< "3. Количеству комнат" << endl << endl
				<< "0. Назад" << endl;

			int choice;
			cin >> choice;

			system("CLS");

			switch (choice)
			{
			case 1:
			{
				string city;
				cout << "Введите город: ";
				cin >> city;

				system("CLS");

				cout << setw(20) << "ГОРОД" << setw(20) << "ВЛАДЕЛЕЦ" << setw(10) << "ЦЕНА" << setw(18) << "ЖИЛ. ПЛОЩАДЬ" << setw(18) << "ГОД ПОСТРОЙКИ"
					<< setw(10) << "ЭТАЖ" << setw(20) << "КОЛ-ВО КОМНАТ" << setw(12) << "ГАРАНТИЯ" << endl;

				while (true)
				{
					NewBuilding object;
					fs >> object;

					if (fs.eof())
					{
						break;
					}

					if (object.getCity() == city)
					{
						cout << object;
					}
				}

				cout << endl;
			}
			break;

			case 2:
			{
				int minPrice;
				int maxPrice;

				cout << "Введите минимальную цену: ";
				cin >> minPrice;

				cout << "Введите максимальную цену: ";
				cin >> maxPrice;

				system("CLS");

				cout << setw(20) << "ГОРОД" << setw(20) << "ВЛАДЕЛЕЦ" << setw(10) << "ЦЕНА" << setw(18) << "ЖИЛ. ПЛОЩАДЬ" << setw(18) << "ГОД ПОСТРОЙКИ"
					<< setw(10) << "ЭТАЖ" << setw(20) << "КОЛ-ВО КОМНАТ" << setw(12) << "ГАРАНТИЯ" << endl;

				while (true)
				{
					NewBuilding object;
					fs >> object;

					if (fs.eof())
					{
						break;
					}

					if (object.getPrice() >= minPrice && object.getPrice() <= maxPrice)
					{
						cout << object;
					}

				}
			}
			break;

			case 3:
			{
				int roomsAmount;
				cout << "Введите количество комнат: ";
				cin >> roomsAmount;

				system("CLS");

				cout << setw(20) << "ГОРОД" << setw(20) << "ВЛАДЕЛЕЦ" << setw(10) << "ЦЕНА" << setw(18) << "ЖИЛ. ПЛОЩАДЬ" << setw(18) << "ГОД ПОСТРОЙКИ"
					<< setw(10) << "ЭТАЖ" << setw(20) << "КОЛ-ВО КОМНАТ" << setw(12) << "ГАРАНТИЯ" << endl;

				while (true)
				{
					NewBuilding object;
					fs >> object;

					if (fs.eof())
					{
						break;
					}

					if (object.getRoomsAmount() == roomsAmount)
					{
						cout << object;
					}

				}
			}
			break;

			case 0:
				return;
			}

			fs.close();
		}
	}
}

template<>
void Interface<SecondaryHousing>::searchData()
{
	fstream fs;

	while (true)
	{
		fs.open("SecondaryHousing.txt", fstream::in | fstream::app);

		if (!fs.is_open())
		{
			cout << "Ошибка открытия файла" << endl;
		}
		else
		{
			cout << "Искать по: " << endl << endl
				<< "1. Городу" << endl
				<< "2. Этаж" << endl
				<< "3. Жилая площадь" << endl << endl
				<< "0. Назад" << endl;

			int choice;
			cin >> choice;

			system("CLS");

			switch (choice)
			{
			case 1:
			{
				string city;
				cout << "Введите город: ";
				cin >> city;

				system("CLS");

				cout << setw(20) << "ГОРОД" << setw(20) << "ВЛАДЕЛЕЦ" << setw(10) << "ЦЕНА" << setw(18) << "ЖИЛ. ПЛОЩАДЬ" << setw(18) << "ГОД ПОСТРОЙКИ"
					<< setw(10) << "ЭТАЖ" << setw(20) << "КОЛ-ВО КОМНАТ" << setw(18) << "ТИП РЕМОНТА" << endl;

				while (true)
				{
					SecondaryHousing object;
					fs >> object;

					if (fs.eof())
					{
						break;
					}

					if (object.getCity() == city)
					{
						cout << object;
					}
				}

				cout << endl;
			}
			break;

			case 2:
			{
				int floor;
				cout << "Введите город: ";
				cin >> floor;

				system("CLS");

				cout << setw(20) << "ГОРОД" << setw(20) << "ВЛАДЕЛЕЦ" << setw(10) << "ЦЕНА" << setw(18) << "ЖИЛ. ПЛОЩАДЬ" << setw(18) << "ГОД ПОСТРОЙКИ"
					<< setw(10) << "ЭТАЖ" << setw(20) << "КОЛ-ВО КОМНАТ" << setw(18) << "ТИП РЕМОНТА" << endl;

				while (true)
				{
					SecondaryHousing object;
					fs >> object;

					if (fs.eof())
					{
						break;
					}

					if (object.getFloor() == floor)
					{
						cout << object;
					}
				}

				cout << endl;
			}
			break;

			case 3:
			{
				float minLivingSpace;
				float maxLivingSpace;

				cout << "Введите минимальную жилую площадь: ";
				cin >> minLivingSpace;

				cout << "Введите максимальную жилую площадь: ";
				cin >> maxLivingSpace;

				system("CLS");

				cout << setw(20) << "ГОРОД" << setw(20) << "ВЛАДЕЛЕЦ" << setw(10) << "ЦЕНА" << setw(18) << "ЖИЛ. ПЛОЩАДЬ" << setw(18) << "ГОД ПОСТРОЙКИ"
					<< setw(10) << "ЭТАЖ" << setw(20) << "КОЛ-ВО КОМНАТ" << setw(18) << "ТИП РЕМОНТА" << endl;

				while (true)
				{
					SecondaryHousing object;
					fs >> object;

					if (fs.eof())
					{
						break;
					}

					if (object.getLivingSpace() <= maxLivingSpace && object.getLivingSpace() >= minLivingSpace)
					{
						cout << object;
					}

				}
			}
			break;

			case 0:
				return;
			}

			fs.close();
		}
	}
}

template<>
void Interface<Cottage>::searchData()
{
	fstream fs;

	while (true)
	{
		fs.open("Cottage.txt", fstream::in | fstream::app);

		if (!fs.is_open())
		{
			cout << "Ошибка открытия файла" << endl;
		}
		else
		{
			cout << "Искать по: " << endl << endl
				<< "1. Город" << endl
				<< "2. Посёлок" << endl
				<< "3. Количество этажей" << endl << endl
				<< "0. Назад" << endl;

			int choice;
			cin >> choice;

			system("CLS");

			switch (choice)
			{
			case 1:
			{
				string city;
				cout << "Введите город: ";
				cin >> city;

				system("CLS");

				cout << setw(20) << "ГОРОД" << setw(20) << "ВЛАДЕЛЕЦ" << setw(10) << "ЦЕНА" << setw(18) << "ЖИЛ. ПЛОЩАДЬ" << setw(18) << "ГОД ПОСТРОЙКИ"
					<< setw(20) << "КОЛ-ВО ЭТАЖЕЙ" << setw(15) << "ПОСЁЛОК" << endl;

				while (true)
				{
					Cottage object;
					fs >> object;

					if (fs.eof())
					{
						break;
					}

					if (object.getCity() == city)
					{
						cout << object;
					}
				}

				cout << endl;
			}
			break;

			case 2:
			{
				string nameOfVillage;
				cout << "Введите название посёлка: ";
				cin >> nameOfVillage;

				system("CLS");

				cout << setw(20) << "ГОРОД" << setw(20) << "ВЛАДЕЛЕЦ" << setw(10) << "ЦЕНА" << setw(18) << "ЖИЛ. ПЛОЩАДЬ" << setw(18) << "ГОД ПОСТРОЙКИ"
					<< setw(20) << "КОЛ-ВО ЭТАЖЕЙ" << setw(15) << "ПОСЁЛОК" << endl;

				while (true)
				{
					Cottage object;
					fs >> object;

					if (fs.eof())
					{
						break;
					}

					if (object.getNameOfVillage() == nameOfVillage)
					{
						cout << object;
					}
				}

				cout << endl;
			}
			break;

			case 3:
			{
				int floorsAmount;
				cout << "Введите количество этажей: ";
				cin >> floorsAmount;

				system("CLS");

				cout << setw(20) << "ГОРОД" << setw(20) << "ВЛАДЕЛЕЦ" << setw(10) << "ЦЕНА" << setw(18) << "ЖИЛ. ПЛОЩАДЬ" << setw(18) << "ГОД ПОСТРОЙКИ"
					<< setw(20) << "КОЛ-ВО ЭТАЖЕЙ" << setw(15) << "ПОСЁЛОК" << endl;

				while (true)
				{
					Cottage object;
					fs >> object;

					if (fs.eof())
					{
						break;
					}

					if (object.getFloorsAmount() == floorsAmount)
					{
						cout << object;
					}

				}
			}
			break;

			case 0:
				return;
			}

			fs.close();
		}
	}
}

template<>
void Interface<Country>::searchData()
{
	fstream fs;

	while (true)
	{
		fs.open("Country.txt", fstream::in | fstream::app);

		if (!fs.is_open())
		{
			cout << "Ошибка открытия файла" << endl;
		}
		else
		{
			cout << "Искать по: " << endl << endl
				<< "1. Расстояние от города" << endl
				<< "2. Цена" << endl
				<< "3. Год постройки" << endl << endl
				<< "0. Назад" << endl;

			int choice;
			cin >> choice;

			system("CLS");

			switch (choice)
			{
			case 1:
			{
				int distanceFromCity;
				cout << "Введите максимальное расстяоние от города: ";
				cin >> distanceFromCity;

				system("CLS");

				cout << setw(20) << "ГОРОД" << setw(20) << "ВЛАДЕЛЕЦ" << setw(10) << "ЦЕНА" << setw(18) << "ЖИЛ. ПЛОЩАДЬ" << setw(18) << "ГОД ПОСТРОЙКИ"
					<< setw(20) << "КОЛ-ВО ЭТАЖЕЙ" << setw(25) << "РАССТОЯНИЕ ОТ ГОРОДА" << endl;

				while (true)
				{
					Country object;
					fs >> object;

					if (fs.eof())
					{
						break;
					}

					if (object.getDistanceFromCity() <= distanceFromCity)
					{
						cout << object;
					}
				}

				cout << endl;
			}
			break;

			case 2:
			{
				int minPrice;
				int maxPrice;

				cout << "Введите минимальную цену: ";
				cin >> minPrice;

				cout << "Введите максимальную цену: ";
				cin >> maxPrice;

				system("CLS");

				cout << setw(20) << "ГОРОД" << setw(20) << "ВЛАДЕЛЕЦ" << setw(10) << "ЦЕНА" << setw(18) << "ЖИЛ. ПЛОЩАДЬ" << setw(18) << "ГОД ПОСТРОЙКИ"
					<< setw(20) << "КОЛ-ВО ЭТАЖЕЙ" << setw(25) << "РАССТОЯНИЕ ОТ ГОРОДА" << endl;

				while (true)
				{
					Country object;
					fs >> object;

					if (fs.eof())
					{
						break;
					}

					if (object.getPrice() >= minPrice && object.getPrice() <= maxPrice)
					{
						cout << object;
					}

				}
			}
			break;

			case 3:
			{
				int yearBuilt;
				cout << "Введите год постройки: ";
				cin >> yearBuilt;

				system("CLS");

				cout << setw(20) << "ГОРОД" << setw(20) << "ВЛАДЕЛЕЦ" << setw(10) << "ЦЕНА" << setw(18) << "ЖИЛ. ПЛОЩАДЬ" << setw(18) << "ГОД ПОСТРОЙКИ"
					<< setw(20) << "КОЛ-ВО ЭТАЖЕЙ" << setw(25) << "РАССТОЯНИЕ ОТ ГОРОДА" << endl;

				while (true)
				{
					Country object;
					fs >> object;

					if (fs.eof())
					{
						break;
					}

					if (object.getYearBuilt() == yearBuilt)
					{
						cout << object;
					}

				}
			}
			break;

			case 0:
				return;
			}

			fs.close();
		}
	}
}

template<>
void Interface<Ground>::searchData()
{
	fstream fs;

	while (true)
	{
		fs.open("Ground.txt", fstream::in | fstream::app);

		if (!fs.is_open())
		{
			cout << "Ошибка открытия файла" << endl;
		}
		else
		{
			cout << "Искать по: " << endl << endl
				<< "1. Площадь земельного участка" << endl
				<< "2. Цена" << endl
				<< "3. Город" << endl << endl
				<< "0. Назад" << endl;

			int choice;
			cin >> choice;

			system("CLS");

			switch (choice)
			{
			case 1:
			{
				float minLandSquare;
				float maxLandSquare;

				cout << "Введите минимальную площадь земельного участка: ";
				cin >> minLandSquare;

				cout << "Введите максимальную площадь земельного участка: ";
				cin >> maxLandSquare;

				system("CLS");

				cout << setw(20) << "ГОРОД" << setw(20) << "ВЛАДЕЛЕЦ" << setw(10) << "ЦЕНА" << setw(20) << "ПЛОЩАДЬ УЧАСТКА" << endl;

				while (true)
				{
					Ground object;
					fs >> object;

					if (fs.eof())
					{
						break;
					}

					if (object.getLandSquare() <= maxLandSquare && object.getLandSquare() >= minLandSquare)
					{
						cout << object;
					}
				}

				cout << endl;
			}
			break;

			case 2:
			{
				int minPrice;
				int maxPrice;

				cout << "Введите минимальную цену: ";
				cin >> minPrice;

				cout << "Введите максимальную цену: ";
				cin >> maxPrice;

				system("CLS");

				cout << setw(20) << "ГОРОД" << setw(20) << "ВЛАДЕЛЕЦ" << setw(10) << "ЦЕНА" << setw(20) << "ПЛОЩАДЬ УЧАСТКА" << endl;

				while (true)
				{
					Ground object;
					fs >> object;

					if (fs.eof())
					{
						break;
					}

					if (object.getPrice() >= minPrice && object.getPrice() <= maxPrice)
					{
						cout << object;
					}

				}
			}
			break;

			case 3:
			{
				string city;
				cout << "Введите город: ";
				cin >> city;

				system("CLS");

				cout << setw(20) << "ГОРОД" << setw(20) << "ВЛАДЕЛЕЦ" << setw(10) << "ЦЕНА" << setw(20) << "ПЛОЩАДЬ УЧАСТКА" << endl;

				while (true)
				{
					Ground object;
					fs >> object;

					if (fs.eof())
					{
						break;
					}

					if (object.getCity() == city)
					{
						cout << object;
					}

				}
			}
			break;

			case 0:
				return;
			}

			fs.close();
		}
	}
}