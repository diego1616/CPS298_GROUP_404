#include <string>
#include <iostream>
#include "Menu.h"
//#include "User.h"

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


void Menu::clearLine(int howManyLines) {

    string temp("");
    int lineWidth = 200;

    for (int i = 0; i < lineWidth; i++)
        temp += " ";

    for (int i = 0; i < howManyLines; i++)
        cout << temp << endl;

}


void Menu::prepField(int position, int length)
{
    //go to the start of the field.  We must always start at the most left. So use zero as parameter.
    int x = 0;
    gotoxy(x,position);
    clearLine(length);
    gotoxy(x, position);
}

void Menu::printWhiteBar(int where)
{
    gotoxy(HORIZOTAL_OFFSET, where);
    setColor(WHITE);
    for (int i = 0; i < 28; i++)
        cout << bar;
}

void Menu::printMenuLine(string& menuText, string storedInput, int margin, int margin2, int position, int color) {
    
    gotoxy(margin, position);
    clearLine();
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

//adds a quotes AND commas at the end of each field, but it does not do it to the final field.
string Menu::buildData(string data[], int size) {
    
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


void Menu::bar_Title_Menu(string title, string instructions)
{
    int count = 0;
    int short_delay = 20;
    int long_delay = 3000;

    //wait up to three seconds if other function is printing a msg.  Otherwise there may be conflict. 
    while (EventLog::sync) {
        this_thread::sleep_for(chrono::milliseconds(short_delay));
        count = +short_delay;

        if (count >= long_delay)
            break;
    }

    EventLog::setSync();

        //printing white bar to separate message area
    printWhiteBar(BAR_FIELD_POS);

    //printing the title, if any
    printMenuLine(title, instructions, MARGIN_2, MARGIN_2 + (int)title.length() + 5, TITLE_FIELD_POS, WHITE);

    //clearning old field, so that new output is clean and in the right place. 
    prepField(MENU_FIELD_POS, MENU_FIELD);

    this_thread::sleep_for(chrono::milliseconds(short_delay)); //chill for a bit. then carry on. 

    EventLog::unsetSync();

}

void Menu::loginBasedPrint(string text, int minAccess)
{
    if (minAccess >= DB_Connect::getAcess())
        cout << text << endl;
    else
        cout << "" << endl;

}
