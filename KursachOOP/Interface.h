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

	void searchDataInFile();

private:
	void enterData(T* data);	
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
			enterData(&value);
			object.addToBegin(value);
			break;

		case 2:
			enterData(&value);
			object.addToEnd(value);
			break;

		case 3:
			cout << "Введите индекс: ";
			cin >> index;

			if (index < 0 || index > object.getSize())
			{
				cout << "Неверный индекс" << endl;
				break;
			}

			enterData(&value);
			object.addByIndex(value, index);
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
			object.fileService();
			break;

		case 0:
			return;
		}

		cout << endl;
	}
}

template<>
void Interface<NewBuilding>::searchDataInFile()
{
	fstream fs;

	while (true)
	{
		fs.open("NewBuilding.txt", fstream::in);

		if (!fs.is_open())
		{
			cout << "Ошибка открытия файла" << endl;
		}
		else
		{
			cout << "Выберетие параметр:" << endl
				<< "1. Город" << endl
				<< "2. Владелец" << endl
				<< "3. Цена" << endl
				<< "4. Жилая площадь" << endl
				<< "5. Год постройки" << endl
				<< "6. Кол-во комнат" << endl
				<< "7. Этаж" << endl
				<< "8. Гарантия" << endl << endl
				<< "0. Назад" << endl;

			int choice;
			cin >> choice;

			system("CLS");

			switch (choice)
			{
			case 1:
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

				while (true)
				{
					NewBuilding object;

					fs >> object;

					if (fs.eof())
					{
						break;
					}

					if (city == object.getCity())
					{
						cout << object;
					}
				}

				break;
			}

			case 2:
			{
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

				while (true)
				{
					NewBuilding object;

					fs >> object;

					if (fs.eof())
					{
						break;
					}

					if (owner == object.getOwner())
					{
						cout << object;
					}
				}

				break;
			}

			case 3:
			{
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

				while (true)
				{
					NewBuilding object;

					fs >> object;

					if (fs.eof())
					{
						break;
					}

					if (price == object.getPrice())
					{
						cout << object;
					}
				}

				break;
			}

			case 4:
			{
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

				while (true)
				{
					NewBuilding object;

					fs >> object;

					if (fs.eof())
					{
						break;
					}

					if (livingSpace == object.getLivingSpace())
					{
						cout << object;
					}
				}

				break;
			}

			case 5:
			{
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

				while (true)
				{
					NewBuilding object;

					fs >> object;

					if (fs.eof())
					{
						break;
					}

					if (yearBuilt == object.getYearBuilt())
					{
						cout << object;
					}
				}

				break;
			}

			case 6:
			{
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

				while (true)
				{
					NewBuilding object;

					fs >> object;

					if (fs.eof())
					{
						break;
					}

					if (floor == object.getFloor())
					{
						cout << object;
					}
				}

				break;
			}

			case 7:
			{
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

				while (true)
				{
					NewBuilding object;

					fs >> object;

					if (fs.eof())
					{
						break;
					}

					if (roomsAmount == object.getRoomsAmount())
					{
						cout << object;
					}
				}

				break;
			}

			case 8:
			{
				int warranty;
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

				while (true)
				{
					NewBuilding object;

					fs >> object;

					if (fs.eof())
					{
						break;
					}

					if (warranty == object.getWarranty())
					{
						cout << object;
					}
				}

				break;
			}

			case 0:
				return;
			}
		}

		fs.close();
	}

	
}

void Interface<SecondaryHousing>::searchDataInFile()
{
	fstream fs;

	while (true)
	{
		fs.open("SecondaryHousing.txt", fstream::in);

		if (!fs.is_open())
		{
			cout << "Ошибка открытия файла" << endl;
		}
		else
		{
			cout << "Выберетие параметр:" << endl
				<< "1. Город" << endl
				<< "2. Владелец" << endl
				<< "3. Цена" << endl
				<< "4. Жилая площадь" << endl
				<< "5. Год постройки" << endl
				<< "6. Кол-во комнат" << endl
				<< "7. Этаж" << endl
				<< "8. Тип ремонта" << endl << endl
				<< "0. Назад" << endl;

			int choice;
			cin >> choice;

			system("CLS");

			switch (choice)
			{
			case 1:
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

				while (true)
				{
					SecondaryHousing object;

					fs >> object;

					if (fs.eof())
					{
						break;
					}

					if (city == object.getCity())
					{
						cout << object;
					}
				}

				break;
			}

			case 2:
			{
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

				while (true)
				{
					SecondaryHousing object;

					fs >> object;

					if (fs.eof())
					{
						break;
					}

					if (owner == object.getOwner())
					{
						cout << object;
					}
				}

				break;
			}

			case 3:
			{
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

				while (true)
				{
					SecondaryHousing object;

					fs >> object;

					if (fs.eof())
					{
						break;
					}

					if (price == object.getPrice())
					{
						cout << object;
					}
				}

				break;
			}

			case 4:
			{
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

				while (true)
				{
					SecondaryHousing object;

					fs >> object;

					if (fs.eof())
					{
						break;
					}

					if (livingSpace == object.getLivingSpace())
					{
						cout << object;
					}
				}

				break;
			}

			case 5:
			{
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

				while (true)
				{
					SecondaryHousing object;

					fs >> object;

					if (fs.eof())
					{
						break;
					}

					if (yearBuilt == object.getYearBuilt())
					{
						cout << object;
					}
				}

				break;
			}

			case 6:
			{
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

				while (true)
				{
					SecondaryHousing object;

					fs >> object;

					if (fs.eof())
					{
						break;
					}

					if (floor == object.getFloor())
					{
						cout << object;
					}
				}

				break;
			}

			case 7:
			{
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

				while (true)
				{
					SecondaryHousing object;

					fs >> object;

					if (fs.eof())
					{
						break;
					}

					if (roomsAmount == object.getRoomsAmount())
					{
						cout << object;
					}
				}

				break;
			}

			case 8:
			{
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

				while (true)
				{
					SecondaryHousing object;

					fs >> object;

					if (fs.eof())
					{
						break;
					}

					if (typeOfRepair == object.getTypeOfRepair())
					{
						cout << object;
					}
				}

				break;
			}

			case 0:
				return;
			}
		}

		fs.close();
	}


}

void Interface<Cottage>::searchDataInFile()
{
	fstream fs;

	while (true)
	{
		fs.open("Cottage.txt", fstream::in);

		if (!fs.is_open())
		{
			cout << "Ошибка открытия файла" << endl;
		}
		else
		{
			cout << "Выберетие параметр:" << endl
				<< "1. Город" << endl
				<< "2. Владелец" << endl
				<< "3. Цена" << endl
				<< "4. Жилая площадь" << endl
				<< "5. Год постройки" << endl
				<< "6. Кол-во этажей" << endl
				<< "7. Имя посёлка" << endl << endl
				<< "0. Назад" << endl;

			int choice;
			cin >> choice;

			system("CLS");

			switch (choice)
			{
			case 1:
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

				while (true)
				{
					Cottage object;

					fs >> object;

					if (fs.eof())
					{
						break;
					}

					if (city == object.getCity())
					{
						cout << object;
					}
				}

				break;
			}

			case 2:
			{
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

				while (true)
				{
					Cottage object;

					fs >> object;

					if (fs.eof())
					{
						break;
					}

					if (owner == object.getOwner())
					{
						cout << object;
					}
				}

				break;
			}

			case 3:
			{
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

				while (true)
				{
					Cottage object;

					fs >> object;

					if (fs.eof())
					{
						break;
					}

					if (price == object.getPrice())
					{
						cout << object;
					}
				}

				break;
			}

			case 4:
			{
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

				while (true)
				{
					Cottage object;

					fs >> object;

					if (fs.eof())
					{
						break;
					}

					if (livingSpace == object.getLivingSpace())
					{
						cout << object;
					}
				}

				break;
			}

			case 5:
			{
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

				while (true)
				{
					Cottage object;

					fs >> object;

					if (fs.eof())
					{
						break;
					}

					if (yearBuilt == object.getYearBuilt())
					{
						cout << object;
					}
				}

				break;
			}

			case 6:
			{
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

				while (true)
				{
					Cottage object;

					fs >> object;

					if (fs.eof())
					{
						break;
					}

					if (floorsAmount == object.getFloorsAmount())
					{
						cout << object;
					}
				}

				break;
			}

			case 7:
			{
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

				while (true)
				{
					Cottage object;

					fs >> object;

					if (fs.eof())
					{
						break;
					}

					if (nameOfVillage == object.getNameOfVillage())
					{
						cout << object;
					}
				}

				break;
			}

			case 0:
				return;
			}
		}

		fs.close();
	}
}

void Interface<Country>::searchDataInFile()
{
	fstream fs;

	while (true)
	{
		fs.open("Country.txt", fstream::in);

		if (!fs.is_open())
		{
			cout << "Ошибка открытия файла" << endl;
		}
		else
		{
			cout << "Выберетие параметр:" << endl
				<< "1. Город" << endl
				<< "2. Владелец" << endl
				<< "3. Цена" << endl
				<< "4. Жилая площадь" << endl
				<< "5. Год постройки" << endl
				<< "6. Кол-во этажей" << endl
				<< "7. Расстояние от города" << endl << endl
				<< "0. Назад" << endl;

			int choice;
			cin >> choice;

			system("CLS");

			switch (choice)
			{
			case 1:
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

				while (true)
				{
					Country object;

					fs >> object;

					if (fs.eof())
					{
						break;
					}

					if (city == object.getCity())
					{
						cout << object;
					}
				}

				break;
			}

			case 2:
			{
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

				while (true)
				{
					Country object;

					fs >> object;

					if (fs.eof())
					{
						break;
					}

					if (owner == object.getOwner())
					{
						cout << object;
					}
				}

				break;
			}

			case 3:
			{
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

				while (true)
				{
					Country object;

					fs >> object;

					if (fs.eof())
					{
						break;
					}

					if (price == object.getPrice())
					{
						cout << object;
					}
				}

				break;
			}

			case 4:
			{
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

				while (true)
				{
					Country object;

					fs >> object;

					if (fs.eof())
					{
						break;
					}

					if (livingSpace == object.getLivingSpace())
					{
						cout << object;
					}
				}

				break;
			}

			case 5:
			{
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

				while (true)
				{
					Country object;

					fs >> object;

					if (fs.eof())
					{
						break;
					}

					if (yearBuilt == object.getYearBuilt())
					{
						cout << object;
					}
				}

				break;
			}

			case 6:
			{
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

				while (true)
				{
					Country object;

					fs >> object;

					if (fs.eof())
					{
						break;
					}

					if (floorsAmount == object.getFloorsAmount())
					{
						cout << object;
					}
				}

				break;
			}

			case 7:
			{
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

				while (true)
				{
					Country object;

					fs >> object;

					if (fs.eof())
					{
						break;
					}

					if (distanceFromCity == object.getDistanceFromCity())
					{
						cout << object;
					}
				}

				break;
			}

			case 0:
				return;
			}
		}

		fs.close();
	}
}

void Interface<Ground>::searchDataInFile()
{
	fstream fs;

	while (true)
	{
		fs.open("Ground.txt", fstream::in);

		if (!fs.is_open())
		{
			cout << "Ошибка открытия файла" << endl;
		}
		else
		{
			cout << "Выберетие параметр:" << endl
				<< "1. Город" << endl
				<< "2. Владелец" << endl
				<< "3. Цена" << endl
				<< "4. Площадь земельного участка" << endl << endl
				<< "0. Назад" << endl;

			int choice;
			cin >> choice;

			system("CLS");

			switch (choice)
			{
			case 1:
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

				while (true)
				{
					Ground object;

					fs >> object;

					if (fs.eof())
					{
						break;
					}

					if (city == object.getCity())
					{
						cout << object;
					}
				}

				break;
			}

			case 2:
			{
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

				while (true)
				{
					Ground object;

					fs >> object;

					if (fs.eof())
					{
						break;
					}

					if (owner == object.getOwner())
					{
						cout << object;
					}
				}

				break;
			}

			case 3:
			{
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

				while (true)
				{
					Ground object;

					fs >> object;

					if (fs.eof())
					{
						break;
					}

					if (price == object.getPrice())
					{
						cout << object;
					}
				}

				break;
			}

			case 4:
			{
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

				while (true)
				{
					Ground object;

					fs >> object;

					if (fs.eof())
					{
						break;
					}

					if (landSquare == object.getLandSquare())
					{
						cout << object;
					}
				}

				break;
			}

			case 0:
				return;
			}
		}

		fs.close();
	}
}

template<class T>
void Interface<T>::enterData(T* object)
{
	(*object).enterData();
}