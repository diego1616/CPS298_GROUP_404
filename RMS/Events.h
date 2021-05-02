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


class EventLog {

	string path = "chronicles\\";
	string fileName;
	string extension = ".log";
	TimeStamp watch;
	ofstream chronicle;

	bool fileStatus;

	static int msgColor;
	static int lineCount;
	static void checktLineCount(bool reset = false);

public:
	
	//may have to overload a few constructors.
	EventLog(string msg = "");
	~EventLog();

	static bool sync;
	static void setSync();
	static void unsetSync();

	static void makePath(string path = "");
	void logEvent(string msg="", bool print=true);
};


