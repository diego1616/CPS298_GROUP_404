#include "Events.h"
#pragma warning(disable : 4996)

//record the time the object is created
TimeStamp::TimeStamp()
{
	start = chrono::system_clock::now();
}

//create a time_point object pointing to now and return it. 
string TimeStamp::now(const char* format)
{

	if (format == "")
		return "Events::TimeStamp::now() - Bad Function Call";

	else {
		//create a time_point object based on the system clock
		chrono::time_point<chrono::system_clock> nowTimePoint = chrono::system_clock::now();

		//current time using chrono. there are other ways to get it. 
		time_t myTime = chrono::system_clock::to_time_t(nowTimePoint);

		//tm is predefined struct from c++.  Assign the current time by means of the local time function. 
		tm* curr_tm = localtime(&myTime);

		//the size is the max size of the string
		char rString[30];

		//strftime is a predefined function to print dates and time
		strftime(rString, sizeof(rString), format, curr_tm);

		return (const char*)rString;
	}

}

//return a string with the current time
string TimeStamp::nowTime()
{
	string currentTime = this->now("%H:%M:%S");
	return currentTime;
}

//return string with current date
string TimeStamp::nowDate() {

	string currentTime = this->now("%Y-%b-%d");

	return currentTime;
}

//use this function to find out the time from object creation to now
double TimeStamp::nowtimer()
{
	chrono::time_point <chrono::system_clock> stop = chrono::system_clock::now();

	chrono::duration<double> currentTimer = stop - this->start;

	return currentTimer.count();
}


//constructor meant to create folder paths, create a file with today's date, and write to it if needed.
//The object can be used to keep on writing if needed by means of other functions. 
EventLog::EventLog(string msg)
{
	this->fileName = "log "+ this->watch.nowDate() + this->extension;
	this->logEvent(msg);
}

EventLog::~EventLog()
{
	chronicle.close();
}

bool EventLog::sync = false;

void EventLog::setSync()
{
	sync = true;
}

void EventLog::unsetSync()
{
	sync = false;
}

//creates a file path if it doesnt exist
void EventLog::makePath(string path) {

	std::filesystem::path dir(path);

	if (path == "")
		return;

	else if (!(std::filesystem::exists(dir)))
		std::filesystem::create_directories(dir);
}

int EventLog::msgColor = WHITE;
int EventLog::lineCount = 0;

void EventLog::checktLineCount(bool reset)
{
	if(reset)
		EventLog::lineCount = 0;
	else if (EventLog::lineCount >= (MSG_FIELD - 1)) {
		EventLog::lineCount = 0;
		if(EventLog::msgColor == WHITE)
			EventLog::msgColor = BLUE;
		else
			EventLog::msgColor = WHITE;
	}

}

void EventLog::logEvent(string msg, bool print) {
	
	Menu display;
	int count = 0;

	//display.prepField(MSG_FIELD_POS, MSG_FIELD);

	try {

		if (msg == "")
			return;

		EventLog::makePath(path);

		if (!this->chronicle.is_open())
			this->chronicle.open((this->path + this->fileName), ios::app);

		if (this->chronicle.fail())
			throw runtime_error(LOG_ERROR);
		
		else {
						
			if (print) {
				
				//wait up to three seconds if other function is printing a msg
				while (sync) {
					this_thread::sleep_for(chrono::milliseconds(20));
					count++;

					if (count >= 3)
						break;
				}

				setSync();

				EventLog::checktLineCount();
				display.gotoxy(MARGIN_0, MSG_FIELD_POS + EventLog::lineCount); 
				display.clearLine(1);
				display.gotoxy(MARGIN_0, MSG_FIELD_POS + EventLog::lineCount);
				EventLog::lineCount++;

				display.setColor(EventLog::msgColor);
				cout << this->watch.nowTime() + (string)" - " + msg << endl;
				this_thread::sleep_for(chrono::milliseconds(50)); //this ensure each message is display for this many seconds before being deleted. 
				
				unsetSync();
			}
			this->chronicle << this->watch.nowTime() << " - " << msg << endl;
		}

		this->chronicle.close();
	}
	catch (exception e) {
		cout << e.what() << "Events::logEvent()" << endl;
		this->chronicle.close();
		return;
	}
}
