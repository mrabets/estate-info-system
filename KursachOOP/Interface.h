#pragma once

#include "NewBuilding.h"
#include "SecondaryHousing.h"
#include "Cottage.h"
#include "Country.h"
#include "Ground.h"
#include "Ring.h"
#include "Admin.h"
#include "User.h"

//void pointOfEntry();
//
//void userMenu();
//bool isUserAuthorization();
//void userRegistration();
//void userFileCreating();
//
//void viewEstate();
//
//void adminMenu();
//bool isAdminAuthorization();
//void adminRegistration();
//void userManage();
//void adminFileCreating();

//string encryptDecrypt(string toEncrypt);

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
	
	int price;
	while (true)
	{
		cin.clear();

		cout << "Введите цену (в долларах): ";
		cin >> price;

		if (price >= 100 && price <= 10000000)
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

		if (livingSpace >= 1.0 && price <= 200.0)
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

	int price;
	while (true)
	{
		cin.clear();

		cout << "Введите цену (в долларах): ";
		cin >> price;

		if (price >= 100 && price <= 10000000)
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

		if (livingSpace >= 1.0 && price <= 200.0)
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

	int price;
	while (true)
	{
		cin.clear();

		cout << "Введите цену (в долларах): ";
		cin >> price;

		if (price >= 100 && price <= 10000000)
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

		if (livingSpace >= 1.0 && price <= 200.0)
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

	int price;
	while (true)
	{
		cin.clear();

		cout << "Введите цену (в долларах): ";
		cin >> price;

		if (price >= 100 && price <= 10000000)
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

		if (livingSpace >= 1.0 && price <= 200.0)
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

	int price;
	while (true)
	{
		cin.clear();

		cout << "Введите цену (в долларах): ";
		cin >> price;

		if (price >= 100 && price <= 10000000)
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

//
//void typeChoosing()
//{
//	while (true)
//	{
//		int choiceDevice;
//
//		cout << "Выберите объект недвижимости: " << endl << endl
//			<< "1. Новостройка" << endl
//			<< "2. Вторичка" << endl << endl
//			<< "3. Коттедж" << endl
//			<< "4. Дача" << endl << endl
//			<< "5. Участок" << endl << endl
//			<< "0. Выйти в главное меню" << endl;
//
//		cin >> choiceDevice;
//
//		system("CLS");
//
//		switch (choiceDevice)
//		{
//		case 1:
//		{
//			Interface<NewBuilding> object;
//			object.serviceMenuAdmin();
//		}
//		break;
//
//		case 2:
//		{
//			Interface<SecondaryHousing> object;
//			object.serviceMenuAdmin();
//		}
//		break;
//
//		case 3:
//		{
//			Interface<Cottage> object;
//			object.serviceMenuAdmin();
//		}
//		break;
//
//		case 4:
//		{
//			Interface<Country> object;
//			object.serviceMenuAdmin();
//		}
//		break;
//
//		case 5:
//		{
//			Interface<Ground> object;
//			object.serviceMenuAdmin();
//		}
//		break;
//
//		case 0:
//			return;
//		}
//	}
//}
//
//
//void pointOfEntry()
//{
//	ifstream fin;
//
//	fin.open("Admin.txt");
//
//	if (!fin.is_open())
//	{
//		adminFileCreating();
//	}
//
//	fin.close();
//
//	fin.open("User.txt");
//
//	if (!fin.is_open())
//	{
//		userFileCreating();
//	}
//
//	fin.close();
//
//	while (true)
//	{
//		cout << "Выберите тип входа: " << endl
//			<< "1. Пользователь" << endl
//			<< "2. Администратор" << endl;
//
//		int choice;
//		cin >> choice;
//
//		system("CLS");
//
//		switch (choice)
//		{
//		case 1:
//			userRegistration();
//			break;
//
//		case 2:
//			if (isAdminAuthorization())
//			{
//				cout << "Вы вошли в систему" << endl;
//				adminMenu();
//			}
//			else
//			{
//				cout << "Неверный логин или пароль" << endl;
//			}
//			break;
//
//		case 0:
//			return;
//		}
//	}
//}
//
//
//
//void viewEstate()
//{
//	while (true)
//	{
//		string fileName;
//
//		cout << "Просмотреть: " << endl << endl
//			<< "1. Новостройки" << endl
//			<< "2. Вторички" << endl
//			<< "3. Коттеджи" << endl
//			<< "4. Дачи" << endl
//			<< "5. Участки" << endl << endl
//			<< "0. Назад" << endl;
//
//		int choice;
//		cin >> choice;
//
//		system("CLS");
//
//		switch (choice)
//		{
//		case 1:
//			cout << setw(20) << "ГОРОД" << setw(20) << "ВЛАДЕЛЕЦ" << setw(10) << "ЦЕНА" << setw(18) << "ЖИЛ. ПЛОЩАДЬ" << setw(18) << "ГОД ПОСТРОЙКИ"
//				<< setw(10) << "ЭТАЖ" << setw(20) << "КОЛ-ВО КОМНАТ" << setw(12) << "ГАРАНТИЯ" << endl;
//
//			fileName = "NewBuilding.txt";
//			break;
//
//		case 2:
//			cout << setw(20) << "ГОРОД" << setw(20) << "ВЛАДЕЛЕЦ" << setw(10) << "ЦЕНА" << setw(18) << "ЖИЛ. ПЛОЩАДЬ" << setw(18) << "ГОД ПОСТРОЙКИ"
//				<< setw(10) << "ЭТАЖ" << setw(20) << "КОЛ-ВО КОМНАТ" << setw(18) << "ТИП РЕМОНТА" << endl;
//
//			fileName = "SecondaryHousing.txt";
//			break;
//
//		case 3:
//			cout << setw(20) << "ГОРОД" << setw(20) << "ВЛАДЕЛЕЦ" << setw(10) << "ЦЕНА" << setw(18) << "ЖИЛ. ПЛОЩАДЬ" << setw(18) << "ГОД ПОСТРОЙКИ"
//				<< setw(20) << "КОЛ-ВО ЭТАЖЕЙ" << setw(15) << "ПОСЁЛОК" << endl;
//
//			fileName = "Cottage.txt";
//			break;
//
//		case 4:
//			cout << setw(20) << "ГОРОД" << setw(20) << "ВЛАДЕЛЕЦ" << setw(10) << "ЦЕНА" << setw(18) << "ЖИЛ. ПЛОЩАДЬ" << setw(18) << "ГОД ПОСТРОЙКИ"
//				<< setw(20) << "КОЛ-ВО ЭТАЖЕЙ" << setw(25) << "РАССТОЯНИЕ ОТ ГОРОДА" << endl;
//
//			fileName = "Country.txt";
//			break;
//
//		case 5:
//			cout << setw(20) << "ГОРОД" << setw(20) << "ВЛАДЕЛЕЦ" << setw(10) << "ЦЕНА" << setw(20) << "ПЛОЩАДЬ УЧАСТКА" << endl;
//
//			fileName = "Ground.txt";
//			break;
//
//		case 0:
//			return;
//		}
//
//		fstream fs;
//
//		fs.open(fileName, fstream::in);
//
//		if (!fs.is_open())
//		{
//			cout << "Данный тип недвижимости отсутсвует в каталоге" << endl;
//		}
//		else
//		{
//			char ch;
//			while (fs.get(ch))
//			{
//				cout << ch;
//			}
//		}
//		fs.close();
//	}
//}
//
//void searchEstate()
//{
//	while (true)
//	{
//		string fileName;
//
//		cout << "Искать в разделе: " << endl << endl
//			<< "1. Всю недвижимость" << endl
//			<< "2. Новостройки" << endl
//			<< "3. Вторички" << endl
//			<< "4. Коттеджи" << endl
//			<< "5. Дачи" << endl
//			<< "6. Участки" << endl << endl
//			<< "0. Назад" << endl;
//
//		int choice;
//		cin >> choice;
//
//		system("CLS");
//
//		switch (choice)
//		{
//		case 2:
//		{
//			Interface<NewBuilding> object;
//			object.searchData();
//		}
//		break;
//
//		case 3:
//			cout << setw(20) << "ГОРОД" << setw(20) << "ВЛАДЕЛЕЦ" << setw(10) << "ЦЕНА" << setw(18) << "ЖИЛ. ПЛОЩАДЬ" << setw(18) << "ГОД ПОСТРОЙКИ"
//				<< setw(10) << "ЭТАЖ" << setw(20) << "КОЛ-ВО КОМНАТ" << setw(18) << "ТИП РЕМОНТА" << endl;
//
//			fileName = "SecondaryHousing.txt";
//			break;
//
//		case 4:
//			cout << setw(20) << "ГОРОД" << setw(20) << "ВЛАДЕЛЕЦ" << setw(10) << "ЦЕНА" << setw(18) << "ЖИЛ. ПЛОЩАДЬ" << setw(18) << "ГОД ПОСТРОЙКИ"
//				<< setw(20) << "КОЛ-ВО ЭТАЖЕЙ" << setw(15) << "ПОСЁЛОК" << endl;
//
//			fileName = "Cottage.txt";
//			break;
//
//		case 5:
//			cout << setw(20) << "ГОРОД" << setw(20) << "ВЛАДЕЛЕЦ" << setw(10) << "ЦЕНА" << setw(18) << "ЖИЛ. ПЛОЩАДЬ" << setw(18) << "ГОД ПОСТРОЙКИ"
//				<< setw(20) << "КОЛ-ВО ЭТАЖЕЙ" << setw(25) << "РАССТОЯНИЕ ОТ ГОРОДА" << endl;
//
//			fileName = "Country.txt";
//			break;
//
//		case 6:
//			cout << setw(20) << "ГОРОД" << setw(20) << "ВЛАДЕЛЕЦ" << setw(10) << "ЦЕНА" << setw(20) << "ПЛОЩАДЬ УЧАСТКА" << endl;
//
//			fileName = "Ground.txt";
//			break;
//
//		case 0:
//			return;
//		}
//
//		fstream fs;
//
//		fs.open(fileName, fstream::in);
//
//		if (fs.is_open())
//		{
//			cout << "Данный тип недвижимости отсутсвует в каталоге" << endl;
//		}
//		else
//		{
//
//		}
//		fs.close();
//	}
//}
//
//void userMenu()
//{
//	while (true)
//	{
//		cout << "Выберите опцию: " << endl
//			<< "1. Просмотреть недвижимость" << endl
//			<< "2. Искать недвижимость по параметрам" << endl
//			<< "3. Купить недвижимость" << endl << endl
//			<< "0. Назад" << endl;
//
//		int choice;
//		cin >> choice;
//
//		system("CLS");
//
//		switch (choice)
//		{
//		case 1:
//			viewEstate();
//			break;
//
//		case 2:
//			searchEstate();
//			break;
//
//		case 3:
//		{
//			viewEstate();
//
//			break;
//		}
//			
//		case 0:
//			return;
//		}
//	}
//}
//
//bool isUserAuthorization()
//{
//	cout << "Логин: ";
//
//	string login;
//	cin >> login;
//
//	cout << "Пароль: ";
//
//	string password;
//	cin >> password;
//
//	system("CLS");
//
//	ifstream fin;
//
//	fin.open("User.txt");
//
//	if (!fin.is_open())
//	{
//		cout << "Ошибка открытия файла" << endl;
//	}
//	else
//	{
//		while (true)
//		{
//			User obj;
//			fin >> obj;
//
//			if (fin.eof())
//			{
//				break;
//			}
//
//			if (login == obj.getLogin() && password == encryptDecrypt(obj.getPassword()))
//			{
//				fin.close();
//				return true;
//			}
//		}
//	}
//
//	fin.close();
//	return false;
//}
//
//void userRegistration()
//{
//	fstream fs;
//
//	while (true)
//	{
//		fs.open("User.txt", fstream::in | fstream::out | fstream::app);
//
//		if (!fs.is_open())
//		{
//			cout << "Ошибка открытия файла" << endl;
//		}
//		else
//		{
//			cout << "Выберите опцию: " << endl
//				<< "1. Авторизация" << endl
//				<< "2. Регистрация" << endl;
//
//			int userChoice;
//			cin >> userChoice;
//
//			system("CLS");
//
//			switch (userChoice)
//			{
//			case 1:
//				if (isUserAuthorization())
//				{
//					cout << "Вы вошли в систему" << endl;
//					userMenu();
//				}
//				else
//				{
//					cout << "Неверный логин или пароль" << endl;
//				}
//
//				break;
//
//			case 2:
//			{
//				string login;
//				while (true)
//				{
//					cin.clear();
//
//					cout << "Логин: ";
//
//					cin >> login;
//
//					if (login.length() >= 5 && login.length() <= 12)
//					{
//						break;
//					}
//
//					system("CLS");
//					cout << "Некорректное значение. Повторите ввод: " << endl;
//				}
//
//				string password;
//				while (true)
//				{
//					cin.clear();
//
//					cout << "Пароль: ";
//
//					cin >> password;
//
//					if (password.length() >= 5 && password.length() <= 12)
//					{
//						password = encryptDecrypt(password);
//						break;
//					}
//
//					system("CLS");
//					cout << "Некорректное значение. Повторите ввод: " << endl;
//				}
//
//				int age;
//				while (true)
//				{
//					cin.clear();
//
//					cout << "Возраст: ";
//
//					cin >> age;
//
//					if (age >= 18 && age <= 120)
//					{
//						break;
//					}
//
//					system("CLS");
//					cout << "Некорректное значение. Повторите ввод: " << endl;
//				}
//
//				char sex;
//				while (true)
//				{
//					cin.clear();
//
//					cout << "Пол (М - мужской, Ж - женский): ";
//
//					cin >> sex;
//
//					if (sex == 'М' || sex == 'Ж' || sex == 'м' || sex == 'ж')
//					{
//						break;
//					}
//
//					system("CLS");
//					cout << "Некорректное значение. Повторите ввод: " << endl;
//				}
//
//				string phone;
//				while (true)
//				{
//					cin.clear();
//
//					cout << "Номер мобильного телефона (напр. +375257712277): ";
//
//					cin >> phone;
//
//					if (phone.length() != 13 || phone[0] != '+')
//					{
//						system("CLS");
//						cout << "Некорректное значение. Повторите ввод: " << endl;
//					}
//
//					bool isAllDigit = true;
//					for (int i = 1; i < phone.length(); i++)
//					{
//						if (phone[i] < '0' || phone[i] > '9')
//						{
//							isAllDigit = false;
//							break;
//						}
//					}
//
//					if (isAllDigit)
//					{
//						break;
//					}
//
//					system("CLS");
//					cout << "Некорректное значение. Повторите ввод: " << endl;
//				}
//
//				string email;
//				while (true)
//				{
//					cin.clear();
//
//					cout << "Адрес электронной почты: ";
//					cin >> email;
//
//					bool isSign = false;
//					bool isPoint = false;
//					for (int i = 0; i < email.length(); i++)
//					{
//						if (email[i] == '@' && !isSign)
//						{
//							isSign = true;
//						}
//
//						if (email[i] == '.' && i != email.length() - 1 && !isPoint && isSign)
//						{
//							isPoint = true;
//						}
//					}
//
//					if (isSign && isPoint)
//					{
//						break;
//					}
//
//					system("CLS");
//					cout << "Некорректное значение. Повторите ввод: " << endl;
//				}
//
//				system("CLS");
//
//				User user(login, password, age, sex, phone, email);
//
//				fs << user;
//
//				cout << "Успешная регистрация" << endl;
//
//				break;
//			}
//
//			case 0:
//				return;
//			}
//		}
//
//		fs.close();
//	}
//}
//
//void userFileCreating()
//{
//	ofstream fout;
//
//	fout.open("User.txt");
//
//	if (!fout.is_open())
//	{
//		cout << "Ошибка открытия файла" << endl;
//	}
//
//	fout.close();
//}
//
//
//void adminMenu()
//{
//	while (true)
//	{
//		cout << "Выберите опцию: " << endl << endl
//			<< "1. Работа с объектами" << endl
//			<< "2. Работа с учетными записями администраторов" << endl
//			<< "3. Работа с учетными записями пользователей" << endl << endl
//			<< "0. Назад" << endl;
//
//		int choice;
//		cin >> choice;
//
//		system("CLS");
//
//		switch (choice)
//		{
//		case 1:
//			typeChoosing();
//			break;
//
//		case 2:
//			adminRegistration();
//			break;
//
//		case 3:
//			userManage();
//			break;
//
//		case 0:
//			return;
//		}
//	}
//}
//
//bool isAdminAuthorization()
//{
//	cout << "Логин: ";
//
//	string login;
//	cin >> login;
//
//	cout << "Пароль: ";
//
//	string password;
//	cin >> password;
//
//	system("CLS");
//
//	ifstream fin;
//
//	fin.open("Admin.txt");
//
//	if (!fin.is_open())
//	{
//		cout << "Ошибка открытия файла" << endl;
//	}
//	else
//	{
//		while (true)
//		{
//			Admin obj;
//			fin >> obj;
//
//			if (fin.eof())
//			{
//				break;
//			}
//
//			if (login == obj.getLogin() && password == encryptDecrypt(obj.getPassword()))
//			{
//				fin.close();
//				return true;
//			}
//		}
//	}
//
//	fin.close();
//	return false;
//}
//
//void adminRegistration()
//{
//	fstream fs;
//	while (true)
//	{
//		fs.open("Admin.txt", fstream::in | fstream::out | fstream::app);
//
//		if (!fs.is_open())
//		{
//			cout << "Ошибка открытия файла" << endl;
//		}
//		else
//		{
//			cout << "Выберите опцию: " << endl << endl
//				<< "1. Зарегистрировать нового администратора" << endl
//				<< "2. Посмотреть список всех администраторов" << endl << endl
//				<< "0. Назад" << endl;
//
//			int choice;
//			cin >> choice;
//
//			system("CLS");
//
//			switch (choice)
//			{
//			case 1:
//			{
//				string login;
//				while (true)
//				{
//					cin.clear();
//
//					cout << "Логин: ";
//
//					cin >> login;
//
//					if (login.length() >= 5 && login.length() <= 12)
//					{
//						break;
//					}
//
//					system("CLS");
//					cout << "Некорректное значение. Повторите ввод: " << endl;
//				}
//
//				string password;
//				while (true)
//				{
//					cin.clear();
//
//					cout << "Пароль: ";
//
//					cin >> password;
//
//					if (password.length() >= 5 && password.length() <= 12)
//					{
//						password = encryptDecrypt(password);
//						break;
//					}
//
//					system("CLS");
//					cout << "Некорректное значение. Повторите ввод: " << endl;
//				}
//
//				system("CLS");
//
//				Admin admin(login, password);
//
//				fs << admin;
//
//				cout << "Успешное добавление нового администратора" << endl;
//
//				break;
//			}		
//
//			case 2:
//			{	
//				cout << setw(12) << "ЛОГИН" << setw(12) << "ПАРОЛЬ" << endl;
//
//				while (true)
//				{
//					Admin obj;
//					fs >> obj;
//
//					if (fs.eof())
//					{
//						break;
//					}
//
//					cout << obj;
//				}
//
//				break;
//			}
//
//			case 0:
//				return;
//			}
//
//			fs.close();
//		}
//
//	}
//
//
//}
//
//void userManage()
//{
//	fstream fs;
//	while (true)
//	{
//		fs.open("User.txt", fstream::in | fstream::out | fstream::app);
//
//		if (!fs.is_open())
//		{
//			cout << "Ошибка открытия файла" << endl;
//		}
//		else
//		{
//			cout << "Выберите опцию: " << endl << endl
//				<< "1. Просмотреть данные всех пользователей" << endl
//				<< "2. Просмотреть данные определенного пользователя" << endl
//				<< "3. Добавить нового пользователя" << endl << endl
//				<< "0. Назад" << endl;
//
//			int choice;
//			cin >> choice;
//
//			system("CLS");
//
//			switch (choice)
//			{
//			case 1:
//			{
//				cout << setw(12) << "ЛОГИН" << setw(12) << "ПАРОЛЬ" << setw(10) << "ВОЗРАСТ" << setw(5) << "ПОЛ" << setw(18) << "МОБ.НОМЕР" << setw(22) << "ЕМЕЙЛ" << endl;
//
//				while (true)
//				{
//					User obj;
//					fs >> obj;
//
//					if (fs.eof())
//					{
//						break;
//					}
//
//					cout << obj;
//				}
//
//				break;
//			}
//
//			case 2:
//			{
//				cout << setw(12) << "ЛОГИН" << setw(12) << "ПАРОЛЬ" << setw(10) << "ВОЗРАСТ" << setw(5) << "ПОЛ" << setw(18) << "МОБ.НОМЕР" << setw(22) << "ЕМЕЙЛ" << endl;
//
//				string login;
//				while (true)
//				{
//					cin.clear();
//
//					cout << "Логин пользователя: ";
//
//					cin >> login;
//
//					if (login.length() >= 5 && login.length() <= 12)
//					{
//						break;
//					}
//
//					system("CLS");
//					cout << "Некорректное значение. Повторите ввод: " << endl;
//				}
//
//				while (true)
//				{
//					User obj;
//					fs >> obj;
//
//					if (fs.eof())
//					{
//						break;
//					}
//
//					if (obj.getLogin() == login)
//					{
//						cout << obj;
//						break;
//					}
//
//				}
//
//				break;
//			}
//
//			case 3:
//			{
//				string login;
//				while (true)
//				{
//					cin.clear();
//
//					cout << "Логин: ";
//
//					cin >> login;
//
//					if (login.length() >= 5 && login.length() <= 12)
//					{
//						break;
//					}
//
//					system("CLS");
//					cout << "Некорректное значение. Повторите ввод: " << endl;
//				}
//
//				string password;
//				while (true)
//				{
//					cin.clear();
//
//					cout << "Пароль: ";
//
//					cin >> password;
//
//					if (password.length() >= 5 && password.length() <= 12)
//					{
//						password = encryptDecrypt(password);
//						break;
//					}
//
//					system("CLS");
//					cout << "Некорректное значение. Повторите ввод: " << endl;
//				}
//
//				int age;
//				while (true)
//				{
//					cin.clear();
//
//					cout << "Возраст: ";
//
//					cin >> age;
//
//					if (age >= 18 && age <= 120)
//					{
//						break;
//					}
//
//					system("CLS");
//					cout << "Некорректное значение. Повторите ввод: " << endl;
//				}
//
//				char sex;
//				while (true)
//				{
//					cin.clear();
//
//					cout << "Пол (М - мужской, Ж - женский): ";
//
//					cin >> sex;
//
//					if (sex == 'М' || sex == 'Ж' || sex == 'м' || sex == 'ж')
//					{
//						break;
//					}
//
//					system("CLS");
//					cout << "Некорректное значение. Повторите ввод: " << endl;
//				}
//
//				string phone;
//				while (true)
//				{
//					cin.clear();
//
//					cout << "Номер мобильного телефона (напр. +375257712277): ";
//
//					cin >> phone;
//
//					if (phone.length() != 13 || phone[0] != '+')
//					{
//						system("CLS");
//						cout << "Некорректное значение. Повторите ввод: " << endl;
//					}
//
//					bool isAllDigit = true;
//					for (int i = 1; i < phone.length(); i++)
//					{
//						if (phone[i] < '0' || phone[i] > '9')
//						{
//							isAllDigit = false;
//							break;
//						}
//					}
//
//					if (isAllDigit)
//					{
//						break;
//					}
//
//					system("CLS");
//					cout << "Некорректное значение. Повторите ввод: " << endl;
//				}
//
//				string email;	
//				while (true)
//				{
//					cin.clear();
//
//					cout << "Адрес электронной почты: ";
//					cin >> email;
//
//					bool isSign = false;
//					bool isPoint = false;
//					for (int i = 0; i < email.length(); i++)
//					{
//						if (email[i] == '@' && !isSign)
//						{
//							isSign = true;
//						}
//
//						if (email[i] == '.' && i != email.length() - 1 && !isPoint && isSign)
//						{
//							isPoint = true;
//						}
//					}
//
//					if (isSign && isPoint)
//					{
//						break;
//					}
//
//					system("CLS");
//					cout << "Некорректное значение. Повторите ввод: " << endl;
//				}			
//
//				system("CLS");
//
//				User user(login, password, age, sex, phone, email);
//
//				fs << user;
//
//				cout << "Успешное добавление нового пользователя" << endl;
//
//				break;
//			}
//
//			case 0:
//				return;
//			}
//		}
//
//		fs.close();
//	}
//}
//
//void adminFileCreating()
//{
//	ofstream fout;
//
//	fout.open("Admin.txt");
//
//	if (!fout.is_open())
//	{
//		cout << "Ошибка открытия файла" << endl;
//	}
//	else
//	{
//		Admin admin("admin", encryptDecrypt("admin"));
//		fout << admin;
//	}
//
//	fout.close();
//}
//
//string encryptDecrypt(string toEncrypt)
//{
//	char key[3] = { 'K', 'C', 'Q' };
//	string output = toEncrypt;
//
//	for (int i = 0; i < toEncrypt.size(); i++)
//		output[i] = toEncrypt[i] ^ key[i % (sizeof(key) / sizeof(char))];
//
//	return output;
//}