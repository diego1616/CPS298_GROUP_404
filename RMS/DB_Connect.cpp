#include "DB_Connect.h"
#include "DB_Literals.h"
#include <cstring>
#include "AddProduct.h"
#include "StockLevel.h"

DB_Connect::DB_Connect() {
	
	EventLog log;

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
	EventLog log;
	//Close the database
	sqlite3_close(this->sqLiteDB);
	sqLiteDB = nullptr;
	log.logEvent(DB_CLOSED, true);

}

int DB_Connect::accessLevel = 0;

bool DB_Connect::setAcess(int level, string who)
{
	EventLog log;

	if (level > 0 || level <= 3)
		if (who != NOT_FOUND && who != "")
		{
			DB_Connect::accessLevel = level;
			log.logEvent(USER_LOG_OK(who));
			return true;
		}
		else {
			log.logEvent(USER_LOG_BAD(who));
			return false;
		}
	else {
		log.logEvent(WRONG_ACCESS_LEVEL);
		return false;
	}
}

int DB_Connect::getAcess()
{
	return DB_Connect::accessLevel;
}

//this function works well, but it does not display records nicely.  Rather than fixing it, I have used Dans function, who worked on this issue already. 
int DB_Connect::callback(void* notUsed, int resultAmount, char** values, char** column)
{
	for (int i = 0; i < resultAmount; i++)
	{

		cout << column[i] << ":\t" << ((values[i] == nullptr) ? "NULL" : values[i]) << endl;


	}

	return 0;
}

void DB_Connect::insertInto(string table, string fields, string values, string condition)
{
	EventLog log;
	//add code to check for sql injection attacks

	char* error;
	int check;

	try {
		string statement = "INSERT INTO " + table + "(" + fields + ") VALUES(" + values + ")" + condition + ";";

		log.logEvent("INSERT STATEMENT: " + statement);

		check = sqlite3_exec(this->sqLiteDB, statement.c_str(), NULL, NULL, &error);

		if (check != SQLITE_OK)
			throw logic_error(error);
		
	}
	catch (exception e)
	{
		log.logEvent(DB_WRITE_ERROR + (string)" " + (string)e.what());

	}
	catch (int e) {

		log.logEvent(DB_WRITE_ERROR + (string)" " + to_string(e));
	
	}

}

void DB_Connect::query(string& statement)
{
	EventLog log;

	if (statement == "")
		return;

	//add code to check for sql injection attacks
	try {


		char* error;
		int check;

		log.logEvent("DB_Connect::query() SQLITE STATEMENT: " + statement);
		this_thread::sleep_for(chrono::milliseconds(3000));
		
		Menu display;

		//ideally, there would be a way to know how many results and clear up until then. For now I am guessing 60 lines. 
		display.prepField(QUERY_FIELD_POS, 60);

		check = sqlite3_exec(this->sqLiteDB, statement.c_str(), &DB_Connect::callback, NULL, &error);

		display.gotoxy(MARGIN_0, MSG_FIELD_POS);

		if (check != SQLITE_OK)
			throw logic_error(error);
	}
	catch (exception e)
	{
		log.logEvent(DB_READ_ERROR + (string)" " +(string)e.what());
	}
}


//this function works well, but it does not display so nice.  Rather than fixing it, I have used Dans function, who worked on this issue already. 
//void DB_Connect::queryFrom(string table, string fields, string condition)
//{
//	string statement = "SELECT " + fields + " FROM " + table + condition + ";";
//	this->query(statement);
//}

void DB_Connect::queryFrom(string table, string fields, string condition)
{
	string statement = "SELECT " + fields + " FROM " + table + condition + ";";

	this->dbSearch(statement);
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


string DB_Connect::createSearchString(string fields, string table, string column, string search_keyword) {
	string sql = "SELECT " + fields + " FROM " + table + " WHERE " + column + " LIKE '%" + search_keyword + "%';";
	return sql;
}


string DB_Connect::createUpdateString(string table, string fields_and_values, string condition) {
	string sql = "UPDATE " + table + " SET " + fields_and_values + " WHERE " + condition + ";";
	return sql;
}

string DB_Connect::createDeleteString(string table, string condition) {
	string prepared_condition = condition;

	if (condition != "") {
		prepared_condition = " WHERE " + condition;
	}

	string sql = "DELETE FROM " + table + prepared_condition + ";";
	return sql;
}


// Copied from the insert function above
void DB_Connect::dbUpdate(string sql) {

	EventLog log;
	char* error;
	int check;

	try {
		string statement = sql;

		log.logEvent("UPDATE STATEMENT: " + statement);
		
		check = sqlite3_exec(this->sqLiteDB, statement.c_str(), NULL, NULL, &error);

		if (check != SQLITE_OK) {
			throw logic_error(error);
		}
	}
	catch (exception e) {

		log.logEvent(DB_WRITE_ERROR + (string)" " + (string)e.what());
	}
}

//this is the old someTestDanMade function. 
void DB_Connect::dbSearch(string sql) {
	// TODO: pass arrays of columns and eventually search criteria into function for parsing and formatting (add '' and , where needed)
// "+product_table::product_id+","+product_table::item_name+"
	sqlite3_stmt* sql_statement;
	// string sql = "SELECT " + fields + " FROM " + table + " " + condition + ";";

	Menu display;

	//ideally, there would be a way to know how many results and clear up until then. For now I am guessing 60 lines. 
	display.prepField(QUERY_FIELD_POS, 60);
	display.setColor(GREEN);
	
	int statement_length = (int)strlen(sql.c_str());

	int prep = (int)sqlite3_prepare_v2(this->sqLiteDB, sql.c_str(), statement_length, &sql_statement, NULL);
	int step = 0; // new int(0)

	if (prep == SQLITE_OK) {

		// Print basic header row
		// another comment
		for (int header = 0; header < sqlite3_column_count(sql_statement); header++) {
			cout << left << setw(17) << sqlite3_column_name(sql_statement, header);
		}
		cout << endl;
		// end basic header row

		// for (int header = 0; header < sqlite3_column_count(sql_statement); header++) {
		// 	string humanized_header = "";
		// 	const char* col_header = sqlite3_column_name(sql_statement, header);
		// 	for (int i = 0; i < sizeof(*table_fields); i++) {
		// 		if (*table_fields[i][0] == col_header) {
		// 			humanized_header = *table_fields[i][1];
		// 			break; // not absolutely necessary, but avoids extra iterations
		// 		}
		// 	}
		// 	cout << left << setw(25) << humanized_header;
		// }
		// cout << endl; 
		// // end header row

		while (step != SQLITE_DONE) {
			step = sqlite3_step(sql_statement);
			if (step == SQLITE_ROW) {
				// print data row
				for (int cell = 0; cell < sqlite3_column_count(sql_statement); cell++) {
					if (char* col_val = (char*)sqlite3_column_text(sql_statement, cell)) { // NB: NULL cell values will break the function prematurely; those are handled below
						cout << left << setw(17) << col_val;
					}
					else if (sqlite3_column_type(sql_statement, cell) == SQLITE_NULL) {
						cout << left << setw(17) << "NULL";
					}
				}
				cout << endl;
				// end data row
			}
		}
		display.gotoxy(MARGIN_0, MSG_FIELD_POS);//this way you are not at the bottom of the results, which is annoying
	}
	else {
		const char* error_message = sqlite3_errmsg(this->sqLiteDB);
	}
	sqlite3_finalize(sql_statement);
}

//use this function to get a single data field from the DB.  Pass a string variable by reference, and the result will be there. 
void DB_Connect::dbSearch(string sql, string& data) {

	sqlite3_stmt* sql_statement;
	bool check = true;

	EventLog log(sql);
	int statement_length = (int)strlen(sql.c_str());

	int prep = sqlite3_prepare_v2(sqLiteDB, sql.c_str(), statement_length, &sql_statement, NULL);
	int step = 0; // new int(0)

	if (prep == SQLITE_OK) {

		step = sqlite3_step(sql_statement);

		if (step == SQLITE_ROW)
		{
			char* col_val = (char*)sqlite3_column_text(sql_statement, 0);

			if (sqlite3_column_type(sql_statement, 0) != SQLITE_NULL)  // NB: NULL cell values will break the function prematurely; those are handled below
				data = col_val;
			else	//something was found, but it was NULL
				data = NULL_FIND;

		}
		else if (step == SQLITE_DONE) 	//this means nothing was found.  Nothing wrong with the query, just nothing found.
			data = NOT_FOUND;
		
	}
	else {
		const char* error_message = sqlite3_errmsg(this->sqLiteDB);
		log.logEvent(error_message);
	}
	sqlite3_finalize(sql_statement);

}