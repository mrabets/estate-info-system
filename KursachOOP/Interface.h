#pragma once

#include "NewBuilding.h"
#include "SecondaryHousing.h"
#include "Cottage.h"
#include "Country.h"
#include "Ground.h"
#include "Ring.h"
#include "User.h"

void pointOfEntry();

void userMenu();
bool isUserAuthorization();
void userRegistration();
void userFileCreating();

void viewEstate();

void adminMenu();
bool isAdminAuthorization();
void adminRegistration();
void userManage();
void adminFileCreating();

string encryptDecrypt(string toEncrypt);


template<class T>
class Interface
{
public:
	Interface() {};
	~Interface() {};

	void serviceMenuAdmin();
	T enterData();
	void searchData();
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
			object.addToBegin(enterData());
			break;

		case 2:
			object.addToEnd(enterData());
			break;

		case 3:
			cout << "Ââåäèòå èíäåêñ: ";
			cin >> index;

			if (index < 0 || index > object.getSize())
			{
				cout << "Íåâåðíûé èíäåêñ" << endl;
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


template<class T>
T Interface<T>::enterData()
{
	cout << "Ââåäèòå äàííûå: ";
	T data;
	cin >> data;
	return data;
}

template<>
NewBuilding Interface<NewBuilding>::enterData()
{
	string city;
	cout << "Ââåäèòå ãîðîä (íàïð. Ìèíñê): ";
	cin >> city;

	string owner;
	cout << "Ââåäèòå âëàäåëüöà (íàïð. Íîâîñòðîé): ";
	cin >> owner;

	int price;
	cout << "Ââåäèòå öåíó (â äîëëàðàõ): ";
	cin >> price;

	float livingSpace;
	cout << "Ââåäèòå æèëóþ ïëîùàäü (â êâàäðàòíûõ ìåòðàõ): ";
	cin >> livingSpace;

	int yearBuilt;
	cout << "Ââåäèòå ãîä ïîñòðîéêè: ";
	cin >> yearBuilt;

	int floor;
	cout << "Ââåäèòå ýòàæ: ";
	cin >> floor;

	int roomsAmount;
	cout << "Ââåäèòå êîëè÷åñòâî êîìíàò: ";
	cin >> roomsAmount;

	int waranty;
	cout << "Ââåäèòå ãàðàíòèÿ (ëåò): ";
	cin >> waranty;

	NewBuilding object(waranty, roomsAmount, floor, livingSpace, yearBuilt, city, owner, price);
	return object;
}

template<>
SecondaryHousing Interface<SecondaryHousing>::enterData()
{
	string city;
	cout << "Ââåäèòå ãîðîä (íàïð. Ìèíñê): ";
	cin >> city;

	string owner;
	cout << "Ââåäèòå âëàäåëüöà (íàïð. Íîâîñòðîé): ";
	cin >> owner;

	int price;
	cout << "Ââåäèòå öåíó (â äîëëàðàõ): ";
	cin >> price;

	float livingSpace;
	cout << "Ââåäèòå æèëóþ ïëîùàäü (â êâàäðàòíûõ ìåòðàõ): ";
	cin >> livingSpace;

	int yearBuilt;
	cout << "Ââåäèòå ãîä ïîñòðîéêè: ";
	cin >> yearBuilt;

	int floor;
	cout << "Ââåäèòå ýòàæ: ";
	cin >> floor;

	int roomsAmount;
	cout << "Ââåäèòå êîëè÷åñòâî êîìíàò: ";
	cin >> roomsAmount;

	string typeOfRepair;
	cout << "Ââåäèòå òèï ðåìîíòà (íàïð. Åâðîðåìîíò): ";
	cin >> typeOfRepair;

	SecondaryHousing object(city, owner, price, livingSpace, yearBuilt, roomsAmount, floor, typeOfRepair);
	return object;
}

template<>
Cottage Interface<Cottage>::enterData()
{
	string city;
	cout << "Ââåäèòå ãîðîä (íàïð. Ìèíñê): ";
	cin >> city;

	string owner;
	cout << "Ââåäèòå âëàäåëüöà (íàïð. Íîâîñòðîé): ";
	cin >> owner;

	int price;
	cout << "Ââåäèòå öåíó (â äîëëàðàõ): ";
	cin >> price;

	float livingSpace;
	cout << "Ââåäèòå æèëóþ ïëîùàäü (â êâàäðàòíûõ ìåòðàõ): ";
	cin >> livingSpace;

	int yearBuilt;
	cout << "Ââåäèòå ãîä ïîñòðîéêè: ";
	cin >> yearBuilt;

	int floorsAmount;
	cout << "Ââåäèòå êîëè÷åñòâî ýòàæåé: ";
	cin >> floorsAmount;

	string nameOfVillage;
	cout << "Ââåäèòå íàçâàíèå ïîñ¸ëêà: ";
	cin >> nameOfVillage;

	Cottage object(nameOfVillage, floorsAmount, livingSpace, yearBuilt, city, owner, price);
	return object;
}

template<>
Country Interface<Country>::enterData()
{
	string city;
	cout << "Ââåäèòå ãîðîä (íàïð. Ìèíñê): ";
	cin >> city;

	string owner;
	cout << "Ââåäèòå âëàäåëüöà (íàïð. Íîâîñòðîé): ";
	cin >> owner;

	int price;
	cout << "Ââåäèòå öåíó (â äîëëàðàõ): ";
	cin >> price;

	float livingSpace;
	cout << "Ââåäèòå æèëóþ ïëîùàäü (â êâàäðàòíûõ ìåòðàõ): ";
	cin >> livingSpace;

	int yearBuilt;
	cout << "Ââåäèòå ãîä ïîñòðîéêè: ";
	cin >> yearBuilt;

	int floorsAmount;
	cout << "Ââåäèòå êîëè÷åñòâî ýòàæåé: ";
	cin >> floorsAmount;

	int distanceFromCity;
	cout << "Ââåäèòå íàçâàíèå ïîñ¸ëêà: ";
	cin >> distanceFromCity;

	Country object(distanceFromCity, floorsAmount, livingSpace, yearBuilt, city, owner, price);
	return object;
}

template<>
Ground Interface<Ground>::enterData()
{
	string city;
	cout << "Ââåäèòå ãîðîä (íàïð. Ìèíñê): ";
	cin >> city;

	string owner;
	cout << "Ââåäèòå âëàäåëüöà (íàïð. Íîâîñòðîé): ";
	cin >> owner;

	int price;
	cout << "Ââåäèòå öåíó (â äîëëàðàõ): ";
	cin >> price;

	float landSquare;
	cout << "Ââåäèòå ïëîùàäü çåìåëüíîãî ó÷àñòêà (â êâàäðàòíûõ ìåòðàõ): ";
	cin >> landSquare;

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
			cout << "Îøèáêà îòêðûòèÿ ôàéëà" << endl;
		}
		else
		{
			cout << "Èñêàòü ïî: " << endl << endl
				<< "1. Ãîðîäó" << endl
				<< "2. Öåíå" << endl
				<< "3. Êîëè÷åñòâó êîìíàò" << endl << endl
				<< "0. Íàçàä" << endl;

			int choice;
			cin >> choice;

			system("CLS");

			switch (choice)
			{
			case 1:
			{
				string city;
				cout << "Ââåäèòå ãîðîä: ";
				cin >> city;

				system("CLS");

				cout << setw(20) << "ÃÎÐÎÄ" << setw(20) << "ÂËÀÄÅËÅÖ" << setw(10) << "ÖÅÍÀ" << setw(18) << "ÆÈË. ÏËÎÙÀÄÜ" << setw(18) << "ÃÎÄ ÏÎÑÒÐÎÉÊÈ"
					<< setw(10) << "ÝÒÀÆ" << setw(20) << "ÊÎË-ÂÎ ÊÎÌÍÀÒ" << setw(12) << "ÃÀÐÀÍÒÈß" << endl;

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

				cout << "Ââåäèòå ìèíèìàëüíóþ öåíó: ";
				cin >> minPrice;

				cout << "Ââåäèòå ìàêñèìàëüíóþ öåíó: ";
				cin >> maxPrice;

				system("CLS");

				cout << setw(20) << "ÃÎÐÎÄ" << setw(20) << "ÂËÀÄÅËÅÖ" << setw(10) << "ÖÅÍÀ" << setw(18) << "ÆÈË. ÏËÎÙÀÄÜ" << setw(18) << "ÃÎÄ ÏÎÑÒÐÎÉÊÈ"
					<< setw(10) << "ÝÒÀÆ" << setw(20) << "ÊÎË-ÂÎ ÊÎÌÍÀÒ" << setw(12) << "ÃÀÐÀÍÒÈß" << endl;

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
				cout << "Ââåäèòå êîëè÷åñòâî êîìíàò: ";
				cin >> roomsAmount;

				system("CLS");

				cout << setw(20) << "ÃÎÐÎÄ" << setw(20) << "ÂËÀÄÅËÅÖ" << setw(10) << "ÖÅÍÀ" << setw(18) << "ÆÈË. ÏËÎÙÀÄÜ" << setw(18) << "ÃÎÄ ÏÎÑÒÐÎÉÊÈ"
					<< setw(10) << "ÝÒÀÆ" << setw(20) << "ÊÎË-ÂÎ ÊÎÌÍÀÒ" << setw(12) << "ÃÀÐÀÍÒÈß" << endl;

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
			cout << "Îøèáêà îòêðûòèÿ ôàéëà" << endl;
		}
		else
		{
			cout << "Èñêàòü ïî: " << endl << endl
				<< "1. Ãîðîäó" << endl
				<< "2. Ýòàæ" << endl
				<< "3. Æèëàÿ ïëîùàäü" << endl << endl
				<< "0. Íàçàä" << endl;

			int choice;
			cin >> choice;

			system("CLS");

			switch (choice)
			{
			case 1:
			{
				string city;
				cout << "Ââåäèòå ãîðîä: ";
				cin >> city;

				system("CLS");

				cout << setw(20) << "ÃÎÐÎÄ" << setw(20) << "ÂËÀÄÅËÅÖ" << setw(10) << "ÖÅÍÀ" << setw(18) << "ÆÈË. ÏËÎÙÀÄÜ" << setw(18) << "ÃÎÄ ÏÎÑÒÐÎÉÊÈ"
					<< setw(10) << "ÝÒÀÆ" << setw(20) << "ÊÎË-ÂÎ ÊÎÌÍÀÒ" << setw(18) << "ÒÈÏ ÐÅÌÎÍÒÀ" << endl;

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
				cout << "Ââåäèòå ãîðîä: ";
				cin >> floor;

				system("CLS");

				cout << setw(20) << "ÃÎÐÎÄ" << setw(20) << "ÂËÀÄÅËÅÖ" << setw(10) << "ÖÅÍÀ" << setw(18) << "ÆÈË. ÏËÎÙÀÄÜ" << setw(18) << "ÃÎÄ ÏÎÑÒÐÎÉÊÈ"
					<< setw(10) << "ÝÒÀÆ" << setw(20) << "ÊÎË-ÂÎ ÊÎÌÍÀÒ" << setw(18) << "ÒÈÏ ÐÅÌÎÍÒÀ" << endl;

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

				cout << "Ââåäèòå ìèíèìàëüíóþ æèëóþ ïëîùàäü: ";
				cin >> minLivingSpace;

				cout << "Ââåäèòå ìàêñèìàëüíóþ æèëóþ ïëîùàäü: ";
				cin >> maxLivingSpace;

				system("CLS");

				cout << setw(20) << "ÃÎÐÎÄ" << setw(20) << "ÂËÀÄÅËÅÖ" << setw(10) << "ÖÅÍÀ" << setw(18) << "ÆÈË. ÏËÎÙÀÄÜ" << setw(18) << "ÃÎÄ ÏÎÑÒÐÎÉÊÈ"
					<< setw(10) << "ÝÒÀÆ" << setw(20) << "ÊÎË-ÂÎ ÊÎÌÍÀÒ" << setw(18) << "ÒÈÏ ÐÅÌÎÍÒÀ" << endl;

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
			cout << "Îøèáêà îòêðûòèÿ ôàéëà" << endl;
		}
		else
		{
			cout << "Èñêàòü ïî: " << endl << endl
				<< "1. Ãîðîä" << endl
				<< "2. Ïîñ¸ëîê" << endl
				<< "3. Êîëè÷åñòâî ýòàæåé" << endl << endl
				<< "0. Íàçàä" << endl;

			int choice;
			cin >> choice;

			system("CLS");

			switch (choice)
			{
			case 1:
			{
				string city;
				cout << "Ââåäèòå ãîðîä: ";
				cin >> city;

				system("CLS");

				cout << setw(20) << "ÃÎÐÎÄ" << setw(20) << "ÂËÀÄÅËÅÖ" << setw(10) << "ÖÅÍÀ" << setw(18) << "ÆÈË. ÏËÎÙÀÄÜ" << setw(18) << "ÃÎÄ ÏÎÑÒÐÎÉÊÈ"
					<< setw(20) << "ÊÎË-ÂÎ ÝÒÀÆÅÉ" << setw(15) << "ÏÎÑ¨ËÎÊ" << endl;

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
				cout << "Ââåäèòå íàçâàíèå ïîñ¸ëêà: ";
				cin >> nameOfVillage;

				system("CLS");

				cout << setw(20) << "ÃÎÐÎÄ" << setw(20) << "ÂËÀÄÅËÅÖ" << setw(10) << "ÖÅÍÀ" << setw(18) << "ÆÈË. ÏËÎÙÀÄÜ" << setw(18) << "ÃÎÄ ÏÎÑÒÐÎÉÊÈ"
					<< setw(20) << "ÊÎË-ÂÎ ÝÒÀÆÅÉ" << setw(15) << "ÏÎÑ¨ËÎÊ" << endl;

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
				cout << "Ââåäèòå êîëè÷åñòâî ýòàæåé: ";
				cin >> floorsAmount;

				system("CLS");

				cout << setw(20) << "ÃÎÐÎÄ" << setw(20) << "ÂËÀÄÅËÅÖ" << setw(10) << "ÖÅÍÀ" << setw(18) << "ÆÈË. ÏËÎÙÀÄÜ" << setw(18) << "ÃÎÄ ÏÎÑÒÐÎÉÊÈ"
					<< setw(20) << "ÊÎË-ÂÎ ÝÒÀÆÅÉ" << setw(15) << "ÏÎÑ¨ËÎÊ" << endl;

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
			cout << "Îøèáêà îòêðûòèÿ ôàéëà" << endl;
		}
		else
		{
			cout << "Èñêàòü ïî: " << endl << endl
				<< "1. Ðàññòîÿíèå îò ãîðîäà" << endl
				<< "2. Öåíà" << endl
				<< "3. Ãîä ïîñòðîéêè" << endl << endl
				<< "0. Íàçàä" << endl;

			int choice;
			cin >> choice;

			system("CLS");

			switch (choice)
			{
			case 1:
			{
				int distanceFromCity;
				cout << "Ââåäèòå ìàêñèìàëüíîå ðàññòÿîíèå îò ãîðîäà: ";
				cin >> distanceFromCity;

				system("CLS");

				cout << setw(20) << "ÃÎÐÎÄ" << setw(20) << "ÂËÀÄÅËÅÖ" << setw(10) << "ÖÅÍÀ" << setw(18) << "ÆÈË. ÏËÎÙÀÄÜ" << setw(18) << "ÃÎÄ ÏÎÑÒÐÎÉÊÈ"
					<< setw(20) << "ÊÎË-ÂÎ ÝÒÀÆÅÉ" << setw(25) << "ÐÀÑÑÒÎßÍÈÅ ÎÒ ÃÎÐÎÄÀ" << endl;

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

				cout << "Ââåäèòå ìèíèìàëüíóþ öåíó: ";
				cin >> minPrice;

				cout << "Ââåäèòå ìàêñèìàëüíóþ öåíó: ";
				cin >> maxPrice;

				system("CLS");

				cout << setw(20) << "ÃÎÐÎÄ" << setw(20) << "ÂËÀÄÅËÅÖ" << setw(10) << "ÖÅÍÀ" << setw(18) << "ÆÈË. ÏËÎÙÀÄÜ" << setw(18) << "ÃÎÄ ÏÎÑÒÐÎÉÊÈ"
					<< setw(20) << "ÊÎË-ÂÎ ÝÒÀÆÅÉ" << setw(25) << "ÐÀÑÑÒÎßÍÈÅ ÎÒ ÃÎÐÎÄÀ" << endl;

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
				cout << "Ââåäèòå ãîä ïîñòðîéêè: ";
				cin >> yearBuilt;

				system("CLS");

				cout << setw(20) << "ÃÎÐÎÄ" << setw(20) << "ÂËÀÄÅËÅÖ" << setw(10) << "ÖÅÍÀ" << setw(18) << "ÆÈË. ÏËÎÙÀÄÜ" << setw(18) << "ÃÎÄ ÏÎÑÒÐÎÉÊÈ"
					<< setw(20) << "ÊÎË-ÂÎ ÝÒÀÆÅÉ" << setw(25) << "ÐÀÑÑÒÎßÍÈÅ ÎÒ ÃÎÐÎÄÀ" << endl;

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
			cout << "Îøèáêà îòêðûòèÿ ôàéëà" << endl;
		}
		else
		{
			cout << "Èñêàòü ïî: " << endl << endl
				<< "1. Ïëîùàäü çåìåëüíîãî ó÷àñòêà" << endl
				<< "2. Öåíà" << endl
				<< "3. Ãîðîä" << endl << endl
				<< "0. Íàçàä" << endl;

			int choice;
			cin >> choice;

			system("CLS");

			switch (choice)
			{
			case 1:
			{
				float minLandSquare;
				float maxLandSquare;

				cout << "Ââåäèòå ìèíèìàëüíóþ ïëîùàäü çåìåëüíîãî ó÷àñòêà: ";
				cin >> minLandSquare;

				cout << "Ââåäèòå ìàêñèìàëüíóþ ïëîùàäü çåìåëüíîãî ó÷àñòêà: ";
				cin >> maxLandSquare;

				system("CLS");

				cout << setw(20) << "ÃÎÐÎÄ" << setw(20) << "ÂËÀÄÅËÅÖ" << setw(10) << "ÖÅÍÀ" << setw(20) << "ÏËÎÙÀÄÜ Ó×ÀÑÒÊÀ" << endl;

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

				cout << "Ââåäèòå ìèíèìàëüíóþ öåíó: ";
				cin >> minPrice;

				cout << "Ââåäèòå ìàêñèìàëüíóþ öåíó: ";
				cin >> maxPrice;

				system("CLS");

				cout << setw(20) << "ÃÎÐÎÄ" << setw(20) << "ÂËÀÄÅËÅÖ" << setw(10) << "ÖÅÍÀ" << setw(20) << "ÏËÎÙÀÄÜ Ó×ÀÑÒÊÀ" << endl;

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
				cout << "Ââåäèòå ãîðîä: ";
				cin >> city;

				system("CLS");

				cout << setw(20) << "ÃÎÐÎÄ" << setw(20) << "ÂËÀÄÅËÅÖ" << setw(10) << "ÖÅÍÀ" << setw(20) << "ÏËÎÙÀÄÜ Ó×ÀÑÒÊÀ" << endl;

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

void typeChoosing()
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
			<< "1. Íîâîñòðîéêè" << endl
			<< "2. Âòîðè÷êè" << endl
			<< "3. Êîòòåäæè" << endl
			<< "4. Äà÷è" << endl
			<< "5. Ó÷àñòêè" << endl << endl
			<< "0. Íàçàä" << endl;

		int choice;
		cin >> choice;

		system("CLS");

		switch (choice)
		{
		case 1:
			cout << setw(20) << "ÃÎÐÎÄ" << setw(20) << "ÂËÀÄÅËÅÖ" << setw(10) << "ÖÅÍÀ" << setw(18) << "ÆÈË. ÏËÎÙÀÄÜ" << setw(18) << "ÃÎÄ ÏÎÑÒÐÎÉÊÈ"
				<< setw(10) << "ÝÒÀÆ" << setw(20) << "ÊÎË-ÂÎ ÊÎÌÍÀÒ" << setw(12) << "ÃÀÐÀÍÒÈß" << endl;

			fileName = "NewBuilding.txt";
			break;

		case 2:
			cout << setw(20) << "ÃÎÐÎÄ" << setw(20) << "ÂËÀÄÅËÅÖ" << setw(10) << "ÖÅÍÀ" << setw(18) << "ÆÈË. ÏËÎÙÀÄÜ" << setw(18) << "ÃÎÄ ÏÎÑÒÐÎÉÊÈ"
				<< setw(10) << "ÝÒÀÆ" << setw(20) << "ÊÎË-ÂÎ ÊÎÌÍÀÒ" << setw(18) << "ÒÈÏ ÐÅÌÎÍÒÀ" << endl;

			fileName = "SecondaryHousing.txt";
			break;

		case 3:
			cout << setw(20) << "ÃÎÐÎÄ" << setw(20) << "ÂËÀÄÅËÅÖ" << setw(10) << "ÖÅÍÀ" << setw(18) << "ÆÈË. ÏËÎÙÀÄÜ" << setw(18) << "ÃÎÄ ÏÎÑÒÐÎÉÊÈ"
				<< setw(20) << "ÊÎË-ÂÎ ÝÒÀÆÅÉ" << setw(15) << "ÏÎÑ¨ËÎÊ" << endl;

			fileName = "Cottage.txt";
			break;

		case 4:
			cout << setw(20) << "ÃÎÐÎÄ" << setw(20) << "ÂËÀÄÅËÅÖ" << setw(10) << "ÖÅÍÀ" << setw(18) << "ÆÈË. ÏËÎÙÀÄÜ" << setw(18) << "ÃÎÄ ÏÎÑÒÐÎÉÊÈ"
				<< setw(20) << "ÊÎË-ÂÎ ÝÒÀÆÅÉ" << setw(25) << "ÐÀÑÑÒÎßÍÈÅ ÎÒ ÃÎÐÎÄÀ" << endl;

			fileName = "Country.txt";
			break;

		case 5:
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
		case 2:
		{
			Interface<NewBuilding> object;
			object.searchData();
		}
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
		{
			viewEstate();

			break;
		}
			
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
				string decrypted = encryptDecrypt(temp);
				if (decrypted == password)
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
				cout << "Ââåäèòå ëîãèí: ";

				string login;
				cin >> login;

				cout << "Ââåäèòå ïàðîëü: ";

				string password;
				cin >> password;

				password = encryptDecrypt(password);

				cout << "Âîçðàñò: ";

				int age;
				cin >> age;

				cout << "Ïîë: ";

				char sex;
				cin >> sex;

				cout << "Íîìåð ìîáèëüíîãî òåëåôîíà: ";

				string phone;
				cin >> phone;

				cout << "Àäðåñ ýëåêòðîííîé ïî÷òû: ";

				string email;
				cin >> email;

				string decrypted = encryptDecrypt(password);

				system("CLS");

				User user(login, password, age, sex, phone, email);

				fs << user;

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

	fout.open("User.txt");

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
			<< "2. Ðàáîòà ñ ó÷åòíûìè çàïèñÿìè àäìèíèñòðàòîðîâ" << endl
			<< "3. Ðàáîòà ñ ó÷åòíûìè çàïèñÿìè ïîëüçîâàòåëåé" << endl << endl
			<< "0. Íàçàä" << endl;

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
				string decrypted = encryptDecrypt(temp);
				if (decrypted == password)
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
		fs.open("Admin.txt", fstream::in | fstream::out | fstream::app);

		if (!fs.is_open())
		{
			cout << "Îøèáêà îòêðûòèÿ ôàéëà" << endl;
		}
		else
		{
			cout << "Âûáåðèòå îïöèþ: " << endl << endl
				<< "1. Çàðåãèñòðèðîâàòü íîâîãî àäìèíèñòðàòîðà" << endl
				<< "2. Ïîñìîòðåòü ñïèñîê âñåõ àäìèíèñòðàòîðîâ" << endl << endl
				<< "0. Íàçàä" << endl;

			int choice;
			cin >> choice;

			system("CLS");

			switch (choice)
			{
			case 1:
			{
				cout << "Ââåäèòå ëîãèí: ";

				string login;
				cin >> login;

				cout << "Ââåäèòå ïàðîëü: ";

				string password;
				cin >> password;

				string encrypted = encryptDecrypt(password);

				fs << setw(10) << login << setw(10) << encrypted << "\n";

				break;
			}		

			case 2:
			{	
				cout << setw(10) << "Ëîãèí" << setw(10) << "Ïàðîëü" << endl;

				string temp;
				while (!fs.eof())
				{
					temp = "";

					fs >> temp;
					cout << setw(10) << temp;

					temp = "";

					fs >> temp;
					cout << setw(10) << temp;

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

void userManage()
{
	fstream fs;
	while (true)
	{
		fs.open("User.txt", fstream::in | fstream::out | fstream::app);

		if (!fs.is_open())
		{
			cout << "Îøèáêà îòêðûòèÿ ôàéëà" << endl;
		}
		else
		{
			cout << "Âûáåðèòå îïöèþ: " << endl << endl
				<< "1. Ïðîñìîòðåòü äàííûå âñåõ ïîëüçîâàòåëåé" << endl
				<< "2. Ïðîñìîòðåòü äàííûå îïðåäåëåííîãî ïîëüçîâàòåëÿ" << endl
				<< "3. Äîáàâèòü íîâîãî ïîëüçîâàòåëÿ" << endl << endl
				<< "0. Íàçàä" << endl;

			int choice;
			cin >> choice;

			system("CLS");

			switch (choice)
			{
			case 1:
			{
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
				cout << "Ââåäèòå ëîãèí ïîëüçîâàòåëÿ: ";

				string login;
				cin >> login;

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
				cout << "Ââåäèòå ëîãèí: ";

				string login;
				cin >> login;

				cout << "Ââåäèòå ïàðîëü: ";

				string password;
				cin >> password;

				password = encryptDecrypt(password);

				int age;
				while (true)
				{
					cin.clear();

					cout << "Âîçðàñò: ";

					cin >> age;

					if (age >= 18 && age <= 120)
					{
						break;
					}

					system("CLS");
					cout << "Íåêîððåêòíîå çíà÷åíèå. Ïîâòîðèòå ââîä: " << endl;
				}

				char sex;
				while (true)
				{
					cin.clear();

					cout << "Ïîë (Ì - ìóæñêîé, Æ - æåíñêèé): ";

					cin >> sex;

					if (sex == 'Ì' || sex == 'Æ' || sex == 'ì' || sex == 'æ')
					{
						break;
					}

					system("CLS");
					cout << "Íåêîððåêòíîå çíà÷åíèå. Ïîâòîðèòå ââîä: " << endl;
				}

				string phone;

				

				while (true)
				{
					cin.clear();

					cout << "Íîìåð ìîáèëüíîãî òåëåôîíà (íàïð. +375257712277): ";

					cin >> phone;

					if (phone.length() != 13 || phone[0] != '+')
					{
						system("CLS");
						cout << "Íåêîððåêòíîå çíà÷åíèå. Ïîâòîðèòå ââîä: " << endl;
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
					cout << "Íåêîððåêòíîå çíà÷åíèå. Ïîâòîðèòå ââîä: " << endl;
				}

				string email;	

				while (true)
				{
					cin.clear();

					cout << "Àäðåñ ýëåêòðîííîé ïî÷òû: ";
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
					cout << "Íåêîððåêòíîå çíà÷åíèå. Ïîâòîðèòå ââîä: " << endl;
				}			

				system("CLS");

				User user(login, password, age, sex, phone, email);

				fs << user;

				cout << "Óñïåøíîå äîáàâëåíèå íîâîãî ïîëüçîâàòåëÿ" << endl;

				break;
			}

			case 0:
				return;
			}
		}

		fs.close();
	}
}

void adminFileCreating()
{
	ofstream fout;

	fout.open("Admin.txt");

	if (!fout.is_open())
	{
		cout << "Îøèáêà îòêðûòèÿ ôàéëà" << endl;
	}
	else
	{
		string firstLogin = "admin";
		string firstPassword = "admin";

		firstPassword = encryptDecrypt(firstPassword);

		fout << setw(10) << firstLogin << setw(10) << firstPassword << "\n";
	}

	fout.close();
}

string encryptDecrypt(string toEncrypt)
{
	char key[3] = { 'K', 'C', 'Q' };
	string output = toEncrypt;

	for (int i = 0; i < toEncrypt.size(); i++)
		output[i] = toEncrypt[i] ^ key[i % (sizeof(key) / sizeof(char))];

	return output;
}