#include <string>
#include <iostream>
#include "Menu.h"
#include "User.h"


void Menu::print_main_menu() {

void Menu::gotoxy(int x, int y)
{
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void Menu::setColor(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

   
string Menu::addComma(string data) {

    data += ",";

    return data;
}

string Menu::addQuotes(string data, bool comma) {

    data = "'" + data + "'";

    if (comma == true)
        data = addComma(data);

    return data;
}

string Menu::removeChars(string str, string chars) {

    int index(0);

    cout << "removeChars() input string: " << '\"' + str + '\"' << endl;
    while (index >= 0)
    {
        index = (int)str.find_first_of(chars);

        if (chars.length() > 0 && index >= 0)
            str.erase(index, 1);
    }
    cout << "removeChars() output string: " << '\"' + str + '\"' << endl;
    return str;
}

bool Menu::onlyNumbers(string str) {
    //returns true if the string only contains numbers. 

    //cout << "onlyNumbers() input string: " << str << endl;
    for (int i = 0; i < str.length() -1; i++)
            {
        if (str[i] < 48 || str[i]>57)
        {
            //cout << "something besides a number was detected: " << str[i] << endl;
            return false;
        }
    }

    return true;
}

string Menu::checkInput(string str, regex match) {
   
    if (regex_match(str, match)) {
        return str;
    }
    else {
        return "Invalid data.";
    }

    return str;

}


//use this function to conver a double/float like string to int.  Money should always be store in int to avoid rounding
string Menu::dollarToCents(string dollars) {

    if (regex_match(dollars, regex("^\\d+(,\\d{3})*(\\.\\d*)?$"))) {
        return dollars;
    }
    else {
        return "Invalid data.";
    }

    return dollars;
}

string Menu::clearLine(int howManyLines) {

    string temp("");
    int lineWidth = 180;

    for (int i = 0; i < lineWidth; i++)
        temp += " ";

    for (int i = 0; i < howManyLines; i++)
        cout << temp << endl;

    return temp;

}

void Menu::menuLine(string& menuText, string storedInput, int margin, int margin2, int position, int color) {
    gotoxy(margin, position);
    setColor(color);
    cout << menuText;
    gotoxy(margin2, position);
    cout << storedInput;
            }

//the third parameter is a pointer to a function to check the data is correct before accepting it.
void Menu::getMenuLine(string& data, int margin, int position, function<string(string)> validateData) {

    gotoxy(margin, position);
    clearLine(1);
    gotoxy(margin, position);
    getline(cin, data);
    data = validateData(data);
    gotoxy(margin, position);
    cout << data;
}

void Menu::getMenuLine(string& data, int margin, int position) {

    gotoxy(margin, position);
    clearLine(1);
    gotoxy(margin, position);
    getline(cin, data);
    gotoxy(margin, position);
    cout << data;
}

string Menu::buildFields(string fields[], int size) {
    //add a comma at the end of each field, but it does not do it to the final field.

    string sqFields("");

    for (int i = 0; i < size; i++)
    {
        if (i < size - 1)
            sqFields += addComma(fields[i]);
        if (i == size - 1)
            sqFields += fields[i];
    }

    return sqFields;
}

string Menu::buildData(string data[], int size) {
    //adds a quotes AND commas at the end of each field, but it does not do it to the final field.

    string sqFields("");

    for (int i = 0; i < size; i++)
    {
        if (i < size - 1)
            sqFields += addQuotes(data[i]);
        if (i == size - 1)
            sqFields += addQuotes(data[i], false);   //false means dont add the comma
    }

    return sqFields;

}