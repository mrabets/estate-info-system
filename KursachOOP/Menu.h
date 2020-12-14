#pragma once

#include "Admin.h"
#include "User.h"

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

class Menu
{
public:
	void pointOfEntry();

private:
	void typeChoosing();

	void userMenu();
	bool isUserAuthorization();
	void userRegistration();
	void userFileCreating();

	void viewEstateFile();
	void searchEstateFile();

	void adminMenu();
	bool isAdminAuthorization();
	void adminRegistration();
	void userManage();
	void adminFileCreating();

	string encryptDecrypt(string toEncrypt);
};

