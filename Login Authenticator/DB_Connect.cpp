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
	log.logEvent(DB_CLOSED, true);

}

int DB_Connect::callback(void* notUsed, int resultAmount, char** values, char** column)
{
	for (size_t i = 0; i < resultAmount; i++)
	{

		cout << column[i] << ":\t" << ((values[i] == nullptr) ? "NULL" : values[i]) << endl;

		//inserting into the vectors for manipulation later.
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

void DB_Connect::query(string& statement)
{
	if (statement == "")
		return;

	//add code to check for sql injection attacks
	try {

		char* error;
		int check;

		cout << "DB_Connect::query() SQLITE STATEMENT: " << statement << endl;

		check = sqlite3_exec(this->sqLiteDB, statement.c_str(), &DB_Connect::callback, NULL, &error);

		if (check != SQLITE_OK)
			throw logic_error(error);
	}
	catch (exception e)
	{
		cout << DB_READ_ERROR << e.what() << endl;
	}
}

void DB_Connect::queryFrom(string table, string fields, string condition)
{
	string statement = "SELECT " + fields + " FROM " + table + condition + ";";
	this->query(statement);
}

void DB_Connect::getTables()
{
	string statement = "SELECT name FROM sqlite_master WHERE type='table';";
	this->query(statement);
}

bool DB_Connect::generalQuery(string& search_What, string table)
{
	//this function has not been tested, the code below is just a preview
	string statement = "SELECT name FROM sqlite_master WHERE LIKE='" + search_What + "';";

	return false;
}

void DB_Connect::someTestDanMade() {

	sqlite3_stmt* sql_statement;
	const char* sql = "SELECT * FROM product_table;";
	size_t statement_length = strlen(sql);

	int prep = sqlite3_prepare_v2(this->sqLiteDB, sql, statement_length, &sql_statement, NULL);

	if (prep == SQLITE_OK) {
		prep = sqlite3_step(sql_statement);

		for (int i = 0; i < 4; i++) {
			const char* col_val = (char*)sqlite3_column_text(sql_statement, i);
			cout << col_val << endl;
		}
	}
	else {
		const char* error_message = sqlite3_errmsg(this->sqLiteDB);
	}
}