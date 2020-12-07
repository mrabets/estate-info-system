#pragma once

#include <iostream>
#include <iomanip>

using namespace std;

class User
{
public:
	User();
	User(string login, string password, int age, char sex, string phone, string email);

	string getLogin();

	friend ostream& operator << (ostream& out, User& obj);
	friend istream& operator >> (istream& in, User& obj);

private:
	string login;
	string password;
	int age;
	char sex;
	string phone;
	string email;
};