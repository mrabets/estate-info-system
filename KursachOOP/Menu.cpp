#include "Menu.h"

void Menu::pointOfEntry()
{
	ifstream fin;

	fin.open("Admin.txt");

	if (!fin.is_open())
	{
		adminFileCreating();
	}

	fin.close();

	fin.open("User.txt");

	if (!fin.is_open())
	{
		userFileCreating();
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
			userRegistration();
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

void Menu::typeChoosing()
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
			object.service();
		}
		break;

		case 2:
		{
			Interface<SecondaryHousing> object;
			object.service();
		}
		break;

		case 3:
		{
			Interface<Cottage> object;
			object.service();
		}
		break;

		case 4:
		{
			Interface<Country> object;
			object.service();
		}
		break;

		case 5:
		{
			Interface<Ground> object;
			object.service();
		}
		break;

		case 0:
			return;
		}
	}
}

void Menu::userMenu()
{
	while (true)
	{
		cout << "Выберите опцию: " << endl
			<< "1. Просмотреть недвижимость" << endl
			<< "2. Искать недвижимость по параметрам" << endl
			<< "3. Купить недвижимость" << endl << endl
			<< "0. Назад" << endl;

		int choice;
		cin >> choice;

		system("CLS");

		switch (choice)
		{
		case 1:
			viewEstate();
			break;

		case 2:
			searchEstate();
			break;

		case 3:
		{
			viewEstate();

			break;
		}

		case 0:
			return;
		}
	}
}

bool Menu::isUserAuthorization()
{
	cout << "Логин: ";

	string login;
	cin >> login;

	cout << "Пароль: ";

	string password;
	cin >> password;

	system("CLS");

	ifstream fin;

	fin.open("User.txt");

	if (!fin.is_open())
	{
		cout << "Ошибка открытия файла" << endl;
	}
	else
	{
		while (true)
		{
			User obj;
			fin >> obj;

			if (fin.eof())
			{
				break;
			}

			if (login == obj.getLogin() && password == encryptDecrypt(obj.getPassword()))
			{
				fin.close();
				return true;
			}
		}
	}

	fin.close();
	return false;
}

void Menu::userRegistration()
{
	
	fstream fs;

	while (true)
	{
		fs.open("User.txt", fstream::in | fstream::out | fstream::app);

		if (!fs.is_open())
		{
			cout << "Ошибка открытия файла" << endl;
		}
		else
		{
			cout << "Выберите опцию: " << endl
				<< "1. Авторизация" << endl
				<< "2. Регистрация" << endl;

			int userChoice;
			cin >> userChoice;

			system("CLS");

			switch (userChoice)
			{
			case 1:
				if (isUserAuthorization())
				{
					cout << "Вы вошли в систему" << endl;
					userMenu();
				}
				else
				{
					cout << "Неверный логин или пароль" << endl;
				}

				break;

			case 2:
			{
				string login;
				while (true)
				{
					cin.clear();

					cout << "Логин: ";

					cin >> login;

					if (login.length() >= 5 && login.length() <= 12)
					{
						break;
					}

					system("CLS");
					cout << "Некорректное значение. Повторите ввод: " << endl;
				}

				string password;
				while (true)
				{
					cin.clear();

					cout << "Пароль: ";

					cin >> password;

					if (password.length() >= 5 && password.length() <= 12)
					{
						password = encryptDecrypt(password);
						break;
					}

					system("CLS");
					cout << "Некорректное значение. Повторите ввод: " << endl;
				}

				int age;
				while (true)
				{
					cin.clear();

					cout << "Возраст: ";

					cin >> age;

					if (age >= 18 && age <= 120)
					{
						break;
					}

					system("CLS");
					cout << "Некорректное значение. Повторите ввод: " << endl;
				}

				char sex;
				while (true)
				{
					cin.clear();

					cout << "Пол (М - мужской, Ж - женский): ";

					cin >> sex;

					if (sex == 'М' || sex == 'Ж' || sex == 'м' || sex == 'ж')
					{
						break;
					}

					system("CLS");
					cout << "Некорректное значение. Повторите ввод: " << endl;
				}

				string phone;
				while (true)
				{
					cin.clear();

					cout << "Номер мобильного телефона (напр. +375257712277): ";

					cin >> phone;

					if (phone.length() != 13 || phone[0] != '+')
					{
						system("CLS");
						cout << "Некорректное значение. Повторите ввод: " << endl;
					}

					bool isAllDigit = true;
					for (int i = 1; i < phone.length(); i++)
					{
						if (phone[i] < '0' || phone[i] > '9')
						{
							isAllDigit = false;
							break;
						}
					}

					if (isAllDigit)
					{
						break;
					}

					system("CLS");
					cout << "Некорректное значение. Повторите ввод: " << endl;
				}

				string email;
				while (true)
				{
					cin.clear();

					cout << "Адрес электронной почты: ";
					cin >> email;

					bool isSign = false;
					bool isPoint = false;
					for (int i = 0; i < email.length(); i++)
					{
						if (email[i] == '@' && !isSign)
						{
							isSign = true;
						}

						if (email[i] == '.' && i != email.length() - 1 && !isPoint && isSign)
						{
							isPoint = true;
						}
					}

					if (isSign && isPoint)
					{
						break;
					}

					system("CLS");
					cout << "Некорректное значение. Повторите ввод: " << endl;
				}

				system("CLS");

				User user(login, password, age, sex, phone, email);

				fs << user;

				cout << "Успешная регистрация" << endl;

				break;
			}

			case 0:
				return;
			}
		}

		fs.close();
	}
}

void Menu::userFileCreating()
{
	ofstream fout;

	fout.open("User.txt");

	if (!fout.is_open())
	{
		cout << "Ошибка открытия файла" << endl;
	}

	fout.close();
}

void Menu::viewEstate()
{
	while (true)
	{
		string fileName;

		cout << "Просмотреть: " << endl << endl
			<< "1. Новостройки" << endl
			<< "2. Вторички" << endl
			<< "3. Коттеджи" << endl
			<< "4. Дачи" << endl
			<< "5. Участки" << endl << endl
			<< "0. Назад" << endl;

		int choice;
		cin >> choice;

		system("CLS");

		switch (choice)
		{
		case 1:
			cout << setw(20) << "ГОРОД" << setw(20) << "ВЛАДЕЛЕЦ" << setw(10) << "ЦЕНА" << setw(18) << "ЖИЛ. ПЛОЩАДЬ" << setw(18) << "ГОД ПОСТРОЙКИ"
				<< setw(10) << "ЭТАЖ" << setw(20) << "КОЛ-ВО КОМНАТ" << setw(12) << "ГАРАНТИЯ" << endl;

			fileName = "NewBuilding.txt";
			break;

		case 2:
			cout << setw(20) << "ГОРОД" << setw(20) << "ВЛАДЕЛЕЦ" << setw(10) << "ЦЕНА" << setw(18) << "ЖИЛ. ПЛОЩАДЬ" << setw(18) << "ГОД ПОСТРОЙКИ"
				<< setw(10) << "ЭТАЖ" << setw(20) << "КОЛ-ВО КОМНАТ" << setw(18) << "ТИП РЕМОНТА" << endl;

			fileName = "SecondaryHousing.txt";
			break;

		case 3:
			cout << setw(20) << "ГОРОД" << setw(20) << "ВЛАДЕЛЕЦ" << setw(10) << "ЦЕНА" << setw(18) << "ЖИЛ. ПЛОЩАДЬ" << setw(18) << "ГОД ПОСТРОЙКИ"
				<< setw(20) << "КОЛ-ВО ЭТАЖЕЙ" << setw(15) << "ПОСЁЛОК" << endl;

			fileName = "Cottage.txt";
			break;

		case 4:
			cout << setw(20) << "ГОРОД" << setw(20) << "ВЛАДЕЛЕЦ" << setw(10) << "ЦЕНА" << setw(18) << "ЖИЛ. ПЛОЩАДЬ" << setw(18) << "ГОД ПОСТРОЙКИ"
				<< setw(20) << "КОЛ-ВО ЭТАЖЕЙ" << setw(25) << "РАССТОЯНИЕ ОТ ГОРОДА" << endl;

			fileName = "Country.txt";
			break;

		case 5:
			cout << setw(20) << "ГОРОД" << setw(20) << "ВЛАДЕЛЕЦ" << setw(10) << "ЦЕНА" << setw(20) << "ПЛОЩАДЬ УЧАСТКА" << endl;

			fileName = "Ground.txt";
			break;

		case 0:
			return;
		}

		fstream fs;

		fs.open(fileName, fstream::in);

		if (!fs.is_open())
		{
			cout << "Данный тип недвижимости отсутсвует в каталоге" << endl;
		}
		else
		{
			char ch;
			while (fs.get(ch))
			{
				cout << ch;
			}
		}
		fs.close();
	}
}

void Menu::searchEstate()
{
	while (true)
	{
		string fileName;

		cout << "Искать в разделе: " << endl << endl
			<< "1. Всю недвижимость" << endl
			<< "2. Новостройки" << endl
			<< "3. Вторички" << endl
			<< "4. Коттеджи" << endl
			<< "5. Дачи" << endl
			<< "6. Участки" << endl << endl
			<< "0. Назад" << endl;

		int choice;
		cin >> choice;

		system("CLS");

		switch (choice)
		{
		case 2:
		{
			Interface<NewBuilding> object;
			object.searchData();
		}
		break;

		case 3:
			cout << setw(20) << "ГОРОД" << setw(20) << "ВЛАДЕЛЕЦ" << setw(10) << "ЦЕНА" << setw(18) << "ЖИЛ. ПЛОЩАДЬ" << setw(18) << "ГОД ПОСТРОЙКИ"
				<< setw(10) << "ЭТАЖ" << setw(20) << "КОЛ-ВО КОМНАТ" << setw(18) << "ТИП РЕМОНТА" << endl;

			fileName = "SecondaryHousing.txt";
			break;

		case 4:
			cout << setw(20) << "ГОРОД" << setw(20) << "ВЛАДЕЛЕЦ" << setw(10) << "ЦЕНА" << setw(18) << "ЖИЛ. ПЛОЩАДЬ" << setw(18) << "ГОД ПОСТРОЙКИ"
				<< setw(20) << "КОЛ-ВО ЭТАЖЕЙ" << setw(15) << "ПОСЁЛОК" << endl;

			fileName = "Cottage.txt";
			break;

		case 5:
			cout << setw(20) << "ГОРОД" << setw(20) << "ВЛАДЕЛЕЦ" << setw(10) << "ЦЕНА" << setw(18) << "ЖИЛ. ПЛОЩАДЬ" << setw(18) << "ГОД ПОСТРОЙКИ"
				<< setw(20) << "КОЛ-ВО ЭТАЖЕЙ" << setw(25) << "РАССТОЯНИЕ ОТ ГОРОДА" << endl;

			fileName = "Country.txt";
			break;

		case 6:
			cout << setw(20) << "ГОРОД" << setw(20) << "ВЛАДЕЛЕЦ" << setw(10) << "ЦЕНА" << setw(20) << "ПЛОЩАДЬ УЧАСТКА" << endl;

			fileName = "Ground.txt";
			break;

		case 0:
			return;
		}

		fstream fs;

		fs.open(fileName, fstream::in);

		if (fs.is_open())
		{
			cout << "Данный тип недвижимости отсутсвует в каталоге" << endl;
		}
		else
		{

		}
		fs.close();
	}
}

void Menu::adminMenu()
{
	while (true)
	{
		cout << "Выберите опцию: " << endl << endl
			<< "1. Работа с объектами" << endl
			<< "2. Работа с учетными записями администраторов" << endl
			<< "3. Работа с учетными записями пользователей" << endl << endl
			<< "0. Назад" << endl;

		int choice;
		cin >> choice;

		system("CLS");

		switch (choice)
		{
		case 1:
			typeChoosing();
			break;

		case 2:
			adminRegistration();
			break;

		case 3:
			userManage();
			break;

		case 0:
			return;
		}
	}
}

bool Menu::isAdminAuthorization()

{
	cout << "Логин: ";

	string login;
	cin >> login;

	cout << "Пароль: ";

	string password;
	cin >> password;

	system("CLS");

	ifstream fin;

	fin.open("Admin.txt");

	if (!fin.is_open())
	{
		cout << "Ошибка открытия файла" << endl;
	}
	else
	{
		while (true)
		{
			Admin obj;
			fin >> obj;

			if (fin.eof())
			{
				break;
			}

			if (login == obj.getLogin() && password == encryptDecrypt(obj.getPassword()))
			{
				fin.close();
				return true;
			}
		}
	}

	fin.close();
	return false;
}

void Menu::adminRegistration()
{
	fstream fs;
	while (true)
	{
		fs.open("Admin.txt", fstream::in | fstream::out | fstream::app);

		if (!fs.is_open())
		{
			cout << "Ошибка открытия файла" << endl;
		}
		else
		{
			cout << "Выберите опцию: " << endl << endl
				<< "1. Зарегистрировать нового администратора" << endl
				<< "2. Посмотреть список всех администраторов" << endl << endl
				<< "0. Назад" << endl;

			int choice;
			cin >> choice;

			system("CLS");

			switch (choice)
			{
			case 1:
			{
				string login;
				while (true)
				{
					cin.clear();

					cout << "Логин: ";

					cin >> login;

					if (login.length() >= 5 && login.length() <= 12)
					{
						break;
					}

					system("CLS");
					cout << "Некорректное значение. Повторите ввод: " << endl;
				}

				string password;
				while (true)
				{
					cin.clear();

					cout << "Пароль: ";

					cin >> password;

					if (password.length() >= 5 && password.length() <= 12)
					{
						password = encryptDecrypt(password);
						break;
					}

					system("CLS");
					cout << "Некорректное значение. Повторите ввод: " << endl;
				}

				system("CLS");

				Admin admin(login, password);

				fs << admin;

				cout << "Успешное добавление нового администратора" << endl;

				break;
			}

			case 2:
			{
				cout << setw(12) << "ЛОГИН" << setw(12) << "ПАРОЛЬ" << endl;

				while (true)
				{
					Admin obj;
					fs >> obj;

					if (fs.eof())
					{
						break;
					}

					cout << obj;
				}

				break;
			}

			case 0:
				return;
			}

			fs.close();
		}

	}
}

void Menu::userManage()
{
	fstream fs;
	while (true)
	{
		fs.open("User.txt", fstream::in | fstream::out | fstream::app);

		if (!fs.is_open())
		{
			cout << "Ошибка открытия файла" << endl;
		}
		else
		{
			cout << "Выберите опцию: " << endl << endl
				<< "1. Просмотреть данные всех пользователей" << endl
				<< "2. Просмотреть данные определенного пользователя" << endl
				<< "3. Добавить нового пользователя" << endl << endl
				<< "0. Назад" << endl;

			int choice;
			cin >> choice;

			system("CLS");

			switch (choice)
			{
			case 1:
			{
				cout << setw(12) << "ЛОГИН" << setw(12) << "ПАРОЛЬ" << setw(10) << "ВОЗРАСТ" << setw(5) << "ПОЛ" << setw(18) << "МОБ.НОМЕР" << setw(22) << "ЕМЕЙЛ" << endl;

				while (true)
				{
					User obj;
					fs >> obj;

					if (fs.eof())
					{
						break;
					}

					cout << obj;
				}

				break;
			}

			case 2:
			{
				cout << setw(12) << "ЛОГИН" << setw(12) << "ПАРОЛЬ" << setw(10) << "ВОЗРАСТ" << setw(5) << "ПОЛ" << setw(18) << "МОБ.НОМЕР" << setw(22) << "ЕМЕЙЛ" << endl;

				string login;
				while (true)
				{
					cin.clear();

					cout << "Логин пользователя: ";

					cin >> login;

					if (login.length() >= 5 && login.length() <= 12)
					{
						break;
					}

					system("CLS");
					cout << "Некорректное значение. Повторите ввод: " << endl;
				}

				while (true)
				{
					User obj;
					fs >> obj;

					if (fs.eof())
					{
						break;
					}

					if (obj.getLogin() == login)
					{
						cout << obj;
						break;
					}

				}

				break;
			}

			case 3:
			{
				string login;
				while (true)
				{
					cin.clear();

					cout << "Логин: ";

					cin >> login;

					if (login.length() >= 5 && login.length() <= 12)
					{
						break;
					}

					system("CLS");
					cout << "Некорректное значение. Повторите ввод: " << endl;
				}

				string password;
				while (true)
				{
					cin.clear();

					cout << "Пароль: ";

					cin >> password;

					if (password.length() >= 5 && password.length() <= 12)
					{
						password = encryptDecrypt(password);
						break;
					}

					system("CLS");
					cout << "Некорректное значение. Повторите ввод: " << endl;
				}

				int age;
				while (true)
				{
					cin.clear();

					cout << "Возраст: ";

					cin >> age;

					if (age >= 18 && age <= 120)
					{
						break;
					}

					system("CLS");
					cout << "Некорректное значение. Повторите ввод: " << endl;
				}

				char sex;
				while (true)
				{
					cin.clear();

					cout << "Пол (М - мужской, Ж - женский): ";

					cin >> sex;

					if (sex == 'М' || sex == 'Ж' || sex == 'м' || sex == 'ж')
					{
						break;
					}

					system("CLS");
					cout << "Некорректное значение. Повторите ввод: " << endl;
				}

				string phone;
				while (true)
				{
					cin.clear();

					cout << "Номер мобильного телефона (напр. +375257712277): ";

					cin >> phone;

					if (phone.length() != 13 || phone[0] != '+')
					{
						system("CLS");
						cout << "Некорректное значение. Повторите ввод: " << endl;
					}

					bool isAllDigit = true;
					for (int i = 1; i < phone.length(); i++)
					{
						if (phone[i] < '0' || phone[i] > '9')
						{
							isAllDigit = false;
							break;
						}
					}

					if (isAllDigit)
					{
						break;
					}

					system("CLS");
					cout << "Некорректное значение. Повторите ввод: " << endl;
				}

				string email;
				while (true)
				{
					cin.clear();

					cout << "Адрес электронной почты: ";
					cin >> email;

					bool isSign = false;
					bool isPoint = false;
					for (int i = 0; i < email.length(); i++)
					{
						if (email[i] == '@' && !isSign)
						{
							isSign = true;
						}

						if (email[i] == '.' && i != email.length() - 1 && !isPoint && isSign)
						{
							isPoint = true;
						}
					}

					if (isSign && isPoint)
					{
						break;
					}

					system("CLS");
					cout << "Некорректное значение. Повторите ввод: " << endl;
				}

				system("CLS");

				User user(login, password, age, sex, phone, email);

				fs << user;

				cout << "Успешное добавление нового пользователя" << endl;

				break;
			}

			case 0:
				return;
			}
		}

		fs.close();
	}
}

void Menu::adminFileCreating()
{
	ofstream fout;

	fout.open("Admin.txt");

	if (!fout.is_open())
	{
		cout << "Ошибка открытия файла" << endl;
	}
	else
	{
		Admin admin("admin", encryptDecrypt("admin"));
		fout << admin;
	}

	fout.close();
}

string Menu::encryptDecrypt(string toEncrypt)
{
	char key[3] = { 'K', 'C', 'Q' };
	string output = toEncrypt;

	for (int i = 0; i < toEncrypt.size(); i++)
		output[i] = toEncrypt[i] ^ key[i % (sizeof(key) / sizeof(char))];

	return output;
}
