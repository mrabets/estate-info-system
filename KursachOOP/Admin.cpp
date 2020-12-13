#include "Admin.h"

Admin::Admin()
{
	login = "admin";
	password = "admin";
}

Admin::Admin(string login, string password)
{
	this->login = login;
	this->password = password;
}

string Admin::getLogin()
{
	return login;
}

string Admin::getPassword()
{
	return password;
}

ostream& operator<<(ostream& out, Admin& obj)
{
	return out << setw(12) << obj.login << setw(12) << obj.password << "\n";
}

istream& operator>>(istream& in, Admin& obj)
{
	return in >> obj.login >> obj.password;
}
