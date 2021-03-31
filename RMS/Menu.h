#pragma once
#include <iostream>
#include <regex>
#define WIN32_LEAN_AND_MEAN     //the header windows.h defines a lot of data types, which causes conflict. This line fixes that. 
#include <windows.h>
#include <conio.h>	//bad word here.......NSFW.  Give me a safe word. 
#include <string>
#include <functional> //allows passing functions as arguments
using namespace std;

enum colors { WHITE = 7, BLUE = 9, GREEN = 10, RED = 12 };
enum margins{MARGIN_0 = 0, MARGIN1 = 5, MARGIN2 = MARGIN1 + 20, POS_OFFSET = 5, POS_MESSAGES = 0, POS_QUERY = POS_OFFSET + 20};

class Menu
{

	
public:

	regex checkNames = regex("^[\\w\\s]+$");
	regex checkPartNumbers = regex("^[\\w\\s\\-\\_]+$");
	regex checkMoney = regex("^\\d+(,\\d{3})*(\\.\\d*)?$");

	//this is the menus line position.
	int positions[10] = { 5, 7, 9, 11, 13, 15, 17, 19, 21, 23 };
	int position_offset = 5;

	int Set[15] = { WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE }; // DEFAULT COLORS
	void gotoxy(int x, int y);
	void setColor(int color);
	string addComma(string data);
	string addQuotes(string data, bool comma = true);
	string removeChars(string str, string chars = " ");
	bool onlyNumbers(string str);
	string checkInput(string str, regex match);
	string dollarToCents(string dollars);
	string clearLine(int howManyLines = 1);
    
	
	void getMenuLine(string& data, int margin, int position, function<string(string)> validateData);
    
	
	void menuLine(string& menuText, string storedInput, int margin, int margin2, int position, int color);
    void getMenuLine(string& data, int margin, int position);
    string buildFields(string fields[], int size);
    string buildData(string data[], int size);



};

