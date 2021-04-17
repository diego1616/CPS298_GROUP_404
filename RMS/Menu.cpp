#include <string>
#include <iostream>
#include "Menu.h"
#include "User.h"

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


string Menu::checkInput(string str, regex match) {
   
    if (regex_match(str, match)) {
        return str;
    }
    else {
        return "Invalid data.";
    }

    return str;

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

void Menu::printWhiteBar(int margin, int position)
{
    gotoxy(margin, position);
    setColor(WHITE);
    for (int i = 0; i < 28; i++)
        cout << bar;

}

void Menu::menuLine(string& menuText, string storedInput, int margin, int margin2, int position, int color) {
    gotoxy(margin, position);
    setColor(color);
    cout << menuText;
    gotoxy(margin2, position);
    cout << storedInput;
}


void Menu::getMenuLine(string& data, int margin, int position) {

    gotoxy(margin, position);
    clearLine(1);
    gotoxy(margin, position);
    getline(cin, data);
    //gotoxy(margin, position);
    //cout << data;
}

void Menu::outputMsg(string msg)
{
    gotoxy(MARGIN_0, POS_MESSAGES);
    clearLine(POS_BAR -1);
    gotoxy(MARGIN_0, POS_MESSAGES);

    if (msg != "") {
        setColor(WHITE);
        cout << msg << endl;

    }
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