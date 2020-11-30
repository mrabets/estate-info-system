#pragma once

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
		cout << "Ring is empty" << endl;
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
		cout << "Ring is empty" << endl;
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
		cout << "Ring is empty" << endl;
		return;
	}

	while (size)
	{
		deleteFirst();
	}

	cout << "Successful deletion" << endl;
}

template<class T>
void Ring<T>::display()
{
	if (head == nullptr)
	{
		cout << "Ring is empty" << endl;
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

template<>
void Ring<NewBuilding>::display()
{
	if (head == nullptr)
	{
		cout << "Ring is empty" << endl;
		return;
	}

	cout << setw(10) << "MODEL" << setw(10) << "BATTERY" << setw(10) << "MATRIX" << endl;

	Node<NewBuilding>* current = head;
	while (current->next != head)
	{
		cout << current->data;
		current = current->next;
	}

	cout << current->data;
}

template<>
void Ring<SecondaryHousing>::display()
{
	if (head == nullptr)
	{
		cout << "Ring is empty" << endl;
		return;
	}

	cout << setw(10) << "MODEL" << setw(10) << "BATTERY" << setw(10) << "STYLUS" << endl;

	Node<SecondaryHousing>* current = head;
	while (current->next != head)
	{
		cout << current->data;
		current = current->next;
	}

	cout << current->data;
}

template<>
void Ring<Cottage>::display()
{
	if (head == nullptr)
	{
		cout << "Ring is empty" << endl;
		return;
	}

	cout << setw(10) << "MODEL" << setw(10) << "POWER" << setw(10) << "COLOUR" << endl;

	Node<Cottage>* current = head;
	while (current->next != head)
	{
		cout << current->data;
		current = current->next;
	}

	cout << current->data;
}

template<>
void Ring<Country>::display()
{
	if (head == nullptr)
	{
		cout << "Ring is empty" << endl;
		return;
	}

	cout << setw(10) << "MODEL" << setw(10) << "POWER" << setw(10) << "COLOUR" << endl;

	Node<Country>* current = head;
	while (current->next != head)
	{
		cout << current->data;
		current = current->next;
	}

	cout << current->data;
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
			<< "1. Адрес" << endl
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
			cout << "Введите новый адрес: ";
			string newAddress;
			cin >> newAddress;
			current->data.setAddress(newAddress);
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
			int newPrice;
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
			<< "1. Адрес" << endl
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
			cout << "Введите новый адрес: ";
			string newAddress;
			cin >> newAddress;
			current->data.setAddress(newAddress);
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
			int newPrice;
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
			<< "1. Адрес" << endl
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
			cout << "Введите новый адрес: ";
			string newAddress;
			cin >> newAddress;
			current->data.setAddress(newAddress);
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
			int newPrice;
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
			<< "1. Адрес" << endl
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
			cout << "Введите новый адрес: ";
			string newAddress;
			cin >> newAddress;
			current->data.setAddress(newAddress);
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
			int newPrice;
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
			<< "1. Адрес" << endl
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
			cout << "Введите новый адрес: ";
			string newAddress;
			cin >> newAddress;
			current->data.setAddress(newAddress);
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
			int newPrice;
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