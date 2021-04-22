#pragma once
#include <iostream>
#include <string>
#include "User.h"

using namespace std;

class Login: public DB_Connect
{
private:
	int callback(void* notUsed, int resultAmount, char** values, char** column);
	User* validatedUser = new User();
	string userName = "";
	string password = "";

public:
	Login();
	~Login();

protected:
	// Get the username and password from user
	string getUserName();
	string getUserPassword();

	//Functions to operate with the database system
	bool loginChecker();
	//void enterDB(bool validated);
};

