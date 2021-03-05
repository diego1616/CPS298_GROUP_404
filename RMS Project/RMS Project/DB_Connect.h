#pragma once
#include <iostream>
#include <sqlite3.h>
#include <string>
//#include "EventLog"  //class to be added later in order log certain events.  This can be useful for troubleshooting purposes. 

using namespace std;

class DB_Connect
{
	string dbName = "databases\\retail.db";
	string logFile = "logs\\dbConnectLog";
	bool connectionStatus;

public:

	sqlite3* sqLiteDB;	//public for now, but will have to be private later on. 

	DB_Connect();
	~DB_Connect();

	//CRUD methods here

	void callback(void *notUsed, int resultAmount, char** values, char** column);

	void insertInto(string table, string fields, string values, string condition = "");
	void queryFrom(string table, string fields, string condition = "");


};

