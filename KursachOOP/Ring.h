#pragma once

#include <typeinfo>
#include <iostream>
#include <fstream>

using namespace std;

template<class T>
class Ring
{
public:
	Ring();
	~Ring();

	void addToEmpty(T data);
	void addToBegin(T data);
	void addToEnd(T data);
	void addByIndex(T value, int index);

	void deleteFirst();
	void deleteLast();
	void deleteByIndex(int index);

	void changeData(int index);
	void saveDataToFile();
	void display();

	int getSize();

	void clear();

private:
	template<class T>
	class Node
	{
	public:
		Node* next;
		T data;

		Node(T data = T(), Node* next = nullptr)
		{
			this->data = data;
			this->next = next;
		}
	};
	int size;
	Node<T>* head;

	void displayBase();
	void saveDataToFileBase(string fileName);
};

template<class T>
Ring<T>::Ring()
{
	size = 0;
	head = nullptr;
}

template<class T>
Ring<T>::~Ring()
{
	clear();
}

template<class T>
void Ring<T>::addToEnd(T data)
{
	if (head == nullptr)
	{
		addToEmpty(data);
	}
	else
	{
		Node<T>* current = this->head;

		while (current->next != head)
		{
			current = current->next;
		}

		current->next = new Node<T>(data, head);

		size++;
	}
}

template<class T>
void Ring<T>::addToEmpty(T data)
{
	head = new Node<T>(data);
	head->next = head;

	size++;
}

template<class T>
void Ring<T>::addToBegin(T data)
{
	if (head == nullptr)
	{
		addToEmpty(data);
	}
	else
	{
		Node<T>* current = head;

		while (current->next != head)
		{
			current = current->next;
		}

		head = new Node<T>(data, head);
		current->next = head;

		size++;
	}
}

template<class T>
void Ring<T>::addByIndex(T value, int index)
{
	if (index == 0)
	{
		addToBegin(value);
		return;
	}

	if (index == size - 1)
	{
		addToEnd(value);
		return;
	}

	Node<T>* previous = head;

	for (int i = 0; i < index - 1; i++)
	{
		previous = previous->next;
	}

	Node<T>* newNode = new Node<T>(value, previous->next);
	previous->next = newNode;

	size++;
}

template<class T>
void Ring<T>::deleteByIndex(int index)
{
	if (head == nullptr)
	{
		cout << "Таблица пуста" << endl;
		return;
	}

	if (index == 0)
	{
		deleteFirst();
		return;
	}

	Node<T>* previous = head;

	if (previous->next == head)
	{
		head = nullptr;
		delete head;
	}
	else
	{
		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->next;
		}

		Node<T>* temp = previous->next;

		previous->next = temp->next;
		delete temp;
	}

	size--;
}

template<class T>
void Ring<T>::deleteFirst()
{
	if (head == nullptr)
	{
		cout << "Таблица пуста" << endl;
		return;
	}

	Node<T>* current = head;

	if (current->next == head)
	{
		head = nullptr;
		delete head;
	}
	else
	{
		while (current->next != head)
		{
			current = current->next;
		}

		Node<T>* temp = head;

		head = head->next;
		current->next = head;

		delete temp;
	}

	size--;
}

template<class T>
void Ring<T>::deleteLast()
{
	deleteByIndex(size - 1);
}

template<class T>
void Ring<T>::clear()
{
	if (head == nullptr)
	{
		return;
	}

	while (size)
	{
		deleteFirst();
	}

	cout << "Удалено успешно" << endl << endl;
}

template<class T>
void Ring<T>::displayBase()
{
	if (head == nullptr)
	{
		cout << setw(20) << "..." << endl;
		return;
	}

	Node<T>* current = head;
	while (current->next != head)
	{
		cout << current->data;
		current = current->next;
	}

	cout << current->data;
}

template<class T>
void Ring<T>::display()
{
	displayBase();
}

template<>
void Ring<NewBuilding>::display()
{
	cout << setw(20) << "ГОРОД" << setw(20) << "ВЛАДЕЛЕЦ" << setw(10) << "ЦЕНА" << setw(18) << "ЖИЛ. ПЛОЩАДЬ" << setw(18) << "ГОД ПОСТРОЙКИ"
		<< setw(10) << "ЭТАЖ" << setw(20) << "КОЛ-ВО КОМНАТ" << setw(12) << "ГАРАНТИЯ" << endl;

	displayBase();
}

template<>
void Ring<SecondaryHousing>::display()
{
	cout << setw(20) << "ГОРОД" << setw(20) << "ВЛАДЕЛЕЦ" << setw(10) << "ЦЕНА" << setw(18) << "ЖИЛ. ПЛОЩАДЬ" << setw(18) << "ГОД ПОСТРОЙКИ"
		<< setw(10) << "ЭТАЖ" << setw(20) << "КОЛ-ВО КОМНАТ" << setw(18) << "ТИП РЕМОНТА" << endl;

	displayBase();
}

template<>
void Ring<Cottage>::display()
{
	cout << setw(20) << "ГОРОД" << setw(20) << "ВЛАДЕЛЕЦ" << setw(10) << "ЦЕНА" << setw(18) << "ЖИЛ. ПЛОЩАДЬ" << setw(18) << "ГОД ПОСТРОЙКИ"
		<< setw(20) << "КОЛ-ВО ЭТАЖЕЙ" << setw(15) << "ПОСЁЛОК" << endl;

	displayBase();
}

template<>
void Ring<Country>::display()
{
	cout << setw(20) << "ГОРОД" << setw(20) << "ВЛАДЕЛЕЦ" << setw(10) << "ЦЕНА" << setw(18) << "ЖИЛ. ПЛОЩАДЬ" << setw(18) << "ГОД ПОСТРОЙКИ"
		<< setw(20) << "КОЛ-ВО ЭТАЖЕЙ" << setw(25) << "РАССТОЯНИЕ ОТ ГОРОДА" << endl;

	displayBase();
}

template<>
void Ring<Ground>::display()
{
	cout << setw(20) << "ГОРОД" << setw(20) << "ВЛАДЕЛЕЦ" << setw(10) << "ЦЕНА" << setw(20) << "ПЛОЩАДЬ УЧАСТКА" << endl;

	displayBase();
}

template<class T>
int Ring<T>::getSize()
{
	return size;
}

template <class T>
void Ring<T>::changeData(int index)
{
	Node<T>* current = head;

	if (current->next == head)
	{
		head = nullptr;
		delete head;
	}
	else
	{
		T data;

		for (int i = 0; i < index - 1; i++)
		{
			current = current->next;
		}

		cin >> data;
		current->data = data;
	}
}

template<class T>
void Ring<T>::saveDataToFileBase(string fileName)
{
	fstream fs;

	while (true)
	{
		cout << "Выберите опцию для работы в базе данных: " << endl << endl
			<< "1. Добавить данные" << endl
			<< "2. Перезаписать данные" << endl
			<< "3. Извлечь данные" << endl
			<< "4. Вывести данные на экран" << endl
			<< "5. Удалить данные" << endl << endl
			<< "0. Назад" << endl;

		int choice;
		cin >> choice;

		system("CLS");

		string info;
		switch (choice)
		{
		case 1:
		{
			fs.open(fileName, fstream::out | fstream::app);

			if (!fs.is_open())
			{
				cout << "Ошибка открытия файла" << endl;
			}
			else
			{
				if (head == nullptr)
				{
					cout << "Таблица пуста" << endl;
					break;
				}

				Node<T>* current = head;

				while (current->next != head)
				{
					fs << current->data;
					current = current->next;
				}

				fs << current->data;

				cout << "Данные успешно добавлены в базу данных" << endl << endl;
			}

			fs.close();
			break;
		}

		case 2:
		{
			fs.open(fileName, fstream::out | fstream::trunc);

			if (!fs.is_open())
			{
				cout << "Ошибка открытия файла" << endl;
			}
			else
			{
				if (head == nullptr)
				{
					cout << "Таблица пуста" << endl;
					break;
				}

				Node<T>* current = head;
				while (current->next != head)
				{
					fs << current->data;
					current = current->next;
				}

				fs << current->data;

				cout << "Данные успешно перезаписаны в базу данных" << endl << endl;
			}

			fs.close();
			break;
		}

		case 3:
		{
			fs.open(fileName, fstream::in);

			if (!fs.is_open())
			{
				cout << "Ошибка открытия файла" << endl;
			}
			else
			{
				while (true)
				{
					T object;
					fs >> object;

					if (fs.eof())
					{
						break;
					}

					addToEnd(object);
				}

				cout << "Данные успешно извлечены из базы данных" << endl << endl;
			}

			fs.close();
			break;
		}

		case 4:
		{
			fs.open(fileName, fstream::in);

			if (!fs.is_open())
			{
				cout << "Ошибка открытия файла" << endl;
			}
			else
			{
				while (true)
				{
					T object;
					fs >> object;

					if (fs.eof())
					{
						break;
					}

					cout << object;
				}
			}

			fs.close();
			break;
		}

		case 5:
		{
			fs.open(fileName, fstream::out | fstream::trunc);
			fs.close();
			break;
		}

		case 0:
			return;
		}
	}
}

template<>
void Ring<NewBuilding>::saveDataToFile()
{
	saveDataToFileBase("NewBuilding.txt");
}

template<>
void Ring<SecondaryHousing>::saveDataToFile()
{
	saveDataToFileBase("SecondaryHousing.txt");
}

template<>
void Ring<Cottage>::saveDataToFile()
{
	saveDataToFileBase("Cottage.txt");
}

template<>
void Ring<Country>::saveDataToFile()
{
	saveDataToFileBase("Country.txt");
}

template<>
void Ring<Ground>::saveDataToFile()
{
	saveDataToFileBase("Ground.txt");
}

template<>
void Ring<NewBuilding>::changeData(int index)
{
	Node<NewBuilding>* current = head;

	if (current->next != head)
	{
		for (int i = 0; i < index; i++)
		{
			current = current->next;
		}
	}

	while (true)
	{
		cout << "Выберетие параметр:" << endl
			<< "1. Город" << endl
			<< "2. Владелец" << endl
			<< "3. Цена" << endl
			<< "4. Жилая площадь" << endl
			<< "5. Год постройки" << endl
			<< "6. Кол-во комнат" << endl
			<< "7. Этаж" << endl
			<< "8. Гарантия" << endl;

		int whatChange;
		cin >> whatChange;

		system("CLS");

		switch (whatChange)
		{
		case 1:
		{
			cout << "Введите новый город: ";
			string newAddress;
			cin >> newAddress;
			current->data.setCity(newAddress);
			return;
		}

		case 2:
		{
			cout << "Введите нового владельца: ";
			string newOwner;
			cin >> newOwner;
			current->data.setOwner(newOwner);
			return;
		}

		case 3:
		{
			cout << "Введите новую цену: ";
			float newPrice;
			cin >> newPrice;
			current->data.setPrice(newPrice);
			return;
		}		

		case 4:
		{
			cout << "Введите новую жилую площадь: ";
			float newLivingSpace;
			cin >> newLivingSpace;
			current->data.setLivingSpace(newLivingSpace);
			return;
		}

		case 5:
		{
			cout << "Введите новый год постройки: ";
			int newYearBuilt;
			cin >> newYearBuilt;
			current->data.setYearBuilt(newYearBuilt);
			return;
		}

		case 6:
		{
			cout << "Введите новое кол-во комнат: ";
			int newRoomsAmount;
			cin >> newRoomsAmount;
			current->data.setRoomsAmount(newRoomsAmount);
			return;
		}

		case 7:
		{
			cout << "Введите новый этаж: ";
			int newFloor;
			cin >> newFloor;
			current->data.setFloor(newFloor);
			return;
		}

		case 8:
		{
			cout << "Введите новую гарантию: ";
			int newWarranty;
			cin >> newWarranty;
			current->data.setWarranty(newWarranty);
			return;
		}

		case 0:
			return;
		}
	}
}

template<>
void Ring<SecondaryHousing>::changeData(int index)
{
	Node<SecondaryHousing>* current = head;

	if (current->next != head)
	{
		for (int i = 0; i < index; i++)
		{
			current = current->next;
		}
	}

	while (true)
	{
		cout << "Выберетие параметр:" << endl
			<< "1. Город" << endl
			<< "2. Владелец" << endl
			<< "3. Цена" << endl
			<< "4. Жилая площадь" << endl
			<< "5. Год постройки" << endl
			<< "6. Кол-во комнат" << endl
			<< "7. Этаж" << endl
			<< "8. Тип ремонта" << endl;

		int whatChange;
		cin >> whatChange;

		system("CLS");

		switch (whatChange)
		{
		case 1:
		{
			cout << "Введите новый город: ";
			string newAddress;
			cin >> newAddress;
			current->data.setCity(newAddress);
			return;
		}

		case 2:
		{
			cout << "Введите нового владельца: ";
			string newOwner;
			cin >> newOwner;
			current->data.setOwner(newOwner);
			return;
		}

		case 3:
		{
			cout << "Введите новую цену: ";
			float newPrice;
			cin >> newPrice;
			current->data.setPrice(newPrice);
			return;
		}

		case 4:
		{
			cout << "Введите новую жилую площадь: ";
			float newLivingSpace;
			cin >> newLivingSpace;
			current->data.setLivingSpace(newLivingSpace);
			return;
		}

		case 5:
		{
			cout << "Введите новый год постройки: ";
			int newYearBuilt;
			cin >> newYearBuilt;
			current->data.setYearBuilt(newYearBuilt);
			return;
		}

		case 6:
		{
			cout << "Введите новое кол-во комнат: ";
			int newRoomsAmount;
			cin >> newRoomsAmount;
			current->data.setRoomsAmount(newRoomsAmount);
			return;
		}

		case 7:
		{
			cout << "Введите новый этаж: ";
			int newFloor;
			cin >> newFloor;
			current->data.setFloor(newFloor);
			return;
		}

		case 8:
		{
			cout << "Введите новый тип ремонта: ";
			string newTypeOfRepair;
			cin >> newTypeOfRepair;
			current->data.setTypeOfRepair(newTypeOfRepair);
			return;
		}

		case 0:
			return;
		}
	}
}

template<>
void Ring<Cottage>::changeData(int index)
{
	Node<Cottage>* current = head;

	if (current->next != head)
	{
		for (int i = 0; i < index; i++)
		{
			current = current->next;
		}
	}

	while (true)
	{
		cout << "Выберетие параметр:" << endl
			<< "1. Город" << endl
			<< "2. Владелец" << endl
			<< "3. Цена" << endl
			<< "4. Жилая площадь" << endl
			<< "5. Год постройки" << endl
			<< "6. Кол-во этажей" << endl
			<< "7. Имя посёлка" << endl;

		int whatChange;
		cin >> whatChange;

		system("CLS");

		switch (whatChange)
		{
		case 1:
		{
			cout << "Введите новый город: ";
			string newAddress;
			cin >> newAddress;
			current->data.setCity(newAddress);
			return;
		}

		case 2:
		{
			cout << "Введите нового владельца: ";
			string newOwner;
			cin >> newOwner;
			current->data.setOwner(newOwner);
			return;
		}

		case 3:
		{
			cout << "Введите новую цену: ";
			float newPrice;
			cin >> newPrice;
			current->data.setPrice(newPrice);
			return;
		}

		case 4:
		{
			cout << "Введите новую жилую площадь: ";
			float newLivingSpace;
			cin >> newLivingSpace;
			current->data.setLivingSpace(newLivingSpace);
			return;
		}

		case 5:
		{
			cout << "Введите новый год постройки: ";
			int newYearBuilt;
			cin >> newYearBuilt;
			current->data.setYearBuilt(newYearBuilt);
			return;
		}

		case 6:
		{
			cout << "Введите новое кол-во этажей: ";
			int newFloorsAmount;
			cin >> newFloorsAmount;
			current->data.setFloorsAmount(newFloorsAmount);
			return;
		}

		case 7:
		{
			cout << "Введите новое имя посёлка: ";
			string newNameOfVillage;
			cin >> newNameOfVillage;
			current->data.setNameOfVillage(newNameOfVillage);
			return;
		}

		case 0:
			return;
		}
	}
}

template<>
void Ring<Country>::changeData(int index)
{
	Node<Country>* current = head;

	if (current->next != head)
	{
		for (int i = 0; i < index; i++)
		{
			current = current->next;
		}
	}

	while (true)
	{
		cout << "Выберетие параметр:" << endl
			<< "1. Город" << endl
			<< "2. Владелец" << endl
			<< "3. Цена" << endl
			<< "4. Жилая площадь" << endl
			<< "5. Год постройки" << endl
			<< "6. Кол-во этажей" << endl
			<< "7. Расстояние от города" << endl;

		int whatChange;
		cin >> whatChange;

		system("CLS");

		switch (whatChange)
		{
		case 1:
		{
			cout << "Введите новый город: ";
			string newAddress;
			cin >> newAddress;
			current->data.setCity(newAddress);
			return;
		}

		case 2:
		{
			cout << "Введите нового владельца: ";
			string newOwner;
			cin >> newOwner;
			current->data.setOwner(newOwner);
			return;
		}

		case 3:
		{
			cout << "Введите новую цену: ";
			float newPrice;
			cin >> newPrice;
			current->data.setPrice(newPrice);
			return;
		}

		case 4:
		{
			cout << "Введите новую жилую площадь: ";
			float newLivingSpace;
			cin >> newLivingSpace;
			current->data.setLivingSpace(newLivingSpace);
			return;
		}

		case 5:
		{
			cout << "Введите новый год постройки: ";
			int newYearBuilt;
			cin >> newYearBuilt;
			current->data.setYearBuilt(newYearBuilt);
			return;
		}

		case 6:
		{
			cout << "Введите новое кол-во этажей: ";
			int newFloorsAmount;
			cin >> newFloorsAmount;
			current->data.setFloorsAmount(newFloorsAmount);
			return;
		}

		case 7:
		{
			cout << "Введите новое расстояние от города: ";
			int newDistanceFromCity;
			cin >> newDistanceFromCity;
			current->data.setDistanceFromCity(newDistanceFromCity);
			return;
		}

		case 0:
			return;
		}
	}
}

template<>
void Ring<Ground>::changeData(int index)
{
	Node<Ground>* current = head;

	if (current->next != head)
	{
		for (int i = 0; i < index; i++)
		{
			current = current->next;
		}
	}

	while (true)
	{
		cout << "Выберетие параметр:" << endl
			<< "1. Город" << endl
			<< "2. Владелец" << endl
			<< "3. Цена" << endl
			<< "4. Площадь земельного участка" << endl;

		int whatChange;
		cin >> whatChange;

		system("CLS");

		switch (whatChange)
		{
		case 1:
		{
			cout << "Введите новый город: ";
			string newAddress;
			cin >> newAddress;
			current->data.setCity(newAddress);
			return;
		}

		case 2:
		{
			cout << "Введите нового владельца: ";
			string newOwner;
			cin >> newOwner;
			current->data.setOwner(newOwner);
			return;
		}

		case 3:
		{
			cout << "Введите новую цену: ";
			float newPrice;
			cin >> newPrice;
			current->data.setPrice(newPrice);
			return;
		}

		case 4:
		{
			cout << "Введите новую площадь земельного участка: ";
			float newLandSquare;
			cin >> newLandSquare;
			current->data.setLandSquare(newLandSquare);
			return;
		}

		case 0:
			return;
		}
	}
}