#pragma once

#include "NewBuilding.h"
#include "SecondaryHousing.h"
#include "Cottage.h"
#include "Country.h"
#include "Ground.h"
#include "Ring.h"

void pointOfEntry();

void userMenu();
bool isUserAuthorization();
void userRegistration();
void userFileCreating();

void adminMenu();
bool isAdminAuthorization();
void adminRegistration();
void adminFileCreating();

template<class T>
class Interface
{
public:
	Interface() {};
	~Interface() {};

	void serviceMenuAdmin();
};

template <class T>
void Interface<T>::serviceMenuAdmin()
{
	Ring<T> object;

	while (true)
	{
		cout << "Âûáåðèòå îïåðàöèþ:" << endl << endl
			<< "1. Äîáàâèòü äàííûå â íà÷àëî òàáëèöû" << endl
			<< "2. Äîáàâèòü äàííûå â êîíåö òàáëèöû" << endl
			<< "3. Äîáàâèòü äàííûå â òàáëèöó ïî èíäåêñó" << endl << endl
			<< "4. Óäàëèòü äàííûå â íà÷àëå òàáëèöû" << endl
			<< "5. Óäàëèòü äàííûå â êîíöå òàáëèöû" << endl
			<< "6. Óäàëèòü äàííûå â òàáëèöå ïî èíäåêñó" << endl
			<< "7. Óäàëèòü âñå äàííûå" << endl << endl
			<< "8. Ðåäàêòèðîâàòü äàííûå" << endl << endl
			<< "9. Âûâåñòè äàííûå íà ýêðàí" << endl << endl
			<< "10. Ðàáîòà ñ áàçîé äàííûõ" << endl << endl
			<< "0. Íàçàä" << endl;

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
			cout << "Ââåäèòå èíäåêñ: ";
			cin >> index;

			if (index < 0 || index > object.getSize())
			{
				cout << "Íåâåðíûé èíäåêñ" << endl;
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
			cout << "Ââåäèòå èíäåêñ: ";
			cin >> index;

			if (index < 0 || index > object.getSize())
			{
				cout << "Íåâåðíûé èíäåêñ" << endl;
				break;
			}

			object.deleteByIndex(index);

			break;

		case 7:
			object.clear();
			break;

		case 8:
			cout << "Ââåäèòå èíäåêñ: ";
			cin >> index;

			if (index < 0 || index > object.getSize())
			{
				cout << "Íåâåðíûé èíäåêñ" << endl;
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

void typeChoosingAdmin()
{
	while (true)
	{
		int choiceDevice;

		cout << "Âûáåðèòå îáúåêò íåäâèæèìîñòè: " << endl << endl
			<< "1. Íîâîñòðîéêà" << endl
			<< "2. Âòîðè÷êà" << endl << endl
			<< "3. Êîòòåäæ" << endl
			<< "4. Äà÷à" << endl << endl
			<< "5. Ó÷àñòîê" << endl << endl
			<< "0. Âûéòè â ãëàâíîå ìåíþ" << endl;

		cin >> choiceDevice;

		system("CLS");

		switch (choiceDevice)
		{
		case 1:
		{
			Interface<NewBuilding> object;
			object.serviceMenuAdmin();
		}
		break;

		case 2:
		{
			Interface<SecondaryHousing> object;
			object.serviceMenuAdmin();
		}
		break;

		case 3:
		{
			Interface<Cottage> object;
			object.serviceMenuAdmin();
		}
		break;

		case 4:
		{
			Interface<Country> object;
			object.serviceMenuAdmin();
		}
		break;

		case 5:
		{
			Interface<Ground> object;
			object.serviceMenuAdmin();
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

	fin.open("user.txt");

	if (!fin.is_open())
	{
		userFileCreating();
	}

	fin.close();

	while (true)
	{
		cout << "Âûáåðèòå òèï âõîäà: " << endl
			<< "1. Ïîëüçîâàòåëü" << endl
			<< "2. Àäìèíèñòðàòîð" << endl;

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
				cout << "Âû âîøëè â ñèñòåìó" << endl;
				adminMenu();
			}
			else
			{
				cout << "Íåâåðíûé ëîãèí èëè ïàðîëü" << endl;
			}
			break;

		case 0:
			return;
		}
	}
}


void viewEstate()
{
	while (true)
	{
		string fileName;

		cout << "Ïðîñìîòðåòü: " << endl << endl
			<< "1.Âñþ íåäâèæèìîñòü" << endl
			<< "2. Íîâîñòðîéêè" << endl
			<< "3. Âòîðè÷êè" << endl
			<< "4. Êîòòåäæè" << endl
			<< "5. Äà÷è" << endl
			<< "6. Ó÷àñòêè" << endl << endl
			<< "0. Íàçàä" << endl;

		int choice;
		cin >> choice;

		system("CLS");

		switch (choice)
		{
		case 1:
			break;

		case 2:
			cout << setw(20) << "ÃÎÐÎÄ" << setw(20) << "ÂËÀÄÅËÅÖ" << setw(10) << "ÖÅÍÀ" << setw(18) << "ÆÈË. ÏËÎÙÀÄÜ" << setw(18) << "ÃÎÄ ÏÎÑÒÐÎÉÊÈ"
				<< setw(10) << "ÝÒÀÆ" << setw(20) << "ÊÎË-ÂÎ ÊÎÌÍÀÒ" << setw(12) << "ÃÀÐÀÍÒÈß" << endl;

			fileName = "NewBuilding.txt";
			break;

		case 3:
			cout << setw(20) << "ÃÎÐÎÄ" << setw(20) << "ÂËÀÄÅËÅÖ" << setw(10) << "ÖÅÍÀ" << setw(18) << "ÆÈË. ÏËÎÙÀÄÜ" << setw(18) << "ÃÎÄ ÏÎÑÒÐÎÉÊÈ"
				<< setw(10) << "ÝÒÀÆ" << setw(20) << "ÊÎË-ÂÎ ÊÎÌÍÀÒ" << setw(18) << "ÒÈÏ ÐÅÌÎÍÒÀ" << endl;

			fileName = "SecondaryHousing.txt";
			break;

		case 4:
			cout << setw(20) << "ÃÎÐÎÄ" << setw(20) << "ÂËÀÄÅËÅÖ" << setw(10) << "ÖÅÍÀ" << setw(18) << "ÆÈË. ÏËÎÙÀÄÜ" << setw(18) << "ÃÎÄ ÏÎÑÒÐÎÉÊÈ"
				<< setw(20) << "ÊÎË-ÂÎ ÝÒÀÆÅÉ" << setw(15) << "ÏÎÑ¨ËÎÊ" << endl;

			fileName = "Cottage.txt";
			break;

		case 5:
			cout << setw(20) << "ÃÎÐÎÄ" << setw(20) << "ÂËÀÄÅËÅÖ" << setw(10) << "ÖÅÍÀ" << setw(18) << "ÆÈË. ÏËÎÙÀÄÜ" << setw(18) << "ÃÎÄ ÏÎÑÒÐÎÉÊÈ"
				<< setw(20) << "ÊÎË-ÂÎ ÝÒÀÆÅÉ" << setw(25) << "ÐÀÑÑÒÎßÍÈÅ ÎÒ ÃÎÐÎÄÀ" << endl;

			fileName = "Country.txt";
			break;

		case 6:
			cout << setw(20) << "ÃÎÐÎÄ" << setw(20) << "ÂËÀÄÅËÅÖ" << setw(10) << "ÖÅÍÀ" << setw(20) << "ÏËÎÙÀÄÜ Ó×ÀÑÒÊÀ" << endl;

			fileName = "Ground.txt";
			break;

		case 0:
			return;
		}

		fstream fs;

		fs.open(fileName, fstream::in);

		if (!fs.is_open())
		{
			cout << "Äàííûé òèï íåäâèæèìîñòè îòñóòñâóåò â êàòàëîãå" << endl;
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

void searchEstate()
{
	while (true)
	{
		string fileName;

		cout << "Èñêàòü â ðàçäåëå: " << endl << endl
			<< "1. Âñþ íåäâèæèìîñòü" << endl
			<< "2. Íîâîñòðîéêè" << endl
			<< "3. Âòîðè÷êè" << endl
			<< "4. Êîòòåäæè" << endl
			<< "5. Äà÷è" << endl
			<< "6. Ó÷àñòêè" << endl << endl
			<< "0. Íàçàä" << endl;

		int choice;
		cin >> choice;

		system("CLS");

		switch (choice)
		{
		case 1:
			break;

		case 2:
			cout << setw(20) << "ÃÎÐÎÄ" << setw(20) << "ÂËÀÄÅËÅÖ" << setw(10) << "ÖÅÍÀ" << setw(18) << "ÆÈË. ÏËÎÙÀÄÜ" << setw(18) << "ÃÎÄ ÏÎÑÒÐÎÉÊÈ"
				<< setw(10) << "ÝÒÀÆ" << setw(20) << "ÊÎË-ÂÎ ÊÎÌÍÀÒ" << setw(12) << "ÃÀÐÀÍÒÈß" << endl;

			fileName = "NewBuilding.txt";
			break;

		case 3:
			cout << setw(20) << "ÃÎÐÎÄ" << setw(20) << "ÂËÀÄÅËÅÖ" << setw(10) << "ÖÅÍÀ" << setw(18) << "ÆÈË. ÏËÎÙÀÄÜ" << setw(18) << "ÃÎÄ ÏÎÑÒÐÎÉÊÈ"
				<< setw(10) << "ÝÒÀÆ" << setw(20) << "ÊÎË-ÂÎ ÊÎÌÍÀÒ" << setw(18) << "ÒÈÏ ÐÅÌÎÍÒÀ" << endl;

			fileName = "SecondaryHousing.txt";
			break;

		case 4:
			cout << setw(20) << "ÃÎÐÎÄ" << setw(20) << "ÂËÀÄÅËÅÖ" << setw(10) << "ÖÅÍÀ" << setw(18) << "ÆÈË. ÏËÎÙÀÄÜ" << setw(18) << "ÃÎÄ ÏÎÑÒÐÎÉÊÈ"
				<< setw(20) << "ÊÎË-ÂÎ ÝÒÀÆÅÉ" << setw(15) << "ÏÎÑ¨ËÎÊ" << endl;

			fileName = "Cottage.txt";
			break;

		case 5:
			cout << setw(20) << "ÃÎÐÎÄ" << setw(20) << "ÂËÀÄÅËÅÖ" << setw(10) << "ÖÅÍÀ" << setw(18) << "ÆÈË. ÏËÎÙÀÄÜ" << setw(18) << "ÃÎÄ ÏÎÑÒÐÎÉÊÈ"
				<< setw(20) << "ÊÎË-ÂÎ ÝÒÀÆÅÉ" << setw(25) << "ÐÀÑÑÒÎßÍÈÅ ÎÒ ÃÎÐÎÄÀ" << endl;

			fileName = "Country.txt";
			break;

		case 6:
			cout << setw(20) << "ÃÎÐÎÄ" << setw(20) << "ÂËÀÄÅËÅÖ" << setw(10) << "ÖÅÍÀ" << setw(20) << "ÏËÎÙÀÄÜ Ó×ÀÑÒÊÀ" << endl;

			fileName = "Ground.txt";
			break;

		case 0:
			return;
		}

		fstream fs;

		fs.open(fileName, fstream::in);

		if (fs.is_open())
		{
			cout << "Äàííûé òèï íåäâèæèìîñòè îòñóòñâóåò â êàòàëîãå" << endl;
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

void userMenu()
{
	while (true)
	{
		cout << "Âûáåðèòå îïöèþ: " << endl
			<< "1. Ïðîñìîòðåòü íåäâèæèìîñòü" << endl
			<< "2. Èñêàòü íåäâèæèìîñòü ïî ïàðàìåòðàì" << endl
			<< "3. Êóïèòü íåäâèæèìîñòü" << endl << endl
			<< "0. Íàçàä" << endl;

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

			break;

		case 0:
			return;
		}
	}
}

bool isUserAuthorization()
{
	string login;
	string password;

	cout << "Ëîãèí: ";
	cin >> login;

	cout << "Ïàðîëü: ";
	cin >> password;

	system("CLS");

	ifstream fin;

	fin.open("user.txt");

	if (!fin.is_open())
	{
		cout << "Îøèáêà îòêðûòèÿ ôàéëà" << endl;
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

void userRegistration()
{
	fstream fs;

	while (true)
	{
		fs.open("user.txt", fstream::in | fstream::out | fstream::app);

		if (!fs.is_open())
		{
			cout << "Îøèáêà îòêðûòèÿ ôàéëà" << endl;
		}
		else
		{
			cout << "Âûáåðèòå îïöèþ: " << endl
				<< "1. Àâòîðèçàöèÿ" << endl
				<< "2. Ðåãèñòðàöèÿ" << endl;

			int userChoice;
			cin >> userChoice;

			system("CLS");

			switch (userChoice)
			{
			case 1:
				if (isUserAuthorization())
				{
					cout << "Âû âîøëè â ñèñòåìó" << endl;
					userMenu();
				}
				else
				{
					cout << "Íåâåðíûé ëîãèí èëè ïàðîëü" << endl;
				}

				break;

			case 2:
			{
				string login;
				string password;

				cout << "Ââåäèòå ëîãèí: ";
				cin >> login;

				cout << "Ââåäèòå ïàðîëü: ";
				cin >> password;

				fs << login << " " << password << "\n";

				cout << "Óñïåøíàÿ ðåãèñòðàöèÿ" << endl;

				break;
			}

			case 0:
				return;
			}
		}

		fs.close();
	}
}

void userFileCreating()
{
	ofstream fout;

	fout.open("user.txt");

	if (!fout.is_open())
	{
		cout << "Îøèáêà îòêðûòèÿ ôàéëà" << endl;
	}

	fout.close();
}


void adminMenu()
{
	while (true)
	{
		cout << "Âûáåðèòå îïöèþ: " << endl << endl
			<< "1. Ðàáîòà ñ îáúåêòàìè" << endl
			<< "2. Ðàáîòà ñ ó÷åòíûìè çàïèñÿìè àäìèíèñòðàòîðîâ" << endl << endl
			<< "0. Íàçàä" << endl;

		int choice;
		cin >> choice;

		system("CLS");

		switch (choice)
		{
		case 1:
			typeChoosingAdmin();
			break;

		case 2:
			adminRegistration();
			break;

		case 0:
			return;
		}
	}
}

bool isAdminAuthorization()
{
	string login;
	string password;

	cout << "Ëîãèí: ";
	cin >> login;

	cout << "Ïàðîëü: ";
	cin >> password;

	system("CLS");

	ifstream fin;

	fin.open("admin.txt");

	if (!fin.is_open())
	{
		cout << "Îøèáêà îòêðûòèÿ ôàéëà" << endl;
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

void adminRegistration()
{
	fstream fs;
	while (true)
	{
		fs.open("admin.txt", fstream::in | fstream::out | fstream::app);

		if (!fs.is_open())
		{
			cout << "Îøèáêà îòêðûòèÿ ôàéëà" << endl;
		}
		else
		{
			cout << "Âûáåðèòå îïöèþ: " << endl
				<< "1. Çàðåãèñòðèðîâàòü íîâîãî àäìèíèñòðàòîðà" << endl
				<< "2. Ïîñìîòðåòü ñïèñîê âñåõ àäìèíèñòðàòîðîâ" << endl;

			int choice;
			cin >> choice;

			system("CLS");

			switch (choice)
			{
			case 1:
			{
				string login;
				string password;

				cout << "Ââåäèòå ëîãèí: ";
				cin >> login;

				cout << "Ââåäèòå ïàðîëü: ";
				cin >> password;

				fs << login << " " << password << "\n";
			}
			break;

			case 2:
			{
				string view;
				cout << setw(10) << "Ëîãèí" << setw(10) << "Ïàðîëü" << endl;

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

void adminFileCreating()
{
	ofstream fout;

	fout.open("admin.txt");

	if (!fout.is_open())
	{
		cout << "Îøèáêà îòêðûòèÿ ôàéëà" << endl;
	}
	else
	{
		string firstLoginAndPassword = "admin";

		fout << firstLoginAndPassword << " " << firstLoginAndPassword << "\n";
	}

	fout.close();
}


