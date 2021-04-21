#pragma once
#include <iostream>
#include "sqlite_dependencies/sqlite3.h"
#include <string>
#include "Events.h"
#include "DB_Literals.h"
#include "DB_Tables.h"
#include <vector>

using namespace std;

//standard errors and messages. 
#define DB_OPENING "CONNECTING TO DATABASE.... "
#define DB_OPENED "SUCESS! DATABASE IS OPENED "
#define DB_CLOSED "DATABASE IS CLOSED "
#define DB_ERROR "DATABASE CONNECTION ERROR "
#define DB_WRITE_ERROR "ILLEGAL DATABASE DATA "
#define DB_READ_ERROR "UNABLE TO READ FROM DATABASE "
#define DB_MISSING "DATABASE MISSING! AN EMTPY DATABASE HAS BEEN CREATED "
#define DB_INSERT_OK "DATABASE UPDATED"

#define USER_CREATED(X) "USER WAS CREATED SUCESSFULLY: " + (string)X
#define USER_DELETED(X) "USER WAS DELETED SUCESSFULLY: " + (string)X
#define USER_UPDATED(X) "USER WAS UPDATED SUCESSFULLY: " + (string)X
#define USER_LOGIN(X) "USER SESSION START: " + (string)X
#define USER_LOGIN_FAILURE(X) "USER SESSION COULD NOT BE STARTED: " + (string)X
#define USER_LOCKED(X) "USER ACCOUNT IS LOCKED: " + (string)X

#define PRODUCT_ADDED(X) "PRODUCT ADDED: " + (string)X
#define PRODUCT_DELETED(X) "PRODUCT DELETED: " + (string)X
#define PRODUCT_UPDATED(X) "PRODUCT UPDATED: " + (string)X

#define LOG_ERROR "UNABLE TO OPEN OR WRITE TO LOG FILE "

class DB_Connect
{
	string path = "databases\\";
	string dbName = "retail.db";
	EventLog log;
	bool connectionStatus;
	
	
	vector<string> columns;
	vector<string> data;

public:
	sqlite3* sqLiteDB;

	DB_Connect();
	~DB_Connect();

	//int lastQueryRows;

	//CRUD methods here

	//helper function for queries
	static int callback(void* notUsed, int resultAmount, char** values, char** column);
	static const char* prod_id;

	void query(string& statement);//use if you already have a sqlite statement
	void insertInto(string table, string fields, string values, string condition = "");
	void queryFrom(string table, string fields, string condition = "");
	void getTables();
	bool generalQuery(string& search_What, string table = "");
	string createUpdateString(string table, string fields_and_values, string condition);
	string createSearchString(string fields, string table, string column, string search_keyword);
	string createDeleteString(string table, string condition = "");
	void dbUpdate(string sql);
	void dbSearch(string sql);


};
