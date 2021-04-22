#include "Login.h"

int Login::callback(void* notUsed, int resultAmount, char** values, char** column)
{
	return 0;
}

Login::Login()
{  

	string* tempUString = new string;
	string* tempPString = new string;

	cout << "Enter in your Username: ";
	cin >> *tempUString;

	cout << "Enter in your Password: ";
	cin >> *tempPString;

	this->userName = *tempUString;
	this->password = *tempPString;

	delete tempUString;
	delete tempPString;
}

Login::~Login()
{
}

string Login::getUserName()
{
	return userName;
}

string Login::getUserPassword()
{
	return password;
}

// Check user's id & password with the database to check for a match
bool Login::loginChecker()
{
	DB_Connect* tempDB = new DB_Connect();  //creates db connection
	bool* validation = new bool(false);
	int* currentLocation = new int(0);
	string* inputUserName = new string();
	string* inputUserPassword = new string();
	User* tempUser = new User();

	/* do we need a User object function to take in the parameter of a Database in User.cpp?
	*  in Login.cpp, created tempUser as search critera for find_In_DB_Table() function
	*
	*	Goal:
	*		Access to User DB Table without granting full access to end-user before validation
	*
	*/


	*inputUserName = getUserName();
	*inputUserPassword = getUserPassword();

	// ?Insert SQL Statement here? String represents the User at currentline location in UserTable.h file
	if (this->queryFrom("user_table", "f_name", "where f_name=" + "*inputUserName")

	{
		// SELECT statement to search
		*tempUser = User::find_In_DB_Table(); //searches user table
		//search user db table for password match
		if (*inputUserPassword == *tempUser.getPassword())							   
		{
			*validation = true;
			this->validatedUser = *tempUser;
		}
	}
	else
	{
		*validation = false;
		cout << "User not found!!!" << endl;
		*currentLocation++;
	}

	delete currentLocation, inputUserName, inputUserPassword, tempUser;  //for memory & security management

	return *validation;
}

// if loginChecker = true; enter db
void Login::enterDB(bool validated, DB_Connect& database)
{
	if (validated == true)
	{
		database; //connect to DB
	}
}


//
//#include "Login.h"
//
//Login::Login()
//{
//	string* tempUString = new string;
//	string* tempPString = new string;
//
//	cout << "Enter in your Username: ";
//	cin >> *tempUString;
//
//	cout << "Enter in your Password: ";
//	cin >> *tempPString;
//
//	this->userName = *tempUString;
//	this->password = *tempPString;
//
//	delete tempUString;
//	delete tempPString;
//}
//
//Login::~Login()
//{
//}
//
//string Login::getUserName()
//{
//	return userName;
//}
//
//string Login::getUserPassword()
//{
//	return password;
//}
//
//// Check user's username & password with the database to check for a match
//bool Login::loginChecker(DB_Connect& database)  //pass database in main function
//{
//	DB_Connect* tempDB = new DB_Connect();
//	bool* validation = new bool;
//	int* currentLocation = 0;
//	string* inputUserName = new string;
//	string* inputUserPassword = new string;
//	User* tempUser = new User;
//
//	tempDB = database;
//
//	/* do we need a User object function to take in the parameter of a Database in User.cpp?
//	*  in Login.cpp, created tempUser as search critera for find_In_DB_Table() function
//	*
//	*	Goal:
//	*		Access to User DB Table without granting full access to end-user before validation
//	*
//	*/
//
//
//	* inputUserName = getUserName();
//	*inputUserPassword = getUserPassword();
//
//	// ?Insert SQL Statement here? String represents the User at currentline location in UserTable.h file
//	if (*inputUserName == "User::find_In_DB_Table() open user db table to search for existing username ")
//	{
//		*tempUser = User::find_In_DB_Table(); //searches user table
//		//search user db table for password match
//		if (*inputUserPassword == *tempUser.getPassword()) //???can Catie include getPassword() in User.h file???								   
//		{
//			*validation = true;
//			this->validatedUser = *tempUser;
//		}
//	}
//	else
//	{
//		*validation = false;
//		cout << "User not found!!!" << endl;
//		*currentLocation++;
//	}
//
//	delete currentLocation, inputUserName, inputUserPassword, tempUser;  //for memory & security management
//
//	return *validation;
//}
//
//// if loginChecker = true; enter db
//void Login::enterDB(bool validated, DB_Connect& database)
//{
//	if (validated == true)
//	{
//		database; //connect to DB
//	}
//}
//
//





