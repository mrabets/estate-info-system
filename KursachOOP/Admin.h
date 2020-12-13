#pragma once

#include <iostream>
#include <iomanip>

using namespace std;

class Admin
{
public:
	Admin();
	Admin(string login, string password);

	string getLogin();
	string getPassword();

	friend ostream& operator << (ostream& out, Admin& obj);
	friend istream& operator >> (istream& in, Admin& obj);

private:
	string login;
	string password;
};

