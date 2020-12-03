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

		case 10:
			object.saveDataToFile();
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

void pointOfEntry()
{
	ifstream fin;

	fin.open("admin.txt");

	if (!fin.is_open())
	{
		adminFileCreating();
	}

	fin.close();

	while (true)
	{
		cout << "Выберите тип входа: " << endl
			<< "1. Пользователь" << endl
			<< "2. Администратор" << endl;

		int choice;
		cin >> choice;

		system("CLS");

		switch (choice)
		{
		case 1:
			break;
		case 2:
			if (isAdminAuthorization())
			{
				cout << "Вы вошли в систему" << endl;
				adminMenu();
			}
			else
			{
				cout << "Неверный логин или пароль" << endl;
			}
			break;

		case 0:
			return;
		}
	}
}

void adminFileCreating()
{
	ofstream fout;

	fout.open("admin.txt");

	if (!fout.is_open())
	{
		cout << "Ошибка открытия файла" << endl;
	}
	else
	{
		string firstLoginAndPassword = "admin";

		fout << firstLoginAndPassword << " " << firstLoginAndPassword << "\n";
	}

	fout.close();
}
void adminRegistration()
{
	fstream fs;
	while (true)
	{
		fs.open("admin.txt", fstream::in | fstream::out | fstream::app);

		if (!fs.is_open())
		{
			cout << "Ошибка открытия файла" << endl;
		}
		else
		{
			cout << "Выберите опцию: " << endl
				<< "1. Зарегистрировать нового администратора" << endl
				<< "2. Посмотреть список текущий администраторов" << endl;

			int choice;
			cin >> choice;

			system("CLS");

			switch (choice)
			{
			case 1:
			{
				string login;
				string password;

				cout << "Введите логин: ";
				cin >> login;

				cout << "Введите пароль: ";
				cin >> password;

				fs << login << " " << password << "\n";
			}
			break;

			case 2:
			{
				string view;
				cout << setw(10) << "Логин" << setw(10) << "Пароль" << endl;

				while (!fs.eof())
				{
					view = "";

					fs >> view;
					cout << setw(10) << view;

					view = "";

					fs >> view;
					cout << setw(10) << view;

					cout << endl;
				}

				cout << endl << endl;
			}
			break;

			case 0:
				return;
			}

			fs.close();
		}

	}


}

bool isAdminAuthorization()
{
	string login;
	string password;

	cout << "Логин: ";
	cin >> login;

	cout << "Пароль: ";
	cin >> password;

	system("CLS");

	ifstream fin;

	fin.open("admin.txt");

	if (!fin.is_open())
	{
		cout << "Ошибка открытия файла" << endl;
	}
	else
	{
		string temp;
		while (!fin.eof())
		{
			temp = "";
			fin >> temp;

			if (temp == login)
			{
				fin >> temp;
				if (temp == password)
				{
					fin.close();
					return true;
				}
			}
			else
			{
				fin >> temp;
			}
		}
	}

	fin.close();
	return false;
}

void adminMenu()
{
	while (true)
	{
		cout << "Выберите опцию: " << endl
			<< "1. Че-то добавить" << endl
			<< "2. Работа с учетными записями" << endl;

		int choice;
		cin >> choice;

		system("CLS");

		switch (choice)
		{
		case 1:
			break;
		case 2:
			adminRegistration();

		case 0:
			return;
		}
	}
}