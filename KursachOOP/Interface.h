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

template<>
NewBuilding Interface<NewBuilding>::enterData()
{
	NewBuilding object;
	object.enterData();
	return object;
}

template<>
SecondaryHousing Interface<SecondaryHousing>::enterData()
{
	SecondaryHousing object;
	object.enterData();
	return object;
}

template<>
Cottage Interface<Cottage>::enterData()
{
	Cottage object;
	object.enterData();
	return object;
}

template<>
Country Interface<Country>::enterData()
{
	Country object;
	object.enterData();
	return object;
}

template<>
Ground Interface<Ground>::enterData()
{
	Ground object;
	object.enterData();
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