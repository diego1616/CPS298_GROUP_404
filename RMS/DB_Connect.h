#pragma once
#include <iostream>
#include "sqlite_dependencies/sqlite3.h"
#include <string>
#include "Events.h"
#include "DB_Literals.h"
#include "DB_Tables.h"
#include <vector>

using namespace std;

class DB_Connect
{
	string path = "databases\\";
	string dbName = "retail.db";
	EventLog log;
	bool connectionStatus;
	sqlite3* sqLiteDB;
	
	vector<string> columns;
	vector<string> data;

public:
		
	DB_Connect();
	~DB_Connect();

	//CRUD methods here

	//helper function for queries
	static int callback(void *notUsed, int resultAmount, char** values, char** column);

	void query(string& statement);//use if you already have a sqlite statement
	void insertInto(string table, string fields, string values, string condition = "");
	void queryFrom(string table, string fields, string condition = "");
	void getTables();
	bool generalQuery(string& search_What, string table="");
	void someTestDanMade();
};

