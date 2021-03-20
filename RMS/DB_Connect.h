#pragma once
#include <iostream>
#include "sqlite_dependencies/sqlite3.h"
#include <string>
#include "Events.h"
#include "DB_Literals.h"
#include "DB_Tables.h"

using namespace std;

class DB_Connect
{
	string path = "databases\\";
	string dbName = "retail.db";
	EventLog log;
	bool connectionStatus;
	sqlite3* sqLiteDB;
	void query(string& statement);

public:
		
	DB_Connect();
	~DB_Connect();

	//CRUD methods here

	//helper function for queries
	static int callback(void *notUsed, int resultAmount, char** values, char** column);

	void insertInto(string table, string fields, string values, string condition = "");
	void queryFrom(string table, string fields, string condition = "");
	void getTables();
	void generalQuery(string& search_What);

};

