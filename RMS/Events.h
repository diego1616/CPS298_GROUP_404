#pragma once
#include <iostream>
#include <fstream>
#include <filesystem>
//DO NOT USE <experimental/filesystem>, use <filesystem> then project_properties/C/C++/Language/C++ language standard = ISO C++17 Standard (/std:c++17)
#include <string>
#include <chrono>

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

//records creating time, and can print a timer to that time, or just print the time
class TimeStamp {

	chrono::time_point<chrono::system_clock> start;
	string now(const char* format = "");

public:

	TimeStamp();

	string nowTime();
	string nowDate();
	double nowtimer();

};


class EventLog {	//this class starts out very basic, but we need to add funcionality such as tapping into the user session.  
					//for now it will be just creating a file and a folder with the date on the name
	string path = "chronicles\\";
	string fileName;
	string extension = ".log";
	TimeStamp watch;
	ofstream chronicle;

	bool fileStatus;

public:
	
	//may have to overload a few constructors.
	EventLog(string msg = "");
	~EventLog();

	static void makePath(string path = "");
	void logEvent(string msg="", bool print=false);
};

