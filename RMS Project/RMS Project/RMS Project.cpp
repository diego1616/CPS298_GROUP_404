#include <iostream>
#include "DB_Connect.h"


int main()
{
	DB_Connect dataBase;
	char* error = new char(), * error2 = new char();

	string myq = "CREATE TABLE USERS(\
		USER_ID INT PRIMARY KEY NOT NULL, \
		FIRST_NAME VARCHAR(50) NOT NULL, \
		LAST_NAME VARCHAR(50) NOT NULL, \
		TITLE_ID INT NOT NULL,	\
		DEPARTMENT_ID INT NOT NULL,	\
		PASSWORD VARCHAR(50) NOT NULL);";

	system("pause");

	sqlite3_exec(dataBase.sqLiteDB, myq.c_str(), NULL, NULL, &error);

	cout << "Error = " << error << endl;

	system("pause");

	string myq2 = ".schema USERS";

	sqlite3_exec(dataBase.sqLiteDB, myq2.c_str(), NULL, NULL, &error2);

	cout << "Error = " << error << endl;

	system("pause");

	dataBase.insertInto("USERS", "FIRST_NAME, LAST_NAME, TITLE_ID, DEPARTMENT_ID, PASSWORD", "diego, perez, 123, 456, beer789");

	system("pause");

	dataBase.queryFrom("USERS", "*");

	system("pause");


	return 0;
}


