#pragma once
#include <string>
#include <iostream>
#include <regex>
#define WIN32_LEAN_AND_MEAN     //the header windows.h defines a lot of data types, which causes conflict. This line fixes that. 
#include <windows.h>
#include <conio.h>	//bad word here.......NSFW.  Give me a safe word. 
#include <string>
#include "Events.h" //check the outputMsg().  I included this header just to give this function some special functionatily.  
using namespace std;

enum colors { WHITE = 7, BLUE = 9, GREEN = 10, RED = 12 };
enum margins{MARGIN_0 = 0, MARGIN1 = MARGIN_0 + 5, MARGIN2 = MARGIN1 + 20, 
				       POS_OFFSET = 5, POS_MESSAGES = 0, POS_BAR = POS_OFFSET + 1, POS_TITLE = POS_BAR + 2 };

class Menu
{
	
public:

	//regex expression to check input.
	regex checkNames = regex("^[\\w\\s]+$");
	regex checkPartNumbers = regex("^[\\w\\s\\-\\_]+$");
	regex checkMoney = regex("^\\d+(,\\d{3})*(\\.\\d*)?$");
	string checkInput(string str, regex match); // if the regex matches, it returns the string, otherwise it returns "invalid data"
	string bar = "\xb0\xb0\xb0\xb0\xb0\xb0\xb0";

	//this is the menus line position.
	const int positions[15] = { 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25, 27, 29, 31, 33  };

	//this is the default color for each line position. When the color changes, it gets stored here. 
	int Set[15] = { WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE }; // DEFAULT COLORS
	void gotoxy(int x, int y); //tells the curson where to go in the screen
	void setColor(int color);	//sets the color of the line where the cursor is at
	string clearLine(int howManyLines = 1); //this super important function overwrites x amount of lines with white spaces. it clears entire screen sections to make them glitch free, then print to them.
	void printWhiteBar(int margin, int position);
	
	//these functions are for building sqlite statements
	string addComma(string data);						//adds a comma ar the end of the string. 
	string addQuotes(string data, bool comma = true);	//adds quotes and a comma by default, unless false is passed as a second argument.
	string buildFields(string fields[], int size);		//pass the array, and it returns a formated sqlite field statement
	string buildData(string data[], int size);			//NEEDS WORK.  It works but it has no way to know if something is a string or int, or double. 
	
	//this function generates a menu line.  TEXT, Where to Store the Input, position for menu, position for data to be collected, position in y, and the color of the line.  
	void menuLine(string& menuText, string storedInput, int margin, int margin2, int position, int color);

	//actually collects the data from the menu line.  
    void getMenuLine(string& data, int margin, int position);

	void outputMsg(string msg=""); //use to either output to the msg field, or prime to the right place
    


};

