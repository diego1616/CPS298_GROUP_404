#include "DB_Connect.h"

DB_Connect::DB_Connect() {

	int check1 = 0, check2 = 0;
	string str;
	DB_Tables tables;
	char* error = new char();	//error message if writing to db
	
	log.logEvent(DB_OPENING, true);
	str = this->path + this->dbName;

	//check if the doesn't database exist.
	if (!filesystem::exists(str)) {
		log.logEvent(DB_MISSING, true);
		log.makePath(this->path);
	}
	
	//Open or create database, and create tables. Old data will not be overwriten if already exists.
	check1 = sqlite3_open(str.c_str(), &this->sqLiteDB);
	check2 = sqlite3_exec(this->sqLiteDB, tables.all_Tables.c_str(), NULL, NULL, &error);

	// Test for error opening database
	if (check1) {
		str = sqlite3_errmsg(sqLiteDB);
		connectionStatus = false;
		log.logEvent(DB_ERROR + str, true);
	}
	else if (check2) {
		str = error;
		connectionStatus = false;
		log.logEvent(DB_WRITE_ERROR + str, true);
	}
	else {
		connectionStatus = true;
		log.logEvent(DB_OPENED, true);
	}

	if (!this->connectionStatus) {
		//Close the database
		sqlite3_close(this->sqLiteDB);
		sqLiteDB = nullptr;
		log.logEvent(DB_CLOSED, true);
	}


}

DB_Connect::~DB_Connect() {

	//Close the database
	sqlite3_close(this->sqLiteDB);
	sqLiteDB = nullptr;
	log.logEvent(DB_CLOSED,true);
			
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
		cout << DB_WRITE_ERROR << e.what() << endl;
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
			cout << DB_READ_ERROR << e.what() << endl;
	}

}
