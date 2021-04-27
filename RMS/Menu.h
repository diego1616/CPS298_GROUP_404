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

//enum margins{MARGIN_0 = 0, MARGIN1 = MARGIN_0 + 5, MARGIN2 = MARGIN1 + 20, 
//				       POS_OFFSET = 5, POS_MESSAGES = 0, POS_BAR = POS_OFFSET + 1, POS_TITLE = POS_BAR + 2 };

enum offsets {
	VERTICAL_OFFSET = 0,
	HORIZOTAL_OFFSET = 0
};

enum margin {
	MARGIN_0 = 0 + HORIZOTAL_OFFSET,
	MARGIN_1 = 10 + HORIZOTAL_OFFSET,
	MARGIN_2 = 40 + HORIZOTAL_OFFSET,
};

enum fieldLength {
	MSG_FIELD = 5 + VERTICAL_OFFSET,
	BAR_FIELD = 2 + VERTICAL_OFFSET,
	TITLE_FIELD = 2 + VERTICAL_OFFSET,
	MENU_FIELD = 15 + VERTICAL_OFFSET
};

//I set it up this way, so that if you change the lenght of one field, the positions will be right.
enum fieldPosition {
	MSG_FIELD_POS = VERTICAL_OFFSET,										//0
	BAR_FIELD_POS = MSG_FIELD + VERTICAL_OFFSET,							//5 = 5
	TITLE_FIELD_POS = BAR_FIELD_POS + BAR_FIELD + VERTICAL_OFFSET,			//5 + 2 = 7
	MENU_FIELD_POS = TITLE_FIELD_POS + TITLE_FIELD + VERTICAL_OFFSET,		//7 + 1 = 9
	QUERY_FIELD_POS = MENU_FIELD_POS + MENU_FIELD + VERTICAL_OFFSET			//9 + 30  = 39			
};

class Menu
{
	
public:

	//regex expression to check input.
	regex checkNames = regex("^[\\w\\s]+$");
	regex checkPartNumbers = regex("^[\\w\\s\\-\\_]+$");
	regex checkMoney = regex("^\\d+(,\\d{3})*(\\.\\d*)?$");
	regex noCheck = regex(".*");

	string checkInput(string str, regex match); // if the regex matches, it returns the string, otherwise it returns "invalid data"
	string bar = "\xb0\xb0\xb0\xb0\xb0\xb0\xb0";

	//this is the menus line position.
	//const int positions[15] = { 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25, 27, 29, 31, 33  };
	const int positions[15] = { 0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28 };

	//this is the default color for each line position. When the color changes, it gets stored here. 
	int Set[15] = { WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE }; // DEFAULT COLORS
	void gotoxy(int x, int y); //tells the curson where to go in the screen
	void setColor(int color);	//sets the color of the line where the cursor is at
	void clearLine(int howManyLines = 1); //this super important function overwrites x amount of lines with white spaces. it clears entire screen sections to make them glitch free, then print to them.
	void prepField(int position, int length);
	void printWhiteBar(int where);
	
	//these functions are for building sqlite statements
	string addComma(string data);						//adds a comma ar the end of the string. 
	string addQuotes(string data, bool comma = true);	//adds quotes and a comma by default, unless false is passed as a second argument.
	string buildFields(string fields[], int size);		//pass the array, and it returns a formated sqlite field statement
	string buildData(string data[], int size);			//NEEDS WORK.  It works but it has no way to know if something is a string or int, or double. 
	
	//this function generates a menu line.  TEXT, Where to Store the Input, position for menu, position for data to be collected, position in y, and the color of the line.  
	void printMenuLine(string& menuText, string storedInput, int margin, int margin2, int position, int color);

	//actually collects the data from the menu line.  
    void getMenuLine(string& data, int margin, int position);

	void outputMsg(string msg=""); //use to either output to the msg field, or prime to the right place

	void bar_Title_Menu(string title = " ", string instructions = " ");
    


};

