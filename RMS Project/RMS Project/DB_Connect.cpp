#include "DB_Connect.h"

DB_Connect::DB_Connect() {

	int database = 0;

	cout << "Opening database...." << endl;


	//opens or creates database
	database = sqlite3_open(this->dbName.c_str(), &this->sqLiteDB);

	// Test for error opening database
	if (database) {
		cout << "DB open error: " << sqlite3_errmsg(sqLiteDB) << endl;
		connectionStatus = false;
		//add code for log file
	}
	else {
		cout << "Opened database successfully!" << endl;
		connectionStatus = true;
		//add code for log file
	}

}

DB_Connect::~DB_Connect() {

	//Close the database
	sqlite3_close(this->sqLiteDB);

	sqLiteDB = nullptr;

	cout << "Closed database successfully!" << endl;
	//add code for log file
			
}

int DB_Connect::callback(void* notUsed, int resultAmount, char** values, char** column)
{

	for (size_t i = 0; i < resultAmount; i++)
	{
		cout << column[i] << ":\t" << values[i] << endl;
	}

	return 0;
}

void DB_Connect::insertInto(string table, string fields, string values, string condition)
{
	//add code to check for sql injection attacks

	char* error;
	int check;

	try {
		string statement = "INSERT INTO " + table + "(" + fields + ") VALUES(" + values + ")" + condition + ";";

		cout << "SQLITE STATEMENT: " << statement << endl;

		check = sqlite3_exec(this->sqLiteDB, statement.c_str(), NULL, NULL, &error);

		if (check != SQLITE_OK)
			throw logic_error(error);
	}
	catch (exception e) 
	{
		cout << "Something went wrong while creating user: " << e.what() << endl;
	}
	
}

void DB_Connect::queryFrom(string table, string fields, string condition)
{
	//add code to check for sql injection attacks

	char* error;
	int check;

	try {
		string statement = "SELECT " + fields + " FROM " + table + condition + ";";

		cout << "SQLITE STATEMENT: " << statement << endl;

		check = sqlite3_exec(this->sqLiteDB, statement.c_str(), &DB_Connect::callback, NULL, &error);

		if (check != SQLITE_OK)
			throw logic_error(error);
	}
	catch (exception e)
	{
			cout << "Something went wrong during query: " << e.what() << endl;
	}

}
