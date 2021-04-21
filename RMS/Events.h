#pragma once
#include <iostream>
#include <fstream>
#include <filesystem>
//DO NOT USE <experimental/filesystem>, use <filesystem> then project_properties/C/C++/Language/C++ language standard = ISO C++17 Standard (/std:c++17)
#include <string>
#include <chrono>
#include <thread>
#include "Menu.h"

using namespace std;

//standard errors and messages. 
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

	static bool sync;
	static void setSync();
	static void unsetSync();

	static void makePath(string path = "");
	void logEvent(string msg="", bool print=false);
};


