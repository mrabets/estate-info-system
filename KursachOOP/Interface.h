#pragma once

#include "NewBuilding.h"
#include "SecondaryHousing.h"
#include "Cottage.h"
#include "Country.h"
#include "Ground.h"
#include "Ring.h"

template<class T>
class Interface
{
public:
	Interface() {};
	~Interface() {};

	void serviceMenu();
};

template <class T>
void Interface<T>::serviceMenu()
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
			<< "0. Назад" << endl;

		int choiceMenu;
		cin >> choiceMenu;

		system("CLS");

		T value;
		int index;

		switch (choiceMenu)
		{
		case 1:
			cin >> value;
			object.addToBegin(value);

			break;

		case 2:
			cin >> value;
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

			cin >> value;

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

		case 0:
			return;
		}

		cout << endl;
	}
}

void typeChoosing()
{
	while (true)
	{
		int choiceDevice;

		cout << "Выберите объект недвижимости: " << endl << endl
			<< "1. Новостройка" << endl
			<< "2. Вторичка" << endl << endl
			<< "3. Коттедж" << endl
			<< "4. Дача" << endl << endl
			<< "5. Участок" << endl << endl
			<< "0. Выйти в главное меню" << endl;

		cin >> choiceDevice;

		system("CLS");

		switch (choiceDevice)
		{
		case 1:
		{
			Interface<NewBuilding> object;
			object.serviceMenu();
		}
		break;

		case 2:
		{
			Interface<SecondaryHousing> object;
			object.serviceMenu();
		}
		break;

		case 3:
		{
			Interface<Cottage> object;
			object.serviceMenu();
		}
		break;

		case 4:
		{
			Interface<Country> object;
			object.serviceMenu();
		}
		break;

		case 5:
		{
			Interface<Ground> object;
			object.serviceMenu();
		}
		break;

		case 0:
			return;
		}
	}
}